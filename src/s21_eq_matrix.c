#include <string.h>

#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = SUCCESS;
  if (A == NULL || !is_matrix_valid(*A) || !is_matrix_valid(*B) ||
      !is_same_size(*A, *B) || s21_isinf(*A) || s21_isinf(*B)) {
    result = FAILURE;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > s21_EPS) {
          result = FAILURE;
        }
      }
    }
  }
  return result;
}