#pragma once
#ifndef TIME__H
#define TIME__H
#include <string>
using namespace std;
class Time
{
    
protected:
    string id;
    int menu=0;
public:
    virtual void setting_air_Time() {};
    virtual void get_time(int menu, int time, int way) {};
    virtual void get_date(int menu,int x) {};
    virtual void set_info(string get_date, string way1, string way2,string id, string airplane, string get_time="00½Ã") {};
    virtual void set_info(string get_date_s, string get_time_s,string id) {};
    virtual void set_info(string get_date_s,string id) {};
    virtual ~Time() {};
    virtual void set_name(int seat) {}
};
#endif