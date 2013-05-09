#include "includes.h"
#include "torus.h"

/**
 * Construtor da class Torus.
 * Inicializa todas as variaveis de instancia.
 *
 */
Torus::Torus(){
	this->raioI = 0.0;
	this->raioE = 0.0;
	this->fatias = 0.0;
	this->camadas = 0.0;
	this->tipo = 0;
}

/**
 * Construtor da class Torus.
 * Inicializa as variaveis de instancia do torus.
 *@param ri
 * 	 Variavel que especifica o raio Interior do torus	
 *@param re
 * 	 Variavel que especifica o raio Exterior do torus
  *@param f
 * 	 Variavel que especifica as fatias do torus
  *@param c
 * 	 Variavel que especifica as camadas do torus
 */

Torus::Torus(float ri, float re, float f, float c, int t){
	this->raioI = ri;
	this->raioE = re;
	this->fatias = f; 
	this->camadas = c;
	this->tipo = t;

	std:: vector <vertex> vertices;

	if(tipo == 1){
		float incR = 2 * M_PI / fatias;
		float incA = M_PI / (camadas);
		float grausA = -M_PI;
		float grausE = -M_PI/2;
		float somatorio = raioE * cos(grausE);
		float somatorio2 = raioE * cos(grausE + incA);
		for(int a = 0; a < camadas; a++){
			float grausR = 0.0f;
			for(int l = 0; l < fatias; l++){
				vertices.push_back(vertex((raioI + raioE + somatorio) * cos(grausR), raioE * cos(grausA), (raioI + raioE + somatorio) * sin(grausR),cos(grausR),cos(grausA),sin(grausR))); 
				vertices.push_back(vertex((raioI + raioE + somatorio2)  * cos(grausR), raioE * cos(grausA + incA), (raioI + raioE + somatorio2) * sin(grausR),cos(grausR),cos(grausA+incA),sin(grausR)));
				vertices.push_back(vertex((raioI + raioE + somatorio2) * cos(grausR + incR), raioE * cos(grausA + incA), (raioI + raioE + somatorio2) * sin(grausR + incR),cos(grausR+incR),cos(grausA+incA),sin(grausR+incR)));

				vertices.push_back(vertex((raioI + raioE + somatorio) * cos(grausR), raioE * cos(grausA), (raioI + raioE + somatorio) * sin(grausR),cos(grausR),cos(grausA),sin(grausR))); 
				vertices.push_back(vertex((raioI + raioE + somatorio2) * cos(grausR + incR), raioE * cos(grausA + incA), (raioI + raioE + somatorio2) * sin(grausR + incR),cos(grausR+incR),cos(grausA+incA),sin(grausR+incR)));
				vertices.push_back(vertex((raioI + raioE + somatorio)  * cos(grausR + incR), raioE * cos(grausA), (raioI + raioE + somatorio) * sin(grausR + incR),cos(grausR+incR),cos(grausA),sin(grausR+incR)));
			
				vertices.push_back(vertex((raioI + raioE - somatorio) * cos(grausR), raioE * cos(grausA), (raioI + raioE - somatorio) * sin(grausR),-cos(grausR),cos(grausA),-sin(grausR)));
				vertices.push_back(vertex((raioI + raioE - somatorio2) * cos(grausR + incR), raioE * cos(grausA + incA), (raioI + raioE - somatorio2) * sin(grausR + incR),-cos(grausR+incR),cos(grausA+incA),-sin(grausR+incR)));
				vertices.push_back(vertex((raioI + raioE - somatorio2)  * cos(grausR), raioE * cos(grausA + incA), (raioI + raioE - somatorio2) * sin(grausR),-cos(grausR),cos(grausA+incA),-sin(grausR)));
			
				vertices.push_back(vertex((raioI + raioE - somatorio) * cos(grausR), raioE * cos(grausA), (raioI + raioE - somatorio) * sin(grausR),-cos(grausR),cos(grausA),-sin(grausR))); 
				vertices.push_back(vertex((raioI + raioE - somatorio) * cos(grausR + incR), raioE * cos(grausA), (raioI + raioE - somatorio) * sin(grausR + incR),-cos(grausR+incR),cos(grausA),-sin(grausR+incR)));
				vertices.push_back(vertex((raioI + raioE - somatorio2)  * cos(grausR + incR), raioE * cos(grausA + incA), (raioI + raioE - somatorio2) * sin(grausR + incR),-cos(grausR+incR),cos(grausA+incA),-sin(grausR+incR)));
				grausR = grausR + incR;
			}
			grausA = grausA + incA;
			grausE = grausE + incA;
			somatorio = raioE * cos(grausE);
			somatorio2 = raioE * cos(grausE + incA);		
		}
	}

	//Desenha Metade de um torus
	if(tipo == 2){
		float incR = M_PI / fatias;
		float incA = M_PI / (camadas);
		float grausA = -M_PI;
		float grausE = -M_PI/2;
		float somatorio = raioE * cos(grausE);
		float somatorio2 = raioE * cos(grausE + incA);
		for(int a = 0; a < camadas; a++){
			float grausR = 0.0f;
			for(int l = 0; l < fatias; l++){
				vertices.push_back(vertex((raioI + raioE + somatorio) * cos(grausR), raioE * cos(grausA), (raioI + raioE + somatorio) * sin(grausR),cos(grausR),cos(grausA),sin(grausR))); 
				vertices.push_back(vertex((raioI + raioE + somatorio2)  * cos(grausR), raioE * cos(grausA + incA), (raioI + raioE + somatorio2) * sin(grausR),cos(grausR),cos(grausA+incA),sin(grausR)));
				vertices.push_back(vertex((raioI + raioE + somatorio2) * cos(grausR + incR), raioE * cos(grausA + incA), (raioI + raioE + somatorio2) * sin(grausR + incR),cos(grausR+incR),cos(grausA+incA),sin(grausR+incR)));

				vertices.push_back(vertex((raioI + raioE + somatorio) * cos(grausR), raioE * cos(grausA), (raioI + raioE + somatorio) * sin(grausR),cos(grausR),cos(grausA),sin(grausR))); 
				vertices.push_back(vertex((raioI + raioE + somatorio2) * cos(grausR + incR), raioE * cos(grausA + incA), (raioI + raioE + somatorio2) * sin(grausR + incR),cos(grausR+incR),cos(grausA+incA),sin(grausR+incR)));
				vertices.push_back(vertex((raioI + raioE + somatorio)  * cos(grausR + incR), raioE * cos(grausA), (raioI + raioE + somatorio) * sin(grausR + incR),cos(grausR+incR),cos(grausA),sin(grausR+incR)));
			
				vertices.push_back(vertex((raioI + raioE - somatorio) * cos(grausR), raioE * cos(grausA), (raioI + raioE - somatorio) * sin(grausR),cos(grausR),cos(grausA),sin(grausR)));
				vertices.push_back(vertex((raioI + raioE - somatorio2) * cos(grausR + incR), raioE * cos(grausA + incA), (raioI + raioE - somatorio2) * sin(grausR + incR),cos(grausR+incR),cos(grausA+incA),sin(grausR+incR)));
				vertices.push_back(vertex((raioI + raioE - somatorio2)  * cos(grausR), raioE * cos(grausA + incA), (raioI + raioE - somatorio2) * sin(grausR),cos(grausR),cos(grausA+incA),sin(grausR)));
			
				vertices.push_back(vertex((raioI + raioE - somatorio) * cos(grausR), raioE * cos(grausA), (raioI + raioE - somatorio) * sin(grausR),cos(grausR),cos(grausA),sin(grausR))); 
				vertices.push_back(vertex((raioI + raioE - somatorio) * cos(grausR + incR), raioE * cos(grausA), (raioI + raioE - somatorio) * sin(grausR + incR),cos(grausR+incR),cos(grausA),sin(grausR+incR)));
				vertices.push_back(vertex((raioI + raioE - somatorio2)  * cos(grausR + incR), raioE * cos(grausA + incA), (raioI + raioE - somatorio2) * sin(grausR + incR),cos(grausR+incR),cos(grausA+incA),sin(grausR+incR)));
				grausR = grausR + incR;
			}
			grausA = grausA + incA;
			grausE = grausE + incA;
			somatorio = raioE * cos(grausE);
			somatorio2 = raioE * cos(grausE + incA);		
		}
	}
	nVertices = vertices.size();
	glGenBuffers(1,&vbo);
	glBindBuffer(GL_ARRAY_BUFFER,vbo);
	glBufferData(GL_ARRAY_BUFFER,vertices.size()*sizeof(vertex), &vertices[0], GL_STATIC_DRAW);
}

void Torus::desenha(){
	glBindBuffer(GL_ARRAY_BUFFER,vbo);
	glVertexPointer(3,GL_FLOAT,sizeof(vertex),(void*)offsetof(vertex,vertices));
	glNormalPointer(GL_FLOAT,sizeof(vertex),(void*)offsetof(vertex,normais));
	glDrawArrays(GL_TRIANGLES,0,nVertices);
}

/**
 * Destrutor da class Torus.
 * Destroi o VBO criado, para nao ficar alocada memoria na placa grafica	
 */
Torus::~Torus(){
	glDeleteBuffers(1,&vbo);
}
