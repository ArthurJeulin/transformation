// **********************************************************
//      2024 : Arthur JEULIN
//      Copyright (c) Arthur JEULIN 
//      Created by Arthur JEULIN on 18/04/2024.
// **********************************************************
//
// Module : Attitude Vector 3 Class
//
#include <cmath>
#include <iostream>
#include <aml_dcm.h>


namespace aml
{

  const double radToDeg(const double& rad)
  {
    return rad * (180.0/M_PI);
  }

  const double degToRad(const double& deg)
  {
    return deg * (M_PI/180.0);
  }

  Matrix33 rotationX(double phi)
  {
      double data[3][3] = {{1.0, 0.0, 0.0},
                            {0.0, cos(phi), sin(phi)}, 
                            {0.0, -sin(phi), cos(phi)}};
      Matrix33 Mat(data);
      return Mat;
  }
  
  Matrix33 rotationY(double theta)
  {
      double data[3][3] = {{cos(theta), 0.0 ,-sin(theta)},
                            {0.0, 1.0 , 0.0}, 
                            {sin(theta), 0.0, cos(theta)}};
      Matrix33 Mat(data);
      return Mat;
  }
  
  Matrix33 rotationZ(double psi)
  {
      double data[3][3] = {{cos(psi), sin(psi), 0.0},
                            {-sin(psi), cos(psi), 0.0}, 
                            {0.0, 0.0, 1.0}};
      Matrix33 Mat(data);
      return Mat;
  }

  Matrix33 rotationXYZ(double phi, double theta, double psi)
  {
      Matrix33 Mat_tem = rotationY(theta) * rotationZ(psi);
      Matrix33 Mat = rotationX(phi)* Mat_tem;
      return Mat;
  }

} // namespace aml