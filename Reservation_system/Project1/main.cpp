#include <iostream>
#include "Booking.h"
#include "Airplane.h"
#include "Restaurant.h"
#include "Study.h"
map<string, vector<string>>info[3];//������
map<string, vector<int>>stats[3];//�¼�Ȥ�� ���̺� ���
map<string, vector<string>>stats_sex;//���� ���
string ID[3];//���̵�
int main()
{
    int get_menu;
    int get_airline;

    cout << "<���տ���ý����� ����Ǿ����ϴ�>" << endl<<endl;
    while (1) {
        cout << "<���Ͻô� ������ �������ּ���>" << endl;
        cout << "1:����� ����, 2:�Ĵ� ����, 3.������ ����, 4.����>> ";
        cin >> get_menu;
        cout << endl << endl;
        if (get_menu == 1)
        {
            cout << "<���Ͻô� �װ��� ���񽺸� �������ּ���>" << endl;
            cout << "�����װ�:1, �ƽþƳ��װ�:2, �Ѽ��װ�:3>>";
            cin >> get_airline;
            Booking* book = new Airplane(get_menu, get_airline);
        }
        else if (get_menu == 2) //�Ĵ�
        {
            Booking* book=new Restaurant;
        }
        else if (get_menu == 3)//������
        {
            Booking* book = new Study;
        }
        else if (get_menu == 4)
        {
            cout << "<���� �ý����� �����մϴ�>" << endl;
            cout << "-----------------------------" << endl << endl;
            break;
        }
        else
        {
            cout << "<�߸��Է��ϼ̽��ϴ�. �ٽ��Է����ּ���>" << endl;
        }
    }
    return 0;
}