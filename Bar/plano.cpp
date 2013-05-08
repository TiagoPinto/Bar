#include "includes.h"
#include "plano.h"


/**
 * Construtor da class Plano.
 * Inicializa todas as variaveis de instancia.
 *
 */
Plano::Plano(){
	this->c = 0.0f; 
	this->a = 0.0f;
	this->f = 0.0f;
	this->c = 0.0f;
	this->tri = 0;
}
/**
 * Construtor da class Plano.
 * Inicializa todas as variaveis de instancia com os valores passados por parametros.
 * @param c
 * Define o comprimento do plano
 * @param a
 * define a altura do plano
 */

Plano::Plano(float c, float a, float f, float p, int tri){
	this->c = c;
	this->a = a;
	this->f = f;
	this->p = p;
	this->tri = tri;


	std:: vector <vertex> vertice;

	//Desenha um Plano no eixo XoY;
	if(tri == 1){
		float larg = -this->a/2;
		float incrementoX = this->c/this->f;
		float incrementoY = this->a/this->p;
		for(int j = 0; j < this->p; j++){
			float comp = -this->c/2;
			for(int i = 0; i < this->f; i++){
				vertice.push_back(vertex( comp, larg, 0.0f, 0, 0, 1));
				vertice.push_back(vertex( comp + incrementoX, larg, 0.0f, 0, 0, 1));
				vertice.push_back(vertex( comp + incrementoX, larg + incrementoY, 0.0f, 0, 0, 1));
		 
				vertice.push_back(vertex( comp, larg, 0.0f, 0, 0, 1));
				vertice.push_back(vertex( comp + incrementoX, larg + incrementoY, 0.0f, 0, 0, 1));
				vertice.push_back(vertex( comp, larg + incrementoY, 0.0f, 0, 0, 1));
				comp = comp + incrementoX;
			}
			larg = larg + incrementoY;
		}
	}
	//Desenha um Plano no eixo XoZ
	if(tri==2){
		float alt = -this->a/2;
		float incrementoX = this->c/this->f;
		float incrementoZ = this->a/this->p;
		for(int j = 0; j < this->p; j++){
			float comp = -this->c/2;
			for(int i = 0; i < this->f; i++){
				vertice.push_back(vertex( comp, 0.0f, alt, 0, 1, 0));
				vertice.push_back(vertex( comp, 0.0f, alt + incrementoZ, 0, 1, 0));
				vertice.push_back(vertex( comp + incrementoX, 0.0f, alt + incrementoZ, 0, 1, 0));
				
				
				vertice.push_back(vertex( comp , 0.0f, alt, 0, 1, 0));
				vertice.push_back(vertex( comp + incrementoX, 0.0f, alt + incrementoZ, 0, 1, 0));
				vertice.push_back(vertex( comp + incrementoX, 0.0f, alt, 0, 1, 0));
				comp = comp + incrementoX;
			}
			alt = alt + incrementoZ;
		}
	}

	//Desenha um Plano no eixo YoZ
	if(tri==3){
		float alt = -this->a/2;
		float incrementoY = this->a/this->p;
		float incrementoZ = this->c/this->f;
		for(int j = 0; j < this->f; j++){
			float comp = -this->c/2;
			for(int i = 0; i < this->p; i++){
				vertice.push_back(vertex( 0.0f, alt, comp, 1, 0, 0));
				vertice.push_back(vertex( 0.0f, alt + incrementoY, comp, 1, 0, 0));
				vertice.push_back(vertex( 0.0f, alt + incrementoY, comp + incrementoZ, 1, 0, 0));

				vertice.push_back(vertex( 0.0f, alt, comp, 1, 0, 0));
				vertice.push_back(vertex( 0.0f, alt + incrementoY, comp + incrementoZ, 1, 0 , 0));
				vertice.push_back(vertex( 0.0f, alt, comp + incrementoZ, 1, 0, 0));
				alt = alt + incrementoY;
			}
		comp = comp + incrementoZ;
		}
	}
	nVertices = vertice.size();
	glGenBuffers(1,&vbo);
	glBindBuffer(GL_ARRAY_BUFFER,vbo);
	glBufferData(GL_ARRAY_BUFFER,vertice.size()*sizeof(vertex), &vertice[0], GL_STATIC_DRAW);
}

/**
 * Destrutor da class Cubo.
 *  * Destroi o VBO criado, para nao ficar alocada memoria na placa grafica	
 */
Plano::~Plano(){
	glDeleteBuffers(1,&vbo);
}	


void Plano:: desenha(){
	glBindBuffer(GL_ARRAY_BUFFER,vbo);
	glVertexPointer(3,GL_FLOAT,sizeof(vertex),(void*)offsetof(vertex,vertices));
	glNormalPointer(GL_FLOAT,sizeof(vertex),(void*)offsetof(vertex,normais));
	glDrawArrays(GL_TRIANGLES,0,nVertices);
}