#include<GL/glut.h>
#include<iostream>
#include<math.h>
#include<ctime>

#define PI (2*acos(0.0))

using namespace std;

GLfloat outer_radius = 0.55;
GLfloat inner_radius = 0.5;
int steps_to_draw = 50;
GLfloat hand_length = 0.2;
GLfloat hand_width = 0.015;

struct point {
    GLfloat x;
    GLfloat y;

    point(GLfloat a, GLfloat b) {
        x = a;
        y = b;
    }

    point() {

    }
};


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

void drawCircle(point c, GLfloat r, int steps) {
    // cout << "hello\n";
    // drawLine(point(0, 0), point(0.5, 0));
    point prev, cur;
    GLfloat theta = 0.0;
    GLfloat eachStep = 2*PI/steps;
    prev.x = c.x + r*cos(theta);
    prev.y = c.y + r*sin(theta);
    for(int i=0;i<steps;i++) {
        theta += eachStep;
        cur.x = c.x + r*cos(theta);
        cur.y = c.y + r*sin(theta);
        drawLine(prev, cur);
        prev = cur;
    }
}

void drawTimeIndicator(int howMany, GLfloat scale) {
    glPushMatrix();
        for(int i=0;i<howMany;i++) {
            drawLine(point(0, inner_radius), point(0, inner_radius/scale));
            glRotatef(360.0/howMany, 0, 0, 1);
        }
    glPopMatrix();
}

void indicateDial() {
    drawTimeIndicator(4, 1.25);
    drawTimeIndicator(12, 1.15);
    drawTimeIndicator(60, 1.05);
}

void drawClockBody() {
    drawCircle(point(0.0, 0.0), inner_radius, steps_to_draw);
    drawCircle(point(0.0, 0.0), outer_radius, steps_to_draw);
    indicateDial();
}

void mapHands(GLfloat l, GLfloat w, GLfloat rot) {
    // cout << rot << endl;
    glPushMatrix();
        glRotatef(rot, 0, 0, 1);
        drawQuad(point(w, 0), point(w, l), point(-w, l), point(-w, 0.0));
        drawTriangle(point(w, l), point(-w, l), point(0.0, l+l/2.5));
    glPopMatrix();
}

void drawHands(int value) {
    glutTimerFunc(1000, drawHands, 0);
    time_t now = time(0);
    tm *local = localtime(&now);
    // cout << local->tm_hour << ":" << local->tm_min << ":" << local->tm_sec << "\n";
    GLfloat hour = local->tm_hour*1.0 + local->tm_min/60.0 ;
    GLfloat min = local->tm_min*1.0 + local->tm_sec/60.0;
    mapHands(hand_length/1.2, hand_width/1.2, -(hour/12.0)*360.0); // hour
    mapHands(hand_length/0.9, hand_width/2, -(min/60.0)*360.0); // minute
    mapHands(hand_length/0.8, hand_width/3, -(local->tm_sec/60.0)*360.0); // second
    // glutPostRedisplay();
}

void makeClock() {
    drawClockBody();
    drawHands(0);
}

void idle() {
    glutPostRedisplay();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0, 0, 0, 0); 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    time_t now = time(0);
    tm *local = localtime(&now);
    // cout << local->tm_hour << ":" << local->tm_min << ":" << local->tm_sec << "\n";
    makeClock();

    glutSwapBuffers();
}






void gl_init(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
    glutCreateWindow("Clock");
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char* argv[]) {
    // cout << "hello\n";
    gl_init(argc, argv);

    glutDisplayFunc(display);
    glutIdleFunc(idle);

    glutMainLoop();
    
    return 0;
}