

#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = OK;

  if (result == NULL || rows < 1 || columns < 1) {
    error = INCORRECT_MATRIX;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows + rows * columns, sizeof(double));
    if (result->matrix != NULL) {
      double *start = (double *)(result->matrix + rows);
      int iteration_limit = rows <= columns ? columns : rows;
      for (int i = 0; i < iteration_limit; i++) {
        result->matrix[i] = start + i * columns;
      }
    }
  }
  return error;
}
