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

	string sDate = to_string(Date.tm_year + 1900) + to_string(Date.tm_mon + 1) + to_string(Date.tm_mday);
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
	cout << left << setw(8) << "航班号" << setw(20) << "出发机场" << setw(20) << "目的机场" << setw(8) << "余票量" /* << setw(12) << "起飞时间" << setw(12) << "抵达时间" */ << setw(18) << "航空公司" << setw(12) << "飞机型号" << endl;
	for (size_t i = 0, length = directLine.size(); i < length; i++) {
		cout << n++ << "、" << '\n' << left << setw(8) << directLine[i] << setw(20) << DEPA[choice1 - 1] << setw(20) << DEST[choice2 - 1] << setw(8) << info.SearchRemainTicket(sDate, directLine[i]) /* << info.SearchDeparTime(directLine[i])  << "       " << info.SearchDesTime(directLine[i]) << "       "*/ << setw(18) << info.SearchCompany(directLine[i]) << setw(12) << info.SearchAirplane(directLine[i]) << endl;
		cout << "总里程：" << info.SearchDistance(directLine[i]) << "km" << endl;
	}
	int border = --n; n++;
	for (size_t i = 0, length = indirectLine.size(); i < length; i++)
	{
		cout << n++ << "、" << "(中转)" << endl;
		cout << left << setw(8) << indirectLine[i][0] << setw(20) << info.SearchDepart(indirectLine[i][0]) << setw(20) << info.SearchDesti(indirectLine[i][0]) << setw(8) << info.SearchRemainTicket(sDate, indirectLine[i][0])  /* << info.SearchDeparTime(indirectLine[i][0]) << "       " << info.SearchDesTime(indirectLine[i][0]) << "       " */ << setw(18) << info.SearchCompany(indirectLine[i][0]) << setw(12) << info.SearchAirplane(indirectLine[i][0]) << endl;
		cout << left << setw(8) << indirectLine[i][1] << setw(20) << info.SearchDepart(indirectLine[i][1]) << setw(20) << info.SearchDesti(indirectLine[i][1]) << setw(8) << info.SearchRemainTicket(sDate, indirectLine[i][1])  /* << info.SearchDeparTime(indirectLine[i][1]) << "       " << info.SearchDesTime(indirectLine[i][1]) << "       " */ << setw(18) << info.SearchCompany(indirectLine[i][1]) << setw(12) << info.SearchAirplane(indirectLine[i][1]) << endl;
		cout << "总里程：" << info.SearchDistance(indirectLine[i][0]) + info.SearchDistance(indirectLine[i][1]) << "km" << endl;
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
		if (tic.Order(uid, directLine[choice3], amount, sDate, ifqueue))cout << "购票成功";
		else cout << "购票失败，请重试";
	}
	else if (choice3 > border) {
		if (tic.Order(uid, indirectLine[choice3][0], amount, sDate, ifqueue)
			&& tic.Order(uid, indirectLine[choice3][1], amount, sDate, ifqueue))cout << "购票成功";
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
	Date.tm_year -= 1900;
	Date.tm_mon -= 1;  //Sync with tm

	string sDate = to_string(Date.tm_year + 1900) + to_string(Date.tm_mon + 1) + to_string(Date.tm_mday);
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
	cout << left << setw(8) << "航班号" << setw(20) << "出发机场" << setw(20) << "目的机场" << setw(8) << "余票量" /* << setw(12) << "起飞时间" << setw(12) << "抵达时间" */<< setw(18) << "航空公司" << setw(12) << "飞机型号" << endl;
	for (size_t i = 0, length = directLine.size(); i < length; i++) {
		cout << n++ << "、" << '\n' << left << setw(8) << directLine[i] << setw(20) << DEPA[choice1 - 1] << setw(20) << DEST[choice2 - 1] << setw(8) << info.SearchRemainTicket(sDate, directLine[i]) /* << info.SearchDeparTime(directLine[i])  << "       " << info.SearchDesTime(directLine[i]) << "       "*/ << setw(18) << info.SearchCompany(directLine[i]) << setw(12) << info.SearchAirplane(directLine[i]) << endl;
		cout << "总里程：" << info.SearchDistance(directLine[i]) << "km" << endl;
	}
	int border = --n; n++;
	for (size_t i = 0, length = indirectLine.size(); i < length; i++)
	{
		cout << n++ << "、" << "(中转)" << endl;
		cout << left << setw(8) << indirectLine[i][0] << setw(20) << info.SearchDepart(indirectLine[i][0]) << setw(20) << info.SearchDesti(indirectLine[i][0]) << setw(8) << info.SearchRemainTicket(sDate, indirectLine[i][0])  /* << info.SearchDeparTime(indirectLine[i][0]) << "       " << info.SearchDesTime(indirectLine[i][0]) << "       " */ << setw(18) << info.SearchCompany(indirectLine[i][0]) << setw(12) << info.SearchAirplane(indirectLine[i][0]) << endl;
		cout << left << setw(8) << indirectLine[i][1] << setw(20) << info.SearchDepart(indirectLine[i][1]) << setw(20) << info.SearchDesti(indirectLine[i][1]) << setw(8) << info.SearchRemainTicket(sDate, indirectLine[i][1])  /* << info.SearchDeparTime(indirectLine[i][1]) << "       " << info.SearchDesTime(indirectLine[i][1]) << "       " */ << setw(18) << info.SearchCompany(indirectLine[i][1]) << setw(12) << info.SearchAirplane(indirectLine[i][1]) << endl;
		cout << "总里程：" << info.SearchDistance(indirectLine[i][0]) + info.SearchDistance(indirectLine[i][1]) << "km" << endl;
	}
	cout << "按任意键返回上级菜单";
	char a;
	cin >> a;
	return;
}

void UserInterface::TicketDiscard(int uid) {
	system("cls");
	int n = 1;
	cout << "   " << left << setw(8) << "航班号" << setw(10) << "出发日期" << setw(20) << "出发机场" << setw(20) << "目的机场" << setw(12) << "起飞时间" << setw(12) << "抵达时间" << setw(18) << "航空公司" << setw(12) << "飞机型号" << endl;
	for (auto &a : PassengerDatabase[uid].tickets) {
		auto &line = AirlineInfoDatabase[LineQuickFind[a.LineNo]];
		cout << n++ << "、" << left << setw(8) << a.LineNo << setw(10) << a.FlightDate << setw(20) << line.Departure << setw(20) << line.Destination;
		cout << line.DepartureTime << "       " << line.estDestinationTime << "       ";
		cout << left << setw(18) << line.Company << setw(12) << line.Airplane << endl;
	}
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
	system("cls");
	int n = 1;
	cout <<"   " << left << setw(8) << "航班号" << setw(10) <<"出发日期" << setw(20) << "出发机场" << setw(20) << "目的机场" <<setw(12)<<"起飞时间"<<setw(12) << "抵达时间" << setw(18) << "航空公司" << setw(12) << "飞机型号" << endl;
	for (auto &a : PassengerDatabase[uid].tickets) {
		auto &line = AirlineInfoDatabase[LineQuickFind[a.LineNo]];
		cout << n++ << "、" << left << setw(8) << a.LineNo << setw(10) << a.FlightDate << setw(20) << line.Departure << setw(20) << line.Destination;
		cout << line.DepartureTime << "       " << line.estDestinationTime << "       ";
		cout << left << setw(18) << line.Company << setw(12) << line.Airplane << endl;
	}
	cout << "按任意键返回上级菜单";
	char a;
	cin >> a;
	return;
}


