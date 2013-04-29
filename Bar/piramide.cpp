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

Piramide::Piramide(float c, float a,float l, float f, float p){
	this->comprimento = c;
	this->altura = a;
	this->largura = l;
	this->fatias = f; 
	this->camadas = p;
}


/**
 * Desenha uma piramide com base rectangular, com as dimensoes definidas no construtor
 *		
 */

void Piramide::desenhaR(){
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
	//Primeiro Ciclo para as fatias, Segundo para as Camadas
	for(int j = 0; j < this->camadas; j++){
		incrementoX = tamanhoC/fatias;
		incrementoX2 = tamanho2 / fatias;
		incrementoZ = tamanhoL/fatias;
		incrementoZ2 = tamanhoL2/ fatias;
		for(int i = 0; i < fatias; i++){
				if(i == 0)
				{
					y = comp2;
					z = larg3;
				}
			glBegin(GL_TRIANGLES);
			//Face Frontal Triangulo
				glVertex3f(comp, alt, larg);
				glVertex3f(comp + incrementoX, alt, larg);
				glVertex3f(comp2, alt + incrementoY, decrementoL);
				
				glVertex3f(comp + incrementoX, alt, larg);
				glVertex3f(comp2 + incrementoX2, alt + incrementoY, decrementoL);
				glVertex3f(comp2, alt + incrementoY, decrementoL); 
				
			//Face Traseira Triangulo
				glVertex3f(comp, alt, -larg);
				glVertex3f(comp2, alt + incrementoY, -decrementoL);
				glVertex3f(comp2 + incrementoX2, alt + incrementoY, -decrementoL);

				glVertex3f(comp, alt, -larg);
				glVertex3f(comp2 + incrementoX2, alt + incrementoY, -decrementoL);
				glVertex3f(comp + incrementoX, alt , -larg);

			//Face Lateral Direita
				glVertex3f(comprimentoL,alt,larg2);
				glVertex3f(decrementoL,alt + incrementoY, larg3);
				glVertex3f(decrementoL, alt + incrementoY,larg3 + incrementoZ2);

				glVertex3f(comprimentoL, alt, larg2);
				glVertex3f(decrementoL, alt + incrementoY, larg3 + incrementoZ2);
				glVertex3f(comprimentoL, alt, larg2 + incrementoZ);

			//Face Lateral Esquerda
				glVertex3f(-comprimentoL,alt,larg2);
				glVertex3f(-decrementoL, alt + incrementoY, larg3 + incrementoZ2);
				glVertex3f(-decrementoL,alt + incrementoY, larg3);			

				glVertex3f(-comprimentoL, alt, larg2);
				glVertex3f(-comprimentoL, alt, larg2 + incrementoZ);
				glVertex3f(-decrementoL, alt + incrementoY, larg3 + incrementoZ2);

				comp = comp + incrementoX;
				comp2 = comp2 + incrementoX2;
				larg2 = larg2 + incrementoZ;
				larg3 = larg3 + incrementoZ2;
			glEnd();
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
	}

	incrementoX = this->comprimento/this->camadas;
	incrementoZ = this->largura/this->fatias;
	comp = -this->comprimento/2;
	for(int z = 0; z < this->camadas; z++){
		float larg = -this->largura/2;
		for(int x = 0; x < this->fatias; x++){
			glBegin(GL_TRIANGLES);

			//Face de Baixo
				glVertex3f(comp, -altura/2, larg);
				glVertex3f(comp + incrementoX, -altura/2, larg + incrementoZ);
				glVertex3f(comp, -altura/2, larg + incrementoZ);			

				glVertex3f(comp, -altura/2, larg);
				glVertex3f(comp + incrementoX, -altura/2, larg);
				glVertex3f(comp + incrementoX, -altura/2, larg + incrementoZ);
				larg = larg + incrementoZ;
			glEnd();
		}
		comp = comp + incrementoX;
	}
}