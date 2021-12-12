#include "AMS.h"

void UserInterface::TicketOrder(int uid) {
	system("cls");
	AirlineInfo info = AirlineInfo();
	string Departure, Destination;
	char buffer[80];
	strftime(buffer, 80, "������ %F %A", &CurTime);
	cout << buffer << endl;
	tm Date;
	//Check Date
	cout << "���������ĳ������ڣ�15�����ڣ���" << '\n' << "�꣺";
	cin >> Date.tm_year;
	cout << "�£�";
	cin >> Date.tm_mon;
	cout << "�գ�";
	cin >> Date.tm_mday;
	Date.tm_year -= 1900;
	Date.tm_mon -= 1;  //Sync with tm

	string sDate = to_string(Date.tm_year + 1900) + to_string(Date.tm_mon + 1) + to_string(Date.tm_mday);
	cout << "���������ĳ���ʡ�ݣ�";
	cin >> Departure;
	int n = 1;
	vector<string>DEPA;
	for (auto it = AirportDatabase.begin(); it != AirportDatabase.end(); it++)
	{
		if ((*it).City == Departure) {
			DEPA.emplace_back((*it).AirportName);
			cout << n++ << "��" << (*it).AirportName << endl;
		}
	}
	int choice1;
	cout << "���������ĳ���������";
	cin >> choice1;
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
	//Search Line
	vector<string>directLine(info.SearchLine(DEPA[choice1 - 1], DEST[choice2 - 1]));
	vector<vector<string>>indirectLine(info.SearchIndirectLine(DEPA[choice1 - 1], DEST[choice2 - 1]));
	sort(indirectLine.begin(), indirectLine.end(), [&info](const vector<string> &v1, const vector<string> &v2) {return (info.SearchDistance(v1[0]) + info.SearchDistance(v1[1])) < (info.SearchDistance(v2[0]) + info.SearchDistance(v2[1])); });
	n = 1;
	cout << left << setw(8) << "�����" << setw(20) << "��������" << setw(20) << "Ŀ�Ļ���" << setw(8) << "��Ʊ��" /* << setw(12) << "���ʱ��" << setw(12) << "�ִ�ʱ��" */ << setw(18) << "���չ�˾" << setw(12) << "�ɻ��ͺ�" << endl;
	for (size_t i = 0, length = directLine.size(); i < length; i++) {
		cout << n++ << "��" << '\n' << left << setw(8) << directLine[i] << setw(20) << DEPA[choice1 - 1] << setw(20) << DEST[choice2 - 1] << setw(8) << info.SearchRemainTicket(sDate, directLine[i]) /* << info.SearchDeparTime(directLine[i])  << "       " << info.SearchDesTime(directLine[i]) << "       "*/ << setw(18) << info.SearchCompany(directLine[i]) << setw(12) << info.SearchAirplane(directLine[i]) << endl;
		cout << "����̣�" << info.SearchDistance(directLine[i]) << "km" << endl;
	}
	int border = --n; n++;
	for (size_t i = 0, length = indirectLine.size(); i < length; i++)
	{
		cout << n++ << "��" << "(��ת)" << endl;
		cout << left << setw(8) << indirectLine[i][0] << setw(20) << info.SearchDepart(indirectLine[i][0]) << setw(20) << info.SearchDesti(indirectLine[i][0]) << setw(8) << info.SearchRemainTicket(sDate, indirectLine[i][0])  /* << info.SearchDeparTime(indirectLine[i][0]) << "       " << info.SearchDesTime(indirectLine[i][0]) << "       " */ << setw(18) << info.SearchCompany(indirectLine[i][0]) << setw(12) << info.SearchAirplane(indirectLine[i][0]) << endl;
		cout << left << setw(8) << indirectLine[i][1] << setw(20) << info.SearchDepart(indirectLine[i][1]) << setw(20) << info.SearchDesti(indirectLine[i][1]) << setw(8) << info.SearchRemainTicket(sDate, indirectLine[i][1])  /* << info.SearchDeparTime(indirectLine[i][1]) << "       " << info.SearchDesTime(indirectLine[i][1]) << "       " */ << setw(18) << info.SearchCompany(indirectLine[i][1]) << setw(12) << info.SearchAirplane(indirectLine[i][1]) << endl;
		cout << "����̣�" << info.SearchDistance(indirectLine[i][0]) + info.SearchDistance(indirectLine[i][1]) << "km" << endl;
	}
	cout << "����������ѡ��";
	int choice3;
	cin >> choice3;
	choice3 -= 1; //ͬ�����
	Ticket tic = Ticket();
	cout << "����������Ҫ����Ļ�Ʊ��Ŀ���������ߣ���";
	int amount = 1;
	cin >> amount;
	cout << "�Ƿ�Ը��򲹹�Ʊ����Y/N��:";
	char idea;
	cin >> idea;
	bool ifqueue;
	if (idea == 'Y') ifqueue = 1;
	else ifqueue = 0;
	if (choice3 <= border) {
		if (tic.Order(uid, directLine[choice3], amount, sDate, ifqueue))cout << "��Ʊ�ɹ�";
		else cout << "��Ʊʧ�ܣ�������";
	}
	else if (choice3 > border) {
		if (tic.Order(uid, indirectLine[choice3][0], amount, sDate, ifqueue)
			&& tic.Order(uid, indirectLine[choice3][1], amount, sDate, ifqueue))cout << "��Ʊ�ɹ�";
		else cout << "��Ʊʧ�ܣ�������";
	}
	cout << "\n" << "���ڷ����ϼ��˵�...";
	this_thread::sleep_for(chrono::milliseconds(700));
	return;
}

