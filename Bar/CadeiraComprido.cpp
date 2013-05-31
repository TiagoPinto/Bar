#include "includes.h"
#include "cadeiraComprido.h"
#include "cubo.h"
#include "cilindro.h"
#include "esfera.h"

/**
 * Construtor da class Cadeira.
 * Inicializa as variaveis de largura, altura, espessura, fatias e camadas.	
 */
CadeiraComprido::CadeiraComprido(){
	this->comprimento = 0.0f;
	this->largura = 0.0f;
	this->altura = 0.0f;
	this->espessura = 0.0f;
	this->fatias = 0.0f;
	this->camadas = 0.0f;
}

/**
 * Construtor da class Cadeira.
  *@param c
 * 	 Variavel que especifica a comprimento da cadeira
 *@param l
 * 	 Variavel que especifica a largura da cadeira
  *@param a
 * 	 Variavel que especifica a altura da cadeira
  *@param e
 * 	 Variavel que especifica a espessura da cadeira
 *@param f
 * 	 Variavel que especifica as fatias da cadeira
 *@param p
 * 	 Variavel que especifica as camadas da cadeira
 */
CadeiraComprido::CadeiraComprido(float c, float l, float a, float e, float f, float p, GLuint idtex){
	this->comprimento = c;
	this->largura = l;
	this->altura = a;
	this->espessura = e;
	this->fatias = f;
	this->camadas = p;
	this->textura = idtex;

		base = new Cubo(this->comprimento, this->espessura, this->largura, this->fatias, this->camadas, textura);;
		perna[0] = new Cubo(this->espessura, (4.5f * this->altura / 10.0f) - this->espessura/2 , this->espessura, this->fatias, this->camadas, textura);
		perna[1] = new Cubo(this->espessura, (4.5f * this->altura / 10.0f) - this->espessura/2 , this->espessura, this->fatias, this->camadas, textura);
		perna[2] = new Cubo(this->espessura, (4.5f * this->altura / 10.0f) - this->espessura/2 , this->espessura, this->fatias, this->camadas, textura);
		perna[3] = new Cubo(this->espessura, (4.5f * this->altura / 10.0f) - this->espessura/2 , this->espessura, this->fatias, this->camadas, textura);
		tabua[0] = new Cubo(this->espessura, this->espessura / 2, this->largura - 2 * this->espessura, this->fatias, this->camadas, textura);
		tabua[1] = new Cubo(this->espessura, this->espessura / 2, this->largura - 2 * this->espessura, this->fatias, this->camadas, textura);
		tabua[2] = new Cubo(this->comprimento - 2 * this->espessura, this->espessura / 2, this->espessura, this->fatias, this->camadas, textura);
}

/* Metodo que desenha o esqueleto de uma cadeira em que as pernas base e costas sao desenhadas a partir
  * do construtor Cubo */
void CadeiraComprido::desenhaBasePernas(){
	//Base da Mesa 
	glPushMatrix();
		glTranslatef(0.0f, 4.5f * this->altura / 10.0f, 0.0f);
		base->desenha();
	glPopMatrix();

	//Perna da Frente Direita
	glPushMatrix();
		glTranslatef(this->comprimento/2 - this->espessura/2, (2.25f * this->altura) / 10.0f - this->espessura / 4, this->largura/2 - this->espessura/2);
		perna[0]->desenha();
	glPopMatrix();	

	//Perna da Frente Esquerda
	glPushMatrix();
		glTranslatef(-this->comprimento/2 + this->espessura/2, (2.25f * this->altura) / 10.0f - this->espessura / 4, this->largura/2 - this->espessura/2);
		perna[1]->desenha();
	glPopMatrix();	
	
	//Perna de Tras Direita
	glPushMatrix();
		glTranslatef(this->comprimento/2 - this->espessura/2, (2.25f * this->altura) / 10.0f - this->espessura / 4, -this->largura/2 + this->espessura/2);
		perna[2]->desenha();
	glPopMatrix();

	//Perna de Tras Esquerda
	glPushMatrix();
		glTranslatef(-this->comprimento/2 + this->espessura/2, (2.25f * this->altura) / 10.0f - this->espessura / 4, -this->largura/2 + this->espessura/2);
		perna[3]->desenha();
	glPopMatrix();
}

/* Metodo que desenha um banco comprido com uma tabua a ligar as pernas pelo meio  */
void CadeiraComprido::desenhaC(){
	
	desenhaBasePernas();
	//Tabua que Liga as Pernas da Direita
	glPushMatrix();
		glTranslatef(this->comprimento/2 - this->espessura/2, this->altura / 10, 0.0f);
		tabua[0]->desenha();
	glPopMatrix();

	//Tabua que Liga as Pernas da Esquerda
	glPushMatrix();
		glTranslatef(-this->comprimento/2 + this->espessura/2, this->altura / 10, 0.0f);
		tabua[1]->desenha();
	glPopMatrix();

	//Tabua Central
	glPushMatrix();
		glTranslatef(0.0f, this->altura / 10, 0.0f);
		tabua[2]->desenha();
	glPopMatrix();
}

/**
 * Destrutor da class Bar.
 *  * Destroi o VBO criado, para nao ficar alocada memoria na placa grafica	
 */
CadeiraComprido::~CadeiraComprido(){
	glDeleteBuffers(1,&vbo);
	delete perna[0];
	delete perna[1];
	delete perna[2];
	delete perna[3];
	delete base;
	delete tabua[0];
	delete tabua[1];
	delete tabua[2];
}	