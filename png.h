#pragma once

#include <vector>
#include "./image/image.h"

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
      throw "not implemented yet";
    }
/**
 * Saves a pixicog::Image to a local file
 * @name save
 * @public
 * @param imgPtr {&Image} - the image to be saved
 * @param filepath {std-string} - the file to write to
 */
    void save(pixicog::Image *imgPtr, std::string filepath) {
      throw "not implemented yet";
    }
  }
}

