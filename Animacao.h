/*
 * Animacao.h
 *
 *  Created on: 20/06/2012
 *      Author: renan
 */

#ifndef ANIMACAO_H_
#define ANIMACAO_H_

#include "Modelo.h"

static int FRAMESCAMINHADA = 15;
static int FRAMESATAQUE = 10;
static int flagPinca = 0;
static int flagCauda = 0;
static int flagAndar = 0;
static int framesPinca = FRAMESATAQUE;
static int framesCauda = FRAMESATAQUE;
static int framesAndar = FRAMESCAMINHADA;

class Animacao {
public:
	Animacao(Modelo *modeloAnimacao);
	virtual ~Animacao();
	void animarPincas();
	void animarCauda();
	void andar(bool frente);
	void atacar();
	void aumentarFrames();
	void diminuirFrames();
private:
	Modelo *modelo;
	bool atacando;
};

#endif /* ANIMACAO_H_ */
