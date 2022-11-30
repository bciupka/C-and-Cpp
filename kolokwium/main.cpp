#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define PI 3.14159265
#include<iostream>

//Program oblicza prędkości Va, Vb, Vba dla danego kąta alfa, prędkości Vb oraz Vba dla zmiennego kąta alfa, rysuje ramiona układu wodzikowego za pomocą OpenGL (wersja statyczna, bez symulacji ruchu)


void init();
void Reshape(int, int);
void display();
void draw();
float R=1;
float omega=1;
float alfa=60;


float calcStaticVb(float omega,float r,float alfa)
{
    float sinAlfa=sin(alfa*(PI/180));
    float cosAlfa=cos(alfa*(PI/180));
    float sinBeta=(r*sinAlfa)/(r*sqrt(3));
    float cosBeta=sqrt(1-(r*r*sinAlfa*sinAlfa)/r*sinAlfa);
    float x=omega*r*sinAlfa+(omega*r*(cosAlfa/cosBeta))*sinBeta;
    return x;
}

float calcStaticVba(float omega,float r,float alfa)
{
    float sinAlfa=sin(alfa*(PI/180));
    float cosAlfa=cos(alfa*(PI/180));
    float cosBeta=sqrt(1-(r*r*sinAlfa*sinAlfa)/r*sinAlfa);
    float Va = omega*r;
    float y=Va*(cosAlfa/cosBeta);
    return y;
}

void calcDynamicVb(float omega,float r)
{
    for(int i=0; i<361; i+=10)
    {
    float sinAlfa=sin(i*(PI/180));
    float cosAlfa=cos(i*(PI/180));
    float sinBeta=(r*sinAlfa)/(r*sqrt(3));
    float cosBeta=sqrt(1-(r*r*sinAlfa*sinAlfa)/r*sinAlfa);
    float x=omega*r*sinAlfa+(omega*r*(cosAlfa/cosBeta))*sinBeta;
    std::cout<<"Alfa="<<i<<" Vb="<<x<<std::endl;
    }
}

void calcDynamicVba(float omega,float r)
{
    for(int i=0; i<361; i+=10)
    {
    float sinAlfa=sin(i*(PI/180));
    float cosAlfa=cos(i*(PI/180));
    float cosBeta=sqrt(1-(r*r*sinAlfa*sinAlfa)/r*sinAlfa);
    float Va = omega*r;
    float y=Va*(cosAlfa/cosBeta);
    std::cout<<"Alfa="<<i<<" Vba="<<y<<std::endl;
    }
}

int main(int argc, char **argv)
{
    std::cout<<"Predkosci statyczne:\n"<<std::endl;
    float Va=omega*R;
    float Vb=calcStaticVb(omega,R,alfa);
    float Vba=calcStaticVba(omega, R, alfa);
    std::cout<<"Va="<<Va<<"\nVb="<<Vb<<"\nVba="<<Vba<<"\n\n"<<std::endl;
    std::cout<<"Predkosci Vb dynamiczne:\n"<<std::endl;
    calcDynamicVb(omega, R);
    std::cout<<"\n\nPredkosci Vba dynamiczne:\n"<<std::endl;
    calcDynamicVba(omega, R);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);//podwujne buforowanie |GLUTE_DOUBLE | GRAFIKA 3D GLUT_DEPTH
    glutInitWindowPosition(250,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("OpenGL window");
    //funcja wyœwietlanie
    glutDisplayFunc(&display);
    //display();
    glutReshapeFunc(&Reshape);

    //cylkicznie wywolywanu obiekt ierwsze czas przerwy drugie funkcja wywoływana no i jakas val

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
    gluOrtho2D(-3.0,3.0,-3.0,3.0);
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
    float sinAlfa=sin(alfa*(PI/180));
    float cosAlfa=cos(alfa*(PI/180));
    float sinBeta=(R*sinAlfa)/(R*sqrt(3));
    float cosBeta=sqrt(1-(R*R*sinAlfa*sinAlfa)/R*sinAlfa);
    //rysowanie punktów
    glPointSize(10);
    glBegin(GL_LINES); //line zamkniente
    //glBegin(GL_TRIANGLES); //powieszchnie
    //glBegin(GL_POLYGON);
    //glBegin(GL_QUADS);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(R*cosAlfa, R*sinAlfa, 0.0f);
    glVertex3f(R*cosAlfa, R*sinAlfa, 0.0f);
    glVertex3f(R*cosAlfa+R*sqrt(3)*cosBeta,0.0f, 0.0f);
        /*glColor3f(1.0,0,0);
        glVertex2f(0.0,5.0);
        glColor3f(0,1,0);
        glVertex2f(5.0,5.5);
        */
    glEnd();
}
