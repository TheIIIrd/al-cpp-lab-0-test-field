/*
Лабораторная Работа "Матрица"
*/

#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

struct Matrix {
  // двумерный массив с данными.
  int **data_ = nullptr;
  // количество столбцов
  size_t n_ = 0u;
  // количество строк
  size_t m_ = 0u;
};

// Создает заполненную нулями матрицу n x m.
// void Construct(Matrix& out, size_t n, size_t m);
void Construct(Matrix &out, size_t n, size_t m) {

  out.n_ = n;
  out.m_ = m;

  out.data_ = new int *[n];

  for (size_t i = 0; i < n; ++i) {
    out.data_[i] = new int[m];
  }

  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < m; ++j) {
      out.data_[i][j] = 0;
    }
  }

  return;
}

// Освобождает выделенную память.
// void Destruct(Matrix& in);
void Destruct(Matrix &in) {
  for (size_t i = 0; i < in.n_; ++i) {
    delete in.data_[i];
  }

  return;
}

// Создает копию матрицы |matrix|.
// Matrix Copy(const Matrix& matrix);
Matrix Copy(const Matrix &matrix) {

  Matrix matrix_copy;
  Construct(matrix_copy, matrix.n_, matrix.m_);

  for (size_t i = 0; i < matrix.n_; ++i) {
    for (size_t j = 0; j < matrix.m_; ++j) {
      matrix_copy.data_[i][j] = matrix.data_[i][j];
    }
  }

  return matrix_copy;
}

// Возвращает сумму двух матриц.
// Если операция невозможна - вернуть пустую матрицу
// Matrix Add(const Matrix& a, const Matrix& b);
Matrix Add(const Matrix &a, const Matrix &b) {

  if ((a.m_ == b.m_) && (a.n_ == b.n_)) {

    Matrix matrix_res;
    Construct(matrix_res, a.n_, a.m_);

    for (size_t i = 0; i < a.n_; ++i) {
      for (size_t j = 0; j < a.m_; ++j) {
        matrix_res.data_[i][j] = a.data_[i][j] + b.data_[i][j];
      }
    }

    return matrix_res;
  }

  return Matrix();
}

// Возвращает разницу двух матриц.
// Если операция невозможна - вернуть пустую матрицу
// Matrix Sub(const Matrix& a, const Matrix& b);
Matrix Sub(const Matrix &a, const Matrix &b) {

  if ((a.m_ == b.m_) && (a.n_ == b.n_)) {

    Matrix matrix_res;
    Construct(matrix_res, a.n_, a.m_);

    for (size_t i = 0; i < a.n_; ++i) {
      for (size_t j = 0; j < a.m_; ++j) {
        matrix_res.data_[i][j] = a.data_[i][j] - b.data_[i][j];
      }
    }

    return matrix_res;
  }

  return Matrix();
}

// Возвращает произведение двух матриц.
// Если операция невозможна - вернуть пустую матрицу
// Matrix Mult(const Matrix& a, const Matrix& b);
Matrix Mult(const Matrix &a, const Matrix &b) {

  if ((a.m_ == b.n_) && (a.n_ == b.m_)) {

    Matrix matrix_res;
    Construct(matrix_res, a.n_, b.m_);

    for (size_t i = 0; i < matrix_res.n_; ++i) {
      for (size_t j = 0; j < matrix_res.m_; ++j) {
        for (size_t k = 0; k < a.n_; ++k) {
          matrix_res.data_[i][j] += a.data_[i][k] * b.data_[k][j];
        }
      }
    }

    return matrix_res;
  }

  return Matrix();
}

// Транспонирование матрицы.
// void Transposition(Matrix& matrix);
void Transposition(Matrix &matrix) {

  Matrix matrix_res;
  Construct(matrix_res, matrix.m_, matrix.n_);

  for (size_t i = 0; i < matrix_res.n_; ++i) {
    for (size_t j = 0; j < matrix_res.m_; ++j) {
      matrix_res.data_[i][j] = matrix.data_[j][i];
    }
  }

  matrix.n_ = matrix_res.n_;
  matrix.m_ = matrix_res.m_;

  matrix = matrix_res;

  Destruct(matrix_res);
}

// Сравнение двух матриц.
// bool operator==(const Matrix& a, const Matrix& b);

int main() {

  Matrix mtx_one;
  Construct(mtx_one, 4, 7);

  Matrix mtx_two;
  Construct(mtx_two, 4, 7);

  Matrix mtx_three;
  Construct(mtx_two, 5, 2);

  return 0;
}
