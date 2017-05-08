// shadertype=glsl
#version 330 core

in vec2 TexCoords;
out vec4 color;

uniform sampler2D Sprite;

void main()
{
	vec4 tex = texture(Sprite, TexCoords);
	if(tex.a < 0.1f)
		discard;
	color =  tex;
}