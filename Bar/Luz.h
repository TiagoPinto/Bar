//=================================
// include guard
#ifndef __LUZ_H_INCLUDED__
#define __LUZ_H_INCLUDED__

#include <GL/glew.h>
#include <GL/glut.h>

class Luz {
	public:
		float pos[4]; //= {x, y, z, 0.0};
		GLfloat specularLight[3];
		GLfloat ambientLight[3];
		GLfloat diffuseLight[3];
		float c;
		float l;
		float q;

		Luz(){};
		Luz(float x, float y, float z,float w);
		Luz(float x,float y,float z);
		void setConstant(float co){this->c=co;}
		void setLinear(float li){this->l=li;}
		void setQuadratic(float qu){this->q=qu;}
		float getConstant(){ return this->c;}
		float getLinear(){ return this->l;}
		float getQuadratic(){ return this->q;}
		void setLuzMaterial();
		void mudaLuz(int n);
		void luzSetAmbient(GLfloat ambient[3]) ;		
		void luzSetDiffuse(GLfloat diffuse[3]) ;
		void luzSetSpecular(GLfloat specular[3]);
		void luzSetModel(GLfloat ambient[3],GLfloat diffuse[3],GLfloat specular[3]);
		void luzModelAssign(int i);
		void luzSetAtt(float c,float l,float q);
		void luzAttAssign(int i);
		void luzSpot();
		void setLuzPosition(float x,float y,float z);
};

#endif