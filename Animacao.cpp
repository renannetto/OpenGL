/*
 * Animacao.cpp
 *
 *  Created on: 20/06/2012
 *      Author: renan
 */

#include "Animacao.h"

Animacao::Animacao(Modelo *modeloAnimacao) {
	modelo = modeloAnimacao;
}

Animacao::~Animacao() {
	// TODO Auto-generated destructor stub
}

void Animacao::animarPincas() {
	static int frames = FRAMES;
	static int flag = 0;
	float pinca_esq_sup, pinca_esq_meio, pinca_esq_inf, pinca_dir_sup,
			pinca_dir_meio, pinca_dir_inf;

	float angulos_add[12][3][3];

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				angulos_add[i][j][k] = 0;
			}
		}
	}

	switch (flag) {
	case 0:
		pinca_esq_sup = 0;
		pinca_esq_meio = 30;
		pinca_esq_inf = 0;

		pinca_dir_sup = 0;
		pinca_dir_meio = -30;
		pinca_dir_inf = 0;
		break;
	case 1:
		pinca_esq_sup = 0;
		pinca_esq_meio = -30;
		pinca_esq_inf = 0;

		pinca_dir_sup = 0;
		pinca_dir_meio = 30;
		pinca_dir_inf = 0;
		break;
	}

	angulos_add[PINCA_ESQ][0][Y] = pinca_esq_sup / FRAMES;
	angulos_add[PINCA_ESQ][1][Y] = pinca_esq_meio / FRAMES;
	angulos_add[PINCA_ESQ][2][Y] = pinca_esq_inf / FRAMES;

	angulos_add[PINCA_DIR][0][Y] = pinca_dir_sup / FRAMES;
	angulos_add[PINCA_DIR][1][Y] = pinca_dir_meio / FRAMES;
	angulos_add[PINCA_DIR][2][Y] = pinca_dir_inf / FRAMES;

	modelo->acrescentarAngulos(angulos_add);

	frames--;
	if (frames == 0) {
		flag = (flag + 1) % 2;
		frames = FRAMES;
	}
}

void Animacao::animarCauda() {
	static int frames = FRAMES;
	static int flag = 0;
	float cauda_sup, cauda_meio, cauda_inf, ferrao;

	float angulos_add[12][3][3];

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				angulos_add[i][j][k] = 0;
			}
		}
	}

	switch (flag) {
	case 0:
		cauda_sup = 60;
		cauda_meio = 40;
		cauda_inf = 40;
		ferrao = 60;
		break;
	case 1:
		cauda_sup = -90;
		cauda_meio = -60;
		cauda_inf = -60;
		ferrao = -90;
		break;
	case 2:
		cauda_sup = 10;
		cauda_meio = 0;
		cauda_inf = 0;
		ferrao = 0;
		break;
	case 3:
		cauda_sup = 20;
		cauda_meio = 20;
		cauda_inf = 20;
		ferrao = 30;
		break;
	}

	angulos_add[CAUDA][0][X] = cauda_sup / FRAMES;
	angulos_add[CAUDA][1][X] = cauda_meio / FRAMES;
	angulos_add[CAUDA][2][X] = cauda_inf / FRAMES;
	angulos_add[FERRAO][0][X] = ferrao / FRAMES;

	modelo->acrescentarAngulos(angulos_add);

	frames--;
	if (frames == 0) {
		flag = (flag + 1) % 4;
		frames = FRAMES;
	}
}

