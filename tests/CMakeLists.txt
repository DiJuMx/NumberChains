
# Test 1: Check at least one argument
ADD_TEST(NAME ArgCheck1 COMMAND numberChains)
SET_TESTS_PROPERTIES(ArgCheck1 PROPERTIES WILL_FAIL true)

# Test 2: Check at most two arguments
ADD_TEST(NAME ArgCheck2 COMMAND numberChains 1 1 1)
SET_TESTS_PROPERTIES(ArgCheck2 PROPERTIES WILL_FAIL true)

# Test 3: Check rejection of non-digits
ADD_TEST(NAME ArgCheck3 COMMAND numberChains "4,000")
SET_TESTS_PROPERTIES(ArgCheck3 PROPERTIES WILL_FAIL true)

# Test 4: Check 4 returns 1
ADD_TEST(NAME ValueCheck1 COMMAND numberChains 4)
SET_TESTS_PROPERTIES(ValueCheck1 PROPERTIES PASS_REGULAR_EXPRESSION ".*Length: 1.*" )
