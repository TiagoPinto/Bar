#pragma once
class Cubo;
class Cilindro;
class Anel;
class Luz;
class CandeeiroCandelabro{
	private:
		float comprimento;
		float altura;
		float fatias;
		float camadas;
		GLuint texturaFerro;
		GLuint texturaVela;
		GLuint texturaMadeira;
		GLuint vbo;
		int nVertices;
		Cilindro *segurador;
		Cilindro *vela[2];
		Cubo *ferros[8];
		Anel *anel[2];
		Luz *luz;

	public:
		CandeeiroCandelabro();
		CandeeiroCandelabro(float c, float a, float f, float p, GLuint idferro, GLuint idvela, GLuint idmadeira);
		void desenhaB();
		void preparaB();
		~CandeeiroCandelabro();
};