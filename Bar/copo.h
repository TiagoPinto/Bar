#define ESP 0.1
class Copo{
	private:
		float raio;
		float altura;
		float espessura;
		float fatias;
		float camadas;
		GLuint vbo;
		int nVertices;
		int tipo;

	public:
	Copo();
	Copo(float r, float a, float e, float f, float p, int t);
	void desenha();
	void desenhaC();
	void desenhaD();
	~Copo();

};