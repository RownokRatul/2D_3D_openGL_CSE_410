#ifndef _camera_header_
#define _camera_header_

#include<iostream>
#include<GL/glut.h>
#include "point3d.h"


class Camera {

    public:

        point3d eye;
        point3d centre;
        point3d up;

        Camera(point3d e, point3d c, point3d u) {
            eye = e;
            centre = c;
            up = u;
        }

        Camera() {

        }

};

#endif