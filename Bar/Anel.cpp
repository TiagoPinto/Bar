#include "includes.h"
#include "Anel.h"

Anel::Anel(float ri, float re, float altura, float f, float c,int tipo, GLuint idtex){
	this->raioI = ri;
	this->raioE = re;
	this->altura = altura;
	this->fatias = f;
	this->camadas = c;
	this->tipo = tipo;
	this->textura = idtex;

	std:: vector<vertex> vertices;

	float rotacao = 2 * M_PI/this->fatias;
	float rotacaoF = (2 * M_PI) / this->fatias;
	float graus = 0.0f;
	float incX = 1/fatias;
	float incY = 1/camadas;
	float texY = 1;
	float texX = 0;
	float texX2 = 0;
	if(tipo == 1){
	while(graus <=2* M_PI){
	//anel a volta
	//parte Superior
		vertices.push_back(vertex(raioI * cos(graus), altura/2, raioI * sin(graus), 0,1,0, texX, texY));
		vertices.push_back(vertex((raioI+raioE)* cos(graus + rotacaoF), altura/2, (raioE+raioI) * sin(graus + rotacaoF),0,1,0, texX+incX, texY-incY));
		vertices.push_back(vertex((raioE+raioI) * cos(graus), altura/2, (raioE+raioI) * sin(graus),0,1,0,texX, texY-incY));

		vertices.push_back(vertex(raioI * cos(graus), altura/2, raioI * sin(graus),0,1,0, texX, texY));
		vertices.push_back(vertex((raioI) * cos(graus + rotacaoF), altura/2, (raioI) * sin(graus + rotacaoF),0,1,0, texX+incX, texY));
		vertices.push_back(vertex((raioE+raioI) * cos(graus + rotacaoF), altura/2, (raioE+raioI) * sin(graus + rotacaoF),0,1,0, texX+incX, texY+incY));

	//parte Inferior
		vertices.push_back(vertex(raioI* cos(graus), -altura/2, raioI * sin(graus),0,-1,0, texX, texY));
		vertices.push_back(vertex((raioE+raioI) * cos(graus), -altura/2, (raioE+raioI) * sin(graus),0,-1,0, texX, texY - incY));
		vertices.push_back(vertex((raioE+raioI) * cos(graus + rotacaoF), -altura/2, (raioE+raioI) * sin(graus + rotacaoF),0,-1,0, texX + incX, texY - incY));
			

		vertices.push_back(vertex((raioI) * cos(graus), -altura/2, (raioI) * sin(graus),0,-1,0, texX, texY));
		vertices.push_back(vertex((raioE+raioI) * cos(graus + rotacaoF), -altura/2, (raioE+raioI) * sin(graus + rotacaoF),0,-1,0, texX + incX, texY - incX));
		vertices.push_back(vertex((raioI) * cos(graus + rotacaoF), -altura/2, (raioI) * sin(graus + rotacaoF),0,-1,0, texX + incX, texY));		

		float incA = altura/this->camadas;
		float cam = -this->altura/2;
		for(int i = 0; i < this->camadas; i++) {
			//Parte exterior do anel
			vertices.push_back(vertex((raioE+raioI) * cos(graus), cam, (raioE+raioI) * sin(graus),cos(graus),0,sin(graus), texX2, texY)); 
			vertices.push_back(vertex((raioE+raioI) * cos(graus), cam + incA, (raioE+raioI) * sin(graus),cos(graus),0,sin(graus), texX2, texY-incY));
			vertices.push_back(vertex((raioE+raioI) * cos(graus + rotacao), cam + incA, (raioE+raioI) * sin(graus + rotacao),cos(graus+rotacao),0,sin(graus+rotacao), texX2+incX, texY - incY));
			
			vertices.push_back(vertex((raioE+raioI) * cos(graus), cam , (raioE+raioI) * sin(graus),cos(graus),0,sin(graus), texX2, texY)); 				
			vertices.push_back(vertex((raioE+raioI) * cos(graus + rotacao), cam +incA, (raioE+raioI) * sin(graus + rotacao),cos(graus+rotacao),0,sin(graus+rotacao), texX2 + incX, texY - incY));
			vertices.push_back(vertex((raioE+raioI) * cos(graus + rotacao), cam, (raioE+raioI) * sin(graus + rotacao),cos(graus+rotacao),0,sin(graus+rotacao), texX2 + incX, texY));
			cam = cam + incA;		//Incrementa a altura, para fazer as outras camadas;
			texX2 = texX2 + incX;
		}
		incA = altura/this->camadas;
		cam = -this->altura/2;
		for(int i = 0; i < this->camadas; i++) {
			//Parte interior do anel
			vertices.push_back(vertex(raioI * cos(graus), cam, raioI * sin(graus),-cos(graus),0,-sin(graus), texX2, texY)); 
			vertices.push_back(vertex(raioI * cos(graus + rotacao), cam + incA, raioI * sin(graus + rotacao),-cos(graus+rotacao),0,-sin(graus+rotacao), texX2 + incX, texY - incY));
			vertices.push_back(vertex(raioI * cos(graus), cam + incA, raioI * sin(graus),-cos(graus),0,-sin(graus), texX2, texY - incY));
			
			vertices.push_back(vertex(raioI * cos(graus), cam , raioI * sin(graus),-cos(graus),0,-sin(graus), texX2, texY)); 
			vertices.push_back(vertex(raioI * cos(graus + rotacao), cam, raioI * sin(graus + rotacao),-cos(graus+rotacao),0,-sin(graus+rotacao), texX2 + incX, texY));
			vertices.push_back(vertex(raioI * cos(graus + rotacao), cam +incA, raioI * sin(graus + rotacao),-cos(graus+rotacao),0,-sin(graus+rotacao), texX2 + incX, texY - incY));	
			cam = cam + incA;		//Incrementa a altura, para fazer as outras camadas;
		}			
		graus = graus + rotacao;
		texY = texY - incY;
		texX = texX + incX;
	}
	}
	if(tipo == 2){
	graus = 0.0f;
	texY = 1;
	texX = 0;
	texX2 = 0;
	while(graus <=M_PI/2){
	//anel a volta
	//parte Superior
		vertices.push_back(vertex(raioI * cos(graus), altura/2, raioI * sin(graus), 0,1,0, texX, texY));
		vertices.push_back(vertex((raioI+raioE)* cos(graus + rotacaoF), altura/2, (raioE+raioI) * sin(graus + rotacaoF),0,1,0, texX+incX, texY-incY));
		vertices.push_back(vertex((raioE+raioI) * cos(graus), altura/2, (raioE+raioI) * sin(graus),0,1,0,texX, texY-incY));

		vertices.push_back(vertex(raioI * cos(graus), altura/2, raioI * sin(graus),0,1,0, texX, texY));
		vertices.push_back(vertex((raioI) * cos(graus + rotacaoF), altura/2, (raioI) * sin(graus + rotacaoF),0,1,0, texX+incX, texY));
		vertices.push_back(vertex((raioE+raioI) * cos(graus + rotacaoF), altura/2, (raioE+raioI) * sin(graus + rotacaoF),0,1,0, texX+incX, texY+incY));

	//parte Inferior
		vertices.push_back(vertex(raioI* cos(graus), -altura/2, raioI * sin(graus),0,-1,0, texX, texY));
		vertices.push_back(vertex((raioE+raioI) * cos(graus), -altura/2, (raioE+raioI) * sin(graus),0,-1,0, texX, texY - incY));
		vertices.push_back(vertex((raioE+raioI) * cos(graus + rotacaoF), -altura/2, (raioE+raioI) * sin(graus + rotacaoF),0,-1,0, texX + incX, texY - incY));
			

		vertices.push_back(vertex((raioI) * cos(graus), -altura/2, (raioI) * sin(graus),0,-1,0, texX, texY));
		vertices.push_back(vertex((raioE+raioI) * cos(graus + rotacaoF), -altura/2, (raioE+raioI) * sin(graus + rotacaoF),0,-1,0, texX + incX, texY - incX));
		vertices.push_back(vertex((raioI) * cos(graus + rotacaoF), -altura/2, (raioI) * sin(graus + rotacaoF),0,-1,0, texX + incX, texY));		

		float incA = altura/this->camadas;
		float cam = -this->altura/2;
		for(int i = 0; i < this->camadas; i++) {
			//Parte exterior do anel
			vertices.push_back(vertex((raioE+raioI) * cos(graus), cam, (raioE+raioI) * sin(graus),cos(graus),0,sin(graus), texX2, texY)); 
			vertices.push_back(vertex((raioE+raioI) * cos(graus), cam + incA, (raioE+raioI) * sin(graus),cos(graus),0,sin(graus), texX2, texY-incY));
			vertices.push_back(vertex((raioE+raioI) * cos(graus + rotacao), cam + incA, (raioE+raioI) * sin(graus + rotacao),cos(graus+rotacao),0,sin(graus+rotacao), texX2+incX, texY - incY));
			
			vertices.push_back(vertex((raioE+raioI) * cos(graus), cam , (raioE+raioI) * sin(graus),cos(graus),0,sin(graus), texX2, texY)); 				
			vertices.push_back(vertex((raioE+raioI) * cos(graus + rotacao), cam +incA, (raioE+raioI) * sin(graus + rotacao),cos(graus+rotacao),0,sin(graus+rotacao), texX2 + incX, texY - incY));
			vertices.push_back(vertex((raioE+raioI) * cos(graus + rotacao), cam, (raioE+raioI) * sin(graus + rotacao),cos(graus+rotacao),0,sin(graus+rotacao), texX2 + incX, texY));
			cam = cam + incA;		//Incrementa a altura, para fazer as outras camadas;
			texX2 = texX2 + incX;
		}
		incA = altura/this->camadas;
		cam = -this->altura/2;
		for(int i = 0; i < this->camadas; i++) {
			//Parte interior do anel
			vertices.push_back(vertex(raioI * cos(graus), cam, raioI * sin(graus),-cos(graus),0,-sin(graus), texX2, texY)); 
			vertices.push_back(vertex(raioI * cos(graus + rotacao), cam + incA, raioI * sin(graus + rotacao),-cos(graus+rotacao),0,-sin(graus+rotacao), texX2 + incX, texY - incY));
			vertices.push_back(vertex(raioI * cos(graus), cam + incA, raioI * sin(graus),-cos(graus),0,-sin(graus), texX2, texY - incY));
			
			vertices.push_back(vertex(raioI * cos(graus), cam , raioI * sin(graus),-cos(graus),0,-sin(graus), texX2, texY)); 
			vertices.push_back(vertex(raioI * cos(graus + rotacao), cam, raioI * sin(graus + rotacao),-cos(graus+rotacao),0,-sin(graus+rotacao), texX2 + incX, texY));
			vertices.push_back(vertex(raioI * cos(graus + rotacao), cam +incA, raioI * sin(graus + rotacao),-cos(graus+rotacao),0,-sin(graus+rotacao), texX2 + incX, texY - incY));	
			cam = cam + incA;		//Incrementa a altura, para fazer as outras camadas;
		}			
		graus = graus + rotacao;
		texY = texY - incY;
		texX = texX + incX;
	}
	}
	nVertices = vertices.size();
	glGenBuffers(1,&vbo);
	glBindBuffer(GL_ARRAY_BUFFER,vbo);
	glBufferData(GL_ARRAY_BUFFER,vertices.size()*sizeof(vertex), &vertices[0], GL_STATIC_DRAW);
}

void Anel::desenha(){
	glBindBuffer(GL_ARRAY_BUFFER,vbo);
	glBindTexture(GL_TEXTURE_2D,textura);
	glVertexPointer(3,GL_FLOAT,sizeof(vertex),(void*)offsetof(vertex,vertices));
	glNormalPointer(GL_FLOAT,sizeof(vertex),(void*)offsetof(vertex,normais));
	glTexCoordPointer(2,GL_FLOAT,sizeof(vertex),(void*)offsetof(vertex,texturas));
	glPushMatrix();
	glMatrixMode(GL_TEXTURE);
	glScalef(2,2,0);
	glPopMatrix();
	glDrawArrays(GL_TRIANGLES,0,nVertices);
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

/**
 * Destrutor da class Anel.
 * Destroi o VBO criado, para nao ficar alocada memoria na placa grafica	
 */
Anel::~Anel(){
	glDeleteBuffers(1,&vbo);
}