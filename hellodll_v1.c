/* hellodll_v1.c */
#include <stdio.h>

__declspec(dllexport) void __cdecl get_version()
{
  printf("hellodll_v1\n");
}
