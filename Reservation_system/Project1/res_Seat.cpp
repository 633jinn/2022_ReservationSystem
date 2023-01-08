#include "res_Seat.h"
#include <iostream>

using namespace std;

res_Seat::res_Seat()
{
    for (int i = 0; i < 3; i++)
    {
        seat_2[i] = new char[20];
        strcpy(seat_2[i], "___");
        seat_4[i] = new char[20];
        strcpy(seat_4[i], "___");
    }
}
void res_Seat::reserve()
{
    cout << "예약자 분의 나이를 입력해주세요>>";
    cin >> age;
    cout << endl;
    if (age <= 7)
    {
        cout << "<미취학 아동은 예약이 불가능합니다>" << endl << endl;
        return;
    }
    cout << "예약자명을 입력해주세요>>";
    cin >> get_name;
    cout << endl;
    while (1)
    {
        cout << "총 인원을 입력해주세요, 최대 예약 가능 인원 4명(0입력시 종료)>>";
        cin >> total_p;
        cout << endl;
        if (total_p == 0)
        {
            cout << "<시스템이 종료됩니다>" << endl;
            return;
        }
        else if (total_p > 4)
            cout << "<예약 가능 인원은 최대 4명입니다>" << endl;
        else if (total_p > total_rs)
            cout << "<총 인원이 남은 예약좌석보다 많습니다>" << endl;
        else
            break;
    }
    if (get_total_p_rs(total_p, get_name))
    {
        cout << "<좌석이 부족하여 예약을 할 수 없습니다>" << endl;
        return;
    }
    cout << endl;
}

