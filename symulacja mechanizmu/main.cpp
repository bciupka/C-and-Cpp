#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<iostream>
#define PI 3.14159265
#define N 4
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
void init();
void Reshape(int, int);
void display();
void keyboard(unsigned char,int,int);
void draw();
void mainmanu();
void menu(int);
float R=1;
float Omega=1;
float Alfa=60;
GLfloat x_pos=-10;
GLfloat y_pos=0;
GLint x_kierunek=1;
GLint y_kierunek=1;
GLfloat x_delta=0;
GLfloat y_delta=0;




//GLfloat pt[N][3]= {{0,0,0.0},{0,-1.0,0.0},{-10.0,-1.0,0.0},{-8,-1.0,0}};
//GLfloat color[N][3]= {{1,0,0},{0,1,0},{0.0,0,1},{0.0,0,1}};
void Timer(int);
float get_VB(float omega,float r,float alfa)
{
    float sin_alfa=sin(alfa*(PI/180));
    float cos_alfa=cos(alfa*(PI/180));
    float sin_beta=(r*sin_alfa)/(r*sqrt(3));
    float cos_beta=sqrt(1-(r*r*sin_alfa*sin_alfa)/r*sin_alfa);
    float val=omega*r*sin_alfa+(omega*r*(cos_alfa/cos_beta))*sin_beta;
    return val;
}
int main(int argc, char **argv)
{
    float VA=1*1;
    float VB=get_VB(1,1,60);
    std::cout<<"Va="<<VA<<" Vb="<<VB<<std::endl;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);//podwujne buforowanie |GLUTE_DOUBLE | GRAFIKA 3D GLUT_DEPTH
    glutInitWindowPosition(250,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("OpenGL window");
    //funcja wyœwietlanie
    glutDisplayFunc(&display);
    //display();
    glutReshapeFunc(&Reshape);
    glutKeyboardFunc(&keyboard);
    //cylkicznie wywolywanu obiekt ierwsze czas przerwy drugie funkcja wywoływana no i jakas val
    mainmanu();
    glutTimerFunc(0,&Timer,0);
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

void keyboard(unsigned char key ,int x, int y)
{
    switch(key)
    {
        case 27: exit(0);
    }
}
void menu(int n)
{
    switch(n)
    {
        case 1:
            if(x_delta==0)
            {
                x_delta=0.1*x_kierunek;
                y_delta=0.1*y_kierunek;
            }
            break;
        case 2:
            x_delta=0;
            y_delta=0;
            break;
        case 3:
            x_delta=x_delta+x_delta*0.5;
            y_delta=y_delta+y_delta*0.5;
            break;
        case 4:
            x_delta=x_delta-x_delta*0.5;
            y_delta=y_delta-y_delta*0.5;
            break;

    }

}
void mainmanu()
{
    glutCreateMenu(menu);
        glutAddMenuEntry("Start",1);
        glutAddMenuEntry("Stop",2);
        glutAddMenuEntry("Faster",3);
        glutAddMenuEntry("Slower",4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void draw()
{
    float sin_alfa=sin(Alfa*(PI/180));
    float cos_alfa=cos(Alfa*(PI/180));
    float sin_beta=(R*sin_alfa)/(R*sqrt(3));
    float cos_beta=sqrt(1-(R*R*sin_alfa*sin_alfa)/R*sin_alfa);
    //rysowanie punktów
    glPointSize(10);
    glBegin(GL_LINES); //line zamkniente
    //glBegin(GL_TRIANGLES); //powieszchnie
    //glBegin(GL_POLYGON);
    //glBegin(GL_QUADS);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(R*cos_alfa, R*sin_alfa, 0.0f);
    glVertex3f(R*cos_alfa, R*sin_alfa, 0.0f);
    glVertex3f(R*cos_alfa+R*sqrt(3)*cos_beta,0.0f, 0.0f);
        /*glColor3f(1.0,0,0);
        glVertex2f(0.0,5.0);
        glColor3f(0,1,0);
        glVertex2f(5.0,5.5);
        */
    glEnd();
}
void Timer(int t)
{
    /*if(pt[3][0]>10||pt[0][0]<-10)
    {
        x_kierunek=-x_kierunek;
        x_delta=x_delta*x_kierunek;
    }
    if(pt[3][1]>10||pt[1][1]<-10)
    {
        y_kierunek=-y_kierunek;
        y_delta=y_delta*y_kierunek;
    }
    for(int i=0;i<N;i++)
    {
        pt[i][0]=pt[i][0]+x_delta;
        pt[i][1]=pt[i][1]+y_delta;
    }*/
    glutPostRedisplay();
    glutTimerFunc(1000/60,&Timer,0);
}
