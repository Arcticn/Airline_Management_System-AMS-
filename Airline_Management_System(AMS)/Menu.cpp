#include "AMS.h"

bool Menu::StartMenu() {
    Login login;
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
        AirlineBoard();
        return true;
    case 0:
        return false;
    default:
        cout << "您的输入有误，请重新输入！" << endl;
        return true;
    }
}

void Menu::UserMenu() {
    UserInterface ui =UserInterface();
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
            ui.TicketOrder();
            break;
        case 2:
            ui.AirlineSearch();
            break;
        case 3:
            ui.TicketDiscard();
            break;
        case 4:
            ui.ViewMyTicket();
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
            cout << "您的输入有误，请重新输入！" << endl;
            break;
        }
    }
outport:return;
}
