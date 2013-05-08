class Esfera {
	private:
		float raio;
		float fatias;
		float camadas;
		int tipo;
		GLuint vbo;
		int nVertices;

	public:
		Esfera();
		Esfera(float r, float f, float c, int t);
		void desenha();
		~Esfera();
};