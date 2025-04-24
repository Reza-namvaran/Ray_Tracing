#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray_tracing.hpp"

class HitRecord {
  public:
    Point3 p;
    Vector3 normal;
    double t;
    bool front_face;

    void set_face_normal(const Ray& ray, const Vector3& outward_normal) {
        /// NOTE: the parameter outward_normal is assumed to have unit length.

        front_face = dot(ray.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class Hittable {
  public:
    virtual ~Hittable() = default;

    virtual bool hit(const Ray& ray, double ray_t_min, double ray_t_max, HitRecord& rec) const = 0;
};

#endif // HITTABLE_H