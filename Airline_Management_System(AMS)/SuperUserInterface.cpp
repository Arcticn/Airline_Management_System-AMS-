#include "AMS.h"

void SuperUserInterface::SuperTicketOrder()
{
	UserInterface u;
	cout << "请输入该用户的UID：";
	int uid;
	cin >> uid;
	u.TicketOrder(uid);
}

void SuperUserInterface::SuperAirlineSearch()
{
	UserInterface u;
	u.AirlineSearch();
}

void SuperUserInterface::SuperTicketDiscard()
{
	UserInterface u;
	cout << "请输入该用户的UID：";
	int uid;
	cin >> uid;
	u.TicketDiscard(uid);
}

void SuperUserInterface::SuperViewTicket()
{
	UserInterface u;
	cout << "请输入该用户的UID：";
	int uid;
	cin >> uid;
	u.ViewMyTicket(uid);
}

void SuperUserInterface::LineInfoChange()
{
	system("cls");
	AirlineInfo info;
	cout << "请输入您想要更改的航线的航班号：";
	string line;
	cin >> line;
	cout << left << setw(8) << "航班号" << setw(20) << "出发机场" << setw(20) << "目的机场" << setw(12) << "起飞时间" << setw(12) << "抵达时间"  << setw(18) << "航空公司" << setw(12) << "飞机型号" << endl;
	cout << left << setw(8) << line << setw(20) << info.SearchDepart(line) << setw(20) << info.SearchDesti(line) << info.SearchDeparTime(line) << "       " << info.SearchDesTime(line) << "       "  << setw(18) << info.SearchCompany(line) << setw(12) << info.SearchAirplane(line) << endl;
	cout << "1、出发机场" << endl << "2、目的机场" << endl << "3、起飞时间"  << endl << "4、航空公司" << endl << "5、飞机型号" << endl;
	cout << "请输入您想要更改的信息的序号：" << endl;
	char choice;
	cin >> choice;
	int n;
	switch (choice)
	{
	case '1':
		n = 1;
		for (auto c : AirportDatabase) {
			cout << n++ << "、" << c.AirportName << endl;
		}
		cout << "请输入您想要选择的机场序号：";
		int choice1;
		cin >> choice1;
		AirlineInfoDatabase[LineQuickFind[line]].Departure = AirportDatabase[choice1 - 1].AirportName;
		break;
	case '2':
		n = 1;
		for (auto c : AirportDatabase) {
			cout << n++ << "、" << c.AirportName << endl;
		}
		cout << "请输入您想要选择的机场序号：";
		int choice2;
		cin >> choice2;
		AirlineInfoDatabase[LineQuickFind[line]].Destination = AirportDatabase[choice2 - 1].AirportName;
		break;
	case '3':
		tm depart;
		cout << "请输入您想要更改的出发时间：" << '\n' << "小时：";
		cin >> depart.tm_hour;
		cout << "分钟：";
		cin >> depart.tm_min;
		AirlineInfoDatabase[LineQuickFind[line]].DepartureTime = depart;
		break;
	case '4':
		n = 1;
		for (auto c : Company) {
			cout << n++ << "、" << c << endl;
		}
		cout << "请输入您想要选择的公司序号：";
		int choice4;
		cin >> choice4;
		AirlineInfoDatabase[LineQuickFind[line]].Company = Company[choice4 - 1];
		break;
	case '5':
		n = 1;
		for (auto c : AirplaneDatabase) {
			cout << n++ << "、" << c.Model << endl;
		}
		cout << "请输入您想要选择的飞机序号：";
		int choice5;
		cin >> choice5;
		AirlineInfoDatabase[LineQuickFind[line]].Airplane = AirplaneDatabase[choice5 - 1].Model;
		break;
	default:
		break;
	}
	AirlineInfoDatabase[LineQuickFind[line]].RefreshLine();
	cout << "更改成功！";
	cout << "\n" << "正在返回上级菜单...";
	this_thread::sleep_for(chrono::milliseconds(700));
	return;
}
