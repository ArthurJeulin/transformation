// **********************************************************
//      2024 : Arthur JEULIN
//      Copyright (c) Arthur JEULIN 
//      Created by Arthur JEULIN on 18/04/2024.
// **********************************************************
//
// Module : Attitude Matrix 33 Class
//

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#ifndef AML_MATRIX_33_H
#define AML_MATRIX_33_H

#include "aml_vector_3.h"

namespace aml
{
  class Vector3;
  class Matrix33
  {
    public:
    // Data 
    union
    {
      double data[3][3];
      struct{ double m11, m12, m13, m21, m22, m23, m31, m32, m33;};
    };

    // Constructors
    Matrix33();
    explicit Matrix33(double val);
    explicit Matrix33(const double data[9]);
    explicit Matrix33(const double data[3][3]);
    explicit Matrix33(const Vector3& v1, const Vector3& v2, const Vector3& v3);
    // Operator Assignments (Matrix)
    Matrix33& operator+=(const Matrix33& rhs);
    Matrix33& operator-=(const Matrix33& rhs);
    Matrix33& operator*=(const Matrix33& rhs);
    Matrix33& operator/=(const Matrix33& rhs);
    // Operator Assignments (Scalar)
    Matrix33& operator+=(double rhs);
    Matrix33& operator-=(double rhs);
    Matrix33& operator*=(double rhs);
    Matrix33& operator/=(double rhs);

    // Special Object Creators
    static const Matrix33 identity();

  };
  // Matrix / Matrix Operations
  Matrix33 operator-(const Matrix33& rhs);
  Matrix33 operator+(const Matrix33& lhs, const Matrix33& rhs);
  Matrix33 operator-(const Matrix33& lhs, const Matrix33& rhs);
  Matrix33 operator*(const Matrix33& lhs, const Matrix33& rhs);
  Matrix33 operator/(const Matrix33& lhs, const Matrix33& rhs);

  // Matrix / Vector Operations
  Vector3 operator*(const Matrix33& lhs,const Vector3& rhs);

  // Matrix / Scalar Operations
  Matrix33 operator+(const Matrix33& lhs, double s);
  Matrix33 operator-(const Matrix33& lhs, double s);
  Matrix33 operator*(const Matrix33& lhs, double s);
  Matrix33 operator/(const Matrix33& lhs, double s);
  Matrix33 operator+(double s, const Matrix33& rhs);
  Matrix33 operator-(double s, const Matrix33& rhs);
  Matrix33 operator*(double s, const Matrix33& rhs);
  Matrix33 operator/(double s, const Matrix33& rhs);


  // Matrix Operations
  Vector3 diag(const Matrix33& rhs);
  Matrix33 diag(const Vector3& rhs);
  Matrix33 transpose(const Matrix33& rhs);
  double determinant(const Matrix33& rhs);
  Matrix33 inverse(const Matrix33& rhs);

  // Stream Operations
  std::ostream& operator<<(std::ostream& os, const Matrix33& obj);

}; // namespace aml

#endif /* AML_MATRIX_33_H*/