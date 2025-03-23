#ifndef COLOR_H
#define COLOR_H

#include "Vector3.hpp"

using Color = Vector3;

inline void write_color(std::ostream& out, const Color& pixel_color) {
  std::clog << "\rWriting Color\n" << std::flush;

  auto r = pixel_color.x();
  auto g = pixel_color.y();
  auto b = pixel_color.z();

  // Translate [0, 1] component to byte range
  int rbyte = int(255.999 * r);
  int gbyte = int(255.999 * g);
  int bbyte = int(255.999 * b);

  out << rbyte << ' ' << gbyte << ' ' << bbyte << "\n";
}

#endif // COLOR_H
