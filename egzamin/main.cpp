#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14159265





void init();
void Reshape(int, int);
void display();
void draw();


float R=1; /// bok

float O=1; /// omega

float A=60; /// alfa





//GLfloat pt[N][3]= {{0,0,0.0},{0,-1.0,0.0},{-10.0,-1.0,0.0},{-8,-1.0,0}};
//GLfloat color[N][3]= {{1,0,0},{0,1,0},{0.0,0,1},{0.0,0,1}};

float obl_VB(float o,float r,float a)  /// Vb dla 60 stopni
{
    float sin_a=sin(a*(PI/180));
    float cos_a=cos(a*(PI/180));
    float cos_b=sqrt(1-(r*r*sin_a*sin_a)/r*sin_a);
    float sin_b=(r*sin_a)/(r*sqrt(3));
    float x=o*r*sin_a+(o*r*(cos_a/cos_b))*sin_b;
    return x;
}

void obl_dVb(float o,float r)  /// dynamiczne Vb co 5 stopni
{
    for(int i=0; i<361; i+=5)
    {
    float sin_a=sin(i*(PI/180));
    float cos_a=cos(i*(PI/180));
    float sin_b=(r*sin_a)/(r*sqrt(3));
    float cos_b=sqrt(1-(r*r*sin_a*sin_a)/r*sin_a);
    float x=o*r*sin_a+(o*r*(cos_a/cos_b))*sin_b;
    std::cout<<"Alfa="<<i<<" Vb="<<x<<std::endl;
    }
}

int main(int argc, char **argv)
{
    float VA=1*1;
    float VB=obl_VB(1,1,60);
    obl_dVb(O, R);
    std::cout<<"Va="<<VA<<" Vb (dla 60 stopni)="<<VB<<std::endl;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);//podwojne buforowanie |GLUTE_DOUBLE | GRAFIKA 3D GLUT_DEPTH
    glutInitWindowPosition(250,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("OpenGL window");
    //funcja wyœwietlanie
    glutDisplayFunc(&display);
    //display();
    glutReshapeFunc(&Reshape);
    init();
    glutMainLoop();
    return 0;
}

void Reshape(int w, int h)
{
    //okresla miejsce i przestrzeni gdzie rysujesz
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    //tryb projekcji
    glMatrixMode(GL_PROJECTION);
    //reset wszytskich transformacji
    glLoadIdentity();
    gluOrtho2D(-2.5,2.5,-2.5,2.5);
    glMatrixMode(GL_MODELVIEW);

}
void display()
{
    //czysczenie buforów do rysowania ¿ebu nie by³o smieci
    glClear(GL_COLOR_BUFFER_BIT);
    //reset transformacji
    glLoadIdentity();
    draw();
    //drukowanie na ekran
    glutSwapBuffers();
}
void init()
{
    //ustawienie kolou tla
    glClearColor(0,0,0,1);
}


void draw()
{
    float sin_a=sin(A*(PI/180));
    float cos_a=cos(A*(PI/180));
    float sin_b=(R*sin_a)/(R*sqrt(3));
    float cos_b=sqrt(1-(R*R*sin_a*sin_a)/R*sin_a);
    //rysowanie punktów
    glPointSize(10);
    glBegin(GL_LINES); //line zamkniente
    //glBegin(GL_TRIANGLES); //powieszchnie
    //glBegin(GL_POLYGON);
    //glBegin(GL_QUADS);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(R*cos_a, R*sin_a, 0.0f);
    glVertex3f(R*cos_a, R*sin_a, 0.0f);
    glVertex3f(R*cos_a+R*sqrt(3)*cos_b,0.0f, 0.0f);
        /*glColor3f(1.0,0,0);
        glVertex2f(0.0,5.0);
        glColor3f(0,1,0);
        glVertex2f(5.0,5.5);
        */
    glEnd();
}
