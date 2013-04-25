#define _USE_MATH_DEFINES
#include <GL/glut.h>
#include <math.h>
#include "candeeiro.h"
#include "cilindro.h"
#include "esfera.h"
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
Candeeiro::Candeeiro(){
	this->comprimento = 0.0f;
	this->altura = 0.0f;
	this->fatias = 0.0f;
	this->camadas = 0.0f;
}

Candeeiro::Candeeiro(float c, float a, float f, float p){
	this->comprimento = c;
	this->altura = a;
	this->fatias = f;
	this->camadas = p;
}
/**
 * Método que desenha um cilindro
 *
 */
void Candeeiro::desenhaA(){
	Cubo *base;
	Cubo *segurador[2];
	Plano *caixa[9];
	Cilindro *vela;
	Piramide *topo;

	glPushMatrix();
		glTranslatef(0.0f,-this->altura/2, 0.0f);
		base = new Cubo(this->comprimento, this->altura / 6, this->comprimento, this->fatias, this->camadas);
		base->desenha();
	glPopMatrix();

	//parede da caixa, parte traseira
	glPushMatrix();
		glTranslatef(0.0f,-this->altura /6, -this->comprimento/2);
		caixa[0] = new Plano(this->comprimento, this->altura / 2, this->fatias, this->camadas);
		caixa[0]->desenhaXoY();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0f,-this->altura /6, -this->comprimento/2);
		glRotatef(180,0,1,0);
		caixa[1] = new Plano(this->comprimento, this->altura / 2, this->fatias, this->camadas);
		caixa[1]->desenhaXoY();
	glPopMatrix();

	//parede da caixa, parte frontal
	glPushMatrix();
		glTranslatef(0.0f,-this->altura /6, this->comprimento/2);
		caixa[2] = new Plano(this->comprimento, this->altura / 2, this->fatias, this->camadas);
		caixa[2]->desenhaXoY();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0f,-this->altura /6, this->comprimento/2);
		glRotatef(180,0,1,0);
		caixa[3] = new Plano(this->comprimento, this->altura / 2, this->fatias, this->camadas);
		caixa[3]->desenhaXoY();
	glPopMatrix();

	//parede da caixa, parte lateral direita
	glPushMatrix();
		glTranslatef(this->comprimento/2,-this->altura /6, 0.0f);
		glRotatef(90,0,1,0);
		caixa[4] = new Plano(this->comprimento, this->altura / 2, this->fatias, this->camadas);
		caixa[4]->desenhaXoY();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(this->comprimento/2,-this->altura /6, 0.0f);
		glRotatef(-90,0,1,0);
		caixa[5] = new Plano(this->comprimento, this->altura / 2, this->fatias, this->camadas);
		caixa[5]->desenhaXoY();
	glPopMatrix();

	//parede da caixa, parte lateral esquerda
	glPushMatrix();
		glTranslatef(-this->comprimento/2,-this->altura /6, 0.0f);
		glRotatef(90,0,1,0);
		caixa[6] = new Plano(this->comprimento, this->altura / 2, this->fatias, this->camadas);
		caixa[6]->desenhaXoY();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-this->comprimento/2,-this->altura /6, 0.0f);
		glRotatef(-90,0,1,0);
		caixa[7] = new Plano(this->comprimento, this->altura / 2, this->fatias, this->camadas);
		caixa[7]->desenhaXoY();
	glPopMatrix();

	//piramide no topo
	glPushMatrix();
		glTranslatef(0.0f,this->altura*0.30, 0.0f);
		topo = new Piramide(comprimento, 0.43*altura, comprimento, fatias, camadas);
		topo->desenhaR();
	glPopMatrix();

	//vela
	glPushMatrix();
		glTranslatef(0.0f,-this->altura /4, 0.0f);
		vela = new Cilindro(this->comprimento/5, this->altura/3, this->fatias*2, this->camadas);
		vela->desenha();
	glPopMatrix();

	//Sitio onde segura
	glPushMatrix();
		glTranslatef(0.0f,this->altura/2 + this->altura/16, 0.0f);
		segurador[0] = new Cubo(this->comprimento /20, this->altura / 8, this->comprimento / 20, this->fatias, this->camadas);
		segurador[0]->desenha();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.0f,this->altura/2 + this->altura / 8 + this->comprimento / 20, -this->comprimento/4);
		segurador[0] = new Cubo(this->comprimento /8, this->comprimento / 10, 2 * this->comprimento / 3, this->fatias, this->camadas);
		segurador[0]->desenha();
	glPopMatrix();
}

 void Candeeiro::desenhaB(){
	 Cilindro *segurador;
	 Cilindro *vela;
	 Cubo *ferros;

	 float rotacao = 2 * M_PI/this->fatias;
	 float rotacaoF = (2 * M_PI) / this->fatias;
	 float graus = 0.0f;
	 //float incA = (this->altura -this->espessura)/this->camadas;

	 //ferro segurador
	 glPushMatrix();
		glTranslatef(0.0f,0.0f,0.0f);
		segurador = new Cilindro(comprimento*0.1, altura, fatias*2, camadas*2);
		segurador->desenha();
	 glPopMatrix();

	 /*ferros que seguram os Aneis*/
	 glPushMatrix();
		glTranslatef((comprimento/2-comprimento*0.05)*cos(0.0f),-altura/2+comprimento*0.05,0);
		ferros = new Cubo((comprimento-comprimento*0.3), comprimento*0.05,comprimento*0.05, fatias, camadas);
		ferros->desenha();
	glPopMatrix();

	glPushMatrix();
		glTranslatef((comprimento/4-comprimento*0.05)*cos(0.0f),comprimento*0.05,0);
		ferros = new Cubo((comprimento/2-comprimento*0.3), comprimento*0.05,comprimento*0.05, fatias, camadas);
		ferros->desenha();
	glPopMatrix();

	glPushMatrix();
		glTranslatef((-comprimento/2+comprimento*0.05)*cos(0.0f),-altura/2+comprimento*0.05,0);
		ferros = new Cubo((comprimento-comprimento*0.3), comprimento*0.05,comprimento*0.05, fatias, camadas);
		ferros->desenha();
	glPopMatrix();

	glPushMatrix();
		glTranslatef((-comprimento/4+comprimento*0.05)*cos(0.0f),comprimento*0.05,0);
		ferros = new Cubo((comprimento/2-comprimento*0.3), comprimento*0.05,comprimento*0.05, fatias, camadas);
		ferros->desenha();
	glPopMatrix();


	glPushMatrix();
		glTranslatef(0,-altura/2+comprimento*0.05,(comprimento/2)*sin(90.0f));
		ferros = new Cubo(comprimento*0.05, comprimento*0.05,(comprimento-comprimento*0.3), fatias, camadas);
		ferros->desenha();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0,comprimento*0.05,(comprimento/4-comprimento*0.04)*sin(90.0f));
		ferros = new Cubo(comprimento*0.05, comprimento*0.05,(comprimento/2-comprimento*0.3), fatias, camadas);
		ferros->desenha();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0,-altura/2+comprimento*0.05,(-comprimento/2)*sin(90.0f));
		ferros = new Cubo(comprimento*0.05, comprimento*0.05,(comprimento-comprimento*0.3), fatias, camadas);
		ferros->desenha();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0,comprimento*0.05,(-comprimento/4+comprimento*0.04)*sin(90.0f));
		ferros = new Cubo(comprimento*0.05, comprimento*0.05,(comprimento/2-comprimento*0.3), fatias, camadas);
		ferros->desenha();
	glPopMatrix();


	 while(graus <=2* M_PI){
		 /*ANEL DE BAIXO*/
		 /*velas de cima*/
		 glPushMatrix();
			glTranslatef((comprimento - comprimento*0.1) * cos(3 * graus),-altura/2 +comprimento*0.1+(altura/5)/2,(comprimento-comprimento*0.1) * sin(3 * graus));
			vela = new Cilindro(comprimento*0.05, altura/5, fatias*2, camadas*2);
			vela->desenha();
		glPopMatrix();
		/*velas de baixo*/
		 glPushMatrix();
			glTranslatef((comprimento/2 - comprimento*0.1) * cos(3 * graus),comprimento*0.1+(altura/7)/2,(comprimento/2-comprimento*0.1) * sin(3 * graus));
			vela = new Cilindro(comprimento*0.05, altura/7, fatias*2, camadas*2);
			vela->desenha();
		glPopMatrix();

		//anel a volta
		glBegin(GL_TRIANGLES);
		//parte Superior
			glVertex3f((comprimento -comprimento*0.2)* cos(graus), -altura/2 + comprimento*0.1, (comprimento -comprimento*0.2) * sin(graus));
			glVertex3f(comprimento * cos(graus + rotacaoF), -altura/2 + comprimento*0.1, comprimento * sin(graus + rotacaoF));
			glVertex3f(comprimento * cos(graus), -altura/2 + comprimento*0.1, comprimento * sin(graus));

			glVertex3f((comprimento -comprimento*0.2) * cos(graus), -altura/2 + comprimento*0.1, (comprimento-comprimento*0.2) * sin(graus));
			glVertex3f((comprimento-comprimento*0.2) * cos(graus + rotacaoF), -altura/2+comprimento*0.1, (comprimento-comprimento*0.2) * sin(graus + rotacaoF));
			glVertex3f(comprimento * cos(graus + rotacaoF), -altura/2+comprimento*0.1, comprimento * sin(graus + rotacaoF));

		//parte Inferior
			glVertex3f((comprimento -comprimento*0.2)* cos(graus), -altura/2, (comprimento -comprimento*0.2) * sin(graus));
			glVertex3f(comprimento * cos(graus), -altura/2, comprimento * sin(graus));
			glVertex3f(comprimento * cos(graus + rotacaoF), -altura/2, comprimento * sin(graus + rotacaoF));
			

			glVertex3f((comprimento -comprimento*0.2) * cos(graus), -altura/2, (comprimento-comprimento*0.2) * sin(graus));
			glVertex3f(comprimento * cos(graus + rotacaoF), -altura/2, comprimento * sin(graus + rotacaoF));
			glVertex3f((comprimento-comprimento*0.2) * cos(graus + rotacaoF), -altura/2, (comprimento-comprimento*0.2) * sin(graus + rotacaoF));		

		float incA = (comprimento*0.1)/this->camadas;
		float cam = -this->altura/2;
		for(int i = 0; i < this->camadas; i++) {
			/*Parte exterior do anel*/
			glVertex3f(comprimento * cos(graus), cam, comprimento * sin(graus)); 
			glVertex3f(comprimento * cos(graus), cam + incA, comprimento * sin(graus));
			glVertex3f(comprimento * cos(graus + rotacao), cam + incA, comprimento * sin(graus + rotacao));
			
			glVertex3f(comprimento * cos(graus), cam , comprimento * sin(graus)); 				
			glVertex3f(comprimento * cos(graus + rotacao), cam +incA, comprimento * sin(graus + rotacao));
			glVertex3f(comprimento * cos(graus + rotacao), cam, comprimento * sin(graus + rotacao));
			cam = cam + incA;		//Incrementa a altura, para fazer as outras camadas;
		}
		incA = (comprimento*0.1)/this->camadas;
		cam = -this->altura/2;
		for(int i = 0; i < this->camadas; i++) {
			/*Parte interior do anel*/
			glVertex3f((comprimento-comprimento*0.2) * cos(graus), cam, (comprimento-comprimento*0.2) * sin(graus)); 
			glVertex3f((comprimento-comprimento*0.2) * cos(graus + rotacao), cam + incA, (comprimento-comprimento*0.2) * sin(graus + rotacao));
			glVertex3f((comprimento-comprimento*0.2) * cos(graus), cam + incA, (comprimento-comprimento*0.2) * sin(graus));
			
			glVertex3f((comprimento-comprimento*0.2) * cos(graus), cam , (comprimento-comprimento*0.2) * sin(graus)); 
			glVertex3f((comprimento-comprimento*0.2) * cos(graus + rotacao), cam, (comprimento-comprimento*0.2) * sin(graus + rotacao));
			glVertex3f((comprimento-comprimento*0.2) * cos(graus + rotacao), cam +incA, (comprimento-comprimento*0.2) * sin(graus + rotacao));	
			cam = cam + incA;		//Incrementa a altura, para fazer as outras camadas;
		}


		/*ANEL Superior*/

		//anel a volta
		//parte Superior
			glVertex3f((comprimento/2 -comprimento*0.2)* cos(graus), comprimento*0.1, (comprimento/2 -comprimento*0.2) * sin(graus));
			glVertex3f(comprimento/2 * cos(graus + rotacaoF), comprimento*0.1, comprimento/2 * sin(graus + rotacaoF));
			glVertex3f(comprimento/2 * cos(graus), comprimento*0.1, comprimento/2 * sin(graus));

			glVertex3f((comprimento/2 -comprimento*0.2) * cos(graus), comprimento*0.1, (comprimento/2-comprimento*0.2) * sin(graus));
			glVertex3f((comprimento/2-comprimento*0.2) * cos(graus + rotacaoF), comprimento*0.1, (comprimento/2-comprimento*0.2) * sin(graus + rotacaoF));
			glVertex3f(comprimento/2 * cos(graus + rotacaoF), comprimento*0.1, comprimento/2 * sin(graus + rotacaoF));

		//parte Inferior
			glVertex3f((comprimento/2 -comprimento*0.2)* cos(graus), 0, (comprimento/2 -comprimento*0.2) * sin(graus));
			glVertex3f(comprimento/2 * cos(graus), 0, comprimento/2 * sin(graus));
			glVertex3f(comprimento/2 * cos(graus + rotacaoF), 0, comprimento/2 * sin(graus + rotacaoF));

			glVertex3f((comprimento/2 -comprimento*0.2) * cos(graus), 0, (comprimento/2-comprimento*0.2) * sin(graus));
			glVertex3f(comprimento/2 * cos(graus + rotacaoF), 0, comprimento/2 * sin(graus + rotacaoF));
			glVertex3f((comprimento/2-comprimento*0.2) * cos(graus + rotacaoF), 0, (comprimento/2-comprimento*0.2) * sin(graus + rotacaoF));

		incA = (comprimento*0.1)/this->camadas;
		cam = 0;
		for(int i = 0; i < this->camadas; i++) {
			/*Parte exterior do anel*/
			glVertex3f(comprimento/2 * cos(graus), cam, comprimento/2 * sin(graus)); 
			glVertex3f(comprimento/2 * cos(graus), cam + incA, comprimento/2 * sin(graus));
			glVertex3f(comprimento/2 * cos(graus + rotacao), cam + incA, comprimento/2 * sin(graus + rotacao));
			
			glVertex3f(comprimento/2 * cos(graus), cam , comprimento/2 * sin(graus)); 				
			glVertex3f(comprimento/2 * cos(graus + rotacao), cam +incA, comprimento/2 * sin(graus + rotacao));
			glVertex3f(comprimento/2 * cos(graus + rotacao), cam, comprimento/2 * sin(graus + rotacao));
			cam = cam + incA;		//Incrementa a altura, para fazer as outras camadas;
		}

		incA = (comprimento*0.1)/this->camadas;
		cam = 0;
		for(int i = 0; i < this->camadas; i++) {
			/*Parte exterior do anel*/
			glVertex3f((comprimento/2-comprimento*0.2) * cos(graus), cam, (comprimento/2-comprimento*0.2) * sin(graus));
			glVertex3f((comprimento/2-comprimento*0.2) * cos(graus + rotacao), cam + incA, (comprimento/2-comprimento*0.2) * sin(graus + rotacao));
			glVertex3f((comprimento/2-comprimento*0.2) * cos(graus), cam + incA, (comprimento/2-comprimento*0.2) * sin(graus));
			
			glVertex3f((comprimento/2-comprimento*0.2) * cos(graus), cam , (comprimento/2-comprimento*0.2) * sin(graus)); 
			glVertex3f((comprimento/2-comprimento*0.2) * cos(graus + rotacao), cam, (comprimento/2-comprimento*0.2) * sin(graus + rotacao));
			glVertex3f((comprimento/2-comprimento*0.2) * cos(graus + rotacao), cam +incA, (comprimento/2-comprimento*0.2) * sin(graus + rotacao));
			cam = cam + incA;		//Incrementa a altura, para fazer as outras camadas;
		}

		graus = graus + rotacao;
		glEnd();
	 }
 }