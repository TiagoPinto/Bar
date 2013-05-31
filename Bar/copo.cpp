#include "includes.h"
#include "copo.h"
#include "esfera.h"
#include "torus.h"

/**
 * Construtor da class Copo.
 * Inicializa todas as variaveis de instancia.
 *
 */
Copo::Copo(){
	this->raio = 0.0f;
	this->altura = 0.0f;
	this->espessura = 0.0f;
	this->fatias = 0.0f;
	this->camadas = 0.0f;
}

/**
 * Construtor da class Copo.
 * 
 *@param r
 * 	 Variavel que especifica o raio do copo	
 *@param a
 * 	 Variavel que especifica a altura do copo
  *@param e
 * 	 Variavel que especifica a espessura do copo
  *@param f
 * 	 Variavel que especifica as fatias do copo
  *@param p
 *	 Variavel que especifica as fatias do copo
 */
Copo::Copo(float r, float a, float e, float f, float p, int t, GLuint idtex){
	this->raio = r;
	this->altura = a;
	this->espessura = e;
	this->fatias = f;
	this->camadas = p;
	this->tipo = t;
	this->textura = idtex;

	std:: vector <vertex> vertices;
	float texX = 0;
	float texY;
	float incTX = 1 / fatias;
	float incTY = 1 / camadas;
	if(tipo == 1){
		float rotacao = 2 * M_PI/this->fatias;
		float graus = 0;
		float incremento = 2* this->espessura / this->camadas;
		float incA = this->altura/this->camadas;
		float incB = (this->altura - this->espessura) / this->camadas;
		texY = 1;
		while(graus <= 2 * M_PI){
			//Parte de fora
			//Base Topo
			vertices.push_back(vertex((raio + 2*espessura) * cos(graus), altura/2, (raio + 2 * espessura) * sin(graus),0,1,0, texX, texY));
			vertices.push_back(vertex((raio + 3*espessura) * cos(graus + rotacao), altura/2, (raio + 3*espessura) * sin(graus + rotacao),0,1,0, texX + incTX, texY - incTY));
			vertices.push_back(vertex((raio + 3*espessura) * cos(graus), altura/2, (raio + 3*espessura) * sin(graus),0,1,0, texX, texY - incTY));

			vertices.push_back(vertex((raio + 2*espessura) * cos(graus), altura/2, (raio + 2 * espessura) * sin(graus),0,1,0, texX, texY));
			vertices.push_back(vertex((raio + 2*espessura) * cos(graus + rotacao), altura/2, (raio + 2*espessura) * sin(graus + rotacao),0,1,0, texX + incTX, texY));
			vertices.push_back(vertex((raio + 3*espessura)* cos(graus + rotacao), altura/2, (raio + 3*espessura) * sin(graus + rotacao),0,1,0, texX + incTX, texY));
			
			//Base Baixo
			vertices.push_back(vertex(0.0f, -altura/2, 0.0f,0,-1,0, 0.5, 0.5));
			vertices.push_back(vertex((raio + espessura) * cos(graus), -altura/2, (raio + espessura) * sin(graus),0,-1,0, 1, 0));			
			vertices.push_back(vertex((raio + espessura) * cos(graus + rotacao), -altura/2, (raio + espessura) * sin(graus + rotacao),0,-1,0, 0, 1));
		
			//Parte de fora
			float cam = -this->altura/2;
			float aumento = 0.0f;
			texY = 1;
			for(int i = 0; i < this->camadas; i++) {
				vertices.push_back(vertex((raio + espessura + aumento) * cos(graus), cam, (raio + espessura + aumento) * sin(graus),cos(graus),cam,sin(graus),texY, texX)); 
				vertices.push_back(vertex((raio + espessura + aumento + incremento) * cos(graus), cam + incA, (raio + espessura + aumento + incremento) * sin(graus),cos(graus),cam+incA,sin(graus), texY-incTY, texX));					
				vertices.push_back(vertex((raio + espessura + aumento + incremento) * cos(graus + rotacao), cam + incA, (raio + espessura + aumento + incremento) * sin(graus + rotacao),cos(graus+rotacao),cam+incA,sin(graus+rotacao), texY - incTY, texX + incTX ));
			
				vertices.push_back(vertex((raio + espessura + aumento)* cos(graus), cam , (raio + espessura + aumento) * sin(graus),cos(graus),cam,sin(graus), texY, texX)); 				
				vertices.push_back(vertex((raio + espessura + aumento + incremento) * cos(graus + rotacao), cam +incA, (raio + espessura + aumento + incremento) * sin(graus + rotacao),cos(graus+rotacao),cam+incA,sin(graus+rotacao), texY - incTY, texX + incTX));				
				vertices.push_back(vertex((raio + espessura + aumento) * cos(graus + rotacao), cam, (raio + espessura + aumento) * sin(graus + rotacao),cos(graus+rotacao),cam,sin(graus+rotacao), texY, texX + incTX));
				cam = cam + incA;		//Incrementa a altura, para fazer as outras camadas;
				aumento = aumento + incremento;
				texY = texY - incTY;
			}
			float cami = -this->altura/2 + espessura;
			//Parte Interior
			//Base Baixo
			vertices.push_back(vertex(0.0f, cami, 0.0f,0,1,0, 0.5, 0.5));
			vertices.push_back(vertex((raio ) * cos(graus + rotacao), cami, (raio ) * sin(graus + rotacao),0,1,0, 1, 0));
			vertices.push_back(vertex((raio )* cos(graus), cami, (raio) * sin(graus),0,1,0, 0, 1));

			//Parte lateral Interior
			aumento = 0.0f;
			texY = 1;
			for(int i = 0; i < this->camadas; i++) {
				vertices.push_back(vertex((raio + aumento) * cos(graus + rotacao), cami, (raio + aumento) * sin(graus + rotacao),-cos(graus+rotacao),cami,-sin(graus+rotacao), texY, texX));
				vertices.push_back(vertex((raio + aumento + incremento) * cos(graus + rotacao), cami + incB, (raio + aumento + incremento) * sin(graus + rotacao),-cos(graus+rotacao),(cami+incB),-sin(graus+rotacao), texY - incTY, texX + incTX));
				vertices.push_back(vertex((raio + aumento + incremento) * cos(graus), cami + incB, (raio + aumento + incremento) * sin(graus),-cos(graus),(cami+incB),-sin(graus), texY-incTY, texX));				
				
				vertices.push_back(vertex((raio + aumento) * cos(graus + rotacao), cami, (raio + aumento) * sin(graus + rotacao),-cos(graus+rotacao),cami,-sin(graus+rotacao), texY, texX + incTX));
				vertices.push_back(vertex((raio + aumento + incremento) * cos(graus), cami +incB, (raio + aumento + incremento) * sin(graus),-cos(graus),(cami+incB),-sin(graus), texY - incTY, texX));				
				vertices.push_back(vertex((raio + aumento)* cos(graus), cami , (raio + aumento) * sin(graus),-cos(graus),(cami),-sin(graus), texY, texX));
				cami = cami + incB;		//Incrementa a altura, para fazer as outras camadas;
				aumento = aumento + incremento;		//Incrementa o raio do copo, porque ele vai aumentando de raio, a medida que chega ao topo
				texY = texY - incTY;
			}
			graus = graus + rotacao;
			texX = texX + incTX;
		}
	}
	texX = 0;
	//Desenha uma Caneca
	if(tipo == 2){
		float rotacaoF = (2 * M_PI) / this->fatias;
		float graus = 0.0f;
		float incA = (this->altura -this->espessura)/this->camadas;
		texY = 1;
		while(graus <= 2 * M_PI){
			//Topo da Caneca
			vertices.push_back(vertex((raio - espessura) * cos(graus), altura/2, (raio -espessura) * sin(graus),0,1,0, texX, texY));
			vertices.push_back(vertex(raio * cos(graus + rotacaoF), altura/2, raio * sin(graus + rotacaoF),0,1,0, texX+incTX, texY-incTY));
			vertices.push_back(vertex(raio * cos(graus), altura/2, raio * sin(graus),0,1,0, texX, texY - incTY));

			vertices.push_back(vertex((raio - espessura) * cos(graus), altura/2, (raio - espessura) * sin(graus),0,1,0, texX, texY));
			vertices.push_back(vertex((raio - espessura) * cos(graus + rotacaoF), altura/2, (raio - espessura) * sin(graus + rotacaoF),0,1,0));
			vertices.push_back(vertex(raio * cos(graus + rotacaoF), altura/2, raio * sin(graus + rotacaoF),0,1,0));

			//Parte de Baixo da caneca
			vertices.push_back(vertex(0.0f, -altura/2, 0.0f,0,-1,0, 0.5, 0.5));
			vertices.push_back(vertex((raio + espessura) * cos(graus), -altura/2, (raio + espessura) * sin(graus),0,-1,0, 0, 1));
			vertices.push_back(vertex((raio + espessura) * cos(graus + rotacaoF), -altura/2, (raio + espessura) * sin(graus + rotacaoF),0,-1,0, 1, 0));
			texY = 1;
			//Base da Caneca Cilindrica com o inferior com maior raio que a parte superior
			for(int k = 0; k < this->fatias; k++){
				vertices.push_back(vertex((raio + espessura) * cos(graus), -altura/2 , (raio + espessura) * -sin(graus),cos(graus),0.5,-sin(graus), texY, texX));
				vertices.push_back(vertex(raio * cos(graus + rotacaoF), -altura/ 2 + espessura, raio * -sin(graus + rotacaoF),cos(graus+rotacaoF),1,-sin(graus+rotacaoF), texY - incTY, texX+incTX));			
				vertices.push_back(vertex(raio * cos(graus), -altura / 2 + espessura, raio * -sin(graus),cos(graus),1,-sin(graus), texY - incTY, texX));

				vertices.push_back(vertex((raio + espessura) * cos(graus), -altura/2 , (raio + espessura) * -sin(graus),cos(graus),1,-sin(graus), texY, texX));
				vertices.push_back(vertex((raio + espessura) * cos(graus + rotacaoF), -altura/ 2, (raio + espessura) * -sin(graus + rotacaoF),cos(graus+rotacaoF),1,-sin(graus+rotacaoF), texY, texX + incTX));			
				vertices.push_back(vertex(raio * cos(graus + rotacaoF), -altura/ 2 + espessura, raio * -sin(graus + rotacaoF),cos(graus+rotacaoF),0.5,-sin(graus+rotacaoF), texY - incTY, texX+incTX));	
				texY = texY - incTY;
			}
		
			float cam = -this->altura/2 + this->espessura;
			texY = 1;
			for(int i = 0; i < this->camadas; i++) {
				vertices.push_back(vertex(raio * cos(graus), cam, raio * sin(graus),cos(graus),0,sin(graus), texY, texX)); 
				vertices.push_back(vertex(raio * cos(graus), cam + incA, raio * sin(graus),cos(graus),0,sin(graus), texY-incTY, texX));					
				vertices.push_back(vertex(raio * cos(graus + rotacaoF), cam + incA, raio * sin(graus + rotacaoF),cos(graus+rotacaoF),0,sin(graus+rotacaoF), texY-incTY, texX+incTX));
			
				vertices.push_back(vertex(raio* cos(graus), cam , raio* sin(graus),cos(graus),0,sin(graus), texY, texX)); 				
				vertices.push_back(vertex(raio* cos(graus + rotacaoF), cam +incA, raio * sin(graus + rotacaoF),cos(graus+rotacaoF),0,sin(graus+rotacaoF), texY - incTY, texX + incTX));				
				vertices.push_back(vertex(raio* cos(graus + rotacaoF), cam, raio* sin(graus + rotacaoF),cos(graus+rotacaoF),0,sin(graus+rotacaoF), texY, texX + incTX));
				cam = cam + incA;		//Incrementa a altura, para fazer as outras camadas;
				texY = texY - incTY;
			}
			cam = -this->altura/2 + this->espessura;
			//Parte Interior
			//Base Baixo
			vertices.push_back(vertex(0.0f, cam, 0.0f,0,1,0,0.5, 0.5));
			vertices.push_back(vertex((raio - espessura) * cos(graus + rotacaoF), cam, (raio - espessura ) * sin(graus + rotacaoF),0,1,0, 1, 0));
			vertices.push_back(vertex((raio - espessura)* cos(graus), cam, (raio - espessura) * sin(graus),0,1,0, 0 , 1));
		
			//Parte lateral Interior
			texY = 1;
			for(int i = 0; i < this->camadas; i++) {
				vertices.push_back(vertex((raio - espessura) * cos(graus + rotacaoF), cam, (raio - espessura) * sin(graus + rotacaoF),-cos(graus+rotacaoF),0,-sin(graus+rotacaoF), texY, texX + incTX));
				vertices.push_back(vertex((raio - espessura) * cos(graus + rotacaoF), cam + incA, (raio - espessura) * sin(graus + rotacaoF),-cos(graus+rotacaoF),0,-sin(graus+rotacaoF), texY - incTY, texX + incTX));
				vertices.push_back(vertex((raio - espessura) * cos(graus), cam + incA, (raio - espessura) * sin(graus),-cos(graus),0,-sin(graus), texY - incTY, texX));				
			
				vertices.push_back(vertex((raio - espessura) * cos(graus + rotacaoF), cam, (raio - espessura) * sin(graus + rotacaoF),-cos(graus+rotacaoF),0,-sin(graus+rotacaoF), texY, texX + incTX));
				vertices.push_back(vertex((raio - espessura) * cos(graus), cam +incA, (raio - espessura) * sin(graus),-cos(graus),0,-sin(graus), texY - incTY, texX));			
				vertices.push_back(vertex((raio - espessura) * cos(graus), cam , (raio - espessura) * sin(graus),-cos(graus),0,-sin(graus), texY, texX));
				cam = cam + incA;		//Incrementa a altura, para fazer as outras camadas;
				texY = texY - incTY;
			}
			graus = graus + rotacaoF;
			texX = texX + incTX;
		}
		pega = new Torus(this->altura / 4, this->espessura ,this->fatias, this->camadas, 2, textura);
	}

	nVertices = vertices.size();
	glGenBuffers(1,&vbo);
	glBindBuffer(GL_ARRAY_BUFFER,vbo);
	glBufferData(GL_ARRAY_BUFFER,vertices.size()*sizeof(vertex), &vertices[0], GL_STATIC_DRAW);
}


