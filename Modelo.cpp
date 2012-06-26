/*
 * Modelo.cpp
 *
 *  Created on: 19/06/2012
 *      Author: renan
 */

#include "Modelo.h"
#include <math.h>

Modelo::Modelo() {
	posicao[X] = 0;
	posicao[Y] = 0;
	posicao[Z] = -3;

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				angulos[i][j][k] = 0;
			}
		}
	}

	angulos[PATA_ESQ_1][0][Y] = 10;
	angulos[PATA_DIR_1][0][Y] = 10;
	angulos[PATA_ESQ_2][0][Y] = -10;
	angulos[PATA_DIR_2][0][Y] = -10;
	angulos[PATA_ESQ_3][0][Y] = 10;
	angulos[PATA_DIR_3][0][Y] = 10;
	angulos[PATA_ESQ_4][0][Y] = -10;
	angulos[PATA_DIR_4][0][Y] = -10;

	angulos[PATA_ESQ_1][0][Z] = -135;
	angulos[PATA_DIR_1][0][Z] = 135;
	angulos[PATA_ESQ_2][0][Z] = -135;
	angulos[PATA_DIR_2][0][Z] = 135;
	angulos[PATA_ESQ_3][0][Z] = -135;
	angulos[PATA_DIR_3][0][Z] = 135;
	angulos[PATA_ESQ_4][0][Z] = -135;
	angulos[PATA_DIR_4][0][Z] = 135;

	angulos[PATA_ESQ_1][1][Z] = 90;
	angulos[PATA_DIR_1][1][Z] = -90;
	angulos[PATA_ESQ_2][1][Z] = 90;
	angulos[PATA_DIR_2][1][Z] = -90;
	angulos[PATA_ESQ_3][1][Z] = 90;
	angulos[PATA_DIR_3][1][Z] = -90;
	angulos[PATA_ESQ_4][1][Z] = 90;
	angulos[PATA_DIR_4][1][Z] = -90;

	angulos[PATA_ESQ_1][2][Z] = 45;
	angulos[PATA_DIR_1][2][Z] = -45;
	angulos[PATA_ESQ_2][2][Z] = 45;
	angulos[PATA_DIR_2][2][Z] = -45;
	angulos[PATA_ESQ_3][2][Z] = 45;
	angulos[PATA_DIR_3][2][Z] = -45;
	angulos[PATA_ESQ_4][2][Z] = 45;
	angulos[PATA_DIR_4][2][Z] = -45;

	angulos[PINCA_ESQ][0][Y] = 45;
	angulos[PINCA_DIR][0][Y] = -45;

	angulos[PINCA_ESQ][1][Y] = -45;
	angulos[PINCA_DIR][1][Y] = 45;

	angulos[PINCA_ESQ][2][Y] = -45;
	angulos[PINCA_DIR][2][Y] = 45;

	angulos[CAUDA][0][X] = -70;
	angulos[CAUDA][1][X] = -50;
	angulos[CAUDA][2][X] = -50;

	angulos[FERRAO][0][X] = -45;
}

Modelo::~Modelo() {
	// TODO Auto-generated destructor stub
}

