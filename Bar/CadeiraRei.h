#pragma once
class Cubo;
class Esfera;
class Cilindro;
class CadeiraRei{
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
	Esfera *ornamento[2];
	Cubo *bracos[4];
	Cilindro *metade;
	
public:
	CadeiraRei();
	CadeiraRei(float c, float l, float a, float e, float f, float p, GLuint idtex, GLuint idbola);
	void desenhaBasePernas();
	void desenhaD();
	~CadeiraRei();
};