#define _USE_MATH_DEFINES

#include "mesa.h"
#include "cubo.h"
#include "cilindro.h"
#include <GL/glut.h>
#include <math.h>

/**
 * Construtor da class Mesa.
 * Inicializa as variaveis de comprimento, largura, altura, espessura, fatias e camadas.	
 */
Mesa::Mesa(){
	this->comprimento = 0.0f;
	this->largura = 0.0f;
	this->altura = 0.0f;
	this->espessura = 0.0f;
	this->fatias = 0.0f;
	this->camadas = 0.0f;
}

/**
 * Construtor da class Mesa.
 * Inicializa as variaveis de raio e altura do cilindro.
 *@param c
 * 	 Variavel que especifica o comprimento da mesa
 *@param l
 * 	 Variavel que especifica a largura da mesa
  *@param a
 * 	 Variavel que especifica a altura da mesa
  *@param e
 * 	 Variavel que especifica a espessura da mesa
 *@param f
 * 	 Variavel que especifica as fatias da mesa
 *@param p
 * 	 Variavel que especifica as camadas da mesa
 */
Mesa::Mesa(float c, float l, float a, float e, float f, float p){
	this->comprimento = c;
	this->largura = l;
	this->altura = a;
	this->espessura = e;
	this->fatias = f;
	this->camadas = p;
}


/**
 * Desenha uma mesa standard rectangular ou quadrada com as pernas cilindricas
 * 		
 */
void Mesa::desenhaA(){
	Cubo *base;
	Cilindro *perna[4];

	//Base da Mesa 
	glPushMatrix();
		glTranslatef(0.0f, this->altura, 0.0f);
		base = new Cubo(this->comprimento, this->espessura,this->largura , this->fatias, this->camadas);
		base->desenha();
	glPopMatrix();

	//Perna da Frente Direita
	glPushMatrix();
		glTranslatef(this->comprimento/2 - this->espessura, this->altura / 2, this->largura/2 - this->espessura);
		perna[0] = new Cilindro((2 * this->espessura) / 3, this->altura - this->espessura, this->fatias * 3, this->camadas);
		perna[0]->desenha();
	glPopMatrix();	

	//Perna da Frente Esquerda
	glPushMatrix();
		glTranslatef(-this->comprimento/2 + this->espessura, this->altura/2, this->largura/2 - this->espessura);
		perna[1] = new Cilindro((2 * this->espessura) / 3, this->altura - this->espessura, this->fatias * 3, this->camadas);
		perna[1]->desenha();
	glPopMatrix();	
	
	//Perna de Tras Direita
	glPushMatrix();
		glTranslatef(this->comprimento/2 - this->espessura, this->altura/2, -this->largura/2 + this->espessura);
		perna[2] = new Cilindro((2 * this->espessura) / 3, this->altura - this->espessura, this->fatias * 3, this->camadas);
		perna[2]->desenha();
	glPopMatrix();

	//Perna de Tras Esquerda
	glPushMatrix();
		glTranslatef(-this->comprimento/2 + this->espessura, this->altura/2, -this->largura/2 + this->espessura);
		perna[3] = new Cilindro((2 * this->espessura) / 3, this->altura - this->espessura, this->fatias * 3, this->camadas);
		perna[3]->desenha();
	glPopMatrix();
}

/**
 * Desenha uma mesa cilindrica com as pernas tb cilindricas
 * 		
 */
void Mesa::desenhaB(){
	Cilindro *base;
	Cilindro *perna[4];
	float rotacao = 2 * M_PI / this->fatias;
	float graus = 0;
	//Base da Mesa 
	glPushMatrix();
		glTranslatef(0.0f, this->altura, 0.0f);
		base = new Cilindro(this->comprimento / 2, this->espessura , this->fatias, this->camadas);
		base->desenha();
	glPopMatrix();
	//Pernas, ate 5 fatias, desenha quantas pernas quantas fatias houver, mais que 5, já desenha apenas 4 pernas
	if(this->fatias <= 5.0f){
		for(int i = 0; i < this->fatias; i++) {
			glPushMatrix();
				glTranslatef((this->comprimento / 2 - this->espessura) * cos(graus), this->altura / 2, (this->comprimento / 2 - this->espessura) * sin(graus));
				perna[i] = new Cilindro((2 *this->espessura) / 3, this->altura - this->espessura, this->fatias * 3, this->camadas);
				perna[i]->desenha();
			glPopMatrix();	
			graus = graus + rotacao;
		}
	}
	else{
		for(int i = 0; i < 4; i++) {
			glPushMatrix();
				glTranslatef((this->comprimento / 2-this->espessura) * cos(graus), this->altura / 2, (this->comprimento / 2 - this->espessura) * sin(graus));
				perna[i] = new Cilindro((2 * this->espessura) / 3, this->altura - this->espessura, this->fatias * 3, this->camadas);
				perna[i]->desenha();
			glPopMatrix();	
			graus = graus + M_PI / 2;
		}
	}
}

/**
 * Desenha uma mesa rectangular comprida com tabuas de madeira no fundo
 * 		
 */
void Mesa::desenhaC(){
	Cubo *base;
	Cubo *perna[3];
	Cubo *tabua;

	//Base da Mesa 
	glPushMatrix();
		glTranslatef(0.0f, this->altura, 0.0f);
		base = new Cubo(this->comprimento, this->espessura,this->largura , this->fatias, this->camadas);
		base->desenha();
	glPopMatrix();

	//Perna da direita 
	glPushMatrix();
		glTranslatef(this->comprimento / 2 - (this->comprimento / 10), this->altura / 2, 0.0f);
		perna[0] = new Cubo(this->espessura / 2, this->altura,this->largura - this->largura / 8, this->fatias, this->camadas);
		perna[0]->desenha();
	glPopMatrix();

	//Perna do meio
	glPushMatrix();
		glTranslatef(0.0f, this->altura / 2, 0.0f);
		perna[1] = new Cubo(this->espessura / 2, this->altura,this->largura - this->largura / 8, this->fatias, this->camadas);
		perna[1]->desenha();
	glPopMatrix();

	//Perna da esquerda
	glPushMatrix();
		glTranslatef(-this->comprimento / 2 + (this->comprimento / 10), this->altura / 2, 0.0f);
		perna[2] = new Cubo(this->espessura / 2, this->altura, this->largura - this->largura / 8, this->fatias, this->camadas);
		perna[2]->desenha();
	glPopMatrix();

	//Tabua de baixo
	glPushMatrix();
		glTranslatef(0.0f, this->altura / 10, 0.0f);
		tabua = new Cubo(this->comprimento, this->espessura / 3,this->largura / 10 , this->fatias, this->camadas);
		tabua->desenha();
	glPopMatrix();

}
