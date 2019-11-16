#include <Arduino.h>
#include <unity.h>

String STR_TO_TEST;

void setUp(void) {
    // set stuff up here
    STR_TO_TEST = "DRONE LIFT OFF!!";
}

void tearDown(void) {
    // clean stuff up here
    STR_TO_TEST = "";
}

void test_string_concat(void) { //testing the concatenation of the two strings
    String drone = "DRONE ";
    String liftoff = "LIFT OFF!!";
    TEST_ASSERT_EQUAL_STRING(STR_TO_TEST.c_str(), (drone + liftoff).c_str());
}

void test_string_substring(void) { //testing the substring "DRONE"
    TEST_ASSERT_EQUAL_STRING("DRONE", STR_TO_TEST.substring(0, 5).c_str());
}

    void test_string_index_of(void) { //testing that index 6 is 'L'
    TEST_ASSERT_EQUAL(6, STR_TO_TEST.indexOf('L'));
}

void test_string_equal_ignore_case(void) { //testing case-insensitive comparison of two strings
    TEST_ASSERT_TRUE(STR_TO_TEST.equalsIgnoreCase("DRONE LIFT OFF!!"));
}


void test_string_replace(void) { //testing the correctness of the replacing operation
    STR_TO_TEST.replace('!', '?');
    TEST_ASSERT_EQUAL_STRING("DRONE LIFT OFF??", STR_TO_TEST.c_str());
}

void setup()
{
    delay(2000); // service delay
    UNITY_BEGIN();

    RUN_TEST(test_string_concat);
    RUN_TEST(test_string_substring);
    RUN_TEST(test_string_index_of);
    RUN_TEST(test_string_equal_ignore_case);
    RUN_TEST(test_string_replace);

    UNITY_END(); // stop unit testing
}

void loop()
{
}