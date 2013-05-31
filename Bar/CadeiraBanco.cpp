#include "includes.h"
#include "CadeiraBanco.h"
#include "cubo.h"
#include "cilindro.h"

/**
 * Construtor da class Cadeira.
 * Inicializa as variaveis de largura, altura, espessura, fatias e camadas.	
 */
CadeiraBanco::CadeiraBanco(){
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
CadeiraBanco::CadeiraBanco(float c, float l, float a, float e, float f, float p, GLuint idtex){
	this->comprimento = c;
	this->largura = l;
	this->altura = a;
	this->espessura = e;
	this->fatias = f;
	this->camadas = p;
	this->textura = idtex;

	base = new Cilindro(this->largura, this->espessura, this->fatias * 3, this->camadas * 2,1,textura);
	//Pernas
	for(int i = 0; i < 4; i++) {
			perna[i] = new Cilindro(this->espessura / 2, this->altura - this->espessura, this->fatias * 3, this->camadas,1,textura);
	}

}

/* metodo que desenha um Banco */
void CadeiraBanco::desenhaB(){
	float graus = 0.0f;
	//Base da Mesa 
	glPushMatrix();
		glTranslatef(0.0f, this->altura, 0.0f);
		base->desenha();
	glPopMatrix();
	//Pernas
	for(int i = 0; i < 4; i++) {
		glPushMatrix();
			glTranslatef((this->largura - this->espessura) * cos(graus), this->altura / 2, (this->largura - this->espessura) * sin(graus));
			perna[i]->desenha();
		glPopMatrix();	
		graus = graus + M_PI / 2;
	}
}

/**
 * Destrutor da class Bar.
 *  * Destroi o VBO criado, para nao ficar alocada memoria na placa grafica	
 */
CadeiraBanco::~CadeiraBanco(){
	glDeleteBuffers(1,&vbo);
	delete base;
	for(int i = 0; i < 4; i++) {
		delete perna[i];
	}
}	