void Modelo::desenharModelo(int angX, int angY, FRAME frame) {
	glPushMatrix();
	glTranslatef(posicao[X], posicao[Y], posicao[Z]);
	glRotatef(angX, 0.0, 1.0, 0.0);
	glRotatef(angY, 1.0, 0.0, 0.0);
	desenharTorso(frame);

	glPushMatrix();
	glTranslatef(-(0.9 * TORSO_LARG / 2), 0, 0);
	glTranslatef(0.0, 0.0, 2 * TORSO_COMP / 5);
	desenharPata(PATA_ESQ_1, frame);
	glTranslatef(-(0.2 * TORSO_LARG / 2), 0, 0);
	glTranslatef(0.0, 0.0, -TORSO_COMP / 5);
	desenharPata(PATA_ESQ_2, frame);
	glTranslatef(0.0, 0.0, -TORSO_COMP / 5);
	desenharPata(PATA_ESQ_3, frame);
	glTranslatef(0.0, 0.0, -TORSO_COMP / 5);
	desenharPata(PATA_ESQ_4, frame);
	glTranslatef((0.2 * TORSO_LARG / 2), 0, 0);
	glTranslatef(0.0, 0.0, -1.1 * TORSO_COMP / 5);
	desenharPinca(PINCA_ESQ, frame);
	glPopMatrix();

	glPushMatrix();
	glTranslatef((0.9 * TORSO_LARG / 2), 0, 0);
	glTranslatef(0.0, 0.0, 2 * TORSO_COMP / 5);
	desenharPata(PATA_DIR_1, frame);
	glTranslatef((0.2 * TORSO_LARG / 2), 0, 0);
	glTranslatef(0.0, 0.0, -TORSO_COMP / 5);
	desenharPata(PATA_DIR_2, frame);
	glTranslatef(0.0, 0.0, -TORSO_COMP / 5);
	desenharPata(PATA_DIR_3, frame);
	glTranslatef(0.0, 0.0, -TORSO_COMP / 5);
	desenharPata(PATA_DIR_4, frame);
	glTranslatef(-(0.2 * TORSO_LARG / 2), 0, 0);
	glTranslatef(0.0, 0.0, -1.1 * TORSO_COMP / 5);
	desenharPinca(PINCA_DIR, frame);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, (0.6 * TORSO_ALT - ART) / 2,
			(1.05 * TORSO_COMP / 2) + ART);
	desenharCauda(CAUDA, frame);
	glPopMatrix();

	glPopMatrix();
}

void Modelo::desenharTorso(FRAME frame) {
	glPushMatrix();
	glScalef(TORSO_LARG, TORSO_ALT, TORSO_COMP);
	glColor3f(0.0, 1.0, 0.0);
	if (frame == WIRE)
		glutWireSphere(0.6, 10, 10);
	else
		glutSolidSphere(0.6, 10, 10);
	glPopMatrix();
}

void Modelo::desenharPata(PARTE_DO_CORPO parte, FRAME frame) {
	glPushMatrix();
	glRotatef(angulos[parte][0][Y], 0.0, 1.0, 0.0);
	glRotatef(angulos[parte][0][Z], 0.0, 0.0, 1.0);
	desenharPataSuperior(frame);
	glTranslatef(0.0, -(PATA_SUP_ALT / 2), 0.0);
	glRotatef(angulos[parte][1][Z], 0.0, 0.0, 1.0);
	desenharPataMeio(frame);
	glTranslatef(0.0, -(PATA_MEIO_ALT / 2), 0.0);
	glRotatef(angulos[parte][2][Z], 0.0, 0.0, 1.0);
	desenharPataInferior(frame);
	glPopMatrix();
}

void Modelo::desenharPataSuperior(FRAME frame) {
	/*glPushMatrix();
	glScalef(ART, ART, ART);
	glColor3f(0.0, 0.0, 1.0);
	if (frame == WIRE)
		glutWireSphere(1.0, 8, 8);
	else
		glutSolidSphere(1.0, 8, 8);
	glPopMatrix();*/

	glTranslatef(0.0, -(PATA_SUP_ALT / 2), 0.0);
	glPushMatrix();
	glScalef(PATA_SUP_LARG, PATA_SUP_ALT, PATA_SUP_COMP);
	glColor3f(0.0, 0.0, 1.0);
	if (frame == WIRE)
		glutWireSphere(0.5, 8, 8);
	else
		glutSolidSphere(0.5, 8, 8);
	glPopMatrix();
}

void Modelo::desenharPataMeio(FRAME frame) {
	/*glPushMatrix();
	glScalef(ART, ART, ART);
	glColor3f(0.0, 0.0, 1.0);
	if (frame == WIRE)
		glutWireSphere(1.0, 8, 8);
	else
		glutSolidSphere(1.0, 8, 8);
	glPopMatrix();*/

	glTranslatef(0.0, -(PATA_MEIO_ALT / 2), 0.0);
	glPushMatrix();
	glScalef(PATA_MEIO_LARG, PATA_MEIO_ALT, PATA_MEIO_COMP);
	glColor3f(0.0, 0.0, 1.0);
	if (frame == WIRE)
		glutWireSphere(0.5, 8, 8);
	else
		glutSolidSphere(0.5, 8, 8);
	glPopMatrix();
}

