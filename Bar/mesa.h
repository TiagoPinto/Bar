class Mesa{
	private:
		float comprimento;
		float largura;
		float altura;
		float espessura;
		float fatias;
		float camadas;
		
	public:
		Mesa();
		Mesa(float c, float l, float a, float e, float f, float p);
		void desenhaA();
		void desenhaB();
		void desenhaC();
};