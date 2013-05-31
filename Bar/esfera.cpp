#include "includes.h"
#include "esfera.h"

/**
 * Construtor da class Esfera.
 * Inicializa as variaveis de raios, fatias e camadas.	
 */
Esfera:: Esfera(){
	this->raio = 0.0f;
	this->fatias = 0.0f;
	this->camadas = 0.0f;
	this->tipo = 0;
}

/**
 * Construtor da class Esfera.
 * Inicializa as variaveis de raio, fatias e camadas de uma esfera.
 *@param r
 * 	 Variavel que especifica o raio da esfera	
 *@param f
 * 	 Variavel que especifica as fatias da esfera	
 *@param c
 * 	 Variavel que especifica as camadas da esfera
 *		
 */
Esfera:: Esfera(float r, float f, float c, int t, GLuint textura){
	this->raio = r;
	this->fatias = f;
	this->camadas = c;
	this->tipo = t;
	this->textura = textura;

	std:: vector <vertex> vertices;
	
	float incTY = 1/camadas;
	float incTX = 1/fatias;
	float texY = 0;
	if(tipo == 1){
		float rotacaoR = 2 * M_PI / this->fatias;
		float rotacaoC = M_PI / this->camadas;
		float grausC = 0;
		for(int k = 0; k < this->camadas; k++){
			float grausR = 0;
			float texX = 0;
			for(int i = 0; i < this->fatias; i++) {
				//Parte Superior da Esfera
				vertices.push_back(vertex(raio * cos(grausR) * sin(grausC), raio * cos(grausC), raio * sin(grausR) * sin(grausC), -cos(grausR)*sin(grausC), -cos(grausC), -sin(grausR)*sin(grausC),texX, texY)); 
				vertices.push_back(vertex(raio * cos(grausR) * sin(grausC + rotacaoC), raio * cos(grausC + rotacaoC), raio * sin(grausR) * sin(grausC + rotacaoC), -cos(grausR)*sin(grausC+rotacaoC), -cos(grausC+rotacaoC), -sin(grausR)*sin(grausC+rotacaoC), texX, texY+incTY));
				vertices.push_back(vertex(raio * cos(grausR + rotacaoR) * sin(grausC + rotacaoC), raio * cos(grausC + rotacaoC), raio * sin(grausR + rotacaoR) * sin(grausC + rotacaoC), -cos(grausR+rotacaoR)*sin(grausC+rotacaoC), -cos(grausC+rotacaoC), -sin(grausR+rotacaoR)*sin(grausC+rotacaoC), texX+incTX, texY + incTY));

				vertices.push_back(vertex(raio * cos(grausR) * sin(grausC), raio * cos(grausC), raio * sin(grausR) * sin(grausC), -cos(grausR)*sin(grausC), -cos(grausC), -sin(grausR)*sin(grausC), texX , texY)); 				
				vertices.push_back(vertex(raio * cos(grausR + rotacaoR) * sin(grausC + rotacaoC), raio * cos(grausC + rotacaoC), raio * sin(grausR + rotacaoR) * sin(grausC + rotacaoC), -cos(grausR + rotacaoR) * sin(grausC + rotacaoC), -cos(grausC+rotacaoC), -sin(grausR + rotacaoR) * sin(grausC + rotacaoC), texX + incTY, texY + incTY));
				vertices.push_back(vertex(raio * cos(grausR + rotacaoR) * sin(grausC), raio * cos(grausC), raio * sin(grausR + rotacaoR) * sin(grausC), -cos(grausR+rotacaoR)*sin(grausC), -cos(grausC), -sin(grausR+rotacaoR) * sin(grausC), texX + incTY, texY));		
				grausR = grausR + rotacaoR;
				texX = texX + incTX;
			}
			grausC = grausC + rotacaoC;
			texY = texY + incTY;
		}
	}

	//Desenha apenas metade de uma Esfera
	if(tipo == 2){
		float rotacaoR =  2 * M_PI / this->fatias;
		float rotacaoC = (M_PI / 2) / this->camadas;
		float grausC = 0;
		for(int k = 0; k < this->camadas; k++){
			float grausR = 0;
			for(int i = 0; i < this->fatias; i++) {
				//Parte Superior da Esfera
				vertices.push_back(vertex(raio * cos(grausR) * sin(grausC), raio * cos(grausC), raio * sin(grausR) * sin(grausC), -cos(grausR) * sin(grausC), -cos(grausC), -sin(grausR) * sin(grausC))); 
				vertices.push_back(vertex(raio * cos(grausR) * sin(grausC + rotacaoC), raio * cos(grausC + rotacaoC), raio * sin(grausR) * sin(grausC + rotacaoC), -cos(grausR) * sin(grausC + rotacaoC), -cos(grausC + rotacaoC), -sin(grausR) * sin(grausC + rotacaoC)));
				vertices.push_back(vertex(raio * cos(grausR + rotacaoR) * sin(grausC + rotacaoC), raio * cos(grausC + rotacaoC), raio * sin(grausR + rotacaoR) * sin(grausC + rotacaoC), -cos(grausR + rotacaoR) * sin(grausC + rotacaoC), -cos(grausC + rotacaoC), -sin(grausR + rotacaoR) * sin(grausC + rotacaoC)));

				vertices.push_back(vertex(raio * cos(grausR) * sin(grausC), raio * cos(grausC), raio * sin(grausR) * sin(grausC), -cos(grausR) * sin(grausC), -cos(grausC), -sin(grausR) * sin(grausC))); 				
				vertices.push_back(vertex(raio * cos(grausR + rotacaoR) * sin(grausC + rotacaoC), raio * cos(grausC + rotacaoC), raio * sin(grausR + rotacaoR) * sin(grausC + rotacaoC), -cos(grausR + rotacaoR) * sin(grausC + rotacaoC), -cos(grausC + rotacaoC), -sin(grausR + rotacaoR) * sin(grausC + rotacaoC)));
				vertices.push_back(vertex(raio * cos(grausR + rotacaoR) * sin(grausC), raio * cos(grausC), raio * sin(grausR + rotacaoR) * sin(grausC), -cos(grausR + rotacaoR) * sin(grausC), -cos(grausC), -sin(grausR + rotacaoR) * sin(grausC)));	
			grausR = grausR + rotacaoR;	
			}
			grausC = grausC + rotacaoC;
		}
	}
	nVertices = vertices.size();
	glGenBuffers(1,&vbo);
	glBindBuffer(GL_ARRAY_BUFFER,vbo);
	glBufferData(GL_ARRAY_BUFFER,vertices.size()*sizeof(vertex), &vertices[0], GL_STATIC_DRAW);
}

/**
 * Desenha uma esfera, com as dimensoes definidas no construtor
 *		
 */
void Esfera:: desenha(){
	glBindBuffer(GL_ARRAY_BUFFER,vbo);
	glBindTexture(GL_TEXTURE_2D,textura);
	glVertexPointer(3,GL_FLOAT,sizeof(vertex),(void*)offsetof(vertex,vertices));
	glNormalPointer(GL_FLOAT,sizeof(vertex),(void*)offsetof(vertex,normais));
	glTexCoordPointer(2,GL_FLOAT,sizeof(vertex),(void*)offsetof(vertex,texturas));
	glPushMatrix();
	glMatrixMode(GL_TEXTURE);
	glScalef(raio/2,raio/2,0);
	glPopMatrix();
	glDrawArrays(GL_TRIANGLES,0,nVertices);
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

/**
 * Destrutor da class Esfera.
 * Destroi o VBO criado, para nao ficar alocada memoria na placa grafica	
 */
Esfera::~Esfera(){
	glDeleteBuffers(1,&vbo);
}



