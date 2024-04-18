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
  aml::Vector3 v1(1.0,2.0,3.0);
  aml::Vector3 v2(4.0,5.0,6.0);
  aml::Vector3 v3 = v1 + v2 ;
  aml::Vector3 v4 = v3 * v1 ;

  std::cout << v1 <<std::endl;
  std::cout << v2 <<std::endl;
  std::cout << v3 <<std::endl;
  std::cout << v4 <<std::endl;

  return 0;
}