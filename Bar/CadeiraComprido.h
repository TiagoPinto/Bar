#pragma once
class Cubo;
class CadeiraComprido{
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
	Cubo *tabua[3];
	
public:
	CadeiraComprido();
	CadeiraComprido(float c, float l, float a, float e, float f, float p, GLuint idtex);
	void desenhaBasePernas();
	void desenhaC();
	~CadeiraComprido();
};