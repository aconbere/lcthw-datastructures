#ifndef DynamicArray
#define DynamicArray

#include <stdlib.h>
#include "dbg.h"

typedef struct DArray {
  int max;
  int end;
  size_t element_size;
  size_t expand_rate;
  void **contents;
} DArray;

DArray *DArray_create(size_t element_size, size_t max);
void DArray_destroy(DArray *array);
void DArray_clear(DArray *array);
void DArray_clear_destroy(DArray *array);
int DArray_expand(DArray *array);
int DArray_contract(DArray *array);
int DArray_push(DArray *array);
void DArray_pop(DArray *array);

#define DArray_first(A) ((A)->content[0])
#define DArray_last(A) ((A)->content[end - 1])
#define DEFAULT_EXPAND_RATE 300
#endif
