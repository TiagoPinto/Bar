class Cubo{
	private:
		float c;	//comprimento
		float a;	//altura
		float l;	//largura
		float f;	//camadas
		float p;	//fatias
		GLuint textura;
		GLuint vbo;
		int nVertices;

	public:
		Cubo();
		Cubo(float c, float a, float l, float f, float p, GLuint idTextura);
		void desenha();
		~Cubo();

};