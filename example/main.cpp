// **********************************************************
//      2024 : Arthur JEULIN
//      Copyright (c) Arthur JEULIN 
//      Created by Arthur JEULIN on 18/04/2024.
// **********************************************************
//

#include <iostream>
#include <string>
#include <cmath>

#include "aml.h"

int main()
{
//   aml::Vector3 v1(1.0,2.0,3.0);
//   aml::Vector3 v2(4.0,5.0,6.0);
//   aml::Vector3 v3 = v1 + v2 ;
//   aml::Vector3 v4 = v3 * v1 ;

//   std::cout << v1 <<std::endl;
//   std::cout << v2 <<std::endl;
//   std::cout << v3 <<std::endl;
//   std::cout << v4 <<std::endl;

  double data[3][3] = {{1.2 , 3.2 , 0.5},{0.1, 1.0, 6.0} , {-4.1 , 4.9 , 3.1}};
  aml::Matrix33 Mat1(data);
  
  aml::Vector3 v1(1,0,0);
  aml::Vector3 v3(0,1,0);
  aml::Vector3 v2 = Mat1 * v1;
  aml::Vector3 v4 = Mat1 * v3;

  std::cout << Mat1 << std::endl;
  std::cout << v1 << std::endl;
  std::cout << v2 << std::endl;
  std::cout << v3 << std::endl;
  std::cout << v4 << std::endl;

  /*----------DCM-Single-Rotation-----------------*/
  // aml::Vector3 x_a(0.70,1.20,-0.30);
  // aml::Matrix33 Rx = aml::rotationX(30*(M_PI/180));
  // aml::Vector3 x_b = Rx * x_a;

  // std::cout << x_a << std::endl;
  // std::cout << Rx << std::endl;
  // std::cout << x_b << std::endl;

  /*----------DCM-Chain-Rotation-----------------*/
  aml::Vector3 x_a(0.0,1.0,0.0);
  aml::Matrix33 R_ba = aml::rotationX(30*(M_PI/180));
  aml::Matrix33 R_cb = aml::rotationX(15*(M_PI/180));
  aml::Vector3 x_b = R_ba * x_a;
  aml::Vector3 x_c = R_cb * x_b;

  aml::Matrix33 R_ca = R_cb * R_ba;

  aml::Vector3 x_c2 = R_ca * x_a;
  std::cout << x_a << std::endl;
  std::cout << R_ba << std::endl;
  std::cout << R_cb << std::endl;
  std::cout << x_b << std::endl;
  std::cout << x_c << std::endl;
  std::cout << R_ca << std::endl;
  std::cout << x_c2 << std::endl;



  aml::Matrix33 euler_angle = aml::rotationXYZ(30.0*(M_PI/180), 65.0*(M_PI/180), -45.0*(M_PI/180));
  std::cout << euler_angle << std::endl;
  
  
  aml::Matrix33 euler_angle_test = aml::rotationXYZ(-45.0*(M_PI/180), -75.0*(M_PI/180), -78.0*(M_PI/180));
  aml::Euler angle = eulerFromRxyz(euler_angle_test);
  angle.toDeg();
  std::cout << angle << std::endl;
  
  
  return 0;
}