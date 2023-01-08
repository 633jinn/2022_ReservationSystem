#include <iostream>
#include "Booking.h"
#include "Airplane.h"
#include "Restaurant.h"
#include "Study.h"
map<string, vector<string>>info[3];//예약기록
map<string, vector<int>>stats[3];//좌석혹은 테이블 통계
map<string, vector<string>>stats_sex;//성별 통계
string ID[3];//아이디
int main()
{
    int get_menu;
    int get_airline;

    cout << "<종합예약시스템이 실행되었습니다>" << endl<<endl;
    while (1) {
        cout << "<원하시는 예약을 선택해주세요>" << endl;
        cout << "1:비행기 예약, 2:식당 예약, 3.독서실 예약, 4.종료>> ";
        cin >> get_menu;
        cout << endl << endl;
        if (get_menu == 1)
        {
            cout << "<원하시는 항공사 서비스를 선택해주세요>" << endl;
            cout << "대한항공:1, 아시아나항공:2, 한성항공:3>>";
            cin >> get_airline;
            Booking* book = new Airplane(get_menu, get_airline);
        }
        else if (get_menu == 2) //식당
        {
            Booking* book=new Restaurant;
        }
        else if (get_menu == 3)//독서실
        {
            Booking* book = new Study;
        }
        else if (get_menu == 4)
        {
            cout << "<예약 시스템을 종료합니다>" << endl;
            cout << "-----------------------------" << endl << endl;
            break;
        }
        else
        {
            cout << "<잘못입력하셨습니다. 다시입력해주세요>" << endl;
        }
    }
    return 0;
}