#include <iostream>
#include <cstring>
#include "Airplane.h"

using namespace std;


Airplane::Airplane(int menu, int airline)
{
    
    for (int i = 0;i < 7;i++)
    {
        time[i] = new air_Time;
    }
    int check = 0;
    while (true)
    {
        f_id.open("Airplane_id.txt", ios::in);
        cout << endl;
        cout << "<아이디와 비밀번호를 입력해주세요>" << endl;
        cout << "===================================" << endl;
        cout << "id:";
        cin >> id;
        cout << "password:";
        cin >> password;
        cout << "===================================" << endl << endl;
        if (find_id(f_id, id))
        {
            cout << "<아이디가 존재하지 않습니다. 회원가입하시겠습니까?>" << endl;
            cout << "예:1, 아니오:2>>";
            int answer = 0;
            cin >> answer;
            cout << endl;
            if (answer == 1)
            {
                f_id.open("Airplane_id.txt", ios::out | ios::app);
                make_id(f_id);
                f_id.close();
            }
            else
            {
                cout << "<회원가입을 하지 않으셨습니다. 초기 화면으로 돌아갑니다>"<<endl << endl;
                break;
            }
                
        }
        else if (password==_password)
        {
            ID[0] = id;
            check = 1;
            break;
        }
        else
            cout << "<비밀번호가 다릅니다. 다시 입력해주세요>" << endl << endl;
    }
    
    if (check == 1)
    {
        if (airline == 1)
        {
            cout << "****대한항공에 오신것을 환영합니다 ****" << endl << endl;
            airplane_s = "[대한항공]";
        }
        else if (airline == 2)
        {
            cout << "****아시아나항공에 오신것을 환영합니다 ****" << endl << endl;
            airplane_s = "[아시아나항공]";
        }
        else
        {
            cout << "****한성항공에 오신것을 환영합니다 ****" << endl << endl;
            airplane_s = "[한성항공]";
        }
        
        this->prt_menu();
    }
    else
        cout << endl;
}
void Airplane::prt_menu()
{
    while (1)
    {
        cout << "**비행기 예약 프로그램**" << endl;
        get_menu = 0;
        cout << "예약:1, 취소:2, 보기:3, 예약기록 확인:4, 통계:5, 끝내기:6>> ";
        cin >> get_menu;
        cout << endl << endl;
        if (get_menu == 6)
        {
            cout << "<비행기 예약 시스템을 종료합니다>" << endl;
            cout << "-----------------------------" << endl << endl;
            return;
        }
        else if (get_menu == 5)
        {
            f_id.open(id + "_info_air.txt", ios::in);
            if (!f_id)
                cout << "<예약기록이 없습니다>" << endl << endl;
            print_stats(f_id, 8);
            f_id.close();
        }
        else if (get_menu == 4)
        {
            f_id.open(id + "_info_air.txt", ios::in);
            if (!f_id)
                cout << "<예약기록이 없습니다>" << endl << endl;
            else
            {
                read_info(f_id);
                f_id.close();
                cout << endl;
            }
        }
        else if (get_menu == 1)
        {
            round_onway();
        }
        else if (get_menu == 2)
        {
            int w = trip_way();
            prt_way(w);
            prt_date();
            prt_time(w);
        }
        else if (get_menu == 3)
        {
            int w = trip_way();
            prt_way(w);
            cout << endl;
            prt_date();
            cout << endl;
            get_time = 0;
            time[get_date - 1]->set_info(to_string(get_date), "", way1, way2, id, airplane_s);
            time[get_date - 1]->get_time(get_menu, get_time, w);
        }
        else
        {
            cout << "<잘못된 입력입니다>" << endl;
        }

    }
}
void Airplane::round_onway()//왕복, 편도
{
    while (true)
    {
        cout << "왕복 : 1, 편도 : 2>>";
        cin >> get_round_onway;
        if (get_round_onway == 1)
        {
            int w = trip_way();

            prt_way(w);
            prt_date();
            prt_time(w);

            prt_way(w+10);
            prt_date();
            prt_time(w+10);
            break;
        }
        else if (get_round_onway == 2)
        {
            int w = trip_way();
            if (w >= 0 && w < 10)
            {

                prt_way(w);
                prt_date();
                prt_time(w);
            }
            break;
        }
        else
            cout << "<잘못된 입력입니다>" << endl;
    }
}
int Airplane::trip_way()//출발, 도착지
{
    cout << endl << "<출발지를 골라주세요>" << endl;
    cout << "1:인천공항, 2:김포공항, 3:김해공항, 4:대구공항, 5:제주공항>>";
    while (1)
    {
        cin >> departure;
        if (departure >= 1 && departure <= 5)
            break;
        else
            cout << "<잘못된 입력입니다>" << endl;
    }
    while (1)
    {
        cout << endl << "<도착지를 선택해주세요>";
        cout << "1:미국, 2:중국>>";
        cin >> destination;
        if (destination == 1 || destination == 2)
            break;
        else
            cout << "<잘못된 입력입니다>" << endl;
    }
    cout << endl;
    int check = 0;
    int way = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (i == departure - 1 && j == destination - 1)
            {
                way = check;
            }
            else
                check++;
        }
    }
    return way;
}
void Airplane::prt_way(int xx)//비행기 행 출력
{
    int count = 0;
    int check = 0;
    if (xx >= 10)
        check = xx - 10;
    else
        check = xx;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (count == check)
            {
                if (i == 0)
                    way1 = "인천공항";
                else if (i == 1)
                    way1 = "김포공항";
                else if (i == 2)
                    way1 = "김해공항";
                else if (i == 3)
                    way1 = "대구공항";
                else if (i == 4)
                    way1 = "제주공항";

                if (j == 0)
                    way2 = "미국";
                else if (j == 1)
                    way2 = "중국";
            }
            count++;
        }
    }
    if (xx >= 10)
    {
        string tmp = way1;
        way1 = way2;
        way2 = tmp;
    }
    cout << "[" << way1 << "ㅡㅡㅡ>" << way2 << "행 비행기 입니다.]" << endl << endl;
}
void Airplane::prt_date()//날짜 예약
{
    get_date = 0;
    while (1)
    {
        cout << "<원하시는 날짜를 입력해주세요>" << endl << "5월 1일부터 7일 중 예약 가능합니다." << endl;
        cout << "예) 5월 3일>>\'3\'입력>>";
        cin >> get_date;
        cout << endl;
        if (get_date == 1 || get_date == 2 || get_date == 3 || get_date == 4 || get_date == 5 || get_date == 6 || get_date == 7)
            break;
        else
            cout << "<잘못된 입력입니다>" << endl;
    }

}
void Airplane::prt_time(int xx)//시간예약
{
    get_time = 0;
    while (1)
    {
        cout << "<원하시는 시간을 입력해주세요>" << endl;
        cout << "07시:1, 12시:2, 17시:3>> ";
        cin >> get_time;
        cout << endl;
        if (get_time == 1 || get_time == 2 || get_time == 3)
        {
            break;
        }
        else
            cout << "<잘못된 입력입니다>" << endl;
    }
    set_info(xx);
    time[get_date - 1]->get_time(get_menu, get_time, xx);

}
void Airplane::set_info(int xx)
{
    string get_time_s;
    if (get_time == 1)
        get_time_s = "07시";
    else if (get_time == 2)
        get_time_s = "12시";
    else if (get_time == 3)
        get_time_s = "17시";
    if (xx >= 10)
    {
        time[get_date - 1]->set_info(to_string(get_date), get_time_s, way2, way1, id, airplane_s);
    }
    else
    {
        time[get_date - 1]->set_info(to_string(get_date), get_time_s, way1, way2, id, airplane_s);
    }
}

Airplane::~Airplane()
{
    for (int i = 0;i < 7;i++)
    {
        delete time[i];
    }
}