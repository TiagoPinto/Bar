#pragma once
class Cilindro;
class CandeeiroMesa{
	private:
		float comprimento;
		float altura;
		float fatias;
		float camadas;
		GLuint texturaFerro;
		GLuint texturaVela;
		GLuint vbo;
		int nVertices;
		Cilindro *base;
		Cilindro *segurador[2];
		Cilindro *vela;

	public:
		CandeeiroMesa();
		CandeeiroMesa(float c, float a, float f, float p, GLuint idFerro, GLuint idVela);
		void desenha();
		~CandeeiroMesa();
};