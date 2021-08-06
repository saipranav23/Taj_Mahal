#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
float _angle=44.0f;
float r =(100.0f/600.0f);
float rx=(70.0f/600.0f);
float sx=1.0f,sy=1.0f,sz=1.0f;
float lx = 0.0, lz = -1.0;
float x = 0.0, z = 5.0, xRot, yRot, zRot;
using namespace std;

void draw()
{
// Draw the bottom box
 glPushMatrix();
 glScaled(0.8,0.04,0.8);
 glTranslatef(0.0,-30.2,0.0);
 glutSolidCube(7.0);
 glPopMatrix();

//main cube
 glTranslatef(0.0,-.6,0.0);
 glutSolidCube(2.0);

 //main gumbazz
 glPushMatrix();
 glScaled(0.8,1.0,0.8);
 glTranslatef(0.0,1.5,0.0);
 glutSolidSphere(0.8,80,120);
 glPopMatrix();

 glTranslatef(0.0,1.0,0.0);
 glScaled(1.2,0.25,1.2);
 glutSolidCube(0.9);

 //gumbaz pointer
 glPushMatrix();
 glScaled(0.03,0.5,0.03);
 glTranslatef(0.0,10.8,0.0);
 glutSolidSphere(0.4,80,120);
 glPopMatrix();

 //Minars
 glPushMatrix();
 glTranslated(2,-1.9,2);
 glScaled(.2,10.5,.2);
 glutSolidSphere(0.4,80,120);
 glPopMatrix();

 //minar's sphere
 glPushMatrix();
 glTranslated(2,0.8,2);
 glScaled(0.3,1.5,0.3);
 glutSolidSphere(0.4,80,120);
 glPopMatrix();

 //Minars
 glPushMatrix();
 glTranslated(-2,-1.9,2);
 glScaled(.2,10.5,.2);
 glutSolidSphere(0.4,80,120);
 glPopMatrix();

 //minar's sphere
 glPushMatrix();
 glTranslated(-2,0.8,2);
 glScaled(0.3,1.5,0.3);
 glutSolidSphere(0.4,80,120);
 glPopMatrix();

 //Minars
 glPushMatrix();
 glTranslated(-2,-1.9,-2);
 glScaled(.2,10.5,.2);
 glutSolidSphere(0.4,80,120);
 glPopMatrix();

 //minar's sphere
 glPushMatrix();
 glTranslated(-2,0.8,-2);
 glScaled(0.3,1.5,0.3);
 glutSolidSphere(0.4,80,120);
 glPopMatrix();

 //Minars
 glPushMatrix();
 glTranslated(2,-1.9,-2);
 glScaled(.2,10.5,.2);
 glutSolidSphere(0.4,80,120);
 glPopMatrix();

 //minar's sphere
 glPushMatrix();
 glTranslated(2,0.8,-2);
 glScaled(0.3,1.5,0.3);
 glutSolidSphere(0.4,80,120);
 glPopMatrix();

 //short Minars
 glPushMatrix();
 glTranslated(0.6,-0.5,0.6);
 glScaled(.2,11.5,.2);
 glutSolidSphere(0.2,80,120);
 glPopMatrix();

 //short minar's sphere
 glPushMatrix();
 glTranslated(0.6,0.5,0.6);
 glScaled(0.3,1.5,0.3);
 glutSolidSphere(0.4,80,120);
 glPopMatrix();

 //short Minars
 glPushMatrix();
 glTranslated(0.6,-0.5,-0.6);
 glScaled(.2,11.5,.2);
 glutSolidSphere(0.2,80,120);
 glPopMatrix();

 //short minar's sphere
 glPushMatrix();
 glTranslated(0.6,0.5,-0.6);
 glScaled(0.3,1.5,0.3);
 glutSolidSphere(0.4,80,120);
 glPopMatrix();

 //short Minars
 glPushMatrix();
 glTranslated(-0.6,-0.5,-0.6);
 glScaled(.2,11.5,.2);
 glutSolidSphere(0.2,80,120);
 glPopMatrix();

 //short minar's sphere
 glPushMatrix();
 glTranslated(-0.6,0.5,-0.6);
 glScaled(0.3,1.5,0.3);
 glutSolidSphere(0.4,80,120);
 glPopMatrix();

 //short Minars
 glPushMatrix();
 glTranslated(-0.6,-0.5,0.6);
 glScaled(.2,11.5,.2);
 glutSolidSphere(0.2,80,120);
 glPopMatrix();

 //short minar's sphere
 glPushMatrix();
 glTranslated(-0.6,0.5,0.6);
 glScaled(0.3,1.5,0.3);
 glutSolidSphere(0.4,80,120);
 glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
    glLoadIdentity();
    gluLookAt( x, 0.0, z, x + lx, 0.0, z + lz, 0.0, 1.0, 0.0);
    glPushMatrix();
    draw();
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}

void initRendering()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glClearDepth(1.0f);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    glEnable(GL_NORMALIZE);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f}; //Color (0.2, 0.2, 0.2)
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
    //Add positioned light
    GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.5, 0.5)
    GLfloat lightPos0[] = {3.0f, 0.0f, 0.3f, 1.0f}; //Positioned at (300, 0, 100)
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

    GLfloat lightColor1[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.5, 0.5)
    GLfloat lightPos1[] = {-5.0f, 0.0f, 8.0f, 1.0f}; //Positioned at (300, 0, 100)
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

    GLfloat lightColor2[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.5, 0.5)
    GLfloat lightPos2[] = {3.0f, 0.0f, 0.5f, 1.0f}; //Positioned at (300, 0, 100)
    glLightfv(GL_LIGHT2, GL_DIFFUSE, lightColor2);
    glLightfv(GL_LIGHT2, GL_POSITION, lightPos2);
}

float frc=0.5f;
void specialkeyboard(int key, int xx, int yy)
{
    float frc = 0.1;
    switch(key)
    {
        case(GLUT_KEY_LEFT):
        _angle -= 0.05;
        lx = sin(_angle);
        lz = -cos(_angle);
        break;

        case(GLUT_KEY_RIGHT):
            _angle += 0.05;
            lx = sin(_angle);
            lz = -cos(_angle);
            break;

        case(GLUT_KEY_UP):
            x += lx*frc;
            z += lz*frc;
            break;

        case(GLUT_KEY_DOWN):
            x -= lx*frc;
            z -= lz*frc;
            break;

        default: break;
    }
    glutPostRedisplay();
}

void handleResize(int w, int h) {

    double w2h = (h>0) ? (double)w/h:1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    gluPerspective(45.0f, (double)w / (double)h, 1.0f, 200.0f);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void windowMenu(int value)
{
    specialkeyboard((unsigned char)value, 0, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("Taj Mahal");
    initRendering();
    glutDisplayFunc(display);
    glutReshapeFunc(handleResize);

    glutSpecialFunc(specialkeyboard);
    glutCreateMenu(windowMenu);
    glutAddMenuEntry("Move LEFT ",GLUT_KEY_LEFT);
    glutAddMenuEntry("Move RIGHT ",GLUT_KEY_RIGHT);
    glutAddMenuEntry("Zoom IN ",GLUT_KEY_UP);
    glutAddMenuEntry("Zoom OUT ",GLUT_KEY_DOWN);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}
