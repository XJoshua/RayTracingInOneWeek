#ifndef MATERIALH
#define MATERIALH

struct hit_record;
#include "vec3.h"
#include "hitable.h"

class material {
public:
	virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& atteuation, ray& scattered) const = 0;
};

class lambertian :public material {
public:
	lambertian(const vec3& a) : albedo(a) {}
	virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const {
		vec3 target = rec.p + rec.normal + random_in_unit_sphere();
		scattered = ray(rec.p, target - rec.p);
		attenuation = albedo;
		return true;
	}
};

#endif
