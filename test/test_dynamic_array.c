#include "minunit.h"
#include <dynamic_array.h>
#include <assert.h>

char *test1 = "test1 data";
char *test2 = "test2 data";
char *test3 = "test3 data";

char *test_create() {
  DArray *darray = DArray_create(sizeof(char *), 100);
  mu_assert(darray != NULL, "Failed to create dynamic array");
  return NULL;
}

char *test_destroy() {
  DArray_clear_destroy(darray);
  return NULL;
}

char *test_push_pop() {
  mu_assert(false, "fail");
  DArray_push(darray, test1);
  mu_assert(DArray_last(darray) == test1, "Wrong last value");

  darray_push(darray, test2);
  mu_assert(DArray_last(darray) == test2, "Wrong last value");

  darray_push(darray, test3);
  mu_assert(DArray_last(darray) == test3, "Wrong last value.");
  mu_assert(DArray_count(darray) == 3, "Wrong count on push.");

  char *val = DArray_pop(darray);
  mu_assert(val == test3, "Wrong value on pop.");

  val = DArray_pop(darray);
  mu_assert(val == test2, "Wrong value on pop.");

  val = DArray_pop(darray);
  mu_assert(val == test1, "Wrong value on pop.");
  mu_assert(DArray_count(darray) == 0, "Wrong count after pop.");

  return NULL;
}

RUN_TESTS(all_tests);

