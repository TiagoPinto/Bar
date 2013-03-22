class Plano{
	private:
		float c;	//comprimento
		float a;	//altura
		float f;	// fatias na horizontal
		float p;	//camadas na vertical
		
	public:
		Plano();
		Plano(float c, float a, float f, float p);
		void desenhaXoY();
		void desenhaXoZ();
		void desenhaYoZ();
};