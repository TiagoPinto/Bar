#define _USE_MATH_DEFINES_
#include <GL/glut.h>
#include<stdio.h>
#include <math.h>
#include "candeeiro.h"
#include "cilindro.h"
#include "esfera.h"
#include "cubo.h"
#include "plano.h"
/**
 * Construtor da class Cilindro.
 * Inicializa as variaveis de comprimento, altura, fatias e camadas do cilindro.
 *@param c
 * 	 Variavel que especifica o comprimento do cilindro	
 *@param a
 * 	 Variavel que especifica a altura do cilindro
  *@param f
 * 	 Variavel que especifica as fatias do cilindro
  *@param p
 * 	 Variavel que especifica as camadas do cilindro
 */

/**
 * Construtor da class Candeeiro.
 * Inicializa todas as variaveis de instancia.
 *
 */
Candeeiro::Candeeiro(){
	this->comprimento = 0.0f;
	this->altura = 0.0f;
	this->fatias = 0.0f;
	this->camadas = 0.0f;
}

Candeeiro::Candeeiro(float c, float a, float f, float p){
	this->comprimento = c;
	this->altura = a;
	this->fatias = f;
	this->camadas = p;
}
/**
 * Método que desenha um cilindro
 *
 */
void Candeeiro::desenhaA(){
	Cubo *base;
	Cubo *segurador[2];
	Plano *caixa[9];
	Cilindro *vela;

	glPushMatrix();
		glTranslatef(0.0f,-this->altura/2, 0.0f);
		base = new Cubo(this->comprimento, this->altura / 6, this->comprimento, this->fatias, this->camadas);
		base->desenha();
	glPopMatrix();

	//parede da caixa, parte traseira
	glPushMatrix();
		glTranslatef(0.0f,-this->altura /6, -this->comprimento/2);
		caixa[0] = new Plano(this->comprimento, this->altura / 2, this->fatias, this->camadas);
		caixa[0]->desenhaXoY();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0f,-this->altura /6, -this->comprimento/2);
		glRotatef(180,0,1,0);
		caixa[1] = new Plano(this->comprimento, this->altura / 2, this->fatias, this->camadas);
		caixa[1]->desenhaXoY();
	glPopMatrix();

	//parede da caixa, parte frontal
	glPushMatrix();
		glTranslatef(0.0f,-this->altura /6, this->comprimento/2);
		caixa[2] = new Plano(this->comprimento, this->altura / 2, this->fatias, this->camadas);
		caixa[2]->desenhaXoY();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0f,-this->altura /6, this->comprimento/2);
		glRotatef(180,0,1,0);
		caixa[3] = new Plano(this->comprimento, this->altura / 2, this->fatias, this->camadas);
		caixa[3]->desenhaXoY();
	glPopMatrix();

	//parede da caixa, parte lateral direita
	glPushMatrix();
		glTranslatef(this->comprimento/2,-this->altura /6, 0.0f);
		glRotatef(90,0,1,0);
		caixa[4] = new Plano(this->comprimento, this->altura / 2, this->fatias, this->camadas);
		caixa[4]->desenhaXoY();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(this->comprimento/2,-this->altura /6, 0.0f);
		glRotatef(-90,0,1,0);
		caixa[5] = new Plano(this->comprimento, this->altura / 2, this->fatias, this->camadas);
		caixa[5]->desenhaXoY();
	glPopMatrix();

	//parede da caixa, parte lateral esquerda
	glPushMatrix();
		glTranslatef(-this->comprimento/2,-this->altura /6, 0.0f);
		glRotatef(90,0,1,0);
		caixa[6] = new Plano(this->comprimento, this->altura / 2, this->fatias, this->camadas);
		caixa[6]->desenhaXoY();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-this->comprimento/2,-this->altura /6, 0.0f);
		glRotatef(-90,0,1,0);
		caixa[7] = new Plano(this->comprimento, this->altura / 2, this->fatias, this->camadas);
		caixa[7]->desenhaXoY();
	glPopMatrix();

	//parede da caixa, tecto
	glPushMatrix();
		glTranslatef(0.0f,this->altura /12, 0.0f);
		glRotatef(180,1,0,0);
		caixa[6] = new Plano(this->comprimento, this->comprimento, this->fatias, this->camadas);
		caixa[6]->desenhaXoZ();
	glPopMatrix();

	//piramide no topo


	//vela
	glPushMatrix();
		glTranslatef(0.0f,-this->altura /4, 0.0f);
		vela = new Cilindro(this->comprimento/5, this->altura/3, this->fatias*2, this->camadas);
		vela->desenha();
	glPopMatrix();

	//Sitio onde segura
	glPushMatrix();
		glTranslatef(0.0f,this->altura/2 + this->altura / 16, 0.0f);
		segurador[0] = new Cubo(this->comprimento /20, this->altura / 8, this->comprimento / 20, this->fatias, this->camadas);
		segurador[0]->desenha();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.0f,this->altura/2 + this->altura / 8 + this->comprimento / 20, -this->comprimento/4);
		segurador[0] = new Cubo(this->comprimento /8, this->comprimento / 10, 2 * this->comprimento / 3, this->fatias, this->camadas);
		segurador[0]->desenha();
	glPopMatrix();
}