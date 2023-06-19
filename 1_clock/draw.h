#ifndef _draw_header_
#define _draw_header_

#include<iostream>
#include<GL/glut.h>
#include<math.h>
#include "config.h"
#include "point.h"


void drawLine(point a, point b) {
    // cout << a.x << " " << b.x << endl;
    glBegin(GL_LINES); {
        glVertex2f(a.x, a.y);
        glVertex2f(b.x, b.y);
    } glEnd();
}

void drawTriangle(point a, point b, point c) {
    glBegin(GL_TRIANGLES); {
        glVertex2f(a.x, a.y);
        glVertex2f(b.x, b.y);
        glVertex2f(c.x, c.y);
    } glEnd();
}

void drawQuad(point a, point b, point c, point d) {
    glBegin(GL_QUADS); {
        // given points should be counter clockwise
        glVertex2f(a.x, a.y);
        glVertex2f(b.x, b.y);
        glVertex2f(c.x, c.y);
        glVertex2f(d.x, d.y);
    }glEnd();
}

void drawCircle(GLfloat r, int steps) {
    // cout << "hello\n";
    // drawLine(point(0, 0), point(0.5, 0));
    point prev, cur;
    GLfloat theta = 0.0;
    GLfloat eachStep = 2*PI/steps;
    prev.x = r*cos(theta);
    prev.y = r*sin(theta);
    for(int i=0;i<steps;i++) {
        theta += eachStep;
        cur.x = r*cos(theta);
        cur.y = r*sin(theta);
        drawLine(prev, cur);
        prev = cur;
    }
}

#endif