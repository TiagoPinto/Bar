class Cilindro{
	private:
		float raio;					//raio do cilindro
		float altura;				//altura do cilindro
		float fatias;				//precisao circulo quanto mais alta,mais fatias tem as bases e o "tronco" 
		float camadas;				//numero de camadas do tronco

	public:
		Cilindro();
		Cilindro(float r, float a, float f, float c);
		Cilindro(float r, float a);
		void desenha();
		float getAltura();
		void meioCilindro();
};