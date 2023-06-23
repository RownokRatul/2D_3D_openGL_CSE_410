#ifndef _KEY_header_
#define _KEY_header_

#include <GL/glut.h>
#include <cmath>
#include <stdio.h>
#include "config.h"

void specialKeyListener(int key, int x, int y) {
    GLfloat del = 0.1;
    GLfloat eyeToCentre_x = camera.centre.x - camera.eye.x;
    GLfloat eyeToCentre_y = camera.centre.z - camera.eye.z;
    GLfloat proj;

    switch(key) {
        case GLUT_KEY_UP:
            camera.eye.x -= del;
            camera.eye.y -= del;
            camera.eye.z -= del;
            break;
        case GLUT_KEY_DOWN:
            camera.eye.x += del;
            camera.eye.y += del;
            camera.eye.z += del;
            break;
        case GLUT_KEY_LEFT:
            camera.centre.x += del;
            camera.eye.x += del;
            break;
        case GLUT_KEY_RIGHT:
            camera.centre.x -= del;
            camera.eye.x -= del;
            break;
        case GLUT_KEY_PAGE_UP:
            camera.centre.y -= del;
            break;
        case GLUT_KEY_PAGE_DOWN:
            camera.centre.y += del;
            break;
        
    }

    glutPostRedisplay();
}

void rotate_eye_left_right(GLfloat l_r) {
    printf("yo\n");
    GLfloat v = 0.25;
    GLfloat lx = camera.centre.x - camera.eye.x;
    GLfloat lz = camera.centre.z - camera.eye.z;
    GLfloat s;
    camera.eye.x += v * l_r * (camera.up.y*lz);
    camera.eye.z += v * l_r * (-lx*camera.up.y);
    s = sqrt(camera.eye.x*camera.eye.x + camera.eye.z*camera.eye.z) / (4 * sqrt(2));
    camera.eye.x /= s;
    camera.eye.z /= s;
}

bool boundCheck(GLfloat x, GLfloat eps, GLfloat t) {
    if(x > t+eps || x < t-eps) {
        return false;
    }
    return true;
}

void octahedronToSphere() {
    printf("o to S\n");
    if(currentTriangleScale > 0) {
        currentTriangleScale--;
        currentSphereScale--;
        currentCylinderScale--;
    }
}

void sphereToOctahedron() {
    printf("s to o\n");
    if(currentTriangleScale < SCALE_SUBDIVISION) {
        currentTriangleScale++;
        currentSphereScale++;
        currentCylinderScale++;
    }
}

void usualKeyListener(unsigned char key, int x, int y) {
    GLfloat del = 0.2;
    switch(key) {
        case 'w':
            camera.eye.y += del;
            break;
        case 's':
            camera.eye.y -= del;
            break;
        case '1':
            rotate_eye_left_right(1.0);
            break;
        case '2':
            rotate_eye_left_right(-1.0);
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            break;
        case '6':
            break;
        case ',':
            octahedronToSphere();
            break;
        case '.':
            sphereToOctahedron();
            break;
    }
    glutPostRedisplay();
}

#endif