void UserInterface::AirlineSearch() {
	system("cls");
	AirlineInfo info = AirlineInfo();
	string Departure, Destination;
	char buffer[80];
	strftime(buffer, 80, "������ %F %A", &CurTime);
	cout << buffer << endl;
	tm Date;
	//Check Date
	cout << "���������ĳ������ڣ�15�����ڣ���" << '\n' << "�꣺";
	cin >> Date.tm_year;
	cout << "�£�";
	cin >> Date.tm_mon;
	cout << "�գ�";
	cin >> Date.tm_mday;
	Date.tm_year -= 1900;
	Date.tm_mon -= 1;  //Sync with tm

	string sDate = to_string(Date.tm_year + 1900) + to_string(Date.tm_mon + 1) + to_string(Date.tm_mday);
	cout << "���������ĳ���ʡ�ݣ�";
	cin >> Departure;
	int n = 1;
	vector<string>DEPA;
	for (auto it = AirportDatabase.begin(); it != AirportDatabase.end(); it++)
	{
		if ((*it).City == Departure) {
			DEPA.emplace_back((*it).AirportName);
			cout << n++ << "��" << (*it).AirportName << endl;
		}
	}
	int choice1;
	cout << "���������ĳ���������";
	cin >> choice1;
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
	//Search Line
	vector<string>directLine(info.SearchLine(DEPA[choice1 - 1], DEST[choice2 - 1]));
	vector<vector<string>>indirectLine(info.SearchIndirectLine(DEPA[choice1 - 1], DEST[choice2 - 1]));
	sort(indirectLine.begin(), indirectLine.end(), [&info](const vector<string> &v1, const vector<string> &v2) {return (info.SearchDistance(v1[0]) + info.SearchDistance(v1[1])) < (info.SearchDistance(v2[0]) + info.SearchDistance(v2[1])); });
	n = 1;
	cout << left << setw(8) << "�����" << setw(20) << "��������" << setw(20) << "Ŀ�Ļ���" << setw(8) << "��Ʊ��" /* << setw(12) << "���ʱ��" << setw(12) << "�ִ�ʱ��" */<< setw(18) << "���չ�˾" << setw(12) << "�ɻ��ͺ�" << endl;
	for (size_t i = 0, length = directLine.size(); i < length; i++) {
		cout << n++ << "��" << '\n' << left << setw(8) << directLine[i] << setw(20) << DEPA[choice1 - 1] << setw(20) << DEST[choice2 - 1] << setw(8) << info.SearchRemainTicket(sDate, directLine[i]) /* << info.SearchDeparTime(directLine[i])  << "       " << info.SearchDesTime(directLine[i]) << "       "*/ << setw(18) << info.SearchCompany(directLine[i]) << setw(12) << info.SearchAirplane(directLine[i]) << endl;
		cout << "����̣�" << info.SearchDistance(directLine[i]) << "km" << endl;
	}
	int border = --n; n++;
	for (size_t i = 0, length = indirectLine.size(); i < length; i++)
	{
		cout << n++ << "��" << "(��ת)" << endl;
		cout << left << setw(8) << indirectLine[i][0] << setw(20) << info.SearchDepart(indirectLine[i][0]) << setw(20) << info.SearchDesti(indirectLine[i][0]) << setw(8) << info.SearchRemainTicket(sDate, indirectLine[i][0])  /* << info.SearchDeparTime(indirectLine[i][0]) << "       " << info.SearchDesTime(indirectLine[i][0]) << "       " */ << setw(18) << info.SearchCompany(indirectLine[i][0]) << setw(12) << info.SearchAirplane(indirectLine[i][0]) << endl;
		cout << left << setw(8) << indirectLine[i][1] << setw(20) << info.SearchDepart(indirectLine[i][1]) << setw(20) << info.SearchDesti(indirectLine[i][1]) << setw(8) << info.SearchRemainTicket(sDate, indirectLine[i][1])  /* << info.SearchDeparTime(indirectLine[i][1]) << "       " << info.SearchDesTime(indirectLine[i][1]) << "       " */ << setw(18) << info.SearchCompany(indirectLine[i][1]) << setw(12) << info.SearchAirplane(indirectLine[i][1]) << endl;
		cout << "����̣�" << info.SearchDistance(indirectLine[i][0]) + info.SearchDistance(indirectLine[i][1]) << "km" << endl;
	}
	cout << "������������ϼ��˵�";
	char a;
	cin >> a;
	return;
}

