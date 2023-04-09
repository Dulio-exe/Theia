#include <opencv2/opencv.hpp>

cv::Mat sharp(cv::Mat img, float sharp_point, float sharp_low) {
    cv::Mat s_kernel = (cv::Mat_<float>(3, 3) << 0, sharp_low, 0, sharp_low,
                        sharp_point, sharp_low, 0, sharp_low, 0);
    cv::Mat sharpened;
    cv::filter2D(img, sharpened, -1, s_kernel);
    return sharpened;
}
