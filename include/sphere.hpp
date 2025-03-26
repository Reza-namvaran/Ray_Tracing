#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.hpp"
#include "Vector3.hpp"

class Sphere : public Hittable {
    public:
        Sphere(const Point3& p_center, double p_radius) : center(p_center), radius(std::fmax(0, p_radius)) {}
        
        bool hit(const Ray& ray, double ray_t_min, double ray_t_max, HitRecord& rec) const override;
        
    private:
        Point3 center;
        double radius;
};

#endif // SPHERE_H