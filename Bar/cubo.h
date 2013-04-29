class Cubo{
	private:
		float c;	//comprimento
		float a;	//altura
		float l;	//largura
		float f;	//camadas
		float p;	//fatias
		GLuint vbo;
		int nVertices;	//Numero de Vertices 

	public:
		Cubo();
		Cubo(float c, float a, float l, float f, float p);
		void desenha();
		~Cubo();

};