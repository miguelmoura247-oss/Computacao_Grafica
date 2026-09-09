#include <GL/glut.h>
#include <math.h>

float angle = 0.0f;

void DrawCube() {
    glBegin(GL_QUADS);

        glColor3f(1.0f, 0.28f, 0.58f);
        glVertex3f(-1, -1,  1); glVertex3f( 1, -1,  1);
        glVertex3f( 1,  1,  1); glVertex3f(-1,  1,  1);

        glColor3f(0.0f, 0.83f, 0.88f);
        glVertex3f(-1, -1, -1); glVertex3f(-1,  1, -1);
        glVertex3f( 1,  1, -1); glVertex3f( 1, -1, -1);

        glColor3f(0.98f, 0.82f, 0.38f);
        glVertex3f(-1,  1, -1); glVertex3f(-1,  1,  1);
        glVertex3f( 1,  1,  1); glVertex3f( 1,  1, -1);

        glColor3f(0.48f, 0.18f, 0.74f);
        glVertex3f(-1, -1, -1); glVertex3f( 1, -1, -1);
        glVertex3f( 1, -1,  1); glVertex3f(-1, -1,  1);


        glColor3f(0.31f, 0.89f, 0.69f);
        glVertex3f( 1, -1, -1); glVertex3f( 1,  1, -1);
        glVertex3f( 1,  1,  1); glVertex3f( 1, -1,  1);

        glColor3f(0.98f, 0.45f, 0.35f);
        glVertex3f(-1, -1, -1); glVertex3f(-1, -1,  1);
        glVertex3f(-1,  1,  1); glVertex3f(-1,  1, -1);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    // Câmera fixa, um pouco acima e afastada
    gluLookAt(
        0.0, 1.5, 3.0,   // posição da câmera
        0.0, 0.0, 0.0,   // olha para o centro do cubo
        0.0, 1.0, 0.0    // direção "para cima"
    );

    // Cubo gira em torno do próprio eixo
    glRotatef(angle, 0.0f, -1.0f, 0.0f);

    DrawCube();

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

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}
