#include "AMS.h"

bool Menu::StartMenu() {
    Login login;
    AirlineBoard ab;
    system("cls");
    cout << "1、管理员登录入口" << endl;
    cout << "2、用户端登录入口" << endl;
    cout << "3、查看所有航班信息" << endl;
    cout << "0、退出系统" << endl;
    cout << "请输入您的选择:";
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
        cout << "您的输入有误，请重新输入！" << endl;
        return true;
    }
}

void Menu::UserMenu(int uid) {
    UserInterface ui =UserInterface(uid);
    while (true) {
        system("cls");
        cout << "1、订票" << '\n';
        cout << "2、查询航班" << '\n';
        cout << "3、退票" << '\n';
        cout << "4、查看我的航班" << '\n';
        cout << "0、返回上级菜单" << '\n';
        cout << "请输入您的选择：";
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
            cout << "您的输入有误，请重新输入！" << endl;
            break;
        }
    }
outport:return;
}

void Menu::SuperUserMenu() {
    SuperUserInterface ui = SuperUserInterface();
    while (true) {
        system("cls");
        cout << "1、订票" << '\n';
        cout << "2、查询航班" << '\n';
        cout << "3、退票" << '\n';
        cout << "4、查看当前航班信息" << '\n';
        cout << "0、返回上级菜单" << '\n';
        cout << "请输入您的选择：";
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
            cout << "您的输入有误，请重新输入！" << endl;
            break;
        }
    }
outport:return;
}
