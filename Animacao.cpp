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
	float p_esq_sup, p_esq_meio, p_esq_inf, p_dir_sup, p_dir_meio, p_dir_inf;
	float p_esq_sup_add, p_esq_meio_add, p_esq_inf_add, p_dir_sup_add,
			p_dir_meio_add, p_dir_inf_add;

	float angulos_add[12][3][3];

	switch (flag) {
	case 0:
		p_esq_sup = 0;
		p_esq_meio = -30;
		p_esq_inf = -30;

		p_dir_sup = 0;
		p_dir_meio = 30;
		p_dir_inf = 30;
		break;
	}

	p_esq_sup_add = p_esq_sup / FRAMES;
	p_esq_meio_add = p_esq_meio / FRAMES;
	p_esq_inf_add = p_esq_inf / FRAMES;

	p_dir_sup_add = p_esq_sup / FRAMES;
	p_dir_meio_add = p_esq_meio / FRAMES;
	p_dir_inf_add = p_esq_inf / FRAMES;

	angulos_add[PINCA_ESQ][0][Y] = p_esq_sup_add;
	angulos_add[PINCA_ESQ][1][Y] = p_esq_meio_add;
	angulos_add[PINCA_ESQ][2][Y] = p_esq_inf_add;

	angulos_add[PINCA_DIR][0][Y] = p_dir_sup_add;
	angulos_add[PINCA_DIR][1][Y] = p_dir_meio_add;
	angulos_add[PINCA_DIR][2][Y] = p_dir_inf_add;

	modelo->acrescentarAngulos(angulos_add);

	frames--;
	if (frames == 0) {
		flag = (flag + 1) % 1;
	}
}

