/*
 * main.c
 *
 *  Created on: 16/06/2012
 *      Author: renan
 */
#include "Animacao.h"

Modelo modelo;
FRAME frame = SOLID;
Animacao animacao = Animacao(&modelo);

int angX = 0;
int angY = 0;
bool andandoParaFrente = false;
bool andandoParaTras = false;

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

void draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	setLight0();

	modelo.desenharModelo(angX, angY, frame);

	glutSwapBuffers();
}

void update() {

	animacao.animarPincas();
	animacao.animarCauda();
	if (andandoParaFrente)
		animacao.andar(true);
	else if (andandoParaTras)
		animacao.andar(false);

	glutPostRedisplay();
}

void keyPressed(unsigned char key, int x, int y) {
	switch (key) { // feito na primeira aula de OpenGL
	case 'a':
		angX += 10;
		break;
	case 'd':
		angX -= 10;
		break;
	case 'w':
		angY += 10;
		break;
	case 's':
		angY -= 10;
		break;
	case 32:
		animacao.atacar();
		break;
	case 'i':
		andandoParaFrente = true;
		break;
	case 'k':
		andandoParaTras = true;
		break;
	case '1':
		andandoParaFrente = !andandoParaFrente;
		break;
	case '2':
		if (frame == SOLID)
			frame = WIRE;
		else if (frame == WIRE)
			frame = SOLID;
		break;
	case '+':
		animacao.diminuirFrames();
		modelo.iniciarMedidas();
		break;
	case '-':
		animacao.aumentarFrames();
		modelo.iniciarMedidas();
		break;
	}

	glutPostRedisplay(); // redesenha depois de evento de teclado
}

void keyReleased(unsigned char key, int x, int y) {
	switch (key) {
	case 'i':
		andandoParaFrente = false;
		break;
	case 'k':
		andandoParaTras = false;
		break;
	}
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

void initGL() {
	glShadeModel(GL_SMOOTH); // tente trocar por GL_FLAT
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // define cor para limpar fundo
	glClearDepth(1.0f); // inicializa buffer de profundidade
	glEnable(GL_DEPTH_TEST); //
	glDepthFunc(GL_LEQUAL); //
	glEnable(GL_COLOR_MATERIAL); // cor de objetos com glColor apenas
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	//glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // default: GL_FILL
}

int main(int argc, char** argv) {
	// inicializar GLUT:
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Minha janela com GLUT");

	// definir funcoes de callback da GLUT:
	glutDisplayFunc(draw);
	glutIdleFunc(update);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyPressed);
	glutKeyboardUpFunc(keyReleased);

	initGL(); // inicializar OpenGL

	glutMainLoop(); // nao retorna

	return 0;
}
