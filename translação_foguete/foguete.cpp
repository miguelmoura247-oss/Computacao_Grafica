#include <GL/glut.h>
#include <math.h>

float angle = 0.0f;

void DrawTriangulo() {
    glBegin(GL_POLYGON);

        glColor3f(1, 0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(1, 0, 0 );
        glVertex3f(0.5, 1, 0 );

        glEnd();
    }

    void DrawRetangulo() {
    glBegin(GL_POLYGON);

     glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0, 0, 0);
        glVertex3f(0, -3, 0 );
        glVertex3f(1, -3, 0 );
        glVertex3f(1, 0, 0 );

        glEnd();
    }

    void DrawTriangulo1() {
    glBegin(GL_POLYGON);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(0, -2, 0);
        glVertex3f(0, -3, 0 );
        glVertex3f(-1, -3, 0 );

        glEnd();
    }

     void DrawTriangulo2() {
     glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(1, -3, 0 );        
        glVertex3f(1, -2, 0);
        glVertex3f(2, -3, 0 );

        glEnd();
    }
      


void display2() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -6.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);

    DrawTriangulo();
    DrawRetangulo();
    DrawTriangulo1();
    DrawTriangulo2();

    glutSwapBuffers();
}


void update(int value) {
    angle += 0.5f;
    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // ~60 fps
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80.0, (double)w / h, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Cube");

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    glutDisplayFunc(display2);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}
