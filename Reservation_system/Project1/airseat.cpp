#include <iostream>
#include "air_Seat.h"
using namespace std;
air_Seat::air_Seat()
{
    for (int i = 0;i < 8;i++)
    {
        name[i] = new char[20];
        strcpy(name[i], "___");
    }
}
void air_Seat::get_timeseat(const char* x)
{
    if (x != NULL) 
    {
        strcpy(time, x);
    }
    
}

void air_Seat::reserve(int way)
{
    show();
    cout << "<���� ������ �Է����ּ���>"<<endl<<"��)10000�� >> \'10000\'�Է�";
    int money;
    cin >> money;
    if (money < 80000)
    {
        cout << "<���� ������ �¼��� �����ϴ�>"<<endl;
        return;
    }
    else
        available_seat(money);
   
    while (1)
    {
        cout << "<1~3�� �¼�:����Ͻ�, 4~8�� �¼�:���ڳ�� �¼��Դϴ�>"<<endl;
        cout << "�¼���ȣ(0�Է½� ����)>>";
        cin >> seat_num;
        cout << endl;
        if (seat_num == 0)
        {
            cout << "<0�� �ԷµǾ����ϴ�. ������ ����˴ϴ�>" << endl << endl;
            return;
        }
        else if (!(seat_num >= 1 && seat_num <= 8))
        {
            cout << "<���� �¼��Դϴ�. �ٽ� �������ּ���>" << endl << endl;
            continue;
        }
        if (strcmp(name[seat_num - 1], "___"))
            cout << "<�̹� ����� �¼��Դϴ�. �ٽ� �Է����ּ���>" << endl << endl;
        else if (seat_num < 3) {
            cout << "<����Ͻ����Դϴ�. ������ 100000�Դϴ�>" << endl << endl;
            break;
        }
        else
        {
            cout << "<���ڳ���¼��Դϴ�. ������ 80000�Դϴ�>" << endl << endl;
            break;
        }

    }
    cout << "�̸��Է�>>";
    cin >> get_name;
    strcpy(name[seat_num - 1], get_name);

    cout << endl << endl;
    f_id.open(id + "_info_air.txt", ios::out | ios::app);
    f_id << airplane + "[5�� " + get_date_s + "��][" + get_time_s + "][" + way1 + "->" + way2 + "] : " + get_name + (string)"[�¼� " + to_string(seat_num) + "]"<<endl;
    f_id.close();
    stats[0][ID[0]].push_back(seat_num);
    save_file(f_id);
    prt_way(get_name);
}

void air_Seat::cancel(int way)
{
    show();
    while (1)
    {
        cout << "�¼���ȣ>>(0�Է½� ����)";
        cin >> seat_num;
        cout << endl;
        if (seat_num == 0)
        {
            cout << "<0�� �ԷµǾ����ϴ�. ���� ��Ұ� ����˴ϴ�>" << endl << endl;
            return;
        }
        cout << "�̸��Է�>>";
        cin >> get_name;

        if (!strcmp(name[seat_num - 1], get_name))
        {
            strcpy(name[seat_num - 1], "___");
            break;
        }
        else
        {
            cout << "<����Ǿ����� �ʰų�, ����Ǿ� �ִ� �̸��� �ٸ��ϴ�. �ٽ� �Է����ּ���>" << endl;
        };
    }
    prt_way(get_name);
    erase_file(f_id,id+"_info_air.txt");
    for (int size=0;size < info[0][ID[0]].size();size++)
    {
        if (info[0][ID[0]][size] == ("[5�� " + get_date_s + "��][" + get_time_s + "][" + way1 + "->" + way2 + "] : " + get_name + "[�¼� " + to_string(seat_num) + "]"))
        {
            stats[0][ID[0]].erase(remove(stats[0][ID[0]].begin(), stats[0][ID[0]].end(), stats[0][ID[0]][size]), stats[0][ID[0]].end());
        }
    }
    save_file(f_id);
}
void air_Seat::show()
{
    open_file(f_id);
    cout << time << ":  ";
    for (int i = 0;i < 8;i++)
    {
        cout << name[i];
        cout << "     ";
    }
    cout << endl ;
}
void air_Seat::available_seat(int money)
{
    cout << "������ �¼� : ";
    if (money >= 80000 && money < 100000)
    {
        for (int i = 3;i < 8;i++)
        {
            if (!strcmp(name[i], "___"))
                cout << i + 1 << "  ";
        }
    }
    else if(money>=100000)
    for (int i = 0;i < 8;i++)
    {
        if (!strcmp(name[i], "___"))
            cout << i + 1 << "  ";
    }
    cout << endl;
}
void air_Seat::prt_way(char* get_name)
{
    cout <<"<" << id << "���� ���ϸ����� " << get_mile(f_id) << "�� �Դϴ�>" << endl << endl;
}


void air_Seat::set_info(string get_date_s, string get_time_s, string way1, string way2,string id, string airplane)
{
    this->get_date_s = get_date_s;
    this->get_time_s = get_time_s;
    this->way1 = way1;
    this->way2 = way2;
    this->id = id;
    this->airplane = airplane;
}
void air_Seat::erase_file(fstream& f_id,string txt)
{
    string line;
    f_id.open(txt, ios::in);
    help_info.open("help.txt", ios::out);
    while (getline(f_id, line))
    {
        if (line != (airplane + "[5�� " + get_date_s + "��][" + get_time_s + "][" + way1 + "->" + way2 + "] : " + get_name + (string)"[�¼� " + to_string(seat_num) + "]"))
            help_info << line << endl;
    }
    f_id.close();
    help_info.close();

    f_id.open(txt, ios::out);
    help_info.open("help.txt", ios::in);
    while (getline(help_info, line))
    {
        f_id << line<<endl;
    }
    f_id.close();
    help_info.close();
    cout << "<������ ��ҵǾ����ϴ�>" << endl;
}
air_Seat::~air_Seat()
{
    for (int i = 0;i < 8;i++)
    {
        delete[] name[i];
    }
}
void air_Seat::save_file(fstream& f_id)
{
    f_id.open(airplane + get_date_s + get_time_s + way1 + way2 + ".txt", ios::out);
    for (int i = 0; i < 8; i++)
    {
        f_id << name[i] << endl;
    }
    f_id.close();
}
void air_Seat::open_file(fstream& f_id)
{
    string line;
    int i = 0;
    f_id.open(airplane + get_date_s + get_time_s + way1 + way2 + ".txt", ios::in);
    while (getline(f_id, line))
    {
        strcpy(name[i], line.c_str());
        i++;
    }
    f_id.close();
}
int air_Seat::get_mile(fstream& f_id)
{
    string line;
    string add="\0";
    int i = 0;
    int mile=0;
    char first='\0', second='\0';
    f_id.open(id + "_info_air.txt", ios::in);
    while (getline(f_id, line))
    {
        char first = '\0', second = '\0';
        for (int i = 0; i < line.size(); i++)
        {
            if (first == '-')
            {
                if (second == ']')
                {
                    if (strcmp(add.c_str(), "�̱�"))
                        mile += 111;
                    else
                        mile += 21;
                    add = "\0";
                    break;
                }
                else
                {
                    add+= line[i];
                    second = line[i];
                }
                    
            }
            else
                first = line[i];

        }
    }
    f_id.close();
    return mile;
}
