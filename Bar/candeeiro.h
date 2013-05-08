#pragma once


class Candeeiro{
	private:
		float comprimento;
		float altura;
		float fatias;
		float camadas;
		GLuint vbo;
		int nVertices;

	public:
		Candeeiro();
		Candeeiro(float c, float a, float f, float p);
		void desenhaA();
		void desenhaB();
		void preparaB();
		~Candeeiro();
};