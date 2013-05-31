#pragma once
class Cilindro;
class MesaRedonda{
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
		Cilindro *ligacao[2];
		
	public:
		MesaRedonda();
		MesaRedonda(float c, float l, float a, float e, float f, float p, GLuint idmadeira);
		void desenhaB();
		~MesaRedonda();
};