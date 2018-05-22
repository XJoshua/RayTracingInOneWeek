// 01_overview.cpp : 定义控制台应用程序的入口点。

//#include <iostream>
//#include <fstream>
//#include "vec3.h"
//
//using namespace std;

//int main()
//{
//	ofstream outfile("chapter1_output.ppm", ios_base::out);
//
//	int nx = 200;
//	int ny = 100;
//	outfile << "P3\n" << nx << " " << ny << "\n255\n";
//	for (int i = ny - 1; i >= 0; i--)
//	{
//		for (int j = 0; j < nx; j++)
//		{
//			// chapter 1
//			/*float r = float(j) / float(nx);
//			float g = float(i) / float(ny);
//			float b = 0.2;
//			int ir = int(255.99*r);
//			int ig = int(255.99*g);
//			int ib = int(255.99*b);*/
//
//			// chapter 2
//			vec3 col(float(j) / float(nx), float(i) / float(ny), 0.2);
//			int ir = int(255.99 * col[0]);
//			int ig = int(255.99 * col[1]);
//			int ib = int(255.99 * col[2]);
//
//			outfile << ir << " " << ig << " " << ib << "\n";
//		}
//	}
//    return 0;
//}

