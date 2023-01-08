#pragma once
#ifndef BOOKING__H
#define BOOKING__H
#include <iostream>
#include "air_Time.h"
#include "Time.h"
#include <string>
#include <fstream>
using namespace std;
class Booking
{
protected:
    int get_menu=0;
    int get_time=0;
    int get_date=0;
    int walkin_menu=0;
    string id;
    string password;
    string _password;
    fstream f_id;
public:
    static map<string, string> login[3];
    virtual void prt_menu() = 0;
    virtual void prt_date() = 0;
    virtual void prt_time(int w){};
    virtual ~Booking() {};
    void make_id(fstream& f_id);
    virtual bool find_id(fstream& f_id, string id);
    virtual void read_info(fstream& f_id);
    virtual void print_stats(fstream& f_id, int size);
    
};
#endif