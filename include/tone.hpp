#ifndef TONE_HPP
#define TONE_HPP

#include <iostream>
#include <opencv2/opencv.hpp>

// Remove tone
void remove_screentones(std::string dir_i, std::string dir_o, int blur_amount, float sh_point=5.56, float sh_low=-1.14);

#endif // TONE_HPP