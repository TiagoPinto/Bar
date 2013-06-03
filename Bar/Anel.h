class Anel{
private:
	float raioI;
	float raioE;
	float altura;
	float fatias;
	float camadas;
	int tipo;
	GLuint textura;
	GLuint vbo;
	int nVertices;

public:
	Anel();
	Anel(float ri, float re, float altura, float f, float c,int tipo, GLuint idtex);
	void desenha();
	~Anel();
};