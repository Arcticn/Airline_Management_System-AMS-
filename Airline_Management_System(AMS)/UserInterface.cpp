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
	int diffday = Date - CurTime;
	string sDate = to_string(Date.tm_year+1900) + to_string(Date.tm_mon+1) + to_string(Date.tm_mday);
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
	for (size_t i = 0, length = directLine.size(); i < length; i++)
		cout << n++ << "��" << '\n' << directLine[i] << " " << DEPA[choice1 - 1] << " " << DEST[choice2 - 1] << " " << endl;
	int border = --n;
	for (size_t i = 0, length = indirectLine.size(); i < length; i++)
	{
		cout << n++ << "��" << endl;
		cout << indirectLine[i][0] << " " << info.SearchDepart(indirectLine[i][0]) << " " << info.SearchDesti(indirectLine[i][0]) << "(��ת) " << "��Ʊ��" << info.SearchRemainTicket(sDate,indirectLine[i][0]) << endl;
		cout << indirectLine[i][1] << " " << info.SearchDepart(indirectLine[i][1]) << "(��ת) " << info.SearchDesti(indirectLine[i][1]) << " " << "��Ʊ��" << info.SearchRemainTicket(sDate,indirectLine[i][1]) << endl;

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
		if (tic.Order(uid, directLine[choice3], amount, diffday, ifqueue))cout << "��Ʊ�ɹ�";
		else cout << "��Ʊʧ�ܣ�������";
	}
	else if (choice3 > border) {
		if(tic.Order(uid, indirectLine[choice3][0], amount, diffday, ifqueue)
		&& tic.Order(uid, indirectLine[choice3][1], amount, diffday, ifqueue))cout << "��Ʊ�ɹ�";
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
	int diffday = Date - CurTime;
	string sDate = to_string(Date.tm_year) + to_string(Date.tm_mon) + to_string(Date.tm_mday);
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
	for (size_t i = 0, length = directLine.size(); i < length; i++)
		cout << n++ << "��" << '\n' << directLine[i] << " " << DEPA[choice1 - 1] << " " << DEST[choice2 - 1] << " " << endl;
	int border = --n;
	for (size_t i = 0, length = indirectLine.size(); i < length; i++)
	{
		cout << n++ << "��" << endl;
		cout << indirectLine[i][0] << " " << info.SearchDepart(indirectLine[i][0]) << " " << info.SearchDesti(indirectLine[i][0]) << "(��ת) " << "��Ʊ��" << info.SearchRemainTicket(sDate, indirectLine[i][0]) << endl;
		cout << indirectLine[i][1] << " " << info.SearchDepart(indirectLine[i][1]) << "(��ת) " << info.SearchDesti(indirectLine[i][1]) << " " << "��Ʊ��" << info.SearchRemainTicket(sDate, indirectLine[i][1]) << endl;
	}
	cout << "������������ϼ��˵�";
	char a;
	cin >> a;
	return;
}

void UserInterface::TicketDiscard(int uid) {
	ViewMyTicket(uid);
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
	int n = 1;
	for (auto &a : PassengerDatabase[uid].tickets) {
		cout << n++ << "��" << a.LineNo << " " << a.FlightDate << " " << a.Departure << " " << a.Destination << " ";
		cout << a.DepartureTime.tm_hour << ":" << a.DepartureTime.tm_min << " " << a.estDestinationTime.tm_hour << ":" << a.estDestinationTime.tm_min;
		cout << a.Company << " " << a.Airplane << endl;
	}
	cout << "������������ϼ��˵�";
	char a;
	cin >> a;
	return;
}


