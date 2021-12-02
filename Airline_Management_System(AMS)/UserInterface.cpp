#include "AMS.h"


void TicketOrder() {
	system("cls");
	string Departure, Destination;
	cout << "请输入您的出发省份：";
	cin >> Departure;
	int n = 1;
	for (auto it = AirportDatabase.begin(); it != AirportDatabase.end(); it++)
	{
		if ((*it).City == Departure) {
			cout<<n++<<"、"<< (*it).AirportName << endl;
		}
	}
	int choice1;
	cout << "请输入您的出发机场：";
	cin >> choice1;
	//
	cout << "请输入您的目的省份：";
	cin >> Destination;
	n = 1;
	for (auto it = AirportDatabase.begin(); it != AirportDatabase.end(); it++)
	{
		if ((*it).City == Destination) {
			cout << n++ << "、" << (*it).AirportName << endl;
		}
	}
	int choice2;
	cout << "请输入您的目的机场：";
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


