#include <iostream> 
#include <vector>

#include "./image/image.h"
#include "./png.h"
#include "./tap/tap.h"

using namespace pixicog;

void openWorks() {
  Image img;
  pixicog::png::open(&img, "./fixtures/1x1-red.png");
  if (img.get(0, 0, 0) != 255) throw "this should be full red!";
  if (img.get(0, 0, 1) != 0) throw "this should be 0 green";
  if (img.get(0, 0, 2) != 0) throw "this should be 0 blue";
  std::vector<int> shape = img.getShape();
  if (shape[0] != 1) throw "width is wrong";
  if (shape[1] != 1) throw "height is wrong";
  if (shape[2] != 4) throw "num channels is wrong";
};

void saveWorks() {
  const char* file = "./build/test-1x1-red.png";

  Image img(1, 1, 3);
  img.set(0, 0, 0, 255);
  pixicog::png::save(&img, file);

  Image read;
  pixicog::png::open(&read, file);
  if (read.get(0, 0, 0) != 255) throw "red is not right";

  std::vector<int> shape = read.getShape();
  if (shape[0] != 1) throw "width is not right";
  if (shape[1] != 1) throw "height is not right";
  if (shape[2] != 4) throw "num channels is not right";
};

int main(int argc, char * argv[]) {
  tap::start();
  tap::test("vaild input works");
  tap::throwFail(&openWorks, "check that opening works");
  tap::throwFail(&saveWorks, "check that saving works");

  return tap::end();
};

