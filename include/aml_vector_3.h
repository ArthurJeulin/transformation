// **********************************************************
//      2024 : Arthur JEULIN
//      Copyright (c) Arthur JEULIN 
//      Created by Arthur JEULIN on 18/04/2024.
// **********************************************************
//
// Module : Attitude Vector 3 Class
//

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#ifndef AML_VECTOR_3_H
#define AML_VECTOR_3_H

#include <iostream>
#include <cmath>

namespace aml
{

  class Vector3
  {
    public:
      // Vector Data
      union 
      {
        double data[3];
        struct{double x,y,z;};
        
      };
      
      // Constructors
      Vector3();
      Vector3(double val);
      Vector3(double x_, double y_, double z_);
      Vector3(const double data_[3]);
      // Copy Constructor
      Vector3(const Vector3& other);

      // Operator Assignments (Vector) v1+=v2
      Vector3& operator+=(const Vector3& rhs);
      Vector3& operator-=(const Vector3& rhs);
      Vector3& operator*=(const Vector3& rhs);
      Vector3& operator/=(const Vector3& rhs);
      // Operator Assignments (Scalar) v+=0.1
      Vector3& operator+=(double s);
      Vector3& operator-=(double s);
      Vector3& operator*=(double s);
      Vector3& operator/=(double s);

      // Special Object Creator
      static const Vector3 xAxis();
      static const Vector3 yAxis();
      static const Vector3 zAxis();
  };

  // Vector / Vector Elementwise Operations
  Vector3 operator-(const Vector3& rhs); // v1-v2
  Vector3 operator+(const Vector3& lhs,const Vector3& rhs); // v1+v2
  Vector3 operator-(const Vector3& lhs,const Vector3& rhs); // v1-v2
  Vector3 operator*(const Vector3& lhs,const Vector3& rhs); // v1*v2
  Vector3 operator/(const Vector3& lhs,const Vector3& rhs); // v1/v2
  // Vector / Scalar Operations v1 * 0.1
  Vector3 operator+(const Vector3& lhs, double s);
  Vector3 operator-(const Vector3& lhs, double s);
  Vector3 operator*(const Vector3& lhs, double s);
  Vector3 operator/(const Vector3& lhs, double s);
  // 0.1* v1
  Vector3 operator+(double s, const Vector3& rhs);
  Vector3 operator-(double s, const Vector3& rhs);
  Vector3 operator*(double s, const Vector3& rhs);
  Vector3 operator/(double s, const Vector3& rhs);

  // Vector Operations
  double norm(const Vector3& rhs);
  void normalise(Vector3& rhs);
  Vector3 unit(const Vector3& rhs);
  Vector3 cross(const Vector3& lhs, const Vector3& rhs);
  double dot(const Vector3& lhs, const Vector3& rhs);
  
  // Stream Functions
  std::ostream& operator<<(std::ostream& os, const Vector3& obj);

} // namespace aml

#endif /* AML_VECTOR_3_H*/