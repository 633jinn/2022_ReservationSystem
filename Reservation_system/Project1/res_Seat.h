#pragma once
#include "Seat.h"
#include <string>
#include <vector>
extern map<string, vector<string>>info[3];
extern map<string, vector<int>>stats[3];
extern string ID[3];
using namespace std;
class res_Seat :public Seat
{

    vector<string> seat_2_w;//walk-in ÁÂ¼®
    vector<string> seat_4_w;
    vector<string>::iterator it;
    string str_get_name;
    string get_date_s;
    char* seat_2[3];//¿¹¾à ÁÂ¼®
    char* seat_4[3];
    int total_p=0;//ÃÑÀÎ¿ø
    int total_rs=16;//ÃÑ¿¹¾àÁÂ¼®
    int age = 0;
public:
    res_Seat();
    bool get_total_p_rs(int tp, char* name);
    void reserve();
    void cancel() ;
    void show() ;
    void w_in_reserve();
    void w_in_cancel();
    void w_in_show();
    void set_info(string get_date_s,string id);
    void erase_file(fstream& f_id);
    virtual ~res_Seat();
};