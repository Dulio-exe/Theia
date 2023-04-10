# Include Folder

This folder contains the header files for Theia, an image processing program written in C++.

## Contents

The `include` folder contains the following header files:

- `blur.hpp`: Declaration of the Gaussian blur filter for images
- `log.hpp`: Declaration of the Laplacian of Gaussian (LoG) filter for images
- `sharp.hpp`: Declaration of the sharpening filter for images
- `tone.hpp`: Declaration of the tonemapping algorithm for high dynamic range (HDR) images

Each of these header files corresponds to an implementation file in the `src` folder.

## How to use

To use any of the filters or algorithms in your own project, simply include the corresponding header file in your C++ source code:

```c++
#include "blur.hpp"

// use the Gaussian blur filter
```

You can then use the functions and classes defined in the header file to apply the filter or algorithm to your images.

Note that to use these header files, you will need to link the required libraries and dependencies in your own project's build system.

## Dependencies

The header files in this folder depend on the following libraries:

- OpenCV: Used for image processing and manipulation

Make sure to install OpenCV before using the header files in your own project.
