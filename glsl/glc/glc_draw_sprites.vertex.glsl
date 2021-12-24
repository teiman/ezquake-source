#version 120

#tkquake-definitions

varying vec2 TextureCoord;
varying vec4 fsColor;

void main()
{
	gl_Position = ftransform();
	TextureCoord = gl_MultiTexCoord0.st;
	fsColor = gl_Color;
}
