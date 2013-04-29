class Esfera {
	private:
		float raio;
		float fatias;
		float camadas;
		GLuint vbo;
		int nVertices;

	public:
		Esfera();
		Esfera(float r, float f, float c);
		void desenha();
		void meiaEsfera();
};