#pragma once
#ifndef STUDY__H
#define STUDY__H
#include "stu_Time.h"
#include "Booking.h"
extern map<string, vector<string>>info[3];
extern map<string, vector<int>>stats[3];
extern map<string, vector<string>>stats_sex;
extern string ID[3];
class Study :public Booking
{
    Time* time[7] ;
public:
    Study();
    void prt_menu();
    void prt_date();
    void prt_time();
    virtual ~Study();
    void print_stats_sex(fstream& f_id);
};
#endif // !STUDY__H