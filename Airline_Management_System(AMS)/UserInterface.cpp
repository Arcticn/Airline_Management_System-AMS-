#include "AMS.h"

void UserInterface::TicketOrder(int uid) {
	system("cls");
	AirlineInfo info = AirlineInfo();
	string Departure, Destination;
	char buffer[80];
	strftime(buffer, 80, "今天是 %F %A", &CurTime);
	cout << buffer << endl;
	tm Date;
	//Check Date
	cout << "请输入您的出发日期（15天以内）：" << '\n' << "年：";
	cin >> Date.tm_year;
	cout << "月：";
	cin >> Date.tm_mon;
	cout << "日：";
	cin >> Date.tm_mday;
	Date.tm_year -= 1900;
	Date.tm_mon -= 1;  //Sync with tm
	int diffday = Date - CurTime;
	string sDate = to_string(Date.tm_year+1900) + to_string(Date.tm_mon+1) + to_string(Date.tm_mday);
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
	//Search Line
	vector<string>directLine(info.SearchLine(DEPA[choice1 - 1], DEST[choice2 - 1]));
	vector<vector<string>>indirectLine(info.SearchIndirectLine(DEPA[choice1 - 1], DEST[choice2 - 1]));
	sort(indirectLine.begin(), indirectLine.end(), [&info](const vector<string> &v1, const vector<string> &v2) {return (info.SearchDistance(v1[0]) + info.SearchDistance(v1[1])) < (info.SearchDistance(v2[0]) + info.SearchDistance(v2[1])); });
	n = 1;
	for (size_t i = 0, length = directLine.size(); i < length; i++)
		cout << n++ << "、" << '\n' << directLine[i] << " " << DEPA[choice1 - 1] << " " << DEST[choice2 - 1] << " " << endl;
	int border = --n;
	for (size_t i = 0, length = indirectLine.size(); i < length; i++)
	{
		cout << n++ << "、" << endl;
		cout << indirectLine[i][0] << " " << info.SearchDepart(indirectLine[i][0]) << " " << info.SearchDesti(indirectLine[i][0]) << "(中转) " << "余票：" << info.SearchRemainTicket(sDate,indirectLine[i][0]) << endl;
		cout << indirectLine[i][1] << " " << info.SearchDepart(indirectLine[i][1]) << "(中转) " << info.SearchDesti(indirectLine[i][1]) << " " << "余票：" << info.SearchRemainTicket(sDate,indirectLine[i][1]) << endl;

	}
	cout << "请输入您的选择：";
	int choice3;
	cin >> choice3;
	choice3 -= 1; //同步序号
	Ticket tic = Ticket();
	cout << "请输入您想要购买的机票数目（整条航线）：";
	int amount = 1;
	cin >> amount;
	cout << "是否愿意候补购票？（Y/N）:";
	char idea;
	cin >> idea;
	bool ifqueue;
	if (idea == 'Y') ifqueue = 1;
	else ifqueue = 0;
	if (choice3 <= border) {
		if (tic.Order(uid, directLine[choice3], amount, diffday, ifqueue))cout << "购票成功";
		else cout << "购票失败，请重试";
	}
	else if (choice3 > border) {
		if(tic.Order(uid, indirectLine[choice3][0], amount, diffday, ifqueue)
		&& tic.Order(uid, indirectLine[choice3][1], amount, diffday, ifqueue))cout << "购票成功";
		else cout << "购票失败，请重试";
	}
	cout << "\n" << "正在返回上级菜单...";
	this_thread::sleep_for(chrono::milliseconds(700));
	return;
}

void UserInterface::AirlineSearch() {
	system("cls");
	AirlineInfo info = AirlineInfo();
	string Departure, Destination;
	char buffer[80];
	strftime(buffer, 80, "今天是 %F %A", &CurTime);
	cout << buffer << endl;
	tm Date;
	//Check Date
	cout << "请输入您的出发日期（15天以内）：" << '\n' << "年：";
	cin >> Date.tm_year;
	cout << "月：";
	cin >> Date.tm_mon;
	cout << "日：";
	cin >> Date.tm_mday;
	int diffday = Date - CurTime;
	string sDate = to_string(Date.tm_year) + to_string(Date.tm_mon) + to_string(Date.tm_mday);
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
	//Search Line
	vector<string>directLine(info.SearchLine(DEPA[choice1 - 1], DEST[choice2 - 1]));
	vector<vector<string>>indirectLine(info.SearchIndirectLine(DEPA[choice1 - 1], DEST[choice2 - 1]));
	sort(indirectLine.begin(), indirectLine.end(), [&info](const vector<string> &v1, const vector<string> &v2) {return (info.SearchDistance(v1[0]) + info.SearchDistance(v1[1])) < (info.SearchDistance(v2[0]) + info.SearchDistance(v2[1])); });
	n = 1;
	for (size_t i = 0, length = directLine.size(); i < length; i++)
		cout << n++ << "、" << '\n' << directLine[i] << " " << DEPA[choice1 - 1] << " " << DEST[choice2 - 1] << " " << endl;
	int border = --n;
	for (size_t i = 0, length = indirectLine.size(); i < length; i++)
	{
		cout << n++ << "、" << endl;
		cout << indirectLine[i][0] << " " << info.SearchDepart(indirectLine[i][0]) << " " << info.SearchDesti(indirectLine[i][0]) << "(中转) " << "余票：" << info.SearchRemainTicket(sDate, indirectLine[i][0]) << endl;
		cout << indirectLine[i][1] << " " << info.SearchDepart(indirectLine[i][1]) << "(中转) " << info.SearchDesti(indirectLine[i][1]) << " " << "余票：" << info.SearchRemainTicket(sDate, indirectLine[i][1]) << endl;
	}
	cout << "按任意键返回上级菜单";
	char a;
	cin >> a;
	return;
}

void UserInterface::TicketDiscard(int uid) {
	ViewMyTicket(uid);
	cout << "输入您想要退订的机票的编号：";
	int choice;
	cin >> choice;
	choice -= 1;//Sync
	Ticket tic = Ticket();
	if(tic.Refund(PassengerDatabase[uid].tickets[choice]))cout<<"退票成功！";
	cout << "\n" << "正在返回上级菜单...";
	this_thread::sleep_for(chrono::milliseconds(700));
	return;
}

void UserInterface::ViewMyTicket(int uid) {
	int n = 1;
	for (auto &a : PassengerDatabase[uid].tickets) {
		cout << n++ << "、" << a.LineNo << " " << a.FlightDate << " " << a.Departure << " " << a.Destination << " ";
		cout << a.DepartureTime.tm_hour << ":" << a.DepartureTime.tm_min << " " << a.estDestinationTime.tm_hour << ":" << a.estDestinationTime.tm_min;
		cout << a.Company << " " << a.Airplane << endl;
	}
	cout << "按任意键返回上级菜单";
	char a;
	cin >> a;
	return;
}


