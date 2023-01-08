#include "stu_Seat.h"

stu_Seat::stu_Seat()
{
    for (int i = 0;i < 15;i++)
    {
        for (int j = 0;j < 15;j++)
        {
            seat[i][j]="___";
        }
    }
}
void stu_Seat::reserve()
{
    while (1) 
    {
        cout << "본인 세대의 ID를 입력해주세요>>(0입력시 종료)";
        cin >> Id;
        cout << endl;
        if (stoi(Id) >= 1 && stoi(Id) <= 300)
            break;
        else if (stoi(Id) == 0)
        {
            cout << "<0이 입력되었습니다. 예약이 종료됩니다>" << endl;
            return;
        }
        else
            cout << "<존재하지 않는 세대입니다. 다시 입력해주세요>" << endl;

    }
    
    cout << "예약자 분의 나이를 입력해주세요>>";
    cin >> age;
    cout << endl;
    if (age <= 13)
    {
        cout << "<13세 이하는 예약이 불가능합니다>" << endl << endl;
        return;
    }
    show();

    cout << "이름입력>>";
    cin >> get_name;
    cout << "성별입력, 남자:1, 여자:2>>";
    cin >> get_sex;
    cout << endl;
    int row = 0;
    int column = 0;
    while (1)
    {
        cout << "좌석번호(0입력시 종료)>>";
        cin >> seat_num;
        if (seat_num == 0)
        {
            cout << "<0이 입력되었습니다. 예약이 종료됩니다>" << endl;
            return;
        }
        else if (!(seat_num >= 1 && seat_num <= 225))
        {
            cout << "<없는 좌석입니다. 다시 선택해주세요>" << endl;
            continue;
        }
        
        int check = 1;
        for (int i = 0;i < 15;i++)
        {
            for (int j = 0;j < 15;j++)
            {
                if (seat_num == check)
                {
                    row = i;
                    column = j;
                }
                check++;
            }
        }
        if (seat[row][column]!= "___")
            cout << "<이미 예약된 좌석입니다. 다시 입력해주세요>" << endl;
        else if (!check_sex(row, column, get_sex))
        {
            cout << "<앞뒤, 양옆에 다른 성의 이용자가 있습니다. 다른 좌석을 선택해 주세요>" << endl;
        }
        else
            break;
        
    }
    if (
        (f_id, stoi(get_date_s))<5)
    {
        cout << "<예약되었습니다>" << endl;
    }
    else
    {
        cout << "<세대 당 최대 4시간까지 예약 가능합니다>" << endl << "<더이상 예약하실 수 없습니다>" << endl;
        return;
    }
    int size = info[2][ID[2]].size();
    if (get_sex == 1)
    {
        seat[row][column] = get_name + (string)"(남)";
        stats[2][ID[2]].push_back(seat_num);
        stats_sex[ID[2]].push_back("남");
        f_id.open(id + "_info_stu.txt", ios::out | ios::app);
        if (!f_id)
            cout << "열리지 않습니다" << endl;
        f_id << "[5월 " + get_date_s + "일][" + get_time_s + "시][" + Id + "] : " + get_name + (string)"(남)" + "[좌석 " + to_string(seat_num) + "]" << endl;
        f_id.close();
    }
    else if (get_sex == 2) 
    {
        f_id.close();
        seat[row][column] = get_name + (string)"(여)";
        stats[2][ID[2]].push_back(seat_num);
        stats_sex[ID[2]].push_back("여");
        f_id.open(id + "_info_stu.txt", ios::out | ios::app);
        if (!f_id)
            cout << "열리지 않습니다" << endl;
        f_id << "[5월 " + get_date_s + "일][" + get_time_s + "시][" + Id + "] : " + get_name + (string)"(여)" + "[좌석 " + to_string(seat_num) + "]" << endl;
    }
    save_file(f_id);
    cout << endl << endl;
}
void stu_Seat::cancel()
{
    show();
    int row = 0;
    int column = 0;
    while (1)
    {
        cout << "본인 세대의 ID를 입력해주세요>>(0입력시 종료)";
        cin >> Id;
        cout << endl;
        if (stoi(Id) >= 1 && stoi(Id) <= 300)
            break;
        else if (stoi(Id) == 0)
        {
            cout << "<0이 입력되었습니다. 예약이 종료됩니다>" << endl;
            return;
        }
        else
            cout << "<존재하지 않는 세대입니다. 다시 입력해주세요>" << endl;

    }
    while (1)
    {
        cout << "좌석번호>>(0입력시 종료)";
        cin >> seat_num;
        cout << endl;
        if (seat_num == 0)
        {
            cout << "<0이 입력되었습니다. 예약이 종료됩니다>" << endl;
            return;
        }
        else if (!(seat_num >= 1 && seat_num <= 225))
        {
            cout << "<없는 좌석입니다. 다시 선택해주세요>" << endl;
            continue;
        }
        int check = 1;
        for (int i = 0;i < 15;i++)
        {
            for (int j = 0;j < 15;j++)
            {
                if (seat_num == check)
                {
                    row = i;
                    column = j;
                }
                check++;
            }
        }
        cout << "이름입력>>";
        cin >> get_name;
        cout << endl;
        while (true)
        {
            cout << "성별입력, 남자:1, 여자:2>>";
            cin >> get_sex;
            cout << endl;
            if (get_sex != 1 && get_sex != 2)
                cout << "<잘못된 입력입니다>" << endl;
            else
                break;
        }
        
        if (get_sex == 1)
        {
            if (seat[row][column] == get_name + (string)"(남)")
            {
                seat[row][column] = "___";
                erase_file(f_id);
                for (int size = 0;size < info[2][ID[2]].size();size++)
                {
                    if (info[2][ID[2]][size] == "[5월 " + get_date_s + "일][" + get_time_s + "시][" + Id + "] : " + get_name + (string)"(남)" + "[좌석 " + to_string(seat_num) + "]")
                    {
                        stats[2][ID[2]].erase(remove(stats[2][ID[2]].begin(), stats[2][ID[2]].end(), stats[2][ID[2]][size]), stats[2][ID[2]].end());
                        stats_sex[ID[2]].erase(remove(stats_sex[ID[2]].begin(), stats_sex[ID[2]].end(), stats_sex[ID[2]][size]), stats_sex[ID[2]].end());
                    }
                }
                save_file(f_id);
                break;
            }
            else
            {
                cout << "<예약되어있지 않거나, 예약되어 있는 이름과 다릅니다. 다시 입력해주세요>" << endl;
            };
        }
        else if (get_sex == 2)
        {
            if (seat[row][column] == get_name + (string)"(여)")
            {
                seat[row][column] = "___";
                erase_file(f_id);
                for (int size = 0;size < info[2][ID[2]].size();size++)
                {
                    if (info[2][ID[2]][size] == "[5월 " + get_date_s + "일][" + get_time_s + "시][" + Id + "] : " + get_name + (string)"(여)" + "[좌석 " + to_string(seat_num) + "]")
                    {
                        stats[2][ID[2]].erase(remove(stats[2][ID[2]].begin(), stats[2][ID[2]].end(), stats[2][ID[2]][size]), stats[2][ID[2]].end());
                        stats_sex[ID[2]].erase(remove(stats_sex[ID[2]].begin(), stats_sex[ID[2]].end(), stats_sex[ID[2]][size]), stats_sex[ID[2]].end());
                    }
                        
                }
                save_file(f_id);
                break;
            }
            else
            {
                cout << "<예약되어있지 않거나, 예약되어 있는 이름과 다릅니다. 다시 입력해주세요>" << endl;
            };
        }
    }
}
void stu_Seat::show()
{
    open_file(f_id);
    int check = 1;
    string name;
    for (int i = 0;i < 15;i++)
    {
        for (int j = 0;j < 15;j++)
        {
            if (seat[i][j] == "___")
            {
                name = "_" + to_string(check) + "_";
                cout.width(11);
                cout << left<<name;
            }
            else
            {
                cout.width(11);
                cout << left << seat[i][j];
            }
            check++;
        }
        cout << endl;
    }
    cout << endl;
}
bool stu_Seat::check_sex(int row, int column,int get_sex)//자리 옆에 이성이 있는지 확인
{
    if (get_sex == 1)
    {
        if (row == 0 && column == 0)
        {
            if (sex[row + 1][column] == 2 || sex[row][column + 1] == 2)
                return false;
        }
        else if (row == 14 && column == 0)
        {
            if (sex[row - 1][column] == 2 || sex[row][column + 1] ==2)
                return false;
        }
        else if (row == 0 && column == 14)
        {
            if (sex[row + 1][column] == 2 || sex[row][column - 1] ==2)
                return false;
        }
        else if (row == 14 && column == 14)
        {
            if (sex[row - 1][column] == 2 || sex[row][column - 1] == 2)
                return false;
        }
        else if (row == 0)
        {
            if (sex[row + 1][column] ==2 || sex[row][column - 1] == 2 || sex[row][column + 1] ==2)
                return false;
        }
        else if (row == 14)
        {
            if (sex[row - 1][column] == 2 || sex[row][column - 1] == 2 || sex[row][column + 1] == 2)
                return false;
        }
        else if (column == 0)
        {
            if (sex[row + 1][column] == 2 || sex[row - 1][column] ==2 || sex[row][column + 1] ==2)
                return false;
        }
        else if (column == 14)
        {
            if (sex[row + 1][column] == 2 || sex[row - 1][column] ==  2 || sex[row][column - 1] ==2)
                return false;
        }
        else
        {
            if (sex[row + 1][column] == 2 || sex[row - 1][column] == 2 || sex[row][column + 1] == 2 || sex[row][column - 1] == 2)
                return false;
        }
    }
    else
    {
        if (row == 0 && column == 0)
        {
            if (sex[row + 1][column] == 1 || sex[row][column + 1] == 1)
                return false;
        }
        else if (row == 14 && column == 0)
        {
            if (sex[row - 1][column] == 1 || sex[row][column + 1] == 1)
                return false;
        }
        else if (row == 0 && column == 14)
        {
            if (sex[row + 1][column] == 1 || sex[row][column - 1] == 1)
                return false;
        }
        else if (row == 14 && column == 14)
        {
            if (sex[row - 1][column] ==1 || sex[row][column - 1] == 1)
                return false;
        }
        else if (row == 0)
        {
            if (sex[row + 1][column] == 1 || sex[row][column - 1] == 1 || sex[row][column + 1] == 1)
                return false;
        }
        else if (row == 14)
        {
            if (sex[row - 1][column] == 1 || sex[row][column - 1] == 1 || sex[row][column + 1] == 1)
                return false;
        }
        else if (column == 0)
        {
            if (sex[row + 1][column] == 1 || sex[row - 1][column] == 1 || sex[row][column + 1] == 1)
                return false;
        }
        else if (column == 14)
        {
            if (sex[row + 1][column] == 1 || sex[row - 1][column] == 1 || sex[row][column - 1] == 1)
                return false;
        }
        else
        {
            if (sex[row + 1][column] == 1 || sex[row - 1][column] == 1 || sex[row][column + 1] == 1 || sex[row][column - 1] == 1)
                return false;
        }
    }
    sex[row][column] = get_sex;
    return true;
}
void stu_Seat::erase_file(fstream& f_id)
{
    string line;
    f_id.open(id + "_info_stu.txt", ios::in);
    help_info.open("help.txt", ios::out);
    while (getline(f_id, line))
    {
        if (line != ("[5월 " + get_date_s + "일]" + "[" + get_time_s + "시][" + Id + "] : " + get_name + (string)"(남)" + "[좌석 " + to_string(seat_num) + "]" )
            && line != ("[5월 " + get_date_s + "일]" + "[" + get_time_s + "시][" + Id + "] : " + get_name + (string)"(여)" + "[좌석 " + to_string(seat_num) + "]"))
            help_info << line << endl;
    }
    f_id.close();
    help_info.close();

    f_id.open(id + "_info_stu.txt", ios::out);
    help_info.open("help.txt", ios::in);
    while (getline(help_info, line))
    {
        f_id << line << endl;
    }
    f_id.close();
    help_info.close();
    cout << "<예약이 취소되었습니다>" << endl;
}
void stu_Seat::set_info(string get_date, string get_time,string id)
{
    this->get_date_s= get_date;
    this->get_time_s = get_time;
    this->id = id;
}
void stu_Seat::save_file(fstream& f_id)
{
    f_id.open("[stu]" + get_date_s + get_time_s + ".txt", ios::out);
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            f_id << seat[i][j] << endl;
        }
    }
    f_id.close();
}
void stu_Seat::open_file(fstream& f_id)
{
    string line;
    int i = 0,j=0;
    f_id.open("[stu]"+get_date_s + get_time_s + ".txt", ios::in);
    while (getline(f_id, line))
    {
        seat[i][j] = line;
        if (j == 14)
        {
            j = 0;
            i++;
        }
        else
            j++;
    }
    f_id.close();
}
int stu_Seat::get_count(fstream& f_id,int x)
{
    string line;
    string first = "\0", second= "\0";
    string add;
    int day[7] = { 0 };
    int i = 0, j = 0;
    f_id.open(id + "_info_stu.txt", ios::in);
    while (getline(f_id, line))
    {
        seat[i][j] = line;
        if (j == 14)
        {
            if (first == " ")
            {
                second = line[i] + line[i + 1];
                if (second == "일")
                    day[stoi(add) - 1] += 1;
                else
                    add = line[i];
            }
            else
                first = line[i];
        }
        else
            j++;
    }
    f_id.close();
    if (day[x - 1] > 4)
        return 5;
    else 
        return day[x - 1];
}