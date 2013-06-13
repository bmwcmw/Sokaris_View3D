#include "scene.h"

#include <gl/glew.h>
#include <gl/gl.h>
#include <gl/glu.h>

#include "sdlglutils.h"

void maisonde42();
void jardindeDeadMaster();

GLuint texture[21];

void prepareScene(){
	GLUquadric* params;
	params = gluNewQuadric();
	gluQuadricTexture(params,GL_TRUE);

	glBindTexture(GL_TEXTURE_2D, texture[10]);

	float ptSize = 6;
	for ( float flo = -50; flo < 50; flo+=1 )
	{
		glPointSize(ptSize);
		glBegin(GL_POINTS);
		glVertex3d(flo,0,0);
		glEnd();
	}

	for ( float flo = -50; flo < 50; flo+=1 )
	{
		glPointSize(ptSize);
		glBegin(GL_POINTS);
		glVertex3d(0,flo,0);
		glEnd();
	}
	float xmin=-50.0, xmax=50.0, dx=5.0, x;
	float ymin=-50.0, ymax=50.0, dy=5.0, y;

	glBegin(GL_LINES);

	for(x=xmin; x<=xmax; x+=dx)
	{
		for(y=ymin; y<=ymax; y+=dy)
		{
			glVertex3f(x, ymin, 0.0);
			glVertex3f(x, ymax, 0.0);

			glVertex3f(xmin, y, 0.0);
			glVertex3f(xmax, y, 0.0);
		}
	}

	glEnd();

	gluDeleteQuadric(params);
}

void dessinerScene()
{
	std::vector<Plane> vP;
	std::vector<Intersection> vI;
	prepareScene();
	build3DResult(readPlanesFromFile("./Planes_SalleTP.ini"));
	build3DResult2(readPlanesFromFile("./Planes_SalleTPHeat.ini"));
	drawGazes(readIntersectionsFromFile("./Intersections.ini"));
}


void chargerTextures()
{
	texture[10] = loadTexture("./texture/floor.jpg");
	texture[1] = loadTexture("./texture/mur.jpg");
	texture[2] = loadTexture("./texture/gaze.jpg");

	texture[11] = loadTexture("./texture/heatHN.png");
	texture[12] = loadTexture("./texture/heatHS.png");
	texture[13] = loadTexture("./texture/heatHE.png");
	texture[14] = loadTexture("./texture/heatHW.png");
}

void drawGazes(vector<Intersection> vI){
	GLUquadric* params;
	params = gluNewQuadric();
	gluQuadricTexture(params,GL_TRUE);

	float pointsize=0.01;
	glBindTexture(GL_TEXTURE_2D, texture[2]);

	for(int i=0;i<vI.size();i++){

		glTranslatef(vI[i].position.x, vI[i].position.y, vI[i].position.z);

		glBegin(GL_QUADS);

		// Front
		glTexCoord2d(pointsize ,pointsize);
		glVertex3f(-pointsize, pointsize, pointsize);
		glVertex3f( pointsize, pointsize, pointsize);
		glVertex3f( pointsize,-pointsize, pointsize);
		glVertex3f(-pointsize,-pointsize, pointsize);

		// Left
		glTexCoord2d(pointsize ,pointsize);
		glVertex3f(-pointsize, pointsize,-pointsize);
		glVertex3f(-pointsize,-pointsize,-pointsize);
		glVertex3f(-pointsize,-pointsize, pointsize);
		glVertex3f(-pointsize, pointsize, pointsize);

		// Right
		glTexCoord2d(pointsize ,pointsize);
		glVertex3f(pointsize, pointsize, pointsize);
		glVertex3f(pointsize,-pointsize, pointsize);
		glVertex3f(pointsize,-pointsize,-pointsize);
		glVertex3f(pointsize, pointsize,-pointsize);

		// Back
		glTexCoord2d(pointsize ,pointsize);
		glVertex3f( pointsize, pointsize,-pointsize);
		glVertex3f( pointsize,-pointsize,-pointsize);
		glVertex3f(-pointsize,-pointsize,-pointsize);
		glVertex3f(-pointsize, pointsize,-pointsize);

		// Up
		glTexCoord2d(pointsize ,pointsize);
		glVertex3f(-pointsize, pointsize,-pointsize);
		glVertex3f(-pointsize, pointsize, pointsize);
		glVertex3f( pointsize, pointsize, pointsize);
		glVertex3f( pointsize, pointsize,-pointsize);

		// Down
		glTexCoord2d(pointsize ,pointsize);
		glVertex3f( pointsize,-pointsize, pointsize);
		glVertex3f(-pointsize,-pointsize, pointsize);
		glVertex3f(-pointsize,-pointsize,-pointsize);
		glVertex3f( pointsize,-pointsize,-pointsize);

		glEnd();

		glTranslatef(-vI[i].position.x, -vI[i].position.y, -vI[i].position.z);
		glPopMatrix();

	}

	gluDeleteQuadric(params);
}

void build3DResult(vector<Plane> vP){
	GLUquadric* params;
	params = gluNewQuadric();
	gluQuadricTexture(params,GL_TRUE);

	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glLineWidth(1.0f);
	for(int i=0;i<vP.size();i++){

		glBegin(GL_LINE_LOOP);
		glVertex3d(vP[i].point1.x ,vP[i].point1.y, vP[i].point1.z);
		glVertex3d(vP[i].point2.x ,vP[i].point2.y, vP[i].point2.z);
		glVertex3d(vP[i].point3.x ,vP[i].point3.y, vP[i].point3.z);
		glVertex3d(vP[i].point4.x ,vP[i].point4.y, vP[i].point4.z);
		glEnd();

	}

	gluDeleteQuadric(params);
}

void build3DResult2(vector<Plane> vP){
	GLUquadric* params;
	params = gluNewQuadric();
	gluQuadricTexture(params,GL_TRUE);

	for(int i=0;i<vP.size();i++){
		glBindTexture(GL_TEXTURE_2D, texture[i+11]);
		glBegin(GL_QUADS);
		glTexCoord2d(0 , 0);
		glVertex3d(vP[i].point1.x ,vP[i].point1.y, vP[i].point1.z);
		glTexCoord2d(1 , 0);
		glVertex3d(vP[i].point2.x ,vP[i].point2.y, vP[i].point2.z);
		glTexCoord2d(1 , 1);
		glVertex3d(vP[i].point3.x ,vP[i].point3.y, vP[i].point3.z);
		glTexCoord2d(0 , 1);
		glVertex3d(vP[i].point4.x ,vP[i].point4.y, vP[i].point4.z);
		glEnd();

	}

	gluDeleteQuadric(params);
}