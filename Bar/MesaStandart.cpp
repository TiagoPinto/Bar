#include "includes.h"
#include "MesaStandart.h"
#include "cubo.h"
#include "cilindro.h"


/**
 * Construtor da class Mesa.
 * Inicializa as variaveis de comprimento, largura, altura, espessura, fatias e camadas.	
 */
MesaStandart::MesaStandart(){
	this->comprimento = 0.0f;
	this->largura = 0.0f;
	this->altura = 0.0f;
	this->espessura = 0.0f;
	this->fatias = 0.0f;
	this->camadas = 0.0f;
}

/**
 * Construtor da class Mesa.
 * Inicializa as variaveis de raio e altura do cilindro.
 *@param c
 * 	 Variavel que especifica o comprimento da mesa
 *@param l
 * 	 Variavel que especifica a largura da mesa
  *@param a
 * 	 Variavel que especifica a altura da mesa
  *@param e
 * 	 Variavel que especifica a espessura da mesa
 *@param f
 * 	 Variavel que especifica as fatias da mesa
 *@param p
 * 	 Variavel que especifica as camadas da mesa
 */
MesaStandart::MesaStandart(float c, float l, float a, float e, float f, float p, GLuint idMadeira){
	this->comprimento = c;
	this->largura = l;
	this->altura = a;
	this->espessura = e;
	this->fatias = f;
	this->camadas = p;
	this->textura = idMadeira;

	//Base da Mesa 
		base = new Cubo(this->comprimento, this->espessura,this->largura , this->fatias, this->camadas, idMadeira);

	//Perna da Frente Direita
		perna[0] = new Cilindro((2 * this->espessura) / 3, this->altura - this->espessura, this->fatias * 3, this->camadas,1, idMadeira);

	//Perna da Frente Esquerda
		perna[1] = new Cilindro((2 * this->espessura) / 3, this->altura - this->espessura, this->fatias * 3, this->camadas,1, idMadeira);
	
	//Perna de Tras Direita
		perna[2] = new Cilindro((2 * this->espessura) / 3, this->altura - this->espessura, this->fatias * 3, this->camadas,1, idMadeira);

	//Perna de Tras Esquerda
		perna[3] = new Cilindro((2 * this->espessura) / 3, this->altura - this->espessura, this->fatias * 3, this->camadas,1, idMadeira);

}


/**
 * Desenha uma mesa standard rectangular ou quadrada com as pernas cilindricas
 * 		
 */
void MesaStandart::desenhaA(){
	//Base da Mesa 
	glPushMatrix();
	glTranslatef(0.0f, this->altura-this->espessura/2, 0.0f);
		base->desenha();
	glPopMatrix();

	//Perna da Frente Direita
	glPushMatrix();
		glTranslatef(this->comprimento/2 - this->espessura, this->altura / 2-this->espessura/2, this->largura/2 - this->espessura);
		perna[0]->desenha();
	glPopMatrix();	

	//Perna da Frente Esquerda
	glPushMatrix();
		glTranslatef(-this->comprimento/2 + this->espessura, this->altura / 2-this->espessura/2, this->largura/2 - this->espessura);
		perna[1]->desenha();
	glPopMatrix();	
	
	//Perna de Tras Direita
	glPushMatrix();
		glTranslatef(this->comprimento/2 - this->espessura, this->altura / 2-this->espessura/2, -this->largura/2 + this->espessura);
		perna[2]->desenha();
	glPopMatrix();

	//Perna de Tras Esquerda
	glPushMatrix();
		glTranslatef(-this->comprimento/2 + this->espessura, this->altura / 2-this->espessura/2, -this->largura/2 + this->espessura);
		perna[3]->desenha();
	glPopMatrix();
}

MesaStandart::~MesaStandart(){
	glDeleteBuffers(1,&vbo);
	delete base;
	delete perna[0];
	delete perna[1];
	delete perna[2];
	delete perna[3];
}	