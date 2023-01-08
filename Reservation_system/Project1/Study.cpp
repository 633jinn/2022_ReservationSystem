#pragma once
#include "Study.h"
Study::Study()
{
    for (int i = 0;i < 7;i++)
        time[i] = new stu_Time;
    int check = 0;
    while (true)
    {
        f_id.open("Study_id.txt", ios::in);
        if (!f_id)
            cout << "열리지 않습니다" << endl;
        cout << "**독서실 예약 프로그램**" << endl;
        cout << "<아이디와 비밀번호를 입력해주세요>" << endl;
        cout << "===================================" << endl;
        cout << "id:";
        cin >> id;
        cout << "password:";
        cin >> password;
        cout << "===================================" << endl<<endl;
        if (find_id(f_id, id))
        {
            cout << "<아이디가 존재하지 않습니다. 회원가입하시겠습니까?>" << endl;
            cout << "예:1, 아니오:2>>";
            int answer = 0;
            cin >> answer;
            cout << endl;
            if (answer == 1)
            {
                f_id.open("Study_id.txt", ios::out | ios::app);
                make_id(f_id);
                f_id.close();
            }
            else
            {
                cout << "<회원가입을 하지 않으셨습니다. 초기 화면으로 돌아갑니다>" << endl << endl;
                break;
            }
        }
        else if (password == _password)
        {
            ID[2] = id;
            check = 1;
            break;
        }
        else
            cout << "<비밀번호가 다릅니다. 다시 입력해주세요>" << endl << endl;
    }
    if(check==1)
        this->prt_menu();
}
void Study::prt_menu()
{
    while (1)
    {
        get_menu = 0;
        cout << "예약:1, 취소:2, 보기:3, 예약기록 확인:4, 통계:5, 끝내기:6>> ";
        cin >> get_menu;
        cout << endl << endl;
        if (get_menu == 6)
        {
            cout << "<식당 예약 시스템을 종료합니다>" << endl;
            cout << "-----------------------------" << endl << endl;
            return;
        }
        else if (get_menu == 5)
        {
            f_id.open(id + "_info_stu.txt", ios::in);
            if (!f_id)
                cout << "<예약기록이 없습니다>" << endl << endl;
            else 
            {
                print_stats(f_id, 225);
                f_id.close();
                f_id.open(id + "_info_stu.txt", ios::in);
                print_stats_sex(f_id);
                f_id.close();
            }
        }
        else if (get_menu == 4)
        {
            f_id.open(id + "_info_stu.txt", ios::in);
            if (!f_id)
                cout << "<예약기록이 없습니다>" << endl << endl;
            else
            {
                read_info(f_id);
                f_id.close();
                cout << endl;
            }
        }
        else if (get_menu == 1 || get_menu == 2 || get_menu == 3)
        {
            prt_date();
            prt_time();
        }
        else
        {
            cout << "<잘못된 입력입니다>" << endl;
        }

    }
}
void Study::prt_date()
{
    while (1)
    {
        get_date = 0;
        cout << "<원하시는 날짜를 입력해주세요>" << endl << "<5월 1일부터 7일 중 예약 가능합니다>" << endl;
        cout << "예) 5월 3일>>\'3\'입력>>";
        cin >> get_date;
        cout << endl;
        if (get_date >= 1 && get_date <= 7)
            break;
        else
            cout << "<잘못된 입력입니다>" << endl;
    }
}
void Study::prt_time()//시간예약
{
    get_time = 0;
    while (1)
    {
        cout << "<09시~24시까지 운행합니다. 예약은 1시간 단위로 가능합니다>" << endl << "원하시는 시간대를 입력해주세요.(9시~23시 사이 선택가능) 예)09시>>\'9\'입력>>";
        cin >> get_time;
        cout << endl;
        if (get_time >= 9 && get_time <= 23)
        {
            break;
        }
        else
            cout << "<잘못된 입력입니다>" << endl;
    }
    if (get_menu == 1)
        info[2][ID[2]].push_back("[5월 " + to_string(get_date) + "일]");
    time[get_date - 1]->set_info(to_string(get_date), to_string(get_time),id);
    time[get_date - 1]->get_date(get_menu, get_time-9);

}
void Study::print_stats_sex(fstream& f_id)
{
    cout << "<" << id << "님의 성별 별 예약 횟수를 출력합니다>" << endl << endl;
    string line="\0";
    string first_c = "\0", second_c = "\0";//"좌석"을 찾는다.
    string add_c = "\0";
    string check_c;
    string tmp;
    int check = 0;
    int total[2] = {0,0};
    while (getline(f_id, line))
    {
        first_c = "\0", second_c = "\0", add_c = "\0";
        for (int i = 0; i < line.size(); i++)
        {
            
            if (first_c == "(")
            {
                second_c = line[i];
                if (second_c == ")")
                {
                    if (add_c == "남")
                        total[0] += 1;
                    else
                        total[1] += 1;
                    break;
                }
                else 
                    add_c += line[i];
            }
            else
                first_c = line[i];
        }
    }
    cout << "남자 : " << total[0] << "회" << endl;
    cout << "여자 : " << total[1] << "회" << endl << endl;
}
Study::~Study()
{
    for(int i=0;i<7;i++)
        delete time[i];
}