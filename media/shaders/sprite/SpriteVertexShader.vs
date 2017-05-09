// shadertype=glsl
#version 330 core
layout(location = 0) in vec2 position;
layout(location = 1) in vec2 texCoords;

out vec2 TexCoords;

uniform vec2 clip; // 1 2
uniform	vec2 rowCol; // 13 21

void main()
{
	gl_Position = vec4(position, 0.0f, 1.0f);
	TexCoords = vec2((texCoords.x/rowCol.x)+((1/rowCol.x)*clip.y), (texCoords.y/rowCol.y)+((1/rowCol.y)*clip.x));
	//TexCoords = texCoords;
}