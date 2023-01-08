#pragma once
#ifndef STU_SEAT__H
#define STU_SEAT__H
#include "Seat.h"
extern map<string, vector<string>>info[3];
extern map<string, vector<int>>stats[3];
extern map<string, vector<string>>stats_sex;
extern string ID[3];
class stu_Seat :public Seat
{
    int age=0;
    string seat[15][15] ;
    int sex[15][15] = { 0 };
    string Id;
    int get_sex;
    string get_date_s;
    string get_time_s;
public:
    stu_Seat();
    void reserve();
    bool check_sex(int row, int column,int sex);
    void cancel();
    void show();
    void set_info(string get_date, string get_time,string id);
    void erase_file(fstream& f_id);
    void save_file(fstream& f_id);
    void open_file(fstream& f_id);
    int get_count(fstream& f_id, int x);
};
#endif // !STU_SEAT__H
