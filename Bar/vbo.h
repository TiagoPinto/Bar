class Vbo
{
private:
	float x;	//coordenada X
	float y;	//coordenada Y
	float z;	//coordenada z
	float nx;	//normal x
	float ny;	//normal y
	float nz;	//normal z
	float s0;	//texturas
	float t0;

public:

	void adicionar(float x, float y, float z, float nx = 0, float ny = 0, float nz = 0, float s0 = 0, float t0 = 0);
};
