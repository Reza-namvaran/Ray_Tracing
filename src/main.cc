#include "Vector3.hpp"
#include "color.hpp"

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
      auto pixel_color = Color(double(i) / (image_width - 1), 0, (double)(j) / (image_height - 1));
      write_color(std::cout, pixel_color);
    }
  }

  std::clog << "\rDone.                 \n";
  return 0;
}
