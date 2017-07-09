#include <iostream> 

#include "./image/image.h"
#include "./png.h"
#include "./tap/tap.h"

using namespace pixicog;

int main(int argc, char * argv[]) {
  tap::start();
  tap::test("creating the image object");
  tap::pass(false, "need to write these");

  return tap::end();
};