void Modelo::desenharPataInferior(FRAME frame) {
	/*glPushMatrix();
	glScalef(ART, ART, ART);
	glColor3f(0.0, 0.0, 1.0);
	if (frame == WIRE)
		glutWireSphere(1.0, 8, 8);
	else
		glutSolidSphere(1.0, 8, 8);
	glPopMatrix();*/

	glTranslatef(0.0, -(PATA_INF_ALT / 2), 0.0);
	glPushMatrix();
	glScalef(PATA_INF_LARG, PATA_INF_ALT, PATA_INF_COMP);
	glColor3f(0.0, 0.0, 1.0);
	if (frame == WIRE)
		glutWireSphere(0.5, 8, 8);
	else
		glutSolidSphere(0.5, 8, 8);
	glPopMatrix();
}

void Modelo::desenharPinca(PARTE_DO_CORPO parte, FRAME frame) {
	glPushMatrix();
	glRotatef(angulos[parte][0][Y], 0.0, 1.0, 0.0);
	desenharPincaSuperior(frame);
	glTranslatef(0.0, 0.0, -(PINCA_SUP_COMP / 2));
	glRotatef(angulos[parte][1][Y], 0.0, 1.0, 0.0);
	desenharPincaMeio(frame);
	glTranslatef(0.0, 0.0, -(PINCA_MEIO_COMP / 2));
	glRotatef(angulos[parte][2][Y], 0.0, 1.0, 0.0);
	desenharPincaInferior(frame);
	glPopMatrix();
}

void Modelo::desenharPincaSuperior(FRAME frame) {
	/*glPushMatrix();
	glScalef(ART, ART, ART);
	glColor3f(1.0, 0.0, 0.0);
	if (frame == WIRE)
		glutWireSphere(1.0, 8, 8);
	else
		glutSolidSphere(1.0, 8, 8);
	glPopMatrix();*/

	glTranslatef(0.0, 0.0, -(PINCA_SUP_COMP / 2));
	glPushMatrix();
	glScalef(PINCA_SUP_LARG, PINCA_SUP_ALT, PINCA_SUP_COMP);
	glColor3f(1.0, 0.0, 0.0);
	if (frame == WIRE)
		glutWireSphere(0.5, 8, 8);
	else
		glutSolidSphere(0.5, 8, 8);
	glPopMatrix();
}

void Modelo::desenharPincaMeio(FRAME frame) {
	/*glPushMatrix();
	glScalef(ART, ART, ART);
	glColor3f(1.0, 0.0, 0.0);
	if (frame == WIRE)
		glutWireSphere(1.0, 8, 8);
	else
		glutSolidSphere(1.0, 8, 8);
	glPopMatrix();*/

	glTranslatef(0.0, 0.0, -(PINCA_MEIO_COMP / 2));
	glPushMatrix();
	glScalef(PINCA_MEIO_LARG, PINCA_MEIO_ALT, PINCA_MEIO_COMP);
	glColor3f(1.0, 0.0, 0.0);
	if (frame == WIRE)
		glutWireSphere(0.5, 8, 8);
	else
		glutSolidSphere(0.5, 8, 8);
	glPopMatrix();
}

