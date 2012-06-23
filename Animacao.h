/*
 * Animacao.h
 *
 *  Created on: 20/06/2012
 *      Author: renan
 */

#ifndef ANIMACAO_H_
#define ANIMACAO_H_

#include "Modelo.h"

#define FRAMES 50

class Animacao {
public:
	Animacao(Modelo *modeloAnimacao);
	virtual ~Animacao();
	void animarPincas();
	void animarCauda();
	void andar();
	void correr();
private:
	Modelo *modelo;
};

#endif /* ANIMACAO_H_ */
