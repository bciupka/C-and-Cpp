#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "arc.h"
#include "line.h"
#include "figure.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#define N 3
#include <stdlib.h>
#include <stdio.h>

void init();
void Reshape(int, int);
void display();
void keyboard(unsigned char,int,int);
void draw();
void mainmanu();
void point(float*,float,float);
//GLfloat pt[N][3]= {{-5.0,2.0,0.0},{5.0,-2.0,0.0},{0.0,7.0,0}};
figure Figura;

int main(int argc, char **argv)
{

    Figura.load("data");
    Figura.calculate();

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);//podwujne buforowanie |GLUTE_DOUBLE | GRAFIKA 3D GLUT_DEPTH
    glutInitWindowPosition(250,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("OpenGL window");

    //funcja wyœwietlanie
    glutDisplayFunc(&display);
    //display();
    glutReshapeFunc(&Reshape);
    glutKeyboardFunc(&keyboard);
    init();
    mainmanu();
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
    gluOrtho2D(-10.0,10.0,-10.0,10.0);
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
    glFlush();
}
void init()
{
    //ustawienie kolou tla
    glClearColor(0,0,0,1);
}

void keyboard(unsigned char key ,int x, int y)
{
    switch(key)
    {
        case 27: exit(0);
    }
}
;
void mainmanu()
{
    //
}

void draw()
{
    //rysowanie punktów
    GLfloat color[]={1,1,1};
    float**pt;
    int Tab_size;
    pt=Figura.get_points_table();
    Tab_size=Figura.get_tab_size();
    glPointSize(10);
    glBegin(GL_LINE_LOOP); //line zamkniente
    //glBegin(GL_TRIANGLES); //powieszchnie
    //glBegin(GL_POLYGON);
    //glBegin(GL_QUADS);
        for(int i=0;i<Tab_size;i++)
        {
            glColor3f(color[0],color[1],color[2]);
            glVertex2f(pt[i][0],pt[i][1]);
        }
        /*glColor3f(1.0,0,0);
        glVertex2f(0.0,5.0);
        glColor3f(0,1,0);
        glVertex2f(5.0,5.5);
        */
    glEnd();
}


void point(float*tab ,float a,float b)
{
    tab[0]=(a-4.2)*0.1;
    tab[1]=b*0.1;

}
