#include <blur.hpp>
#include <log.hpp>
#include <opencv2/opencv.hpp>
#include <sharp.hpp>
#include <string>
#include <vector>

using namespace std;
using namespace cv;

void remove_screentones(string dir_i, string dir_o, int blur_amount,
                        float sh_point = 5.56, float sh_low = -1.14) {
    if (dir_i.empty()) {
        log("No input directory");
        return;
    }
    if (dir_o.empty()) {
        log("No output directory");
        return;
    }

    vector<String> inputs;
    glob(dir_i + "/*.*", inputs);
    if (inputs.empty()) {
        log("No images file found");
        return;
    }

    log("Removing tone");

    sh_point = static_cast<float>(sh_point);
    sh_low = static_cast<float>(sh_low);

    int bs_amount = 0;
    if (blur_amount == 1) {
        bs_amount = 3;
    }
    if (blur_amount == 2) {
        bs_amount = 5;
    }
    if (blur_amount == 3) {
        bs_amount = 7;
    }

    for (auto i : inputs) {
        Mat img = imread(i);
        Mat blurred = img.clone();
        medianBlur(img, blurred, bs_amount);
        Mat ret = Mat::zeros(img.size(), img.type());
        sharp(blur(img, blur_amount), sh_point, sh_low)
            .copyTo(ret, blurred > 0);
        bool success =
            imwrite(dir_o + "/" + i.substr(i.find_last_of("/") + 1), ret);
        if (!success) {
            log("An error occurred");
        }
    }
    log("ToneRemover has done running");
}