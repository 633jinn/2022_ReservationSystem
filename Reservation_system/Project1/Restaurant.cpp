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
            cout << "������ �ʽ��ϴ�" << endl;
        cout << "**�Ĵ� ���� ���α׷�**" << endl;;
        cout << "<���̵�� ��й�ȣ�� �Է����ּ���>" << endl;
        cout << "===================================" << endl;
        cout << "id:";
        cin >> id;
        cout << "password:";
        cin >> password;
        cout << "===================================" << endl << endl;
        
        if (find_id(f_id, id))
        {
            cout << "<���̵� �������� �ʽ��ϴ�. ȸ�������Ͻðڽ��ϱ�?>" << endl;
            cout << "��:1, �ƴϿ�:2>>";
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
                cout << "<ȸ�������� ���� �����̽��ϴ�. �ʱ� ȭ������ ���ư��ϴ�>" << endl<<endl;
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
            cout << "<��й�ȣ�� �ٸ��ϴ�. �ٽ� �Է����ּ���>" << endl<<endl;
    }
    while (check==1)
    {
        cout << "�Ĵ� ����:1, walk-in ���:2, ������ Ȯ��:3,���:4, ������:5>>";
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
                cout << "<�������� �����ϴ�>" << endl << endl;
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
                cout << "<�������� �����ϴ�>" << endl << endl;
            print_stats(f_id, 2);
            f_id.close();

        }
        else if (menu == 5)
            break;
        else
            cout << "<�߸��� �Է��Դϴ�>" << endl;
    }
}
void Restaurant::prt_menu()
{
    while (1)
    {
        get_menu = 0;
        cout << "����:1, ���:2, ����:3, ������:4>> ";
        cin >> get_menu;
        cout << endl << endl;
        if (get_menu == 4)
        {
            cout << "<�Ĵ� ���� �ý����� �����մϴ�>" << endl;
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
            cout << "<�߸��� �Է��Դϴ�>" << endl;
        }

    }
}
void Restaurant::walk_in_menu()
{
    while (1)
    {
        walkin_menu = 0;
        cout << "walk-in ���:1, walk-in ���:2, ������:3>>";
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
            cout << "<walk-in ��� �ý����� �����մϴ�>" << endl;
            cout << "-----------------------------" << endl << endl;
            return;
        }
        else
        {
            cout << "<�߸��� �Է��Դϴ�>" << endl;
        }

    }
}
void Restaurant::prt_date()
{
    while (1)
    {
        get_date = 0;
        cout << "<���Ͻô� ��¥�� �Է����ּ���>" << endl << "<5�� 1�Ϻ��� 7�� �� ���� �����մϴ�>" << endl;
        cout << "��) 5�� 3��>>\'3\'�Է�>>";
        cin >> get_date;
        cout << endl;
        if (get_date >= 1 && get_date <= 7)
            break;
        else
            cout << "<�߸��� �Է��Դϴ�>" << endl;
    }
}

Restaurant::~Restaurant()
{
    for (int i = 0;i < 8;i++)
        delete time[i];
}