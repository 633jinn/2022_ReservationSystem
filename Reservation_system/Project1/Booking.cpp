#include "Booking.h"
void Booking::make_id(fstream& f_id)
{
    cout << "<����� ���̵�� ��й�ȣ�� �Է����ּ���>" << endl;
    cout << "id :";
    cin >> id;
    cout << "password :";
    cin >> password;
    cout << endl;
    f_id << id << endl << password << endl;
}
bool Booking::find_id(fstream& f_id, string id)
{
    string line;
    int count = 0;
    while (getline(f_id, line))
    {
        if (line == id && count % 2 == 0)
        {
            getline(f_id, _password);
            f_id.close();
            return 0;
        }
        count++;
    }
    f_id.close();
    return 1;
}
void Booking::read_info(fstream& f_id)
{
    cout << "<" << id << "���� ���� ����� ����մϴ�>" << endl;
    string line;
    while (getline(f_id,line))
    {
        cout << line << endl;
    }
}
void Booking::print_stats(fstream& f_id, int size)
{
    cout << "<" << id << "���� ���� ��踦 ����մϴ�>" << endl<<endl;

    string line;
    string first_c="\0", second_c="\0";//"�¼�"�� ã�´�.
    string add_c="\0";
    string check_c;
    string tmp;
    int check = 0;
    int* total=new int[size];
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        total[i]=0;
    }
    if (size == 2)
    {
        while (getline(f_id, line)) 
        {
            first_c = "\0", second_c = "\0", add_c = "\0";
            for (int i = 0; i < line.size(); i++)
            {
                tmp = second_c;
                second_c = line[i + 2];
                first_c = tmp;
                add_c = line[i];
                if ( first_c + second_c == "��")
                {
                    total[stoi(add_c)/2 - 1] += 1;
                    count++;
                    break;
                }
            }
        }
        cout << "<������� �� [" << count << "]ȸ �����ϼ̽��ϴ�.>" << endl;
        cout << "----------------------------------------------" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << (i + 1) * 2 << "�� �¼� ���� : ";
            cout << total[i] << "ȸ" << endl << endl;
        }
    }
    else
    {
        while (getline(f_id, line))
        {
            first_c = "\0", second_c = "\0", add_c = "\0";
            for (int i = 0; i < line.size(); i++)
            {

                if (check == 1 && first_c + second_c == "��")
                {
                    check_c = line[i + 1];
                    if (check_c != "]")
                        add_c += check_c;
                    else
                    {
                        total[stoi(add_c) - 1] += 1;
                        count++;
                        break;
                    }
                }
                else
                {
                    if (first_c + second_c == "��")
                        check = 1;
                    tmp = second_c;
                    second_c = line[i];
                    first_c = tmp;
                }
            }
        }
        cout << "<������� �� [" << count << "]ȸ �����ϼ̽��ϴ�.>" << endl;
        cout << "----------------------------------------------" << endl;
        for (int i = 0; i < size; i++)
        {
            if (total[i] > 0)
            {
                cout << "[�¼� " << i + 1 << "]���� : ";
                cout << total[i] << "ȸ" << endl << endl;
            }
        }
    }
    delete[]  total;
}
