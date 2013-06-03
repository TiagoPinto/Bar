#pragma once
class Cubo;
class Anel;
class CadeiraBanco;
class Copo;
class Balcao{
private:
	float comprimento;
	float largura;
	float altura;
	float fatias;
	float camadas;
	GLuint textura;
	GLuint texVidro;
	GLuint texFerro;
	GLuint vbo;
	int nVertices;
	Cubo *balcao;
	Anel *anel;
	CadeiraBanco *banco;
	Copo *copo[3];

public:
	Balcao();
	Balcao(float comp, float l, float a, float f, float c, GLuint idtex, GLuint idvidro, GLuint idferro);
	void desenha();
	~Balcao();
};