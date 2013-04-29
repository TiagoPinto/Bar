#include "plano.h"
#include "cubo.h"
#include "cilindro.h"
#include "esfera.h"
#include "torus.h"
#include "piramide.h"
#include "mesa.h"
#include "cadeira.h"
#include "copo.h"
#include "candeeiro.h"
#include "bar.h"

//angulos de rotacao Sobre a propria figura
float angX= 0.0f, angY = 0.0f;
//angulos de rotacao da camara
float alfa = 0.0f, beta = 0.0f, raio = 20.0f;
float camX, camY, camZ;
float x = 0.0f;
float y = 0.0f;
float speed = 2.0f;
//Cores Iniciais
float red = 1.0f;
float green = 0.5f;
float blue = 0.0f;
//Opcao do menu para desenhar os objectos
int objecto = 0;

//Funcao da Camara em coordenadas polares
void converte() {

	camX = raio * cos(beta) * sin(alfa);
	camY = raio * sin(beta);
	camZ = raio * cos(beta) * cos(alfa);
}


//opcoes usadas no menuprincipal
void  menuPrincipal(int operador){
	switch(operador){
		case 0: objecto = 100; break;
		case 1: objecto = 0; break;
		case 2: 
		angX= 0.0f, angY = 0.0f;
		alfa = 0.0f; beta = 0.0f; raio = 6.0f;
		converte();
		x = 0.0f, y = 0.0f, speed = 3.0f; break;
		case 3: red = 1.0f, green = 0.5f, blue = 0.0f; break;
	}
}

//opcoes do sub-menu do estilo
void  menuEstilo(int operador){
	switch(operador) {
		case 1: glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); break; 
		case 2: glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); break; 
		case 3: glPolygonMode(GL_FRONT_AND_BACK,GL_POINT); break;
		case 4: glFrontFace(GL_CCW); break;
		case 5: glFrontFace(GL_CW); break;
	}
}

//opcoes do sub-menu da camara
void menuCamara(int operador){
	switch(operador){
		case 6: ; break;
		case 7: ; break;
	}
}

//opcoes do sub-menu das cores
void menuCor(int operador) {
	switch(operador) {
		case 8: red += 0.1f; green -= 0.1f; blue -= 0.1f; break;
		case 9: green += 0.1f; red -= 0.1f; blue -= 0.1f; break;
		case 10: blue += 0.1f; red -= 0.1f, green -= 0.1f; break;
	}
	if(red < 0.0f)
		red = 0.0f;
	if(red > 1.0f)
		red = 1.0f;
	if(green < 0.0f)
		green = 0.0f;
	if(green > 1.0f)
		green = 1.0f;
	if(blue < 0.0f)
		blue = 0.0f;
	if(blue > 1.0f)
		blue = 1.0f;
}

//opces do sub-menu das figuras
void menuObjecto(int operador)	{
	 objecto = operador;
}

// escrever função de processamento do menu
void criarMenu(){
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	int principal, estilo, camara, cor, objecto, plano, mesa, cadeira, candeeiro, copo;

	estilo = glutCreateMenu(menuEstilo);
		glutAddMenuEntry("Line", 1);
		glutAddMenuEntry("Fill", 2);
		glutAddMenuEntry("Point", 3);
		glutAddMenuEntry("CCW", 4);
		glutAddMenuEntry("CW", 5);
		

	camara = glutCreateMenu(menuCamara);
		glutAddMenuEntry("First Person",6);
		glutAddMenuEntry("Polar Coordenates",7);

	cor = glutCreateMenu(menuCor);
		glutAddMenuEntry("Red", 8);
		glutAddMenuEntry("Green", 9);
		glutAddMenuEntry("Blue", 10);

	plano = glutCreateMenu(menuObjecto);
		glutAddMenuEntry("PlanoXoY", 11);
		glutAddMenuEntry("PlanoXoZ", 12);
		glutAddMenuEntry("PlanoYoZ", 13);

	mesa = glutCreateMenu(menuObjecto);
		glutAddMenuEntry("Standard", 19);
		glutAddMenuEntry("Redonda", 20);
		glutAddMenuEntry("Medieval", 21);

	cadeira = glutCreateMenu(menuObjecto);
		glutAddMenuEntry("Standard", 22);
		glutAddMenuEntry("Banco", 23);
		glutAddMenuEntry("Medieval", 24);
		glutAddMenuEntry("Rei", 25);

	candeeiro = glutCreateMenu(menuObjecto);
		glutAddMenuEntry("Parede",26);
		glutAddMenuEntry("Candelabro",27);


	copo = glutCreateMenu(menuObjecto);
		glutAddMenuEntry("Standard", 28);
		glutAddMenuEntry("Caneca", 29);
		glutAddMenuEntry("Calice", 30);
		glutAddMenuEntry("Corno", 31);

	objecto = glutCreateMenu(menuObjecto);
		glutAddSubMenu("Planos", plano);
		glutAddMenuEntry("Cubo", 14);
		glutAddMenuEntry("Cilindro", 15);
		glutAddMenuEntry("Esfera", 16);
		glutAddMenuEntry("Torus",17);
		glutAddMenuEntry("Piramide", 18);
		glutAddSubMenu("Mesa", mesa);
		glutAddSubMenu("Cadeira", cadeira);
		glutAddSubMenu("Candeeiro", candeeiro);
		glutAddSubMenu("Copo", copo);
		
	principal = glutCreateMenu(menuPrincipal);
		glutAddMenuEntry("Bar", 0);
		glutAddMenuEntry("Limpar",1);
		glutAddMenuEntry("Reset Camara", 2);
		glutAddMenuEntry("Reset Cor", 3);
		glutAddSubMenu("Modo dos Poligonos",estilo);
		glutAddSubMenu("Modo da Camara", camara);
		glutAddSubMenu("Cores",cor);
		glutAddSubMenu("Objectos",objecto);
		glutAttachMenu(GLUT_RIGHT_BUTTON);
}
