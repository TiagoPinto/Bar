#pragma once
class Cubo;
class CadeiraStandart{
private:
	float comprimento;
	float largura;
	float altura;
	float espessura;
	float fatias;
	float camadas;
	GLuint textura;
	GLuint vbo;
	int nVertices;
	Cubo *base;
	Cubo *perna[4];
	Cubo *costas;
	Cubo *tabua[4];
	
public:
	CadeiraStandart();
	CadeiraStandart(float c, float l, float a, float e, float f, float p, GLuint idtex);
	void desenhaBasePernas();
	void desenhaA();
	~CadeiraStandart();
};