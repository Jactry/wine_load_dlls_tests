/* hello.c */
#include <stdio.h>
#include <windows.h>

__declspec(dllimport) void __cdecl get_version();


int main(int argc, char** argv)
{
  HINSTANCE hInstLibrary = LoadLibrary("lib/hellodll.dll");
  if (hInstLibrary == NULL)
    printf("LoadLibrary failed!\n");
  get_version();
  return 0;
}
