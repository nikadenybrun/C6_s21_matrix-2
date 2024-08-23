#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int err = OK;

  if (A == NULL || B == NULL || !is_matrix_valid(*A) || !is_matrix_valid(*B) ||
      result == NULL) {
    err = INCORRECT_MATRIX;

  } else if (A->columns != B->rows || s21_isinf(*A) || s21_isinf(*B)) {
    err = ERROR;

  } else {
    s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < B->columns; i++) {
      for (int j = 0; j < A->rows; j++) {
        for (int k = 0; k < A->columns; k++) {
          result->matrix[j][i] += A->matrix[j][k] * B->matrix[k][i];
        }
      }
    }
  }
  return err;
}