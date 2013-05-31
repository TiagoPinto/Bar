#pragma once
class Cubo;
class MesaRectangular{
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
		Cubo *perna[3];
		Cubo *tabua;
		
	public:
		MesaRectangular();
		MesaRectangular(float c, float l, float a, float e, float f, float p, GLuint idMadeira);
		void desenhaC();
		~MesaRectangular();
};