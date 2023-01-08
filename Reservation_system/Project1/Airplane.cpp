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
                f_id.open("Airplane_id.txt", ios::out | ios::app);
                make_id(f_id);
                f_id.close();
            }
            else
            {
                cout << "<ȸ�������� ���� �����̽��ϴ�. �ʱ� ȭ������ ���ư��ϴ�>"<<endl << endl;
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
            cout << "<��й�ȣ�� �ٸ��ϴ�. �ٽ� �Է����ּ���>" << endl << endl;
    }
    
    if (check == 1)
    {
        if (airline == 1)
        {
            cout << "****�����װ��� ���Ű��� ȯ���մϴ� ****" << endl << endl;
            airplane_s = "[�����װ�]";
        }
        else if (airline == 2)
        {
            cout << "****�ƽþƳ��װ��� ���Ű��� ȯ���մϴ� ****" << endl << endl;
            airplane_s = "[�ƽþƳ��װ�]";
        }
        else
        {
            cout << "****�Ѽ��װ��� ���Ű��� ȯ���մϴ� ****" << endl << endl;
            airplane_s = "[�Ѽ��װ�]";
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
        cout << "**����� ���� ���α׷�**" << endl;
        get_menu = 0;
        cout << "����:1, ���:2, ����:3, ������ Ȯ��:4, ���:5, ������:6>> ";
        cin >> get_menu;
        cout << endl << endl;
        if (get_menu == 6)
        {
            cout << "<����� ���� �ý����� �����մϴ�>" << endl;
            cout << "-----------------------------" << endl << endl;
            return;
        }
        else if (get_menu == 5)
        {
            f_id.open(id + "_info_air.txt", ios::in);
            if (!f_id)
                cout << "<�������� �����ϴ�>" << endl << endl;
            print_stats(f_id, 8);
            f_id.close();
        }
        else if (get_menu == 4)
        {
            f_id.open(id + "_info_air.txt", ios::in);
            if (!f_id)
                cout << "<�������� �����ϴ�>" << endl << endl;
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
            cout << "<�߸��� �Է��Դϴ�>" << endl;
        }

    }
}
void Airplane::round_onway()//�պ�, ��
{
    while (true)
    {
        cout << "�պ� : 1, �� : 2>>";
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
            cout << "<�߸��� �Է��Դϴ�>" << endl;
    }
}
int Airplane::trip_way()//���, ������
{
    cout << endl << "<������� ����ּ���>" << endl;
    cout << "1:��õ����, 2:��������, 3:���ذ���, 4:�뱸����, 5:���ְ���>>";
    while (1)
    {
        cin >> departure;
        if (departure >= 1 && departure <= 5)
            break;
        else
            cout << "<�߸��� �Է��Դϴ�>" << endl;
    }
    while (1)
    {
        cout << endl << "<�������� �������ּ���>";
        cout << "1:�̱�, 2:�߱�>>";
        cin >> destination;
        if (destination == 1 || destination == 2)
            break;
        else
            cout << "<�߸��� �Է��Դϴ�>" << endl;
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
void Airplane::prt_way(int xx)//����� �� ���
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
                    way1 = "��õ����";
                else if (i == 1)
                    way1 = "��������";
                else if (i == 2)
                    way1 = "���ذ���";
                else if (i == 3)
                    way1 = "�뱸����";
                else if (i == 4)
                    way1 = "���ְ���";

                if (j == 0)
                    way2 = "�̱�";
                else if (j == 1)
                    way2 = "�߱�";
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
    cout << "[" << way1 << "�ѤѤ�>" << way2 << "�� ����� �Դϴ�.]" << endl << endl;
}
void Airplane::prt_date()//��¥ ����
{
    get_date = 0;
    while (1)
    {
        cout << "<���Ͻô� ��¥�� �Է����ּ���>" << endl << "5�� 1�Ϻ��� 7�� �� ���� �����մϴ�." << endl;
        cout << "��) 5�� 3��>>\'3\'�Է�>>";
        cin >> get_date;
        cout << endl;
        if (get_date == 1 || get_date == 2 || get_date == 3 || get_date == 4 || get_date == 5 || get_date == 6 || get_date == 7)
            break;
        else
            cout << "<�߸��� �Է��Դϴ�>" << endl;
    }

}
void Airplane::prt_time(int xx)//�ð�����
{
    get_time = 0;
    while (1)
    {
        cout << "<���Ͻô� �ð��� �Է����ּ���>" << endl;
        cout << "07��:1, 12��:2, 17��:3>> ";
        cin >> get_time;
        cout << endl;
        if (get_time == 1 || get_time == 2 || get_time == 3)
        {
            break;
        }
        else
            cout << "<�߸��� �Է��Դϴ�>" << endl;
    }
    set_info(xx);
    time[get_date - 1]->get_time(get_menu, get_time, xx);

}
void Airplane::set_info(int xx)
{
    string get_time_s;
    if (get_time == 1)
        get_time_s = "07��";
    else if (get_time == 2)
        get_time_s = "12��";
    else if (get_time == 3)
        get_time_s = "17��";
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