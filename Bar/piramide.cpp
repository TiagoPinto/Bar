#include "includes.h"
#include "piramide.h"

/**
 * Construtor da class Piramide.
 * Inicializa todas as variaveis de instancia.
 *
 */
Piramide::Piramide(){
	this->comprimento = 0.0f;
	this->altura = 0.0f;
	this->largura = 0.0f;
	this->fatias = 0.0f;
	this->camadas = 0.0f;
}

/**
 * Construtor da class Piramide.
 * Inicializa as variaveis de raio ou comprimento, altura, largura, fatias e camadas do piramide.
 *@param c
 * 	 Variavel que especifica o comprimento ou raio da piramide	
 *@param a
 * 	 Variavel que especifica a altura da piramide
  *@param l
 * 	 Variavel que especifica o comprimento da piramide
  *@param f
 * 	 Variavel que especifica as fatias da piramide
  *@param c
 * 	 Variavel que especifica as camadas da piramide
 */

Piramide::Piramide(float c, float a,float l, float f, float p, GLuint idtex){
	this->comprimento = c;
	this->altura = a;
	this->largura = l;
	this->fatias = f; 
	this->camadas = p;
	this->textura = idtex;

	std:: vector <vertex> vertices;

	//Variaveis Iniciais para comecar a desenhar 
	float alt = -this->altura/2;
	float tamanhoC = comprimento;
	float tamanhoL = largura;
	float anguloC = tanh((comprimento/2)/altura);
	float anguloL = tanh((largura/2)/altura);
	float tamanho2 = comprimento - 2*(altura/camadas* tan(anguloC));
	float tamanhoL2 = largura - 2*(altura/camadas* tan(anguloL));
	float incrementoY = this->altura/this->camadas;
	float comp = -tamanhoC/2, comp2 = -tamanho2/2;
	float larg2 = -tamanhoL/2, larg3 = -tamanhoL2/2;
	float y,z;
	float incrementoX, incrementoX2, incrementoZ, incrementoZ2;
	float larg = largura/2;
	float comprimentoL = comprimento/2;
	float decrementoL = largura/2 - (largura/2)/camadas;
	float decrementoC = comprimento/2 - (comprimento/2)/camadas;
	float texY = 1;
	float incTY = 1/camadas;
	float incTX = 1/fatias;
	//Primeiro Ciclo para as fatias, Segundo para as Camadas
	for(int j = 0; j < this->camadas; j++){
		incrementoX = tamanhoC/fatias;
		incrementoX2 = tamanho2 / fatias;
		incrementoZ = tamanhoL/fatias;
		incrementoZ2 = tamanhoL2/ fatias;
		float texX = 0;
		for(int i = 0; i < fatias; i++){
			if(i == 0){
				y = comp2;
				z = larg3;
			}
			
			//Face Frontal Triangulo
			vertices.push_back(vertex(comp, alt, larg,0,alt,1, texX, texY));
			vertices.push_back(vertex(comp + incrementoX, alt, larg,0,alt,1, texX+incTX, texY));
			vertices.push_back(vertex(comp2, alt + incrementoY, decrementoL,0,alt+incrementoY,1, texX, texY - incTY));
				
			vertices.push_back(vertex(comp + incrementoX, alt, larg,0,alt,1, texX+incTX, texY));
			vertices.push_back(vertex(comp2 + incrementoX2, alt + incrementoY, decrementoL,0,alt+incrementoY,1, texX +incTX, texY - incTY));
			vertices.push_back(vertex(comp2, alt + incrementoY, decrementoL,0,alt+incrementoY,1, texX, texY - incTY)); 
				
			//Face Traseira Triangulo
			vertices.push_back(vertex(comp, alt, -larg, 0, alt, -1, texX, texY));
			vertices.push_back(vertex(comp2, alt + incrementoY, -decrementoL, 0, alt+incrementoY, -1, texX, texY - incTY));
			vertices.push_back(vertex(comp2 + incrementoX2, alt + incrementoY, -decrementoL, 0, alt+incrementoY, -1, texX + incTX, texY-incTY));

			vertices.push_back(vertex(comp, alt, -larg, 0, alt, -1, texX, texY));
			vertices.push_back(vertex(comp2 + incrementoX2, alt + incrementoY, -decrementoL, 0, alt+incrementoY, -1, texX + incTX, texY-incTY));
			vertices.push_back(vertex(comp + incrementoX, alt , -larg, 0, alt, -1, texX+incTX, texY));

			//Face Lateral Direita
			vertices.push_back(vertex(comprimentoL,alt,larg2, 1, alt, 0, texX, texY));
			vertices.push_back(vertex(decrementoL,alt + incrementoY, larg3, 1, alt+incrementoY, 0, texX, texY-incTY));
			vertices.push_back(vertex(decrementoL, alt + incrementoY,larg3 + incrementoZ2, 1, alt+incrementoY, 0, texX+incTX, texY - incTY));
			
			vertices.push_back(vertex(comprimentoL, alt, larg2, 1, alt, 0, texX, texY));
			vertices.push_back(vertex(decrementoL, alt + incrementoY, larg3 + incrementoZ2, 1, alt+incrementoY, 0, texX+incTX, texY-incTY));
			vertices.push_back(vertex(comprimentoL, alt, larg2 + incrementoZ, 1, alt, 0, texX+incTX, texY));
			
			//Face Lateral Esquerda
			vertices.push_back(vertex(-comprimentoL,alt,larg2, -1, alt, 0, texX, texY));
			vertices.push_back(vertex(-decrementoL, alt + incrementoY, larg3 + incrementoZ2, -1, alt+incrementoY, 0, texX+incTX, texY-incTY));
			vertices.push_back(vertex(-decrementoL,alt + incrementoY, larg3, -1, alt+incrementoY, 0, texX, texY-incTY));			

			vertices.push_back(vertex(-comprimentoL, alt, larg2, -1, alt, 0, texX, texY));
			vertices.push_back(vertex(-comprimentoL, alt, larg2 + incrementoZ, -1, alt, 0, texX +incTX, texY));
			vertices.push_back(vertex(-decrementoL, alt + incrementoY, larg3 + incrementoZ2, -1, alt+incrementoY, 0, texX+incTX, texY - incTY));

			comp = comp + incrementoX;
			comp2 = comp2 + incrementoX2;
			larg2 = larg2 + incrementoZ;
			larg3 = larg3 + incrementoZ2;
			texX = texX + incTX;
		}

		comp = y;
		comp2 = y+ (altura/camadas)*tan(anguloC);
		larg2 = z;
		larg3 = z + (altura/camadas)*tan(anguloL);
		tamanhoC = tamanho2;
		tamanhoL = tamanhoL2;
		tamanho2 = tamanho2 - 2*(altura/camadas* tan(anguloC));
		tamanhoL2 = tamanhoL2 - 2*(altura/camadas * tan(anguloL));
		alt = alt + incrementoY;
		larg = decrementoL;
		comprimentoL = decrementoC;
		decrementoL = decrementoL - (largura/2)/camadas;
		decrementoC = decrementoC - (comprimento/2)/camadas;
		texY = texY - incTY;
	}
	texY = 1;
	incrementoX = this->comprimento/this->camadas;
	incrementoZ = this->largura/this->fatias;
	comp = -this->comprimento/2;
	for(int z = 0; z < this->camadas; z++){
		larg = -this->largura/2;
		float texX = 0;
		for(int x = 0; x < this->fatias; x++){
			//Face de Baixo
			vertices.push_back(vertex(comp, -altura/2, larg,0,-1,0, texY, texX));
			vertices.push_back(vertex(comp + incrementoX, -altura/2, larg + incrementoZ,0,-1,0,texY-incTY ,texX+incTX ));
			vertices.push_back(vertex(comp, -altura/2, larg + incrementoZ,0,-1,0,texY - incTY , texX));
			
			vertices.push_back(vertex(comp, -altura/2, larg,0,-1,0, texY, texX));
			vertices.push_back(vertex(comp + incrementoX, -altura/2, larg,0,-1,0, texY, texX + incTX));
			vertices.push_back(vertex(comp + incrementoX, -altura/2, larg + incrementoZ,0,-1,0,texY - incTY ,texX + incTX ));
			larg = larg + incrementoZ;
			texY = texY - incTY;
		}
		comp = comp + incrementoX;
		
		texX = texX + incTX;
	}
	nVertices = vertices.size();
	glGenBuffers(1,&vbo);
	glBindBuffer(GL_ARRAY_BUFFER,vbo);
	glBufferData(GL_ARRAY_BUFFER,vertices.size()*sizeof(vertex), &vertices[0], GL_STATIC_DRAW);
}


/**
 * Desenha uma piramide com base rectangular, com as dimensoes definidas no construtor
 *		
 */

void Piramide::desenha(){
	glBindBuffer(GL_ARRAY_BUFFER,vbo);
	glBindTexture(GL_TEXTURE_2D,textura);
	glVertexPointer(3,GL_FLOAT,sizeof(vertex),(void*)offsetof(vertex,vertices));
	glNormalPointer(GL_FLOAT,sizeof(vertex),(void*)offsetof(vertex,normais));
	glTexCoordPointer(2,GL_FLOAT,sizeof(vertex),(void*)offsetof(vertex,texturas));
	glPushMatrix();
	glMatrixMode(GL_TEXTURE);
	//glScalef(raioE,raioI,0);
	glPopMatrix();
	glDrawArrays(GL_TRIANGLES,0,nVertices);
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

/**
 * Destrutor da class Piramide.
 * Destroi o VBO criado, para nao ficar alocada memoria na placa grafica	
 */
Piramide::~Piramide(){
	glDeleteBuffers(1,&vbo);
}