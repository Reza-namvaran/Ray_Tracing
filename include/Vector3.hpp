#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>
#include <iostream>

class Vector3 {
  public:
    double el[3];
    
    Vector3() : el{0, 0, 0} {}
    Vector3(double el0, double el1, double el2) : el{el0, el1, el2} {}

    // getters
    double x() const { return this->el[0]; }
    double y() const { return this->el[1]; }
    double z() const { return this->el[2]; }

    Vector3 operator-() const { return Vector3{-el[0], -el[1], -el[2]}; }

    double operator[](int idx) const { return el[idx]; }
    double& operator[](int idx) { return el[idx]; }

    Vector3& operator+=(const Vector3& vec) {
      this->el[0] += vec.el[0];
      this->el[1] += vec.el[1];
      this->el[2] += vec.el[2];
      return *this;
    }

    Vector3& operator*=(double k) {
      this->el[0] *= k;
      this->el[1] *= k;
      this->el[2] *= k;
      return *this;   
    }


    Vector3& operator/=(double k) {
      return *this *= 1/k;
    }

    double len_squared() const {
      return pow(this->el[0], 2) + pow(this->el[1], 2) + pow(this->el[2], 2);
    }

    double len() const { return std::sqrt(this->len_squared()); }
};

// alias for better geometric clarity
using Point3 = Vector3;

// Utility functions

inline std::ostream& operator<<(std::ostream& out, const Vector3& vec) {
  return out << vec.el[0] << ' ' << vec.el[1] << ' ' << vec.el[2];
}

inline Vector3 operator+(const Vector3& u, const Vector3& v) {
  return Vector3(u.el[0] + v.el[0], u.el[1] + v.el[1], u.el[2] + v.el[2]);
}


inline Vector3 operator-(const Vector3& u, const Vector3& v) {
  return Vector3(u.el[0] - v.el[0], u.el[1] - v.el[1], u.el[2] - v.el[2]);
}


inline Vector3 operator*(const Vector3& u, const Vector3& v) {
  return Vector3(u.el[0] * v.el[0], u.el[1] * v.el[1], u.el[2] * v.el[2]);
}


inline Vector3 operator*(const Vector3& v, double k) {
  return v * k;
}

inline Vector3 operator/(const Vector3& v, double k) {
  return v * (1/k);
}

inline double dot(const Vector3& u, const Vector3& v) {
  return u.el[0] * v.el[0]
      +  u.el[1] * v.el[1]
      +  u.el[2] * v.el[2];
}

inline Vector3 cross(const Vector3& u, const Vector3& v) {
  return Vector3(u.el[1] * v.el[2] - u.el[2] * v.el[1],
                 u.el[2] * v.el[0] - u.el[0] * v.el[2],
                 u.el[0] * v.el[1] - u.el[1] * v.el[0]
         );
}

inline Vector3 unit_vector(const Vector3& vec) {
  return vec / vec.len();
}

#endif // VECTOR_H
