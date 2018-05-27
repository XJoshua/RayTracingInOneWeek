#if 1

#include <iostream>
#include <fstream>

#include "vec3.h"
#include "sphere.h"
#include "ray.h"
#include "camera.h"
#include "hitablelist.h"

using namespace std;

// ���ɣ�0��1����Χ�ڵ����ֵ
float drand48()
{
	return rand() / double(RAND_MAX);
}

// �������
vec3 random_in_unit_sphere()
{
	vec3 p;
	// ����(-1,1)��ʸ�����������ȴ���1��ʸ����ʣ�µľ������ڵ�ʸ��
	do {
		p = 2.0 * vec3(drand48(), drand48(), drand48()) - vec3(1, 1, 1);
	} while (dot(p, p) >= 1.0);
	return p;
}

vec3 color(const ray& r, hitable *world)
{
	hit_record rec;
	if (world->hit(r, 0.0, FLT_MAX, rec)) {
		// ���е㴦���е�λ���ϵ������
		vec3 target = rec.p + rec.normal + random_in_unit_sphere();
		// �ӵ�p����������Ĺ��ߣ���������ߣ����ݹ�ֱ��û�л�������
		return 0.5*color(ray(rec.p, target - rec.p), world);
		//return 0.5*vec3(rec.normal.x() + 1, rec.normal.y() + 1, rec.normal.z() + 1);
	}
	else {
		vec3 unit_direction = unit_vector(r.direction());
		float t = 0.5*(unit_direction.y() + 1.0);
		return (1.0 - t)*vec3(1.0, 1.0, 1.0) + t*vec3(0.5, 0.7, 1.0);
	}
}

int main()
{
	ofstream outfile("output/07_diffuse.ppm", ios_base::out);

	int nx = 200;
	int ny = 100;
	int ns = 100;
	outfile << "P3\n" << nx << " " << ny << "\n255\n";

	hitable *list[2];
	list[0] = new sphere(vec3(0, 0, -1), 0.5);
	list[1] = new sphere(vec3(0, -100.5, -1), 100);
	hitable *world = new hitable_list(list, 2);
	camera cam;

	for (int i = ny - 1; i >= 0; i--)
	{
		for (int j = 0; j < nx; j++)
		{
			vec3 col(0, 0, 0);
			// ������㷨����β���ƽ����ɫ
			// ÿ�����ض���ns������ɣ������һЩƫ��
			for (int s = 0; s < ns; s++)
			{
				float u = float(j + drand48()) / float(nx);
				float v = float(i + drand48()) / float(ny);
				ray r = cam.get_ray(u, v);
				vec3 p = r.point_at_parameter(2.0);
				col += color(r, world);
			}
			col /= float(ns);
			
			// Gamma Correction��gamma = 2
			col = vec3(sqrt(col[0]), sqrt(col[1]), sqrt(col[2]));

			int ir = int(255.99 * col[0]);
			int ig = int(255.99 * col[1]);
			int ib = int(255.99 * col[2]);

			outfile << ir << " " << ig << " " << ib << "\n";
		}
	}
	return 0;
}

#endif