/* Desenha um copo standard, em que o copo e cilindrico, mas que a base e inferior em raio a altura */
void Copo::desenha(){
	if(tipo == 2){
		glPushMatrix();
		glRotatef(90,0,1,0);
		glRotatef(90,0,0,1);
		glTranslatef(0.0f,0.0f, this->raio);
		pega->desenha();
		glPopMatrix();
	}

	glBindBuffer(GL_ARRAY_BUFFER,vbo);
	glBindTexture(GL_TEXTURE_2D,textura);
	glVertexPointer(3,GL_FLOAT,sizeof(vertex),(void*)offsetof(vertex,vertices));
	glNormalPointer(GL_FLOAT,sizeof(vertex),(void*)offsetof(vertex,normais));
	glTexCoordPointer(2,GL_FLOAT,sizeof(vertex),(void*)offsetof(vertex,texturas));
	glPushMatrix();
	glMatrixMode(GL_TEXTURE);
	glScalef(1,2,0);
	glPopMatrix();
	glDrawArrays(GL_TRIANGLES,0,nVertices);
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void Copo::desenhaC(){
/*	Esfera *calice;

	glPushMatrix();
		glRotatef(180,1,0,0);
		glTranslatef(0.0f, - 2 * this->altura / 3 -this->raio, 0.0f);
		calice = new Esfera(this->altura / 3,3*this->fatias, 3*this->camadas,2);
		calice->desenha();
	glPopMatrix();
*/

}

void Copo::desenhaD(){
/*	float incR = M_PI / ( 2* fatias);
	float incA = M_PI / (2* camadas);
	float grausA = -M_PI;
	float grausE = -M_PI/2;
	float graus = -M_PI/2;
	float somatorio = raio * cos(grausE);
	float somatorio2 = raio * cos(grausE + incA);
	float valor = 0;
	float incr = raio / 3;
	float raioC = raio * cos(graus);
	float raioC2 = raio * cos(graus - incR);
	for(int a = 0; a < camadas; a++){
		float grausR = 0.0f;

		for(int l = 0; l < 1; l++){
			glBegin(GL_TRIANGLES);
			
			
			vertices.push_back(vertex((altura + raio + somatorio) * cos(grausR), raio * cos(grausA), (altura + raio + somatorio) * sin(grausR)); 
			vertices.push_back(vertex((altura + raio + somatorio2) * cos(grausR + incR), raio * cos(grausA + incA), (altura + raio + somatorio2) * sin(grausR + incR));
			vertices.push_back(vertex((altura + raio + somatorio)  * cos(grausR + incR), raio * cos(grausA), (altura + raio + somatorio) * sin(grausR + incR));
			
			vertices.push_back(vertex((altura + raio - somatorio) * cos(grausR), raio * cos(grausA), (altura + raio - somatorio) * sin(grausR));
			vertices.push_back(vertex((altura + raio - somatorio2) * cos(grausR + incR), raio * cos(grausA + incA), (altura + raio - somatorio2) * sin(grausR + incR));
			vertices.push_back(vertex((altura + raio - somatorio2)  * cos(grausR), raio * cos(grausA + incA), (altura + raio - somatorio2) * sin(grausR));
			
			vertices.push_back(vertex((altura + raio - somatorio) * cos(grausR), raio * cos(grausA), (altura + raio - somatorio) * sin(grausR)); 
			vertices.push_back(vertex((altura + raio - somatorio) * cos(grausR + incR), raio * cos(grausA), (altura + raio - somatorio) * sin(grausR + incR));
			vertices.push_back(vertex((altura + raio - somatorio2)  * cos(grausR + incR), raio * cos(grausA + incA), (altura + raio - somatorio2) * sin(grausR + incR));
			
			glEnd();
			grausR = grausR + incR;
			graus = graus - incR;
			raioC = raio * sin(graus);
			raioC2 = raio * sin(graus - incR);
		}
		grausA = grausA + incA;
		grausE = grausE + incA;
		somatorio = raio * cos(grausE);
		somatorio2 = raio * cos(grausE + incA);		
	}*/
}

Copo::~Copo(){
	glDeleteBuffers(1,&vbo);
	delete pega;
}