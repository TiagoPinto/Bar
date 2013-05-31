#include "includes.h"
#include "cilindro.h"

/**
 * Construtor da class Cilindro.
 * Inicializa todas as variaveis de instancia.
 *
 */
Cilindro::Cilindro(){
	this->raio = 0.0;
	this->altura = 0.0;
	this->fatias = 0.0;
	this->camadas = 0.0;
}

float Cilindro::getAltura(){
	return this->altura;
}

/**
 * Construtor da class Cilindro.
 * Inicializa as variaveis de raio do cilindro.
 *@param r
 * 	 Variavel que especifica o raio do cilindro	
 *@param a
 * 	 Variavel que especifica a altura do cilindro
  *@param f
 * 	 Variavel que especifica as fatias do cilindro
  *@param c
 * 	 Variavel que especifica as camadas do cilindro
 */

Cilindro::Cilindro(float r, float a,float f, float c, int t, GLuint idTextura){
	this->raio = r;
	this->altura = a;
	this->fatias = f; 
	this->camadas = c;
	this->tipo = t;
	this->textura = idTextura;

	std::vector <vertex> vertices;
	float texX = 0;
	float inctexX = 1/fatias;
	float inctexY = 1/camadas;
	float rotacaotex = M_PI/fatias;
	if(tipo == 1){
		float rotacao = 2 * M_PI/this->fatias;
		float graus = 0;
		
		while(graus <= 2 * M_PI){
			//Base Topo
			vertices.push_back(vertex(0.0f, altura/2, 0.0f,0,1,0, 0.5, 0.5));
			vertices.push_back(vertex(raio * cos(graus + rotacao), altura/2, raio * sin(graus + rotacao),0,1,0, 1, 1));
			vertices.push_back(vertex(raio * cos(graus), altura/2, raio * sin(graus),0,1,0, 1, 0));
			//Base Baixo
			vertices.push_back(vertex(0.0f, -altura/2, 0.0f,0,-1,0,0.5,0.5));
			vertices.push_back(vertex(raio * cos(graus), -altura/2, raio * sin(graus),0,-1,0, 1, 0));
			vertices.push_back(vertex(raio * cos(graus + rotacao), -altura/2, raio * sin(graus + rotacao),0,-1,0, 1, 1));
	
			//Lado
			float incA = this->altura/this->camadas;
			float cam = -this->altura/2;
			float texY = 1;
			for(int i = 0; i < this->camadas; i++) {
				vertices.push_back(vertex(raio * cos(graus), cam, raio * sin(graus),cos(graus),0,sin(graus),texX, texY ));
				vertices.push_back(vertex(raio * cos(graus), cam + incA, raio * sin(graus),cos(graus),0,sin(graus), texX, texY - inctexY));
				vertices.push_back(vertex(raio * cos(graus + rotacao), cam + incA, raio * sin(graus + rotacao),cos(graus+rotacao),0,sin(graus+rotacao), texX+inctexX, texY - inctexY));
				
				vertices.push_back(vertex(raio * cos(graus), cam , raio * sin(graus),cos(graus),0,sin(graus), texX, texY));
				vertices.push_back(vertex(raio * cos(graus + rotacao), cam +incA, raio * sin(graus + rotacao),cos(graus+rotacao),0,sin(graus+rotacao), texX + inctexX, texY - inctexY));
				vertices.push_back(vertex(raio * cos(graus + rotacao), cam, raio * sin(graus + rotacao),cos(graus+rotacao),0,sin(graus+rotacao), texX + inctexX, texY));
				cam = cam + incA;		//Incrementa a altura, para fazer as outras camadas;
				texY = texY - inctexY;
			}
			graus = graus + rotacao;
			texX = texX + inctexX;
		}
	}
	 //Desenha metade de um cilindro de no constructor passar o parametro 2
	if (tipo == 2){
		float rotacao = M_PI/fatias;
		float graus = 0;
		while(graus <= M_PI){
			//Base Topo
			vertices.push_back(vertex(0.0f, altura/2, 0.0f,0,1,0,0.5,0.5));
			vertices.push_back(vertex(raio * cos(graus + rotacao), altura/2, raio * sin(graus + rotacao),0,1,0,1,1));
			vertices.push_back(vertex(raio * cos(graus), altura/2, raio * sin(graus),0,1,0,1,0));
			//Base Baixo
			vertices.push_back(vertex(0.0f, -altura/2, 0.0f,0,-1,0,0.5,0.5));
			vertices.push_back(vertex(raio * cos(graus), -altura/2, raio * sin(graus),0,-1,0, 1, 0));
			vertices.push_back(vertex(raio * cos(graus + rotacao), -altura/2, raio * sin(graus + rotacao),0,-1,0, 1, 1));
		
			//Lado
			float incA = altura/camadas;
			float cam = -altura/2;
			float texY = 1;
			for(int i = 0; i < this->camadas; i++) {
				vertices.push_back(vertex(raio * cos(graus), cam, raio * sin(graus),cos(graus),0,sin(graus),texX, texY ));
				vertices.push_back(vertex(raio * cos(graus), cam + incA, raio * sin(graus),cos(graus),0,sin(graus), texX, texY - inctexY));
				vertices.push_back(vertex(raio * cos(graus + rotacao), cam + incA, raio * sin(graus + rotacao),cos(graus+rotacao),0,sin(graus+rotacao), texX+inctexX, texY - inctexY));
				
				vertices.push_back(vertex(raio * cos(graus), cam , raio * sin(graus),cos(graus),0,sin(graus), texX, texY));
				vertices.push_back(vertex(raio * cos(graus + rotacao), cam +incA, raio * sin(graus + rotacao),cos(graus+rotacao),0,sin(graus+rotacao), texX + inctexX, texY - inctexY));
				vertices.push_back(vertex(raio * cos(graus + rotacao), cam, raio * sin(graus + rotacao),cos(graus+rotacao),0,sin(graus+rotacao), texX + inctexX, texY));
				cam = cam + incA;		//Incrementa a altura, para fazer as outras camadas;
				texY = texY - inctexY;
			}
			graus = graus + rotacao;
			texX = texX + inctexX;
		}
	}
	nVertices = vertices.size();
	glGenBuffers(1,&vbo);
	glBindBuffer(GL_ARRAY_BUFFER,vbo);
	glBufferData(GL_ARRAY_BUFFER,vertices.size()*sizeof(vertex), &vertices[0], GL_STATIC_DRAW);
}

/**
 * Destrutor da class Cilindro.
 * Destroi o VBO criado, para nao ficar alocada memoria na placa grafica	
 */
Cilindro::~Cilindro(){
	glDeleteBuffers(1,&vbo);
}

/**
 * Método que desenha um cilindro com os parametros definido
 * previamente no construtor
 */
void Cilindro::desenha(){
	glBindBuffer(GL_ARRAY_BUFFER,vbo);
	glBindTexture(GL_TEXTURE_2D,textura);
	glVertexPointer(3,GL_FLOAT,sizeof(vertex),(void*)offsetof(vertex,vertices));
	glNormalPointer(GL_FLOAT,sizeof(vertex),(void*)offsetof(vertex,normais));
	glTexCoordPointer(2,GL_FLOAT,sizeof(vertex),(void*)offsetof(vertex,texturas));
	glPushMatrix();
	glMatrixMode(GL_TEXTURE);
	//glScalef(raio,,0);
	glPopMatrix();
	glDrawArrays(GL_TRIANGLES,0,nVertices);
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}