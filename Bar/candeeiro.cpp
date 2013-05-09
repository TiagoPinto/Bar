#include "includes.h"
#include "candeeiro.h"
#include "cilindro.h"
#include "esfera.h"
#include "cubo.h"
#include "plano.h"
#include "piramide.h"
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
Candeeiro::Candeeiro(){
	this->comprimento = 0.0f;
	this->altura = 0.0f;
	this->fatias = 0.0f;
	this->camadas = 0.0f;
}

Candeeiro::Candeeiro(float c, float a, float f, float p){
	this->comprimento = c;
	this->altura = a;
	this->fatias = f;
	this->camadas = p;
}
/**
 * Método que desenha um cilindro
 *
 */
void Candeeiro::desenhaA(){
	Cubo *base;
	Cubo *segurador[2];
	Plano *caixa[9];
	Cilindro *vela;
	Piramide *topo;

	glPushMatrix();
		glTranslatef(0.0f,-this->altura/2, 0.0f);
		base = new Cubo(this->comprimento, this->altura / 6, this->comprimento, this->fatias, this->camadas);
		base->desenha();
		delete base;
	glPopMatrix();

	//parede da caixa, parte traseira
	glPushMatrix();
		glTranslatef(0.0f,-this->altura /6, -this->comprimento/2);
		caixa[0] = new Plano(this->comprimento, this->altura / 2, this->fatias, this->camadas,1);
		caixa[0]->desenha();
		delete caixa[0];
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0f,-this->altura /6, -this->comprimento/2);
		glRotatef(180,0,1,0);
		caixa[1] = new Plano(this->comprimento, this->altura / 2, this->fatias, this->camadas,1);
		caixa[1]->desenha();
		delete caixa[1];
	glPopMatrix();

	//parede da caixa, parte frontal
	glPushMatrix();
		glTranslatef(0.0f,-this->altura /6, this->comprimento/2);
		caixa[2] = new Plano(this->comprimento, this->altura / 2, this->fatias, this->camadas,1);
		caixa[2]->desenha();
		delete caixa[2];
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0f,-this->altura /6, this->comprimento/2);
		glRotatef(180,0,1,0);
		caixa[3] = new Plano(this->comprimento, this->altura / 2, this->fatias, this->camadas,1);
		caixa[3]->desenha();
		delete caixa[3];
	glPopMatrix();

	//parede da caixa, parte lateral direita
	glPushMatrix();
		glTranslatef(this->comprimento/2,-this->altura /6, 0.0f);
		glRotatef(90,0,1,0);
		caixa[4] = new Plano(this->comprimento, this->altura / 2, this->fatias, this->camadas,1);
		caixa[4]->desenha();
		delete caixa[4];
	glPopMatrix();

	glPushMatrix();
		glTranslatef(this->comprimento/2,-this->altura /6, 0.0f);
		glRotatef(-90,0,1,0);
		caixa[5] = new Plano(this->comprimento, this->altura / 2, this->fatias, this->camadas,1);
		caixa[5]->desenha();
		delete caixa[5];
	glPopMatrix();

	//parede da caixa, parte lateral esquerda
	glPushMatrix();
		glTranslatef(-this->comprimento/2,-this->altura /6, 0.0f);
		glRotatef(90,0,1,0);
		caixa[6] = new Plano(this->comprimento, this->altura / 2, this->fatias, this->camadas,1);
		caixa[6]->desenha();
		delete caixa[6];
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-this->comprimento/2,-this->altura /6, 0.0f);
		glRotatef(-90,0,1,0);
		caixa[7] = new Plano(this->comprimento, this->altura / 2, this->fatias, this->camadas,1);
		caixa[7]->desenha();
		delete caixa[7];
	glPopMatrix();

	//piramide no topo
	glPushMatrix();
		glTranslatef(0.0f,this->altura*0.30, 0.0f);
		topo = new Piramide(comprimento, 0.43*altura, comprimento, fatias, camadas);
		topo->desenha();
		delete topo;
	glPopMatrix();

	//vela
	glPushMatrix();
		glTranslatef(0.0f,-this->altura /4, 0.0f);
		vela = new Cilindro(this->comprimento/5, this->altura/3, this->fatias*2, this->camadas,1);
		vela->desenha();
		delete vela;
	glPopMatrix();

	//Sitio onde segura
	glPushMatrix();
		glTranslatef(0.0f,this->altura/2 + this->altura/16, 0.0f);
		segurador[0] = new Cubo(this->comprimento /20, this->altura / 8, this->comprimento / 20, this->fatias, this->camadas);
		segurador[0]->desenha();
		delete segurador[0];
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.0f,this->altura/2 + this->altura / 8 + this->comprimento / 20, -this->comprimento/4);
		segurador[1] = new Cubo(this->comprimento /8, this->comprimento / 10, 2 * this->comprimento / 3, this->fatias, this->camadas);
		segurador[1]->desenha();
		delete segurador[1];
	glPopMatrix();
}

 void Candeeiro::preparaB(){
	 std:: vector<vertex> vertices;

	 float rotacao = 2 * M_PI/this->fatias;
	 float rotacaoF = (2 * M_PI) / this->fatias;
	 float graus = 0.0f;

	while(graus <=2* M_PI){
		//ANEL DE BAIXO
		
	//anel a volta
	//parte Superior
		vertices.push_back(vertex((comprimento -comprimento*0.2)* cos(graus), -altura/2 + comprimento*0.1, (comprimento -comprimento*0.2) * sin(graus), 0,1,0));
		vertices.push_back(vertex(comprimento * cos(graus + rotacaoF), -altura/2 + comprimento*0.1, comprimento * sin(graus + rotacaoF),0,1,0));
		vertices.push_back(vertex(comprimento * cos(graus), -altura/2 + comprimento*0.1, comprimento * sin(graus),0,1,0));

		vertices.push_back(vertex((comprimento -comprimento*0.2) * cos(graus), -altura/2 + comprimento*0.1, (comprimento-comprimento*0.2) * sin(graus),0,1,0));
		vertices.push_back(vertex((comprimento-comprimento*0.2) * cos(graus + rotacaoF), -altura/2+comprimento*0.1, (comprimento-comprimento*0.2) * sin(graus + rotacaoF),0,1,0));
		vertices.push_back(vertex(comprimento * cos(graus + rotacaoF), -altura/2+comprimento*0.1, comprimento * sin(graus + rotacaoF),0,1,0));

	//parte Inferior
		vertices.push_back(vertex((comprimento -comprimento*0.2)* cos(graus), -altura/2, (comprimento -comprimento*0.2) * sin(graus),0,-1,0));
		vertices.push_back(vertex(comprimento * cos(graus), -altura/2, comprimento * sin(graus),0,-1,0));
		vertices.push_back(vertex(comprimento * cos(graus + rotacaoF), -altura/2, comprimento * sin(graus + rotacaoF),0,-1,0));
			

		vertices.push_back(vertex((comprimento -comprimento*0.2) * cos(graus), -altura/2, (comprimento-comprimento*0.2) * sin(graus),0,-1,0));
		vertices.push_back(vertex(comprimento * cos(graus + rotacaoF), -altura/2, comprimento * sin(graus + rotacaoF),0,-1,0));
		vertices.push_back(vertex((comprimento-comprimento*0.2) * cos(graus + rotacaoF), -altura/2, (comprimento-comprimento*0.2) * sin(graus + rotacaoF),0,-1,0));		

		float incA = (comprimento*0.1)/this->camadas;
		float cam = -this->altura/2;
		for(int i = 0; i < this->camadas; i++) {
			//Parte exterior do anel
			vertices.push_back(vertex(comprimento * cos(graus), cam, comprimento * sin(graus),cos(graus),0,sin(graus))); 
			vertices.push_back(vertex(comprimento * cos(graus), cam + incA, comprimento * sin(graus),cos(graus),0,sin(graus)));
			vertices.push_back(vertex(comprimento * cos(graus + rotacao), cam + incA, comprimento * sin(graus + rotacao),cos(graus+rotacao),0,sin(graus+rotacao)));
			
			vertices.push_back(vertex(comprimento * cos(graus), cam , comprimento * sin(graus),cos(graus),0,sin(graus))); 				
			vertices.push_back(vertex(comprimento * cos(graus + rotacao), cam +incA, comprimento * sin(graus + rotacao),cos(graus+rotacao),0,sin(graus+rotacao)));
			vertices.push_back(vertex(comprimento * cos(graus + rotacao), cam, comprimento * sin(graus + rotacao),cos(graus+rotacao),0,sin(graus+rotacao)));
			cam = cam + incA;		//Incrementa a altura, para fazer as outras camadas;
		}
		incA = (comprimento*0.1)/this->camadas;
		cam = -this->altura/2;
		for(int i = 0; i < this->camadas; i++) {
			//Parte interior do anel
			vertices.push_back(vertex((comprimento-comprimento*0.2) * cos(graus), cam, (comprimento-comprimento*0.2) * sin(graus),-cos(graus),0,-sin(graus))); 
			vertices.push_back(vertex((comprimento-comprimento*0.2) * cos(graus + rotacao), cam + incA, (comprimento-comprimento*0.2) * sin(graus + rotacao),-cos(graus+rotacao),0,-sin(graus+rotacao)));
			vertices.push_back(vertex((comprimento-comprimento*0.2) * cos(graus), cam + incA, (comprimento-comprimento*0.2) * sin(graus),-cos(graus),0,-sin(graus)));
			
			vertices.push_back(vertex((comprimento-comprimento*0.2) * cos(graus), cam , (comprimento-comprimento*0.2) * sin(graus),-cos(graus),0,-sin(graus))); 
			vertices.push_back(vertex((comprimento-comprimento*0.2) * cos(graus + rotacao), cam, (comprimento-comprimento*0.2) * sin(graus + rotacao),-cos(graus+rotacao),0,-sin(graus+rotacao)));
			vertices.push_back(vertex((comprimento-comprimento*0.2) * cos(graus + rotacao), cam +incA, (comprimento-comprimento*0.2) * sin(graus + rotacao),-cos(graus+rotacao),0,-sin(graus+rotacao)));	
			cam = cam + incA;		//Incrementa a altura, para fazer as outras camadas;
		}
		//ANEL Superior

		//anel a volta
		//parte Superior
			vertices.push_back(vertex((comprimento/2 -comprimento*0.2)* cos(graus), comprimento*0.1, (comprimento/2 -comprimento*0.2) * sin(graus),0,1,0));
			vertices.push_back(vertex(comprimento/2 * cos(graus + rotacaoF), comprimento*0.1, comprimento/2 * sin(graus + rotacaoF),0,1,0));
			vertices.push_back(vertex(comprimento/2 * cos(graus), comprimento*0.1, comprimento/2 * sin(graus),0,1,0));

			vertices.push_back(vertex((comprimento/2 -comprimento*0.2) * cos(graus), comprimento*0.1, (comprimento/2-comprimento*0.2) * sin(graus),0,1,0));
			vertices.push_back(vertex((comprimento/2-comprimento*0.2) * cos(graus + rotacaoF), comprimento*0.1, (comprimento/2-comprimento*0.2) * sin(graus + rotacaoF),0,1,0));
			vertices.push_back(vertex(comprimento/2 * cos(graus + rotacaoF), comprimento*0.1, comprimento/2 * sin(graus + rotacaoF),0,1,0));

		//parte Inferior
			vertices.push_back(vertex((comprimento/2 -comprimento*0.2)* cos(graus), 0, (comprimento/2 -comprimento*0.2) * sin(graus),0,-1,0));
			vertices.push_back(vertex(comprimento/2 * cos(graus), 0, comprimento/2 * sin(graus),0,-1,0));
			vertices.push_back(vertex(comprimento/2 * cos(graus + rotacaoF), 0, comprimento/2 * sin(graus + rotacaoF),0,-1,0));

			vertices.push_back(vertex((comprimento/2 -comprimento*0.2) * cos(graus), 0, (comprimento/2-comprimento*0.2) * sin(graus),0,-1,0));
			vertices.push_back(vertex(comprimento/2 * cos(graus + rotacaoF), 0, comprimento/2 * sin(graus + rotacaoF),0,-1,0));
			vertices.push_back(vertex((comprimento/2-comprimento*0.2) * cos(graus + rotacaoF), 0, (comprimento/2-comprimento*0.2) * sin(graus + rotacaoF),0,-1,0));

		incA = (comprimento*0.1)/this->camadas;
		cam = 0;
		for(int i = 0; i < this->camadas; i++) {
			//Parte exterior do anel
			vertices.push_back(vertex(comprimento/2 * cos(graus), cam, comprimento/2 * sin(graus),cos(graus),0,sin(graus))); 
			vertices.push_back(vertex(comprimento/2 * cos(graus), cam + incA, comprimento/2 * sin(graus),cos(graus),0,sin(graus)));
			vertices.push_back(vertex(comprimento/2 * cos(graus + rotacao), cam + incA, comprimento/2 * sin(graus + rotacao),cos(graus+rotacao),0,sin(graus+rotacao)));
			
			vertices.push_back(vertex(comprimento/2 * cos(graus), cam , comprimento/2 * sin(graus),cos(graus),0,sin(graus))); 				
			vertices.push_back(vertex(comprimento/2 * cos(graus + rotacao), cam +incA, comprimento/2 * sin(graus + rotacao),cos(graus+rotacao),0,sin(graus+rotacao)));
			vertices.push_back(vertex(comprimento/2 * cos(graus + rotacao), cam, comprimento/2 * sin(graus + rotacao),cos(graus+rotacao),0,sin(graus+rotacao)));
			cam = cam + incA;		//Incrementa a altura, para fazer as outras camadas;
		}

		incA = (comprimento*0.1)/this->camadas;
		cam = 0;
		for(int i = 0; i < this->camadas; i++) {
			//Parte interior do anel
			vertices.push_back(vertex((comprimento/2-comprimento*0.2) * cos(graus), cam, (comprimento/2-comprimento*0.2) * sin(graus),-cos(graus),0,-sin(graus)));
			vertices.push_back(vertex((comprimento/2-comprimento*0.2) * cos(graus + rotacao), cam + incA, (comprimento/2-comprimento*0.2) * sin(graus + rotacao),-cos(graus+rotacao),0,-sin(graus+rotacao)));
			vertices.push_back(vertex((comprimento/2-comprimento*0.2) * cos(graus), cam + incA, (comprimento/2-comprimento*0.2) * sin(graus),-cos(graus),0,-sin(graus)));
			
			vertices.push_back(vertex((comprimento/2-comprimento*0.2) * cos(graus), cam , (comprimento/2-comprimento*0.2) * sin(graus),-cos(graus),0,-sin(graus))); 
			vertices.push_back(vertex((comprimento/2-comprimento*0.2) * cos(graus + rotacao), cam, (comprimento/2-comprimento*0.2) * sin(graus + rotacao),-cos(graus+rotacao),0,-sin(graus+rotacao)));
			vertices.push_back(vertex((comprimento/2-comprimento*0.2) * cos(graus + rotacao), cam +incA, (comprimento/2-comprimento*0.2) * sin(graus + rotacao),-cos(graus+rotacao),0,-sin(graus+rotacao)));
			cam = cam + incA;		//Incrementa a altura, para fazer as outras camadas;
		}
		
		graus = graus + rotacao;
	 }
	 nVertices = vertices.size();
	 glGenBuffers(1,&vbo);
	 glBindBuffer(GL_ARRAY_BUFFER,vbo);
	 glBufferData(GL_ARRAY_BUFFER,vertices.size()*sizeof(vertex), &vertices[0], GL_STATIC_DRAW);
	 
 }

 void Candeeiro::desenhaB(){
	 Cilindro *segurador, *vela[2];
	 Cubo *ferros;
	 float graus = 0;
	 //ferro segurador
	 glPushMatrix();
		glTranslatef(0.0f,0.0f,0.0f);
		segurador = new Cilindro(comprimento*0.1, altura, fatias*2, camadas,1);
		segurador->desenha();
		delete segurador;
	 glPopMatrix();

	 	//DESENHO DAS VELAS
	while (graus <= 2*M_PI){
		for(int cima = 0; cima < 2; cima ++){
		//velas de cima
			glPushMatrix();
			glTranslatef((comprimento - comprimento*0.1) * cos(graus),-altura/2 +comprimento*0.1+(altura/5)/2,(comprimento-comprimento*0.1) * sin(graus));
			vela[cima] = new Cilindro(comprimento*0.05, altura/5, fatias*2, camadas,1);
			vela[cima]->desenha();
			delete vela[cima];
			glPopMatrix();
			cima ++;
			//velas de baixo
			glPushMatrix();
			glTranslatef((comprimento/2 - comprimento*0.1) * cos(graus),comprimento*0.1+(altura/7)/2,(comprimento/2-comprimento*0.1) * sin(graus));
			vela[cima] = new Cilindro(comprimento*0.05, altura/7, fatias*2, camadas,1);
			vela[cima]->desenha();
			delete vela[cima];
			glPopMatrix();
		}
		graus = 3*(2 * M_PI/this->fatias) + graus;
	}

		 //ferros que seguram os Aneis
	 glPushMatrix();
		glTranslatef((comprimento/2-comprimento*0.05)*cos(0.0f),-altura/2+comprimento*0.05,0);
		ferros = new Cubo((comprimento-comprimento*0.3), comprimento*0.05,comprimento*0.05, fatias/2, camadas/2);
		ferros->desenha();
		delete ferros;
	glPopMatrix();

	glPushMatrix();
		glTranslatef((comprimento/4-comprimento*0.05)*cos(0.0f),comprimento*0.05,0);
		ferros = new Cubo((comprimento/2-comprimento*0.3), comprimento*0.05,comprimento*0.05, fatias/2, camadas/2);
		ferros->desenha();
		delete ferros;
	glPopMatrix();

	glPushMatrix();
		glTranslatef((-comprimento/2+comprimento*0.05)*cos(0.0f),-altura/2+comprimento*0.05,0);
		ferros = new Cubo((comprimento-comprimento*0.3), comprimento*0.05,comprimento*0.05, fatias/2, camadas/2);
		ferros->desenha();
		delete ferros;
	glPopMatrix();

	glPushMatrix();
		glTranslatef((-comprimento/4+comprimento*0.05)*cos(0.0f),comprimento*0.05,0);
		ferros = new Cubo((comprimento/2-comprimento*0.3), comprimento*0.05,comprimento*0.05, fatias/2, camadas/2);
		ferros->desenha();
		delete ferros;
	glPopMatrix();


	glPushMatrix();
		glTranslatef(0,-altura/2+comprimento*0.05,(comprimento/2)*sin(90.0f));
		ferros = new Cubo(comprimento*0.05, comprimento*0.05,(comprimento-comprimento*0.3), fatias/2, camadas/2);
		ferros->desenha();
		delete ferros;
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0,comprimento*0.05,(comprimento/4-comprimento*0.04)*sin(90.0f));
		ferros = new Cubo(comprimento*0.05, comprimento*0.05,(comprimento/2-comprimento*0.3), fatias/2, camadas/2);
		ferros->desenha();
		delete ferros;
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0,-altura/2+comprimento*0.05,(-comprimento/2)*sin(90.0f));
		ferros = new Cubo(comprimento*0.05, comprimento*0.05,(comprimento-comprimento*0.3), fatias/2, camadas/2);
		ferros->desenha();
		delete ferros;
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0,comprimento*0.05,(-comprimento/4+comprimento*0.04)*sin(90.0f));
		ferros = new Cubo(comprimento*0.05, comprimento*0.05,(comprimento/2-comprimento*0.3), fatias/2, camadas/2);
		ferros->desenha();
		delete ferros;
	glPopMatrix();

	 glBindBuffer(GL_ARRAY_BUFFER,vbo);
	 glVertexPointer(3,GL_FLOAT,sizeof(vertex),(void*)offsetof(vertex,vertices));
	 glNormalPointer(GL_FLOAT,sizeof(vertex),(void*)offsetof(vertex,normais));
	 glDrawArrays(GL_TRIANGLES,0,nVertices);
 }