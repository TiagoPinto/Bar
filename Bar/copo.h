#define ESP 0.1
class Torus;
class Copo{
	private:
		float raio;
		float altura;
		float espessura;
		float fatias;
		float camadas;
		GLuint textura;
		GLuint vbo;
		int nVertices;
		int tipo;
		Torus *pega;

	public:
	Copo();
	Copo(float r, float a, float e, float f, float p, int t, GLuint idtex);
	void desenha();
	void desenhaC();
	void desenhaD();
	~Copo();
};