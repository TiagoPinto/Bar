#include <GL/glut.h>
#include <math.h>
#include "plano.h"
/**
 * Construtor da class Plano.
 * Inicializa todas as variaveis de instancia.
 *
 */

Plano::Plano(){
	this->c = 0.0f; 
	this->a = 0.0f;
	this->f = 0.0f;
	this->c = 0.0f;
}
/**
 * Construtor da class Plano.
 * Inicializa todas as variaveis de instancia com os valores passados por parametros.
 * @param c
 * Define o comprimento do plano
 * @param a
 * define a altura do plano
 */

Plano::Plano(float c, float a, float f, float p){
	this->c = c;
	this->a = a;
	this->f = f;
	this->p = p;
}
/**
 * Desenha um plano de comprimento c e altura a no eixo XoY
 * 		
 */
void Plano::desenhaXoY(){

	float larg = -this->a/2;
	float incrementoX = this->c/this->f;
	float incrementoY = this->a/this->p;
	for(int j = 0; j < this->p; j++){
		float comp = -this->c/2;
		for(int i = 0; i < this->f; i++){
			glBegin(GL_TRIANGLES);
				glVertex3f( comp, larg, 0.0f );
				glVertex3f( comp + incrementoX, larg, 0.0f );
				glVertex3f( comp + incrementoX, larg + incrementoY, 0.0f );
		 
				glVertex3f( comp, larg, 0.0f );
				glVertex3f( comp + incrementoX, larg + incrementoY, 0.0f );
				glVertex3f( comp, larg + incrementoY, 0.0f );
				comp = comp + incrementoX;
				
			glEnd();
		}
		larg = larg + incrementoY;
	}
}
/**
 * Desenha um plano de comprimento c e altura a no eixo XoZ
 * 		
 */

void Plano::desenhaXoZ(){

	float alt = -this->a/2;
	float incrementoX = this->c/this->f;
	float incrementoZ = this->a/this->p;
	for(int j = 0; j < this->p; j++){
		float comp = -this->c/2;
		for(int i = 0; i < this->f; i++){
			glBegin(GL_TRIANGLES);
				glVertex3f( comp, 0.0f, alt );
				glVertex3f( comp, 0.0f, alt + incrementoZ );
				glVertex3f( comp + incrementoX, 0.0f, alt + incrementoZ );
				
				
				glVertex3f( comp , 0.0f, alt );
				glVertex3f( comp + incrementoX, 0.0f, alt + incrementoZ );
				glVertex3f( comp + incrementoX, 0.0f, alt );
			glEnd();
			comp = comp + incrementoX;
		}
		alt = alt + incrementoZ;
	}
}
/**
 * Desenha um plano de comprimento c e altura a no eixo YoZ
 * 		
 */

void Plano::desenhaYoZ(){

	float alt = -this->a/2;
	float incrementoY = this->a/this->p;
	float incrementoZ = this->c/this->f;
	for(int j = 0; j < this->f; j++){
		float comp = -this->c/2;
		for(int i = 0; i < this->p; i++){
			glBegin(GL_TRIANGLES);
				glVertex3f( 0.0f, alt, comp );
				glVertex3f( 0.0f, alt + incrementoY, comp);
				glVertex3f( 0.0f, alt + incrementoY, comp + incrementoZ );

				glVertex3f( 0.0f, alt, comp );
				glVertex3f( 0.0f, alt + incrementoY, comp + incrementoZ );
				glVertex3f( 0.0f, alt, comp + incrementoZ );
			glEnd();
			alt = alt + incrementoY;
		}
		comp = comp + incrementoZ;
	}
}