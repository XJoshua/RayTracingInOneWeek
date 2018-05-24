#if 0

#include <iostream>
#include <fstream>
//#include <random>
#include "vec3.h"
//#include "float.h"
#include "sphere.h"
#include "ray.h"
#include "camera.h"
#include "hitablelist.h"

using namespace std;

vec3 color(const ray& r, hitable *world)
{
    // 击中记录：p：击中的点，t：光线的函数的x值，normal：法线向量
	hit_record rec;
    // 通过调用world的hit方法，判断光线是否击中
	if (world->hit(r, 0.0, FLT_MAX, rec)) {
        // 把法线坐标转换成颜色：((-1,1)+1)*0.5 -> (0,1)
		return 0.5*vec3(rec.normal.x() + 1, rec.normal.y() + 1, rec.normal.z() + 1);
	}
	else {
        // 没击中返回背景（蓝白渐变）
		vec3 unit_direction = unit_vector(r.direction());
		float t = 0.5*(unit_direction.y() + 1.0);
		return (1.0 - t)*vec3(1.0, 1.0, 1.0) + t*vec3(0.5, 0.7, 1.0);
	}
}

int main()
{
	ofstream outfile("output/06_antialiasing.ppm", ios_base::out);

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
            // 抗锯齿算法，多次采样平均颜色
			for (int s = 0; s < ns; s++)
			{
				float u = float(j + rand() / double(RAND_MAX)) / float(nx);
				float v = float(i + rand() / double(RAND_MAX)) / float(ny);
				ray r = cam.get_ray(u, v);
				vec3 p = r.point_at_parameter(2.0);
				col += color(r, world);
			}
			col /= float(ns);

			int ir = int(255.99 * col[0]);
			int ig = int(255.99 * col[1]);
			int ib = int(255.99 * col[2]);

			outfile << ir << " " << ig << " " << ib << "\n";
		}
	}
	return 0;
}

#endif