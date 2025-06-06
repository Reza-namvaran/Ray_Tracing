#ifndef HITTABLE_LIST
#define HITTABLE_LIST

#include "ray_tracing.hpp"
#include "hittable.hpp"

#include <vector>


class HittableList : public Hittable {
    public:
        std::vector<shared_ptr<Hittable>> objects;

        HittableList() {}
        HittableList(shared_ptr<Hittable> object) { this-> add(object); }

        void clear_list() { this->objects.clear(); }

        void add(shared_ptr<Hittable> object) {
            objects.emplace_back(object);
        }

        virtual bool hit(const Ray& ray, double ray_t_min, double ray_t_max, HitRecord& rec) const override {
            HitRecord temp_rec;
            bool hit_obj = false;
            auto closest = ray_t_max;

            for (const auto& object : objects) {
                if (object->hit(ray, ray_t_min, closest, temp_rec)) {
                    hit_obj = true;
                    closest = temp_rec.t;
                    rec = temp_rec;
                }
            }

            return hit_obj;
        }
};

#endif // HITTABLE_LIST