void Animacao::andar() {
	static int frames = FRAMES;
	static int flag = 0;

	float base = 0;

	float pata_esq_1_meio_Z = 0;
	float pata_esq_2_meio_Z = 0;
	float pata_esq_3_meio_Z = 0;
	float pata_esq_4_meio_Z = 0;

	float pata_esq_1_sup_Z = 0;
	float pata_esq_2_sup_Z = 0;
	float pata_esq_3_sup_Z = 0;
	float pata_esq_4_sup_Z = 0;

	float pata_dir_1_meio_Z = 0;
	float pata_dir_2_meio_Z = 0;
	float pata_dir_3_meio_Z = 0;
	float pata_dir_4_meio_Z = 0;

	float pata_dir_1_sup_Z = 0;
	float pata_dir_2_sup_Z = 0;
	float pata_dir_3_sup_Z = 0;
	float pata_dir_4_sup_Z = 0;

	float angulos_add[12][3][3];

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				angulos_add[i][j][k] = 0;
			}
		}
	}

	switch (flag) {
	case 0:
		pata_esq_1_sup_Z = -30;
		pata_dir_2_sup_Z = 30;
		pata_esq_3_sup_Z = -30;
		pata_dir_4_sup_Z = 30;

		pata_dir_1_sup_Z = -10;
		pata_esq_2_sup_Z = 10;
		pata_dir_3_sup_Z = -10;
		pata_esq_4_sup_Z = 10;

		pata_esq_1_meio_Z = 30;
		pata_dir_2_meio_Z = -30;
		pata_esq_3_meio_Z = 30;
		pata_dir_4_meio_Z = -30;

		pata_dir_1_meio_Z = 10;
		pata_esq_2_meio_Z = -10;
		pata_dir_3_meio_Z = 10;
		pata_esq_4_meio_Z = -10;

		base = 0.04;
		break;
	case 1:
		pata_esq_1_sup_Z = 30;
		pata_dir_2_sup_Z = -30;
		pata_esq_3_sup_Z = 30;
		pata_dir_4_sup_Z = -30;

		pata_dir_1_sup_Z = 10;
		pata_esq_2_sup_Z = -10;
		pata_dir_3_sup_Z = 10;
		pata_esq_4_sup_Z = -10;

		pata_esq_1_meio_Z = -30;
		pata_dir_2_meio_Z = 30;
		pata_esq_3_meio_Z = -30;
		pata_dir_4_meio_Z = 30;

		pata_dir_1_meio_Z = -10;
		pata_esq_2_meio_Z = 10;
		pata_dir_3_meio_Z = -10;
		pata_esq_4_meio_Z = 10;

		base = -0.04;
		break;
	case 2:
		pata_dir_1_sup_Z = 30;
		pata_esq_2_sup_Z = -30;
		pata_dir_3_sup_Z = 30;
		pata_esq_4_sup_Z = -30;

		pata_esq_1_sup_Z = 10;
		pata_dir_2_sup_Z = -10;
		pata_esq_3_sup_Z = 10;
		pata_dir_4_sup_Z = -10;

		pata_dir_1_meio_Z = -30;
		pata_esq_2_meio_Z = 30;
		pata_dir_3_meio_Z = -30;
		pata_esq_4_meio_Z = 30;

		pata_esq_1_meio_Z = -10;
		pata_dir_2_meio_Z = 10;
		pata_esq_3_meio_Z = -10;
		pata_dir_4_meio_Z = 10;

		base = 0.04;
		break;
	case 3:
		pata_dir_1_sup_Z = -30;
		pata_esq_2_sup_Z = 30;
		pata_dir_3_sup_Z = -30;
		pata_esq_4_sup_Z = 30;

		pata_esq_1_sup_Z = -10;
		pata_dir_2_sup_Z = 10;
		pata_esq_3_sup_Z = -10;
		pata_dir_4_sup_Z = 10;

		pata_dir_1_meio_Z = 30;
		pata_esq_2_meio_Z = -30;
		pata_dir_3_meio_Z = 30;
		pata_esq_4_meio_Z = -30;

		pata_esq_1_meio_Z = 10;
		pata_dir_2_meio_Z = -10;
		pata_esq_3_meio_Z = 10;
		pata_dir_4_meio_Z = -10;

		base = -0.04;
		break;
	}

	angulos_add[PATA_ESQ_1][0][Z] = pata_esq_1_sup_Z / FRAMES;
	angulos_add[PATA_ESQ_2][0][Z] = pata_esq_2_sup_Z / FRAMES;
	angulos_add[PATA_ESQ_3][0][Z] = pata_esq_3_sup_Z / FRAMES;
	angulos_add[PATA_ESQ_4][0][Z] = pata_esq_4_sup_Z / FRAMES;

	angulos_add[PATA_DIR_1][0][Z] = pata_dir_1_sup_Z / FRAMES;
	angulos_add[PATA_DIR_2][0][Z] = pata_dir_2_sup_Z / FRAMES;
	angulos_add[PATA_DIR_3][0][Z] = pata_dir_3_sup_Z / FRAMES;
	angulos_add[PATA_DIR_4][0][Z] = pata_dir_4_sup_Z / FRAMES;

	angulos_add[PATA_ESQ_1][2][Z] = pata_esq_1_meio_Z / FRAMES;
	angulos_add[PATA_ESQ_2][2][Z] = pata_esq_2_meio_Z / FRAMES;
	angulos_add[PATA_ESQ_3][2][Z] = pata_esq_3_meio_Z / FRAMES;
	angulos_add[PATA_ESQ_4][2][Z] = pata_esq_4_meio_Z / FRAMES;

	angulos_add[PATA_DIR_1][2][Z] = pata_dir_1_meio_Z / FRAMES;
	angulos_add[PATA_DIR_2][2][Z] = pata_dir_2_meio_Z / FRAMES;
	angulos_add[PATA_DIR_3][2][Z] = pata_dir_3_meio_Z / FRAMES;
	angulos_add[PATA_DIR_4][2][Z] = pata_dir_4_meio_Z / FRAMES;

	modelo->acrescentarAngulos(angulos_add);
	modelo->movimentoDoCorpo(0, base / FRAMES, 0);

	frames--;
	if (frames == 0) {
		flag = (flag + 1) % 4;
		frames = FRAMES;
	}
}

