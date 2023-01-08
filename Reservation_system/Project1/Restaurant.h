#include "Booking.h"
#include "res_Time.h"
#include <iostream>
using namespace std;
extern map<string, vector<string>>info[3];
extern map<string, vector<int>>stats[3];
extern string ID[3];
class Restaurant :public Booking
{
    int menu;
    Time* time[8];
public:
    Restaurant();
    void prt_menu();
    void prt_date();
    void walk_in_menu();
    ~Restaurant();
};
