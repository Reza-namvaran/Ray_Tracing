#ifndef HITTABLE_H
#define HITTABLE_H

#include "Ray.hpp"

class HitRecord {
  public:
    Point3 p;
    Vector3 normal;
    double t;
};

class Hittable {
  public:
    virtual ~Hittable() = default;
    
    virtual bool hit(const Ray& ray, double ray_t_min, double ray_t_max, HitRecord& rec) const = 0;
};

#endif // HITTABLE_H