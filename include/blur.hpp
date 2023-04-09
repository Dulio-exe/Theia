#ifndef BLUR_HPP
#define BLUR_HPP

#include <iostream>
#include <opencv2/opencv.hpp>

cv::Mat blur(const cv::Mat& img, int blur_amount = 5);

#endif // BLUR_HPP