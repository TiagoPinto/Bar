#include "includes.h"
#include "plano.h"

struct vertex{
	float vertices[3];
	float texturas[2];
	float normais[3];

	vertex(float x,float y, float z, float nx = 0, float ny = 0, float nz = 0, float tt = 0, float ts = 0){
		vertices[0] = x;
		vertices[1] = y;
		vertices[2] = z;
		normais[0] = nx;
		normais[1] = ny;
		normais[2] = nz;
		texturas[0] = tt;
		texturas[1] = ts;
	}
};


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


	std::vector <vertex> vertices;

	//Desenha um Plano no eixo XoY;
	if(tri == 1){
		float larg = -this->a/2;
		float incrementoX = this->c/this->f;
		float incrementoY = this->a/this->p;
		for(int j = 0; j < this->p; j++){
			float comp = -this->c/2;
			for(int i = 0; i < this->f; i++){
				vertices.push_back(vertex( comp, larg, 0.0f ));
				vertices.push_back(vertex( comp + incrementoX, larg, 0.0f ));
				vertices.push_back(vertex( comp + incrementoX, larg + incrementoY, 0.0f ));
		 
				vertices.push_back(vertex( comp, larg, 0.0f ));
				vertices.push_back(vertex( comp + incrementoX, larg + incrementoY, 0.0f ));
				vertices.push_back(vertex( comp, larg + incrementoY, 0.0f ));
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
				vertices.push_back(vertex( comp, 0.0f, alt ));
				vertices.push_back(vertex( comp, 0.0f, alt + incrementoZ ));
				vertices.push_back(vertex( comp + incrementoX, 0.0f, alt + incrementoZ ));
				
				
				vertices.push_back(vertex( comp , 0.0f, alt ));
				vertices.push_back(vertex( comp + incrementoX, 0.0f, alt + incrementoZ ));
				vertices.push_back(vertex( comp + incrementoX, 0.0f, alt ));
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
				vertices.push_back(vertex( 0.0f, alt, comp ));
				vertices.push_back(vertex( 0.0f, alt + incrementoY, comp));
				vertices.push_back(vertex( 0.0f, alt + incrementoY, comp + incrementoZ ));

				vertices.push_back(vertex( 0.0f, alt, comp ));
				vertices.push_back(vertex( 0.0f, alt + incrementoY, comp + incrementoZ ));
				vertices.push_back(vertex( 0.0f, alt, comp + incrementoZ ));
				alt = alt + incrementoY;
			}
		comp = comp + incrementoZ;
		}
	}
	nVertices = vertices.size();
	glGenBuffers(1,&vbo);
	glBindBuffer(GL_ARRAY_BUFFER,vbo);
	glBufferData(GL_ARRAY_BUFFER,vertices.size()*sizeof(vertex), &vertices[0], GL_STATIC_DRAW);
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
	glDrawArrays(GL_TRIANGLES,0,nVertices);
}