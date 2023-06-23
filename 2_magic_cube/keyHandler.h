#ifndef _KEY_header_
#define _KEY_header_

#include <GL/glut.h>
#include <cmath>
#include <stdio.h>
#include "config.h"

void specialKeyListener(int key, int x, int y) {
    GLfloat eyeToCentre_x = camera.centre.x - camera.eye.x;
    GLfloat eyeToCentre_y = camera.centre.z - camera.eye.z;
    GLfloat proj;

    switch(key) {
        case GLUT_KEY_UP:
            camera.eye.x += camera.centre.x;
            camera.eye.y += camera.centre.y;
            camera.eye.z += camera.centre.z;
            break;
        case GLUT_KEY_DOWN:
            camera.eye.x -= camera.centre.x;
            camera.eye.y -= camera.centre.y;
            camera.eye.z -= camera.centre.z;
            break;
        case GLUT_KEY_LEFT:
            camera.eye.x += camera.right.x;
            camera.eye.y += camera.right.y;
            camera.eye.z += camera.right.z;
            break;
        case GLUT_KEY_RIGHT:
            camera.eye.x -= camera.right.x;
            camera.eye.y -= camera.right.y;
            camera.eye.z -= camera.right.z;
            break;
        case GLUT_KEY_PAGE_UP:
            camera.eye.x += camera.up.x;
            camera.eye.y += camera.up.y;
            camera.eye.z += camera.up.z;
            break;
        case GLUT_KEY_PAGE_DOWN:
            camera.eye.x -= camera.up.x;
            camera.eye.y -= camera.up.y;
            camera.eye.z -= camera.up.z;
            break;
        
    }

    glutPostRedisplay();
}

void rotate_eye_left_right(GLfloat f) {
    camera.right.x = camera.right.x*cos(f*DEL)+camera.centre.x*sin(f*DEL);
    camera.right.y = camera.right.y*cos(f*DEL)+camera.centre.y*sin(f*DEL);
    camera.right.z = camera.right.z*cos(f*DEL)+camera.centre.z*sin(f*DEL);

    camera.centre.x = camera.centre.x*cos(f*DEL)-camera.right.x*sin(f*DEL);
    camera.centre.y = camera.centre.y*cos(f*DEL)-camera.right.y*sin(f*DEL);
    camera.centre.z = camera.centre.z*cos(f*DEL)-camera.right.z*sin(f*DEL);
}

void rotate_eye_up_down(GLfloat f) {
    camera.centre.x = camera.centre.x*cos(f*DEL)+camera.up.x*sin(f*DEL);
    camera.centre.y = camera.centre.y*cos(f*DEL)+camera.up.y*sin(f*DEL);
    camera.centre.z = camera.centre.z*cos(f*DEL)+camera.up.z*sin(f*DEL);

    camera.up.x = camera.up.x*cos(f*DEL)-camera.centre.x*sin(f*DEL);
    camera.up.y = camera.up.y*cos(f*DEL)-camera.centre.y*sin(f*DEL);
    camera.up.z = camera.up.z*cos(f*DEL)-camera.centre.z*sin(f*DEL);
}

void tilt_eye(GLfloat f) {
    camera.up.x = camera.up.x*cos(f*DEL)+camera.right.x*sin(f*DEL);
    camera.up.y = camera.up.y*cos(f*DEL)+camera.right.y*sin(f*DEL);
    camera.up.z = camera.up.z*cos(f*DEL)+camera.right.z*sin(f*DEL);

    camera.right.x = camera.right.x*cos(f*DEL)-camera.up.x*sin(f*DEL);
    camera.right.y = camera.right.y*cos(f*DEL)-camera.up.y*sin(f*DEL);
    camera.right.z = camera.right.z*cos(f*DEL)-camera.up.z*sin(f*DEL);
}

bool boundCheck(GLfloat x, GLfloat eps, GLfloat t) {
    if(x > t+eps || x < t-eps) {
        return false;
    }
    return true;
}

void octahedronToSphere() {
    // printf("o to S\n");
    if(currentTriangleScale > 0) {
        currentTriangleScale--;
        currentSphereScale--;
        currentCylinderScale--;
    }
}

void sphereToOctahedron() {
    // printf("s to o\n");
    if(currentTriangleScale < SCALE_SUBDIVISION) {
        currentTriangleScale++;
        currentSphereScale++;
        currentCylinderScale++;
    }
}

void usualKeyListener(unsigned char key, int x, int y) {
    switch(key) {
        case 'w':
            camera.eye.y += DEL;
            break;
        case 's':
            camera.eye.y -= DEL;
            break;
        case '1':
            // look left
            rotate_eye_left_right(1.0);
            break;
        case '2':
            rotate_eye_left_right(-1.0);
            break;
        case '3':
            rotate_eye_up_down(1.0);
            break;
        case '4':
            rotate_eye_up_down(-1.0);
            break;
        case '5':
            tilt_eye(1.0);
            break;
        case '6':
            tilt_eye(-1.0);
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