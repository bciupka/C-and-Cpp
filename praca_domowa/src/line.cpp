#include "line.h"
#include <iostream>
#include <math.h>

using namespace std;
line::line()
{
    //ctor
}
line::line(float* N_starting_point,float* N_end_point)
{
    Starting_point[0]=N_starting_point[0];
    Starting_point[1]=N_starting_point[1];

    end_point[0]=N_end_point[0];
    end_point[1]=N_end_point[1];
    line_length=distance_between_points(Starting_point,end_point);
    tab_size=2;
    Create_points_list();
}
void line::print()
{
    cout<<"Punkty:["<<Starting_point[0]<<","<<Starting_point[1]<<"]"<<endl;
    cout<<"["<<end_point[0]<<","<<end_point[1]<<"]"<<endl;
    cout<<"dugosc:"<<line_length<<endl;
    cout<<"Punkty listy:"<<endl;
    for(int i=0;i<tab_size;i++)
    {
        cout<<"x("<<i<<")="<<points_table[i][0]<<" ";
        cout<<"y("<<i<<")="<<points_table[i][1]<<endl;
    }
}
bool line::Create_points_list()
{
    int i;
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
        points_table[tab_size-1][0]=end_point[0];
        points_table[tab_size-1][1]=end_point[1];
        return 1;
}
float line::distance_between_points(float* Point1,float* Point2)
{
    return sqrt(pow(Point2[0]-Point1[0],2)+pow(Point2[1]-Point1[1],2));
}
float ** line::get_points_table()
{
    return points_table;
}
int line::get_tab_size()
{
    return tab_size;
}
line::~line()
{
    for(int i=tab_size-1;i>=0;i--)
    {
        delete[] points_table[i];
    }
    delete[] points_table;
}
