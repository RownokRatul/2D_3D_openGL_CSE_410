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

void drawTriangle(point3d a, point3d b, point3d c) {
    glBegin(GL_TRIANGLES);
    {
        glVertex3f(a.x, a.y, a.z);
        glVertex3f(b.x, b.y, b.z);
        glVertex3f(c.x, c.y, c.z);
    }
    glEnd();
}

void drawBasicTriangle() {
    drawTriangle(point3d(1, 0, 0), point3d(0, 1, 0), point3d(0, 0, 1));
}

void drawOctahedron() {
    glPushMatrix();
        bool col = 1;
        for(int i=0;i<4;i++) {
            glColor3f(col, !col, col);
            col = !col;
            drawBasicTriangle();
            glPushMatrix();
                glColor3f(col, !col, col);
                glRotatef(45.0, 0, 1, 0);
                glRotatef(180.0, 0, 0, 1);
                glRotatef(-45.0, 0, 1, 0);
                drawBasicTriangle();
            glPopMatrix();
            glRotatef(90.0, 0, 1, 0);
            
        }
    glPopMatrix();
}

void drawAxes() {
    glColor3f(1, 0, 0);
    drawLine(point3d(0, 0, 0), point3d(2, 0, 0));
    glColor3f(0, 1, 0);
    drawLine(point3d(0, 0, 0), point3d(0, 2, 0));
    glColor3f(0, 0, 1);
    drawLine(point3d(0, 0, 0), point3d(0, 0, 2));
}

#endif