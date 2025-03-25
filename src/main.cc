#include "Vector3.hpp"
#include "color.hpp"
#include "ray.hpp"

#include <algorithm>

#pragma GCC optimize("O3")

typedef unsigned int uint;

// function to calculate blenden value (lerp)
Color ray_color(const Ray& p_r) {
   Vector3 unit_direction = unit_vector(p_r.direction());
   auto a = (unit_direction.y() + 1.0) * 0.5;
   return (1.0 - a) * Color(1.0, 1.0, 1.0) + a * Color(0.5, 0.7, 1.0);
}

int main() {
  // Image details
   auto aspect_ratio = 16.0 / 9.0;

   uint image_width = 400;
   uint image_height = std::max(static_cast<int>(image_width / aspect_ratio), 1);

  // Camera
   auto focal_len = 1.0;

   auto viewport_hight = 2.0;
   auto viewport_width = viewport_hight * (double(image_width)/image_height);

   auto camera_center = Point3(0, 0, 0);

  // Calculate the vectors across the horizontal and the vertical viewport edges
   auto viewport_u = Vector3(viewport_width, 0, 0);
   auto viewport_v = Vector3(0, -viewport_hight, 0);
  // Calculate the horizontal and vertical delta vectors pixel to pixel

   auto pixel_du = viewport_u / image_width;
   auto pixel_dv = viewport_v / image_height;

  // Finding the location of upper left pixel

   auto viewport_upper_left = camera_center - Vector3(0, 0, focal_len) - viewport_u / 2 - viewport_v / 2;
   auto zero_pixel_loc = viewport_upper_left + 0.5 * (pixel_du + pixel_dv);
  // Rendering
   std::cout << "P3" << "\n" << image_width << ' ' << image_height << "\n255\n";
   for (size_t j = 0; j < image_height; ++j) {
     std::clog << "\rRemaining scanlines: " << (image_height - j) << ' ' << std::flush;
     for (size_t i = 0; i < image_width; ++i) {
       auto pixel_center = zero_pixel_loc + (i * pixel_du) + (j * pixel_dv);
       auto ray_direction = pixel_center - camera_center;
       Ray ray(camera_center, ray_direction);

       Color pixel_color = ray_color(ray);
       write_color(std::cout, pixel_color);
     }
   }

   std::clog << "\rDone.                 \n";
   return 0;
}
