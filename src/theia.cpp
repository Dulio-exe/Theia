#include <blur.hpp>
#include <iostream>
#include <log.hpp>
#include <sharp.hpp>
#include <string>
#include <tone.hpp>

using namespace std;
using namespace cv;

int main(int argc, char* argv[]) {
    // Path to input and output directories
    string input_dir = "./input/";
    string outputDir = "./output/";

    // Set blur values
    int blur_amount = 2;
    float sharpness_point = 5.56;
    float sharpness_low = -1.14;

    remove_screentones(input_dir, input_dir, blur_amount, sharpness_point,
                       sharpness_low);

    // Read all image files in the input directory
    vector<string> filenames;
    glob(input_dir + "*", filenames);

    // Loop through each file and convert it to PNG
    for (size_t i = 0; i < filenames.size(); i++) {
        // Load image from file
        Mat image = imread(filenames[i], IMREAD_COLOR);

        // Check if image was loaded successfully
        if (image.empty()) {
            cerr << "Error: Unable to load image " << filenames[i] << endl;
            continue;
        }

        // Create output filename by replacing extension with .png
        string outputFilename =
            outputDir + filenames[i].substr(filenames[i].find_last_of("/") + 1);
        outputFilename =
            outputFilename.substr(0, outputFilename.find_last_of(".")) + ".png";

        // Save image as PNG
        imwrite(outputFilename, image);

        // Print status message
        log("Converted " + filenames[i] + " to " + outputFilename);
    }

    return 0;
}
