/*
 * Modelo.cpp
 *
 *  Created on: 19/06/2012
 *      Author: renan
 */

#include "Modelo.h"

Modelo::Modelo() {
	angulos[L1][0] = -45;
	angulos[R1][0] = 45;
	angulos[L2][0] = -45;
	angulos[R2][0] = 45;
	angulos[L3][0] = -45;
	angulos[R3][0] = 45;
	angulos[L1][1] = 45;
	angulos[R1][1] = -45;
	angulos[L2][1] = 45;
	angulos[R2][1] = -45;
	angulos[L3][1] = 45;
	angulos[R3][1] = -45;
}

Modelo::~Modelo() {
	// TODO Auto-generated destructor stub
}

void Modelo::desenharModelo() {
	glPushMatrix();
	glTranslatef(0, 0, -2);
	//glRotatef(-90, 0.0, 1.0, 0.0);
	desenharTorso();

	glPushMatrix();
	glTranslatef(-(1.1 * TORSO_LARG / 2), 0, 0);
	glTranslatef(0.0, 0.0, TORSO_COMP / 3);
	desenharPata(L1);
	glTranslatef(0.0, 0.0, -TORSO_COMP / 3);
	desenharPata(L2);
	glTranslatef(0.0, 0.0, -TORSO_COMP / 3);
	desenharPata(L3);
	glPopMatrix();

	glPushMatrix();
	glTranslatef((1.1 * TORSO_LARG / 2), 0, 0);
	glTranslatef(0.0, 0.0, TORSO_COMP / 3);
	desenharPata(R1);
	glTranslatef(0.0, 0.0, -TORSO_COMP / 3);
	desenharPata(R2);
	glTranslatef(0.0, 0.0, -TORSO_COMP / 3);
	desenharPata(R3);
	glPopMatrix();

	glPopMatrix();
}

void Modelo::desenharTorso() {
	glPushMatrix();
	glScalef(TORSO_LARG, TORSO_ALT, TORSO_COMP);
	glColor3f(0.0, 0.0, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
}

void Modelo::desenharPata(LADO lado) {
	glPushMatrix();
	glRotatef(angulos[lado][0], 0.0, 0.0, 1.0);
	desenharPataSuperior(lado);
	glTranslatef(0.0, -(PATA_COMP / 2 + PATA_ART), 0.0);
	glRotatef(angulos[lado][1], 0.0, 0.0, 1.0);
	desenharPataInferior(lado);
	glPopMatrix();
}

void Modelo::desenharPataSuperior(LADO lado) {
	glPushMatrix();
	glScalef(PATA_ART, PATA_ART, PATA_ART);
	glColor3f(0.0, 0.0, 1.0);
	glutWireSphere(1.0, 8, 8);
	glPopMatrix();

	glTranslatef(0.0, -(PATA_ALT / 2 + PATA_ART), 0.0);
	glPushMatrix();
	glScalef(PATA_LARG, PATA_COMP, PATA_ALT);
	glColor3f(0.0, 0.0, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
}

void Modelo::desenharPataInferior(LADO lado) {
	glPushMatrix();
	glScalef(PATA_ART, PATA_ART, PATA_ART);
	glColor3f(0.0, 0.0, 1.0);
	glutWireSphere(1.0, 8, 8);
	glPopMatrix();

	glTranslatef(0.0, -(PATA_ALT / 2 + PATA_ART), 0.0);
	glPushMatrix();
	glScalef(PATA_LARG, PATA_COMP, PATA_ALT);
	glColor3f(0.0, 0.0, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
}

