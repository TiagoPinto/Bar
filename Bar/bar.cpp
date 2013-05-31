#include "includes.h"
#include "bar.h"
#include "plano.h"
#include "cubo.h"
#include "CadeiraBanco.h"
#include "CadeiraComprido.h"
#include "CadeiraRei.h"
#include "cadeiraStandart.h"
#include "CandeeiroCandelabro.h"
#include "CandeeiroParede.h"
#include "CandeeiroMesa.h"
#include "MesaRectangular.h"
#include "MesaRedonda.h"
#include "MesaStandart.h"

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
 * Define o comprimento do espa�o
 * @param l
 * define a largura do espa�o
 * @param a
 * define a altura do espa�o
  * @param f
 * define as fatias do espa�o
 * @param p
 * define as camadas do espaco
 */

Bar::Bar(float c, float l, float a, float f, float p){
	this->c = c;
	this->l = l;
	this->a = a;
	this->f = f;
	this->p = p;
	
	float comp = this->c/2;
	float larg = this->l/2;
	float alt = this->a/2;

	//TEXTURAS
	GLuint texparede = getTextura("texturas/paredes.jpg");
	GLuint textecto = getTextura("texturas/cena.jpg");
	GLuint texchao = getTextura("texturas/chao.png");
	GLuint ferro = getTextura("texturas/ferro.jpg");
	GLuint vela = getTextura("texturas/vela.jpg");
	GLuint madeira = getTextura("texturas/madeira.jpg");
	GLuint madeiraR = getTextura("texturas/madeira5.jpg");
	GLuint porta = getTextura("texturas/porta.jpg");
	GLuint vidro = getTextura("texturas/vidro.jpg");
	/*Desenha o Chao do bar */

	chaoP = new Plano(comp, 2*larg / 3, this->f, this->p,2, texchao);
	chaoC = new Cubo(6 * comp / 8, 0.05f, 1*larg / 3, this->f, this->p, texchao);

	/*Desenha as Paredes do Bar*/
	parede[0] = new Plano(6*comp/8, alt, this->f, this->p,1, texparede);
	parede[1] = new Plano(comp, alt, this->f, this->p,1, texparede);
	parede[2] = new Plano(larg, alt, this->f, this->p,1, texparede);
	parede[3] = new Plano(2*larg/3, alt, this->f, this->p,1, texparede);
	parede[4] = new Plano(larg/3, alt, this->f, this->p,1, texparede);
	parede[5] = new Plano(2*comp/8, alt, this->f, this->p,1, texparede);

	/*Desenha o Chao do bar */
	tecto[0] = new Plano(comp, 2*larg / 3, this->f, this->p,2, textecto);
	tecto[1] = new Plano(6 * comp / 8, 1*larg / 3, this->f, this->p,2, textecto);

	/*Pilares */
	pilares[0] = new Cubo(0.1, alt, 0.1, f, p, madeira);

	/*Candeeiros*/
	candeeiroTecto[0] = new CandeeiroCandelabro(larg/35,1.5*alt/4, f, p, ferro, vela, madeira);
	candeeiroTecto[0]->preparaB();
	candeeiroTecto[1] = new CandeeiroCandelabro(0.2,alt/4, f, p, ferro, vela, madeira);
	candeeiroTecto[1]->preparaB();
	candeeiroParede[0] = new CandeeiroParede(0.09f,0.15f,f,p, madeira, vidro, vela);

	/*MESAS*/
	mesaRedonda[0] = new MesaRedonda(0.5,0.5,alt/4, 0.05, f, p, madeira);
	mesaRectangular[0] = new MesaRectangular(comp/3,0.5, alt/4,0.05, f, p, madeira);

	/*BANCO*/
	cadeiracomprido[0] = new CadeiraComprido(comp/7, 0.17, alt/4, 0.01, f, p, madeira);

	/*ENFEITES*/
	enfeites[0] = new Plano(1.5f, 2*alt/3-0.05f, 1, 1, 1, porta);
}
/**
 * Desenha as 4 paredes, o ch�o e o tecto.
 * 		
 */
