// **********************************************************
//      2024 : Arthur JEULIN
//      Copyright (c) Arthur JEULIN 
//      Created by Arthur JEULIN on 18/04/2024.
// **********************************************************
//

#include <iostream>
#include <string>

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
  return 0;
}