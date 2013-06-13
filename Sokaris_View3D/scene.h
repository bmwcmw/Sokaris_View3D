#ifndef SCENE_H
#define SCENE_H
#include <windows.h>
#include "loadVectors.h"

using namespace std;

void chargerTextures();
void dessinerScene();

void build3DResult(vector<Plane> vP);
void build3DResult2(vector<Plane> vP);
void drawGazes(vector<Intersection> vI);

#endif //SCENE_H
