#ifdef WIN32
#include <windows.h>
#endif
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>

double rot_x = 0;
double rot_y = 0;
double posx = 0;
double posy = 0;
double superPos[3] = { 1, 0, 0 };

void display();
void specialKeys(int, int, int);
void info();

int main(int argc, char ** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Spining cube ");
	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(display);
	glutSpecialFunc(specialKeys);
	glutIdleFunc(glutPostRedisplay);

	glutMainLoop();

	return 0;

}

void display(){
	//  Clear screen and Z-buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

	// Other Transformations
	// glTranslatef( 0.1, 0.0, 0.0 );      // Not included
	// glRotatef( 180, 0.0, 1.0, 0.0 );    // Not included

	// Rotate when user changes rotate_x and rotate_y
	//rot_x += rot_x; rot_y += rot_y;
	posx += rot_x; posy += rot_y;
	glRotatef(posx, 1.0, 0.0, 0.0);
	glRotatef(posy, 0.0, 1.0, 0.0);

	// Other Transformations
	// glScalef( 2.0, 2.0, 0.0 );          // Not included
	/*
	glBegin(GL_POLYGON);
	glColor3f(1.0/'a',1.0/'d',1.0/'z');
	glVertex3f(1.0,0,0);
	glVertex3f(-1.0,0,0);
	glVertex3f(0,0,1.0);
	glVertex3f(0,0,-1.0);
	glEnd();
	*/
	//Multi-colored side - FRONT
	glBegin(GL_POLYGON);

	glColor3f(1.0, 0.0, 0.0);     glVertex3f(0.5, -0.5, -0.5);      // P1 is red
	glColor3f(0.0, 1.0, 0.0);     glVertex3f(0.5, 0.5, -0.5);      // P2 is green
	glColor3f(0.0, 0.0, 1.0);     glVertex3f(-0.5, 0.5, -0.5);      // P3 is blue
	glColor3f(1.0, 0.0, 1.0);     glVertex3f(-0.5, -0.5, -0.5);      // P4 is purple

	glEnd();

	// White side - BACK
	glBegin(GL_POLYGON);
	glColor3f(superPos[0]+1.0, 1.0, 1.0);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();

	// Green side - LEFT
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();

	// Blue side - TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glEnd();

	// Red side - BOTTOM
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();

	glFlush();
	glutSwapBuffers();

	
}

void specialKeys(int key, int x, int y){
	if (key == GLUT_KEY_DOWN){
		rot_x -= .1;
	}
	if (key == GLUT_KEY_UP){
		rot_x += .1;
	}
	if (key == GLUT_KEY_LEFT){
		rot_y -= .1;
	}
	if (key == GLUT_KEY_RIGHT){
		rot_y += .1;
	}
	if (key == GLUT_KEY_F1){
		rot_y = rot_x = 0;
	}
	if (key == GLUT_KEY_F2){
		rot_y = 0;
	}
	if (key == GLUT_KEY_F3){
		rot_x = 0;
	}
	for (int i = 0; i < 2; i++){
		double * tmp = ((i == 0) ? &posx : &posy);
		if (*tmp / 360 == 0){
			*tmp = 0;
		}
	}

	//std::cout << "x:\t" << rot_x << "  y:\t" << rot_y << std::endl;
} 

void info(){}
