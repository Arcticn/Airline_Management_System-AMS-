#include "AMS.h"


void UserInterface::TicketOrder() {
	system("cls");
	AirlineInfo info = AirlineInfo();
	string Departure, Destination;
	char buffer[80];
	strftime(buffer, 80, "今天是 %F %A", CurTime);
	cout << buffer << endl;
	tm Date;
	cout << "请输入您的出发日期（15天以内）：" << '\n' << "年：";
	cin >> Date.tm_year;
	cout << "月：";
	cin >> Date.tm_mon;
	cout << "日：";
	cin >> Date.tm_mday;
	int diffday = Date - CurDate;
	cout << "请输入您的出发省份：";
	cin >> Departure;
	int n = 1;
	vector<string>DEPA;
	for (auto it = AirportDatabase.begin(); it != AirportDatabase.end(); it++)
	{
		if ((*it).City == Departure) {
			DEPA.emplace_back((*it).AirportName);
			cout << n++ << "、" << (*it).AirportName << endl;
		}
	}
	int choice1;
	cout << "请输入您的出发机场：";
	cin >> choice1;
	//
	cout << "请输入您的目的省份：";
	cin >> Destination;
	n = 1;
	vector<string>DEST;
	for (auto it = AirportDatabase.begin(); it != AirportDatabase.end(); it++)
	{
		if ((*it).City == Destination) {
			DEST.emplace_back((*it).AirportName);
			cout << n++ << "、" << (*it).AirportName << endl;
		}
	}
	int choice2;
	cout << "请输入您的目的机场：";
	cin >> choice2;
	cout << "航线：" << endl;
	vector<string>directLine(info.SearchLine(DEPA[choice1 - 1], DEST[choice2 - 1]));
	vector<vector<string>>indirectLine(info.SearchIndirectLine(DEPA[choice1 - 1], DEST[choice2 - 1]));
	sort(indirectLine.begin(), indirectLine.end(), [&info](const vector<string> &v1, const vector<string> &v2) {return (info.SearchDistance(v1[0])+info.SearchDistance(v1[1]))<(info.SearchDistance(v2[0]) + info.SearchDistance(v2[1])); });
	n = 1;
	for (size_t i = 0, length = directLine.size(); i < length; i++)
		cout << n++ << "、" << '\n' << directLine[i] << " " << DEPA[choice1 - 1] << " " << DEST[choice2 - 1] << " " << endl;
	int border = --n;
	for (size_t i = 0, length = indirectLine.size(); i < length; i++)
	{
		cout << n++ << "、" << endl;
		cout << indirectLine[i][0] << " " << info.SearchDepart(indirectLine[i][0]) << " " << info.SearchDesti(indirectLine[i][0]) << "(中转) " << "余票：" << info.SearchRemaningTicket(indirectLine[i][0]) << endl;
		cout << indirectLine[i][1] << " " << info.SearchDepart(indirectLine[i][1]) << "(中转) " << info.SearchDesti(indirectLine[i][1]) << " " << "余票：" << info.SearchRemaningTicket(indirectLine[i][1]) << endl;
		
	}
	cout << "请输入您的选择：";
	int choice3;
	cin >> choice3;
	choice3 -= 1; //同步序号
	Ticket tic = Ticket();
	cout << "请输入您想要在几天后出发：";
	int diffday;
	cin >> diffday;
	cout << "请输入您想要购买的机票数目（整条航线）：";
	int amount = 1;
	cin >> amount;
	if (choice3 <= border) {

		tic.Order(100001, directLine[choice3], amount, diffday, ifqueue);
	}
	else if (choice3 > border) {
		
		tic.Order()
	}
}

void UserInterface::AirlineSearch() {

}

void UserInterface::TicketDiscard() {

}

void UserInterface::ViewMyTicket() {

}