void UserInterface::TicketDiscard(int uid) {
	system("cls");
	int n = 1;
	cout << "   " << left << setw(8) << "�����" << setw(10) << "��������" << setw(20) << "��������" << setw(20) << "Ŀ�Ļ���" << setw(12) << "���ʱ��" << setw(12) << "�ִ�ʱ��" << setw(18) << "���չ�˾" << setw(12) << "�ɻ��ͺ�" << endl;
	for (auto &a : PassengerDatabase[uid].tickets) {
		auto &line = AirlineInfoDatabase[LineQuickFind[a.LineNo]];
		cout << n++ << "��" << left << setw(8) << a.LineNo << setw(10) << a.FlightDate << setw(20) << line.Departure << setw(20) << line.Destination;
		cout << line.DepartureTime << "       " << line.estDestinationTime << "       ";
		cout << left << setw(18) << line.Company << setw(12) << line.Airplane << endl;
	}
	cout << "��������Ҫ�˶��Ļ�Ʊ�ı�ţ�";
	int choice;
	cin >> choice;
	choice -= 1;//Sync
	Ticket tic = Ticket();
	if(tic.Refund(PassengerDatabase[uid].tickets[choice]))cout<<"��Ʊ�ɹ���";
	cout << "\n" << "���ڷ����ϼ��˵�...";
	this_thread::sleep_for(chrono::milliseconds(700));
	return;
}

void UserInterface::ViewMyTicket(int uid) {
	system("cls");
	int n = 1;
	cout <<"   " << left << setw(8) << "�����" << setw(10) <<"��������" << setw(20) << "��������" << setw(20) << "Ŀ�Ļ���" <<setw(12)<<"���ʱ��"<<setw(12) << "�ִ�ʱ��" << setw(18) << "���չ�˾" << setw(12) << "�ɻ��ͺ�" << endl;
	for (auto &a : PassengerDatabase[uid].tickets) {
		auto &line = AirlineInfoDatabase[LineQuickFind[a.LineNo]];
		cout << n++ << "��" << left << setw(8) << a.LineNo << setw(10) << a.FlightDate << setw(20) << line.Departure << setw(20) << line.Destination;
		cout << line.DepartureTime << "       " << line.estDestinationTime << "       ";
		cout << left << setw(18) << line.Company << setw(12) << line.Airplane << endl;
	}
	cout << "������������ϼ��˵�";
	char a;
	cin >> a;
	return;
}


