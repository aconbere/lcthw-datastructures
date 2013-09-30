#ifndef DynamicArray
#define DynamicArray

#include <stdlib.h>
#include <dbg.h>

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
int DArray_push(DArray *array, void *el);
void *DArray_pop(DArray *array);

#define DArray_first(A) ((A)->content[0])
#define DArray_last(A) ((A)->contents[(A)->end - 1])
#define DEFAULT_EXPAND_RATE 300

/* set an element in the array */
static inline void DArray_set(DArray *array, int i, void *el) {
  check(i < array->max, "darray attempt to set past max");

  if (i > array->end) {
    array->end = i;
  }

  array->contents[i] = el;
error:
  return;
}

/* return an element in the array */
static inline void *DArray_get(DArray *array, int i) {
  check(i < array->max, "darray attempt to set past max");

  return array->contents[i];
error:
  return NULL;
}

/* NULL an element in the array */
static inline void *DArray_remove(DArray *array, int i) {
  check(i < array->max, "darray attempt to remove past max");

  void * el = array->contents[i];
  array->contents[i] = NULL;
  return el;
error:
  return NULL;
}

/* initialize an new element in the array */
static inline void *DArray_new(DArray *array) {
  check(array->element_size > 0, "can't create new zero size elements");
  return calloc(1, array->element_size);
error:
  return NULL;
}

#define DArray_free(E) free((E))

#endif
