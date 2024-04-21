#include <gtest/gtest.h>
#include "aml.h"

namespace aml
{
  TEST(ClassMatrix33Test,Constructor)
  {
    // Case 1
  Matrix33 m;
  ASSERT_EQ(m.m11 , 0.0);
  ASSERT_EQ(m.m12 , 0.0);
  ASSERT_EQ(m.m13 , 0.0);
  ASSERT_EQ(m.m21 , 0.0);
  ASSERT_EQ(m.m22 , 0.0);
  ASSERT_EQ(m.m23 , 0.0);
  ASSERT_EQ(m.m31 , 0.0);
  ASSERT_EQ(m.m32 , 0.0);
  ASSERT_EQ(m.m33 , 0.0);
  // Case 2
  m = Matrix33(5.0);
  ASSERT_EQ(m.m11 , 5.0);
  ASSERT_EQ(m.m12 , 5.0);
  ASSERT_EQ(m.m13 , 5.0);
  ASSERT_EQ(m.m21 , 5.0);
  ASSERT_EQ(m.m22 , 5.0);
  ASSERT_EQ(m.m23 , 5.0);
  ASSERT_EQ(m.m31 , 5.0);
  ASSERT_EQ(m.m32 , 5.0);
  ASSERT_EQ(m.m33 , 5.0);
  // Case 3
  double data1d[9] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
  m = Matrix33(data1d);
  ASSERT_EQ(m.m11 , 1.0);
  ASSERT_EQ(m.m12 , 2.0);
  ASSERT_EQ(m.m13 , 3.0);
  ASSERT_EQ(m.m21 , 4.0);
  ASSERT_EQ(m.m22 , 5.0);
  ASSERT_EQ(m.m23 , 6.0);
  ASSERT_EQ(m.m31 , 7.0);
  ASSERT_EQ(m.m32 , 8.0);
  ASSERT_EQ(m.m33 , 9.0);
  // Case 4
  double data2d[3][3] = {{1.0,2.0,3.0},{4.0,5.0,6.0},{7.0,8.0,9.0}};
  m = Matrix33(data2d);
  ASSERT_EQ(m.m11 , 1.0);
  ASSERT_EQ(m.m12 , 2.0);
  ASSERT_EQ(m.m13 , 3.0);
  ASSERT_EQ(m.m21 , 4.0);
  ASSERT_EQ(m.m22 , 5.0);
  ASSERT_EQ(m.m23 , 6.0);
  ASSERT_EQ(m.m31 , 7.0);
  ASSERT_EQ(m.m32 , 8.0);
  ASSERT_EQ(m.m33 , 9.0);
  ASSERT_EQ(m.data[0][0] , 1.0);
  ASSERT_EQ(m.data[0][1] , 2.0);
  ASSERT_EQ(m.data[0][2] , 3.0);
  ASSERT_EQ(m.data[1][0] , 4.0);
  ASSERT_EQ(m.data[1][1] , 5.0);
  ASSERT_EQ(m.data[1][2] , 6.0);
  ASSERT_EQ(m.data[2][0] , 7.0);
  ASSERT_EQ(m.data[2][1] , 8.0);
  ASSERT_EQ(m.data[2][2] , 9.0);
  // Case 5
  Vector3 v1(1.0,4.0,7.0);
  Vector3 v2(2.0,5.0,8.0);
  Vector3 v3(3.0,6.0,9.0);
  m = Matrix33(v1,v2,v3);
  ASSERT_EQ(m.m11 , 1.0);
  ASSERT_EQ(m.m12 , 2.0);
  ASSERT_EQ(m.m13 , 3.0);
  ASSERT_EQ(m.m21 , 4.0);
  ASSERT_EQ(m.m22 , 5.0);
  ASSERT_EQ(m.m23 , 6.0);
  ASSERT_EQ(m.m31 , 7.0);
  ASSERT_EQ(m.m32 , 8.0);
  ASSERT_EQ(m.m33 , 9.0);
}
TEST(Matrix33Test,Matrix33AdditionOperatorAssignmentwithMatrix33)
{
    // Case 1
    double data1[3][3] = {{1.0,2.0,3.0}, {4.0,5.0,6.0}, {7.0,8.0,9.0}};
    double data2[3][3] = {{1.5,2.5,3.5}, {4.5,5.5,6.5}, {7.5,8.5,9.5}};
    Matrix33 m1(data1);
    Matrix33 m2(data2);
    Matrix33 m = m1 += m2;

    EXPECT_NEAR(m.m11 , 2.5, 1e-5);
    EXPECT_NEAR(m.m12 , 4.5, 1e-5);
    EXPECT_NEAR(m.m13 , 6.5, 1e-5);
    EXPECT_NEAR(m.m21 , 8.5, 1e-5);
    EXPECT_NEAR(m.m22 , 10.5, 1e-5);
    EXPECT_NEAR(m.m23 , 12.5, 1e-5);
    EXPECT_NEAR(m.m31 , 14.5, 1e-5);
    EXPECT_NEAR(m.m32 , 16.5, 1e-5);
    EXPECT_NEAR(m.m33 , 18.5, 1e-5);

    EXPECT_NEAR(m1.m11 , 2.5, 1e-5);
    EXPECT_NEAR(m1.m12 , 4.5, 1e-5);
    EXPECT_NEAR(m1.m13 , 6.5, 1e-5);
    EXPECT_NEAR(m1.m21 , 8.5, 1e-5);
    EXPECT_NEAR(m1.m22 , 10.5, 1e-5);
    EXPECT_NEAR(m1.m23 , 12.5, 1e-5);
    EXPECT_NEAR(m1.m31 , 14.5, 1e-5);
    EXPECT_NEAR(m1.m32 , 16.5, 1e-5);
    EXPECT_NEAR(m1.m33 , 18.5, 1e-5);
}

TEST(Matrix33Test,Matrix33SubtractionOperatorAssignmentwithMatrix33)
{
    // Case 1
    double data1[3][3] = {{1.0,2.0,3.0}, {4.0,5.0,6.0}, {7.0,8.0,9.0}};
    double data2[3][3] = {{1.5,2.5,3.5}, {4.5,5.5,6.5}, {7.5,8.5,9.5}};
    Matrix33 m1(data1);
    Matrix33 m2(data2);
    Matrix33 m = m1 -= m2;

    EXPECT_NEAR(m1.m11 , -0.5, 1e-5);
    EXPECT_NEAR(m1.m12 , -0.5, 1e-5);
    EXPECT_NEAR(m1.m13 , -0.5, 1e-5);
    EXPECT_NEAR(m1.m21 , -0.5, 1e-5);
    EXPECT_NEAR(m1.m22 , -0.5, 1e-5);
    EXPECT_NEAR(m1.m23 , -0.5, 1e-5);
    EXPECT_NEAR(m1.m31 , -0.5, 1e-5);
    EXPECT_NEAR(m1.m32 , -0.5, 1e-5);
    EXPECT_NEAR(m1.m33 , -0.5, 1e-5);

    EXPECT_NEAR(m1.m11 , m.m11, 1e-5);
    EXPECT_NEAR(m1.m12 , m.m12, 1e-5);
    EXPECT_NEAR(m1.m13 , m.m13, 1e-5);
    EXPECT_NEAR(m1.m21 , m.m21, 1e-5);
    EXPECT_NEAR(m1.m22 , m.m22, 1e-5);
    EXPECT_NEAR(m1.m23 , m.m23, 1e-5);
    EXPECT_NEAR(m1.m31 , m.m31, 1e-5);
    EXPECT_NEAR(m1.m32 , m.m32, 1e-5);
    EXPECT_NEAR(m1.m33 , m.m33, 1e-5);
}

TEST(Matrix33Test,Matrix33MultiplicationOperatorAssignmentwithMatrix33)
{
    // Case 1
    double data1[3][3] = {{1.0,2.0,3.0}, {4.0,5.0,6.0}, {7.0,8.0,9.0}};
    double data2[3][3] = {{1.5,2.5,3.5}, {4.5,5.5,6.5}, {7.5,8.5,9.5}};
    Matrix33 m1(data1);
    Matrix33 m2(data2);
    Matrix33 m = m1 *= m2;

    EXPECT_NEAR(m1.m11 , 33.0, 1e-5);
    EXPECT_NEAR(m1.m12 , 39.0, 1e-5);
    EXPECT_NEAR(m1.m13 , 45.0, 1e-5);
    EXPECT_NEAR(m1.m21 , 73.5, 1e-5);
    EXPECT_NEAR(m1.m22 , 88.5, 1e-5);
    EXPECT_NEAR(m1.m23 , 103.5, 1e-5);
    EXPECT_NEAR(m1.m31 , 114.0, 1e-5);
    EXPECT_NEAR(m1.m32 , 138.0, 1e-5);
    EXPECT_NEAR(m1.m33 , 162., 1e-5);

    EXPECT_NEAR(m1.m11 , m.m11, 1e-5);
    EXPECT_NEAR(m1.m12 , m.m12, 1e-5);
    EXPECT_NEAR(m1.m13 , m.m13, 1e-5);
    EXPECT_NEAR(m1.m21 , m.m21, 1e-5);
    EXPECT_NEAR(m1.m22 , m.m22, 1e-5);
    EXPECT_NEAR(m1.m23 , m.m23, 1e-5);
    EXPECT_NEAR(m1.m31 , m.m31, 1e-5);
    EXPECT_NEAR(m1.m32 , m.m32, 1e-5);
    EXPECT_NEAR(m1.m33 , m.m33, 1e-5);
}

TEST(Matrix33Test,Matrix33DivisionOperatorAssignmentwithMatrix33)
{
    // Case 1
    double data1[3][3] = {{-2.0,-3.0,2.0}, {1.0,0.0,1.0}, {6.0,-8.0,7.0}};
    double data2[3][3] = {{-2.0,2.0,3.0}, {-1.0,1.0,3.0}, {2.0,0.0,-1.0}};
    Matrix33 m1(data1);
    Matrix33 m2(data2);
    Matrix33 m = m1 /= m2;

    EXPECT_NEAR(m1.m11 , -17.0/6.0, 1e-5);
    EXPECT_NEAR(m1.m12 , 8.0/3.0, 1e-5);
    EXPECT_NEAR(m1.m13 , -5.0/2.0, 1e-5);
    EXPECT_NEAR(m1.m21 , -0.5, 1e-5);
    EXPECT_NEAR(m1.m22 , 1.0, 1e-5);
    EXPECT_NEAR(m1.m23 , 0.5, 1e-5);
    EXPECT_NEAR(m1.m31 , -10.0, 1e-5);
    EXPECT_NEAR(m1.m32 , 12.0, 1e-5);
    EXPECT_NEAR(m1.m33 , -1.0, 1e-5);

    EXPECT_NEAR(m1.m11 , m.m11, 1e-5);
    EXPECT_NEAR(m1.m12 , m.m12, 1e-5);
    EXPECT_NEAR(m1.m13 , m.m13, 1e-5);
    EXPECT_NEAR(m1.m21 , m.m21, 1e-5);
    EXPECT_NEAR(m1.m22 , m.m22, 1e-5);
    EXPECT_NEAR(m1.m23 , m.m23, 1e-5);
    EXPECT_NEAR(m1.m31 , m.m31, 1e-5);
    EXPECT_NEAR(m1.m32 , m.m32, 1e-5);
    EXPECT_NEAR(m1.m33 , m.m33, 1e-5);
}

TEST(Matrix33Test,Matrix33AdditionOperatorAssignmentwithScalar)
{
    // Case 1
    double data1[3][3] = {{-2.0,-3.0,2.0}, {1.0,0.0,1.0}, {6.0,-8.0,7.0}};
    Matrix33 m1(data1);
    Matrix33 m = m1 += 0.5;

    EXPECT_NEAR(m1.m11 , -1.5, 1e-5);
    EXPECT_NEAR(m1.m12 , -2.5, 1e-5);
    EXPECT_NEAR(m1.m13 , 2.5, 1e-5);
    EXPECT_NEAR(m1.m21 , 1.5, 1e-5);
    EXPECT_NEAR(m1.m22 , 0.5, 1e-5);
    EXPECT_NEAR(m1.m23 , 1.5, 1e-5);
    EXPECT_NEAR(m1.m31 , 6.5, 1e-5);
    EXPECT_NEAR(m1.m32 , -7.5, 1e-5);
    EXPECT_NEAR(m1.m33 , 7.5, 1e-5);

    EXPECT_NEAR(m1.m11 , m.m11, 1e-5);
    EXPECT_NEAR(m1.m12 , m.m12, 1e-5);
    EXPECT_NEAR(m1.m13 , m.m13, 1e-5);
    EXPECT_NEAR(m1.m21 , m.m21, 1e-5);
    EXPECT_NEAR(m1.m22 , m.m22, 1e-5);
    EXPECT_NEAR(m1.m23 , m.m23, 1e-5);
    EXPECT_NEAR(m1.m31 , m.m31, 1e-5);
    EXPECT_NEAR(m1.m32 , m.m32, 1e-5);
    EXPECT_NEAR(m1.m33 , m.m33, 1e-5);
}

TEST(Matrix33Test,Matrix33SubtractionOperatorAssignmentwithScalar)
{
    // Case 1
    double data1[3][3] = {{-2.0,-3.0,2.0}, {1.0,0.0,1.0}, {6.0,-8.0,7.0}};
    Matrix33 m1(data1);
    Matrix33 m = m1 -= 0.5;

    EXPECT_NEAR(m1.m11 , -2.5, 1e-5);
    EXPECT_NEAR(m1.m12 , -3.5, 1e-5);
    EXPECT_NEAR(m1.m13 , 1.5, 1e-5);
    EXPECT_NEAR(m1.m21 , 0.5, 1e-5);
    EXPECT_NEAR(m1.m22 , -0.5, 1e-5);
    EXPECT_NEAR(m1.m23 , 0.5, 1e-5);
    EXPECT_NEAR(m1.m31 , 5.5, 1e-5);
    EXPECT_NEAR(m1.m32 , -8.5, 1e-5);
    EXPECT_NEAR(m1.m33 , 6.5, 1e-5);

    EXPECT_NEAR(m1.m11 , m.m11, 1e-5);
    EXPECT_NEAR(m1.m12 , m.m12, 1e-5);
    EXPECT_NEAR(m1.m13 , m.m13, 1e-5);
    EXPECT_NEAR(m1.m21 , m.m21, 1e-5);
    EXPECT_NEAR(m1.m22 , m.m22, 1e-5);
    EXPECT_NEAR(m1.m23 , m.m23, 1e-5);
    EXPECT_NEAR(m1.m31 , m.m31, 1e-5);
    EXPECT_NEAR(m1.m32 , m.m32, 1e-5);
    EXPECT_NEAR(m1.m33 , m.m33, 1e-5);
}

TEST(Matrix33Test,Matrix33MultiplicationOperatorAssignmentwithScalar)
{
    // Case 1
    double data1[3][3] = {{-2.0,-3.0,2.0}, {1.0,0.0,1.0}, {6.0,-8.0,7.0}};
    Matrix33 m1(data1);
    Matrix33 m = m1 *= 0.5;

    EXPECT_NEAR(m1.m11 , -1.0, 1e-5);
    EXPECT_NEAR(m1.m12 , -1.5, 1e-5);
    EXPECT_NEAR(m1.m13 , 1.0, 1e-5);
    EXPECT_NEAR(m1.m21 , 0.5, 1e-5);
    EXPECT_NEAR(m1.m22 , 0.0, 1e-5);
    EXPECT_NEAR(m1.m23 , 0.5, 1e-5);
    EXPECT_NEAR(m1.m31 , 3.0, 1e-5);
    EXPECT_NEAR(m1.m32 , -4.0, 1e-5);
    EXPECT_NEAR(m1.m33 , 3.5, 1e-5);

    EXPECT_NEAR(m1.m11 , m.m11, 1e-5);
    EXPECT_NEAR(m1.m12 , m.m12, 1e-5);
    EXPECT_NEAR(m1.m13 , m.m13, 1e-5);
    EXPECT_NEAR(m1.m21 , m.m21, 1e-5);
    EXPECT_NEAR(m1.m22 , m.m22, 1e-5);
    EXPECT_NEAR(m1.m23 , m.m23, 1e-5);
    EXPECT_NEAR(m1.m31 , m.m31, 1e-5);
    EXPECT_NEAR(m1.m32 , m.m32, 1e-5);
    EXPECT_NEAR(m1.m33 , m.m33, 1e-5);
}

TEST(Matrix33Test,Matrix33DivisionOperatorAssignmentwithScalar)
{
    // Case 1
    double data1[3][3] = {{-2.0,-3.0,2.0}, {1.0,0.0,1.0}, {6.0,-8.0,7.0}};
    Matrix33 m1(data1);
    Matrix33 m = m1 /= 0.5;

    EXPECT_NEAR(m1.m11 , -4.0, 1e-5);
    EXPECT_NEAR(m1.m12 , -6.0, 1e-5);
    EXPECT_NEAR(m1.m13 , 4.0, 1e-5);
    EXPECT_NEAR(m1.m21 , 2.0, 1e-5);
    EXPECT_NEAR(m1.m22 , 0.0, 1e-5);
    EXPECT_NEAR(m1.m23 , 2.0, 1e-5);
    EXPECT_NEAR(m1.m31 , 12.0, 1e-5);
    EXPECT_NEAR(m1.m32 , -16.0, 1e-5);
    EXPECT_NEAR(m1.m33 , 14.0, 1e-5);

    EXPECT_NEAR(m1.m11 , m.m11, 1e-5);
    EXPECT_NEAR(m1.m12 , m.m12, 1e-5);
    EXPECT_NEAR(m1.m13 , m.m13, 1e-5);
    EXPECT_NEAR(m1.m21 , m.m21, 1e-5);
    EXPECT_NEAR(m1.m22 , m.m22, 1e-5);
    EXPECT_NEAR(m1.m23 , m.m23, 1e-5);
    EXPECT_NEAR(m1.m31 , m.m31, 1e-5);
    EXPECT_NEAR(m1.m32 , m.m32, 1e-5);
    EXPECT_NEAR(m1.m33 , m.m33, 1e-5);
}

TEST(Matrix33Test,Matrix33Identity)
{
    // Case 1
    Matrix33 m = Matrix33::identity();

    EXPECT_NEAR(m.m11 , 1.0, 1e-5);
    EXPECT_NEAR(m.m12 , 0.0, 1e-5);
    EXPECT_NEAR(m.m13 , 0.0, 1e-5);
    EXPECT_NEAR(m.m21 , 0.0, 1e-5);
    EXPECT_NEAR(m.m22 , 1.0, 1e-5);
    EXPECT_NEAR(m.m23 , 0.0, 1e-5);
    EXPECT_NEAR(m.m31 , 0.0, 1e-5);
    EXPECT_NEAR(m.m32 , 0.0, 1e-5);
    EXPECT_NEAR(m.m33 , 1.0, 1e-5);
}

TEST(Matrix33Test,Matrix33NegativeOperator)
{
    // Case 1
    double data1[3][3] = {{-2.0,-3.0,2.0}, {1.0,0.0,1.0}, {6.0,-8.0,7.0}};
    Matrix33 m = -Matrix33(data1);

    EXPECT_NEAR(m.m11 , 2.0, 1e-5);
    EXPECT_NEAR(m.m12 , 3.0, 1e-5);
    EXPECT_NEAR(m.m13 , -2.0, 1e-5);
    EXPECT_NEAR(m.m21 , -1.0, 1e-5);
    EXPECT_NEAR(m.m22 , 0.0, 1e-5);
    EXPECT_NEAR(m.m23 , -1.0, 1e-5);
    EXPECT_NEAR(m.m31 , -6.0, 1e-5);
    EXPECT_NEAR(m.m32 , 8.0, 1e-5);
    EXPECT_NEAR(m.m33 , -7.0, 1e-5);
}

TEST(Matrix33Test,Matrix33AdditionOperatorwithMatrix33)
{
    // Case 1
    double data1[3][3] = {{1.0,2.0,3.0}, {4.0,5.0,6.0}, {7.0,8.0,9.0}};
    double data2[3][3] = {{1.5,2.5,3.5}, {4.5,5.5,6.5}, {7.5,8.5,9.5}};
    Matrix33 m1(data1);
    Matrix33 m2(data2);
    Matrix33 m = m1 + m2;

    EXPECT_NEAR(m.m11 , 2.5, 1e-5);
    EXPECT_NEAR(m.m12 , 4.5, 1e-5);
    EXPECT_NEAR(m.m13 , 6.5, 1e-5);
    EXPECT_NEAR(m.m21 , 8.5, 1e-5);
    EXPECT_NEAR(m.m22 , 10.5, 1e-5);
    EXPECT_NEAR(m.m23 , 12.5, 1e-5);
    EXPECT_NEAR(m.m31 , 14.5, 1e-5);
    EXPECT_NEAR(m.m32 , 16.5, 1e-5);
    EXPECT_NEAR(m.m33 , 18.5, 1e-5);
}

TEST(Matrix33Test,Matrix33SubtractionOperatorwithMatrix33)
{
    // Case 1
    double data1[3][3] = {{1.0,2.0,3.0}, {4.0,5.0,6.0}, {7.0,8.0,9.0}};
    double data2[3][3] = {{1.5,2.5,3.5}, {4.5,5.5,6.5}, {7.5,8.5,9.5}};
    Matrix33 m1(data1);
    Matrix33 m2(data2);
    Matrix33 m = m1 - m2;

    EXPECT_NEAR(m.m11 , -0.5, 1e-5);
    EXPECT_NEAR(m.m12 , -0.5, 1e-5);
    EXPECT_NEAR(m.m13 , -0.5, 1e-5);
    EXPECT_NEAR(m.m21 , -0.5, 1e-5);
    EXPECT_NEAR(m.m22 , -0.5, 1e-5);
    EXPECT_NEAR(m.m23 , -0.5, 1e-5);
    EXPECT_NEAR(m.m31 , -0.5, 1e-5);
    EXPECT_NEAR(m.m32 , -0.5, 1e-5);
    EXPECT_NEAR(m.m33 , -0.5, 1e-5);
}

TEST(Matrix33Test,Matrix33MultiplicationOperatorwithMatrix33)
{
    // Case 1
    double data1[3][3] = {{1.0,2.0,3.0}, {4.0,5.0,6.0}, {7.0,8.0,9.0}};
    double data2[3][3] = {{1.5,2.5,3.5}, {4.5,5.5,6.5}, {7.5,8.5,9.5}};
    Matrix33 m1(data1);
    Matrix33 m2(data2);
    Matrix33 m = m1 * m2;

    EXPECT_NEAR(m.m11 , 33.0, 1e-5);
    EXPECT_NEAR(m.m12 , 39.0, 1e-5);
    EXPECT_NEAR(m.m13 , 45.0, 1e-5);
    EXPECT_NEAR(m.m21 , 73.5, 1e-5);
    EXPECT_NEAR(m.m22 , 88.5, 1e-5);
    EXPECT_NEAR(m.m23 , 103.5, 1e-5);
    EXPECT_NEAR(m.m31 , 114.0, 1e-5);
    EXPECT_NEAR(m.m32 , 138.0, 1e-5);
    EXPECT_NEAR(m.m33 , 162., 1e-5);
}

TEST(Matrix33Test,Matrix33DivisionOperatorwithMatrix33)
{
    // Case 1
    double data1[3][3] = {{-2.0,-3.0,2.0}, {1.0,0.0,1.0}, {6.0,-8.0,7.0}};
    double data2[3][3] = {{-2.0,2.0,3.0}, {-1.0,1.0,3.0}, {2.0,0.0,-1.0}};
    Matrix33 m1(data1);
    Matrix33 m2(data2);
    Matrix33 m = m1 / m2;

    EXPECT_NEAR(m.m11 , -17.0/6.0, 1e-5);
    EXPECT_NEAR(m.m12 , 8.0/3.0, 1e-5);
    EXPECT_NEAR(m.m13 , -5.0/2.0, 1e-5);
    EXPECT_NEAR(m.m21 , -0.5, 1e-5);
    EXPECT_NEAR(m.m22 , 1.0, 1e-5);
    EXPECT_NEAR(m.m23 , 0.5, 1e-5);
    EXPECT_NEAR(m.m31 , -10.0, 1e-5);
    EXPECT_NEAR(m.m32 , 12.0, 1e-5);
    EXPECT_NEAR(m.m33 , -1.0, 1e-5);
}

TEST(Matrix33Test,Matrix33MultiplicationOperatorwithVector3)
{
    // Case 1
    double data1[3][3] = {{-2.0,-3.0,2.0}, {1.0,0.0,1.0}, {6.0,-8.0,7.0}};
    double data2[3] = {-2.0,2.0,3.0};
    Matrix33 m1(data1);
    Vector3  v1(data2);
    Vector3  v = m1 * v1;

    EXPECT_NEAR(v.x , 4.0, 1e-5);
    EXPECT_NEAR(v.y , 1.0, 1e-5);
    EXPECT_NEAR(v.z , -7.0, 1e-5);
}

TEST(Matrix33Test,Matrix33AdditionOperatorwithScalar)
{
    double data1[3][3] = {{-2.0,-3.0,2.0}, {1.0,0.0,1.0}, {6.0,-8.0,7.0}};
    Matrix33 m1(data1);

    // Case 1
    Matrix33 m = m1 + 0.5;
    EXPECT_NEAR(m.m11 , -1.5, 1e-5);
    EXPECT_NEAR(m.m12 , -2.5, 1e-5);
    EXPECT_NEAR(m.m13 , 2.5, 1e-5);
    EXPECT_NEAR(m.m21 , 1.5, 1e-5);
    EXPECT_NEAR(m.m22 , 0.5, 1e-5);
    EXPECT_NEAR(m.m23 , 1.5, 1e-5);
    EXPECT_NEAR(m.m31 , 6.5, 1e-5);
    EXPECT_NEAR(m.m32 , -7.5, 1e-5);
    EXPECT_NEAR(m.m33 , 7.5, 1e-5);

    // Case 2
    m = 0.5 + m1;
    EXPECT_NEAR(m.m11 , -1.5, 1e-5);
    EXPECT_NEAR(m.m12 , -2.5, 1e-5);
    EXPECT_NEAR(m.m13 , 2.5, 1e-5);
    EXPECT_NEAR(m.m21 , 1.5, 1e-5);
    EXPECT_NEAR(m.m22 , 0.5, 1e-5);
    EXPECT_NEAR(m.m23 , 1.5, 1e-5);
    EXPECT_NEAR(m.m31 , 6.5, 1e-5);
    EXPECT_NEAR(m.m32 , -7.5, 1e-5);
    EXPECT_NEAR(m.m33 , 7.5, 1e-5);

}

TEST(Matrix33Test,Matrix33SubtractionOperatorwithScalar)
{
    double data1[3][3] = {{-2.0,-3.0,2.0}, {1.0,0.0,1.0}, {6.0,-8.0,7.0}};
    Matrix33 m1(data1);

    // Case 1
    Matrix33 m = m1 - 0.5;
    EXPECT_NEAR(m.m11 , -2.5, 1e-5);
    EXPECT_NEAR(m.m12 , -3.5, 1e-5);
    EXPECT_NEAR(m.m13 , 1.5, 1e-5);
    EXPECT_NEAR(m.m21 , 0.5, 1e-5);
    EXPECT_NEAR(m.m22 , -0.5, 1e-5);
    EXPECT_NEAR(m.m23 , 0.5, 1e-5);
    EXPECT_NEAR(m.m31 , 5.5, 1e-5);
    EXPECT_NEAR(m.m32 , -8.5, 1e-5);
    EXPECT_NEAR(m.m33 , 6.5, 1e-5);

    // Case 2
    m = 0.5 - m1;
    EXPECT_NEAR(m.m11 , 2.5, 1e-5);
    EXPECT_NEAR(m.m12 , 3.5, 1e-5);
    EXPECT_NEAR(m.m13 , -1.5, 1e-5);
    EXPECT_NEAR(m.m21 , -0.5, 1e-5);
    EXPECT_NEAR(m.m22 , 0.5, 1e-5);
    EXPECT_NEAR(m.m23 , -0.5, 1e-5);
    EXPECT_NEAR(m.m31 , -5.5, 1e-5);
    EXPECT_NEAR(m.m32 , 8.5, 1e-5);
    EXPECT_NEAR(m.m33 , -6.5, 1e-5);
}

TEST(Matrix33Test,Matrix33MultiplicationOperatorwithScalar)
{
    double data1[3][3] = {{-2.0,-3.0,2.0}, {1.0,0.0,1.0}, {6.0,-8.0,7.0}};
    Matrix33 m1(data1);

    // Case 1
    Matrix33 m = m1 * 0.5;
    EXPECT_NEAR(m.m11 , -1.0, 1e-5);
    EXPECT_NEAR(m.m12 , -1.5, 1e-5);
    EXPECT_NEAR(m.m13 , 1.0, 1e-5);
    EXPECT_NEAR(m.m21 , 0.5, 1e-5);
    EXPECT_NEAR(m.m22 , 0.0, 1e-5);
    EXPECT_NEAR(m.m23 , 0.5, 1e-5);
    EXPECT_NEAR(m.m31 , 3.0, 1e-5);
    EXPECT_NEAR(m.m32 , -4.0, 1e-5);
    EXPECT_NEAR(m.m33 , 3.5, 1e-5);

    // Case 1
    m = 0.5 * m1;
    EXPECT_NEAR(m.m11 , -1.0, 1e-5);
    EXPECT_NEAR(m.m12 , -1.5, 1e-5);
    EXPECT_NEAR(m.m13 , 1.0, 1e-5);
    EXPECT_NEAR(m.m21 , 0.5, 1e-5);
    EXPECT_NEAR(m.m22 , 0.0, 1e-5);
    EXPECT_NEAR(m.m23 , 0.5, 1e-5);
    EXPECT_NEAR(m.m31 , 3.0, 1e-5);
    EXPECT_NEAR(m.m32 , -4.0, 1e-5);
    EXPECT_NEAR(m.m33 , 3.5, 1e-5);
}

TEST(Matrix33Test,Matrix33DivisionOperatorwithScalar)
{
    double data1[3][3] = {{-2.0,-3.0,2.0}, {1.0,-1.0,1.0}, {6.0,-8.0,7.0}};
    Matrix33 m1(data1);

    // Case 1
    Matrix33 m = m1 / 0.5;
    EXPECT_NEAR(m.m11 , -4.0, 1e-5);
    EXPECT_NEAR(m.m12 , -6.0, 1e-5);
    EXPECT_NEAR(m.m13 , 4.0, 1e-5);
    EXPECT_NEAR(m.m21 , 2.0, 1e-5);
    EXPECT_NEAR(m.m22 , -2.0, 1e-5);
    EXPECT_NEAR(m.m23 , 2.0, 1e-5);
    EXPECT_NEAR(m.m31 , 12.0, 1e-5);
    EXPECT_NEAR(m.m32 , -16.0, 1e-5);
    EXPECT_NEAR(m.m33 , 14.0, 1e-5);

    // Case 2
    m = 0.5 / m1;
    EXPECT_NEAR(m.m11 , 0.5/-2.0, 1e-5);
    EXPECT_NEAR(m.m12 , 0.5/-3.0, 1e-5);
    EXPECT_NEAR(m.m13 , 0.5/2.0, 1e-5);
    EXPECT_NEAR(m.m21 , 0.5/1.0, 1e-5);
    EXPECT_NEAR(m.m22 , 0.5/-1.0, 1e-5);
    EXPECT_NEAR(m.m23 , 0.5/1.0, 1e-5);
    EXPECT_NEAR(m.m31 , 0.5/6.0, 1e-5);
    EXPECT_NEAR(m.m32 , 0.5/-8.0, 1e-5);
    EXPECT_NEAR(m.m33 , 0.5/7.0, 1e-5);
}

TEST(Matrix33Test,Matrix33DiagofMatrix33)
{
    // Case 1
    double data1[3][3] = {{-2.0,-3.0,2.0}, {1.0,0.0,1.0}, {6.0,-8.0,7.0}};
    Vector3 m = diag(Matrix33(data1));

    EXPECT_NEAR(m.x , -2.0, 1e-5);
    EXPECT_NEAR(m.y , 0.0, 1e-5);
    EXPECT_NEAR(m.z , 7.0, 1e-5);

}

TEST(Matrix33Test,Matrix33Vector3toDiagMatrix33)
{
    // Case 1
    double data[3] = {-2.0,-3.0,2.0};
    Vector3 v = Vector3(data);
    Matrix33 m = diag(v);

    EXPECT_NEAR(m.m11 , -2.0, 1e-5);
    EXPECT_NEAR(m.m12 , 0.0, 1e-5);
    EXPECT_NEAR(m.m13 , 0.0, 1e-5);
    EXPECT_NEAR(m.m21 , 0.0, 1e-5);
    EXPECT_NEAR(m.m22 , -3.0, 1e-5);
    EXPECT_NEAR(m.m23 , 0.0, 1e-5);
    EXPECT_NEAR(m.m31 , 0.0, 1e-5);
    EXPECT_NEAR(m.m32 , 0.0, 1e-5);
    EXPECT_NEAR(m.m33 , 2.0, 1e-5);

}

TEST(Matrix33Test,Matrix33Transpose)
{
    double data1[3][3] = {{-2.0,-3.0,2.0}, {1.0,-1.0,1.0}, {6.0,-8.0,7.0}};
    Matrix33 m1(data1);

    // Case 1
    Matrix33 m = transpose(m1);
    EXPECT_NEAR(m.m11 , -2.0, 1e-5);
    EXPECT_NEAR(m.m21 , -3.0, 1e-5);
    EXPECT_NEAR(m.m31 , 2.0, 1e-5);
    EXPECT_NEAR(m.m12 , 1.0, 1e-5);
    EXPECT_NEAR(m.m22 , -1.0, 1e-5);
    EXPECT_NEAR(m.m32 , 1.0, 1e-5);
    EXPECT_NEAR(m.m13 , 6.0, 1e-5);
    EXPECT_NEAR(m.m23 , -8.0, 1e-5);
    EXPECT_NEAR(m.m33 , 7.0, 1e-5);
}

TEST(Matrix33Test,Matrix33Determinant)
{
    double data1[3][3] = {{-2.0,-3.0,2.0}, {1.0,-1.0,1.0}, {6.0,-8.0,7.0}};
    Matrix33 m1(data1);

    // Case 1
    double det = determinant(m1);
    EXPECT_NEAR(det , -3.0, 1e-5);
}

TEST(Matrix33Test,Matrix33Inverse)
{
    double data1[3][3] = {{-2.0,-3.0,2.0}, {1.0,-1.0,1.0}, {6.0,-8.0,7.0}};
    Matrix33 m1(data1);

    // Case 1
    Matrix33 m = inverse(m1);
    EXPECT_NEAR(m.m11 , -1.0/3.0, 1e-5);
    EXPECT_NEAR(m.m12 , -5.0/3.0, 1e-5);
    EXPECT_NEAR(m.m13 , 1.0/3.0, 1e-5);
    EXPECT_NEAR(m.m21 , 1.0/3.0, 1e-5);
    EXPECT_NEAR(m.m22 , 26.0/3.0, 1e-5);
    EXPECT_NEAR(m.m23 , -4.0/3.0, 1e-5);
    EXPECT_NEAR(m.m31 , 2.0/3.0, 1e-5);
    EXPECT_NEAR(m.m32 , 34.0/3.0, 1e-5);
    EXPECT_NEAR(m.m33 , -5.0/3.0, 1e-5);
}

} //  namespace aml
