add_test([=[TestSuiteSample.TestSample]=]  /ssd/dev/transformation_course/build/bin/aml_test [==[--gtest_filter=TestSuiteSample.TestSample]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TestSuiteSample.TestSample]=]  PROPERTIES WORKING_DIRECTORY /ssd/dev/transformation_course/build/test SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  aml_test_TESTS TestSuiteSample.TestSample)
