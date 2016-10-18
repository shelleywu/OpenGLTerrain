## OpenGLTerrain
Flying over a terrain wireframe mesh. 
Camera keyboard controls:
up - up
down - down
left - left
right - right
a - forward
z - backward
s - rotate right
x - rotate left

## Uses OpenGL and GLUT
https://www.opengl.org/resources/libraries/glut/
Works on Apple and Linux. 

## Project Usage
This could be used for generating terrains for game backgrounds. 

## Getting Started 
For mac, I used the terminal to make an exectuable.
cd to the folder of the project then use this to make an executable:
gcc -o OpenGLTerrain OpenGLTerrain.c -framework GLUT -framework OpenGL -framework Cocoa -lm -Wno-deprecated
