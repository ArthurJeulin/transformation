// **********************************************************
//      2024 : Arthur JEULIN
//      Copyright (c) Arthur JEULIN 
//      Created by Arthur JEULIN on 18/04/2024.
// **********************************************************
//
// Module : Attitude Rotation
//

// #include "aml_matrix_33.h"
#include "aml_euler.h"

namespace aml
{
  Matrix33 rotationX(double phi);

  Matrix33 rotationY(double theta);
  
  Matrix33 rotationZ(double psi);

  Matrix33 rotationXYZ(double phi, double theta, double psi);

  const Euler eulerFromRxyz(const Matrix33& mat);

  Vector3 eulerAngleRatesXYZ(const Euler& attitude, const Vector3& omega_body);

  Vector3 eulerIntegration(const Vector3& x, const Vector3& x_dot, const double& delta_t);

  Vector3 linearInterpolate(const Vector3& r_0, const Vector3& r_1, const double& t);
  

} // namespace aml