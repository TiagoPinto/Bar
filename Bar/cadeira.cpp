#define _USE_MATH_DEFINES

#include "cadeira.h"
#include "cubo.h"
#include "cilindro.h"
#include "esfera.h"
#include <GL/glut.h>
#include <math.h>

/**
 * Construtor da class Cadeira.
 * Inicializa as variaveis de largura, altura, espessura, fatias e camadas.	
 */
Cadeira::Cadeira(){
	this->comprimento = 0.0f;
	this->largura = 0.0f;
	this->altura = 0.0f;
	this->espessura = 0.0f;
	this->fatias = 0.0f;
	this->camadas = 0.0f;
}

/**
 * Construtor da class Cadeira.
  *@param c
 * 	 Variavel que especifica a comprimento da cadeira
 *@param l
 * 	 Variavel que especifica a largura da cadeira
  *@param a
 * 	 Variavel que especifica a altura da cadeira
  *@param e
 * 	 Variavel que especifica a espessura da cadeira
 *@param f
 * 	 Variavel que especifica as fatias da cadeira
 *@param p
 * 	 Variavel que especifica as camadas da cadeira
 */
Cadeira::Cadeira(float c, float l, float a, float e, float f, float p){
	this->comprimento = c;
	this->largura = l;
	this->altura = a;
	this->espessura = e;
	this->fatias = f;
	this->camadas = p;
}

void Cadeira::desenhaBasePernas(){
	Cubo *base;
	Cubo *perna[4];
	Cubo *costas;

	//Base da Mesa 
	glPushMatrix();
		glTranslatef(0.0f, 4.5f * this->altura / 10.0f, 0.0f);
		base = new Cubo(this->comprimento, this->espessura, this->largura, this->fatias, this->camadas);;
		base->desenha();
	glPopMatrix();

	//Perna da Frente Direita
	glPushMatrix();
		glTranslatef(this->comprimento/2 - this->espessura/2, (2.0f * this->altura) / 10.0f, this->largura/2 - this->espessura/2);
		perna[0] = new Cubo(this->espessura, 4.0f * this->altura / 10.0f , this->espessura, this->fatias, this->camadas);
		perna[0]->desenha();
	glPopMatrix();	

	//Perna da Frente Esquerda
	glPushMatrix();
		glTranslatef(-this->comprimento/2 + this->espessura/2, 2.0f * this->altura / 10, this->largura/2 - this->espessura/2);
		perna[1] = new Cubo(this->espessura, 4.0f * this->altura / 10.0f , this->espessura, this->fatias, this->camadas);
		perna[1]->desenha();
	glPopMatrix();	
	
	//Perna de Tras Direita
	glPushMatrix();
		glTranslatef(this->comprimento/2 - this->espessura/2, 2.0f * this->altura / 10, -this->largura/2 + this->espessura/2);
		perna[2] = new Cubo(this->espessura, 4.0f * this->altura / 10.0f , this->espessura, this->fatias, this->camadas);
		perna[2]->desenha();
	glPopMatrix();

	//Perna de Tras Esquerda
	glPushMatrix();
		glTranslatef(-this->comprimento/2 + this->espessura/2, 2.0f * this->altura / 10, -this->largura/2 + this->espessura/2);
		perna[3] = new Cubo(this->espessura, 4.0f * this->altura / 10.0f , this->espessura, this->fatias, this->camadas);
		perna[3]->desenha();
	glPopMatrix();

	//Tabua Para as Costas
	glPushMatrix();
		glTranslatef(0.0f, 7.5f * this->altura / 10, - this->largura / 2 + this->espessura/2);
		costas = new Cubo(this->comprimento, 5.0f * this->altura / 10, this->espessura, this->fatias, this->camadas);
		costas->desenha();
	glPopMatrix();
}

