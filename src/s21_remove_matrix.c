#include "s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL && is_matrix_valid(*A)) {
    free(A->matrix);
    A->matrix = NULL;
  }
}
