#include "includes.h"
#include "CandeeiroParede.h"
#include "cilindro.h"
#include "cubo.h"
#include "plano.h"
#include "piramide.h"
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
CandeeiroParede::CandeeiroParede(){
	this->comprimento = 0.0f;
	this->altura = 0.0f;
	this->fatias = 0.0f;
	this->camadas = 0.0f;

}

CandeeiroParede::CandeeiroParede(float c, float a, float f, float p, GLuint idtex, GLuint idvidro, GLuint idvela){
	this->comprimento = c;
	this->altura = a;
	this->fatias = f;
	this->camadas = p;
	this->texturaVidro = idvidro;
	this->texturaMadeira = idtex;
	this->texturaVela = idvela;

	base = new Cubo(this->comprimento, this->altura / 6, this->comprimento, this->fatias, this->camadas, texturaMadeira);
	//parede da caixa, parte traseira
		caixa[0] = new Plano(this->comprimento, this->altura / 2, this->fatias, this->camadas,1,texturaVidro);
		caixa[1] = new Plano(this->comprimento, this->altura / 2, this->fatias, this->camadas,1,texturaVidro);
	//parede da caixa, parte frontal
		caixa[2] = new Plano(this->comprimento, this->altura / 2, this->fatias, this->camadas,1,texturaVidro);
		caixa[3] = new Plano(this->comprimento, this->altura / 2, this->fatias, this->camadas,1,texturaVidro);

	//parede da caixa, parte lateral direita
		caixa[4] = new Plano(this->comprimento, this->altura / 2, this->fatias, this->camadas,1,texturaVidro);
		caixa[5] = new Plano(this->comprimento, this->altura / 2, this->fatias, this->camadas,1,texturaVidro);

	//parede da caixa, parte lateral esquerda
		caixa[6] = new Plano(this->comprimento, this->altura / 2, this->fatias, this->camadas,1,texturaVidro);
		caixa[7] = new Plano(this->comprimento, this->altura / 2, this->fatias, this->camadas,1,texturaVidro);
	//piramide no topo
		topo = new Piramide(comprimento, 0.43*altura, comprimento, fatias, camadas, texturaMadeira);

	//vela
		vela = new Cilindro(this->comprimento/5, this->altura/3, this->fatias*2, this->camadas,1, texturaVela);

	//Sitio onde segura
		segurador[0] = new Cubo(this->comprimento /20, this->altura / 8, this->comprimento / 20, this->fatias, this->camadas, texturaMadeira);
		segurador[1] = new Cubo(this->comprimento /8, this->comprimento / 10, 2 * this->comprimento / 3, this->fatias, this->camadas, texturaMadeira);
}
/**
 * Método que desenha um cilindro
 *
 */
void CandeeiroParede::desenhaA(){

	glPushMatrix();
		glTranslatef(0.0f,-this->altura/2, 0.0f);
		base->desenha();
	glPopMatrix();

	//parede da caixa, parte traseira
	glPushMatrix();
		glTranslatef(0.0f,-this->altura /6, -this->comprimento/2);
		caixa[0]->desenha();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.0f,-this->altura /6, -this->comprimento/2);
		glRotatef(180,0,1,0);
		caixa[1]->desenha();
	glPopMatrix();
	
	//parede da caixa, parte frontal
	glPushMatrix();
		glTranslatef(0.0f,-this->altura /6, this->comprimento/2);
		caixa[2]->desenha();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0f,-this->altura /6, this->comprimento/2);
		glRotatef(180,0,1,0);
		caixa[3]->desenha();
	glPopMatrix();

	//parede da caixa, parte lateral direita
	glPushMatrix();
		glTranslatef(this->comprimento/2,-this->altura /6, 0.0f);
		glRotatef(90,0,1,0);
		caixa[4]->desenha();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(this->comprimento/2,-this->altura /6, 0.0f);
		glRotatef(-90,0,1,0);
		caixa[5]->desenha();
	glPopMatrix();

	//parede da caixa, parte lateral esquerda
	glPushMatrix();
		glTranslatef(-this->comprimento/2,-this->altura /6, 0.0f);
		glRotatef(90,0,1,0);
		caixa[6]->desenha();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-this->comprimento/2,-this->altura /6, 0.0f);
		glRotatef(-90,0,1,0);
		caixa[7]->desenha();
	glPopMatrix();

	//piramide no topo
	glPushMatrix();
		glTranslatef(0.0f,this->altura*0.30, 0.0f);
		topo->desenha();
	glPopMatrix();

	//vela
	glPushMatrix();
		glTranslatef(0.0f,-this->altura /4, 0.0f);
		vela->desenha();
	glPopMatrix();

	//Sitio onde segura
	glPushMatrix();
		glTranslatef(0.0f,this->altura/2 + this->altura/16, 0.0f);
		segurador[0]->desenha();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.0f,this->altura/2 + this->altura / 8 + this->comprimento / 20, -this->comprimento/4);
		segurador[1]->desenha();
	glPopMatrix();
}

CandeeiroParede::~CandeeiroParede(){
	glDeleteBuffers(1,&vbo);
	delete base;
	delete segurador[0];
	delete segurador[1];
	delete caixa[0];
	delete caixa[0];
	delete caixa[0];
	delete caixa[0];
	delete caixa[0];
	delete caixa[0];
	delete caixa[0];
	delete caixa[0];
	delete caixa[0];
	delete vela;
	delete topo;
}