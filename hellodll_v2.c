/* hellodll_v2.c */
#include <windows.h>
#include <stdio.h>

__declspec(dllexport) void __cdecl get_version()
{
  printf("hellodll_v2\n");
}

static HINSTANCE instance;

BOOL WINAPI DllMain(HINSTANCE hinst, DWORD reason, LPVOID reserved)
{
  switch (reason)
  {
    case DLL_PROCESS_ATTACH:
      instance = hinst;
      DisableThreadLibraryCalls(hinst);
      break;
  }
  return TRUE;
}
