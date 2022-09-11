// g++ main.cpp -o rubics -lglut -lGLU -lGL && ./rubics

#include <GL/glut.h>
#include <iostream>

int rotate_x = 0;
int rotate_y = 0;
int rotate_z = 0;

void drawSingleCube(GLdouble x, GLdouble y, GLdouble z) {
  glPushMatrix();
  // Translating cube
  glTranslated(x, y, z);

  // Drawing cube
  glBegin(GL_QUADS);
  // Front face
  glColor3d(1.0, 1.0, 0.0); // Yellow
  glVertex3f(1.0, 1.0, 1.0);
  glVertex3f(-1.0, 1.0, 1.0);
  glVertex3f(-1.0, -1.0, 1.0);
  glVertex3f(1.0, -1.0, 1.0);

  // Back face
  glColor3d(1.0, 1.0, 1.0); // White
  glVertex3f(1.0, 1.0, -1.0);
  glVertex3f(1.0, -1.0, -1.0);
  glVertex3f(-1.0, -1.0, -1.0);
  glVertex3f(-1.0, 1.0, -1.0);

  // Left face
  glColor3d(0.0, 1.0, 0.0); // Green
  glVertex3f(-1.0, 1.0, 1.0);
  glVertex3f(-1.0, 1.0, -1.0);
  glVertex3f(-1.0, -1.0, -1.0);
  glVertex3f(-1.0, -1.0, 1.0);

  // Right face
  glColor3d(0.0, 0.0, 1.0); // Blue
  glVertex3f(1.0, 1.0, -1.0);
  glVertex3f(1.0, 1.0, 1.0);
  glVertex3f(1.0, -1.0, 1.0);
  glVertex3f(1.0, -1.0, -1.0);

  // Top face
  glColor3d(1.0, 0.0, 0.0); // Red
  glVertex3f(1.0, 1.0, 1.0);
  glVertex3f(1.0, 1.0, -1.0);
  glVertex3f(-1.0, 1.0, -1.0);
  glVertex3f(-1.0, 1.0, 1.0);

  // Bottom face
  glColor3d(1.0, 0.5, 0.0); // Orange
  glVertex3f(1.0, -1.0, -1.0);
  glVertex3f(1.0, -1.0, 1.0);
  glVertex3f(-1.0, -1.0, 1.0);
  glVertex3f(-1.0, -1.0, -1.0);
  glEnd();

  glPopMatrix();
}

void draw3x3Cubes() {
  GLdouble gap = 0.02;
  int cube_size = 2;

  for (auto i = 1; i < 4; i++) {
    for (auto j = 1; j < 4; j++) {
      for (auto k = 1; k < 4; k++) {
        drawSingleCube(
            (gap + cube_size) * (i - 2),
            (gap + cube_size) * (j - 2),
            (gap + cube_size) * (k - 2));
      }
    }
  }
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);

  glRotated(rotate_x, 1.0, 0.0, 0.0);
  glRotated(rotate_y, 0.0, 1.0, 0.0);
  glRotated(rotate_z, 0.0, 0.0, 1.0);

  draw3x3Cubes();

  glFlush();
}

void init() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  // gluPerspective(60.0f, h/w, 1.0f, 50.0f);
  glFrustum(-2.0, 2.0, -2.0, 2.0, 1.0, 50.0);
  gluLookAt(0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

  // glMatrixMode(GL_MODELVIEW);
  // glLoadIdentity();
  // gluLookAt (0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //Looking from 5 z to 0 z, letting y be up
}

void reshape(int w, int h) {
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

void keybInput(unsigned char key, int x, int y) {
  switch (key) {
  case GLUT_KEY_RIGHT:
    glRotated(90.0, 0.0, 1.0, 0.0);
    std::cout << "Hei" << std::endl;
    break;
  case GLUT_KEY_REPEAT_ON:
    break;
  default:
    break;
  }
}

void specialKeybInput(int key, int x, int y) {
  switch (key) {
  case GLUT_KEY_END:
    rotate_z = (rotate_z + 1) % 360;
    glutPostRedisplay();
    break;
  case GLUT_KEY_RIGHT:
    rotate_x = (rotate_x + 1) % 360;
    glutPostRedisplay();
    break;
  case GLUT_KEY_UP:
    rotate_y = (rotate_y + 1) % 360;
    glutPostRedisplay();
    break;
  default:
    break;
  }
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(800, 600);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Rubiks");

  init();
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);
  //  glutKeyboardFunc(keybInput);
  glutSpecialFunc(specialKeybInput);

  glutMainLoop();
  return 0;
}
