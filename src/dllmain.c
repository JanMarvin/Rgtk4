// dllmain.c - Minimal DLL entry point for Windows
// This satisfies the linker's DllEntryPoint requirement

#ifdef _WIN32
#include <windows.h>

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
  return TRUE;
}

// Alias for old-style entry point
BOOL WINAPI DllEntryPoint(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
  return DllMain(hinstDLL, fdwReason, lpvReserved);
}
#else
// Empty file on non-Windows platforms
// Dummy declaration to avoid ISO C empty translation unit warning
typedef int make_iso_compilers_happy;
#endif
