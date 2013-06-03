#include "includes.h"
#include "Luz.h"

Luz::Luz(float x,float y,float z) {
	this->pos[0]=x;
	this->pos[1]=y;
	this->pos[2]=z;
	this->pos[3]=1.0;

	//Por omissao, luz "branca"
	this->ambientLight[0] = this->ambientLight[1] = this->ambientLight[2] = 0.1;
	this->diffuseLight[0] = this->diffuseLight[1] = this->diffuseLight[2] = 0.9;
	this->specularLight[0]=this->specularLight[1]=this->specularLight[2]= 0.1;

	this->c=1;
	this->l=0;
	this->q=0;
}


Luz::Luz(float x,float y, float z,float w) {
	this->pos[0]=x;
	this->pos[1]=y;
	this->pos[2]=z;
	this->pos[3]=w;

	//Por omissao, luz "branca"
	this->ambientLight[0] = this->ambientLight[1] = this->ambientLight[2] = 0.1;
	this->diffuseLight[0] = this->diffuseLight[1] = this->diffuseLight[2] = 0.9;
	this->specularLight[0]=this->specularLight[1]=this->specularLight[2]= 0.1;

	this->c=1;
	this->l=0;
	this->q=0;
}

void Luz::setLuzPosition(float x,float y,float z) {
	this->pos[0]=x;
	this->pos[1]=y;
	this->pos[2]=z;
}

void Luz::luzSetAmbient(GLfloat ambient[3]) {
		for(int i=0; i<3; i++) {
		this->ambientLight[i] = ambient[i];
		}
}
void Luz::luzSetDiffuse(GLfloat diffuse[3]) {
		for(int i=0; i<3; i++) {
		this->diffuseLight[i] = diffuse[i];
		}
}
void Luz::luzSetSpecular(GLfloat specular[3]) {
		for(int i=0; i<3; i++) {
		this->specularLight[i] = specular[i];
		}
}

void Luz::luzSetModel(GLfloat ambient[3],GLfloat diffuse[3],GLfloat specular[3]) {

	for(int i=0; i<3; i++) {
		this->ambientLight[i] = ambient[i];
		this->diffuseLight[i] = diffuse[i];
		this->specularLight[i]= specular[i];
	}
}

void Luz::luzModelAssign(int indice) {

	if(indice<8){
				glLightfv(GL_LIGHT0+indice, GL_SPECULAR, this->specularLight);
				glLightfv(GL_LIGHT0+indice, GL_AMBIENT, this->ambientLight);
				glLightfv(GL_LIGHT0+indice, GL_DIFFUSE, this->diffuseLight);
	}
}

void Luz::luzSetAtt(float co,float li,float qu) {
	this->c = co;
	this->l = li;
	this->q = qu;
}

void Luz::luzAttAssign(int indice) {

	if(indice<8){
				glLightf(GL_LIGHT0+indice, GL_CONSTANT_ATTENUATION, this->c);
				glLightf(GL_LIGHT0+indice, GL_LINEAR_ATTENUATION, this->l);
				glLightf(GL_LIGHT0+indice, GL_QUADRATIC_ATTENUATION, this->q);
	}
}


void luzSpot(){
	GLfloat spot_direction[] = { -1.0, -1.0, 0.0 };
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);
}

void Luz::setLuzMaterial() {
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_DIFFUSE);
	/* now glColor* changes diffuse reflection  */
	glColor3f(0.2, 0.5, 0.8);
	/* draw some objects here */
	glColorMaterial(GL_FRONT, GL_SPECULAR);
	/* glColor* no longer changes diffuse reflection  */
	/* now glColor* changes specular reflection  */
	glColor3f(0.9, 0.0, 0.2);
	/* draw other objects here */
	glDisable(GL_COLOR_MATERIAL);
}

void Luz::mudaLuz(int n) {
	//if(luzFlag==1) glEnable(GL_LIGHT0);

}