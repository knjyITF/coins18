#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

#define pi M_PI

typedef struct {
	double x, y;
}point;

void kochCurve(point p1, point p2, int times) {
	point p3, p4, p5;
	double theta = pi / 3;

	if (times > 0) {
		p3 = (point){ (2 * p1.x + p2.x) / 3,(2 * p1.y + p2.y) / 3 };
		p5 = (point){ (2 * p2.x + p1.x) / 3,(2 * p2.y + p1.y) / 3 };

		p4 = (point){ p3.x + (p5.x - p3.x) * cos(theta) + (p5.y - p3.y) * sin(theta),p3.y - (p5.x - p3.x) * sin(theta) + (p5.y - p3.y) * cos(theta) };

		kochCurve(p1, p3, times - 1);
		kochCurve(p3, p4, times - 1);
		kochCurve(p4, p5, times - 1);
		kochCurve(p5, p2, times - 1);
	}

	else {
		glVertex2d(p1.x, p1.y, p2.x, p2.y);
	}
}

void display(void) {
	int r;
	point p1, p2;

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3d(1.0, 1.0, 1.0);
	glBegin(GL_LINE_STRIP);

	r = atoi(argV[3]);

	p1 = (point){ 10,h - 10 };
	p2 = (point){ w - 10, h - 10 };

	kochCurve(p1, p2, r);

	glEnd();

	glFlush();
}