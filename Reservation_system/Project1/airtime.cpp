#include <iostream>
#include "air_Time.h"

using namespace std;
void air_Time::setting_air_Time()
{
    for (int i = 0;i < 20;i++)
    {
        time_07[i]->get_timeseat("07시");
        time_12[i]->get_timeseat("12시");
        time_17[i]->get_timeseat("17시");

        time_07[i]->set_info(get_date_s, get_time_s, way1, way2, id, airplane);
        time_12[i]->set_info(get_date_s, get_time_s, way1, way2, id, airplane);
        time_17[i]->set_info(get_date_s, get_time_s, way1, way2, id, airplane);
    }
}
air_Time::air_Time()
{
    this->id = id;
    for (int i = 0;i < 20;i++)
    {
        time_07[i] = new air_Seat;
        time_12[i] = new air_Seat;
        time_17[i] = new air_Seat;
    }
}

void air_Time::get_time(int menu, int time, int way)
{
    setting_air_Time();
    if (menu == 1)
    {
        if (time == 1)
        {
            time_07[way]->reserve(way);
        }
        else if (time == 2)
        {
            time_12[way]->reserve(way);
        }
        else
        {
            time_17[way]->reserve(way);
        }
    }
    else if (menu == 2)
    {
        if (time == 1)
        {
            time_07[way]->cancel(way);
        }
        else if (time == 2)
        {
            time_12[way]->cancel(way);
        }
        else
        {
            time_17[way]->cancel(way);
        }
    }
    else
    {
        time_07[way]->set_info(get_date_s, "07시", way1, way2, id, airplane);
        time_07[way]->show();
        time_12[way]->set_info(get_date_s, "12시", way1, way2, id, airplane);
        time_12[way]->show();
        time_17[way]->set_info(get_date_s, "17시", way1, way2, id, airplane);
        time_17[way]->show();
        cout << endl;
    }
}

void air_Time::set_info(string get_date, string get_time, string way1, string way2,string id, string airplane)
{
    this->get_date_s = get_date;
    this->get_time_s = get_time;
    this->way1 = way1;
    this->way2 = way2;
    this->id = id;
    this->airplane = airplane;
}
air_Time::~air_Time()
{
    for (int i = 0;i < 20;i++)
    {

        delete time_07[i];
        delete time_12[i];
        delete time_17[i];
    }
    
}
