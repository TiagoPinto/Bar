#define _USE_MATH_DEFINES
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "copo.h"
#include "esfera.h"
#include "torus.h"

/**
 * Construtor da class Copo.
 * Inicializa todas as variaveis de instancia.
 *
 */
Copo::Copo(){
	this->raio = 0.0f;
	this->altura = 0.0f;
	this->espessura = 0.0f;
	this->fatias = 0.0f;
	this->camadas = 0.0f;
}

/**
 * Construtor da class Copo.
 * 
 *@param r
 * 	 Variavel que especifica o raio do copo	
 *@param a
 * 	 Variavel que especifica a altura do copo
  *@param e
 * 	 Variavel que especifica a espessura do copo
  *@param f
 * 	 Variavel que especifica as fatias do copo
  *@param p
 *	 Variavel que especifica as fatias do copo
 */
Copo::Copo(float r, float a, float e, float f, float p){
	this->raio = r;
	this->altura = a;
	this->espessura = e;
	this->fatias = f;
	this->camadas = p;
}


/* Desenha um copo standard, em que o copo e cilindrico, mas que a base e inferior em raio a altura */
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

/* Metodo que desenha um copo em forma de caneca com as medidas definidas no construtor*/
void Copo:: desenhaB(){
	Torus *pega;

	glBegin(GL_TRIANGLES);
	float rotacaoF = (2 * M_PI) / this->fatias;
	float graus = 0.0f;
	float incA = (this->altura -this->espessura)/this->camadas;
		
	while(graus <= 2 * M_PI){
		//Topo da Caneca
		glVertex3f((raio - espessura) * cos(graus), altura/2, (raio -espessura) * sin(graus));
		glVertex3f(raio * cos(graus + rotacaoF), altura/2, raio * sin(graus + rotacaoF));
		glVertex3f(raio * cos(graus), altura/2, raio * sin(graus));

		glVertex3f((raio - espessura) * cos(graus), altura/2, (raio - espessura) * sin(graus));
		glVertex3f((raio - espessura) * cos(graus + rotacaoF), altura/2, (raio - espessura) * sin(graus + rotacaoF));
		glVertex3f(raio * cos(graus + rotacaoF), altura/2, raio * sin(graus + rotacaoF));

		//Parte de Baixo da caneca
		glVertex3f(0.0f, -altura/2, 0.0f);
		glVertex3f((raio + espessura) * cos(graus), -altura/2, (raio + espessura) * sin(graus));
		glVertex3f((raio + espessura) * cos(graus + rotacaoF), -altura/2, (raio + espessura) * sin(graus + rotacaoF));
		
		//Base da Caneca Cilindrica com o inferior com maior raio que a parte superior
		for(int k = 0; k < this->fatias; k++){
			glVertex3f((raio + espessura) * cos(graus), -altura/2 , (raio + espessura) * -sin(graus));
			glVertex3f(raio * cos(graus + rotacaoF), -altura/ 2 + espessura, raio * -sin(graus + rotacaoF));			
			glVertex3f(raio * cos(graus), -altura / 2 + espessura, raio * -sin(graus));

			glVertex3f((raio + espessura) * cos(graus), -altura/2 , (raio + espessura) * -sin(graus));
			glVertex3f((raio + espessura) * cos(graus + rotacaoF), -altura/ 2, (raio + espessura) * -sin(graus + rotacaoF));			
			glVertex3f(raio * cos(graus + rotacaoF), -altura/ 2 + espessura, raio * -sin(graus + rotacaoF));	
		}
		
		float cam = -this->altura/2 + this->espessura;
		for(int i = 0; i < this->camadas; i++) {
			glVertex3f(raio * cos(graus), cam, raio * sin(graus)); 
			glVertex3f(raio * cos(graus), cam + incA, raio * sin(graus));					
			glVertex3f(raio * cos(graus + rotacaoF), cam + incA, raio * sin(graus + rotacaoF));
			
			glVertex3f(raio* cos(graus), cam , raio* sin(graus)); 				
			glVertex3f(raio* cos(graus + rotacaoF), cam +incA, raio * sin(graus + rotacaoF));				
			glVertex3f(raio* cos(graus + rotacaoF), cam, raio* sin(graus + rotacaoF));
			cam = cam + incA;		//Incrementa a altura, para fazer as outras camadas;
		}
		cam = -this->altura/2 + this->espessura;
		//Parte Interior
		//Base Baixo
		glVertex3f(0.0f, cam, 0.0f);
		glVertex3f((raio - espessura) * cos(graus + rotacaoF), cam, (raio - espessura ) * sin(graus + rotacaoF));
		glVertex3f((raio - espessura)* cos(graus), cam, (raio - espessura) * sin(graus));
		
		//Parte lateral Interior
		for(int i = 0; i < this->camadas; i++) {
			glVertex3f((raio - espessura) * cos(graus + rotacaoF), cam, (raio - espessura) * sin(graus + rotacaoF));
			glVertex3f((raio - espessura) * cos(graus + rotacaoF), cam + incA, (raio - espessura) * sin(graus + rotacaoF));
			glVertex3f((raio - espessura) * cos(graus), cam + incA, (raio - espessura) * sin(graus));				
			
			glVertex3f((raio - espessura) * cos(graus + rotacaoF), cam, (raio - espessura) * sin(graus + rotacaoF));
			glVertex3f((raio - espessura) * cos(graus), cam +incA, (raio - espessura) * sin(graus));				
			glVertex3f((raio - espessura) * cos(graus), cam , (raio - espessura) * sin(graus));
			cam = cam + incA;		//Incrementa a altura, para fazer as outras camadas;
		}
		graus = graus + rotacaoF;
	}

	glEnd();

	glPushMatrix();
		glRotatef(90,0,1,0);
		glRotatef(90,0,0,1);
		glTranslatef(0.0f,0.0f, this->raio);
		pega = new Torus(this->altura / 4, 2 * this->espessura / 3 ,this->fatias, this->camadas);
		pega->meioTorus();
	glPopMatrix();
}

