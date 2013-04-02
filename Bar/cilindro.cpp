#define _USE_MATH_DEFINES
#include <GL/glut.h>
#include <math.h>
#include "cilindro.h"

/**
 * Construtor da class Cilindro.
 * Inicializa todas as variaveis de instancia.
 *
 */
Cilindro::Cilindro(){
	this->raio = 0.0;
	this->altura = 0.0;
	this->fatias = 18;
	this->camadas = 1;
}

float Cilindro::getAltura(){
	return this->altura;
}

Cilindro::Cilindro(float r, float h){
	this->raio=r;
	this->altura=h;
	this->fatias = 18;			//precisao base do "circlo": quanto mais alta,mais fatias tem as base e o "tronco" 
	this->camadas = 1;			//numero base de camadas do "tronco"
 	
	/*
	this->tx=this->ty=this->tz=0;
	this->alpha_x=0.0;
	this->alpha_y=0.0;
		this->v=10.0;*/
}

/**
 * Construtor da class Cilindro.
 * Inicializa as variaveis de raio do cilindro.
 *@param r
 * 	 Variavel que especifica o raio do cilindro	
 *@param a
 * 	 Variavel que especifica a altura do cilindro
  *@param f
 * 	 Variavel que especifica as fatias do cilindro
  *@param c
 * 	 Variavel que especifica as camadas do cilindro
 */

Cilindro::Cilindro(float r, float a,float f, float c){
	this->raio = r;
	this->altura = a;
	this->fatias = f; 
	this->camadas = c;
}

/**
 * Método que desenha um cilindro com os parametros definido
 * previamente no construtor
 */

void Cilindro::desenha(){
	glBegin(GL_TRIANGLES);
		float rotacao = 2 * M_PI/this->fatias;
		float graus = 0;
		while(graus <= 2 * M_PI){
			//Base Topo
			glVertex3f(0.0f, altura/2, 0.0f);
			glVertex3f(raio * cos(graus + rotacao), altura/2, raio * sin(graus + rotacao));
			glVertex3f(raio * cos(graus), altura/2, raio * sin(graus));
			//Base Baixo
			glVertex3f(0.0f, -altura/2, 0.0f);
			glVertex3f(raio * cos(graus), -altura/2, raio * sin(graus));
			glVertex3f(raio * cos(graus + rotacao), -altura/2, raio * sin(graus + rotacao));
		
			//Lado
			float incA = this->altura/this->camadas;
				float cam = -this->altura/2;
				for(int i = 0; i < this->camadas; i++) {
					glVertex3f(raio * cos(graus), cam, raio * sin(graus)); 
					glVertex3f(raio * cos(graus), cam + incA, raio * sin(graus));
					glVertex3f(raio * cos(graus + rotacao), cam + incA, raio * sin(graus + rotacao));
				
					glVertex3f(raio * cos(graus), cam , raio * sin(graus)); 				
					glVertex3f(raio * cos(graus + rotacao), cam +incA, raio * sin(graus + rotacao));
					glVertex3f(raio * cos(graus + rotacao), cam, raio * sin(graus + rotacao));
					cam = cam + incA;		//Incrementa a altura, para fazer as outras camadas;
			}
			graus = graus + rotacao;
		}

	glEnd();
}


/**
 * Método que desenha metade de um cilindro com o raio 
 * previamente definido no construtor
 */
void Cilindro:: meioCilindro(){
	glBegin(GL_TRIANGLES);
		float rotacao = M_PI/this->fatias;
		float graus = 0;
		while(graus <= M_PI){
			//Base Topo
			glVertex3f(0.0f, altura/2, 0.0f);
			glVertex3f(raio * cos(graus + rotacao), altura/2, raio * sin(graus + rotacao));
			glVertex3f(raio * cos(graus), altura/2, raio * sin(graus));
			//Base Baixo
			glVertex3f(0.0f, -altura/2, 0.0f);
			glVertex3f(raio * cos(graus), -altura/2, raio * sin(graus));
			glVertex3f(raio * cos(graus + rotacao), -altura/2, raio * sin(graus + rotacao));
		
			//Lado
			float incA = this->altura/this->camadas;
				float cam = -this->altura/2;
				for(int i = 0; i < this->camadas; i++) {
					glVertex3f(raio * cos(graus), cam, raio * sin(graus)); 
					glVertex3f(raio * cos(graus), cam + incA, raio * sin(graus));
					glVertex3f(raio * cos(graus + rotacao), cam + incA, raio * sin(graus + rotacao));
				
					glVertex3f(raio * cos(graus), cam , raio * sin(graus)); 				
					glVertex3f(raio * cos(graus + rotacao), cam +incA, raio * sin(graus + rotacao));
					glVertex3f(raio * cos(graus + rotacao), cam, raio * sin(graus + rotacao));
					cam = cam + incA;		//Incrementa a altura, para fazer as outras camadas;
			}
			graus = graus + rotacao;
		}

	glEnd();
}