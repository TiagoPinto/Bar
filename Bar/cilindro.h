class Cilindro{
	private:
		float raio;					//raio do cilindro
		float altura;				//altura do cilindro
		float fatias;				//precisao circulo quanto mais alta,mais fatias tem as bases e o "tronco" 
		float camadas;				//numero de camadas do tronco
		int tipo;					//desenha um cilindro ou metade
		GLuint vbo;
		int nVertices;

	public:
		Cilindro();
		Cilindro(float r, float a, float f, float c,int t);
		Cilindro(float r, float a);
		void desenha();
		float getAltura();
		~Cilindro();
};