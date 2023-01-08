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
    cout << "������ ���� ���̸� �Է����ּ���>>";
    cin >> age;
    cout << endl;
    if (age <= 7)
    {
        cout << "<������ �Ƶ��� ������ �Ұ����մϴ�>" << endl << endl;
        return;
    }
    cout << "�����ڸ��� �Է����ּ���>>";
    cin >> get_name;
    cout << endl;
    while (1)
    {
        cout << "�� �ο��� �Է����ּ���, �ִ� ���� ���� �ο� 4��(0�Է½� ����)>>";
        cin >> total_p;
        cout << endl;
        if (total_p == 0)
        {
            cout << "<�ý����� ����˴ϴ�>" << endl;
            return;
        }
        else if (total_p > 4)
            cout << "<���� ���� �ο��� �ִ� 4���Դϴ�>" << endl;
        else if (total_p > total_rs)
            cout << "<�� �ο��� ���� �����¼����� �����ϴ�>" << endl;
        else
            break;
    }
    if (get_total_p_rs(total_p, get_name))
    {
        cout << "<�¼��� �����Ͽ� ������ �� �� �����ϴ�>" << endl;
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
        cout << "�̸��Է�>>(exit�Է½� ����)";
        cin >> get_name;
        cout << endl;
        if (!strcmp("exit", get_name))
            break;
        for (int i = 0; i < 3; i++)
        {
            if (!strcmp(seat_4[i], get_name))
            {
                cout << "<������ ��ҵǾ����ϴ�>" << endl;
                strcpy(seat_4[i], "___");
                check = 1;
                erase_file(f_id);
                for (int size = 0; size < info[1][ID[1]].size(); size++)
                {

                    if (info[1][ID[1]][size] == "[5�� " + get_date_s + "��][�Ĵ� ����] : " + get_name + (string)"[4�� �¼�]")
                    {
                        stats[1][ID[1]].erase(remove(stats[1][ID[1]].begin(), stats[1][ID[1]].end(), stats[1][ID[1]][size]), stats[1][ID[1]].end());
                    }

                }
                total_rs += 4;
                return;
            }
            else if (!strcmp(seat_2[i], get_name))
            {
                cout << "<������ ��ҵǾ����ϴ�>" << endl;
                strcpy(seat_2[i], "___");
                check = 1;
                erase_file(f_id);
                for (int size = 0; size < info[1][ID[1]].size(); size++)
                {

                    if (info[1][ID[1]][size] == "[5�� " + get_date_s + "��][�Ĵ� ����] : " + get_name + (string)"[2�� �¼�]")
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
            cout << "<����Ǿ����� �ʰų�, ����Ǿ� �ִ� �̸��� �ٸ��ϴ�. �ٽ� �Է����ּ���>" << endl;
        };
    }
}
void res_Seat::show()
{
    cout << "������ ��� : ";
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
                    cout << "������ �ʽ��ϴ�" << endl;
                f_id << "[5�� " + get_date_s + "��][�Ĵ� ����] : " + get_name + (string)"[4�� �¼�]" << endl;
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
                    cout << "������ �ʽ��ϴ�" << endl;
                f_id << "[5�� " + get_date_s + "��][�Ĵ� ����] : " + get_name + (string)"[2�� �¼�]" << endl;
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
                    cout << "������ �ʽ��ϴ�" << endl;
                f_id << "[5�� " + get_date_s + "��][�Ĵ� ����] : " + get_name + (string)"[4�� �¼�]" << endl;
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
        cout << "�� �ο��� �Է����ּ���, �ִ� ��� ���� �ο� 4��(0�Է½� ����)>>";
        cin >> total_p;
        cout << endl;
        if (total_p == 0)
        {
            cout << "<�ý����� ����˴ϴ�>" << endl;
            return;
        }
        else if (total_p > 4)
            cout << "<��� ���� �ο��� �ִ� 4���Դϴ�>" << endl;
        else
            break;
    }
    cout << "����ڸ��� �Է����ּ���>>";
    cin >> str_get_name;
    cout << endl;
    if (total_p == 1 || total_p == 2)
    {
        
        if (seat_2_w.size() < 4)
        {
            cout << "<������ ���� �����մϴ�!>" << endl;
            seat_2_w.push_back(str_get_name);
            f_id.open(id + "_info_res.txt", ios::out | ios::app);
            if (!f_id)
                cout << "������ �ʽ��ϴ�" << endl;
            f_id << "[walk-in] : " + str_get_name + (string)"[2�� �¼�]" << endl;
            f_id.close();
            stats[1][ID[1]].push_back(2);
        }
        else if (seat_4_w.size() < 4)
        {
            cout << "<������ ���� �����մϴ�!>" << endl;
            seat_4_w.push_back(str_get_name);
            f_id.open(id + "_info_res.txt", ios::out | ios::app);
            if (!f_id)
                cout << "������ �ʽ��ϴ�" << endl;
            f_id << "[walk-in] : " + str_get_name + (string)"[4�� �¼�]" << endl;
            f_id.close();
            stats[1][ID[1]].push_back(4);
        }
        else
        {
            seat_2_w.push_back(str_get_name);
            cout << "��� ��ȣ " << seat_2_w.size() - 4 << "�Դϴ�" << endl;
            f_id.open(id + "_info_res.txt", ios::out | ios::app);
            if (!f_id)
                cout << "������ �ʽ��ϴ�" << endl;
            f_id << "[walk-in] : " + str_get_name + (string)"[2�� �¼�]" << endl;
            f_id.close();
            stats[1][ID[1]].push_back(2);
        }
    }
    else if (total_p == 3 || total_p == 4)
    {
        if (seat_4_w.size() < 4)
        {
            cout << "<������ ���� �����մϴ�!>" << endl;
            seat_4_w.push_back(str_get_name);
            f_id.open(id + "_info_res.txt", ios::out | ios::app);
            if (!f_id)
                cout << "������ �ʽ��ϴ�" << endl;
            f_id << "[walk-in] : " + str_get_name + (string)"[4�� �¼�]" << endl;
            f_id.close();
            stats[1][ID[1]].push_back(4);
        }
        else
        {
            seat_4_w.push_back(str_get_name);
            cout << "<��� ��ȣ " << seat_4_w.size() - 4 << "�Դϴ�>" << endl;
            f_id.open(id + "_info_res.txt", ios::out | ios::app);
            if (!f_id)
                cout << "������ �ʽ��ϴ�" << endl;
            f_id << "[walk-in] : " + str_get_name + (string)"[4�� �¼�]" << endl;
            f_id.close();
            stats[1][ID[1]].push_back(4);
        }
    }
}
void res_Seat::w_in_cancel()
{
    while (1)
    {
        cout << "�̸��Է�>>(exit�Է½� ����)";
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
            if (info[1][ID[1]][size] == "[5�� " + get_date_s + "��][�Ĵ� ����] : " + get_name + (string)"[4�� �¼�]" && check >= 4)
            {
                stats[1][ID[1]].erase(remove(stats[1][ID[1]].begin(), stats[1][ID[1]].end(), stats[1][ID[1]][size]), stats[1][ID[1]].end());
            }
            else if (info[1][ID[1]][size] == "[5�� " + get_date_s + "��][�Ĵ� ����] : " + get_name + (string)"[2�� �¼�]" && check >= 4)
            {
                stats[1][ID[1]].erase(remove(stats[1][ID[1]].begin(), stats[1][ID[1]].end(), stats[1][ID[1]][size]), stats[1][ID[1]].end());
            }
        }
        
        for (it = seat_2_w.begin(); it != seat_2_w.end(); it++)
        {
            if (*it == get_name)
            {
                cout << "<��ҵǾ����ϴ�>" << endl;
                seat_2_w.erase(it);
                erase_file(f_id);
                return;
            }
        }
        for (it = seat_4_w.begin(); it != seat_4_w.end(); it++)
        {
            if (*it == get_name)
            {
                cout << "<��ҵǾ����ϴ�>" << endl;
                seat_4_w.erase(it);
                erase_file(f_id);
                return;
            }
        }
        cout << "<����Ǿ����� �ʰų�, ����Ǿ� �ִ� �̸��� �ٸ��ϴ�. �ٽ� �Է����ּ���>" << endl;
    }
}
void res_Seat::w_in_show()
{
    cout << "2�ο� �¼� ����� ��� : ";
    for (int i = 4; i < seat_2_w.size(); i++)
        cout << seat_2_w.at(i);
    cout << "4�ο� �¼� ����� ��� : ";
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
        if (line != ("[5�� " + get_date_s + "��][�Ĵ� ����] : " + get_name + (string)"[2�� �¼�]") && line != ("[5�� " + get_date_s + "��][�Ĵ� ����] : " + get_name + (string)"[4�� �¼�]")
            && line != ("[walk-in] : " + str_get_name + (string)"[2�� �¼�]") && line != ("[walk-in] : " + str_get_name + (string)"[4�� �¼�]"))
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
    cout << "<������ ��ҵǾ����ϴ�>" << endl;
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