#include<GL/glut.h>
#include<iostream>
#include<cmath>
#include "config.h"
#include "camera.h"
#include "point3d.h"
#include "draw3d.h"

using namespace std;

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

    glutSwapBuffers();
}

void gl_init(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(50, 50);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
    glutCreateWindow("Clock");
    glClearColor(0, 0, 0, 0); 
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char* argv[]) {
    gl_init(argc, argv);

    glutDisplayFunc(display);
    glutIdleFunc(idle);

    glutMainLoop();
    
    return 0;
}