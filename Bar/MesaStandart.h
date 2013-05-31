#pragma once
class Cubo;
class Cilindro;
class MesaStandart{
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
		Cilindro *perna[4];
		
	public:
		MesaStandart();
		MesaStandart(float c, float l, float a, float e, float f, float p, GLuint idMadeira);
		void desenhaA();
		~MesaStandart();
};