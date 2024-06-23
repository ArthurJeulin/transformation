// **********************************************************
//      2024 : Arthur JEULIN
//      Copyright (c) Arthur JEULIN 
//      Created by Arthur JEULIN on 18/04/2024.
// **********************************************************
//

#include <iostream>
#include <string>
#include <cmath>

#include <vector>

#include "aml.h"

#include <matplot/matplot.h>
using namespace matplot;

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
  
  // Define a starting attitude
  aml::Euler attitude(0.00001,0.0,0.0);
  attitude.toRad();
  // Rotation Around l'axe Z at 5°/s
  aml::Euler omega_body(2.0,-3.0,0.0);
  omega_body.toRad();
  // time step 
  double dt_step = 0.01;
  std::vector<double> time;
  std::vector<double> phi;
  std::vector<double> theta;
  std::vector<double> psi;
  // 20 s f = 100 Hz
  // for(double dt = 0.01; dt<= 20 ; dt+=0.01)
  // {
  //   aml::Vector3 attitude_dot = aml::eulerAngleRatesXYZ(attitude, omega_body); 
  //   attitude =  aml::eulerIntegration(attitude,attitude_dot,dt_step);
  //   time.push_back(dt);
  //   // Attention le resultat des angles est en radian donc on doit les convertire
  //   phi.push_back(aml::radToDeg(attitude.phi()));
  //   theta.push_back(aml::radToDeg(attitude.theta()));
  //   psi.push_back(aml::radToDeg(attitude.psi()));
  // }

  // // for(const auto& yaw : psi)
  // // {
  // //   std::cout <<yaw << std::endl;
  // // }

  // plot(time,phi)->line_width(2).color("red");
  // hold(on);
  // plot(time,theta)->line_width(2).color("blue");
  // plot(time,psi)->line_width(2).color("green");
  // legend("Roll", "Pitch","Yaw");
  // title("Attitude Plot");
  // xlabel("time in s");
  // ylabel("Angle ° Deg");
  // show();

  // Start Attitude
  aml::Euler attitude_0;
  // End Attitude
  aml::Euler attitude_1(aml::degToRad(-30),
                        aml::degToRad(45),
                        aml::degToRad(135));
  attitude_0.display();
  attitude_1.display();

  aml::Euler attitude_interp = aml::linearInterpolate(attitude_0, attitude_1, 0.5);
  attitude_interp.display();
  return 0;
}