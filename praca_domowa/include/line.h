#ifndef LINE_H
#define LINE_H
#include <iostream>


class line
{
    public:
        line();
        line(float*,float*);
        ~line();
        float **get_points_table();
        int get_tab_size();
        void print();
private:
            float distance_between_points(float*,float*);
            bool Create_points_list(void);
            float Starting_point[2];
            float end_point[2];
            float line_length;
            int tab_size=0;
            float **points_table;
};

#endif // LINE_H
