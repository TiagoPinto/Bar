#define ESP 0.1
class Copo{
	private:
		float raio;
		float altura;
		float espessura;
		float fatias;
		float camadas;


	public:
	Copo();
	Copo(float r, float a, float e, float f, float p);
	void desenhaA();
	void desenhaB();
	void desenhaC();
	void desenhaD();


};