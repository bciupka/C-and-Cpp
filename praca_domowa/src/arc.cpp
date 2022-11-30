#include "arc.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#define Pi 3.14159265359
#define Precision 1.0
using namespace std;
arc::arc()
{

}
arc::arc(float* N_starting_point,float* N_mid_point,float* N_end_point)
{
    Starting_point[0]=N_starting_point[0];
    Starting_point[1]=N_starting_point[1];

    mid_point[0]=N_mid_point[0];
    mid_point[1]=N_mid_point[1];

    end_point[0]=N_end_point[0];
    end_point[1]=N_end_point[1];
    radius=distance_between_points(mid_point,Starting_point);
    angle=180/Pi*angle_determination(distance_between_points(mid_point,Starting_point),distance_between_points(mid_point,end_point),distance_between_points(end_point,Starting_point));
    tab_size=(((int)angle/Precision))+2;
    Create_points_list();
}
arc::arc(float* N_starting_point,float* N_mid_point,float* N_end_point,bool N_direction)
{
    Starting_point[0]=N_starting_point[0];
    Starting_point[1]=N_starting_point[1];

    mid_point[0]=N_mid_point[0];
    mid_point[1]=N_mid_point[1];

    end_point[0]=N_end_point[0];
    end_point[1]=N_end_point[1];
    radius=distance_between_points(mid_point,Starting_point);
    angle=180/Pi*angle_determination(distance_between_points(mid_point,Starting_point),distance_between_points(mid_point,end_point),distance_between_points(end_point,Starting_point));
    tab_size=(((int)angle/Precision))+2;
    reverse_direction=N_direction;
    Create_points_list();
}
float arc::angle_determination(float a,float b,float c)
{
    return acos((pow(a,2)+pow(b,2)-pow(c,2))/(4*a*b));
}
void arc::print()
{
    cout<<"Punkty:["<<Starting_point[0]<<","<<Starting_point[1]<<"]"<<endl;
    cout<<"["<<mid_point[0]<<","<<mid_point[1]<<"]"<<endl;
    cout<<"["<<end_point[0]<<","<<end_point[1]<<"]"<<endl;
    cout<<"Promien:"<<radius<<endl;
    cout<<"Kat:"<<angle<<endl;
    cout<<"Punkty na luku:"<<endl;
    //cout<<180/Pi*acos((Starting_point[0]-mid_point[0])/radius)<<endl;
    for(int i=0;i<tab_size;i++)
    {
        cout<<"x("<<i<<")="<<points_table[i][0]<<" ";
        cout<<"y("<<i<<")="<<points_table[i][1]<<endl;
    }
}
bool arc::Create_points_list()
{
    int i;
    float start_angle=180/Pi*acos((Starting_point[0]-mid_point[0])/radius);
    if(Starting_point[0]-mid_point[0]>=0 && Starting_point[1]-mid_point[1]<0)
    {
        start_angle=start_angle+180;
    }
    float step_angle=Precision;
    if(reverse_direction==true)
    {
        start_angle=start_angle-360;
        step_angle=-step_angle;
    }
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

        points_table[0][0]=Starting_point[0];
        points_table[0][1]=Starting_point[1];
        for(i=0;i<tab_size-1;i++)
        {
            points_table[i+1][0]=radius*cos(Pi/180*((i+1)*step_angle+start_angle))+mid_point[0];
            points_table[i+1][1]=radius*sin(Pi/180*((i+1)*step_angle+start_angle))+mid_point[1];
        }
        points_table[tab_size-1][0]=end_point[0];
        points_table[tab_size-1][1]=end_point[1];
        return 1;
}

float arc::distance_between_points(float* Point1,float* Point2)
{
    return sqrt(pow(Point2[0]-Point1[0],2)+pow(Point2[1]-Point1[1],2));
}
float ** arc::get_points_table()
{
    return points_table;
}
int arc::get_tab_size()
{
    return tab_size;
}

arc::~arc()
{
    for(int i=tab_size-1;i>=0;i--)
    {
        delete[] points_table[i];
    }
    delete[] points_table;
}
