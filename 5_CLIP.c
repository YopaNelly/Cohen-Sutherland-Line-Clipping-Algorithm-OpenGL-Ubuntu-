#include <GL/glut.h>
#include <stdio.h>
#include <unistd.h>

#define INSIDE 0
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

float xmin = 50, ymin = 10, xmax = 80, ymax = 40;

/* Compute region code */
int computeCode(float x, float y) {
    int code = INSIDE;
    if (x < xmin) code |= LEFT;
    else if (x > xmax) code |= RIGHT;
    if (y < ymin) code |= BOTTOM;
    else if (y > ymax) code |= TOP;
    return code;
}

/* Draw a point */
void drawPoint(float x, float y) {
    glPointSize(6);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    glFlush();
}

/* Cohen–Sutherland algorithm */
void cohenSutherland(float x1, float y1, float x2, float y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);

    /* Draw original line */
    glColor3f(1, 0, 0); // Red
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
    glFlush();
    sleep(2);

    while (1) {
        if ((code1 | code2) == 0) {
            /* Draw clipped line */
            glColor3f(0, 1, 0); // Green
            glBegin(GL_LINES);
            glVertex2f(x1, y1);
            glVertex2f(x2, y2);
            glEnd();
            glFlush();
            break;
        }
        else if (code1 & code2) {
            break;
        }
        else {
            float x, y;
            int codeOut = code1 ? code1 : code2;

            if (codeOut & TOP) {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            }
            else if (codeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            }
            else if (codeOut & RIGHT) {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            }
            else {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            /* Draw intersection point */
            glColor3f(1, 1, 0); // Yellow
            drawPoint(x, y);
            sleep(1);

            if (codeOut == code1) {
                x1 = x; y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x; y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
}

/* Display function */
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    /* Draw clipping window */
    glColor3f(1, 1, 1); // White
    glBegin(GL_LINE_LOOP);
    glVertex2f(xmin, ymin);
    glVertex2f(xmax, ymin);
    glVertex2f(xmax, ymax);
    glVertex2f(xmin, ymax);
    glEnd();
    glFlush();

    sleep(1);

    cohenSutherland(40, 15, 75, 45);
    sleep(2);
    cohenSutherland(70, 20, 100, 10);
}

/* Main */
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Cohen-Sutherland Line Clipping");

    glClearColor(0, 0, 0, 1);
    gluOrtho2D(0, 120, 0, 120);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

