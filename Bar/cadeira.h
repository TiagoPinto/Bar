class Cadeira{
private:
	float comprimento;
	float largura;
	float altura;
	float espessura;
	float fatias;
	float camadas;
	GLuint vbo;
	int nVertices;
	
public:
	Cadeira();
	Cadeira(float c, float l, float a, float e, float f, float p);
	void desenhaBasePernas();
	void desenhaA();
	void desenhaB();
	void desenhaC();
	void desenhaD();
	~Cadeira();
};