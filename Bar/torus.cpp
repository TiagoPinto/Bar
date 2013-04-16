#define _USE_MATH_DEFINES
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
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

Torus::Torus(float ri, float re, float f, float c){
	this->raioI = ri;
	this->raioE = re;
	this->fatias = f; 
	this->camadas = c;
}

void Torus::desenha(){
	float incR = 2 * M_PI / fatias;
	float incA = M_PI / (camadas);
	float grausA = -M_PI;
	float grausE = -M_PI/2;
	float somatorio = raioE * cos(grausE);
	float somatorio2 = raioE * cos(grausE + incA);
	for(int a = 0; a < camadas; a++){
		float grausR = 0.0f;
		for(int l = 0; l < fatias; l++){
			glBegin(GL_TRIANGLES);
			glVertex3f((raioI + raioE + somatorio) * cos(grausR), raioE * cos(grausA), (raioI + raioE + somatorio) * sin(grausR)); 
			glVertex3f((raioI + raioE + somatorio2)  * cos(grausR), raioE * cos(grausA + incA), (raioI + raioE + somatorio2) * sin(grausR));
			glVertex3f((raioI + raioE + somatorio2) * cos(grausR + incR), raioE * cos(grausA + incA), (raioI + raioE + somatorio2) * sin(grausR + incR));

			glVertex3f((raioI + raioE + somatorio) * cos(grausR), raioE * cos(grausA), (raioI + raioE + somatorio) * sin(grausR)); 
			glVertex3f((raioI + raioE + somatorio2) * cos(grausR + incR), raioE * cos(grausA + incA), (raioI + raioE + somatorio2) * sin(grausR + incR));
			glVertex3f((raioI + raioE + somatorio)  * cos(grausR + incR), raioE * cos(grausA), (raioI + raioE + somatorio) * sin(grausR + incR));
			
			glVertex3f((raioI + raioE - somatorio) * cos(grausR), raioE * cos(grausA), (raioI + raioE - somatorio) * sin(grausR));
			glVertex3f((raioI + raioE - somatorio2) * cos(grausR + incR), raioE * cos(grausA + incA), (raioI + raioE - somatorio2) * sin(grausR + incR));
			glVertex3f((raioI + raioE - somatorio2)  * cos(grausR), raioE * cos(grausA + incA), (raioI + raioE - somatorio2) * sin(grausR));
			
			glVertex3f((raioI + raioE - somatorio) * cos(grausR), raioE * cos(grausA), (raioI + raioE - somatorio) * sin(grausR)); 
			glVertex3f((raioI + raioE - somatorio) * cos(grausR + incR), raioE * cos(grausA), (raioI + raioE - somatorio) * sin(grausR + incR));
			glVertex3f((raioI + raioE - somatorio2)  * cos(grausR + incR), raioE * cos(grausA + incA), (raioI + raioE - somatorio2) * sin(grausR + incR));
			glEnd();
			grausR = grausR + incR;
		}
		grausA = grausA + incA;
		grausE = grausE + incA;
		somatorio = raioE * cos(grausE);
		somatorio2 = raioE * cos(grausE + incA);		
	}
}

void Torus::meioTorus(){
	float incR = M_PI / fatias;
	float incA = M_PI / (camadas);
	float grausA = -M_PI;
	float grausE = -M_PI/2;
	float somatorio = raioE * cos(grausE);
	float somatorio2 = raioE * cos(grausE + incA);
	for(int a = 0; a < camadas; a++){
		float grausR = 0.0f;
		for(int l = 0; l < fatias; l++){
			glBegin(GL_TRIANGLES);
			glVertex3f((raioI + raioE + somatorio) * cos(grausR), raioE * cos(grausA), (raioI + raioE + somatorio) * sin(grausR)); 
			glVertex3f((raioI + raioE + somatorio2)  * cos(grausR), raioE * cos(grausA + incA), (raioI + raioE + somatorio2) * sin(grausR));
			glVertex3f((raioI + raioE + somatorio2) * cos(grausR + incR), raioE * cos(grausA + incA), (raioI + raioE + somatorio2) * sin(grausR + incR));

			glVertex3f((raioI + raioE + somatorio) * cos(grausR), raioE * cos(grausA), (raioI + raioE + somatorio) * sin(grausR)); 
			glVertex3f((raioI + raioE + somatorio2) * cos(grausR + incR), raioE * cos(grausA + incA), (raioI + raioE + somatorio2) * sin(grausR + incR));
			glVertex3f((raioI + raioE + somatorio)  * cos(grausR + incR), raioE * cos(grausA), (raioI + raioE + somatorio) * sin(grausR + incR));
			
			glVertex3f((raioI + raioE - somatorio) * cos(grausR), raioE * cos(grausA), (raioI + raioE - somatorio) * sin(grausR));
			glVertex3f((raioI + raioE - somatorio2) * cos(grausR + incR), raioE * cos(grausA + incA), (raioI + raioE - somatorio2) * sin(grausR + incR));
			glVertex3f((raioI + raioE - somatorio2)  * cos(grausR), raioE * cos(grausA + incA), (raioI + raioE - somatorio2) * sin(grausR));
			
			glVertex3f((raioI + raioE - somatorio) * cos(grausR), raioE * cos(grausA), (raioI + raioE - somatorio) * sin(grausR)); 
			glVertex3f((raioI + raioE - somatorio) * cos(grausR + incR), raioE * cos(grausA), (raioI + raioE - somatorio) * sin(grausR + incR));
			glVertex3f((raioI + raioE - somatorio2)  * cos(grausR + incR), raioE * cos(grausA + incA), (raioI + raioE - somatorio2) * sin(grausR + incR));
			glEnd();
			grausR = grausR + incR;
		}
		grausA = grausA + incA;
		grausE = grausE + incA;
		somatorio = raioE * cos(grausE);
		somatorio2 = raioE * cos(grausE + incA);		
	}
}