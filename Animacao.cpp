/*
 * Animacao.cpp
 *
 *  Created on: 20/06/2012
 *      Author: renan
 */
#include "Animacao.h"

Animacao::Animacao(Modelo *modeloAnimacao) {
	modelo = modeloAnimacao;
	atacando = false;
}

Animacao::~Animacao() {
	// TODO Auto-generated destructor stub
}

void Animacao::animarPincas() {
	if (atacando) {
		static int frames = FRAMESATAQUE;
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
			pinca_esq_sup = 20;
			pinca_esq_meio = 40;
			pinca_esq_inf = 20;

			pinca_dir_sup = -20;
			pinca_dir_meio = -40;
			pinca_dir_inf = -20;
			break;
		case 1:
			pinca_esq_sup = -30;
			pinca_esq_meio = -45;
			pinca_esq_inf = -25;

			pinca_dir_sup = 30;
			pinca_dir_meio = 45;
			pinca_dir_inf = 25;
			break;
		case 2:
			pinca_esq_sup = 0;
			pinca_esq_meio = 0;
			pinca_esq_inf = 0;

			pinca_dir_sup = 0;
			pinca_dir_meio = 0;
			pinca_dir_inf = 0;
			break;
		case 3:
			pinca_esq_sup = 10;
			pinca_esq_meio = 5;
			pinca_esq_inf = 5;

			pinca_dir_sup = -10;
			pinca_dir_meio = -5;
			pinca_dir_inf = -5;
			break;
		}

		angulos_add[PINCA_ESQ][0][Y] = pinca_esq_sup / FRAMESATAQUE;
		angulos_add[PINCA_ESQ][1][Y] = pinca_esq_meio / FRAMESATAQUE;
		angulos_add[PINCA_ESQ][2][Y] = pinca_esq_inf / FRAMESATAQUE;

		angulos_add[PINCA_DIR][0][Y] = pinca_dir_sup / FRAMESATAQUE;
		angulos_add[PINCA_DIR][1][Y] = pinca_dir_meio / FRAMESATAQUE;
		angulos_add[PINCA_DIR][2][Y] = pinca_dir_inf / FRAMESATAQUE;

		modelo->acrescentarAngulos(angulos_add);

		frames--;
		if (frames == 0) {
			flag = (flag + 1) % 4;
			frames = FRAMESATAQUE;
		}
	}
}

void Animacao::animarCauda() {
	if (atacando) {
		static int frames = FRAMESATAQUE;
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
			cauda_meio = 65;
			cauda_inf = 65;
			ferrao = 50;
			break;
		case 1:
			cauda_sup = -130;
			cauda_meio = -55;
			cauda_inf = -55;
			ferrao = -50;
			break;
		case 2:
			cauda_sup = 10;
			cauda_meio = 0;
			cauda_inf = 0;
			ferrao = 0;
			break;
		case 3:
			cauda_sup = 60;
			cauda_meio = -10;
			cauda_inf = -10;
			ferrao = 0;
			break;
		}

		angulos_add[CAUDA][0][X] = cauda_sup / FRAMESATAQUE;
		angulos_add[CAUDA][1][X] = cauda_meio / FRAMESATAQUE;
		angulos_add[CAUDA][2][X] = cauda_inf / FRAMESATAQUE;
		angulos_add[FERRAO][0][X] = ferrao / FRAMESATAQUE;

		modelo->acrescentarAngulos(angulos_add);

		frames--;
		if (frames == 0) {
			if (flag == 3)
				atacando = false;
			flag = (flag + 1) % 4;
			frames = FRAMESATAQUE;
		}
	}
}

