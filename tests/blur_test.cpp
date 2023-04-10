#include <gtest/gtest.h>
#include <opencv2/opencv.hpp>
#include "../include/blur.hpp"

TEST(BlurFunctionTest, GaussianBlurTest) {
  cv::Mat input_image = cv::imread("test_image.png");
  cv::Mat blurred_image = blur(input_image, 3);
  EXPECT_FALSE(blurred_image.empty());
  EXPECT_TRUE(blurred_image.size() == input_image.size());
  EXPECT_TRUE(blurred_image.type() == input_image.type());
}

TEST(BlurFunctionTest, BilateralBlurTest) {
  cv::Mat input_image = cv::imread("test_image.png");
  cv::Mat blurred_image = blur(input_image, 5);
  EXPECT_FALSE(blurred_image.empty());
  EXPECT_TRUE(blurred_image.size() == input_image.size());
  EXPECT_TRUE(blurred_image.type() == input_image.type());
}

TEST(BlurFunctionTest, InvalidBlurAmountTest) {
  cv::Mat input_image = cv::imread("test_image.png");
  cv::Mat blurred_image = blur(input_image, -1);
  EXPECT_TRUE(blurred_image.empty());
}
