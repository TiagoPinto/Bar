#include "includes.h"
#include "MesaRedonda.h"
#include "cilindro.h"


/**
 * Construtor da class Mesa.
 * Inicializa as variaveis de comprimento, largura, altura, espessura, fatias e camadas.	
 */
MesaRedonda::MesaRedonda(){
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
MesaRedonda::MesaRedonda(float c, float l, float a, float e, float f, float p, GLuint idMadeira){
	this->comprimento = c;
	this->largura = l;
	this->altura = a;
	this->espessura = e;
	this->fatias = f;
	this->camadas = p;
	this->textura = idMadeira;

	float graus = 0;
	base = new Cilindro(this->comprimento / 2, this->espessura , this->fatias, this->camadas,1, textura);
	for(int i = 0; i < 4; i++) {
		perna[i] = new Cilindro((2 * this->espessura) / 3, this->altura - this->espessura, this->fatias * 3, this->camadas,1, textura);
		graus = graus + M_PI / 2;
	}

	ligacao[0] = new Cilindro(this->espessura / 5, this->comprimento -2 *(3 * this->espessura ) / 2, this->fatias * 3, this->camadas,1, textura);
	ligacao[1] = new Cilindro(this->espessura / 5, this->comprimento -2 *(3 * this->espessura) / 2, this->fatias * 3, this->camadas,1, textura);

}
/**
 * Desenha uma mesa cilindrica com as pernas tb cilindricas
 * 		
 */

void MesaRedonda::desenhaB(){
	float graus = 0;

	//Base da Mesa 
	glPushMatrix();
		glTranslatef(0.0f, this->altura-this->espessura/2, 0.0f);
		base->desenha();
	glPopMatrix();

	for(int i = 0; i < 4; i++) {
		glPushMatrix();
		glTranslatef((this->comprimento / 2-this->espessura) * cos(graus), this->altura / 2-this->espessura/2, (this->comprimento / 2 - this->espessura) * sin(graus));			
			perna[i]->desenha();
		glPopMatrix();	
		graus = graus + M_PI / 2;
	}
		glPushMatrix();
			glTranslatef(0.0f, this->altura / 4, 0.0f);
			glRotatef(90.0f, 1.0f,0.0f,0.0f);
			ligacao[0]->desenha();

			glRotatef(90.0f, 0.0f,0.0f,1.0f);
			ligacao[1]->desenha();
		glPopMatrix();

}

MesaRedonda::~MesaRedonda(){
	glDeleteBuffers(1,&vbo);
	delete base;
	delete perna[0];
	delete perna[1];
	delete perna[2];
	delete perna[3];
	delete ligacao[0];
	delete ligacao[1];
}	