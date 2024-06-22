// **********************************************************
//      2024 : Arthur JEULIN
//      Copyright (c) Arthur JEULIN 
//      Created by Arthur JEULIN on 18/04/2024.
// **********************************************************
//
// Module : Attitude DCM
//

#include <aml_matrix_33.h>


namespace aml
{
  Matrix33 rotationX(double phi);

  Matrix33 rotationY(double theta);
  
  Matrix33 rotationZ(double psi);

  Matrix33 rotationXYZ(double phi, double theta, double psi);

  const double radToDeg(const double& rad);
  const double degToRad(const double& deg);

} // namespace aml