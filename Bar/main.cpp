#include <GL/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include "plano.h"
#include "cubo.h"
#include "cilindro.h"
#include "esfera.h"
#include "mesa.h"
#include "cadeira.h"
#include "copo.h"

//angulos de rotacao Sobre a propria figura
float angX= 0.0f, angY = 0.0f;
//angulos de rotacao da camara
float angB = 0.0f;
float angO = 0.0f;
float raioC = 6.0f;
float x = 0.0f;
float y = 0.0f;
float speed = 3.0f;
//Cores Iniciais
float red = 1.0f;
float green = 0.5f;
float blue = 0.0f;
//Opcao do menu para desenhar os objectos
int objecto = 0;


Cilindro *cilindro = new Cilindro(2.0f,1.0f,10.0f,3.0f);
Cubo *cubo = new Cubo(2.0f,1.0f,1.5f,3.0f,2.0f);
Plano *plano = new Plano(2.0f,1.0f,1.0f,3.0f);
Esfera *esfera = new Esfera(1.0f,20.0f,20.0f);
Mesa *mesa = new Mesa(3.0f,2.0f,1.0f, 0.2f, 20.0f, 4.0f);
Cadeira *cadeira = new Cadeira(2.0f, 0.7f, 1.5f, 0.1f, 10.0f, 10.0f);

Copo *copo = new Copo(1.0f,2.0f,0.1f,10.0f,5.0f);

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if(h == 0)
		h = 1;

	// compute window's aspect ratio 
	float ratio = w * 1.0 / h;

	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);
	// Load Identity Matrix
	glLoadIdentity();
	
	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);

	// Set perspective
	gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}



void renderScene(void) {

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(raioC*sin(angB),raioC*cos(angB)*sin(angO),raioC*cos(angB)*cos(angO), 
		      0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);

	//Eixos	
	glBegin(GL_LINES);

    glColor3f (0.0, 1.0, 0.0); // Green for x axis
    glVertex3f(-5,0,0);
    glVertex3f(5,0,0);

    glColor3f(1.0,0.0,0.0); // Red for y axis
    glVertex3f(0,-5,0);

    glVertex3f(0,6,0);

    glColor3f(0.0,0.0,1.0); // Blue for z axis
    glVertex3f(0,0,-10); 
    glVertex3f(0,0,10);
	
    glEnd();

// pôr instruções de desenho aqui
	glColor3f(red, green, blue);
	glRotatef(angX, 0.0f, 1.0f, 0.0f);
	glRotatef(angY, 1.0f, 0.0f, 0.0f);

	switch(objecto) {
		case 11: plano->desenhaXoY(); break;
		case 12: plano->desenhaXoZ(); break;
		case 13: plano->desenhaYoZ(); break;
		case 14: cubo->desenha(); break;
		case 15: cilindro->desenha(); break;
		case 16: esfera->desenha(); break;
		case 17: mesa->desenhaA(); break;
		case 18: mesa->desenhaB(); break;
		case 19: mesa->desenhaC(); break;
		case 20: cadeira->desenhaA(); break;
		case 21: cadeira->desenhaB(); break;
		case 22: cadeira-> desenhaC(); break;
		case 23: cadeira->desenhaD(); break;
		case 24: copo->desenhaA(); break;

	}
	//End of frame
	glutSwapBuffers();
}



// escrever função de processamento do teclado
void keyboard(int tecla, int x, int y){
	switch(tecla){

		case GLUT_KEY_LEFT:
			angX-= 10.0f;
			break;
		case GLUT_KEY_RIGHT:
			angX+=10.0f;
			break;
		case GLUT_KEY_UP:
			angY -= 10.0f;
			break;
		case GLUT_KEY_DOWN:
			angY += 10.0f;
			break;
	}
}

void mouse(int x, int y){
	float diff_x = x - 400;
	float diff_y = y - 300;
	
	angB = -speed*(diff_x/400);
	angO = speed*(diff_y/300);
}

void  menuPrincipal(int operador){
	switch(operador){
		case 0: ; break;
		case 1: objecto = 0; break;
		case 2: 
		angX= 0.0f, angY = 0.0f;
		angB = 0.0f, angO = 0.0f, raioC = 6.0f;
		x = 0.0f, y = 0.0f, speed = 3.0f; break;
		case 3: red = 1.0f, green = 0.5f, blue = 0.0f; break;
	}
}

void  menuEstilo(int operador){
	switch(operador) {
		case 1: glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); break; 
		case 2: glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); break; 
		case 3: glPolygonMode(GL_FRONT_AND_BACK,GL_POINT); break;
		case 4: glFrontFace(GL_CCW); break;
		case 5: glFrontFace(GL_CW); break;
	}
}

void menuCamara(int operador){
	switch(operador){
		case 6: ; break;
		case 7: ; break;
	}
}

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
		glutAddMenuEntry("Standard", 17);
		glutAddMenuEntry("Redonda", 18);
		glutAddMenuEntry("Medieval", 19);

	cadeira = glutCreateMenu(menuObjecto);
		glutAddMenuEntry("Standard", 20);
		glutAddMenuEntry("Banco", 21);
		glutAddMenuEntry("Medieval", 22);
		glutAddMenuEntry("Rei", 23);

	copo = glutCreateMenu(menuObjecto);
		glutAddMenuEntry("Standard", 24);
		glutAddMenuEntry("Caneca", 25);
		glutAddMenuEntry("Vinho", 26);
		glutAddMenuEntry("Corno", 27);

	objecto = glutCreateMenu(menuObjecto);
		glutAddSubMenu("Planos", plano);
		glutAddMenuEntry("Cubo", 14);
		glutAddMenuEntry("Cilindro", 15);
		glutAddMenuEntry("Esfera", 16);
		glutAddSubMenu("Mesa", mesa);
		glutAddSubMenu("Cadeira", cadeira);
		//glutAddSubMenu("Candeeiro", candeeiro);
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



int main(int argc, char **argv) {

// inicialização
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(300,100);
	glutInitWindowSize(800,600);
	glutCreateWindow("Bar@DI-UM");
		

// registo de funções 
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);

// pôr aqui registo da funções do teclado e rato
	glutSpecialFunc(keyboard);
	glutMotionFunc(mouse);
	glutPostRedisplay();
// pôr aqui a criação do menu
	criarMenu();

// alguns settings para OpenGL
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	
// entrar no ciclo do GLUT 
	glutMainLoop();
	
	return 1;
}