#include "includes.h"
#include "MesaRectangular.h"
#include "cubo.h"


/**
 * Construtor da class Mesa.
 * Inicializa as variaveis de comprimento, largura, altura, espessura, fatias e camadas.	
 */
MesaRectangular::MesaRectangular(){
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
MesaRectangular::MesaRectangular(float c, float l, float a, float e, float f, float p, GLuint idMadeira){
	this->comprimento = c;
	this->largura = l;
	this->altura = a;
	this->espessura = e;
	this->fatias = f;
	this->camadas = p;
	this->textura = idMadeira;

	//Base da Mesa 
		base = new Cubo(this->comprimento, this->espessura,this->largura , this->fatias, this->camadas, textura);
	//Perna da direita 
		perna[0] = new Cubo(this->espessura / 2, this->altura,this->largura - this->largura / 8, this->fatias, this->camadas, textura );
	//Perna do meio
		perna[1] = new Cubo(this->espessura / 2, this->altura,this->largura - this->largura / 8, this->fatias, this->camadas,textura );
	//Perna da esquerda
		perna[2] = new Cubo(this->espessura / 2, this->altura, this->largura - this->largura / 8, this->fatias, this->camadas, textura );
	//Tabua de baixo
		tabua = new Cubo(this->comprimento, this->espessura / 3,this->largura / 10 , this->fatias, this->camadas, textura );


}

/**
 * Desenha uma mesa rectangular comprida com tabuas de madeira no fundo
 * 		
 */
void MesaRectangular::desenhaC(){

	//Base da Mesa 
	glPushMatrix();
	glTranslatef(0.0f, this->altura-this->espessura/2, 0.0f);
		base->desenha();
	glPopMatrix();

	//Perna da direita 
	glPushMatrix();
		glTranslatef(this->comprimento / 2 - (this->comprimento / 10), this->altura / 2, 0.0f);
		perna[0]->desenha();
	glPopMatrix();

	//Perna do meio
	glPushMatrix();
		glTranslatef(0.0f, this->altura / 2, 0.0f);
		perna[1]->desenha();
	glPopMatrix();

	//Perna da esquerda
	glPushMatrix();
		glTranslatef(-this->comprimento / 2 + (this->comprimento / 10), this->altura / 2, 0.0f);
		perna[2]->desenha();
	glPopMatrix();

	//Tabua de baixo
	glPushMatrix();
		glTranslatef(0.0f, this->altura / 10, 0.0f);
		tabua->desenha();
	glPopMatrix();

}

MesaRectangular::~MesaRectangular(){
	glDeleteBuffers(1,&vbo);
	delete base;
	delete perna[0];
	delete perna[1];
	delete perna[2];
	delete perna[3];
	delete tabua;
}	