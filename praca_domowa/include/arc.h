#ifndef ARC_H
#define ARC_H


class arc
{
public:
            arc();
            arc(float*,float*,float*);
            arc(float*,float*,float*,bool);
            ~arc();
            void print();
            int get_tab_size();
            float **get_points_table();
private:
            float distance_between_points(float*,float*);
            float angle_determination(float,float,float);
            bool Create_points_list(void);
            float Starting_point[2];
            float end_point[2];
            float mid_point[2];
            float radius;
            float angle;
            int tab_size=0;
            float **points_table;
            bool reverse_direction;

    };

#endif // ARC_H
