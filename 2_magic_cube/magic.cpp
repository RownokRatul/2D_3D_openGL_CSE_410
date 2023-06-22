#include<GL/glut.h>
#include<iostream>
#include<cmath>
#include "config.h"
#include "draw3d.h"
#include "keyHandler.h"

using namespace std;

void reshapeListener(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
    // Compute aspect ratio of the new window
    if (height == 0) height = 1;                // To prevent divide by 0
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    // Set the viewport to cover the new window
    glViewport(0, 0, width, height);

    // Set the aspect ratio of the clipping area to match the viewport
    glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
    glLoadIdentity();             // Reset the projection matrix
    /*if (width >= height) {
        // aspect >= 1, set the height from -1 to 1, with larger width
        gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
    } else {
        // aspect < 1, set the width to -1 to 1, with larger height
        gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
    }*/
    // Enable perspective projection with fovy, aspect, zNear and zFar
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void idle() {

}

void display() {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(camera.eye.x, camera.eye.y, camera.eye.z,
             camera.centre.x, camera.centre.y, camera.centre.z,
             camera.up.x, camera.up.y, camera.up.z);


    drawAxes();
    drawOctahedron();
    // drawPyramid();

    glutSwapBuffers();
}

void gl_init(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(50, 50);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("Magic_Cube");
    glClearColor(0, 0, 0, 1); 
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char* argv[]) {
    gl_init(argc, argv);

    glutDisplayFunc(display);
    glutReshapeFunc(reshapeListener);
    glutSpecialFunc(specialKeyListener);
    glutKeyboardFunc(usualKeyListener);
    // glutIdleFunc(idle);

    glutMainLoop();
    
    return 0;
}