#include "AMS.h"

int User_ID = 100000;
map<string, string>Superuser = { { "admin","admin"} };
unordered_map<string, string>User;

void Login::UserRegister() {
    string username;
    string password;
    while (true) {
        cout << "请输入一个用户名：";
        cin >> username;
        if (username == "0")goto outport;
        if (User.find(username) != User.end()) {
            cout << "用户名" << username << "已被占用，请重新输入，退出请输入0！" << endl;
            this_thread::sleep_for(chrono::milliseconds(700));
            system("cls");
        }
        else break;
    }
    cout << "请输入密码：";
    cin >> password;
    if (password == "0")goto outport;
    User.insert({ username,password });
    PassengerDatabase.insert({ User_ID,Passenger(User_ID)});
    UserToID.insert({ username,User_ID });
    User_ID += 1;
    cout << "注册成功！2秒后跳转回登陆界面";
    this_thread::sleep_for(chrono::seconds(2));
    system("cls");
    UserLogin();
outport:return;
}

void Login::SuperLogin() {
    system("cls");
    string username;
    string password;
    while (true) {
        cout << "请输入管理员账号：";
        cin >> username;
        if (username == "0")goto outport;
        if (Superuser.find(username) == Superuser.end()) {
            cout << "该管理员账号不存在，请重新输入，退出请输入0！" << endl;
            this_thread::sleep_for(chrono::milliseconds(700));
            system("cls");
        }
        else break;
    }
    while (true) {
        cout << "请输入管理员密码：";
        cin >> password;
        if (password == "0")goto outport;
        if (Superuser[username] != password) {
            cout << "密码不正确，请重新输入，退出请输入0！" << endl;
            this_thread::sleep_for(chrono::milliseconds(700));
            system("cls");
        }
        else break;
    }
    if (Superuser[username] == password) {
        cout << "登陆成功！2秒后跳转至管理页面" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        system("cls");
        Menu menu;
        menu.SuperUserMenu();
    }
outport:return;
}

void Login::UserLogin() {
    system("cls");
    string username;
    string password;
    while (true) {
        cout << "若要注册请输入Register"<<'\n'<<"请输入您的账号：" ;
        cin >> username;
        if (username == "0")goto outport;
        if (username == "Register")UserRegister();
        if (User.find(username) == User.end()) {
            cout << "该账号不存在，请重新输入，退出请输入0！" << endl;
            this_thread::sleep_for(chrono::milliseconds(700));
            system("cls");
        }
        else break;
    }
    while (true) {
        cout << "请输入您的密码：";
        cin >> password;
        if (password == "0")goto outport;
        if (User[username] != password) {
            cout << "密码不正确，请重新输入，退出请输入0！" << endl;
            this_thread::sleep_for(chrono::milliseconds(700));
            system("cls");
            cout << "若要注册请输入Register，请输入您的账号：" << username << endl;
        }
        else break;
    }
    if (User[username] == password) {
        cout << "登陆成功！2秒后跳转至主页面" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        system("cls");
        Menu menu;
        menu.UserMenu(UserToID[username]);
    }
outport:return;
}


