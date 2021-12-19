#include "AMS.h"

bool Menu::StartMenu() {
    Login login;
    AirlineBoard ab;
    system("cls");
    cout << "欢迎使用航线管理系统！" << '\n' << endl;
    cout << "1、管理员登录入口" << endl;
    cout << "2、用户端登录入口" << endl;
    cout << "3、航线公示板" << endl;
    cout << "0、退出系统" << endl;
    cout << "请输入您的选择:";
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
        cout << "您的输入有误，请重新输入！" << endl;
        return true;
        break;
    }
}

void Menu::UserMenu(int uid) {
    UserInterface ui =UserInterface(uid);
    while (true) {
        system("cls");
        cout << "1、订票" << '\n';
        cout << "2、查询航班" << '\n';
        cout << "3、退票" << '\n';
        cout << "4、查看我的机票" << '\n';
        cout << "0、返回上级菜单" << '\n';
        cout << "请输入您的选择：";
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
        cout << "4、查看机票信息" << '\n';
        cout << "5、修改航线信息" << '\n';
        cout << "0、返回上级菜单" << '\n';
        cout << "请输入您的选择：";
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
            cout << "您的输入有误，请重新输入！" << endl;
            break;
        }
    }
outport:return;
}
