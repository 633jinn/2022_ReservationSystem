#pragma once
#ifndef AIRPLANE__H
#define AIRPLANE__H
#include "Booking.h"
#include <string>
#include <vector>
#include <fstream>
using namespace std;
extern map<string, vector<string>>info[3];
extern map<string, vector<int>>stats[3];
extern string ID[3];
class Airplane :public Booking
{
    string way1, way2;
    Time* time[7];
    int get_round_onway=0;
    int departure=0;
    int destination=0;
    int way = 0;
    string airplane_s;
public:
    Airplane(int menu, int airline);
    void prt_way(int xx);
    void round_onway();
    void prt_menu();
    void prt_date();
    void prt_time(int w);
    int trip_way();
    void set_info(int xx);
    void check_info(fstream& f_id);//예약자명을 제외한 정보가 같은지 확인
    ~Airplane();
    
};
#endif