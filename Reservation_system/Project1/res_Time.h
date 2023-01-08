#pragma once
#include "Time.h"
#include "Seat.h"
#include "res_Seat.h"
class res_Time :public Time
{
    Seat* seat;
    string get_date_s;
public:
    res_Time();
    void get_date(int menu, int x);
    void set_info(string get_date_s, string id);
    ~res_Time();
};