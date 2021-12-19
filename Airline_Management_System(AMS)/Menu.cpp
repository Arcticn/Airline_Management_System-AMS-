#include "AMS.h"

bool Menu::StartMenu() {
    Login login;
    AirlineBoard ab;
    system("cls");
    cout << "��ӭʹ�ú��߹���ϵͳ��" << '\n' << endl;
    cout << "1������Ա��¼���" << endl;
    cout << "2���û��˵�¼���" << endl;
    cout << "3�����߹�ʾ��" << endl;
    cout << "0���˳�ϵͳ" << endl;
    cout << "����������ѡ��:";
    char n;
    cin >> n;
    switch (n)
    {
    case '1':
        login.SuperLogin();
        return true;
        break;
    case '2':
        login.UserLogin();
        return true;
        break;
    case '3':
        ab.menu();
        return true;
        break;
    case '0':
        return false;
        break;
    default:
        cout << "���������������������룡" << endl;
        return true;
        break;
    }
}

void Menu::UserMenu(int uid) {
    UserInterface ui =UserInterface(uid);
    while (true) {
        system("cls");
        cout << "1����Ʊ" << '\n';
        cout << "2����ѯ����" << '\n';
        cout << "3����Ʊ" << '\n';
        cout << "4���鿴�ҵĻ�Ʊ" << '\n';
        cout << "0�������ϼ��˵�" << '\n';
        cout << "����������ѡ��";
        char n; cin >> n;
        switch (n)
        {
        case '1':
            ui.TicketOrder(uid);
            break;
        case '2':
            ui.AirlineSearch();
            break;
        case '3':
            ui.TicketDiscard(uid);
            break;
        case '4':
            ui.ViewMyTicket(uid);
            break;
        case '0':
            goto outport;
            break;
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
        cout << "4���鿴��Ʊ��Ϣ" << '\n';
        cout << "5���޸ĺ�����Ϣ" << '\n';
        cout << "0�������ϼ��˵�" << '\n';
        cout << "����������ѡ��";
        char n; cin >> n;
        switch (n)
        {
        case '1':
            ui.SuperTicketOrder();
            break;
        case '2':
            ui.SuperAirlineSearch();
            break;
        case '3':
            ui.SuperTicketDiscard();
            break;
        case '4':
            ui.SuperViewTicket();
            break;
        case '5':
            ui.LineInfoChange();
            break;
        case '0':
            goto outport;
            break;
        default:
            cout << "���������������������룡" << endl;
            break;
        }
    }
outport:return;
}
