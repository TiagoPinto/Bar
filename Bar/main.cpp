#include "includes.h"
#include "menu.h"

Bar *bar = new Bar(50, 60, 6, 8, 2);
Plano *plano1, *plano2, *plano3;
Cubo *cubo;
Cilindro *cilindro;
Esfera *esfera;
Torus *torus;
Piramide *piramide;
Mesa *mesa;
Cadeira *cadeira;
Copo *copo, *caneca;
Candeeiro *candeeiro, *candelabro;


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

	float pos[4] = {0.0, 0.0, 1.0, 0.0};
	GLfloat whiteSpecularLight[] = {0.8, 0.8, 0.8}; 
	GLfloat blackAmbientLight[] = {0.2, 0.2, 0.2};
	GLfloat whiteDiffuseLight[] = {1.0, 1.0, 1.0};
	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glLightfv(GL_LIGHT0, GL_SPECULAR, whiteSpecularLight);
	glLightfv(GL_LIGHT0, GL_AMBIENT, blackAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteDiffuseLight);

	// set the camera
	glLoadIdentity();
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
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
		case 11: plano1->desenha(); break;
		case 12: plano2->desenha(); break;
		case 13: plano3->desenha(); break;
		case 14: cubo->desenha(); break;
		case 15: cilindro->desenha(); break;
		case 16: esfera->desenha(); break;
		case 17: torus->desenha(); break;
		case 18: piramide->desenha(); break;
		case 19: mesa->desenhaA(); break;
		case 20: mesa->desenhaB(); break;
		case 21: mesa->desenhaC(); break;
		case 22: cadeira->desenhaA(); break;
		case 23: cadeira->desenhaB(); break;
		case 24: cadeira-> desenhaC(); break;
		case 25: cadeira->desenhaD(); break;
		case 26: candeeiro->desenhaA(); break;
		case 27: candelabro->desenhaB(); break;
		case 28: copo->desenha(); break;
		case 29: caneca->desenha(); break;
		/*case 30: copo->desenhaC(); break;
		case 31: copo->desenhaD(); break;*/

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
	glEnableClientState(GL_NORMAL_ARRAY);

//init
	converte();
	esfera = new Esfera(1.0f,20.0f,20.0f,1);
	mesa = new Mesa(3.0f,2.0f,1.0f, 0.2f, 20.0f, 4.0f);
	cadeira = new Cadeira(2.0f, 1.0f, 1.5f, 0.1f, 5.0f, 5.0f);
	cilindro = new Cilindro(5.0f,1.0f,50.0f,3.0f,1);
	cubo = new Cubo(2.0f,1.0f,1.5f,4.0f,2.0f);
	plano1 = new Plano(2.0f,1.0f,1.0f,3.0f,1);
	plano2 = new Plano(2.0f,1.0f,1.0f,3.0f,2);
	plano3 = new Plano(2.0f,1.0f,1.0f,3.0f,3);
	torus = new Torus(1.0f,0.5f,6.0f,3.0f,1);
	piramide = new Piramide(2.0f, 2.0f, 2.0f, 3.0f, 2.0f);
	candeeiro = new Candeeiro(2.0f,3.0f,14.0f,4.0f);
	candelabro = new Candeeiro(2.0f,3.0f,14.0f,4.0f);
	candelabro->preparaB();
	copo = new Copo(0.8f,2.0f,0.1f,50.0f,5.0f,1);
	caneca = new Copo(0.8f,2.0f,0.1f,20.0f,3.0f,2);

	// inicialização da luz
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_COLOR_MATERIAL);

// entrar no ciclo do GLUT 
	glutMainLoop();
	
	return 1;
}