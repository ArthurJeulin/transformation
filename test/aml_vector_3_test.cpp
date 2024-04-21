#include <gtest/gtest.h>
#include "aml.h"

namespace aml
{
    TEST(ClassVector3Test,Constructor)
    {
        // Case 1
        Vector3 v;
        EXPECT_NEAR(v.x ,0.0, 1e-5);
        EXPECT_NEAR(v.y ,0.0, 1e-5);
        EXPECT_NEAR(v.z ,0.0, 1e-5);
        // Case 2
        v = Vector3(5.0);
        EXPECT_NEAR(v.x ,5.0, 1e-5);
        EXPECT_NEAR(v.y ,5.0, 1e-5);
        EXPECT_NEAR(v.z ,5.0, 1e-5);
        // Case 3
        v = Vector3(1.0,2.0,3.0);
        EXPECT_NEAR(v.x ,1.0, 1e-5);
        EXPECT_NEAR(v.y ,2.0, 1e-5);
        EXPECT_NEAR(v.z ,3.0, 1e-5);
        // Case 4
        double data[3] = {3.0,2.0,1.0};
        v = Vector3(data);
        EXPECT_NEAR(v.x ,3.0, 1e-5);
        EXPECT_NEAR(v.y ,2.0, 1e-5);
        EXPECT_NEAR(v.z ,1.0, 1e-5);
        
    }

TEST(Vector3Test, PlusScalarAssignments) {
    Vector3 v(2, -5, 4);
    v += 3;
    EXPECT_NEAR(v.x, 5, 1e-5);
    EXPECT_NEAR(v.y, -2, 1e-5);
    EXPECT_NEAR(v.z, 7, 1e-5);

    v = Vector3(0.24, 0.0082, -0.03);
    v += 0.2;
    EXPECT_NEAR(v.x, 0.44, 1e-5);
    EXPECT_NEAR(v.y, 0.2082, 1e-5);
    EXPECT_NEAR(v.z, 0.17, 1e-5);

    v = Vector3(-27, 83, -163);
    v += 13;
    EXPECT_NEAR(v.x, -14, 1e-5);
    EXPECT_NEAR(v.y, 96, 1e-5);
    EXPECT_NEAR(v.z, -150, 1e-5);
}

TEST(Vector3Test, MinusScalarAssignmentsCase1) {
    Vector3 v(2, -5, 4);
    v -= 3;
    EXPECT_NEAR(v.x, -1, 1e-5);
    EXPECT_NEAR(v.y, -8, 1e-5);
    EXPECT_NEAR(v.z, 1, 1e-5);
}

TEST(Vector3Test, MinusScalarAssignmentsCase2) {
    Vector3 v(2, -5, 4);
    v -= 3;
    EXPECT_NEAR(v.x, -1, 1e-5);
    EXPECT_NEAR(v.y, -8, 1e-5);
    EXPECT_NEAR(v.z, 1, 1e-5);

    v = Vector3(0.24, 0.0082, -0.03);
    v -= 0.2;
    EXPECT_NEAR(v.x, 0.04, 1e-5);
    EXPECT_NEAR(v.y, -0.1918, 1e-5);
    EXPECT_NEAR(v.z, -0.23, 1e-5);

    v = Vector3(-27, 83, -163);
    v -= 13;
    EXPECT_NEAR(v.x, -40, 1e-5);
    EXPECT_NEAR(v.y, 70, 1e-5);
    EXPECT_NEAR(v.z, -176, 1e-5);
}

// Conversion of "Vector3 minus scalar" test case
TEST(Vector3Test, MinusScalar) {
    Vector3 v(2, -5, 4);
    v = v - 3;
    EXPECT_NEAR(v.x, -1, 1e-5);
    EXPECT_NEAR(v.y, -8, 1e-5);
    EXPECT_NEAR(v.z, 1, 1e-5);

    v = Vector3(0.24, 0.0082, -0.03);
    v = v - 0.2;
    EXPECT_NEAR(v.x, 0.04, 1e-5);
    EXPECT_NEAR(v.y, -0.1918, 1e-5);
    EXPECT_NEAR(v.z, -0.23, 1e-5);

    v = Vector3(-27, 83, -163);
    v = v - 13;
    EXPECT_NEAR(v.x, -40, 1e-5);
    EXPECT_NEAR(v.y, 70, 1e-5);
    EXPECT_NEAR(v.z, -176, 1e-5);
}

// Conversion of "Vector3 times scalar assignment" test case
TEST(Vector3Test, TimesScalarAssignment) {
    Vector3 v(2, -5, 4);
    v *= 3;
    EXPECT_NEAR(v.x, 6, 1e-5);
    EXPECT_NEAR(v.y, -15, 1e-5);
    EXPECT_NEAR(v.z, 12, 1e-5);

    v = Vector3(0.24, 0.0082, -0.03);
    v *= 0.2;
    EXPECT_NEAR(v.x, 0.048, 1e-5);
    EXPECT_NEAR(v.y, 0.00164, 1e-5);
    EXPECT_NEAR(v.z, -0.006, 1e-5);

    v = Vector3(-27, 83, -163);
    v *= 13;
    EXPECT_NEAR(v.x, -351, 1e-5);
    EXPECT_NEAR(v.y, 1079, 1e-5);
    EXPECT_NEAR(v.z, -2119, 1e-5);
}

// Conversion of "Vector3 times scalar" test case
TEST(Vector3Test, TimesScalar) {
    Vector3 v(2, -5, 4);
    v = v * 3;
    EXPECT_NEAR(v.x, 6, 1e-5);
    EXPECT_NEAR(v.y, -15, 1e-5);
    EXPECT_NEAR(v.z, 12, 1e-5);

    v = Vector3(0.24, 0.0082, -0.03);
    v = v * 0.2;
    EXPECT_NEAR(v.x, 0.048, 1e-5);
    EXPECT_NEAR(v.y, 0.00164, 1e-5);
    EXPECT_NEAR(v.z, -0.006, 1e-5);

    v = Vector3(-27, 83, -163);
    v = v * 13;
    EXPECT_NEAR(v.x, -351, 1e-5);
    EXPECT_NEAR(v.y, 1079, 1e-5);
    EXPECT_NEAR(v.z, -2119, 1e-5);
}


TEST(Vector3Test,Vector3dividedbyscalarCase1)
{
    // Case 1
    Vector3 v = Vector3(2, -5, 4);
    v /= 3;
    EXPECT_NEAR(v.x ,0.66666667, 1e-5);
    EXPECT_NEAR(v.y ,-1.66666667, 1e-5);
    EXPECT_NEAR(v.z ,1.33333333, 1e-5);
    // Case 2
    v = Vector3(0.24, 0.0082, -0.03);
    v /= 0.2;
    EXPECT_NEAR(v.x ,1.2, 1e-5);
    EXPECT_NEAR(v.y ,0.041, 1e-5);
    EXPECT_NEAR(v.z ,-0.15, 1e-5);
    // Case 3
    v = Vector3(-27, 83, -163);
    v /= 13;
    EXPECT_NEAR(v.x ,-2.0769231, 1e-5);
    EXPECT_NEAR(v.y ,6.3846154, 1e-5);
    EXPECT_NEAR(v.z ,-12.538462, 1e-5);
}

TEST(Vector3Test,Vector3dividedbyscalarCase2)
{
    // Case 1
    Vector3 v = Vector3(2, -5, 4);
    v = v / 3;
    EXPECT_NEAR(v.x ,0.66666667, 1e-5);
    EXPECT_NEAR(v.y ,-1.66666667, 1e-5);
    EXPECT_NEAR(v.z ,1.33333333, 1e-5);
    // Case 2
    v = Vector3(0.24, 0.0082, -0.03);
    v = v / 0.2;
    EXPECT_NEAR(v.x ,1.2, 1e-5);
    EXPECT_NEAR(v.y ,0.041, 1e-5);
    EXPECT_NEAR(v.z ,-0.15, 1e-5);
    // Case 3
    v = Vector3(-27, 83, -163);
    v = v / 13;
    EXPECT_NEAR(v.x ,-2.0769231, 1e-5);
    EXPECT_NEAR(v.y ,6.3846154, 1e-5);
    EXPECT_NEAR(v.z ,-12.538462, 1e-5);
}

TEST(Vector3Test,Vector3plusVector3)
{
    // Case 1
    Vector3 v1 = Vector3(2, -5, 4);
    Vector3 v2 = Vector3(6, 2, -8);
    v1 += v2;
    EXPECT_NEAR(v1.x ,8, 1e-5);
    EXPECT_NEAR(v1.y ,-3, 1e-5);
    EXPECT_NEAR(v1.z ,-4, 1e-5);
    // Case 2
    v1 = Vector3(0.24, 0.0082, -0.03);
    v2 = Vector3(0.53, -0.0532, -1.53);
    v1 += v2;
    EXPECT_NEAR(v1.x ,0.77, 1e-5);
    EXPECT_NEAR(v1.y ,-0.045, 1e-5);
    EXPECT_NEAR(v1.z ,-1.56, 1e-5);
    // Case 3
    v1 = Vector3(-27, 83, -163);
    v2 = Vector3(36, -64, 264);
    v1 += v2;
    EXPECT_NEAR(v1.x ,9, 1e-5);
    EXPECT_NEAR(v1.y ,19, 1e-5);
    EXPECT_NEAR(v1.z ,101, 1e-5);
}

TEST(Vector3Test,Vector3plusVector3Case2)
{
    // Case 1
    Vector3 v1 = Vector3(2, -5, 4);
    Vector3 v2 = Vector3(6, 2, -8);
    Vector3 v = v1 + v2;
    EXPECT_NEAR(v.x ,8, 1e-5);
    EXPECT_NEAR(v.y ,-3, 1e-5);
    EXPECT_NEAR(v.z ,-4, 1e-5);
    // Case 2
    v1 = Vector3(0.24, 0.0082, -0.03);
    v2 = Vector3(0.53, -0.0532, -1.53);
    v = v1 + v2;
    EXPECT_NEAR(v.x ,0.77, 1e-5);
    EXPECT_NEAR(v.y ,-0.045, 1e-5);
    EXPECT_NEAR(v.z ,-1.56, 1e-5);
    // Case 3
    v1 = Vector3(-27, 83, -163);
    v2 = Vector3(36, -64, 264);
    v = v1 + v2;
    EXPECT_NEAR(v.x ,9, 1e-5);
    EXPECT_NEAR(v.y ,19, 1e-5);
    EXPECT_NEAR(v.z ,101, 1e-5);
}

TEST(Vector3Test,Vector3minusVector3)
{
    // Case 1
    Vector3 v1 = Vector3(2, -5, 4);
    Vector3 v2 = Vector3(6, 2, -8);
    v1 -= v2;
    EXPECT_NEAR(v1.x ,-4, 1e-5);
    EXPECT_NEAR(v1.y ,-7, 1e-5);
    EXPECT_NEAR(v1.z ,12, 1e-5);
    // Case 2
    v1 = Vector3(0.24, 0.0082, -0.03);
    v2 = Vector3(0.53, -0.0532, -1.53);
    v1 -= v2;
    EXPECT_NEAR(v1.x ,-0.29, 1e-5);
    EXPECT_NEAR(v1.y ,0.0614, 1e-5);
    EXPECT_NEAR(v1.z ,1.5, 1e-5);
    // Case 3
    v1 = Vector3(-27, 83, -163);
    v2 = Vector3(36, -64, 264);
    v1 -= v2;
    EXPECT_NEAR(v1.x ,-63, 1e-5);
    EXPECT_NEAR(v1.y ,147, 1e-5);
    EXPECT_NEAR(v1.z ,-427, 1e-5);
}

TEST(Vector3Test,Vector3minusVector3s)
{
    // Case 1
    Vector3 v1 = Vector3(2, -5, 4);
    Vector3 v2 = Vector3(6, 2, -8);
    Vector3 v = v1 - v2;
    EXPECT_NEAR(v.x ,-4, 1e-5);
    EXPECT_NEAR(v.y ,-7, 1e-5);
    EXPECT_NEAR(v.z ,12, 1e-5);
    // Case 2
    v1 = Vector3(0.24, 0.0082, -0.03);
    v2 = Vector3(0.53, -0.0532, -1.53);
    v = v1 - v2;
    EXPECT_NEAR(v.x ,-0.29, 1e-5);
    EXPECT_NEAR(v.y ,0.0614, 1e-5);
    EXPECT_NEAR(v.z ,1.5, 1e-5);
    // Case 3
    v1 = Vector3(-27, 83, -163);
    v2 = Vector3(36, -64, 264);
    v = v1 - v2;
    EXPECT_NEAR(v.x ,-63, 1e-5);
    EXPECT_NEAR(v.y ,147, 1e-5);
    EXPECT_NEAR(v.z ,-427, 1e-5);
}

TEST(Vector3Test,CrossproductofVector3)
{
    // Case 1
    Vector3 v1 = Vector3(2, -5, 4);
    Vector3 v2 = Vector3(6, 2, -8);
    Vector3 v = cross(v1, v2);
    EXPECT_NEAR(v.x ,32, 1e-5);
    EXPECT_NEAR(v.y ,40, 1e-5);
    EXPECT_NEAR(v.z ,34, 1e-5);
    // Case 2
    v1 = Vector3(0.24, 0.0082, -0.03);
    v2 = Vector3(0.53, -0.0532, -1.53);
    v = cross(v1, v2);
    EXPECT_NEAR(v.x ,-0.014142, 1e-5);
    EXPECT_NEAR(v.y ,0.3513, 1e-5);
    EXPECT_NEAR(v.z ,-0.017114, 1e-5);
    // Case 3
    v1 = Vector3(-27, 83, -163);
    v2 = Vector3(36, -64, 264);
    v = cross(v1, v2);
    EXPECT_NEAR(v.x ,11480, 1e-5);
    EXPECT_NEAR(v.y ,1260, 1e-5);
    EXPECT_NEAR(v.z ,-1260, 1e-5);
    // Cross product of vector and itself is zero
    v = cross(v1, v1);
    EXPECT_NEAR(v.x ,0, 1e-5);
    EXPECT_NEAR(v.y ,0, 1e-5);
    EXPECT_NEAR(v.z ,0, 1e-5);
}

TEST(Vector3Test,DotproductofVector3s)
{
    // Case 1
    Vector3 v1 = Vector3(2, -5, 4);
    Vector3 v2 = Vector3(6, 2, -8);
    EXPECT_NEAR(dot(v1, v2) ,-30, 1e-5);
    // Case 2
    v1 = Vector3(0.24, 0.0082, -0.03);
    v2 = Vector3(0.53, -0.0532, -1.53);
    EXPECT_NEAR(dot(v1, v2) ,0.172663, 1e-5);
    // Case 3
    v1 = Vector3(-27, 83, -163);
    v2 = Vector3(36, -64, 264);
    EXPECT_NEAR(dot(v1, v2) ,-49316, 1e-5);
}

TEST(Vector3Test,NormofaVector3)
{
    // Case 1
    Vector3 v = Vector3(2, -5, 4);
    EXPECT_NEAR(norm(v) ,6.70820393, 1e-5);
    // Case 2
    v = Vector3(0.24, 0.0082, -0.03);
    EXPECT_NEAR(norm(v) ,0.242007, 1e-5);
    // Case 3
    v = Vector3(-27, 83, -163);
    EXPECT_NEAR(norm(v) ,184.897269, 1e-5);
}

TEST(Vector3Test, UnitVector3)
{
    // Case 1
    Vector3 v = Vector3(2, -5, 4);
    Vector3 n = unit(v);
    EXPECT_NEAR(n.x ,0.298142, 1e-5);
    EXPECT_NEAR(n.y ,-0.745356, 1e-5);
    EXPECT_NEAR(n.z ,0.596285, 1e-5);
    // Case 2
    v = Vector3(0.24, 0.0082, -0.03);
    n = unit(v);
    EXPECT_NEAR(n.x ,0.991708, 1e-5);
    EXPECT_NEAR(n.y ,0.0338834, 1e-5);
    EXPECT_NEAR(n.z ,-0.123964, 1e-5);
    // Case 3
    v = Vector3(-27, 83, -163);
    n = unit(v);
    EXPECT_NEAR(n.x ,-0.146027, 1e-5);
    EXPECT_NEAR(n.y ,0.448898, 1e-5);
    EXPECT_NEAR(n.z ,-0.881571, 1e-5);
}

TEST(Vector3Test, NormalizedVector3)
{
    // Case 1
    Vector3 n = Vector3(2, -5, 4);
    normalise(n);
    EXPECT_NEAR(n.x ,0.298142, 1e-5);
    EXPECT_NEAR(n.y ,-0.745356, 1e-5);
    EXPECT_NEAR(n.z ,0.596285, 1e-5);
    // Case 2
    n = Vector3(0.24, 0.0082, -0.03);
    normalise(n);
    EXPECT_NEAR(n.x ,0.991708, 1e-5);
    EXPECT_NEAR(n.y ,0.0338834, 1e-5);
    EXPECT_NEAR(n.z ,-0.123964, 1e-5);
    // Case 3
    n = Vector3(-27, 83, -163);
    normalise(n);
    EXPECT_NEAR(n.x ,-0.146027, 1e-5);
    EXPECT_NEAR(n.y ,0.448898, 1e-5);
    EXPECT_NEAR(n.z ,-0.881571, 1e-5);
}

} //  namespace aml


