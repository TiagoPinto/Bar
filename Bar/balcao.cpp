#include "includes.h"
#include "balcao.h"
#include "cubo.h"
#include "Anel.h"
#include "CadeiraBanco.h"
#include "copo.h"

Balcao::Balcao(float comp, float larg, float alt, float f, float p, GLuint idtex, GLuint idvidro, GLuint idferro){
	this->comprimento = comp;
	this->largura = larg;
	this->altura = alt;
	this->fatias = f;
	this->camadas = p;
	this->textura = idtex;
	this->texVidro = idvidro;
	this->texFerro = idferro;

	balcao = new Cubo(comprimento, altura, largura, fatias, camadas, textura);
	anel = new Anel(largura, comprimento, altura*0.2, fatias*5, camadas, 2, textura);
	banco = new CadeiraBanco(0.1, 0.1, 2*altura/3, 0.02, fatias, camadas, textura);
	copo[0] = new Copo(0.03, 0.06, 0.001, fatias, camadas, 1, texVidro);
	copo[1] = new Copo(0.05,0.1,0.01,fatias,camadas,2, texFerro);
}


void Balcao::desenha(){

	glPushMatrix();
	glTranslatef(largura+comprimento/2,altura/2-altura*0.1,largura/2);
	glRotatef(-90,0,1,0);
	anel->desenha();
	glPopMatrix();

	glPushMatrix();
	balcao->desenha();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-comprimento, -altura/2, -largura/2+0.3);
	banco->desenhaB();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-comprimento, -altura/2, -largura/2+0.7);
	banco->desenhaB();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-comprimento, -altura/2, -largura/2+1.1);
	banco->desenhaB();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-comprimento, -altura/2, -largura/2+2);
	banco->desenhaB();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-comprimento+1, -altura/2+0.14, -largura/2+3.0);
	glRotatef(90,1,0,0);
	glRotatef(90,0,0,1);
	banco->desenhaB();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-comprimento/2+0.07, altura/2+0.03, -largura/2+0.3);
	copo[0]->desenha();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-comprimento/2+0.07, altura/2+0.03, -largura/2+1);
	copo[0]->desenha();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-comprimento/2+0.07, altura/2+0.03, -largura/2+1.6);
	copo[0]->desenha();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-comprimento/2+0.1, altura/2+0.05, -largura/2+1.3);
	copo[1]->desenha();
	glPopMatrix();
}

/**
 * Destrutor da class Anel.
 * Destroi o VBO criado, para nao ficar alocada memoria na placa grafica	
 */
Balcao::~Balcao(){
	glDeleteBuffers(1,&vbo);
	delete balcao;
	delete anel;
	delete banco;
	delete copo[0];
	delete copo[1];
	delete copo[2];
}