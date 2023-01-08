#pragma once
#ifndef SEAT__H
#define SEAT__H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
using namespace std;

class Seat
{
    
protected:
    string id;
    char* name[8];
    char* time = new char[5];
    int seat_num;
    char get_name[20];
    string res_name;
    fstream f_id;
    fstream f_system;// 프로그램별 예약정보 저장
    fstream help_info;
public:
    virtual void reserve() {}
    virtual void cancel() {}
    virtual void show() {}
    virtual void reserve(int way) {}
    virtual void cancel(int way) {}
    virtual void get_timeseat(const char* x) {}
    virtual void get_timeseat() {}
    virtual void w_in_reserve() {}
    virtual void w_in_cancel() {}
    virtual void w_in_show() {}
    virtual void set_info(string get_date_s,string id) {}
    virtual void set_info(string get_date, string get_time,string id) {}
    virtual void set_info(string get_date, string get_time, string way1, string way2,string id, string airplane) {}
    virtual ~Seat() {
        delete[]time;
    }
};

#endif 