#include <GL/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include "plano.h"
#include "cubo.h"
#include "cilindro.h"
#include "esfera.h"

float angX= 0.0f, angY = 0.0f;
float angB = 0.0f;
float angO = 0.0f;
float raioC = 6.0f;
float x = 0.0f;
float y = 0.0f;
float speed = 1000;

Cilindro *cilindro = new Cilindro(1.1f,1.1f,7.0f,1.0f);
Cubo *cubo = new Cubo(2.0f,1.0f,3.0f,10.0f,1.0f);
Plano *plano = new Plano(2.0f,1.0f,1.0f,3.0f);
Esfera *esfera = new Esfera(1.0f,20.0f,20.0f);
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

    /*glColor3f (0.0, 1.0, 0.0); // Green for x axis
    glVertex3f(-5,0,0);
    glVertex3f(5,0,0);

    glColor3f(1.0,0.0,0.0); // Red for y axis
    glVertex3f(0,-5,0);

    glVertex3f(0,6,0);

    glColor3f(0.0,0.0,1.0); // Blue for z axis
    glVertex3f(0,0,-10); 
    glVertex3f(0,0,10);
	*/
    glEnd();

// pôr instruções de desenho aqui
	glColor3f(1.0f,0.5f,0.0f);
	glRotatef(angX,0.0,1.0,0.0);
	glRotatef(angY,1,0,0);
	cilindro->desenha();
	//plano->desenhaXoY();
	//plano->desenhaXoZ();
	//plano->desenhaYoZ();
	//cubo->desenha();
	//esfera->desenha();
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
	
	angX = speed*(diff_x/400);
	angY = speed*(diff_y/300);
}


// escrever função de processamento do menu




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

// pôr aqui a criação do menu


// alguns settings para OpenGL
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	
// entrar no ciclo do GLUT 
	glutMainLoop();
	
	return 1;
}