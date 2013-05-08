#include "includes.h"
#include "cadeira.h"
#include "cubo.h"
#include "cilindro.h"
#include "esfera.h"

/**
 * Construtor da class Cadeira.
 * Inicializa as variaveis de largura, altura, espessura, fatias e camadas.	
 */
Cadeira::Cadeira(){
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
Cadeira::Cadeira(float c, float l, float a, float e, float f, float p){
	this->comprimento = c;
	this->largura = l;
	this->altura = a;
	this->espessura = e;
	this->fatias = f;
	this->camadas = p;
}

/* Metodo que desenha o esqueleto de uma cadeira em que as pernas base e costas sao desenhadas a partir
  * do construtor Cubo */
void Cadeira::desenhaBasePernas(){
	Cubo *base;
	Cubo *perna[4];
	Cubo *costas;

	//Base da Mesa 
	glPushMatrix();
		glTranslatef(0.0f, 4.5f * this->altura / 10.0f, 0.0f);
		base = new Cubo(this->comprimento, this->espessura, this->largura, this->fatias, this->camadas);;
		base->desenha();
		delete base;
	glPopMatrix();

	//Perna da Frente Direita
	glPushMatrix();
		glTranslatef(this->comprimento/2 - this->espessura/2, (2.25f * this->altura) / 10.0f - this->espessura / 4, this->largura/2 - this->espessura/2);
		perna[0] = new Cubo(this->espessura, (4.5f * this->altura / 10.0f) - this->espessura/2 , this->espessura, this->fatias, this->camadas);
		perna[0]->desenha();
		delete perna[0];
	glPopMatrix();	

	//Perna da Frente Esquerda
	glPushMatrix();
		glTranslatef(-this->comprimento/2 + this->espessura/2, (2.25f * this->altura) / 10.0f - this->espessura / 4, this->largura/2 - this->espessura/2);
		perna[1] = new Cubo(this->espessura, (4.5f * this->altura / 10.0f) - this->espessura/2 , this->espessura, this->fatias, this->camadas);
		perna[1]->desenha();
		delete perna[1];
	glPopMatrix();	
	
	//Perna de Tras Direita
	glPushMatrix();
		glTranslatef(this->comprimento/2 - this->espessura/2, (2.25f * this->altura) / 10.0f - this->espessura / 4, -this->largura/2 + this->espessura/2);
		perna[2] = new Cubo(this->espessura, (4.5f * this->altura / 10.0f) - this->espessura/2 , this->espessura, this->fatias, this->camadas);
		perna[2]->desenha();
		delete perna[2];
	glPopMatrix();

	//Perna de Tras Esquerda
	glPushMatrix();
		glTranslatef(-this->comprimento/2 + this->espessura/2, (2.25f * this->altura) / 10.0f - this->espessura / 4, -this->largura/2 + this->espessura/2);
		perna[3] = new Cubo(this->espessura, (4.5f * this->altura / 10.0f) - this->espessura/2 , this->espessura, this->fatias, this->camadas);
		perna[3]->desenha();
		delete perna[3];
	glPopMatrix();

	//Tabua Para as Costas
	glPushMatrix();
		glTranslatef(0.0f, 7.25f * this->altura / 10 + this->espessura / 4, - this->largura / 2 + this->espessura/2);
		costas = new Cubo(this->comprimento, (5.5f * this->altura / 10.0f) - this->espessura /2, this->espessura, this->fatias, this->camadas);
		costas->desenha();
		delete costas;
	glPopMatrix();
}

/*Metodo que desenha uma cadeira standard, em que as pernas estao ligadas perpendicularmente */
void Cadeira::desenhaA(){
	Cubo *tabua[4];

	desenhaBasePernas();
	
	//Tabua que Liga as Pernas da Direita
	glPushMatrix();
		glTranslatef(this->comprimento/2 - this->espessura/2, this->altura / 10.0f, 0.0f);
		tabua[0] = new Cubo(this->espessura, this->espessura / 2, this->largura - 2 * this->espessura, this->fatias, this->camadas);
		tabua[0]->desenha();
		delete tabua[0];
	glPopMatrix();
	
	//Tabua que Liga as Pernas da Esquerda
	glPushMatrix();
		glTranslatef(-this->comprimento/2 + this->espessura/2, this->altura / 10, 0.0f);
		tabua[1] = new Cubo(this->espessura, this->espessura / 2, this->largura - 2* this->espessura, this->fatias, this->camadas);
		tabua[1]->desenha();
		delete tabua[1];
	glPopMatrix();
	
	//Tabua que Liga as Pernas da Frente
	glPushMatrix();
		glTranslatef(0.0f, this->altura / 10, this->largura/2 - this->espessura/2);
		tabua[2] = new Cubo(this->comprimento - 2 * this->espessura, this->espessura/2, this->espessura, this->fatias, this->camadas);
		tabua[2]->desenha();
		delete tabua[2];
	glPopMatrix();

	//Tabua que Liga as Pernas de Tras
	glPushMatrix();
		glTranslatef(0.0f, this->altura / 10, -this->largura/2 + this->espessura/2);
		tabua[3] = new Cubo(this->comprimento - 2 * this->espessura, this->espessura/2, this->espessura, this->fatias, this->camadas);
		tabua[3]->desenha();
		delete tabua[3];
	glPopMatrix();
}

/* metodo que desenha um Banco */
void Cadeira::desenhaB(){
	Cilindro *base;
	Cilindro *perna[4];
	float graus = 0.0f;
	//Base da Mesa 
	glPushMatrix();
		glTranslatef(0.0f, this->altura, 0.0f);
		base = new Cilindro(this->largura, this->espessura, this->fatias * 3, this->camadas * 2,1);
		base->desenha();
		delete base;
	glPopMatrix();
	//Pernas
	for(int i = 0; i < 4; i++) {
		glPushMatrix();
			glTranslatef((this->largura - this->espessura) * cos(graus), this->altura / 2, (this->largura - this->espessura) * sin(graus));
			perna[i] = new Cilindro(this->espessura / 2, this->altura - this->espessura, this->fatias * 3, this->camadas,1);
			perna[i]->desenha();
			delete perna[i];
		glPopMatrix();	
		graus = graus + M_PI / 2;
	}
}

/* Metodo que desenha um banco comprido com uma tabua a ligar as pernas pelo meio  */
void Cadeira::desenhaC(){
	Cubo *base;
	Cubo *perna[4];
	Cubo *tabua[3];
	
	desenhaBasePernas();
	//Tabua que Liga as Pernas da Direita
	glPushMatrix();
		glTranslatef(this->comprimento/2 - this->espessura/2, this->altura / 10, 0.0f);
		tabua[0] = new Cubo(this->espessura, this->espessura / 2, this->largura - 2 * this->espessura, this->fatias, this->camadas);
		tabua[0]->desenha();
		delete tabua[0];
	glPopMatrix();

	//Tabua que Liga as Pernas da Esquerda
	glPushMatrix();
		glTranslatef(-this->comprimento/2 + this->espessura/2, this->altura / 10, 0.0f);
		tabua[1] = new Cubo(this->espessura, this->espessura / 2, this->largura - 2 * this->espessura, this->fatias, this->camadas);
		tabua[1]->desenha();
		delete tabua[1];
	glPopMatrix();

	//Tabua Central
	glPushMatrix();
		glTranslatef(0.0f, this->altura / 10, 0.0f);
		tabua[2] = new Cubo(this->comprimento - 2 * this->espessura, this->espessura / 2, this->espessura, this->fatias, this->camadas);
		tabua[2]->desenha();
		delete tabua[2];
	glPopMatrix();
}

/*Metodo que desenha a cadeira de um rei, com sitios para pousar os braços, esferas no topo da cadeira, e um meio cilindro */
void Cadeira::desenhaD(){
	Esfera *ornamento[2];
	Cubo *bracos[4];
	Cilindro *metade;

	desenhaBasePernas();

	//Desenho do Braço Direito
	glPushMatrix();
		glTranslatef(this->comprimento/2 - this->espessura / 4, 7.0f * this->altura / 10.0f, this->espessura/2);
		bracos[0] = new Cubo(this->espessura / 2, this->espessura / 2, this->largura - this->espessura, this->fatias, this->camadas);
		bracos[0]->desenha();
		delete bracos[0];
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(this->comprimento / 2 - this->espessura / 4, 5.75f * this->altura / 10.0f - this->espessura/8 + this->espessura / 4, this->largura/2 - this->espessura/4);
		bracos[1] = new Cubo(this->espessura / 2, 2.5f * this->altura / 10.0f - this->espessura / 4 - this->espessura / 2, this->espessura / 2, this->fatias, this->camadas);
		bracos[1]->desenha();
		delete bracos[1];
	glPopMatrix();

	//Desenho do Braço Esquerdo
	glPushMatrix();
		glTranslatef(-this->comprimento/2 + this->espessura / 4, 7.0f * this->altura / 10.0f, this->espessura/2);
		bracos[2] = new Cubo(this->espessura / 2, this->espessura / 2, this->largura - this->espessura, this->fatias, this->camadas);
		bracos[2]->desenha();
		delete bracos[2];
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-this->comprimento / 2 + this->espessura / 4, 5.75f * this->altura / 10.0f - this->espessura/8 + this->espessura / 4, this->largura/2 - this->espessura/4);
		bracos[3] = new Cubo(this->espessura / 2, 2.5f * this->altura / 10.0f - this->espessura / 4 - this->espessura / 2, this->espessura / 2, this->fatias, this->camadas);
		bracos[3]->desenha();
		delete bracos[3];
	glPopMatrix();

	//Bolas No Canto Superior da Cadeira
	glPushMatrix();
		glTranslatef(-this->comprimento / 2 + this->espessura / 2, this->altura + this->espessura /2, -this->largura / 2 + this->espessura / 2);
		ornamento[0] = new Esfera(this->espessura / 2, this->fatias * 4, this->camadas * 3,1);
		ornamento[0]->desenha();
		delete ornamento[0];
	glPopMatrix();

	glPushMatrix();
		glTranslatef(this->comprimento / 2 - this->espessura / 2, this->altura + this->espessura /2, -this->largura / 2 + this->espessura / 2);
		ornamento[1] = new Esfera(this->espessura / 2, this->fatias * 4, this->camadas * 3,1);
		ornamento[1]->desenha();
		delete ornamento[1];
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0f,this->altura,-this->largura / 2 + this->espessura / 2);
		glRotatef(270.0f,1.0f,0.0f,0.0f);
		metade = new Cilindro(this->comprimento / 2 - this->espessura, this->espessura, this->fatias, this->camadas,2);
		metade->desenha();
		delete metade;
	glPopMatrix();
}