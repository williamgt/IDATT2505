//g++ main.cpp -o rubics -lglut -lGLU -lGL && ./rubics

#include <GL/glut.h>

void drawSingleCube() {
    //Drawing cube
    glBegin(GL_QUADS);
        //Top face
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(1.0, 1.0, -1.0);
        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(-1.0, 1.0, 1.0);
        
        //Front face
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(-1.0, -1.0, 1.0);
        glVertex3f(1.0, -1.0, 1.0);

        //Right face
        glVertex3f(1.0, 1.0, -1.0);
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(1.0, -1.0, 1.0);
        glVertex3f(1.0, -1.0, -1.0);

        //Back face
        glVertex3f(1.0, 1.0, -1.0);
        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(-1.0, -1.0, -1.0);
        glVertex3f(1.0, -1.0, -1.0);

        //Left face
        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(-1.0, -1.0, -1.0);
        glVertex3f(-1.0, -1.0, 1.0);

        //Bottom face
        glVertex3f(1.0, -1.0, -1.0);
        glVertex3f(1.0, -1.0, 1.0);
        glVertex3f(-1.0, -1.0, 1.0);
        glVertex3f(-1.0, -1.0, -1.0);
    glEnd();
}

void draw3x3Cubes(int n) {

}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1.0, 1.0, 1.0);

    for (size_t i = 0; i < 3; i++)
    {
        int xPos = 
        for (size_t j = 0; j < 3; j++)
        {
            int yPos = 
            for (size_t k = 0; k < 3; k++)
            {
                int zPos = 
                
            }
            
        }
        
    }
    glTranslated(0.0, 0.0, -5.0);
    drawSingleCube();
    glTranslated(0.0, 0.0, 5.0);

    glFlush();
}

void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluPerspective(60.0f, h/w, 1.0f, 50.0f);
    glFrustum(-2.0, 2.0, -2.0, 2.0, 1.0, 50.0);
    
    // glMatrixMode(GL_MODELVIEW);
    // glLoadIdentity();
    //gluLookAt (0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //Looking from 5 z to 0 z, letting y be up
}


void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}


// void reshape(int w, int h) {
//   glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//   glMatrixMode(GL_PROJECTION);
//   glLoadIdentity();
//   glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
//   glMatrixMode(GL_MODELVIEW);
//   glLoadIdentity();
// }

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rubiks");
    
    init();

    glutDisplayFunc(display);

    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
