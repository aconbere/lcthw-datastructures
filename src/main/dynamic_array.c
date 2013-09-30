#include "dynamic_array.h"

DArray *DArray_create(size_t element_size, size_t max) {
  check(max > 0, "You must set an initial_max > 0.");

  DArray *array = malloc(sizeof(DArray));
  check_mem(array);

  array->element_size = element_size;
  array->max = max;
  array->end = 0;
  array->expand_rate = DEFAULT_EXPAND_RATE;
  array->contents = calloc(max, sizeof(void *));

  return array;

error:
  return NULL;
}

static inline int DArray_resize(DArray *array, size_t newsize) {
  check(array->max > 0, "The new size must be greater than 0");

  array->max = newsize;

  void *contents = realloc(array->contents, array->max * sizeof(void *));
  check_mem(contents);

  array->contents = contents;
  return 0;
error:
  return -1;
}

void DArray_clear(DArray *array) {
  int i = 0;

  if (array->element_size > 0) {
    for (i = 0; i < array->max; i++) {
      if (array->contents[i] != NULL) {
        free(array->contents[i]);
      }
    }
  }
}

void DArray_destroy(DArray *array) {
  if (array) {
    if (array->contents) {
      free(array->contents);
    }
    free(array);
  }
}

int DArray_expand(DArray *array) {
  size_t old_max = array->max;

  check(
      DArray_resize(array, array->max + array->expand_rate),
      "Failed to resize array to new size %d",
      array->max + (int)array->expand_rate
      );
  // look forward to the start of the new data (array->contents + old_max)
  // set all the data between there and the size of the new block to 0
  memset(array->contents + old_max, 0, array->expand_rate + 1);
  return 0;
error:
  return -1;
}

int DArray_max(int a, int b) {
  return a < b ? b : a;
}

/* bring the array size down to max(array->end, array->expand_rate) */
int DArray_contract(DArray *array) {
  return DArray_resize(array, DArray_max(array->end, (int) array->expand_rate) + 1);
}

