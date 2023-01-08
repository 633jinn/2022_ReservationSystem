#pragma once
#ifndef AIR_SEAT__H
#define AIR_SEAT__H
#include <vector>
#include "Seat.h"
extern map<string, vector<string>>info[3];
extern map<string, vector<int>>stats[3];
extern string ID[3];

using namespace std;
class air_Seat :public Seat
{
    string get_date_s;
    string get_time_s;
    string way1;
    string way2;
    string airplane;
public:
    air_Seat();
    //static map<string, int> mile;//마일리지 적립
    void get_timeseat(const char* x);
    void reserve(int way);
    void cancel(int way);
    void show();
    void prt_way(char* get_name);
    void set_info(string get_date, string get_time, string way1, string way2,string id, string airplane);
    void available_seat(int money);
    void erase_file(fstream& f_id, string txt);
    void save_file(fstream& f_id);
    void open_file(fstream& f_id);
    int get_mile(fstream& f_id);
    ~air_Seat();
};
#endif 