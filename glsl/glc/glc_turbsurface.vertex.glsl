#version 120

#tkquake-definitions

#ifndef FLAT_COLOR
varying vec2 TextureCoord;
#endif

void main()
{
	gl_Position = ftransform();
#ifndef FLAT_COLOR
	TextureCoord = gl_MultiTexCoord0.st;
#endif
}
