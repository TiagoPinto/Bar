class Piramide{
	private:
		float comprimento;	//comprimento
		float altura;	//altura
		float largura;	//largura
		float fatias;	//camadas
		float camadas;	//fatias
		GLuint textura;
		GLuint vbo;
		int nVertices;

	public:
		Piramide();
		Piramide(float c, float a, float l, float f, float p, GLuint idtex);
		void desenha();
		~Piramide();
};