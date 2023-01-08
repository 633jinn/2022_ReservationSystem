#pragma once
#include <iostream>
#include "stu_Time.h"
using namespace std;
stu_Time::stu_Time()
{
    for (int i = 0;i < 15;i++)
    {
        time[i]=new stu_Seat;
    }
}
void stu_Time::get_date(int menu, int time_s)
{
    this->menu = menu;
    this->get_time = time_s;
    time[get_time]->set_info(get_date_s, get_time_s,id);
    if (menu == 1)
    {
        time[get_time]->reserve();
    }
    else if (menu == 2)
    {
        time[get_time]->cancel();
    }
    else
    {
        time[get_time]->show();
        cout << endl;
    }

}
void stu_Time::set_info(string get_date_s, string get_time_s,string id)
{
    this->get_date_s = get_date_s;
    this->get_time_s = get_time_s;
    this->id = id;
}
stu_Time::~stu_Time()
{
    for (int i = 0;i < 15;i++)
        delete time[i];
}