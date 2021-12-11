#include "AMS.h"

bool Menu::StartMenu() {
    Login login;
    AirlineBoard ab;
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
        login.SuperLogin();
        return true;
    case 2:
        login.UserLogin();
        return true;
    case 3:
        ab.menu();
        return true;
    case 0:
        return false;
    default:
        cout << "���������������������룡" << endl;
        return true;
    }
}

void Menu::UserMenu(int uid) {
    UserInterface ui =UserInterface(uid);
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
            ui.TicketOrder(uid);
            break;
        case 2:
            ui.AirlineSearch();
            break;
        case 3:
            ui.TicketDiscard(uid);
            break;
        case 4:
            ui.ViewMyTicket(uid);
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

void Menu::SuperUserMenu() {
    SuperUserInterface ui = SuperUserInterface();
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
            ui.SuperTicketOrder();
            break;
        case 2:
            ui.SuperAirlineSearch();
            break;
        case 3:
            ui.SuperTicketDiscard();
            break;
        case 4:
            ui.SuperViewTicket();
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
