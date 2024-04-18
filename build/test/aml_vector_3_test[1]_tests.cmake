add_test([=[ClassVector3Test.Constructor]=]  /ssd/dev/transformation_course/build/bin/aml_vector_3_test [==[--gtest_filter=ClassVector3Test.Constructor]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[ClassVector3Test.Constructor]=]  PROPERTIES WORKING_DIRECTORY /ssd/dev/transformation_course/build/test SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  aml_vector_3_test_TESTS ClassVector3Test.Constructor)
