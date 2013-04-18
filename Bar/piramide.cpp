#define _USE_MATH_DEFINES
#include <GL/glut.h>
#include <math.h>
#include "piramide.h"

/**
 * Construtor da class Piramide.
 * Inicializa todas as variaveis de instancia.
 *
 */
Piramide::Piramide(){
	this->comprimento = 0.0f;
	this->altura = 0.0f;
	this->largura = 0.0f;
	this->fatias = 0.0f;
	this->camadas = 0.0f;
}

/**
 * Construtor da class Piramide.
 * Inicializa as variaveis de raio ou comprimento, altura, largura, fatias e camadas do piramide.
 *@param c
 * 	 Variavel que especifica o comprimento ou raio da piramide	
 *@param a
 * 	 Variavel que especifica a altura da piramide
  *@param l
 * 	 Variavel que especifica o comprimento da piramide
  *@param f
 * 	 Variavel que especifica as fatias da piramide
  *@param c
 * 	 Variavel que especifica as camadas da piramide
 */

Piramide::Piramide(float c, float a,float l, float f, float p){
	this->comprimento = c;
	this->altura = a;
	this->largura = l;
	this->fatias = f; 
	this->camadas = p;
}


/**
 * Desenha uma piramide com base rectangular, com as dimensoes definidas no construtor
 *		
 */

void Piramide::desenhaR(){
	//Variaveis Iniciais para comecar a desenhar 
	float alt = -this->altura/2;
	
	//Incrementos dependendo das fatias ou camadas
	//Variaveis para a Face de Cima, Baixo, Frente e Tras
	float incrementoX = this->comprimento/this->fatias;
	float incrementoX2 = (this->comprimento - this->comprimento/this->camadas) / this->fatias;
	float incrementoY = this->altura/this->camadas;
	float comp = -this->comprimento/2;
	float comp2 = -this->comprimento/2 + (this->comprimento/2)/this->camadas;
	float incremento = -this->comprimento/2 + (this->comprimento/2)/this->camadas;
	//Primeiro Ciclo para as fatias, Segundo para as Camadas
	for(int j = 0; j < this->camadas; j++){
		float comp = -this->comprimento/2;
		float comp2 = -this->comprimento/2 + (this->comprimento/2)/this->camadas;
		for(int i = 0; i < this->fatias; i++){
			glBegin(GL_TRIANGLES);
			//Face Frontal Triangulo
				glVertex3f(comp, alt, largura/2);
				glVertex3f(comp + incrementoX, alt, largura/2);
				glVertex3f(comp2, alt + incrementoY, largura/2);
				/*
				glVertex3f(comp + incrementoX, alt, largura/2);
				glVertex3f(comp2 + incrementoX2, alt + incrementoY, largura/2);
				glVertex3f(comp2, alt + incrementoY, largura/2); 
				*/
			//Face Traseira Triangulo
				glVertex3f(comp, alt, -largura/2);
				glVertex3f(comp, alt + incrementoY, -largura/2);
				glVertex3f(comp + incrementoX, alt + incrementoY, -largura/2);

				glVertex3f(comp, alt, -largura/2);
				glVertex3f(comp + incrementoX, alt + incrementoY, -largura/2);
				glVertex3f(comp + incrementoX, alt , -largura/2);

				comp = comp + incrementoX;
				comp2 = comp + incrementoX2;
			glEnd();
		}
		alt = alt + incrementoY;
	}
}