/*Xiao Li Wu*/
#include <stdlib.h>

#ifdef __APPLE__
  #include <OpenGL/gl.h>
  #include <OpenGL/glu.h>
  #include <GLUT/glut.h>
#elif __linux__
  #include <GL/glut.h>
#endif
#include <math.h>


float camera_position_x = 45, camera_position_y = 20, camera_position_z = 10;
float line_of_sight_x = 45, line_of_sight_y = 0, line_of_sight_z = 30;

int ycoor[10000];

int RandRange(int Min, int Max)
{
    int diff = Max-Min;
    return (int) (((double)(diff+1)/RAND_MAX) * rand() + Min);
}

void init()
{
    
    for(int i = 0; i < 10000; i++)
    {
        ycoor[i] = RandRange(0,3);
    }
}

void changeSize(int w, int h) {

    // Prevent a divide by zero, when window is too short
    // (you cant make a window of zero width).
    if (h == 0)
        h = 1;
    float ratio =  w * 1.0 / h;

        // Use the Projection Matrix
    glMatrixMode(GL_PROJECTION);

        // Reset Matrix
    glLoadIdentity();

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Set the correct perspective.
    gluPerspective(45.0f, ratio, 0.1f, 100.0f);

    // Get Back to the Modelview
    glMatrixMode(GL_MODELVIEW);
}

void renderScene(void) {

    // Clear Color and Depth Buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();

    
    // Set the camera
    gluLookAt(camera_position_x, camera_position_y, camera_position_z,
            line_of_sight_x, line_of_sight_y,  line_of_sight_z,
            0.0f, 1.0f,  0.0f);
    
    
    for(int x = 0; x < 100; x+=10)
    {
        for(int z = 0; z < 100; z+=10)
        {
            
         glPushMatrix();
            glClearColor (1.0, 1.0, 1.0, 1.0);
            glColor3f(0.0f, 0.0f, 0.0f);
         glBegin (GL_LINE_LOOP);
         glVertex3f (x, ycoor[50*z+x], z);
         glVertex3f (x + 10, ycoor[50*z+x +10], z);
         glVertex3f (x+10, ycoor[50*(z+10)+x+10], z + 10);
         glPopMatrix();
         glEnd ();
            
           //length * z + x
        glPushMatrix();
        glClearColor (1.0, 1.0, 1.0, 1.0);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin (GL_LINE_LOOP);
        glVertex3f(x , ycoor[50*z+x], z ); //top (1, 1, 1)
        glVertex3f( x , ycoor[50*(z+10)+x], z+10); //left (1, -1, 1)
        glVertex3f( x + 10, ycoor[50*(z+10)+x+ 10], z + 10); //bottom
        glPopMatrix(); 
        glEnd();
            
            
        }
    }

    glutSwapBuffers();
}


void processNormalKeys(unsigned char key, int x, int y) {

    switch(key)
    {
        case 'a':
            line_of_sight_y += 3.0f;
            camera_position_y += 3.0f;
            break;
        case 'z':
            line_of_sight_y -= 3.0f;
            camera_position_y -= 3.0f;
            break;
        case 's':
            line_of_sight_y += 3.0f; //ROTATION
            break;
        case 'x':
            line_of_sight_y -= 3.0f; //ROTATION
            break;
        case 'q':
            exit(0);
            break;
        default: break;
    }
}

void processSpecialKeys(int key, int x, int y) {

    /*
     float camera_position_x = 45, camera_position_y = 20, camera_position_z = 10;
     float line_of_sight_x = 45, line_of_sight_y = 0, line_of_sight_z = 30;
     */
    switch(key) {
        case GLUT_KEY_UP :
            if(line_of_sight_z < 95 & camera_position_z < 95)
            {
                line_of_sight_z += 3.0f;
                camera_position_z += 3.0f;
            }
                break;
        case GLUT_KEY_DOWN :
            if(line_of_sight_z > 5 & camera_position_z > 5)
            {
                line_of_sight_z -= 3.0f;
                camera_position_z -= 3.0f;
            }
                break;
        case GLUT_KEY_LEFT :
            if(line_of_sight_x < 95 & camera_position_x < 95)
            {
                    line_of_sight_x += 3.0f;
                    camera_position_x += 3.0f;
            }
                break;
        case GLUT_KEY_RIGHT:
            if(line_of_sight_x > 5 & camera_position_x > 5)
            {
                    line_of_sight_x -= 3.0f;
                    camera_position_x -= 3.0f;
            }
                break;
    }
}

int main(int argc, char **argv) {

    // init GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(900,500);
    glutCreateWindow("HELLO FLYING TERRAIN");
    init();
    // register callbacks
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);

    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);

    // enter GLUT event processing cycle
    glutMainLoop();

    return 1;
}
