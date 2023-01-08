#pragma once
#ifndef AIR_TIME__H
#define AIR_TIME__H
#include <iostream>
#include "Time.h"
#include "Seat.h"
#include "air_Seat.h"
class air_Time :public Time
{
    Seat* time_07[20];
    Seat* time_12[20];
    Seat* time_17[20];
    string get_date_s;
    string get_time_s;
    string way1;
    string way2;
    string airplane;
public:
    air_Time();
    void setting_air_Time();
    void get_time(int menu, int time, int way);
    void set_info(string get_date, string get_time, string way1, string way2,string id,string airplane);
    virtual ~air_Time();
    

};
#endif