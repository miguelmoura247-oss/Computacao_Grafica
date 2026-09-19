#include <GL/glut.h>
#include <math.h>

float angleZ = 0.0f;
float angleY = 0.0f;
float espelhoZ = 1.0f;

float xOffset = 0.0f;
float yOffset = 0.0f;

float escala = 0.5f;
int estado = -1;

void Drawtriangulo() {
    glBegin(GL_TRIANGLES);

        glColor3f(0.0f, 0.83f, 0.88f);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, 1);
        glVertex3f(0.5, 1, 0.5);

        glColor3f(1.0f, 0.28f, 0.58f);
        glVertex3f(0, 0, 1);
        glVertex3f(1, 0, 1);
        glVertex3f(0.5, 1, 0.5);

        glColor3f(0.98f, 0.82f, 0.38f);
        glVertex3f(1, 0, 1);
        glVertex3f(1, 0, 0);
        glVertex3f(0.5, 1, 0.5);

        glColor3f(0.48f, 0.18f, 0.74f);
        glVertex3f(1, 0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0.5, 1, 0.5);
    
    glEnd();
}

void Drawbase() {
    glBegin(GL_POLYGON);

        glColor3f(0.98f, 0.45f, 0.35f);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, 1);
        glVertex3f(1, 0, 1);
        glVertex3f(1, 0, 0);

    glEnd();
}

void arrow_keys(int a_keys, int x, int y) {
    if (estado == 0){
        switch (a_keys) {
        case GLUT_KEY_LEFT:       
            xOffset -= 0.1f;
            glutPostRedisplay();
            break;

        case GLUT_KEY_RIGHT:     
            xOffset += 0.1f;
            glutPostRedisplay();    
            break;

        case GLUT_KEY_UP:
            yOffset += 0.1f;
            glutPostRedisplay();
            break;

        case GLUT_KEY_DOWN:
            yOffset -= 0.1f;
            glutPostRedisplay();
            break;
        }
    }

    if (estado == 1){
        switch (a_keys) {
        case GLUT_KEY_LEFT:       
            angleZ -= 1.0f;
            glutPostRedisplay();
            break;

        case GLUT_KEY_RIGHT:     
            angleZ += 1.0f;
            glutPostRedisplay();
            break;
        }
    }
    
    if (estado == 2){
        switch (a_keys){
        case GLUT_KEY_UP:
            escala += 0.3f;
            glutPostRedisplay();
            break;

        case GLUT_KEY_DOWN:
            escala -= 0.3f;
            glutPostRedisplay();
            break;
        }
    }
}    

void keyboard(unsigned char key, int x, int y) {   
    if (key == 't' || key == 'T'){
        estado = 0;
    }

    if (key == 'r' || key == 'R'){
        estado = 1;
    }

    if (key == 's' || key == 'S'){
        estado = 2;
    }

    if (key == 'm' || key == 'M'){
        estado = 3;
        angleY += 180.0f; 
        glutPostRedisplay();
    }
    
    if (key == 'i' || key == 'I'){
        xOffset = 0.0f;
        yOffset = 0.0f;
        escala = 0.5f;
        angleZ = 0.0f;
        angleY = 0.0f; 
        espelhoZ = 1.0f;
        estado = -1;
        glutPostRedisplay();
    }
}

void desenhaPiramid(){
    Drawtriangulo();
    Drawbase();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    glTranslatef(xOffset, yOffset, 0.0f);
    glRotatef(angleZ, 0.0f, 0.0f, 1.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f); 
        
    glScalef(escala, escala, 0.4f * espelhoZ);
    glRotatef(15, 0.5f, 0.8f, 0.0f);
    glTranslatef(-0.5f, 0.0f, 0.0f);

    desenhaPiramid();
    glutSwapBuffers();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 

    glutInitWindowSize(800, 600);
    
    glutCreateWindow("OpenGL Pyramid");
    
    glEnable(GL_DEPTH_TEST); 
    
    glutDisplayFunc(display);
    
    glutKeyboardFunc(keyboard);
    
    glutSpecialFunc(arrow_keys);
    
    glutMainLoop();
    return 0;
}
