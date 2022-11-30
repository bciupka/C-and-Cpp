#ifndef FIGURE_H
#define FIGURE_H
#include "arc.h"
#include "line.h"
#include <iostream>
#include <string>
#include <fstream>

class figure
{
    public:
        figure();
        ~figure();
        bool add_poits(float**,int);
        void save(std::string);
        bool load(std::string);
        void print();
        void calculate();
        float ** get_points_table();
        int get_tab_size();
    private:
           bool ad_point_to_table(float,float);
           int tab_size=0;
           float **points_table=NULL;
};

#endif // FIGURE_H
