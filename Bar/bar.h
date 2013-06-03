#pragma once
class Plano;
class Cubo;
class Balcao;
class CadeiraComprido;
class CadeiraBanco;
class CadeiraRei;
class CadeiraStandart;
class CandeeiroCandelabro;
class CandeeiroParede;
class CandeeiroMesa;
class MesaRedonda;
class MesaRectangular;
class MesaStandart;
class Copo;
class Bar{
	private:
		float c;	//comprimento
		float l;	//largura
		float a;	//altura
		float f;	//fatias
		float p;	//camadas
		GLuint vbo;
		GLuint texChao;
		GLuint texParede;
		GLuint texTecto;
		int nVertices;
		Plano *chaoP;
		Cubo *chaoC;
		Plano *parede[6];
		Plano *tecto[2];
		Cubo *pilares[10];
		CandeeiroCandelabro *candeeiroTecto[2];
		CandeeiroParede *candeeiroParede[1];
		CandeeiroMesa *candeeiroMesa[1];
		MesaRedonda *mesaRedonda[1];
		MesaRectangular *mesaRectangular[2];
		Plano *enfeites[5];
		CadeiraComprido *cadeiracomprido[1];
		CadeiraRei *cadeiraRei;
		CadeiraBanco *banco;
		CadeiraStandart *cadeiraStandart;
		Balcao *balcao;
		Copo *copo;
		Copo *caneca;
		
		
	public:
		Bar();
		Bar(float c, float l, float a, float f, float p);
		void desenha();
		~Bar();
};