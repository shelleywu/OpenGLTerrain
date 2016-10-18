## OpenGLTerrain
Flying over a terrain wireframe mesh. 
<p>Camera keyboard controls:</p>
<p>up - up</p>
<p>down - down</p>
<p>left - left</p>
<p>right - right</p>
<p>a - forward</p>
<p>z - backward</p>
<p>s - rotate right</p>
<p>x - rotate left</p>

## Uses OpenGL and GLUT
https://www.opengl.org/resources/libraries/glut/
Works on Apple and Linux. 

## Project Usage
This could be used for generating terrains for game backgrounds. 

## Getting Started 
For mac, I used the terminal to make an exectuable.
cd to the folder of the project then use this to make an executable:
gcc -o OpenGLTerrain OpenGLTerrain.c -framework GLUT -framework OpenGL -framework Cocoa -lm -Wno-deprecated
