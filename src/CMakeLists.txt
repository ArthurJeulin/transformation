# **********************************************************
#      2024 : Arthur JEULIN
#      Copyright (c) Arthur JEULIN
#      Created by Arthur JEULIN on 04/30/2024.
# **********************************************************
#
# Module : Create a Parking library
#
cmake_minimum_required(VERSION 3.27.5)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

set(library_name aml)

add_library(${library_name} 
  aml.cpp
)

target_include_directories(${library_name} PUBLIC 
  ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(${library_name} PUBLIC
  Eigen3::Eigen 
  )
target_compile_features(${library_name} PUBLIC cxx_std_17)

install(TARGETS ${library_name})
