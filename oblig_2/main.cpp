#include <GL/glut.h>

void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex3f(0.5, 0.0, 0.5);
    glVertex3f(0.5, 0.0, 0.0);
    glVertex3f(0.0, 0.5, 0.0);
    glVertex3f(0.0, 0.0, 0.5);
    glEnd();
    glFlush();
}

void drawCube2A(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glLoadIdentity();
    glTranslated(0.0, 0.0, -3.0); // Moving back -3 in z direction
    glBegin(GL_LINE_LOOP);
        // Face 1, back
        glVertex3i(-1, -1, -1);
        glVertex3i(1, -1, -1);
        glVertex3i(1, 1, -1);
        glVertex3i(-1, 1, -1);
    glEnd();
    glBegin(GL_LINE_LOOP);
        // Face 2, front
        glVertex3i(-1, -1, 1);
        glVertex3i(1, -1, 1);
        glVertex3i(1, 1, 1);
        glVertex3i(-1, 1, 1);
    glEnd();
    glBegin(GL_LINE_LOOP);
        // Face 3, left
        glVertex3i(-1, -1, -1);
        glVertex3i(-1, -1, 1);
        glVertex3i(-1, 1, 1);
        glVertex3i(-1, 1, -1);
    glEnd();
    glBegin(GL_LINE_LOOP);
        //Face 4, right
        glVertex3i(1, -1, -1);
        glVertex3i(1, -1, 1);
        glVertex3i(1, 1, 1);
        glVertex3i(1, 1, -1);
    glEnd();
    glBegin(GL_LINE_LOOP);
        // Face 5, bottom
        glVertex3i(-1, -1, 1);
        glVertex3i(-1, -1, -1);
        glVertex3i(1, -1, -1);
        glVertex3i(1, -1, 1);
    glEnd();
    glBegin(GL_LINE_LOOP);
        // Face 6, top
        glVertex3i(-1, 1, 1);
        glVertex3i(-1, 1, -1);
        glVertex3i(1, 1, -1);
        glVertex3i(1, 1, 1);
    glEnd();
    glFlush();
}

void drawCube2B(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glLoadIdentity();
    glTranslated(0.0, 0.0, -3.0); // Moving back -3 in z direction
    glutWireCube(2.0f); //Drawing cube here
    glFlush();
}

void drawCube3V1(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0);
    glLoadIdentity();

    glRotatef(30.0f, 0.0f, 0.0f, 1.0f); //Rotating 30 deg at z
    glTranslated(0.0, 2.0, -3.0); // Moving up 2 y directin, back -3 in z direction
    glScaled(1.0, -2.0, 1.0); //Flipping cube upsidedown
    
    glutWireCube(2.0f); //Drawing cube here
    glFlush();
}

void drawCube3V2(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0, 1.0, 1.0);
    glLoadIdentity();
    
    glTranslated(0.0, 2.0, -3.0); // Moving up 2 in y direction, back -3 in z direction
    glRotatef(30.0f, 0.0f, 0.0f, 1.0f); //Rotating 30 deg at z
    glScaled(1.0, -2.0, 1.0); //Flipping cube upsidedown and stretching it
    
    glutWireCube(2.0f); //Drawing cube here
    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluLookAt (0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //Looking pretty much straight at cube from 0,1,1
    //gluLookAt (0.0, 0.0, 2.0, 0.0, 2.0, 0.0, 0.0, 1.0, 0.0); //Looking up to 0,2,0 from 0,0,2 results in some clipping
    //gluLookAt (2.0, 0.0, 1.0, -0.5, 0.0, -2.0, 0.0, 1.0, 0.0); //Going to the right and up from screen, looking at -1,0,-2 results in some clipping

    gluPerspective(90.0f, 1.0f, 0.1f, 40.0f);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Cube");
    
    //glutDisplayFunc(drawCube2A);
    //glutDisplayFunc(drawCube2B);
    glutDisplayFunc(drawCube3V1);
    //glutDisplayFunc(drawCube3V2);

    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
