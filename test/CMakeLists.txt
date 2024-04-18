# **********************************************************
#      2024 : Arthur JEULIN
#      Copyright (c) Arthur JEULIN
#      Created by Arthur JEULIN on 04/30/2024.
# **********************************************************
cmake_minimum_required(VERSION 3.27.5)
#Set the name of the test file
set(test aml_test)

add_executable(${test} ${test}.cpp)

target_include_directories(${test} PRIVATE
  ${CMAKE_SOURCE_DIR}/include
)
target_link_libraries(${test} PRIVATE 
  aml        # Library we are testing
  GTest::gtest 
  GTest::gtest_main 
  GTest::gmock 
  GTest::gmock_main
)
include(GoogleTest)
gtest_discover_tests(${test})
