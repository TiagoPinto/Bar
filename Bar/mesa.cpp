#include "includes.h"
#include "mesa.h"
#include "cubo.h"
#include "cilindro.h"


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
		delete base;
	glPopMatrix();

	//Perna da Frente Direita
	glPushMatrix();
		glTranslatef(this->comprimento/2 - this->espessura, this->altura / 2, this->largura/2 - this->espessura);
		perna[0] = new Cilindro((2 * this->espessura) / 3, this->altura - this->espessura, this->fatias * 3, this->camadas,1);
		perna[0]->desenha();
		delete perna[0];
	glPopMatrix();	

	//Perna da Frente Esquerda
	glPushMatrix();
		glTranslatef(-this->comprimento/2 + this->espessura, this->altura/2, this->largura/2 - this->espessura);
		perna[1] = new Cilindro((2 * this->espessura) / 3, this->altura - this->espessura, this->fatias * 3, this->camadas,1);
		perna[1]->desenha();
		delete perna[1];
	glPopMatrix();	
	
	//Perna de Tras Direita
	glPushMatrix();
		glTranslatef(this->comprimento/2 - this->espessura, this->altura/2, -this->largura/2 + this->espessura);
		perna[2] = new Cilindro((2 * this->espessura) / 3, this->altura - this->espessura, this->fatias * 3, this->camadas,1);
		perna[2]->desenha();
		delete perna[2];
	glPopMatrix();

	//Perna de Tras Esquerda
	glPushMatrix();
		glTranslatef(-this->comprimento/2 + this->espessura, this->altura/2, -this->largura/2 + this->espessura);
		perna[3] = new Cilindro((2 * this->espessura) / 3, this->altura - this->espessura, this->fatias * 3, this->camadas,1);
		perna[3]->desenha();
		delete perna[3];
	glPopMatrix();
}

/**
 * Desenha uma mesa cilindrica com as pernas tb cilindricas
 * 		
 */
void Mesa::desenhaB(){
	Cilindro *base;
	Cilindro *perna[4];
	Cilindro *ligacao[2];
	float graus = 0;

	//Base da Mesa 
	glPushMatrix();
		glTranslatef(0.0f, this->altura, 0.0f);
		base = new Cilindro(this->comprimento / 2, this->espessura , this->fatias, this->camadas,1);
		base->desenha();
		delete base;
	glPopMatrix();

	for(int i = 0; i < 4; i++) {
		glPushMatrix();
		glTranslatef((this->comprimento / 2-this->espessura) * cos(graus), this->altura / 2, (this->comprimento / 2 - this->espessura) * sin(graus));
			perna[i] = new Cilindro((2 * this->espessura) / 3, this->altura - this->espessura, this->fatias * 3, this->camadas,1);
			perna[i]->desenha();
			delete perna[i];
		glPopMatrix();	
		graus = graus + M_PI / 2;
	}
		glPushMatrix();
			glTranslatef(0.0f, this->altura / 4, 0.0f);
			glRotatef(90.0f, 1.0f,0.0f,0.0f);
			ligacao[0] = new Cilindro(this->espessura / 5, this->comprimento -2 *(3 * this->espessura ) / 2, this->fatias * 3, this->camadas,1);
			ligacao[0]->desenha();
			delete ligacao[0];

			glRotatef(90.0f, 0.0f,0.0f,1.0f);
			ligacao[1] = new Cilindro(this->espessura / 5, this->comprimento -2 *(3 * this->espessura) / 2, this->fatias * 3, this->camadas,1);
			ligacao[1]->desenha();
			delete ligacao[1];
		glPopMatrix();

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
		delete base;
	glPopMatrix();

	//Perna da direita 
	glPushMatrix();
		glTranslatef(this->comprimento / 2 - (this->comprimento / 10), this->altura / 2, 0.0f);
		perna[0] = new Cubo(this->espessura / 2, this->altura,this->largura - this->largura / 8, this->fatias, this->camadas);
		perna[0]->desenha();
		delete perna[0];
	glPopMatrix();

	//Perna do meio
	glPushMatrix();
		glTranslatef(0.0f, this->altura / 2, 0.0f);
		perna[1] = new Cubo(this->espessura / 2, this->altura,this->largura - this->largura / 8, this->fatias, this->camadas);
		perna[1]->desenha();
		delete perna[1];
	glPopMatrix();

	//Perna da esquerda
	glPushMatrix();
		glTranslatef(-this->comprimento / 2 + (this->comprimento / 10), this->altura / 2, 0.0f);
		perna[2] = new Cubo(this->espessura / 2, this->altura, this->largura - this->largura / 8, this->fatias, this->camadas);
		perna[2]->desenha();
		delete perna[2];
	glPopMatrix();

	//Tabua de baixo
	glPushMatrix();
		glTranslatef(0.0f, this->altura / 10, 0.0f);
		tabua = new Cubo(this->comprimento, this->espessura / 3,this->largura / 10 , this->fatias, this->camadas);
		tabua->desenha();
		delete tabua;
	glPopMatrix();

}