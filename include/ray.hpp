#ifndef RAY_H
#define RAY_H

#include "Vector3.hpp"

class Ray {
    public:
        Ray() {}
        Ray(const Point3& p_origin, const Vector3& direction) : org(p_origin), dir(direction) {}
        
        // getters
        const Point3& origin() const { return this->org; }
        const Vector3& direction() const { return this->dir; }

        Point3 at(double r) const {
            return this->org + this->dir * r;
        }
    private:
        Point3 org;
        Vector3 dir;
};

#endif // RAY_H