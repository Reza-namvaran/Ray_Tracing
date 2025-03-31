#include "sphere.hpp"

bool Sphere::hit(const Ray& ray, double ray_t_min, double ray_t_max, HitRecord& rec) const {
    Vector3 oc = center - ray.origin();
    auto a = ray.direction().len_squared();
    auto h = dot(ray.direction(), oc);
    auto c = oc.len_squared() - pow(this->radius, 2);
    
    auto discriminant = pow(h, 2) - a * c;
    if (discriminant < 0) {
        return false;
    }
    
    auto sqrt_d = std::sqrt(discriminant);
    // Find the nearest root that lies in the acceptable range.

    auto root = (h - sqrt_d) / a;
    if (root <= ray_t_min || root >= ray_t_max) {
        root = (h + sqrt_d) / a;
        if (root <= ray_t_min || root >= ray_t_max) {
            return false;
        }
    }
    
    rec.t = root;
    rec.p = ray.at(rec.t);
    Vector3 outward_normal = (rec.p - center) / this->radius;
    rec.set_face_normal(r, outward_normal);    
    
    return true;
}