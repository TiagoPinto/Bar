#include "includes.h"
#include "CadeiraRei.h"
#include "cubo.h"
#include "cilindro.h"
#include "esfera.h"

/**
 * Construtor da class Cadeira.
 * Inicializa as variaveis de largura, altura, espessura, fatias e camadas.	
 */
CadeiraRei::CadeiraRei(){
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
CadeiraRei::CadeiraRei(float c, float l, float a, float e, float f, float p, GLuint idtex, GLuint texbola){
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
	costas = new Cubo(this->comprimento, (5.5f * this->altura / 10.0f) - this->espessura /2, this->espessura, this->fatias, this->camadas, textura);
	bracos[0] = new Cubo(this->espessura / 2, this->espessura / 2, this->largura - this->espessura, this->fatias, this->camadas, textura);
	bracos[1] = new Cubo(this->espessura / 2, 2.5f * this->altura / 10.0f - this->espessura / 4 - this->espessura / 2, this->espessura / 2, this->fatias, this->camadas, textura);
	bracos[2] = new Cubo(this->espessura / 2, this->espessura / 2, this->largura - this->espessura, this->fatias, this->camadas, textura);
	bracos[3] = new Cubo(this->espessura / 2, 2.5f * this->altura / 10.0f - this->espessura / 4 - this->espessura / 2, this->espessura / 2, this->fatias, this->camadas, textura);
	ornamento[0] = new Esfera(this->espessura / 2, this->fatias * 4, this->camadas * 3,1,texbola);
	ornamento[1] = new Esfera(this->espessura / 2, this->fatias * 4, this->camadas * 3,1,texbola);
	metade = new Cilindro(this->comprimento / 2 - this->espessura, this->espessura, this->fatias, this->camadas,2,textura);
}

/* Metodo que desenha o esqueleto de uma cadeira em que as pernas base e costas sao desenhadas a partir
  * do construtor Cubo */
void CadeiraRei::desenhaBasePernas(){
	
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

	//Tabua Para as Costas
	glPushMatrix();
		glTranslatef(0.0f, 7.25f * this->altura / 10 + this->espessura / 4, - this->largura / 2 + this->espessura/2);
		costas->desenha();
	glPopMatrix();
}

/*Metodo que desenha a cadeira de um rei, com sitios para pousar os braços, esferas no topo da cadeira, e um meio cilindro */
void CadeiraRei::desenhaD(){

	desenhaBasePernas();

	//Desenho do Braço Direito
	glPushMatrix();
		glTranslatef(this->comprimento/2 - this->espessura / 4, 7.0f * this->altura / 10.0f, this->espessura/2);
		bracos[0]->desenha();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(this->comprimento / 2 - this->espessura / 4, 5.75f * this->altura / 10.0f - this->espessura/8 + this->espessura / 4, this->largura/2 - this->espessura/4);
		bracos[1]->desenha();
	glPopMatrix();

	//Desenho do Braço Esquerdo
	glPushMatrix();
		glTranslatef(-this->comprimento/2 + this->espessura / 4, 7.0f * this->altura / 10.0f, this->espessura/2);
		bracos[2]->desenha();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-this->comprimento / 2 + this->espessura / 4, 5.75f * this->altura / 10.0f - this->espessura/8 + this->espessura / 4, this->largura/2 - this->espessura/4);
		bracos[3]->desenha();
	glPopMatrix();

	//Bolas No Canto Superior da Cadeira
	glPushMatrix();
		glTranslatef(-this->comprimento / 2 + this->espessura / 2, this->altura + this->espessura /2, -this->largura / 2 + this->espessura / 2);
		ornamento[0]->desenha();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(this->comprimento / 2 - this->espessura / 2, this->altura + this->espessura /2, -this->largura / 2 + this->espessura / 2);
		ornamento[1]->desenha();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0f,this->altura,-this->largura / 2 + this->espessura / 2);
		glRotatef(270.0f,1.0f,0.0f,0.0f);
		metade->desenha();
	glPopMatrix();
}

/**
 * Destrutor da class Bar.
 *  * Destroi o VBO criado, para nao ficar alocada memoria na placa grafica	
 */
CadeiraRei::~CadeiraRei(){
	glDeleteBuffers(1,&vbo);
	delete perna[0];
	delete perna[1];
	delete perna[2];
	delete perna[3];
	delete base;
	delete costas;
	delete ornamento[0];
	delete ornamento[1];
	delete metade;
	delete bracos[0];
	delete bracos[1];
	delete bracos[2];
	delete bracos[3];
}	