
//#include <iostream>
//#include <fstream>
//#include "vec3.h"
//#include "ray.h"
//
//using namespace std;

//float hit_sphere(const vec3& center, float radius, const ray& r)
//{
//	vec3 oc = r.origin() - center;
//	float a = dot(r.direction(), r.direction());
//	float b = 2.0 * dot(oc, r.direction());
//	float c = dot(oc, oc) - radius * radius;
//	float discriminant = b*b - 4 * a*c;
//	if (discriminant < 0)
//		return -1.0;
//	else
//		return(-b - sqrt(discriminant)) / (2.0*a);
//		//return (discriminant > 0);
//}
//
//vec3 color(const ray& r)
//{
//	float t = hit_sphere(vec3(0, 0, -1), 0.5, r);
//	if (t > 0.0)
//	{
//		vec3 N = unit_vector(r.point_at_parameter(t) - vec3(0, 0, -1));
//		return 0.5*vec3(N.x() + 1, N.y() + 1, N.z() + 1);
//	}
//	/*if (hit_sphere(vec3(0, 0, -1.0), 0.5, r))
//		return vec3(1.0, 0, 0);*/
//
//	vec3 unit_direction = unit_vector(r.direction());
//	t = 0.5*(unit_direction.y() + 1.0);
//	return (1.0 - t)*vec3(1.0, 1.0, 1.0) + t*vec3(0.5, 0.7, 1.0);
//}
//
//int main()
//{
//	ofstream outfile("Output/chapter5_normal_output.ppm", ios_base::out);
//
//	int nx = 200;
//	int ny = 100;
//	outfile << "P3\n" << nx << " " << ny << "\n255\n";
//
//	vec3 lower_left_corner(-2.0, -1.0, -1.0);
//	vec3 horizontal(4.0, 0.0, 0.0);
//	vec3 vertical(0.0, 2.0, 0.0);
//	vec3 origin(0.0, 0.0, 0.0);
//
//	for (int i = ny - 1; i >= 0; i--)
//	{
//		for (int j = 0; j < nx; j++)
//		{
//			float u = float(j) / float(nx);
//			float v = float(i) / float(ny);
//			ray r(origin, lower_left_corner + u*horizontal + v*vertical);
//			vec3 col = color(r);
//	
//			int ir = int(255.99 * col[0]);
//			int ig = int(255.99 * col[1]);
//			int ib = int(255.99 * col[2]);
//
//			outfile << ir << " " << ig << " " << ib << "\n";
//		}
//	}
//	return 0;
//}