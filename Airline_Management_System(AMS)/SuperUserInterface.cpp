#include "AMS.h"

void SuperUserInterface::SuperTicketOrder()
{
	UserInterface u;
	cout << "��������û���UID��";
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
	cout << "��������û���UID��";
	int uid;
	cin >> uid;
	u.TicketDiscard(uid);
}

void SuperUserInterface::SuperViewTicket()
{
	UserInterface u;
	cout << "��������û���UID��";
	int uid;
	cin >> uid;
	u.ViewMyTicket(uid);
}

void SuperUserInterface::LineInfoChange()
{
	system("cls");
	AirlineInfo info;
	cout << "����������Ҫ���ĵĺ��ߵĺ���ţ�";
	string line;
	cin >> line;
	cout << left << setw(8) << "�����" << setw(20) << "��������" << setw(20) << "Ŀ�Ļ���" << setw(12) << "���ʱ��" << setw(12) << "�ִ�ʱ��"  << setw(18) << "���չ�˾" << setw(12) << "�ɻ��ͺ�" << endl;
	cout << left << setw(8) << line << setw(20) << info.SearchDepart(line) << setw(20) << info.SearchDesti(line) << info.SearchDeparTime(line) << "       " << info.SearchDesTime(line) << "       "  << setw(18) << info.SearchCompany(line) << setw(12) << info.SearchAirplane(line) << endl;
	cout << "1����������" << endl << "2��Ŀ�Ļ���" << endl << "3�����ʱ��"  << endl << "4�����չ�˾" << endl << "5���ɻ��ͺ�" << endl;
	cout << "����������Ҫ���ĵ���Ϣ����ţ�" << endl;
	char choice;
	cin >> choice;
	int n;
	switch (choice)
	{
	case '1':
		n = 1;
		for (auto c : AirportDatabase) {
			cout << n++ << "��" << c.AirportName << endl;
		}
		cout << "����������Ҫѡ��Ļ�����ţ�";
		int choice1;
		cin >> choice1;
		AirlineInfoDatabase[LineQuickFind[line]].Departure = AirportDatabase[choice1 - 1].AirportName;
		break;
	case '2':
		n = 1;
		for (auto c : AirportDatabase) {
			cout << n++ << "��" << c.AirportName << endl;
		}
		cout << "����������Ҫѡ��Ļ�����ţ�";
		int choice2;
		cin >> choice2;
		AirlineInfoDatabase[LineQuickFind[line]].Destination = AirportDatabase[choice2 - 1].AirportName;
		break;
	case '3':
		tm depart;
		cout << "����������Ҫ���ĵĳ���ʱ�䣺" << '\n' << "Сʱ��";
		cin >> depart.tm_hour;
		cout << "���ӣ�";
		cin >> depart.tm_min;
		AirlineInfoDatabase[LineQuickFind[line]].DepartureTime = depart;
		break;
	case '4':
		n = 1;
		for (auto c : Company) {
			cout << n++ << "��" << c << endl;
		}
		cout << "����������Ҫѡ��Ĺ�˾��ţ�";
		int choice4;
		cin >> choice4;
		AirlineInfoDatabase[LineQuickFind[line]].Company = Company[choice4 - 1];
		break;
	case '5':
		n = 1;
		for (auto c : AirplaneDatabase) {
			cout << n++ << "��" << c.Model << endl;
		}
		cout << "����������Ҫѡ��ķɻ���ţ�";
		int choice5;
		cin >> choice5;
		AirlineInfoDatabase[LineQuickFind[line]].Airplane = AirplaneDatabase[choice5 - 1].Model;
		break;
	default:
		break;
	}
	AirlineInfoDatabase[LineQuickFind[line]].RefreshLine();
	cout << "���ĳɹ���";
	cout << "\n" << "���ڷ����ϼ��˵�...";
	this_thread::sleep_for(chrono::milliseconds(700));
	return;
}
