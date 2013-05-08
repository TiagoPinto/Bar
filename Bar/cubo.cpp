#include "includes.h"
#include "cubo.h"



/**
 * Construtor da class Cubo.
 * Inicializa as variaveis de comprimento, altura, largura fatias, e camadas.	
 */
Cubo::Cubo(){
	this->c = 0.0f;
	this->l = 0.0f;
	this->a = 0.0f;
	this->f = 0.0f;
	this->p = 0.0f;
}

/**
 * Destrutor da class Cubo.
 * Destroi o VBO criado, para nao ficar alocada memoria na placa grafica	
 */
Cubo::~Cubo(){
	glDeleteBuffers(1,&vbo);
}

/**
 * Construtor da class Cubo.
 * Inicializa as variaveis de comprimento, altura, largura, fatias e camdas de um paralelipipedo.
 *@param c
 * 	 Variavel que especifica o comprimento do paralelipipedo	
 *@param l
 * 	 Variavel que especifica o largura do paralelipipedo	
 *@param a
 * 	 Variavel que especifica o altura do paralelipipedo	
  *@param f
 * 	 Variavel que especifica o numero de fatias do paralelipipedo
  *@param p
 * 	 Variavel que especifica o numero de camadas do paralelipipedo
 *		
 */

Cubo::Cubo(float c,float a,float l, float f, float p){
	this->c = c;
	this->a = a;
	this->l = l;
	this->f = f;
	this->p = p;

	std::vector <vertex> vertices;

	//Variaveis Iniciais para comecar a desenhar 
	float alt = -this->a/2;
	float comp = -this->c/2;
	//Incrementos dependendo das fatias ou camadas
	//Variaveis para a Face de Cima, Baixo, Frente e Tras
	float incrementoX = this->c/this->p;
	float incrementoY = this->a/this->f;
	float incrementoZ = this->l/this->p;
	//Variaveis para a Face Lateral Direita e Esquerda
	float incY = this->a/this->f;
	float incZ = this->l/this->p;

	//Primeiro Ciclo para as fatias, Segundo para as Camadas
	for(int j = 0; j < this->f; j++){
		float comp = -this->c/2;
		for(int i = 0; i < this->p; i++){
			//Face Frontal Triangulo
			vertices.push_back(vertex(comp,alt,l/2,0,0,1));
			vertices.push_back(vertex(comp + incrementoX, alt + incrementoY, l/2,0,0,1));
			vertices.push_back(vertex(comp, alt + incrementoY, l/2,0,0,1));

			vertices.push_back(vertex(comp, alt, l/2,0,0,1));
			vertices.push_back(vertex(comp + incrementoX, alt, l/2,0,0,1));
			vertices.push_back(vertex(comp + incrementoX, alt + incrementoY, l/2,0,0,1)); 

			//Face Traseira Triangulo
			vertices.push_back(vertex(comp, alt, -l/2,0,0,-1));
			vertices.push_back(vertex(comp, alt + incrementoY, -l/2,0,0,-1));
			vertices.push_back(vertex(comp + incrementoX, alt + incrementoY, -l/2,0,0,-1));

			vertices.push_back(vertex(comp, alt, -l/2,0,0,-1));
			vertices.push_back(vertex(comp + incrementoX, alt + incrementoY, -l/2,0,0,-1));
			vertices.push_back(vertex(comp + incrementoX, alt , -l/2,0,0,-1));
			comp = comp + incrementoX;
		}
		alt = alt + incrementoY;
	}

	alt = -this->a/2;
	for(int i = 0; i < this->f; i++){
		float larg = -this->l/2;
		for(int i = 0; i < this->p; i++){
			//Face Lateral Direita
			vertices.push_back(vertex(c/2,alt,larg,1,0,0));
			vertices.push_back(vertex(c/2,alt + incY, larg,1,0,0));
			vertices.push_back(vertex(c/2, alt + incY,larg + incZ,1,0,0));

			vertices.push_back(vertex(c/2, alt, larg,1,0,0));
			vertices.push_back(vertex(c/2, alt + incY, larg + incZ,1,0,0));
			vertices.push_back(vertex(c/2, alt, larg + incZ,1,0,0));

			//Face Lateral Esquerda
			vertices.push_back(vertex(-c/2,alt,larg,-1,0,0));
			vertices.push_back(vertex(-c/2, alt + incY, larg + incZ,-1,0,0));
			vertices.push_back(vertex(-c/2,alt + incY, larg,-1,0,0));			

			vertices.push_back(vertex(-c/2, alt, larg,-1,0,0));
			vertices.push_back(vertex(-c/2, alt, larg + incZ,-1,0,0));
			vertices.push_back(vertex(-c/2, alt + incY, larg + incZ,-1,0,0));
				
			larg = larg + incZ;
		}
		alt = alt + incY;
	}

	incrementoX = this->c/this->f;
	for(int z = 0; z < this->f; z++){
		float larg = -this->l/2;
		for(int x = 0; x < this->p; x++){
			//Face de Cima
			vertices.push_back(vertex(comp, a/2, larg,0,1,0));
			vertices.push_back(vertex(comp, a/2, larg + incrementoZ,0,1,0));
			vertices.push_back(vertex(comp + incrementoX, a/2, larg + incrementoZ,0,1,0));

			vertices.push_back(vertex(comp, a/2, larg,0,1,0));
			vertices.push_back(vertex(comp + incrementoX, a/2, larg + incrementoZ,0,1,0));
			vertices.push_back(vertex(comp + incrementoX, a/2, larg,0,1,0));

			//Face de Baixo
			vertices.push_back(vertex(comp, -a/2, larg,0,-1,0));
			vertices.push_back(vertex(comp + incrementoX, -a/2, larg + incrementoZ,0,-1,0));
			vertices.push_back(vertex(comp, -a/2, larg + incrementoZ,0,-1,0));			

			vertices.push_back(vertex(comp, -a/2, larg,0,-1,0));
			vertices.push_back(vertex(comp + incrementoX, -a/2, larg,0,-1,0));
			vertices.push_back(vertex(comp + incrementoX, -a/2, larg + incrementoZ,0,-1,0));
			larg = larg + incrementoZ;
		}
		comp = comp + incrementoX;
	}
	nVertices = vertices.size();
	glGenBuffers(1,&vbo);
	glBindBuffer(GL_ARRAY_BUFFER,vbo);
	glBufferData(GL_ARRAY_BUFFER,vertices.size()*sizeof(vertex), &vertices[0], GL_STATIC_DRAW);
}

/**
 * Desenha um cubo, com as dimensoes definidas no construtor
 *		
 */

void Cubo::desenha(){
	glBindBuffer(GL_ARRAY_BUFFER,vbo);
	glVertexPointer(3,GL_FLOAT,sizeof(vertex),(void*)offsetof(vertex,vertices));
	glNormalPointer(GL_FLOAT,sizeof(vertex),(void*)offsetof(vertex,normais));
	glDrawArrays(GL_TRIANGLES,0,nVertices);
}