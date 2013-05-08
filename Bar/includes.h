#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include <vector>

struct vertex{
	float vertices[3];
	float texturas[2];
	float normais[3];

	vertex(float x,float y, float z, float nx, float ny, float nz, float tt = 0, float ts = 0){
		vertices[0] = x;
		vertices[1] = y;
		vertices[2] = z;
		normais[0] = nx;
		normais[1] = ny;
		normais[2] = nz;
		texturas[0] = tt;
		texturas[1] = ts;
	}
};
