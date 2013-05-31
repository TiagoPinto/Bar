#include "texturas.h"
#include <IL/il.h>
#include "includes.h"
#include <string>
#include <map>

static std::map<std::string,unsigned int> texturas;

unsigned int getTextura(const char *path) {
	auto it = texturas.find(path);
	if(it != texturas.end())
		return it->second;
	else {
		GLuint textureID;
		unsigned int t[2], tw, th;
		unsigned char *texData;
		ilGenImages(2,t);
		ilBindImage(t[0]);
		ilLoadImage((ILstring)path);
		tw = ilGetInteger(IL_IMAGE_WIDTH);
		th = ilGetInteger(IL_IMAGE_HEIGHT);
		ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
		texData = ilGetData();
	
		glGenTextures(1,&textureID); // unsigned int texID  - variavel global;
	
		glBindTexture(GL_TEXTURE_2D,textureID);
		glTexParameteri(GL_TEXTURE_2D,	GL_TEXTURE_WRAP_S,		GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D,	GL_TEXTURE_WRAP_T,		GL_REPEAT);

		glTexParameteri(GL_TEXTURE_2D,	GL_TEXTURE_MAG_FILTER,   	GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,	GL_TEXTURE_MIN_FILTER,    	GL_LINEAR);
		
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tw, th, 0, GL_RGBA, GL_UNSIGNED_BYTE, texData);

		texturas.emplace(path, textureID);
		return textureID;
	}
}