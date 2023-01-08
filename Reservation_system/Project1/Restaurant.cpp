#include "Restaurant.h"

Restaurant::Restaurant() 
{
    for (int i = 0;i < 8;i++)
        time[i] = new res_Time;
    int check = 0;
    while (true)
    {
        f_id.open("Restaurant_id.txt", ios::in);
        if (!f_id)
            cout << "열리지 않습니다" << endl;
        cout << "**식당 예약 프로그램**" << endl;;
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
                f_id.open("Restaurant_id.txt", ios::out | ios::app);
                make_id(f_id);
                f_id.close();
            }
            else
            {
                cout << "<회원가입을 하지 않으셨습니다. 초기 화면으로 돌아갑니다>" << endl<<endl;
                break;
            }
        }
        else if (password == _password)
        {
            ID[0] = id;
            check = 1;
            break;
        }
        else
            cout << "<비밀번호가 다릅니다. 다시 입력해주세요>" << endl<<endl;
    }
    while (check==1)
    {
        cout << "식당 예약:1, walk-in 대기:2, 예약기록 확인:3,통계:4, 끝내기:5>>";
        cin >> menu;
        cout << endl << endl;
        if (menu == 1)
        {
            prt_menu();
        }
        else if (menu == 2)
        {
            walk_in_menu();
        }
        else if (menu == 3)
        {
            f_id.open(id + "_info_res.txt", ios::in);
            if (!f_id)
                cout << "<예약기록이 없습니다>" << endl << endl;
            else
            {
                read_info(f_id);
                f_id.close();
                cout << endl;
            }
        }
        else if (menu == 4)
        {
            f_id.open(id + "_info_res.txt", ios::in);
            if (!f_id)
                cout << "<예약기록이 없습니다>" << endl << endl;
            print_stats(f_id, 2);
            f_id.close();

        }
        else if (menu == 5)
            break;
        else
            cout << "<잘못된 입력입니다>" << endl;
    }
}
void Restaurant::prt_menu()
{
    while (1)
    {
        get_menu = 0;
        cout << "예약:1, 취소:2, 보기:3, 끝내기:4>> ";
        cin >> get_menu;
        cout << endl << endl;
        if (get_menu == 4)
        {
            cout << "<식당 예약 시스템을 종료합니다>" << endl;
            cout << "-----------------------------" << endl << endl;
            return;
        }
        else if (get_menu == 1|| get_menu == 2|| get_menu == 3)
        {
            prt_date();
            time[this->get_date - 1]->set_info(to_string(get_date), id);
            time[this->get_date - 1]->get_date(get_menu,0);
            break;
        }
        else
        {
            cout << "<잘못된 입력입니다>" << endl;
        }

    }
}
void Restaurant::walk_in_menu()
{
    while (1)
    {
        walkin_menu = 0;
        cout << "walk-in 대기:1, walk-in 취소:2, 끝내기:3>>";
        cin >> walkin_menu;
        cout << endl;
        if (walkin_menu == 1 || walkin_menu == 2)
        {
            time[7]->set_info(to_string(get_date), id);
            time[7]->get_date(walkin_menu, 1);
            break;
        }
        else if (walkin_menu == 3)
        {
            cout << "<walk-in 대기 시스템을 종료합니다>" << endl;
            cout << "-----------------------------" << endl << endl;
            return;
        }
        else
        {
            cout << "<잘못된 입력입니다>" << endl;
        }

    }
}
void Restaurant::prt_date()
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

Restaurant::~Restaurant()
{
    for (int i = 0;i < 8;i++)
        delete time[i];
}