void Copo::desenhaC(){
	Esfera *calice;

	glPushMatrix();
		glRotatef(180,1,0,0);
		glTranslatef(0.0f, - 2 * this->altura / 3 -this->raio, 0.0f);
		calice = new Esfera(this->altura / 3,3*this->fatias, 3*this->camadas);
		calice->meiaEsfera();
	glPopMatrix();


}

void Copo::desenhaD(){
	float incR = M_PI / ( 2* fatias);
	float incA = M_PI / (2* camadas);
	float grausA = -M_PI;
	float grausE = -M_PI/2;
	float graus = -M_PI/2;
	float somatorio = raio * cos(grausE);
	float somatorio2 = raio * cos(grausE + incA);
	float valor = 0;
	float incr = raio / 3;
	float raioC = raio * cos(graus);
	float raioC2 = raio * cos(graus - incR);
	for(int a = 0; a < camadas; a++){
		float grausR = 0.0f;

		for(int l = 0; l < 1; l++){
			glBegin(GL_TRIANGLES);
			
			
			glVertex3f((altura + raio + somatorio) * cos(grausR), raio * cos(grausA), (altura + raio + somatorio) * sin(grausR)); 
			glVertex3f((altura + raio + somatorio2) * cos(grausR + incR), raio * cos(grausA + incA), (altura + raio + somatorio2) * sin(grausR + incR));
			glVertex3f((altura + raio + somatorio)  * cos(grausR + incR), raio * cos(grausA), (altura + raio + somatorio) * sin(grausR + incR));
			/*
			glVertex3f((altura + raio - somatorio) * cos(grausR), raio * cos(grausA), (altura + raio - somatorio) * sin(grausR));
			glVertex3f((altura + raio - somatorio2) * cos(grausR + incR), raio * cos(grausA + incA), (altura + raio - somatorio2) * sin(grausR + incR));
			glVertex3f((altura + raio - somatorio2)  * cos(grausR), raio * cos(grausA + incA), (altura + raio - somatorio2) * sin(grausR));
			
			glVertex3f((altura + raio - somatorio) * cos(grausR), raio * cos(grausA), (altura + raio - somatorio) * sin(grausR)); 
			glVertex3f((altura + raio - somatorio) * cos(grausR + incR), raio * cos(grausA), (altura + raio - somatorio) * sin(grausR + incR));
			glVertex3f((altura + raio - somatorio2)  * cos(grausR + incR), raio * cos(grausA + incA), (altura + raio - somatorio2) * sin(grausR + incR));
			*/
			glEnd();
			grausR = grausR + incR;
			graus = graus - incR;
			raioC = raio * sin(graus);
			raioC2 = raio * sin(graus - incR);
		}
		grausA = grausA + incA;
		grausE = grausE + incA;
		somatorio = raio * cos(grausE);
		somatorio2 = raio * cos(grausE + incA);		
	}
}