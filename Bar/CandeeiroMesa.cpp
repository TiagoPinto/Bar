#include "includes.h"
#include "CandeeiroMesa.h"
#include "cilindro.h"
#include "Luz.h"
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
CandeeiroMesa::CandeeiroMesa(){
	this->comprimento = 0.0f;
	this->altura = 0.0f;
	this->fatias = 0.0f;
	this->camadas = 0.0f;

}

CandeeiroMesa::CandeeiroMesa(float c, float a, float f, float p, GLuint idferro, GLuint idvela){
	this->comprimento = c;
	this->altura = a;
	this->fatias = f;
	this->camadas = p;
	this->texturaFerro = idferro;
	this->texturaVela = idvela;
	this->luz = new Luz(0,this->altura,0);

	base = new Cilindro(comprimento/2, 0.5*altura/5, fatias, camadas, 1, texturaFerro);
	//parede da caixa, parte traseira
		segurador[0] = new Cilindro(comprimento/10, 2.5*altura/5, fatias, camadas, 1, texturaFerro);
		segurador[1] = new Cilindro(3*comprimento/10,(0.5*altura)/5, fatias, camadas, 1, texturaFerro);
	
	//vela
		vela = new Cilindro(2*comprimento/10, 1.5*altura/5, fatias, camadas,1, texturaVela);
}
/**
 * Método que desenha um cilindro
 *
 */
void CandeeiroMesa::desenha(){

	glPushMatrix();
		glTranslatef(0.0f,-this->altura/2, 0.0f);
		base->desenha();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f,-altura/2 + (0.5*altura/5)/2+(2.5*altura/5)/2, 0.0f);
	segurador[0]->desenha();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f,-altura/2 + (0.5*altura/5)/2+(2.5*altura/5)/2+(2.5*altura/5)/2, 0.0f);
	segurador[1]->desenha();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f,-altura/2 + (0.5*altura/5)/2+(2.5*altura/5)/2+(2.5*altura/5)/2+(1.5*altura/5)/2, 0.0f);
	vela->desenha();
	glPopMatrix();
}

CandeeiroMesa::~CandeeiroMesa(){
	glDeleteBuffers(1,&vbo);
	delete base;
	delete segurador[0];
	delete segurador[1];
	delete vela;

}