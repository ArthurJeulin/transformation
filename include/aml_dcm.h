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
  double radToDeg(const double& rad);
  double degToRad(const double& deg);
  
  class Euler
  {
    public:
      double phi;
      double theta;
      double psi;

      void toDeg();

  };
  // Stream Functions
  std::ostream& operator<<(std::ostream& os, const Euler& angle);

  Matrix33 rotationX(double phi);

  Matrix33 rotationY(double theta);
  
  Matrix33 rotationZ(double psi);

  Matrix33 rotationXYZ(double phi, double theta, double psi);

  const Euler eulerFromRxyz(const Matrix33& mat);

} // namespace aml