void Cadeira::desenhaA(){
	Cubo *tabua[4];

	desenhaBasePernas();
	
	//Tabua que Liga as Pernas da Direita
	glPushMatrix();
		glTranslatef(this->comprimento/2 - this->espessura/2, this->altura / 10.0f, 0.0f);
		tabua[0] = new Cubo(this->espessura, this->espessura / 2, this->largura - 2 * this->espessura, this->fatias, this->camadas);
		tabua[0]->desenha();
	glPopMatrix();
	
	//Tabua que Liga as Pernas da Esquerda
	glPushMatrix();
		glTranslatef(-this->comprimento/2 + this->espessura/2, this->altura / 10, 0.0f);
		tabua[1] = new Cubo(this->espessura, this->espessura / 2, this->largura - 2* this->espessura, this->fatias, this->camadas);
		tabua[1]->desenha();
	glPopMatrix();
	
	//Tabua que Liga as Pernas da Frente
	glPushMatrix();
		glTranslatef(0.0f, this->altura / 10, this->largura/2 - this->espessura/2);
		tabua[2] = new Cubo(this->comprimento - 2 * this->espessura, this->espessura/2, this->espessura, this->fatias, this->camadas);
		tabua[2]->desenha();
	glPopMatrix();

	//Tabua que Liga as Pernas de Tras
	glPushMatrix();
		glTranslatef(0.0f, this->altura / 10, -this->largura/2 + this->espessura/2);
		tabua[3] = new Cubo(this->comprimento - 2 * this->espessura, this->espessura/2, this->espessura, this->fatias, this->camadas);
		tabua[3]->desenha();
	glPopMatrix();
}

void Cadeira::desenhaB(){
	Cilindro *base;
	Cilindro *perna[4];
	float graus = 0.0f;
	//Base da Mesa 
	glPushMatrix();
		glTranslatef(0.0f, this->altura, 0.0f);
		base = new Cilindro(this->largura, this->espessura, this->fatias * 3, this->camadas * 2);
		base->desenha();
	glPopMatrix();
	//Pernas
	for(int i = 0; i < 4; i++) {
		glPushMatrix();
			glTranslatef((this->largura - this->espessura) * cos(graus), this->altura / 2, (this->largura - this->espessura) * sin(graus));
			perna[i] = new Cilindro(this->espessura / 2, this->altura - this->espessura, this->fatias * 3, this->camadas);
			perna[i]->desenha();
		glPopMatrix();	
		graus = graus + M_PI / 2;
	}
}

void Cadeira::desenhaC(){
	Cubo *base;
	Cubo *perna[4];
	Cubo *tabua[3];
	
	desenhaBasePernas();
	//Tabua que Liga as Pernas da Direita
	glPushMatrix();
		glTranslatef(this->comprimento/2 - this->espessura/2, this->altura / 10, 0.0f);
		tabua[0] = new Cubo(this->espessura, this->espessura / 2, this->largura - 2 * this->espessura, this->fatias, this->camadas);
		tabua[0]->desenha();
	glPopMatrix();

	//Tabua que Liga as Pernas da Esquerda
	glPushMatrix();
		glTranslatef(-this->comprimento/2 + this->espessura/2, this->altura / 10, 0.0f);
		tabua[1] = new Cubo(this->espessura, this->espessura / 2, this->largura - 2 * this->espessura, this->fatias, this->camadas);
		tabua[1]->desenha();
	glPopMatrix();

	//Tabua Central
	glPushMatrix();
		glTranslatef(0.0f, this->altura / 10, 0.0f);
		tabua[2] = new Cubo(this->comprimento - 2 * this->espessura, this->espessura / 2, this->espessura, this->fatias, this->camadas);
		tabua[2]->desenha();
	glPopMatrix();
}

