#include "../include/log.hpp" // Include the header file for the log function
#include <gtest/gtest.h> // Include the Google Test framework
#include <string> // Include the string library

// Test the log function
TEST(LogTest, SimpleTest) {

    // Call the log function with a message
    log("This is a test message");

    // Call the log function with a message and a variable
    int test_var = 5;
    log("This is a test message with a variable: ");

    // Call the log function with a message and a string
    std::string test_string = "This is a test string";
    log("This is a test message with a string: ");
}

int main(int argc, char** argv) {
    // Initialize the Google Test framework
    ::testing::InitGoogleTest(&argc, argv);

    // Run the tests
    return RUN_ALL_TESTS();
}
