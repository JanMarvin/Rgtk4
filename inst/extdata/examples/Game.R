library(Rgtk4)
library(magick)
gtkInit()
gtkStartEventLoop()

frink_orig <- magick::image_read("https://jeroen.github.io/images/frink.png")

make_pixbuf <- function(size) {
  scaled <- magick::image_scale(frink_orig, sprintf("%dx%d", size, size))
  info <- magick::image_info(scaled)
  w <- info$width; h <- info$height
  bytes <- as.raw(magick::image_data(scaled, channels = "rgba"))
  data_ptr <- rawToExtptr(bytes)
  gb <- gBytesNew(data_ptr, length(bytes))
  gdkPixbufNewFromBytes(gb, 0L, TRUE, 8L,
                        as.integer(w), as.integer(h),
                        as.integer(w * 4L))
}

HIGHSCORE_FILE <- "~/.whack_a_frink_scores"
load_scores <- function() {
  if (!file.exists(HIGHSCORE_FILE)) return(data.frame(name = character(), score = integer()))
  read.table(HIGHSCORE_FILE, header = TRUE, stringsAsFactors = FALSE,
             colClasses = c("character", "integer"))
}
save_scores <- function(df) {
  write.table(df, HIGHSCORE_FILE, row.names = FALSE, quote = FALSE)
}
add_score <- function(name, score) {
  df <- load_scores()
  df <- rbind(df, data.frame(name = name, score = score))
  df <- df[order(-df$score), ]
  df <- head(df, 10)
  save_scores(df)
  df
}

game <- new.env()
game$pixbuf_keepalive <- list()
window <- gtkWindowNew()
gtkWindowSetTitle(window, "Whack-a-Frink!")
gtkWindowSetDefaultSize(window, 600, 500)

stack <- gtkStackNew()
gtkWindowSetChild(window, stack)

play_box <- gtkFixedNew()
gtkStackAddNamed(stack, play_box, "play")

score_label <- gtkLabelNew("")
gtkFixedPut(play_box, score_label, 10.0, 10.0)

instructions <- gtkLabelNew("")
gtkLabelSetMarkup(instructions,
                  "<span font='12'><b>Click the Frinks before they fill up!</b></span>")
gtkFixedPut(play_box, instructions, 10.0, 40.0)

gameover_box <- gtkBoxNew(1L, 12)
gtkWidgetSetMarginTop(gameover_box, 30)
gtkWidgetSetMarginStart(gameover_box, 30)
gtkWidgetSetMarginEnd(gameover_box, 30)
go_title <- gtkLabelNew("")
gtkLabelSetMarkup(go_title,
                  "<span font='28' weight='bold' foreground='red'>GAME OVER</span>")
gtkBoxAppend(gameover_box, go_title)

final_score_label <- gtkLabelNew("")
gtkBoxAppend(gameover_box, final_score_label)

name_entry <- gtkEntryNew()
gtkEntrySetPlaceholderText(name_entry, "Enter initials (3 chars)")
gtkBoxAppend(gameover_box, name_entry)

submit_btn <- gtkButtonNewWithLabel("Submit Score")
gtkBoxAppend(gameover_box, submit_btn)

scores_label <- gtkLabelNew("")
gtkBoxAppend(gameover_box, scores_label)

restart_btn <- gtkButtonNewWithLabel("Restart")
gtkBoxAppend(gameover_box, restart_btn)
gtkStackAddNamed(stack, gameover_box, "gameover")

format_scores <- function(df) {
  if (nrow(df) == 0) return("<span font_family='monospace'>No scores yet</span>")
  lines <- sprintf("%2d. %-3s  %4d", seq_len(nrow(df)), df$name, df$score)
  paste0("<span font_family='monospace'>",
         paste(c("-- HIGH SCORES --", lines), collapse = "\n"),
         "</span>")
}

reset_state <- function() {
  for (entry in game$frinks) gtkFixedRemove(play_box, entry$img)
  game$frinks <- list()
  game$next_id <- 0
  game$active <- 0
  game$kills <- 0
  game$game_over <- FALSE
  game$max_active <- 8
  game$timer_handle <- NULL
}

update_score <- function() {
  text <- sprintf("Active: %d/%d   Kills: %d",
                  game$active, game$max_active, game$kills)
  gtkLabelSetText(score_label, text)
}

end_game <- function() {
  game$game_over <- TRUE
  gtkLabelSetText(final_score_label,
                  sprintf("Final score: %d", game$kills))
  gtkEditableSetText(name_entry, "")
  gtkLabelSetMarkup(scores_label, format_scores(load_scores()))
  gtkStackSetVisibleChildName(stack, "gameover")
}

add_frink <- function() {
  if (game$game_over) return()
  size <- sample(50:140, 1)
  pb <- make_pixbuf(size)
  x <- as.numeric(sample(20:(600 - size - 20), 1))
  y <- as.numeric(sample(80:(500 - size - 20), 1))
  img <- gtkPictureNewForPixbuf(pb)
  gtkWidgetSetSizeRequest(img, size, size)
  click <- gtkGestureClickNew()
  gObjectRef(click)
  gtkWidgetAddController(img, click)
  game$next_id <- game$next_id + 1
  img_id <- as.character(game$next_id)
  gSignalConnectR(click, "released", function(gesture, n_press, x, y) {
    entry <- game$frinks[[img_id]]
    if (!is.null(entry) && !game$game_over) {
      gtkFixedRemove(play_box, entry$img)
      game$frinks[[img_id]] <- NULL
      game$active <- game$active - 1
      game$kills <- game$kills + 1
      update_score()
    }
  })
  gtkFixedPut(play_box, img, x, y)
  game$frinks[[img_id]] <- list(img = img, click = click)
  game$active <- game$active + 1
  update_score()
  if (game$active >= game$max_active) end_game()
}

spawn_tick <- function() {
  if (!game$game_over) add_frink()
  !game$game_over
}

start_game <- function() {
  reset_state()
  update_score()
  gtkStackSetVisibleChildName(stack, "play")
  add_frink()
  gTimeoutAdd(1500, spawn_tick)
}

gSignalConnectR(submit_btn, "clicked", function(...) {
  name <- toupper(substr(gtkEditableGetText(name_entry), 1, 3))
  if (nchar(name) == 0) name <- "???"
  df <- add_score(name, game$kills)
  gtkLabelSetMarkup(scores_label, format_scores(df))
  gtkWidgetSetSensitive(submit_btn, FALSE)
})

gSignalConnectR(restart_btn, "clicked", function(...) {
  gtkWidgetSetSensitive(submit_btn, TRUE)
  start_game()
})

start_game()
gtkWindowPresent(window)
gtkWindowTrack(window)
