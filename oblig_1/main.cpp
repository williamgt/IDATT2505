#include <GL/glut.h>
#include <GL/gl.h>

void displayMe(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Clear the screen and the depth buffer
	glLoadIdentity();
	glScaled(0.1,0.1,0.1);

	glColor3f(1.0f, 0.0f, 0.0f);      // Set the color to red

	glTranslatef(-1.5f, 0.0f, -8.0f); // Move left 1.5 Units and 7 units into the screen NB! made the triangle render outside of screen
	glBegin(GL_TRIANGLES);          // Start drawing using the polygon primitive GL_TRIANGLES
		glVertex3f(0.0f, 1.0f, 0.0f);   // Top
		glVertex3f(-1.0f, -1.0f, 0.0f); // Bottom left
		glVertex3f(1.0f, -1.0f, 0.0f);  // Bottom right
	glEnd(); 
	glTranslatef(1.5f, 0.0f, 8.0f);

	// //Drawing point
	// glTranslatef(0.0f, 0.2f, 0.0f);
	// glColor3f(1.0f, 0.0f, 0.5f);
	// glPointSize(5.0f); //Upping point size
	// glBegin(GL_POINTS);
	// 	glVertex3d(0.0, 0.0, 0.0);
	// glEnd();
	// glTranslatef(0.0f, -0.2f, 0.0f);

	
	// //Drawing a line
	// glColor3f(1.0f, 1.0f, 1.0f);      // Set the color to white
	// glTranslatef(-8.0f, 0.0f, 0.0f);
	// glBegin(GL_LINES);
	// 	glVertex3f(0.0f, 2.0f, 0.0f);   
	// 	glVertex3f(1.5f, -1.5f, 0.0f); 
	// glEnd();
	// glTranslatef(8.0f, 0.0f, 0.0f);

	// //Drawing striped line
	// glColor3f(0.0f, 1.0f, 0.0f);      // Set the color to green
	// glTranslatef(-6.0f, -7.0f, 0.0f);
	// glBegin(GL_LINE_STRIP);
	// 	glVertex3f(2.0f, 0.0f, 0.0f);   
	// 	glVertex3f(-1.5f, 1.5f, 0.0f); 
	// 	glVertex3f(-2.0f, 0.0f, 0.0f);   
	// 	glVertex3f(-1.5f, -1.5f, 0.0f); 
	// glEnd();
	// glTranslatef(6.0f, 7.0f, 0.0f);

	// //Drawing line loop
	// glColor3f(0.0f, 0.0f, 1.0f);      // Set the color to blue
	// glTranslatef(-6.0f, 7.0f, 0.0f);
	// glBegin(GL_LINE_LOOP);
	// 	glVertex3f(-1.5f, -1.5f, 0.0f); 
	// 	glVertex3f(-1.5f, 1.5f, 0.0f); 
	// 	glVertex3f(1.5f, 1.5f, 0.0f); 
	// 	glVertex3f(1.5f, -1.5f, 0.0f); 
	// glEnd();
	// glTranslatef(6.0f, -7.0f, 0.0f);

	// //Drawing triangles
	// glColor3f(0.0f, 1.0f, 1.0f);      // Set the color to green + blue
	// glTranslatef(0.0f, 7.0f, 0.0f);
	// glBegin(GL_TRIANGLES);
	// 	glVertex3f(-1.5f, -1.5f, 0.0f); 
	// 	glVertex3f(2.0f, 0.0f, 0.0f);   
	// 	glVertex3f(-1.5f, 1.5f, 0.0f); 
	// 	glVertex3f(1.5f, 1.5f, 0.0f); 
	// 	glVertex3f(-2.0f, 0.0f, 0.0f);   
	// 	glVertex3f(1.5f, -1.5f, 0.0f); 
	// glEnd();
	// glTranslatef(0.0f, -7.0f, 0.0f);

	// //Drawing triangle strip
	// glColor3f(1.0f, 0.0f, 1.0f);      // Set the color to red + blue
	// glTranslatef(0.0f, -7.0f, 0.0f);
	// glBegin(GL_TRIANGLE_STRIP);
	// 	glVertex3f(-1.5f, -1.5f, 0.0f); 
	// 	glVertex3f(2.0f, 0.0f, 0.0f);   
	// 	glVertex3f(-1.5f, 1.5f, 0.0f); 
	// 	glVertex3f(1.5f, 1.5f, 0.0f); 
	// 	glVertex3f(-2.0f, 0.0f, 0.0f);   
	// 	glVertex3f(1.5f, -1.5f, 0.0f); 
	// glEnd();
	// glTranslatef(0.0f, 7.0f, 0.0f);

	// //Drawing triangle fan
	// glColor3f(1.0f, 1.0f, 0.0f);      // Set the color to red + green
	// glTranslatef(6.0f, 7.0f, 0.0f);
	// glBegin(GL_TRIANGLE_FAN);
	// 	glVertex3f(-1.5f, -1.5f, 0.0f); 
	// 	glVertex3f(1.5f, -1.5f, 0.0f); 
	// 	glVertex3f(0.0f, -7.0f, 0.0f);   
	// glEnd();
	// glTranslatef(-6.0f, 7.0f, 0.0f);

	// //Drawing quads
	// glColor3f(1.0f, 1.0f, 0.5f);      // Set the color to red + green + 0.5blue
	// glTranslatef(-2.0f, -2.0f, 0.0f);
	// glBegin(GL_QUADS);
	// 	glVertex3f(-1.5f, -1.5f, 0.0f); 
	// 	glVertex3f(1.5f, -1.5f, 0.0f); 
	// 	glVertex3f(-1.5f, 1.5f, 0.0f); 
	// 	glVertex3f(1.5f, 1.5f, 0.0f); 
	// glEnd();
	// glTranslatef(2.0f, 2.0f, 0.0f);

	// //Drawing quad strip
	// glColor3f(0.5f, 0.5f, 1.0f);      // Set the color to 0.5red + 0.5green + blue
	// glTranslatef(2.0f, -2.0f, 0.0f);
	// glBegin(GL_QUAD_STRIP);
	// 	glVertex3f(-1.5f, -1.5f, 0.0f); 
	// 	glVertex3f(1.5f, -1.5f, 0.0f); 
	// 	glVertex3f(-1.5f, 1.5f, 0.0f); 
	// 	glVertex3f(1.5f, 1.5f, 0.0f); 
	// glEnd();
	// glTranslatef(-2.0f, 2.0f, 0.0f);

	// //Drawing polygon
	// glColor3f(0.5f, 0.5f, 0.5f);      // Set the color to 0.5red + 0.5green + 0.5blue
	// glTranslatef(2.0f, 2.0f, 0.0f);
	// glBegin(GL_POLYGON);
	// 	glVertex3f(-1.5f, -1.5f, 0.0f); 
	// 	glVertex3f(1.5f, -1.5f, 0.0f); 
	// 	glVertex3f(0.0, -2.0, 0.0);
	// 	glVertex3f(0.0, 2.0, 0.0);
	// 	glVertex3f(1.5f, 1.5f, 0.0f); 
	// 	glVertex3f(-1.5f, 1.5f, 0.0f); 
	// 	glVertex3f(-1.5f, -1.5f, 0.0f); 
	// glEnd();
	// glTranslatef(-2.0f, -2.0f, 0.0f);

	glFlush();
}

int main(int argc, char** argv) {
	// http://www.cs.uccs.edu/~ssemwal/glman.html

	//draw figures using these OpenGL primitives:
	// GL_POINTS, GL_LINES, GL_LINE_STRIP, GL_LINE_LOOP
	// GL_TRIANGLES, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN
	// GL_QUADS, GL_QUAD_STRIP, GL_POLYGON
	// at these points:
	// p0 = (0.0, 2.0, 0.0), p1 = (1.5, 1.5, 0.0), p2 = (2.0, 0.0, 0.0), p3 = (1.5, -1.5, 0.0),
	// p4 = (0.0, -2.0, 0.0), p5 = (-1.5, -1.5, 0.0), p6 = (-2.0, 0.0, 0.0), p7 = (-1.5, 1.5, 0.0);

	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("oblig_1");
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}
