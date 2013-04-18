#include <GL/glut.h>
#include <math.h>
#include "bar.h"
#include "plano.h"

/**
 * Construtor da class Bar.
 * Simplesmente inicializa as variaveis de instancia.
 *
 */

Bar::Bar(){
	this->c = 0.0f; 
	this->l = 0.0f; 
	this->a = 0.0f;
	this->f = 0.0f;
	this->p = 0.0f;
}
/**
 * Construtor da class Bar.
 * Simplesmente inicializa as variaveis de instancia.
 * @param c
 * Define o comprimento do espaço
 * @param l
 * define a largura do espaço
 * @param a
 * define a altura do espaço
  * @param f
 * define as fatias do espaço
 * @param p
 * define as camadas do espaco
 */

Bar::Bar(float c, float l, float a, float f, float p){
	this->c = c;
	this->l = l;
	this->a = a;
	this->f = f;
	this->p = p;
}
/**
 * Desenha as 4 paredes, o chão e o tecto.
 * 		
 */
void Bar::desenha(){
	float comp = this->c/2;
	float larg = this->l/2;
	float alt = this->a/2;

	Plano *chao[2];
	Plano *parede[6];
	Plano *tecto[2];

	/*Desenha o Chao do bar */
	glPushMatrix();
		glTranslatef(0, 0,1* larg / 6);
		chao[0] = new Plano(comp, 2*larg / 3, this->f, this->p);
		chao[0]->desenhaXoZ();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(- comp / 8, 0,-1* larg / 3);
		chao[0] = new Plano(6 * comp / 8, 1*larg / 3, this->f, this->p);
		chao[0]->desenhaXoZ();
	glPopMatrix();
	
	/*Desenha as Paredes do Bar*/
	glPushMatrix();
		glTranslatef(-comp/8, alt/2, -larg/2);
		parede[0] = new Plano(6*comp/8, alt, this->f, this->p);
		parede[0]->desenhaXoY();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0, alt/2, larg/2);
		glRotatef(180,0,1,0);
		parede[1] = new Plano(comp, alt, this->f, this->p);
		parede[1]->desenhaXoY();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-comp/2,alt/2,0);
		glRotatef(90,0,1,0);
		parede[2] = new Plano(larg, alt, this->f, this->p);
		parede[2]->desenhaXoY();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(comp/2,alt/2,larg/6);
		glRotatef(-90,0,1,0);
		parede[3] = new Plano(2*larg/3, alt, this->f, this->p);
		parede[3]->desenhaXoY();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(comp/4,alt/2,-larg/3);
		glRotatef(-90,0,1,0);
		parede[4] = new Plano(larg/3, alt, this->f, this->p);
		parede[4]->desenhaXoY();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(comp/4 + comp/8,alt/2,-larg/6);
		parede[5] = new Plano(2*comp/8, alt, this->f, this->p);
		parede[5]->desenhaXoY();
	glPopMatrix();

	/*Desenha o Chao do bar */
	glPushMatrix();
		glTranslatef(0, alt,1* larg / 6);
		glRotatef(180,1,0,0);
		tecto[0] = new Plano(comp, 2*larg / 3, this->f, this->p);
		tecto[0]->desenhaXoZ();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(- comp / 8, alt,-1* larg / 3);
		glRotatef(180,1,0,0);
		tecto[0] = new Plano(6 * comp / 8, 1*larg / 3, this->f, this->p);
		tecto[0]->desenhaXoZ();
	glPopMatrix();
}