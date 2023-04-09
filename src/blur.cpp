#include <opencv2/opencv.hpp>

cv::Mat blur(const cv::Mat& img, int blur_amount = 5) {
    cv::Mat dst2, dst;
    if (blur_amount == 7) {
        cv::GaussianBlur(img, dst2, cv::Size(7, 7), 0);
        cv::bilateralFilter(dst2, dst, 7, 80, 80);
    } else {
        cv::GaussianBlur(img, dst2, cv::Size(5, 5), 0);
        cv::bilateralFilter(dst2, dst, 7, 10 * blur_amount, 80);
    }
    return dst;
}
