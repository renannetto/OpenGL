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

#define ART TORSO_LARG/20.0

#define PATA_SUP_COMP PATA_MEIO_COMP
#define PATA_SUP_ALT PATA_MEIO_ALT*0.5
#define PATA_SUP_LARG PATA_MEIO_LARG

#define PATA_MEIO_COMP TORSO_ALT/2.0
#define PATA_MEIO_ALT TORSO_COMP/7.0
#define PATA_MEIO_LARG PATA_MEIO_COMP/2.0

#define PATA_INF_COMP PATA_MEIO_COMP
#define PATA_INF_ALT PATA_MEIO_ALT*0.7
#define PATA_INF_LARG PATA_MEIO_LARG

#define PINCA_SUP_COMP PATA_MEIO_ALT
#define PINCA_SUP_ALT 1.5*PATA_MEIO_LARG
#define PINCA_SUP_LARG 1.5*PATA_MEIO_LARG

#define PINCA_MEIO_COMP 1.5*PINCA_SUP_COMP
#define PINCA_MEIO_ALT 1.5*PINCA_SUP_ALT
#define PINCA_MEIO_LARG 1.5*PINCA_SUP_LARG

#define PINCA_INF_COMP PINCA_MEIO_ALT
#define PINCA_INF_ALT PINCA_INF_COMP
#define PINCA_INF_LARG PINCA_INF_COMP

#define CAUDA_SUP_COMP TORSO_COMP/1.8
#define CAUDA_SUP_ALT TORSO_ALT/1.4
#define CAUDA_SUP_LARG CAUDA_SUP_ALT

#define CAUDA_MEIO_COMP CAUDA_SUP_COMP*0.9
#define CAUDA_MEIO_ALT CAUDA_SUP_ALT
#define CAUDA_MEIO_LARG CAUDA_SUP_LARG

#define CAUDA_INF_COMP CAUDA_SUP_COMP*0.8
#define CAUDA_INF_ALT CAUDA_SUP_ALT
#define CAUDA_INF_LARG CAUDA_SUP_LARG

#define FERRAO_COMP CAUDA_INF_LARG*1.2
#define FERRAO_ALT FERRAO_COMP
#define FERRAO_LARG FERRAO_COMP

enum PARTE_DO_CORPO {
	PATA_ESQ_1, PATA_ESQ_2, PATA_ESQ_3, PATA_ESQ_4,
	PATA_DIR_1, PATA_DIR_2, PATA_DIR_3, PATA_DIR_4,
	PINCA_ESQ, PINCA_DIR,
	CAUDA,
	FERRAO
};

enum FRAME {WIRE, SOLID};

enum EIXO {X, Y, Z};

class Modelo {
public:
	Modelo();
	virtual ~Modelo();
	void desenharModelo(int angX, int angY, FRAME frame);
	void acrescentarAngulos(float angulos_add[12][3][3]);
	void movimentoDoCorpo(float x, float y, float z);
	void iniciarMedidas();
private:
	void desenharTorso(FRAME frame);
	void desenharPata(PARTE_DO_CORPO parte, FRAME frame);
	void desenharPataSuperior(FRAME frame);
	void desenharPataMeio(FRAME frame);
	void desenharPataInferior(FRAME frame);
	void desenharPinca(PARTE_DO_CORPO parte, FRAME frame);
	void desenharPincaSuperior(FRAME frame);
	void desenharPincaMeio(FRAME frame);
	void desenharPincaInferior(FRAME frame);
	void desenharCauda(PARTE_DO_CORPO parte, FRAME frame);
	void desenharCaudaSuperior(FRAME frame);
	void desenharCaudaMeio(FRAME frame);
	void desenharCaudaInferior(FRAME frame);
	void desenharFerrao(FRAME frame);
	float angulos[12][3][3];
	float posicao[3];
};

#endif /* MODELO_H_ */
