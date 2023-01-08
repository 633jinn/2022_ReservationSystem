#include "res_Time.h"
#include <iostream>
using namespace std;

res_Time::res_Time()
{
    seat = new res_Seat;
}
void res_Time::get_date(int menu, int x)
{
    seat->set_info(get_date_s, id);
    if (x == 0)
    {
        if (menu == 1)
        {
            seat->reserve();
        }
        else if (menu == 2)
        {
            seat->cancel();
        }
        else
        {
            seat->show();
            cout << endl;
        }
    }
    else
    {
        if (menu == 1)
        {
            seat->w_in_reserve();
        }
        else if (menu == 2)
        {
            seat->w_in_cancel();
        }
        else
        {
            seat->w_in_show();
        }
    }
    
}
void res_Time::set_info(string get_date_s,string id)
{
    this->get_date_s = get_date_s;
    this->id = id;
}
res_Time::~res_Time()
{
    delete seat;

}
