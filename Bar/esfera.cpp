#define _USE_MATH_DEFINES
#include <GL/glut.h>
#include <math.h>
#include "esfera.h"

/**
 * Construtor da class Esfera.
 * Inicializa as variaveis de raios, fatias e camadas.	
 */
Esfera:: Esfera(){
	this->raio = 0.0f;
	this->fatias = 0.0f;
	this->camadas = 0.0f;
}

/**
 * Construtor da class Esfera.
 * Inicializa as variaveis de raio, fatias e camadas de uma esfera.
 *@param r
 * 	 Variavel que especifica o raio da esfera	
 *@param f
 * 	 Variavel que especifica as fatias da esfera	
 *@param c
 * 	 Variavel que especifica as camadas da esfera
 *		
 */
Esfera:: Esfera(float r, float f, float c){
	this->raio = r;
	this->fatias = f;
	this->camadas = c;
}

/**
 * Desenha uma esfera, com as dimensoes definidas no construtor
 *		
 */
void Esfera:: desenha(){
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	float rotacaoR = 2 * M_PI / this->fatias;
	float rotacaoC = M_PI / this->camadas;
	float grausC = 0;
	for(int k = 0; k < this->camadas; k++){
		float grausR = 0;
		for(int i = 0; i < this->fatias; i++) {
			glBegin(GL_TRIANGLES);
			//Parte Superior da Esfera
			glVertex3f(raio * cos(grausR) * sin(grausC), raio * cos(grausC), raio * sin(grausR) * sin(grausC)); 
			glVertex3f(raio * cos(grausR) * sin(grausC + rotacaoC), raio * cos(grausC + rotacaoC), raio * sin(grausR) * sin(grausC + rotacaoC));
			glVertex3f(raio * cos(grausR + rotacaoR) * sin(grausC + rotacaoC), raio * cos(grausC + rotacaoC), raio * sin(grausR + rotacaoR) * sin(grausC + rotacaoC));

			glVertex3f(raio * cos(grausR) * sin(grausC), raio * cos(grausC), raio * sin(grausR) * sin(grausC)); 				
			glVertex3f(raio * cos(grausR + rotacaoR) * sin(grausC + rotacaoC), raio * cos(grausC + rotacaoC), raio * sin(grausR + rotacaoR) * sin(grausC + rotacaoC));
			glVertex3f(raio * cos(grausR + rotacaoR) * sin(grausC), raio * cos(grausC), raio * sin(grausR + rotacaoR) * sin(grausC));
			glEnd();		
		grausR = grausR + rotacaoR;	
		}
		grausC = grausC + rotacaoC;
	}
	
}






