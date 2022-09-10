// g++ main.cpp -o rubics -lglut -lGLU -lGL && ./rubics

#include <GL/glut.h>
#include <iostream>

int rotate_z = 0;

void drawSingleCube(GLdouble x, GLdouble y, GLdouble z) {
  // Translating cube
  glTranslated(x, y, z);

  // Drawing cube
  glBegin(GL_QUADS);
  // Top face
  glColor3d(1.0, 0, 0);
  glVertex3f(1.0, 1.0, 1.0);
  glVertex3f(1.0, 1.0, -1.0);
  glVertex3f(-1.0, 1.0, -1.0);
  glVertex3f(-1.0, 1.0, 1.0);

  // Front face
  glColor3d(1.0, 1.0, 1.0);
  glVertex3f(1.0, 1.0, 1.0);
  glVertex3f(-1.0, 1.0, 1.0);
  glVertex3f(-1.0, -1.0, 1.0);
  glVertex3f(1.0, -1.0, 1.0);

  // Right face
  glColor3d(0.0, 0.0, 1.0);
  glVertex3f(1.0, 1.0, -1.0);
  glVertex3f(1.0, 1.0, 1.0);
  glVertex3f(1.0, -1.0, 1.0);
  glVertex3f(1.0, -1.0, -1.0);

  // Back face
  glColor3d(1.0, 1.0, 0.0);
  glVertex3f(1.0, 1.0, -1.0);
  glVertex3f(-1.0, 1.0, -1.0);
  glVertex3f(-1.0, -1.0, -1.0);
  glVertex3f(1.0, -1.0, -1.0);

  // Left face
  glColor3d(0.0, 1.0, 0.0);
  glVertex3f(-1.0, 1.0, 1.0);
  glVertex3f(-1.0, 1.0, -1.0);
  glVertex3f(-1.0, -1.0, -1.0);
  glVertex3f(-1.0, -1.0, 1.0);

  // Bottom face
  glColor3d(1.0, 0.5, 0.0);
  glVertex3f(1.0, -1.0, -1.0);
  glVertex3f(1.0, -1.0, 1.0);
  glVertex3f(-1.0, -1.0, 1.0);
  glVertex3f(-1.0, -1.0, -1.0);
  glEnd();

  glTranslated(-x, -y, -z);
}

void draw3x3Cubes() {
  GLdouble gap = 0.1;
  int cube_size = 2;
  int translate_back = -5;

  for (auto i = 1; i < 4; i++) {
    for (auto j = 1; j < 4; j++) {
      for (auto k = 1; k < 4; k++) {
        drawSingleCube(
            (gap + cube_size) * (i - 2),
            (gap + cube_size) * (j - 2),
            (gap + cube_size) * (k - 2 + translate_back));
      }
    }
  }
}

void clear() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void display() {
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glRotated(rotate_z, 0.0, 0.0, 1.0);

  draw3x3Cubes();

  glFlush();
}

void clearAndDisplay(void) {
  clear();
  display();
}

void init() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  // gluPerspective(60.0f, h/w, 1.0f, 50.0f);
  glFrustum(-2.0, 2.0, -2.0, 2.0, 1.0, 50.0);

  // glMatrixMode(GL_MODELVIEW);
  // glLoadIdentity();
  // gluLookAt (0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //Looking from 5 z to 0 z, letting y be up
}

void reshape(int w, int h) {
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
  case GLUT_KEY_RIGHT:
    rotate_z = (rotate_z + 1) % 360;
    std::cout << "Hei" << rotate_z << std::endl;
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
  glutDisplayFunc(clearAndDisplay);
  //  glutKeyboardFunc(keybInput);
  glutSpecialFunc(specialKeybInput);

  glutMainLoop();
  return 0;
}
