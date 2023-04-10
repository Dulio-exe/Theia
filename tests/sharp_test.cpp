#include <opencv2/opencv.hpp>
#include <gtest/gtest.h>
#include "../include/sharp.hpp"

// Tests the sharp function
TEST(SharpTest, SimpleTest) {
    // Create a test image with random values
    cv::Mat test_img(100, 100, CV_8UC1);
    cv::randu(test_img, 0, 255);

    // Call the sharp function with a sharpening point of 5 and low sharpening value of 1
    cv::Mat result = sharp(test_img, 5, 1);

    // Check if the output image has the same size as the input image
    ASSERT_EQ(test_img.size(), result.size());

    // Check if the output image has the same number of channels as the input image
    ASSERT_EQ(test_img.channels(), result.channels());

    // Check if the output image is not empty
    ASSERT_FALSE(result.empty());
}
