#include "AMS.h"

bool Menu() {
    system("cls");
    cout << "1������Ա��¼���" << endl;
    cout << "2���û��˵�¼���" << endl;
    cout << "3���鿴���к�����Ϣ" << endl;
    cout << "0���˳�ϵͳ" << endl;
    cout << "����������ѡ��:";
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        SuperLogin();
        return true;
    case 2:
        Login();
        return true;
    case 3:
        AirlineBoard();
        return true;
    case 0:
        return false;
    default:
        cout << "���������������������룡" << endl;
        return true;
    }
}

void UserMenu() {
    while (true) {
        system("cls");
        cout << "1����Ʊ" << '\n';
        cout << "2����ѯ����" << '\n';
        cout << "3����Ʊ" << '\n';
        cout << "4���鿴�ҵĺ���" << '\n';
        cout << "0�������ϼ��˵�" << '\n';
        cout << "����������ѡ��";
        int n; cin >> n;
        switch (n)
        {
        case 1:
            TicketOrder();
            break;
        case 2:
            AirlineSearch();
            break;
        case 3:
            TicketDiscard();
            break;
        case 4:
            ViewMyTicket();
            break;
        case 0:
            goto outport;
        default:
            cout << "���������������������룡" << endl;
            break;
        }
    }
outport:return;
}

void SuperUserMenu() {
    while (true) {
        system("cls");
        cout << "1����Ʊ" << '\n';
        cout << "2����ѯ����" << '\n';
        cout << "3����Ʊ" << '\n';
        cout << "4���鿴��ǰ������Ϣ" << '\n';
        cout << "0�������ϼ��˵�" << '\n';
        cout << "����������ѡ��";
        int n; cin >> n;
        switch (n)
        {
        case 1:
            TicketOrder();
            break;
        case 2:
            AirlineSearch();
            break;
        case 3:
            TicketDiscard();
            break;
        case 4:
            ViewMyTicket();
            break;
        case 0:
            goto outport;
        default:
            cout << "���������������������룡" << endl;
            break;
        }
    }
outport:return;
}
