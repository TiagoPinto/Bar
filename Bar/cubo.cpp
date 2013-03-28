#include <GL/glut.h>
#include "cubo.h"


/**
 * Construtor da class Cubo.
 * Inicializa as variaveis de comprimento, altura, largura fatias, e camadas.	
 */
Cubo::Cubo(){
	this->c = 0.0f;
	this->l = 0.0f;
	this->a = 0.0f;
	this->f = 0.0f;
	this->p = 0.0f;
}

/**
 * Construtor da class Cubo.
 * Inicializa as variaveis de comprimento, altura, largura, fatias e camdas de um paralelipipedo.
 *@param c
 * 	 Variavel que especifica o comprimento do paralelipipedo	
 *@param l
 * 	 Variavel que especifica o largura do paralelipipedo	
 *@param a
 * 	 Variavel que especifica o altura do paralelipipedo	
  *@param f
 * 	 Variavel que especifica o numero de fatias do paralelipipedo
  *@param p
 * 	 Variavel que especifica o numero de camadas do paralelipipedo
 *		
 */

Cubo::Cubo(float c,float a,float l, float f, float p){
	this->c = c;
	this->a = a;
	this->l = l;
	this->f = f;
	this->p = p;
}

/**
 * Desenha um cubo, com as dimensoes definidas no construtor
 *		
 */

void Cubo::desenha(){
	//Variaveis Iniciais para comecar a desenhar 
	float alt = -this->a/2;
	float comp = -this->c/2;
	//Incrementos dependendo das fatias ou camadas
	//Variaveis para a Face de Cima, Baixo, Frente e Tras
	float incrementoX = this->c/this->p;
	float incrementoY = this->a/this->f;
	float incrementoZ = this->l/this->p;
	//Variaveis para a Face Lateral Direita e Esquerda
	float incY = this->a/this->f;
	float incZ = this->l/this->p;

	//Primeiro Ciclo para as fatias, Segundo para as Camadas
	for(int j = 0; j < this->f; j++){
		float comp = -this->c/2;
		for(int i = 0; i < this->p; i++){
			glBegin(GL_TRIANGLES);
			//Face Frontal Triangulo
				glVertex3f(comp, alt, l/2);
				glVertex3f(comp + incrementoX, alt + incrementoY, l/2);
				glVertex3f(comp, alt + incrementoY, l/2);

				glVertex3f(comp, alt, l/2);
				glVertex3f(comp + incrementoX, alt, l/2);
				glVertex3f(comp + incrementoX, alt + incrementoY, l/2); 

			//Face Traseira Triangulo
				glVertex3f(comp, alt, -l/2);
				glVertex3f(comp, alt + incrementoY, -l/2);
				glVertex3f(comp + incrementoX, alt + incrementoY, -l/2);

				glVertex3f(comp, alt, -l/2);
				glVertex3f(comp + incrementoX, alt + incrementoY, -l/2);
				glVertex3f(comp + incrementoX, alt , -l/2);

				comp = comp + incrementoX;
			glEnd();
		}
		alt = alt + incrementoY;
	}

	alt = -this->a/2;
	for(int i = 0; i < this->f; i++){
		float larg = -this->l/2;
		for(int i = 0; i < this->p; i++){
			glBegin(GL_TRIANGLES);
			//Face Lateral Direita
				glVertex3f(c/2,alt,larg);
				glVertex3f(c/2,alt + incY, larg);
				glVertex3f(c/2, alt + incY,larg + incZ);

				glVertex3f(c/2, alt, larg);
				glVertex3f(c/2, alt + incY, larg + incZ);
				glVertex3f(c/2, alt, larg + incZ);

			//Face Lateral Esquerda
				glVertex3f(-c/2,alt,larg);
				glVertex3f(-c/2, alt + incY, larg + incZ);
				glVertex3f(-c/2,alt + incY, larg);			

				glVertex3f(-c/2, alt, larg);
				glVertex3f(-c/2, alt, larg + incZ);
				glVertex3f(-c/2, alt + incY, larg + incZ);
				
				larg = larg + incZ;
		glEnd();
		}
		alt = alt + incY;
	}

	incrementoX = this->c/this->f;
	for(int z = 0; z < this->f; z++){
		float larg = -this->l/2;
		for(int x = 0; x < this->p; x++){
			glBegin(GL_TRIANGLES);
			//Face de Cima
				glVertex3f(comp, a/2, larg);
				glVertex3f(comp, a/2, larg + incrementoZ);
				glVertex3f(comp + incrementoX, a/2, larg + incrementoZ);

				glVertex3f(comp, a/2, larg);
				glVertex3f(comp + incrementoX, a/2, larg + incrementoZ);
				glVertex3f(comp + incrementoX, a/2, larg);

			//Face de Baixo
				glVertex3f(comp, -a/2, larg);
				glVertex3f(comp + incrementoX, -a/2, larg + incrementoZ);
				glVertex3f(comp, -a/2, larg + incrementoZ);			

				glVertex3f(comp, -a/2, larg);
				glVertex3f(comp + incrementoX, -a/2, larg);
				glVertex3f(comp + incrementoX, -a/2, larg + incrementoZ);
				larg = larg + incrementoZ;
			glEnd();
		}
		comp = comp + incrementoX;
	}
}