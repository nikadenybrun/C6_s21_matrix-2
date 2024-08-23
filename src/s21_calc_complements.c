#include <math.h>

#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int err = OK;
  matrix_t minor;
  if (A == NULL || !is_matrix_valid(*A) || result == NULL) {
    err = INCORRECT_MATRIX;
  } else if (!is_matrix_squared(*A) || s21_isinf(*A)) {
    err = ERROR;
  } else if (A->rows == 1) {
    s21_create_matrix(A->rows, A->columns, result);
    result->matrix[0][0] = 0;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        s21_create_matrix(A->columns - 1, A->rows - 1, &minor);
        make_minor(*A, i, j, &minor);
        double det = 0;
        s21_determinant(&minor, &det);
        result->matrix[i][j] = det * pow(-1, i + j);

        s21_remove_matrix(&minor);
      }
    }
  }
  return err;
}
