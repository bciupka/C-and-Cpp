#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#define N 21
#include <stdlib.h>
#include <stdio.h>

void init();
void Reshape(int, int);
void display();
void draw();

GLfloat pt[N][3] = {{46.0, 66.0, 0.0},{390.0, 66.0, 0.0},{400.0, 68.0, 0.0},{409.0, 70.0, 0.0},{415.0, 72.0, 0.0}, {421.0, 75.0, 0.0},{424.0, 77.0, 0.0}, {427.0, 82.0, 0.0},{429.0, 101.0, 0.0},{430.0, 312.0, 0.0},{236.0, 218.0, 0.0},{303.0, 116.0, 0.0},{23.0, 96.0, 0.0},{23.0, 90.0, 0.0},{24.0, 83.0, 0.0},{26.0, 77.0, 0.0},{29.0, 72.0, 0.0},{31.0, 70.0, 0.0},{34.0, 69.0, 0.0},{41.0, 67.0, 0.0},{46.0, 66.0, 0.0}};
GLfloat color[3][3]= {{1,1,1},{1,1,1},{1.0,1,1}};

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);//podwojne buforowanie |GLUTE_DOUBLE | GRAFIKA 3D GLUT_DEPTH
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("OpenGL window");
    //funcja wyswietlanie
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
    //reset wszystkich transformacji
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
    glMatrixMode(GL_MODELVIEW);
}
void display()
{
    //czysczenie buforow do rysowania zebu nie bylo smieci
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


void draw()
{
    //rysowanie punktów
    glPointSize(10);
    glBegin(GL_LINE_LOOP); //linie zamkniete
    //glBegin(GL_TRIANGLES); //powierzchnie
    //glBegin(GL_POLYGON);
    //glBegin(GL_QUADS);
        for(int i=0;i<N;i++)
        {
            for(int j=0; j<3; j++)
            {
            glColor3f(color[j][0], color[j][1], color[j][2]);
            glVertex3f(pt[i][0], pt[i][1], pt[i][2]);
        }
        }
    glEnd();
}