void Bar::desenha(){
	float comp = this->c/2;
	float larg = this->l/2;
	float alt = this->a/2;

	/*Desenha o Chao do bar */
	glPushMatrix();
		glTranslatef(0, 0,1* larg / 6);
		chaoP->desenha();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(- comp / 8, 0.05/2,-1* larg / 3);
		chaoC->desenha();
	glPopMatrix();
	
	/*Desenha as Paredes do Bar*/
	glPushMatrix();
		glTranslatef(-comp/8, alt/2, -larg/2);
		parede[0]->desenha();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0, alt/2, larg/2);
		glRotatef(180,0,1,0);
		parede[1]->desenha();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-comp/2,alt/2,0);
		glRotatef(90,0,1,0);
		parede[2]->desenha();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(comp/2,alt/2,larg/6);
		glRotatef(-90,0,1,0);
		parede[3]->desenha();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(comp/4,alt/2,-larg/3);
		glRotatef(-90,0,1,0);
		parede[4]->desenha();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(comp/4 + comp/8,alt/2,-larg/6);
		parede[5]->desenha();
	glPopMatrix();

	/*Desenha o Tecto do bar */
	glPushMatrix();
		glTranslatef(0, alt,1* larg / 6);
		glRotatef(180,1,0,0);
		tecto[0]->desenha();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(- comp / 8, alt,-1* larg / 3);
		glRotatef(180,1,0,0);
		tecto[1]->desenha();
	glPopMatrix();

	/* PILARES */
	glPushMatrix();
		glTranslatef(-3 * comp / 8, alt/2+0.025, -larg / 6-0.05);
		pilares[0]->desenha();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(comp/8, alt/2+0.025, -larg / 6-0.05);
		pilares[0]->desenha();
	glPopMatrix();

	/*DESENHA OS CANDEEIROS */
	glPushMatrix();
		glTranslatef(-comp/8, alt-(1.5*alt)/8,0);		
		candeeiroTecto[0]->desenhaB();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-comp/8, alt-alt/8,larg/3);		
		candeeiroTecto[1]->desenhaB();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-comp/8, alt-alt/8,-larg/3);		
		candeeiroTecto[1]->desenhaB();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-comp/2+0.06, 2*alt/3,-larg/3);
		glRotatef(90,0,1,0);
		candeeiroParede[0]->desenhaA();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-comp/2+0.06, 2*alt/3,larg/3);
		glRotatef(90,0,1,0);
		candeeiroParede[0]->desenhaA();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(comp/2-0.06, 2*alt/3,larg/3);
		glRotatef(-90,0,1,0);
		candeeiroParede[0]->desenhaA();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(comp/4-0.06, 2*alt/3,-larg/3);
		glRotatef(-90,0,1,0);
		candeeiroParede[0]->desenhaA();
	glPopMatrix();

	/*DESENHA AS MESAS*/
	glPushMatrix();
		glTranslatef(comp/8, 0.0f,0.0f);
		mesaRedonda[0]->desenhaB();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0f, 0.0f,larg/6);
		glRotatef(90,0,1,0);
		mesaRectangular[0]->desenhaC();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-comp/4, 0.0f,larg/6);
		glRotatef(90,0,1,0);
		mesaRectangular[0]->desenhaC();
	glPopMatrix();

	/*DESENHA AS CADEIRAS*/
	glPushMatrix();
		glTranslatef(-comp/4-0.4, 0.0f,larg/9);
		glRotatef(90,0,1,0);
		cadeiracomprido[0]->desenhaC();
	glPopMatrix();




	/*ENFEITES*/
	glPushMatrix();
		glTranslatef(-comp/8, alt/3,larg/2-0.1f);
		glRotatef(180,0,1,0);
		enfeites[0]->desenha();
	glPopMatrix();
}

/**
 * Destrutor da class Bar.
 *  * Destroi o VBO criado, para nao ficar alocada memoria na placa grafica	
 */
Bar::~Bar(){
	glDeleteBuffers(1,&vbo);
	delete tecto[0];
	delete tecto[1];
	delete chaoP;
	delete chaoC;
	delete parede[0];
	delete parede[1];
	delete parede[2];
	delete parede[3];
	delete parede[4];
	delete parede[5];
	delete candeeiroTecto[0];
	delete candeeiroTecto[1];
	delete mesaRedonda[0];
	delete mesaRectangular[0];
}	