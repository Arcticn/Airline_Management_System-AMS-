#include "AMS.h"

int User_ID = 100000;
map<string, string>Superuser = { { "admin","admin"} };
unordered_map<string, string>User;

void Login::UserRegister() {
    string username;
    string password;
    while (true) {
        cout << "������һ���û�����";
        cin >> username;
        if (username == "0")goto outport;
        if (User.find(username) != User.end()) {
            cout << "�û���" << username << "�ѱ�ռ�ã����������룬�˳�������0��" << endl;
            this_thread::sleep_for(chrono::milliseconds(700));
            system("cls");
        }
        else break;
    }
    cout << "���������룺";
    cin >> password;
    if (password == "0")goto outport;
    User.insert({ username,password });
    PassengerDatabase.insert({ User_ID,Passenger(User_ID)});
    UserToID.insert({ username,User_ID });
    User_ID += 1;
    cout << "ע��ɹ���2�����ת�ص�½����";
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
        cout << "���������Ա�˺ţ�";
        cin >> username;
        if (username == "0")goto outport;
        if (Superuser.find(username) == Superuser.end()) {
            cout << "�ù���Ա�˺Ų����ڣ����������룬�˳�������0��" << endl;
            this_thread::sleep_for(chrono::milliseconds(700));
            system("cls");
        }
        else break;
    }
    while (true) {
        cout << "���������Ա���룺";
        cin >> password;
        if (password == "0")goto outport;
        if (Superuser[username] != password) {
            cout << "���벻��ȷ�����������룬�˳�������0��" << endl;
            this_thread::sleep_for(chrono::milliseconds(700));
            system("cls");
        }
        else break;
    }
    if (Superuser[username] == password) {
        cout << "��½�ɹ���2�����ת������ҳ��" << endl;
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
        cout << "��Ҫע��������Register"<<'\n'<<"�����������˺ţ�" ;
        cin >> username;
        if (username == "0")goto outport;
        if (username == "Register")UserRegister();
        if (User.find(username) == User.end()) {
            cout << "���˺Ų����ڣ����������룬�˳�������0��" << endl;
            this_thread::sleep_for(chrono::milliseconds(700));
            system("cls");
        }
        else break;
    }
    while (true) {
        cout << "�������������룺";
        cin >> password;
        if (password == "0")goto outport;
        if (User[username] != password) {
            cout << "���벻��ȷ�����������룬�˳�������0��" << endl;
            this_thread::sleep_for(chrono::milliseconds(700));
            system("cls");
            cout << "��Ҫע��������Register�������������˺ţ�" << username << endl;
        }
        else break;
    }
    if (User[username] == password) {
        cout << "��½�ɹ���2�����ת����ҳ��" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        system("cls");
        Menu menu;
        menu.UserMenu(UserToID[username]);
    }
outport:return;
}


