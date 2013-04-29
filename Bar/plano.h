class Plano{
	private:
		float c;	//comprimento
		float a;	//altura
		float f;	// fatias na horizontal
		float p;	//camadas na vertical
		int tri;	//tipo de triangulo que desenha
		GLuint vbo;
		int nVertices;
		
	public:
		Plano();
		Plano(float c, float a, float f, float p, int tri);
		void PlanoXoY();
		void PlanoXoZ();
		void PlanoYoZ();
		void desenha();
		~Plano();
};