void Animacao::andar(bool frente) {
	static int frames = FRAMESCAMINHADA;
	static int flag = 0;

	int direcao;
	if (frente)
		direcao = 1;
	else
		direcao = -1;

	float base = 0;

	float pata_esq_1_sup_Y = 0;
	float pata_esq_2_sup_Y = 0;
	float pata_esq_3_sup_Y = 0;
	float pata_esq_4_sup_Y = 0;

	float pata_dir_1_sup_Y = 0;
	float pata_dir_2_sup_Y = 0;
	float pata_dir_3_sup_Y = 0;
	float pata_dir_4_sup_Y = 0;

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

		pata_esq_1_sup_Y = -10;
		pata_dir_2_sup_Y = 10;
		pata_esq_3_sup_Y = -10;
		pata_dir_4_sup_Y = 10;

		pata_dir_1_sup_Y = -10;
		pata_esq_2_sup_Y = 10;
		pata_dir_3_sup_Y = -10;
		pata_esq_4_sup_Y = 10;

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
		pata_esq_1_sup_Y = -10;
		pata_dir_2_sup_Y = 10;
		pata_esq_3_sup_Y = -10;
		pata_dir_4_sup_Y = 10;

		pata_dir_1_sup_Y = -10;
		pata_esq_2_sup_Y = 10;
		pata_dir_3_sup_Y = -10;
		pata_esq_4_sup_Y = 10;

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
		pata_esq_1_sup_Y = 10;
		pata_dir_2_sup_Y = -10;
		pata_esq_3_sup_Y = 10;
		pata_dir_4_sup_Y = -10;

		pata_dir_1_sup_Y = 10;
		pata_esq_2_sup_Y = -10;
		pata_dir_3_sup_Y = 10;
		pata_esq_4_sup_Y = -10;

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
		pata_esq_1_sup_Y = 10;
		pata_dir_2_sup_Y = -10;
		pata_esq_3_sup_Y = 10;
		pata_dir_4_sup_Y = -10;

		pata_dir_1_sup_Y = 10;
		pata_esq_2_sup_Y = -10;
		pata_dir_3_sup_Y = 10;
		pata_esq_4_sup_Y = -10;

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

	angulos_add[PATA_ESQ_1][0][Y] = direcao * pata_esq_1_sup_Y / FRAMESCAMINHADA;
	angulos_add[PATA_ESQ_2][0][Y] = direcao * pata_esq_2_sup_Y / FRAMESCAMINHADA;
	angulos_add[PATA_ESQ_3][0][Y] = direcao * pata_esq_3_sup_Y / FRAMESCAMINHADA;
	angulos_add[PATA_ESQ_4][0][Y] = direcao * pata_esq_4_sup_Y / FRAMESCAMINHADA;

	angulos_add[PATA_DIR_1][0][Y] = direcao * pata_dir_1_sup_Y / FRAMESCAMINHADA;
	angulos_add[PATA_DIR_2][0][Y] = direcao * pata_dir_2_sup_Y / FRAMESCAMINHADA;
	angulos_add[PATA_DIR_3][0][Y] = direcao * pata_dir_3_sup_Y / FRAMESCAMINHADA;
	angulos_add[PATA_DIR_4][0][Y] = direcao * pata_dir_4_sup_Y / FRAMESCAMINHADA;

	angulos_add[PATA_ESQ_1][0][Z] = direcao * pata_esq_1_sup_Z / FRAMESCAMINHADA;
	angulos_add[PATA_ESQ_2][0][Z] = direcao * pata_esq_2_sup_Z / FRAMESCAMINHADA;
	angulos_add[PATA_ESQ_3][0][Z] = direcao * pata_esq_3_sup_Z / FRAMESCAMINHADA;
	angulos_add[PATA_ESQ_4][0][Z] = direcao * pata_esq_4_sup_Z / FRAMESCAMINHADA;

	angulos_add[PATA_DIR_1][0][Z] = direcao * pata_dir_1_sup_Z / FRAMESCAMINHADA;
	angulos_add[PATA_DIR_2][0][Z] = direcao * pata_dir_2_sup_Z / FRAMESCAMINHADA;
	angulos_add[PATA_DIR_3][0][Z] = direcao * pata_dir_3_sup_Z / FRAMESCAMINHADA;
	angulos_add[PATA_DIR_4][0][Z] = direcao * pata_dir_4_sup_Z / FRAMESCAMINHADA;

	angulos_add[PATA_ESQ_1][2][Z] = direcao
			* pata_esq_1_meio_Z / FRAMESCAMINHADA;
	angulos_add[PATA_ESQ_2][2][Z] = direcao
			* pata_esq_2_meio_Z / FRAMESCAMINHADA;
	angulos_add[PATA_ESQ_3][2][Z] = direcao
			* pata_esq_3_meio_Z / FRAMESCAMINHADA;
	angulos_add[PATA_ESQ_4][2][Z] = direcao
			* pata_esq_4_meio_Z / FRAMESCAMINHADA;

	angulos_add[PATA_DIR_1][2][Z] = direcao
			* pata_dir_1_meio_Z / FRAMESCAMINHADA;
	angulos_add[PATA_DIR_2][2][Z] = direcao
			* pata_dir_2_meio_Z / FRAMESCAMINHADA;
	angulos_add[PATA_DIR_3][2][Z] = direcao
			* pata_dir_3_meio_Z / FRAMESCAMINHADA;
	angulos_add[PATA_DIR_4][2][Z] = direcao
			* pata_dir_4_meio_Z / FRAMESCAMINHADA;

	modelo->acrescentarAngulos(angulos_add);
	modelo->movimentoDoCorpo(0, direcao * base / FRAMESCAMINHADA, 0);

	frames -= direcao;

	if (frames == 0) {
		flag = (flag + 1) % 4;
		frames = FRAMESCAMINHADA;
	} else if (frames == FRAMESCAMINHADA + 1) {
		flag = (flag + 3) % 4;
		frames = 1;
	}
}

void Animacao::atacar() {
	atacando = true;
}

