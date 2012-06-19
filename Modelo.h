/*
 * Modelo.h
 *
 *  Created on: 19/06/2012
 *      Author: renan
 */

#ifndef MODELO_H_
#define MODELO_H_

#include <GL/glut.h>

#define TORSO_COMP 1.0
#define TORSO_ALT TORSO_COMP/5.0
#define TORSO_LARG TORSO_COMP/3.0

#define PATA_ART TORSO_LARG/10.0

#define PATA_SUP_COMP TORSO_COMP/5.0
#define PATA_SUP_ALT TORSO_ALT/2.0
#define PATA_SUP_LARG PATA_SUP_ALT/2.0

#define PATA_INF_COMP PATA_SUP_COMP*0.7
#define PATA_INF_ALT PATA_SUP_ALT
#define PATA_INF_LARG PATA_SUP_LARG

enum LADO {
	R1, R2, R3, L1, L2, L3
};

class Modelo {
public:
	Modelo();
	virtual ~Modelo();
	void desenharModelo();
private:
	void desenharTorso();
	void desenharPata(LADO lado);
	void desenharPataSuperior(LADO lado);
	void desenharPataInferior(LADO lado);
	float angulos[3][2];
};

#endif /* MODELO_H_ */
