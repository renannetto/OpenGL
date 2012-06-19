/*
 * Modelo.cpp
 *
 *  Created on: 19/06/2012
 *      Author: renan
 */

#include "Modelo.h"

Modelo::Modelo() {
	// TODO Auto-generated constructor stub

}

Modelo::~Modelo() {
	// TODO Auto-generated destructor stub
}

void Modelo::desenharModelo() {
	glPushMatrix();
	desenharTorso();
	glPopMatrix();
}

void Modelo::desenharTorso() {
	glPushMatrix();
	glScalef(TORSO_LARG, TORSO_ALT, TORSO_COMP);
	glColor3f(0.0, 0.0, 1.0);
	glutWireCube(1.0);

	glPushMatrix();
	glTranslatef(-TORSO_LARG, 0, 0);
	desenharPata(L2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(TORSO_LARG, 0, 0);
	desenharPata(R2);
	glPopMatrix();

	glPopMatrix();
}

void Modelo::desenharPata(LADO lado) {
	glPushMatrix();
	glScalef(PATA_ART, PATA_ART, PATA_ART);
	glColor3f(0.0, 0.0, 1.0);
	glutWireSphere(1.0, 8, 8);
	glPopMatrix();

	glTranslatef(0.0, -PATA_ALT * 0.75, 0.0);
	glPushMatrix();
	glScalef(PATA_LARG, PATA_ALT, PATA_COMP);
	glColor3f(0.0, 0.0, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
}

