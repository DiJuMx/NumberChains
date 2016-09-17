
# Test 1: Check the argument handling
ADD_TEST(NAME ArgCheck1 COMMAND numberChains)
SET_TESTS_PROPERTIES(ArgCheck1 PROPERTIES WILL_FAIL true)
