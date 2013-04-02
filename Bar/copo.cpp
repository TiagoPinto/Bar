#define _USE_MATH_DEFINES
#include <GL/glut.h>
#include <math.h>
#include "copo.h"


Copo::Copo(){
	this->raio = 0.0f;
	this->altura = 0.0f;
	this->espessura = 0.0f;
	this->fatias = 0.0f;
	this->camadas = 0.0f;
}

Copo::Copo(float r, float a, float e, float f, float p){
	this->raio = r;
	this->altura = a;
	this->espessura = e;
	this->fatias = f;
	this->camadas = p;
}

void Copo::desenhaA(){
	glBegin(GL_TRIANGLES);
	float rotacao = 2 * M_PI/this->fatias;
	float graus = 0;
	float incremento = 2* this->espessura / this->camadas;
	float incA = this->altura/this->camadas;
	float incB = (this->altura - this->espessura) / this->camadas;
	while(graus <= 2 * M_PI){
		//Parte de fora
		//Base Topo
		glVertex3f((raio + 2*espessura) * cos(graus), altura/2, (raio + 2 * espessura) * sin(graus));
		glVertex3f((raio + 3*espessura) * cos(graus + rotacao), altura/2, (raio + 3*espessura) * sin(graus + rotacao));
		glVertex3f((raio + 3*espessura)* cos(graus), altura/2, (raio + 3*espessura) * sin(graus));

		glVertex3f((raio + 2*espessura) * cos(graus), altura/2, (raio + 2 * espessura) * sin(graus));
		glVertex3f((raio + 2*espessura) * cos(graus + rotacao), altura/2, (raio + 2*espessura) * sin(graus + rotacao));
		glVertex3f((raio + 3*espessura)* cos(graus + rotacao), altura/2, (raio + 3*espessura) * sin(graus + rotacao));
			
		//Base Baixo
		glVertex3f(0.0f, -altura/2, 0.0f);
		glVertex3f((raio + espessura) * cos(graus), -altura/2, (raio + espessura) * sin(graus));			
		glVertex3f((raio + espessura) * cos(graus + rotacao), -altura/2, (raio + espessura) * sin(graus + rotacao));
		
		//Parte de fora
		float cam = -this->altura/2;
		float aumento = 0.0f;
		for(int i = 0; i < this->camadas; i++) {
			glVertex3f((raio + espessura + aumento) * cos(graus), cam, (raio + espessura + aumento) * sin(graus)); 
			glVertex3f((raio + espessura + aumento + incremento) * cos(graus), cam + incA, (raio + espessura + aumento + incremento) * sin(graus));					
			glVertex3f((raio + espessura + aumento + incremento) * cos(graus + rotacao), cam + incA, (raio + espessura + aumento + incremento) * sin(graus + rotacao));
			
			glVertex3f((raio + espessura + aumento)* cos(graus), cam , (raio + espessura + aumento) * sin(graus)); 				
			glVertex3f((raio + espessura + aumento + incremento) * cos(graus + rotacao), cam +incA, (raio + espessura + aumento + incremento) * sin(graus + rotacao));				
			glVertex3f((raio + espessura + aumento) * cos(graus + rotacao), cam, (raio + espessura + aumento) * sin(graus + rotacao));
			cam = cam + incA;		//Incrementa a altura, para fazer as outras camadas;
			aumento = aumento + incremento;
		}
		float cami = -this->altura/2 + espessura;
		//Parte Interior
		//Base Baixo
		glVertex3f(0.0f, cami, 0.0f);
		glVertex3f((raio ) * cos(graus + rotacao), cami, (raio ) * sin(graus + rotacao));
		glVertex3f((raio )* cos(graus), cami, (raio) * sin(graus));

		//Parte lateral Interior
		aumento = 0.0f;
		for(int i = 0; i < this->camadas; i++) {
			glVertex3f((raio + aumento) * cos(graus + rotacao), cami, (raio + aumento) * sin(graus + rotacao));
			glVertex3f((raio + aumento + incremento) * cos(graus + rotacao), cami + incB, (raio + aumento + incremento) * sin(graus + rotacao));
			glVertex3f((raio + aumento + incremento) * cos(graus), cami + incB, (raio + aumento + incremento) * sin(graus));				

			glVertex3f((raio + aumento) * cos(graus + rotacao), cami, (raio + aumento) * sin(graus + rotacao));
			glVertex3f((raio + aumento + incremento) * cos(graus), cami +incB, (raio + aumento + incremento) * sin(graus));				
			glVertex3f((raio + aumento)* cos(graus), cami , (raio + aumento) * sin(graus));
			
			cami = cami + incB;		//Incrementa a altura, para fazer as outras camadas;
			aumento = aumento + incremento;		//Incrementa o raio do copo, porque ele vai aumentando de raio, a medida que chega ao topo
		}
		graus = graus + rotacao;
	}
	glEnd();
	
}