void Modelo::desenharPincaInferior(FRAME frame) {
	/*glPushMatrix();
	glScalef(ART, ART, ART);
	glColor3f(1.0, 0.0, 0.0);
	if (frame == WIRE)
		glutWireSphere(1.0, 8, 8);
	else
		glutSolidSphere(1.0, 8, 8);
	glPopMatrix();*/

	//glTranslatef(0.0, 0.0, -(ART));
	glPushMatrix();
	glScalef(PINCA_INF_LARG, PINCA_INF_ALT, PINCA_INF_COMP);
	glRotatef(180, 1.0, 0.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	if (frame == WIRE)
		glutWireCone(0.5, 1.0, 8, 8);
	else
		glutSolidCone(0.5, 1.0, 8, 8);
	glPopMatrix();
}

void Modelo::desenharCauda(PARTE_DO_CORPO parte, FRAME frame) {
	glPushMatrix();
	glRotatef(angulos[parte][0][X], 1.0, 0.0, 0.0);
	desenharCaudaSuperior(frame);
	glTranslatef(0.0, 0.0, (CAUDA_SUP_COMP / 2));
	glRotatef(angulos[parte][1][X], 1.0, 0.0, 0.0);
	desenharCaudaMeio(frame);
	glTranslatef(0.0, 0.0, (CAUDA_MEIO_COMP / 2));
	glRotatef(angulos[parte][2][X], 1.0, 0.0, 0.0);
	desenharCaudaInferior(frame);
	glTranslatef(0.0, 0.0, (CAUDA_INF_COMP / 2));
	glRotatef(angulos[FERRAO][0][X], 1.0, 0.0, 0.0);
	desenharFerrao(frame);
	glPopMatrix();
}

void Modelo::desenharCaudaSuperior(FRAME frame) {
//	glPushMatrix();
//	glScalef(ART, ART, ART);
//	glColor3f(1.0, 1.0, 0.0);
//	if (frame == WIRE)
//		glutWireSphere(1.0, 8, 8);
//	else
//		glutSolidSphere(1.0, 8, 8);
//	glPopMatrix();

	glTranslatef(0.0, 0.0, (CAUDA_SUP_COMP / 2));
	glPushMatrix();
	glScalef(CAUDA_SUP_LARG, CAUDA_SUP_ALT, CAUDA_SUP_COMP);
	glColor3f(1.0, 1.0, 0.0);
	if (frame == WIRE)
		glutWireSphere(0.5, 8, 8);
	else
		glutSolidSphere(0.5, 8, 8);
	glPopMatrix();
}

void Modelo::desenharCaudaMeio(FRAME frame) {
//	glPushMatrix();
//	glScalef(ART, ART, ART);
//	glColor3f(1.0, 1.0, 0.0);
//	if (frame == WIRE)
//		glutWireSphere(1.0, 8, 8);
//	else
//		glutSolidSphere(1.0, 8, 8);
//	glPopMatrix();

	glTranslatef(0.0, 0.0, (CAUDA_MEIO_COMP / 2));
	glPushMatrix();
	glScalef(CAUDA_MEIO_LARG, CAUDA_MEIO_ALT, CAUDA_MEIO_COMP);
	glColor3f(1.0, 1.0, 0.0);
	if (frame == WIRE)
		glutWireSphere(0.5, 8, 8);
	else
		glutSolidSphere(0.5, 8, 8);
	glPopMatrix();
}

void Modelo::desenharCaudaInferior(FRAME frame) {
//	glPushMatrix();
//	glScalef(ART, ART, ART);
//	glColor3f(1.0, 1.0, 0.0);
//	if (frame == WIRE)
//		glutWireSphere(1.0, 8, 8);
//	else
//		glutSolidSphere(1.0, 8, 8);
//	glPopMatrix();

	glTranslatef(0.0, 0.0, (CAUDA_INF_COMP / 2));
	glPushMatrix();
	glScalef(CAUDA_INF_LARG, CAUDA_INF_ALT, CAUDA_INF_COMP);
	glColor3f(1.0, 1.0, 0.0);
	if (frame == WIRE)
		glutWireSphere(0.5, 8, 8);
	else
		glutSolidSphere(0.5, 8, 8);
	glPopMatrix();
}

void Modelo::desenharFerrao(FRAME frame) {
//	glPushMatrix();
//	glScalef(ART, ART, ART);
//	glColor3f(1.0, 1.0, 0.0);
//	if (frame == WIRE)
//		glutWireSphere(1.0, 8, 8);
//	else
//		glutSolidSphere(1.0, 8, 8);
//	glPopMatrix();

	/*
	 * Parte gambiarrada
	 */

	glTranslatef(0.0, 0.0, FERRAO_COMP/2);
	glPushMatrix();
	glScalef(FERRAO_LARG, FERRAO_ALT, FERRAO_COMP);
	glColor3f(1.0, 1.0, 0.0);
	if (frame == WIRE)
		glutWireSphere(0.45, 8, 8);
	else
		glutSolidSphere(0.45, 8, 8);
	glScalef(0.5, 0.5, 1);
	glTranslatef(0, 1.05*FERRAO_ALT/2, 0);
	glRotatef(30, 1, 0, 0);
	if (frame == WIRE)
		glutWireCone(0.5, 1.0, 8, 8);
	else
		glutSolidCone(0.5, 1.0, 8, 8);
	glPopMatrix();
}

void Modelo::acrescentarAngulos(float angulos_add[12][3][3]) {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				angulos[i][j][k] += angulos_add[i][j][k];
			}
		}
	}
}

void Modelo::movimentoDoCorpo(float x, float y, float z) {
	posicao[X] += x;
	posicao[Y] += y;
	posicao[Z] += z;
}

