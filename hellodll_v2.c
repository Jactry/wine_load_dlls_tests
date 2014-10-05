/* hellodll_v2.c */
#include <stdio.h>

__declspec(dllexport) void __cdecl get_version()
{
  printf("hellodll_v2\n");
}
