/*
 * main.c
 *
 *  Created on: 16/06/2012
 *      Author: renan
 */
#include "Modelo.h"

Modelo _modelo;

void setLight0() {
	const GLfloat lPos[4] = { 100, 100, 100, 1 };
	const GLfloat lDif[4] = { 1, 1, 1, 1 };
	const GLfloat lEsp[4] = { 1, 1, 1, 1 };
	const GLfloat lAmb[4] = { 0.1f, 0.1f, 0.1f, 1 };

	glLightfv(GL_LIGHT0, GL_POSITION, lPos);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lDif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lEsp);
	glLightfv(GL_LIGHT0, GL_AMBIENT, lAmb);
}

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glShadeModel(GL_FLAT);

	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 's':

		break;
	case 'S':
		glShadeModel(GL_SMOOTH);
		break;
	case 'f':
		glRotatef(10, 0.0, 1.0, 0.0);
		break;
	case 'F':
		glShadeModel(GL_FLAT);
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (h == 0) {
		h = 1;
	}

	gluPerspective(60.0, (GLfloat) w / (GLfloat) h, 1.0f, 1000.0f);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	//setLight0();

	_modelo.desenharModelo();

	glutSwapBuffers();
}

void update() {
	//animate_base();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("First Chapter − Opening an OpenGL Window");

	init();

	glRotatef(90, 0, 1.0, 0);
	glTranslatef(0.0, 0.5, 0.0);

	glutKeyboardFunc(keyboard);

	glutDisplayFunc(display);
	glutIdleFunc(update);
	glutMainLoop();
	return 0;
}
