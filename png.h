#pragma once

#include <vector>
#include <iostream>

#include "./image/image.h"
#include "./lodepng/lodepng.h"

namespace pixicog {
  namespace png {
/**
 * Opens a local file png and fills an image
 * @name open
 * @public
 * @param imgPtr {&Image} - the image to be filled
 * @param filepath {std-string} - the file to be opened
 */
    void open(pixicog::Image *imgPtr, std::string filepath) {
      std::vector<unsigned char> image; //the raw pixels
      unsigned width, height;
      unsigned error = lodepng::decode(image, width, height, filepath);
      if (error) throw lodepng_error_text(error);
      imgPtr->setup(width, height, 4, image);
    }
/**
 * Saves a pixicog::Image to a local file
 * @name save
 * @public
 * @param imgPtr {&Image} - the image to be saved
 * @param filepath {std-string} - the file to write to
 */
    void save(pixicog::Image *imgPtr, std::string filepath) {
      std::vector<int> shape = imgPtr->getShape();
      std::vector<unsigned char> image(shape[0]*shape[1]*4);
      for (int x=0; x<shape[0]; x++) {
        for (int y=0; y<shape[1]; y++) {
          for (int c=0; c<shape[2]; c++) {
            int pos = (y*shape[0]*4)+(x*4) + c;
            image[pos] = imgPtr->get(x, y, c);
          }
        }
      }
      unsigned error = lodepng::encode(filepath, image, shape[0], shape[1]);
      if (error) throw lodepng_error_text(error);
    }
  }
}

