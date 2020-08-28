#include "MemAlloc.h"
#include <stdlib.h>

void *memAlloc(int size) {
  return malloc(size);
}

void memFree(void *memToFree) {
  free(memToFree);
}