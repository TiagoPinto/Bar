
class Bar{
	private:
		float c;	//comprimento
		float l;	//largura
		float a;	//altura
		float f;	//fatias
		float p;	//camadas
		GLuint vbo;
		int nVertices;
		
	public:
		Bar();
		Bar(float c, float l, float a, float f, float p);
		void desenha();
};