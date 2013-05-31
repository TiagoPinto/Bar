#pragma once

class Cubo;
class Plano;
class Piramide;
class Cilindro;
class CandeeiroParede{
	private:
		float comprimento;
		float altura;
		float fatias;
		float camadas;
		GLuint texturaMadeira;
		GLuint texturaVidro;
		GLuint texturaVela;
		GLuint vbo;
		int nVertices;
		Cubo *base;
		Cubo *segurador[2];
		Plano *caixa[9];
		Cilindro *vela;
		Piramide *topo;

	public:
		CandeeiroParede();
		CandeeiroParede(float c, float a, float f, float p, GLuint idtex, GLuint idvidro, GLuint idvela);
		void desenhaA();
		~CandeeiroParede();
};