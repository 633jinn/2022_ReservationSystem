#pragma once
#ifndef STU_TIME__H
#define STU_TIME__H
#include "Time.h"
#include "Seat.h"
#include "stu_Seat.h"
class stu_Time :public Time
{
    Seat* time[15];//15´Â ½Ã°£
    string get_date_s;
    string get_time_s;
    int get_time = 0;
public:
    stu_Time();
    void get_date(int get_menu, int time);
    void set_info(string get_date_s, string get_time_s,string id);
    virtual ~stu_Time();
};
#endif 