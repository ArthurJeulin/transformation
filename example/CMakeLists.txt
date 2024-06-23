# **********************************************************
#      2024 : Arthur JEULIN
#      Copyright (c) Arthur JEULIN
#      Created by Arthur JEULIN on 04/30/2024.
# **********************************************************
#
# Module :
#
cmake_minimum_required(VERSION 3.27.5)

find_package(Matplot++ REQUIRED)

add_executable(aml_example 
  main.cpp
)

target_include_directories(aml_example PRIVATE 
  ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(aml_example PRIVATE
  aml
  Matplot++::cimg 
  Matplot++::matplot
)
target_compile_features(aml_example PRIVATE cxx_std_17)

install(TARGETS aml_example)