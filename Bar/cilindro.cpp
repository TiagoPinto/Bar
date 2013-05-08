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

Cilindro::Cilindro(float r, float a,float f, float c, int t){
	this->raio = r;
	this->altura = a;
	this->fatias = f; 
	this->camadas = c;
	this->tipo = t;

	std::vector <vertex> vertices;

	if(tipo == 1){
		float rotacao = 2 * M_PI/this->fatias;
		float graus = 0;
		while(graus <= 2 * M_PI){
			//Base Topo
			vertices.push_back(vertex(0.0f, altura/2, 0.0f,0,0,0));
			vertices.push_back(vertex(raio * cos(graus + rotacao), altura/2, raio * sin(graus + rotacao),0,0,0));
			vertices.push_back(vertex(raio * cos(graus), altura/2, raio * sin(graus),0,0,0));
			//Base Baixo
			vertices.push_back(vertex(0.0f, -altura/2, 0.0f,0,0,0));
			vertices.push_back(vertex(raio * cos(graus), -altura/2, raio * sin(graus),0,0,0));
			vertices.push_back(vertex(raio * cos(graus + rotacao), -altura/2, raio * sin(graus + rotacao),0,0,0));
	
			//Lado
			float incA = this->altura/this->camadas;
			float cam = -this->altura/2;
			for(int i = 0; i < this->camadas; i++) {
				vertices.push_back(vertex(raio * cos(graus), cam, raio * sin(graus),0,0,0)); 
				vertices.push_back(vertex(raio * cos(graus), cam + incA, raio * sin(graus),0,0,0));
				vertices.push_back(vertex(raio * cos(graus + rotacao), cam + incA, raio * sin(graus + rotacao),0,0,0));
				
				vertices.push_back(vertex(raio * cos(graus), cam , raio * sin(graus),0,0,0)); 				
				vertices.push_back(vertex(raio * cos(graus + rotacao), cam +incA, raio * sin(graus + rotacao),0,0,0));
				vertices.push_back(vertex(raio * cos(graus + rotacao), cam, raio * sin(graus + rotacao),0,0,0));
				cam = cam + incA;		//Incrementa a altura, para fazer as outras camadas;
			}
			graus = graus + rotacao;
		}
	}
	 //Desenha metade de um cilindro de no constructor passar o parametro 2
	if (tipo == 2){
		float rotacao = M_PI/fatias;
		float graus = 0;
		while(graus <= M_PI){
			//Base Topo
			vertices.push_back(vertex(0.0f, altura/2, 0.0f,0,0,0));
			vertices.push_back(vertex(raio * cos(graus + rotacao), altura/2, raio * sin(graus + rotacao),0,0,0));
			vertices.push_back(vertex(raio * cos(graus), altura/2, raio * sin(graus),0,0,0));
			//Base Baixo
			vertices.push_back(vertex(0.0f, -altura/2, 0.0f,0,0,0));
			vertices.push_back(vertex(raio * cos(graus), -altura/2, raio * sin(graus),0,0,0));
			vertices.push_back(vertex(raio * cos(graus + rotacao), -altura/2, raio * sin(graus + rotacao),0,0,0));
		
			//Lado
			float incA = altura/camadas;
			float cam = -altura/2;
			for(int i = 0; i < camadas; i++) {
				vertices.push_back(vertex(raio * cos(graus), cam, raio * sin(graus),0,0,0)); 
				vertices.push_back(vertex(raio * cos(graus), cam + incA, raio * sin(graus),0,0,0));
				vertices.push_back(vertex(raio * cos(graus + rotacao), cam + incA, raio * sin(graus + rotacao),0,0,0));
				
				vertices.push_back(vertex(raio * cos(graus), cam , raio * sin(graus),0,0,0)); 				
				vertices.push_back(vertex(raio * cos(graus + rotacao), cam +incA, raio * sin(graus + rotacao),0,0,0));
				vertices.push_back(vertex(raio * cos(graus + rotacao), cam, raio * sin(graus + rotacao),0,0,0));
				cam = cam + incA;		//Incrementa a altura, para fazer as outras camadas;
			}
			graus = graus + rotacao;
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
	glVertexPointer(3,GL_FLOAT,sizeof(vertex),(void*)offsetof(vertex,vertices));
	glDrawArrays(GL_TRIANGLES,0,nVertices);
}