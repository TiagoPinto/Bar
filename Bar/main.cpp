#include "includes.h"
#include "objectos.h"
#include "menu.h"
#include <IL/il.h>

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
	if(camCamara == 0){
	gluLookAt(camara.m_vPosition.x,	camara.m_vPosition.y,	camara.m_vPosition.z, 
		      camara.m_vView.x,		camara.m_vView.y,		camara.m_vView.z,
			  camara.m_vUpVector.x,	camara.m_vUpVector.y,	camara.m_vUpVector.z);
	}
	if(camCamara == 1){
		gluLookAt(camX,camY,camZ, 
			0.0,0.0,0.0,
			0.0f,1.0f,0.0f);
	}

// pôr instruções de desenho aqui
	glColor3f(red, green, blue);
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
		case 19: mesastandart->desenhaA(); break;
		case 20: mesaredonda->desenhaB(); break;
		case 21: mesarectangular->desenhaC(); break;
		case 22: cadeiraStandart->desenhaA(); break;
		case 23: cadeiraBanco->desenhaB(); break;
		case 24: cadeira-> desenhaC(); break;
		case 25: cadeiraRei->desenhaD(); break;
		case 26: candeeiroParede->desenhaA(); break;
		case 27: candelabro->desenhaB(); break;
		case 28: copo->desenha(); break;
		case 29: caneca->desenha(); break;
		case 30: candeeiroMesa->desenha(); break;
		//case 31: copo->desenhaD(); break;

	}
	//End of frame
	glutSwapBuffers();
}

//funções de processamento do teclado
void keyBoardEspecial(int tecla, int x, int y){
	switch(tecla) {
		case GLUT_KEY_RIGHT ://olha para a direita (+ rapido)
			camara.SetViewByMouse(-0.02, 0.0);
			break;
		case GLUT_KEY_LEFT ://olha para a esquerda (+ rapido)
			camara.SetViewByMouse(0.02, 0.0);
			break;
		case GLUT_KEY_UP ://olha para cima (+ rapido)
			camara.SetViewByMouse(0.0, 0.02);
			break;
		case GLUT_KEY_DOWN ://olha para baixo (+ rapido)
			camara.SetViewByMouse(0.0, -0.02);
			break;
		default:
			break; 
	}
	glutPostRedisplay();
}

void keyBoard(unsigned char tecla, int x, int y){
	switch(tecla) {
		case 'W' :
		case 'w' ://move a camara para a frente (+ rapido)
			camara.MoveCamera(0.2);
			break;
		case 'S' :
		case 's' ://move a camara para tras (+ rapido)
			camara.MoveCamera(-0.2);
			break;
		case 'a':
		case 'A'://move a camara para a esquerda (+ rapido)
			camara.MoveCameraSides(0.2);
			break;
		case 'd':
		case 'D'://move a camara para a direita (+ rapido)
			camara.MoveCameraSides(-0.2);
			break;
		case 'L' :
		case 'l' ://olha para a direita (+ lento)
			camara.SetViewByMouse(-0.01, 0.0);
			break;
		case 'J' :
		case 'j' ://olha para a esquerda (+ lento)
			camara.SetViewByMouse(0.01, 0.0);
			break;
		case 'I' :
		case 'i' ://olha para cima (+ lento)
			camara.SetViewByMouse(0.0, 0.01);
			break;
		case 'K' :
		case 'k' ://olha para baixo (+ lento)
			camara.SetViewByMouse(0.0, -0.01);
			break;
		case '+'://sobe a camara
			camara.m_vPosition.y += 0.3;
			camara.m_vView.y += 0.3;
			break;
		case '-'://desce a camara
			camara.m_vPosition.y -= 0.3;
			camara.m_vView.y -= 0.3;
			break;
		case 27 :
			exit(0);
		break;
		default:
			break;
		}
	glutPostRedisplay();
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
	glutSpecialFunc(keyBoardEspecial);
	glutKeyboardFunc(keyBoard);
	glutMotionFunc(mouse);
// pôr aqui a criação do menu
	criarMenu();
	converte();
// alguns settings para OpenGL
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_TEXTURE_2D);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	ilInit();
//init
	converte();
	GLuint texchao = getTextura("texturas/chao.png");
	GLuint textura = getTextura("texturas/boda.png");
	GLuint parede = getTextura("texturas/parede.png");
	GLuint globo = getTextura("texturas/globo.jpg");
	GLuint ferro = getTextura("texturas/ferro.jpg");
	GLuint vela = getTextura("texturas/vela.jpg");
	GLuint madeira = getTextura("texturas/madeira.jpg");
	GLuint madeira2 = getTextura("texturas/madeira3.jpg");
	GLuint porta = getTextura("texturas/porta.jpg");
	GLuint vidro = getTextura("texturas/vidro.jpg");
	esfera = new Esfera(1.0f,20.0f,20.0f,1, globo);
	mesastandart = new MesaStandart(3.0f,2.0f,1.0f, 0.2f, 20.0f, 4.0f, madeira2);
	mesaredonda = new MesaRedonda(3.0f,2.0f,1.0f, 0.2f, 20.0f, 4.0f, madeira2);
	mesarectangular = new MesaRectangular(3.0f,2.0f,1.0f, 0.2f, 20.0f, 4.0f, madeira2);
	cadeira = new CadeiraComprido(3.0f, 0.5f, 1.0f, 0.1f, 5.0f, 5.0f, madeira2);
	cadeiraBanco = new CadeiraBanco(0.5f, 0.5f, 0.7f, 0.1f, 5.0f, 5.0f, madeira);
	cadeiraStandart = new CadeiraStandart(1.0f, 1.0f, 1.5f, 0.1f, 5.0f, 5.0f, madeira2);
	cadeiraRei = new CadeiraRei(1.0f, 1.0f, 1.5f, 0.15f, 5.0f, 5.0f, madeira2, vidro);
	cilindro = new Cilindro(2.0f,1.0f,40.0f,10.0f,1,vela);
	cubo = new Cubo(2.0f,1.0f,1.5f,4.0f,4.0f, porta);
	plano1 = new Plano(2.0f,1.0f,1.0f,1.0f,1,porta);
	plano2 = new Plano(2.0f,1.0f,1.0f,3.0f,2,texchao);
	plano3 = new Plano(2.0f,1.0f,1.0f,1.0f,3,texchao);
	torus = new Torus(1.0f,0.5f,6.0f,3.0f,1, globo);
	piramide = new Piramide(2.0f, 2.0f, 2.0f, 2.0f, 2.0f, globo);
	candeeiroParede = new CandeeiroParede(2.0f,3.0f,14.0f,4.0f,madeira,vidro,vela);
	candelabro = new CandeeiroCandelabro(2.0f,3.0f,14.0f,4.0f, ferro, vela, madeira);
	candeeiroMesa = new CandeeiroMesa(1,2,10,10,ferro, vela);
	candelabro->preparaB();
	copo = new Copo(0.8f,2.0f,0.1f,30.0f,5.0f,1, vidro);
	caneca = new Copo(0.8f,2.0f,0.1f,20.0f,3.0f,2, vidro);
	bar = new Bar(15, 25, 2, 15, 5);

	// inicialização da luz
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_COLOR_MATERIAL);

// entrar no ciclo do GLUT 
	glutMainLoop();
	
	return 1;
}