class Piramide{
	private:
		float comprimento;	//comprimento
		float altura;	//altura
		float largura;	//largura
		float fatias;	//camadas
		float camadas;	//fatias
		GLint vbo;
		int nVertices;

	public:
		Piramide();
		Piramide(float c, float a, float l, float f, float p);
		void desenhaR();
		void desenhaC();
};