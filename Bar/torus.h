class Torus{
private:
	float raioI;
	float raioE;
	float fatias;
	float camadas;
	GLuint vbo;
	int nVertices;

public:
	Torus();
	Torus(float ri, float re, float f, float c);
	void desenha();
	void meioTorus();
};