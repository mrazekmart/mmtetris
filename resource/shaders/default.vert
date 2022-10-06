#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 color;
vec3 altColor;

uniform mat4 camMatrix;

void main()
{
   gl_Position = camMatrix * vec4(aPos, 1.0);
   altColor = vec3(sin(aPos.x * 10), sin(aPos.y * 20), abs(aPos.x));
   color = altColor;

   //color = vec3(0.2f, 0.5f, 0.8f);
}