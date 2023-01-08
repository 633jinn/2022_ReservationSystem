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
            cout << "������ �ʽ��ϴ�" << endl;
        cout << "**������ ���� ���α׷�**" << endl;
        cout << "<���̵�� ��й�ȣ�� �Է����ּ���>" << endl;
        cout << "===================================" << endl;
        cout << "id:";
        cin >> id;
        cout << "password:";
        cin >> password;
        cout << "===================================" << endl<<endl;
        if (find_id(f_id, id))
        {
            cout << "<���̵� �������� �ʽ��ϴ�. ȸ�������Ͻðڽ��ϱ�?>" << endl;
            cout << "��:1, �ƴϿ�:2>>";
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
                cout << "<ȸ�������� ���� �����̽��ϴ�. �ʱ� ȭ������ ���ư��ϴ�>" << endl << endl;
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
            cout << "<��й�ȣ�� �ٸ��ϴ�. �ٽ� �Է����ּ���>" << endl << endl;
    }
    if(check==1)
        this->prt_menu();
}
void Study::prt_menu()
{
    while (1)
    {
        get_menu = 0;
        cout << "����:1, ���:2, ����:3, ������ Ȯ��:4, ���:5, ������:6>> ";
        cin >> get_menu;
        cout << endl << endl;
        if (get_menu == 6)
        {
            cout << "<�Ĵ� ���� �ý����� �����մϴ�>" << endl;
            cout << "-----------------------------" << endl << endl;
            return;
        }
        else if (get_menu == 5)
        {
            f_id.open(id + "_info_stu.txt", ios::in);
            if (!f_id)
                cout << "<�������� �����ϴ�>" << endl << endl;
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
                cout << "<�������� �����ϴ�>" << endl << endl;
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
            cout << "<�߸��� �Է��Դϴ�>" << endl;
        }

    }
}
void Study::prt_date()
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
void Study::prt_time()//�ð�����
{
    get_time = 0;
    while (1)
    {
        cout << "<09��~24�ñ��� �����մϴ�. ������ 1�ð� ������ �����մϴ�>" << endl << "���Ͻô� �ð��븦 �Է����ּ���.(9��~23�� ���� ���ð���) ��)09��>>\'9\'�Է�>>";
        cin >> get_time;
        cout << endl;
        if (get_time >= 9 && get_time <= 23)
        {
            break;
        }
        else
            cout << "<�߸��� �Է��Դϴ�>" << endl;
    }
    if (get_menu == 1)
        info[2][ID[2]].push_back("[5�� " + to_string(get_date) + "��]");
    time[get_date - 1]->set_info(to_string(get_date), to_string(get_time),id);
    time[get_date - 1]->get_date(get_menu, get_time-9);

}
void Study::print_stats_sex(fstream& f_id)
{
    cout << "<" << id << "���� ���� �� ���� Ƚ���� ����մϴ�>" << endl << endl;
    string line="\0";
    string first_c = "\0", second_c = "\0";//"�¼�"�� ã�´�.
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
                    if (add_c == "��")
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
    cout << "���� : " << total[0] << "ȸ" << endl;
    cout << "���� : " << total[1] << "ȸ" << endl << endl;
}
Study::~Study()
{
    for(int i=0;i<7;i++)
        delete time[i];
}