#include "figure.h"
#include "arc.h"
#include "line.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
using namespace std;
figure::figure()
{
}
void figure::calculate()
{
    float d,A=0,Sx=0,Sy=0,Ix=0,Iy=0,Ixy=0;
    float** a=points_table;

    for(int i=0;i<tab_size-1;i++)
    {
        d=a[i][0]*a[i+1][1]-a[i+1][0]*a[i][1];
        A=A+d/2;
        Sx=Sx+d/6*(a[i][1]+a[i+1][1]);
        Sy=Sy+d/6*(a[i][0]+a[i+1][0]);
        Ix=Ix+d/12*(a[i][1]*a[i][1]+a[i][1]*a[i+1][1]+a[i+1][1]*a[i+1][1]);
        Iy=Iy+d/12*(a[i][0]*a[i][0]+a[i][0]*a[i+1][0]+a[i+1][0]*a[i+1][0]);
        Ixy=Ixy+d/24*(a[i][0]*(2*a[i][1]+a[i+1][1])+a[i+1][0]*(2*a[i+1][1]+a[i][1]));
    }
    printf("Pole:%4.2f\n",A);
    printf("Moment Sx=%4.2f, Sy=%4.2f\n",Sx,Sy);
    printf("Moment Ix=%4.2f, Iy=%4.2f\n",Ix,Iy);
    printf("Moment Ixy=%4.2f\n",Ixy);
}
bool figure::add_poits(float** N_tab_p,int N_size)
{
    float** contener=NULL;
    int contener_size=0;
    int i;

    if(tab_size!=0)
    {
        contener_size=tab_size;
        contener=points_table;
        points_table=NULL;
        tab_size--;
    }


    tab_size=N_size+tab_size;


    try
    {
        points_table= new float*[tab_size];
        for(i=0;i<tab_size;i++)
        {
            points_table[i]= new float[2];

        }
    }
    catch(...)
    {
        for(i;i>0;i--)
        {
            delete[] points_table[i];
        }
        delete points_table;
        cout<<"Blond pamienci";
        return 0;
    }

    if(contener_size!=0)
    {
        for(int j=0;j<contener_size;j++)
        {
            points_table[j][0]=contener[j][0];
            points_table[j][1]=contener[j][1];

        }
        for(int j=contener_size-1;j>=0;j--)
        {
            delete[] contener[j];
        }
        delete[] contener;

        int z=0;
        for(int j=contener_size-1;j<tab_size;j++)
        {
            points_table[j][0]=N_tab_p[z][0];
            points_table[j][1]=N_tab_p[z][1];
            z++;
        }
    }
    else
    {
        for(int j=0;j<tab_size;j++)
        {
            points_table[j][0]=N_tab_p[j][0];
            points_table[j][1]=N_tab_p[j][1];
        }
    }
    return 1;
}

void figure::print()
{

    for(int i=0;i<tab_size;i++)
    {
        cout<<"x("<<i<<")="<<points_table[i][0]<<" ";
        cout<<"y("<<i<<")="<<points_table[i][1]<<endl;
    }
}
void figure::save(string filename)
{

    filename=filename+".csv";
    ofstream myFile(filename);
    // Send column names to the stream
    for(int j = 0; j <tab_size; ++j)
    {
        myFile<<points_table[j][0]<<";";
        myFile<<points_table[j][1]<<"\n";
    }
    myFile.close();
}
bool figure::ad_point_to_table(float x, float y)
{
    float** contener=NULL;
    int contener_size=0;
    int i;
    if(tab_size!=0)
    {
        contener_size=tab_size;
        contener=points_table;
        points_table=NULL;
    }
    tab_size++;

    try
    {
        points_table= new float*[tab_size];
        for(i=0;i<tab_size;i++)
        {
            points_table[i]= new float[2];

        }
    }
    catch(...)
    {
        for(i;i>0;i--)
        {
            delete[] points_table[i];
        }
        delete points_table;
        cout<<"Blond pamienci";
        return 0;
    }

    if(contener_size!=0)
    {
        for(int j=0;j<contener_size;j++)
        {
            points_table[j][0]=contener[j][0];
            points_table[j][1]=contener[j][1];

        }
        for(int j=contener_size-1;j>=0;j--)
        {
            delete[] contener[j];
        }
        delete[] contener;

    }
    points_table[tab_size-1][0]=x;
    points_table[tab_size-1][1]=y;
}
bool figure::load(string filename)
{
        std::ifstream myFile(filename+".csv");
        std::string line;
        if(!myFile.is_open())return 0;
        float val_X;
        float val_Y;
        while(std::getline(myFile, line))
        {
            // Create a stringstream of the current line
            std::stringstream ss(line);

            while(ss >> val_X)
            {
                if(ss.peek() == ';') ss.ignore();
                ss >> val_Y;
                ad_point_to_table(val_X,val_Y);
            }
        }

        // Close file
        myFile.close();
        return 0;
}
float **figure::get_points_table()
{
    return points_table;
}
int figure::get_tab_size()
{
    return tab_size;
}
figure::~figure()
{
    for(int i=tab_size-1;i>=0;i--)
    {
        delete[] points_table[i];
    }
    delete[] points_table;
}