void res_Seat::cancel()
{
    show();
    int check = 0;
    while (1)
    {
        cout << "이름입력>>(exit입력시 종료)";
        cin >> get_name;
        cout << endl;
        if (!strcmp("exit", get_name))
            break;
        for (int i = 0; i < 3; i++)
        {
            if (!strcmp(seat_4[i], get_name))
            {
                cout << "<예약이 취소되었습니다>" << endl;
                strcpy(seat_4[i], "___");
                check = 1;
                erase_file(f_id);
                for (int size = 0; size < info[1][ID[1]].size(); size++)
                {

                    if (info[1][ID[1]][size] == "[5월 " + get_date_s + "일][식당 예약] : " + get_name + (string)"[4인 좌석]")
                    {
                        stats[1][ID[1]].erase(remove(stats[1][ID[1]].begin(), stats[1][ID[1]].end(), stats[1][ID[1]][size]), stats[1][ID[1]].end());
                    }

                }
                total_rs += 4;
                return;
            }
            else if (!strcmp(seat_2[i], get_name))
            {
                cout << "<예약이 취소되었습니다>" << endl;
                strcpy(seat_2[i], "___");
                check = 1;
                erase_file(f_id);
                for (int size = 0; size < info[1][ID[1]].size(); size++)
                {

                    if (info[1][ID[1]][size] == "[5월 " + get_date_s + "일][식당 예약] : " + get_name + (string)"[2인 좌석]")
                    {

                        stats[1][ID[1]].erase(remove(stats[1][ID[1]].begin(), stats[1][ID[1]].end(), stats[1][ID[1]][size]), stats[1][ID[1]].end());
                    }

                }
                total_rs += 2;
                return;
            }
        }
        if (check == 0)
        {
            cout << "<예약되어있지 않거나, 예약되어 있는 이름과 다릅니다. 다시 입력해주세요>" << endl;
        };
    }
}
void res_Seat::show()
{
    cout << "예약자 명단 : ";
    for (int i = 0; i < 3; i++)
    {
        if (!strcmp(seat_2[i], get_name))
        {
            cout << seat_2[i];
            cout << "     ";
        }
        if (!strcmp(seat_4[i], get_name))
        {
            cout << seat_4[i];
            cout << "     ";
        }

    }
    cout << endl;
}
bool res_Seat::get_total_p_rs(int tp, char* name)
{
    int size = info[1][ID[1]].size();
    int check = 0;
    if (tp == 3 || tp == 4)
    {
        for (int i = 0; i < 3; i++)
        {
            if (!strcmp(seat_4[i], "___"))
            {
                strcpy(seat_4[i], get_name);
                total_rs -= 4;
                check = 1;
                f_id.open(id + "_info_res.txt", ios::out | ios::app);
                if (!f_id)
                    cout << "열리지 않습니다" << endl;
                f_id << "[5월 " + get_date_s + "일][식당 예약] : " + get_name + (string)"[4인 좌석]" << endl;
                f_id.close();
                stats[1][ID[1]].push_back(4);
                break;
            }
        }

    }
    else if (tp == 1 || tp == 2)
    {
        for (int j = 0; j < 3; j++)
        {
            if (!strcmp(seat_2[j], "___"))
            {
                strcpy(seat_2[j], get_name);
                total_rs -= 2;
                check = 1;
                f_id.open(id + "_info_res.txt", ios::out | ios::app);
                if (!f_id)
                    cout << "열리지 않습니다" << endl;
                f_id << "[5월 " + get_date_s + "일][식당 예약] : " + get_name + (string)"[2인 좌석]" << endl;
                f_id.close();
                stats[1][ID[1]].push_back(2);
                break;
            }
            else if (!strcmp(seat_4[j], "___"))
            {
                strcpy(seat_4[j], get_name);
                total_rs -= 4;
                check = 1;
                f_id.open(id + "_info_res.txt", ios::out | ios::app);
                if (!f_id)
                    cout << "열리지 않습니다" << endl;
                f_id << "[5월 " + get_date_s + "일][식당 예약] : " + get_name + (string)"[4인 좌석]" << endl;
                f_id.close();
                stats[1][ID[1]].push_back(4);
                break;
            }
        }


    }
    if (check == 0)
        return true;
    else
        return false;
}
void res_Seat::w_in_reserve()
{
    int size = info[1][ID[1]].size();
    while (1)
    {
        cout << "총 인원을 입력해주세요, 최대 대기 가능 인원 4명(0입력시 종료)>>";
        cin >> total_p;
        cout << endl;
        if (total_p == 0)
        {
            cout << "<시스템이 종료됩니다>" << endl;
            return;
        }
        else if (total_p > 4)
            cout << "<대기 가능 인원은 최대 4명입니다>" << endl;
        else
            break;
    }
    cout << "대기자명을 입력해주세요>>";
    cin >> str_get_name;
    cout << endl;
    if (total_p == 1 || total_p == 2)
    {
        
        if (seat_2_w.size() < 4)
        {
            cout << "<대기없이 입장 가능합니다!>" << endl;
            seat_2_w.push_back(str_get_name);
            f_id.open(id + "_info_res.txt", ios::out | ios::app);
            if (!f_id)
                cout << "열리지 않습니다" << endl;
            f_id << "[walk-in] : " + str_get_name + (string)"[2인 좌석]" << endl;
            f_id.close();
            stats[1][ID[1]].push_back(2);
        }
        else if (seat_4_w.size() < 4)
        {
            cout << "<대기없이 입장 가능합니다!>" << endl;
            seat_4_w.push_back(str_get_name);
            f_id.open(id + "_info_res.txt", ios::out | ios::app);
            if (!f_id)
                cout << "열리지 않습니다" << endl;
            f_id << "[walk-in] : " + str_get_name + (string)"[4인 좌석]" << endl;
            f_id.close();
            stats[1][ID[1]].push_back(4);
        }
        else
        {
            seat_2_w.push_back(str_get_name);
            cout << "대기 번호 " << seat_2_w.size() - 4 << "입니다" << endl;
            f_id.open(id + "_info_res.txt", ios::out | ios::app);
            if (!f_id)
                cout << "열리지 않습니다" << endl;
            f_id << "[walk-in] : " + str_get_name + (string)"[2인 좌석]" << endl;
            f_id.close();
            stats[1][ID[1]].push_back(2);
        }
    }
    else if (total_p == 3 || total_p == 4)
    {
        if (seat_4_w.size() < 4)
        {
            cout << "<대기없이 입장 가능합니다!>" << endl;
            seat_4_w.push_back(str_get_name);
            f_id.open(id + "_info_res.txt", ios::out | ios::app);
            if (!f_id)
                cout << "열리지 않습니다" << endl;
            f_id << "[walk-in] : " + str_get_name + (string)"[4인 좌석]" << endl;
            f_id.close();
            stats[1][ID[1]].push_back(4);
        }
        else
        {
            seat_4_w.push_back(str_get_name);
            cout << "<대기 번호 " << seat_4_w.size() - 4 << "입니다>" << endl;
            f_id.open(id + "_info_res.txt", ios::out | ios::app);
            if (!f_id)
                cout << "열리지 않습니다" << endl;
            f_id << "[walk-in] : " + str_get_name + (string)"[4인 좌석]" << endl;
            f_id.close();
            stats[1][ID[1]].push_back(4);
        }
    }
}
void res_Seat::w_in_cancel()
{
    while (1)
    {
        cout << "이름입력>>(exit입력시 종료)";
        cin >> get_name;
        cout << endl;
        if (!strcmp("exit", get_name))
            return;
        int check = -1;
        for (int i = 0; i < seat_2_w.size(); i++)
        {
            if (seat_2_w[i] == get_name)
                check = i;
        }
        for (int size = 0; size < info[1][ID[1]].size(); size++)
        {
            if (info[1][ID[1]][size] == "[5월 " + get_date_s + "일][식당 예약] : " + get_name + (string)"[4인 좌석]" && check >= 4)
            {
                stats[1][ID[1]].erase(remove(stats[1][ID[1]].begin(), stats[1][ID[1]].end(), stats[1][ID[1]][size]), stats[1][ID[1]].end());
            }
            else if (info[1][ID[1]][size] == "[5월 " + get_date_s + "일][식당 예약] : " + get_name + (string)"[2인 좌석]" && check >= 4)
            {
                stats[1][ID[1]].erase(remove(stats[1][ID[1]].begin(), stats[1][ID[1]].end(), stats[1][ID[1]][size]), stats[1][ID[1]].end());
            }
        }
        
        for (it = seat_2_w.begin(); it != seat_2_w.end(); it++)
        {
            if (*it == get_name)
            {
                cout << "<취소되었습니다>" << endl;
                seat_2_w.erase(it);
                erase_file(f_id);
                return;
            }
        }
        for (it = seat_4_w.begin(); it != seat_4_w.end(); it++)
        {
            if (*it == get_name)
            {
                cout << "<취소되었습니다>" << endl;
                seat_4_w.erase(it);
                erase_file(f_id);
                return;
            }
        }
        cout << "<예약되어있지 않거나, 예약되어 있는 이름과 다릅니다. 다시 입력해주세요>" << endl;
    }
}
void res_Seat::w_in_show()
{
    cout << "2인용 좌석 대기자 명단 : ";
    for (int i = 4; i < seat_2_w.size(); i++)
        cout << seat_2_w.at(i);
    cout << "4인용 좌석 대기자 명단 : ";
    for (int i = 4; i < seat_4_w.size(); i++)
        cout << seat_4_w.at(i);
}
void res_Seat::erase_file(fstream& f_id)
{
    string line;
    f_id.open(id + "_info_res.txt", ios::in);
    help_info.open("help.txt", ios::out);
    while (getline(f_id, line))
    {
        if (line != ("[5월 " + get_date_s + "일][식당 예약] : " + get_name + (string)"[2인 좌석]") && line != ("[5월 " + get_date_s + "일][식당 예약] : " + get_name + (string)"[4인 좌석]")
            && line != ("[walk-in] : " + str_get_name + (string)"[2인 좌석]") && line != ("[walk-in] : " + str_get_name + (string)"[4인 좌석]"))
            help_info << line << endl;
    }
    f_id.close();
    help_info.close();

    f_id.open(id + "_info_res.txt", ios::out);
    help_info.open("help.txt", ios::in);
    while (getline(help_info, line))
    {
        f_id << line << endl;
    }
    f_id.close();
    help_info.close();
    cout << "<예약이 취소되었습니다>" << endl;
}
void res_Seat::set_info(string get_date_s, string id)
{
    this->get_date_s = get_date_s;
    this->id = id;
}
res_Seat::~res_Seat()
{
    for (int i = 0; i < seat_2_w.size(); i++)
    {
       // delete []seat_2_w[i];
        //delete []seat_4_w;
    }
}