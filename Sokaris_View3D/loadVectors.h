#ifndef LOADVECTORS_H
#define LOADVECTORS_H

#include <vector>
#include <string>
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Point3d{
	double x;
	double y;
	double z;
};

struct Plane{
	Point3d point1;
	Point3d point2;
	Point3d point3;
	Point3d point4;
};

struct Intersection{
	Point3d position;
	double time;
};

vector<Plane> readPlanesFromFile(string filename);
vector<Intersection> readIntersectionsFromFile(string filename);

#endif //SCENE_H