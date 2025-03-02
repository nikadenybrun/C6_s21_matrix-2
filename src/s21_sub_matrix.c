#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int err = OK;
  if (!is_matrix_valid(*A) || !is_matrix_valid(*B) || result == NULL) {
    err = INCORRECT_MATRIX;
  }
  if (!is_same_size(*A, *B) || s21_isinf(*A) || s21_isinf(*B)) {
    err = ERROR;
  }
  if (!err) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }
  return err;
}