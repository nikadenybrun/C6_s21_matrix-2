#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int err = OK;
  if (A == NULL || !is_matrix_valid(*A) || result == NULL) {
    err = INCORRECT_MATRIX;
  } else if (!is_matrix_squared(*A) || s21_isinf(*A)) {
    err = ERROR;
  } else {
    if (A->rows == 1) {
      *result = A->matrix[0][0];

    } else if (A->rows == 2) {
      *result =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];

    } else {
      int sign = 1;
      for (int i = 0; i < A->columns; i++) {
        double minor_determinant = 0;
        matrix_t minor;
        s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
        make_minor(*A, 0, i, &minor);
        s21_determinant(&minor, &minor_determinant);
        *result += sign * A->matrix[0][i] * minor_determinant;
        sign *= -1;
        s21_remove_matrix(&minor);
      }
    }
  }

  return err;
}