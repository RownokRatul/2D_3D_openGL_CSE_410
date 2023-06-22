#ifndef _draw3d_header_
#define _draw3d_header_

#include<GL/glut.h>
#include<iostream>
#include<cmath>
#include "point3d.h"
#include "camera.h"
#include "config.h"

void drawLine(point3d a, point3d b) {
    glBegin(GL_LINES);
    {
        glVertex3f(a.x, a.y, a.z);
        glVertex3f(b.x, b.y, b.z);
    }
    glEnd();
}


void drawAxes() {
    glColor3f(1, 0, 0);
    drawLine(point3d(0, 0, 0), point3d(1, 0, 0));
    glColor3f(0, 1, 0);
    drawLine(point3d(0, 0, 0), point3d(0, 1, 0));
    glColor3f(0, 0, 1);
    drawLine(point3d(0, 0, 0), point3d(0, 0, 1));
}

#endif