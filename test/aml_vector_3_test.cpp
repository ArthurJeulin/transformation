#include <gtest/gtest.h>
#include "aml.h"

namespace aml
{
    TEST(ClassVector3Test,Constructor)
    {
        // Case 1
        Vector3 v;
        ASSERT_EQ(v.x ,0.0);
        ASSERT_EQ(v.y ,0.0);
        ASSERT_EQ(v.z ,0.0);
        // Case 2
        v = Vector3(5.0);
        ASSERT_EQ(v.x ,5.0);
        ASSERT_EQ(v.y ,5.0);
        ASSERT_EQ(v.z ,5.0);
        // Case 3
        v = Vector3(1.0,2.0,3.0);
        ASSERT_EQ(v.x ,1.0);
        ASSERT_EQ(v.y ,2.0);
        ASSERT_EQ(v.z ,3.0);
        // Case 4
        double data[3] = {3.0,2.0,1.0};
        v = Vector3(data);
        ASSERT_EQ(v.x ,3.0);
        ASSERT_EQ(v.y ,2.0);
        ASSERT_EQ(v.z ,1.0);
        
    }

} //  namespace aml


