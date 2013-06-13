#include <windows.h>
#include <SDL.h>

#include <gl/glu.h>
#include <gl/gl.h>


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#define GLUT_DISABLE_ATEXIT_HACK
#include "glm.h"


#include <cstdlib>
#include "sdlglutils.h"
#include "freeflycamera.h"
#include "scene.h"

#include <SDL_syswm.h>

#define FPS 50
#define LARGEUR_FENETRE 960
#define HAUTEUR_FENETRE 600

#define _USE_MATH_DEFINES

void DrawGL();
void disp_Obj(char* name);

FreeFlyCamera * camera;

void stop()
{
	delete camera;
	SDL_Quit();
}

int main(int argc, char *argv[])
{
	SDL_Event event;
	const Uint32 time_per_frame = 1000/FPS;
	unsigned int width = LARGEUR_FENETRE;
	unsigned int height = HAUTEUR_FENETRE;

	Uint32 last_time,current_time,elapsed_time; //for time animation
	Uint32 start_time,stop_time; //for frame limit

	SDL_Init(SDL_INIT_VIDEO);
	atexit(stop);

	SDL_WM_SetCaption("Sokaris - GL Result Viewer", NULL);


	SDL_SetVideoMode(width, height, 32, SDL_OPENGL);
	initFullScreen(&width,&height);

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity( );
	gluPerspective(70,(double)width/height,0.001,1000);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);

	chargerTextures();

	camera = new FreeFlyCamera(Vector3D(0,0,2));

	//system("D:\\DEV\\GitHub\\Sokaris_View3D\\Debug\\Sokaris_Gaze_Mock_Writer.exe");

	last_time = SDL_GetTicks();
	for (;;)
	{

		start_time = SDL_GetTicks();

		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
			case SDL_QUIT:
				exit(0);
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_p:
					takeScreenshot("./texture/test.bmp");
					break;
				case SDLK_ESCAPE:
					exit(0);
					break;
				default :
					camera->OnKeyboard(event.key);
				}
				break;
			case SDL_KEYUP:
				camera->OnKeyboard(event.key);
				break;
			case SDL_MOUSEMOTION:
				camera->OnMouseMotion(event.motion);
				break;
			case SDL_MOUSEBUTTONUP:
			case SDL_MOUSEBUTTONDOWN:
				camera->OnMouseButton(event.button);
				break;
			}
		}

		current_time = SDL_GetTicks();
		elapsed_time = current_time - last_time;
		last_time = current_time;

		camera->animate(elapsed_time);

		/* Dessiner! */
		DrawGL();

		stop_time = SDL_GetTicks();
		if ((stop_time - last_time) < time_per_frame)
		{
			SDL_Delay(time_per_frame - (stop_time - last_time));
		}

	}

	return 0;
}




void disp_Obj(char* name)
{
	GLMmodel* pmodel = NULL;

	GLdouble projection[16], modelview[16], inverse[16];
	GLuint window, world, screen, command;
	GLuint sub_width = 256, sub_height = 256;
	static float angleX=0.0,angleY=0.0;
	int rx=0,ry=0,rz=0;
	float px=0,py=0,pz=0;
	float scale=1;
	float lx=1;

	GLfloat ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat specular[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat shininess = 65.0;  
	GLfloat light_position[]={ 1.0 , 1.0 , 1.0 , 1.0 };

	////glViewport(0, 0, 640,480);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	////gluPerspective(60.0, (float)LARGEUR_FENETRE/HAUTEUR_FENETRE, 1.0, 8.0);
	//glGetDoublev(GL_PROJECTION_MATRIX, projection);
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	//glClearColor(0.2, 0.2, 0.2, 0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	pmodel = glmReadOBJ(name);
	if (!pmodel) {
		pmodel = glmReadOBJ("obj/teapot.obj");
		if (!pmodel) exit(0);
		glmUnitize(pmodel);
		glmFacetNormals(pmodel);
		glmVertexNormals(pmodel, 90.0);
	}
	light_position[0]=lx;
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);	

	glLightfv( GL_LIGHT0 , GL_POSITION , light_position ); 

	glPushMatrix();		
	glRotatef(angleX,   rx,  1,   rz);
	glRotatef(angleY,   1,    ry,   rz);
	glTranslatef(px, py, pz);
	glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL);
	glPopMatrix();

}

void DrawGL()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();

	camera->look();

	/* Dessiner! */
	dessinerScene();

	//("obj/teapot.obj");

	glFlush();
	SDL_GL_SwapBuffers();
}