#include <iostream>

typedef unsigned int uint;

int main() {
  // Image
   uint image_height = 256;
   uint image_width = 256;

  std::cout << "P3" << "\n" << image_width << ' ' << image_height << "\n255\n";  
  
  // Rendering
  for (size_t j = 0; j < image_height; ++j) {
    std::clog << "\rRemaining scanlines: " << (image_height - j) << ' ' << std::flush;
    for (size_t i = 0; i < image_width; ++i) {
      auto r = (double)(i) / (image_width - 1);
      auto g = 0.0;
      auto b = (double)(j) / (image_height - 1);

      uint red = int(255.999 * r);
      uint green = int(255.999 * g);
      uint blue = int(255.999 * b);

      std::cout << red << ' ' << green << ' ' << blue << "\n";
    }
  }

  std::clog << "\rDone.                 \n";
  return 0;
}
