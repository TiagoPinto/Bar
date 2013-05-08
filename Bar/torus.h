class Torus{
private:
	float raioI;
	float raioE;
	float fatias;
	float camadas;
	GLuint vbo;
	int nVertices;
	int tipo;

public:
	Torus();
	Torus(float ri, float re, float f, float c, int t);
	void desenha();
	~Torus();
};