void Cadeira::desenhaD(){
	Esfera *ornamento[2];
	Cubo *bracos[4];

	desenhaBasePernas();

	//Desenho do Braço Direito
	glPushMatrix();
		glTranslatef(this->comprimento/2 - this->espessura / 4, 7.0f * this->altura / 10.0f, this->espessura/2);
		bracos[0] = new Cubo(this->espessura / 2, this->espessura / 2, this->largura - this->espessura, this->fatias, this->camadas);
		bracos[0]->desenha();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(this->comprimento / 2 - this->espessura / 4, 6.0f * this->altura / 10.0f - this->espessura/8, this->largura/2 - this->espessura/4);
		bracos[0] = new Cubo(this->espessura / 2, 2.0f * this->altura / 10.0f - this->espessura / 4, this->espessura / 2, this->fatias, this->camadas);
		bracos[0]->desenha();
	glPopMatrix();

	//Desenho do Braço Esquerdo
	glPushMatrix();
		glTranslatef(-this->comprimento/2 + this->espessura / 4, 7.0f * this->altura / 10.0f, this->espessura/2);
		bracos[2] = new Cubo(this->espessura / 2, this->espessura / 2, this->largura - this->espessura, this->fatias, this->camadas);
		bracos[2]->desenha();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-this->comprimento / 2 + this->espessura / 4, 6.0f * this->altura / 10.0f - this->espessura/8, this->largura/2 - this->espessura/4);
		bracos[0] = new Cubo(this->espessura / 2, 2.0f * this->altura / 10.0f - this->espessura / 4, this->espessura / 2, this->fatias, this->camadas);
		bracos[0]->desenha();
	glPopMatrix();

	//Bolas No Canto Superior da Cadeira
	glPushMatrix();
		glTranslatef(-this->comprimento / 2 + this->espessura / 2, this->altura + this->espessura /2, -this->largura / 2 + this->espessura / 2);
		ornamento[0] = new Esfera(this->espessura / 2, this->fatias * 4, this->camadas * 3);
		ornamento[0]->desenha();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(this->comprimento / 2 - this->espessura / 2, this->altura + this->espessura /2, -this->largura / 2 + this->espessura / 2);
		ornamento[0] = new Esfera(this->espessura / 2, this->fatias * 4, this->camadas * 3);
		ornamento[0]->desenha();
	glPopMatrix();

	// Meia Circunferencia no Topo da cadeira
	//Meia Circunferencia da parte de tras
	glPushMatrix();
		glTranslatef(0.0f, this->altura, -this->largura / 2);
	float rotacaoRT = M_PI;
	float rotacaoCT = (M_PI / 2) / this->camadas;
	float grausCT = 0;
	for(int k = 0; k < this->camadas; k++){
		float grausRT = 0;
		glBegin(GL_TRIANGLES);
		glVertex3f((this->comprimento / 2 - this->espessura) * cos(grausRT) * sin(grausCT), (this->comprimento / 4) * cos(grausCT), (this->comprimento / 2 - this->espessura) * sin(grausRT) * sin(grausCT)); 
		glVertex3f((this->comprimento / 2 - this->espessura) * cos(grausRT) * sin(grausCT + rotacaoCT), (this->comprimento / 4) * cos(grausCT + rotacaoCT), (this->comprimento / 2 - this->espessura) * sin(grausRT) * sin(grausCT + rotacaoCT));
		glVertex3f((this->comprimento / 2 - this->espessura) * cos(grausRT + rotacaoRT) * sin(grausCT + rotacaoCT), (this->comprimento / 4) * cos(grausCT + rotacaoCT), (this->comprimento / 2 - this->espessura) * sin(grausRT + rotacaoRT) * sin(grausCT + rotacaoCT));

		glVertex3f((this->comprimento / 2 - this->espessura) * cos(grausRT) * sin(grausCT), (this->comprimento / 4) * cos(grausCT), (this->comprimento / 2 - this->espessura) * sin(grausRT) * sin(grausCT)); 				
		glVertex3f((this->comprimento / 2 - this->espessura) * cos(grausRT + rotacaoRT) * sin(grausCT + rotacaoCT), (this->comprimento / 4) * cos(grausCT + rotacaoCT), (this->comprimento / 2 - this->espessura) * sin(grausRT + rotacaoRT) * sin(grausCT + rotacaoCT));
		glVertex3f((this->comprimento / 2 - this->espessura) * cos(grausRT + rotacaoRT) * sin(grausCT), (this->comprimento / 4) * cos(grausCT), (this->comprimento / 2 - this->espessura) * sin(grausRT + rotacaoRT) * sin(grausCT));
		glEnd();		
		grausCT = grausCT + rotacaoCT;
	}

	//Meia Circunferencia da Frente
	glTranslatef(0.0f,0.0f, this->espessura);
	float rotacaoR = M_PI;
	float rotacaoC = (M_PI / 2) / this->camadas;
	float rotacaoA = M_PI / this->camadas;
	float grausC = 0;
	for(int k = 0; k < this->camadas; k++){
		float grausR = 0;
		glBegin(GL_TRIANGLES);
		glVertex3f((this->comprimento / 2 - this->espessura) * cos(rotacaoR) * sin(grausC), (this->comprimento / 4) * cos(grausC), (this->comprimento / 2 - this->espessura) * sin(grausR) * sin(grausC)); 
		glVertex3f((this->comprimento / 2 - this->espessura) * cos(rotacaoR) * sin(grausC + rotacaoC), (this->comprimento / 4) * cos(grausC + rotacaoC), (this->comprimento / 2 - this->espessura) * sin(grausR) * sin(grausC + rotacaoC));
		glVertex3f((this->comprimento / 2 - this->espessura) * cos(grausR) * sin(grausC + rotacaoC), (this->comprimento / 4) * cos(grausC + rotacaoC), (this->comprimento / 2 - this->espessura) * sin(grausR + rotacaoR) * sin(grausC + rotacaoC));

		glVertex3f((this->comprimento / 2 - this->espessura) * cos(rotacaoR) * sin(grausC), (this->comprimento / 4) * cos(grausC), (this->comprimento / 2 - this->espessura) * sin(grausR) * sin(grausC)); 				
		glVertex3f((this->comprimento / 2 - this->espessura) * cos(grausR) * sin(grausC + rotacaoC), (this->comprimento / 4) * cos(grausC + rotacaoC), (this->comprimento / 2 - this->espessura) * sin(grausR + rotacaoR) * sin(grausC + rotacaoC));
		glVertex3f((this->comprimento / 2 - this->espessura) * cos(grausR) * sin(grausC), (this->comprimento / 4) * cos(grausC), (this->comprimento / 2 - this->espessura) * sin(grausR + rotacaoR) * sin(grausC));

		/*
		glVertex3f((this->comprimento / 2 - this->espessura) * cos(grausR) * sin(grausC), (this->comprimento / 4) * cos(grausC), -this->espessura);
		glVertex3f((this->comprimento / 2 - this->espessura) * cos(grausR) * sin(grausC), (this->comprimento / 4) * cos(grausC), 0.0f);
		glVertex3f((this->comprimento / 2 - this->espessura) * cos(grausR + rotacaoA) * sin(grausC), (this->comprimento / 4) * cos(grausC - rotacaoC), 0.0f);

		glVertex3f((this->comprimento / 2 - this->espessura) * cos(grausR) * sin(grausC), (this->comprimento / 4) * cos(grausC), -this->espessura);
		glVertex3f((this->comprimento / 2 - this->espessura) * cos(grausR + rotacaoA) * sin(grausC), (this->comprimento / 4) * cos(grausC + rotacaoC), -this->espessura);
		glVertex3f((this->comprimento / 2 - this->espessura) * cos(grausR + rotacaoA) * sin(grausC), (this->comprimento / 4) * cos(grausC + rotacaoC), 0.0f);
		*/glEnd();		
		grausC = grausC + rotacaoC;
		grausR = grausR + rotacaoA;
	}
	glPopMatrix();
}