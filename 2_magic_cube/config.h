#ifndef _config_header_
#define _config_header_

#include<GL/glut.h>
#include<iostream>
#include "camera.h"

#define PI 2*acos(0.0)

Camera camera(point3d(4, 4, 4), point3d(0, 0, 0), point3d(0, 1, 0));
GLfloat dihedral_angle = 70.5287794;


#endif
