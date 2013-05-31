#pragma once
class Cilindro;
class CadeiraBanco{
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
	Cilindro *base;
	Cilindro *perna[4];
	
public:
	CadeiraBanco();
	CadeiraBanco(float c, float l, float a, float e, float f, float p, GLuint idtex);
	void desenhaBasePernas();
	void desenhaB();
	~CadeiraBanco();
};