#include "AMS.h"


void TicketOrder() {
	system("cls");
	string Departure, Destination;
	cout << "���������ĳ���ʡ�ݣ�";
	cin >> Departure;
	int n = 1;
	for (auto it = AirportDatabase.begin(); it != AirportDatabase.end(); it++)
	{
		if ((*it).City == Departure) {
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
	for (auto it = AirportDatabase.begin(); it != AirportDatabase.end(); it++)
	{
		if ((*it).City == Destination) {
			cout << n++ << "��" << (*it).AirportName << endl;
		}
	}
	int choice2;
	cout << "����������Ŀ�Ļ�����";
	cin >> choice2;
	//
	//if(Airline.Search(choice1,choice2)==1)
}

void AirlineSearch() {

}

void TicketDiscard() {

}

void ViewMyTicket() {

}


