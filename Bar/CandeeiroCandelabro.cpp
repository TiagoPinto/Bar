#include "includes.h"
#include "CandeeiroCandelabro.h"
#include "cilindro.h"
#include "cubo.h"
#include "Anel.h"
/**
 * Construtor da class Cilindro.
 * Inicializa as variaveis de comprimento, altura, fatias e camadas do cilindro.
 *@param c
 * 	 Variavel que especifica o comprimento do cilindro	
 *@param a
 * 	 Variavel que especifica a altura do cilindro
  *@param f
 * 	 Variavel que especifica as fatias do cilindro
  *@param p
 * 	 Variavel que especifica as camadas do cilindro
 */

/**
 * Construtor da class Candeeiro.
 * Inicializa todas as variaveis de instancia.
 *
 */
CandeeiroCandelabro::CandeeiroCandelabro(){
	this->comprimento = 0.0f;
	this->altura = 0.0f;
	this->fatias = 0.0f;
	this->camadas = 0.0f;
}

CandeeiroCandelabro::CandeeiroCandelabro(float c, float a, float f, float p, GLuint idferro, GLuint idvela, GLuint idMadeira){
	this->comprimento = c;
	this->altura = a;
	this->fatias = f;
	this->camadas = p;
	this->texturaFerro = idferro;
	this->texturaVela = idvela;
	this->texturaMadeira = idMadeira;
}

 void CandeeiroCandelabro::preparaB(){
	 float graus = 0;
	//Anel Superior
	anel[0] = new Anel(comprimento/2-comprimento*0.2, comprimento*0.2, comprimento*0.1, fatias, camadas, texturaMadeira);
	//Anel Inferior
	anel[1] = new Anel(comprimento-comprimento*0.2, comprimento*0.2, comprimento*0.1, fatias, camadas, texturaMadeira);

	segurador = new Cilindro(comprimento*0.1, altura, fatias*2, camadas,1, texturaFerro);

	//DESENHO DAS VELAS
	while (graus <= 2*M_PI){
		for(int cima = 0; cima < 2; cima ++){
			//velas de cima
			vela[cima] = new Cilindro(comprimento*0.05, altura/5, fatias*2, camadas,1, texturaVela);
			cima ++;
			//velas de baixo
			vela[cima] = new Cilindro(comprimento*0.05, altura/7, fatias*2, camadas,1, texturaVela);
		}
		graus = 3*(2 * M_PI/this->fatias) + graus;
	}
	//ferros que seguram os Aneis
	ferros[0] = new Cubo((comprimento-comprimento*0.3), comprimento*0.05,comprimento*0.05, fatias/2, camadas/2, texturaFerro);
	ferros[1] = new Cubo((comprimento/2-comprimento*0.3), comprimento*0.05,comprimento*0.05, fatias/2, camadas/2, texturaFerro);
	ferros[2] = new Cubo((comprimento-comprimento*0.3), comprimento*0.05,comprimento*0.05, fatias/2, camadas/2, texturaFerro);
	ferros[3] = new Cubo((comprimento/2-comprimento*0.3), comprimento*0.05,comprimento*0.05, fatias/2, camadas/2, texturaFerro);
	ferros[4] = new Cubo(comprimento*0.05, comprimento*0.05,(comprimento-comprimento*0.3), fatias/2, camadas/2, texturaFerro);
	ferros[5] = new Cubo(comprimento*0.05, comprimento*0.05,(comprimento/2-comprimento*0.3), fatias/2, camadas/2, texturaFerro);
	ferros[6] = new Cubo(comprimento*0.05, comprimento*0.05,(comprimento-comprimento*0.3), fatias/2, camadas/2, texturaFerro);
	ferros[7] = new Cubo(comprimento*0.05, comprimento*0.05,(comprimento/2-comprimento*0.3), fatias/2, camadas/2, texturaFerro);
 }

 void CandeeiroCandelabro::desenhaB(){
	 float graus = 0;

	 glPushMatrix();
		glTranslatef(0.0f, (comprimento*0.1)/2,0.0f);
		anel[0]->desenha();
	 glPopMatrix();

	  glPushMatrix();
		glTranslatef(0.0f, -altura/2+comprimento*0.05,0.0f);
		anel[1]->desenha();
	 glPopMatrix();

	 //ferro segurador
	 glPushMatrix();
		glTranslatef(0.0f,0.0f,0.0f);
		segurador->desenha();
	 glPopMatrix();

	 	//DESENHO DAS VELAS
	while (graus <= 2*M_PI){
		for(int cima = 0; cima < 2; cima ++){
		//velas de cima
			glPushMatrix();
			glTranslatef((comprimento - comprimento*0.1) * cos(graus),-altura/2 +comprimento*0.1+(altura/5)/2,(comprimento-comprimento*0.1) * sin(graus));
			vela[cima]->desenha();
			glPopMatrix();
			cima ++;
			//velas de baixo
			glPushMatrix();
			glTranslatef((comprimento/2 - comprimento*0.1) * cos(graus),comprimento*0.1+(altura/7)/2,(comprimento/2-comprimento*0.1) * sin(graus));
			vela[cima]->desenha();
			glPopMatrix();
		}
		graus = 3*(2 * M_PI/this->fatias) + graus;
	}
	
		 //ferros que seguram os Aneis
	 glPushMatrix();
		glTranslatef((comprimento/2-comprimento*0.05)*cos(0.0f),-altura/2+comprimento*0.05,0);
		ferros[0]->desenha();
	glPopMatrix();

	glPushMatrix();
		glTranslatef((comprimento/4-comprimento*0.05)*cos(0.0f),comprimento*0.05,0);
		ferros[1]->desenha();
	glPopMatrix();

	glPushMatrix();
		glTranslatef((-comprimento/2+comprimento*0.05)*cos(0.0f),-altura/2+comprimento*0.05,0);
		ferros[2]->desenha();
	glPopMatrix();

	glPushMatrix();
		glTranslatef((-comprimento/4+comprimento*0.05)*cos(0.0f),comprimento*0.05,0);
		ferros[3]->desenha();
	glPopMatrix();


	glPushMatrix();
		glTranslatef(0,-altura/2+comprimento*0.05,(comprimento/2)*sin(90.0f));
		ferros[4]->desenha();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0,comprimento*0.05,(comprimento/4-comprimento*0.04)*sin(90.0f));
		ferros[5]->desenha();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0,-altura/2+comprimento*0.05,(-comprimento/2)*sin(90.0f));
		ferros[6]->desenha();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0,comprimento*0.05,(-comprimento/4+comprimento*0.04)*sin(90.0f));
		ferros[7]->desenha();
	glPopMatrix();
	
	glBindBuffer(GL_ARRAY_BUFFER,vbo);
	glBindTexture(GL_TEXTURE_2D,texturaFerro);
	glVertexPointer(3,GL_FLOAT,sizeof(vertex),(void*)offsetof(vertex,vertices));
	glNormalPointer(GL_FLOAT,sizeof(vertex),(void*)offsetof(vertex,normais));
	glTexCoordPointer(2,GL_FLOAT,sizeof(vertex),(void*)offsetof(vertex,texturas));
	glPushMatrix();
	glMatrixMode(GL_TEXTURE);
	//glScalef(2,1,0);
	glPopMatrix();
	glDrawArrays(GL_TRIANGLES,0,nVertices);
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
 }

CandeeiroCandelabro::~CandeeiroCandelabro(){
	glDeleteBuffers(1,&vbo);
	delete segurador;
	delete vela[0];
	delete vela[1];
	delete ferros[0];
	delete ferros[1];
	delete ferros[2];
	delete ferros[3];
	delete ferros[4];
	delete ferros[5];
	delete ferros[6];
	delete ferros[7];
	delete anel[0];
	delete anel[1];
}