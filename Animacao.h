/*
 * Animacao.h
 *
 *  Created on: 20/06/2012
 *      Author: renan
 */

#ifndef ANIMACAO_H_
#define ANIMACAO_H_

#include "Modelo.h"

#define FRAMESCAMINHADA 25
#define FRAMESATAQUE 20

class Animacao {
public:
	Animacao(Modelo *modeloAnimacao);
	virtual ~Animacao();
	void animarPincas();
	void animarCauda();
	void andar(bool frente);
	void correr();
	void atacar();
private:
	Modelo *modelo;
	bool atacando;
};

#endif /* ANIMACAO_H_ */
