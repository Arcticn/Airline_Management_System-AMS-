#include "AMS.h"


void UserInterface::TicketOrder() {
	system("cls");
	AirlineInfo info = AirlineInfo();
	string Departure, Destination;
	cout << "���������ĳ���ʡ�ݣ�";
	cin >> Departure;
	int n = 1;
	vector<string>DEPA;
	for (auto it = AirportDatabase.begin(); it != AirportDatabase.end(); it++)
	{
		if ((*it).City == Departure) {
			DEPA.emplace_back((*it).AirportName);
			cout<<n++<<"��"<< (*it).AirportName << endl;
		}
	}
	int choice1;
	cout << "���������ĳ���������";
	cin >> choice1;
	//
	cout << "����������Ŀ��ʡ�ݣ�";
	cin >> Destination;
	n = 1;
	vector<string>DEST;
	for (auto it = AirportDatabase.begin(); it != AirportDatabase.end(); it++)
	{
		if ((*it).City == Destination) {
			DEST.emplace_back((*it).AirportName);
			cout << n++ << "��" << (*it).AirportName << endl;
		}
	}
	int choice2;
	cout << "����������Ŀ�Ļ�����";
	cin >> choice2;
	cout << "���ߣ�" << endl;
	vector<string>directLine(info.SearchLine(DEPA[choice1 - 1], DEST[choice2 - 1]));
	vector<vector<string>>indirectLine(info.SearchIndirectLine(DEPA[choice1 - 1], DEST[choice2 - 1]));
	n = 1;
	for (size_t i = 0, length = directLine.size(); i < length; i++)
		cout << n++ << "��" <<'\n' << directLine[i] << " " << DEPA[choice1 - 1] << " " << DEST[choice2 - 1] << " " << endl;
	int border = --n;
	for (size_t i = 0,length=indirectLine.size(); i < length; i++)
	{
		cout << n++ << "��" << endl;
		cout << indirectLine[i][0] << " " << info.SearchDepart(indirectLine[i][0]) << " " << info.SearchDesti(indirectLine[i][0]) << "(��ת) "<< endl;
		cout << indirectLine[i][1] << " " << info.SearchDepart(indirectLine[i][1]) << "(��ת) " << info.SearchDesti(indirectLine[i][1]) << " " << endl;
	}
	cout << "����������ѡ��";
	int choice3;
	cin >> choice3;
	Ticket tic = Ticket();
	cout << "����������Ҫ������";
	tm date;
	if (choice3 <= border)tic.Order(id, directLine[border - 1], date);
}

void UserInterface::AirlineSearch() {

}

void UserInterface::TicketDiscard() {

}

void UserInterface::ViewMyTicket() {

}


