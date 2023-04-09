#ifndef SHARP_HPP
#define SHARP_HPP

#include <opencv2/opencv.hpp>

cv::Mat sharp(cv::Mat img, float sharp_point, float sharp_low);

#endif // SHARP_HPP