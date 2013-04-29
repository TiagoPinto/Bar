#include "includes.h"
#include "menu.h"

Cilindro *cilindro = new Cilindro(2.0f,1.0f,70.0f,3.0f);
Cubo *cubo;
Plano *plano;
Esfera *esfera = new Esfera(1.0f,20.0f,20.0f);
Torus *torus = new Torus(1.0f,0.5f,4.0f,2.0f);
Piramide *piramide = new Piramide(2, 2, 2, 3, 2);
Mesa *mesa;
Cadeira *cadeira = new Cadeira(2.0f, 1.0f, 1.5f, 0.1f, 5.0f, 5.0f);
Copo *copo = new Copo(0.8f,2.0f,0.2f,50.0f,2.0f);
Bar *bar = new Bar(50, 60, 6, 8, 2);
Candeeiro *candeeiro = new Candeeiro(2,3,15,4);


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
	gluLookAt(camX,camY,camZ, 
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
		case 100: bar->desenha(); break;
		case 11: plano = new Plano(2.0f,1.0f,1.0f,3.0f,1); plano->desenha(); break;
		case 12: plano = new Plano(2.0f,1.0f,1.0f,3.0f,2); plano->desenha(); break;
		case 13: plano = new Plano(2.0f,1.0f,1.0f,3.0f,3); plano->desenha(); break;
		case 14: cubo->desenha(); break;
		case 15: cilindro->desenha(); break;
		case 16: esfera->desenha(); break;
		case 17: torus->desenha(); break;
		case 18: piramide->desenhaR(); break;
		case 19: mesa->desenhaA(); break;
		case 20: mesa->desenhaB(); break;
		case 21: mesa->desenhaC(); break;
		case 22: cadeira->desenhaA(); break;
		case 23: cadeira->desenhaB(); break;
		case 24: cadeira-> desenhaC(); break;
		case 25: cadeira->desenhaD(); break;
		case 26: candeeiro->desenhaA(); break;
		case 27: candeeiro->desenhaB(); break;
		case 28: copo->desenhaA(); break;
		case 29: copo->desenhaB(); break;
		case 30: copo->desenhaC(); break;
		case 31: copo->desenhaD(); break;

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
	
	alfa = -speed*(diff_x/400);

	beta = speed*(diff_y/300);
	if (beta > 1.5f)
		beta = 1.5f;
	if (beta < -1.5f)
		beta = -1.5f;
	converte();
	glutPostRedisplay();
}

void rato(int botao, int estado, int x, int y){
	switch(botao){
		case 3:
			raio=+1.0f; break;
		case 4:
			raio =-1.0f; break;
	}
}

int main(int argc, char **argv) {

// inicialização
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(300,100);
	glutInitWindowSize(800,600);
	glutCreateWindow("Bar@DI-UM");
	glewInit();	

// registo de funções 
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);

// pôr aqui registo da funções do teclado e rato
	glutSpecialFunc(keyboard);
	glutMotionFunc(mouse);
	glutMouseFunc(rato);
// pôr aqui a criação do menu
	criarMenu();
	converte();
// alguns settings para OpenGL
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnableClientState(GL_VERTEX_ARRAY);

cubo = new Cubo(2.0f,1.0f,1.5f,4.0f,2.0f);
mesa = new Mesa(3.0f,2.0f,1.0f, 0.2f, 20.0f, 4.0f);

//init
	converte();

// entrar no ciclo do GLUT 
	glutMainLoop();
	
	return 1;
}