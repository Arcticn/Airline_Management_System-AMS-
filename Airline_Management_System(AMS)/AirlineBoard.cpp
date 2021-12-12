#include"AMS.h"

void AirlineBoard::menu() {
	system("cls");
	int n = 1;
	for (auto &c : AirportDatabase) {
		cout << n++ << "��" << c.AirportName << endl;
	}
	cout << "����������Ҫ�鿴�Ļ����ı�ţ�";
	int choice;
	cin >> choice;
	choice -= 1;//Sync
	cout << "�����������ӹ�ʾ���밴1������������ӹ�ʾ���밴2��" ;
	int choice2;
	cin >> choice2;
	if (choice2 == 1)depart(choice);
	else if (choice2 == 2)desti(choice);
}

void AirlineBoard::depart(int ap)
{
	system("cls");
	string CurAP = AirportDatabase[ap].AirportName;
	vector<string>Line;
	for (auto &c : AirlineInfoDatabase) {
		if (c.Departure == CurAP)Line.emplace_back(c.LineNo);
	}
	AirlineInfo info;
	sort(Line.begin(), Line.end(), [&info](const string &s1, const string &s2) {return info.SearchDesTime(s1) < info.SearchDesTime(s2); });
	char buffer[80];
	strftime(buffer, 80, "������ %F %A", &CurTime);
	cout << buffer << endl;
	tm Date;
	cout << "��������Ҫ�鿴�����ڣ�15�����ڣ���" << '\n' << "�꣺";
	cin >> Date.tm_year;
	cout << "�£�";
	cin >> Date.tm_mon;
	cout << "�գ�";
	cin >> Date.tm_mday;
	string date = to_string(Date.tm_year) + to_string(Date.tm_mon) + to_string(Date.tm_mday);
	while (true) {
		system("cls");
		cout << CurAP << endl;
		cout << "����" << '\t' << left << setw(20) << "�ִ����" << '\t' << "����ʱ��" << '\t' << "Ԥ�Ƶ���ʱ��" << '\t' << "��Ʊ" << endl;
		for (auto &c : Line) {
			char buffer1[10], buffer2[10];
			tm t1 = info.SearchDeparTime(c), t2 = info.SearchDesTime(c);
			strftime(buffer1, 10, "%R", &t1);
			strftime(buffer2, 10, "%R", &t2);
			cout << c << '\t' << left << setw(20) << info.SearchDesti(c) << '\t' << buffer1;
			cout << '\t' << '\t' << buffer2 << '\t' <<'\t' << info.SearchRemainTicket(date, c)<<'\t'<<'\t' << endl;
		}
		cout << "��0�����ϼ��˵�����1ˢ��";
		char a;
		cin >> a;
		if (a == '0')break;
	}
}

void AirlineBoard::desti(int ap)
{
	system("cls");
	string CurAP = AirportDatabase[ap].AirportName;
	vector<string>Line;
	for (auto &c : AirlineInfoDatabase) {
		if (c.Destination == CurAP)Line.emplace_back(c.LineNo);
	}
	AirlineInfo info;
	sort(Line.begin(), Line.end(), [&info](const string &s1, const string &s2) {return info.SearchDeparTime(s1) < info.SearchDeparTime(s2); });
	char buffer[80];
	strftime(buffer, 80, "������ %F %A", &CurTime);
	cout << buffer << endl;
	tm Date;
	cout << "��������Ҫ�鿴�����ڣ�15�����ڣ���" << '\n' << "�꣺";
	cin >> Date.tm_year;
	cout << "�£�";
	cin >> Date.tm_mon;
	cout << "�գ�";
	cin >> Date.tm_mday;
	string date = to_string(Date.tm_year) + to_string(Date.tm_mon) + to_string(Date.tm_mday);
	while (true) {
		system("cls");
		cout << CurAP << endl;
		string date = to_string(CurTime.tm_year+1900) + to_string(CurTime.tm_mon+1) + to_string(CurTime.tm_mday);
		cout << "����" << '\t' << left << setw(20) << "�ִ����" << '\t' << "����ʱ��" << '\t' << "Ԥ�Ƶ���ʱ��" <<'\t'<<"��Ʊ" << endl;
		for (auto &c : Line) {
			char buffer1[10], buffer2[10];
			tm t1 = info.SearchDeparTime(c), t2 = info.SearchDesTime(c);
			strftime(buffer1, 10, "%R", &t1);
			strftime(buffer2, 10, "%R", &t2);
			cout << c << '\t' << left << setw(20) << info.SearchDepart(c) << '\t' << buffer1;
			cout << '\t' << '\t' << buffer2 <<'\t'<<info.SearchRemainTicket(date,c) << endl;
		}
		cout << "��0�����ϼ��˵�����1ˢ��";
		char a;
		cin >> a;
		if (a == '0')break;
	}
}

