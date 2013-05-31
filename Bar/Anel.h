class Anel{
private:
	float raioI;
	float raioE;
	float altura;
	float fatias;
	float camadas;
	GLuint textura;
	GLuint vbo;
	int nVertices;

public:
	Anel();
	Anel(float ri, float re, float altura, float f, float c, GLuint idtex);
	void desenha();
	~Anel();
};