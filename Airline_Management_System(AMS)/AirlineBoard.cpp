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
	string CurAP= AirportDatabase[ap].AirportName;
	cout << CurAP << endl;
	vector<string>Line;
	for (auto &c : AirlineInfoDatabase) {
		if (c.Departure == CurAP)Line.emplace_back(c.LineNo);
	}
	AirlineInfo info;
	sort(Line.begin(), Line.end(), [&info](const string &s1, const string &s2) {return info.SearchDesTime(s1) < info.SearchDesTime(s2); });
	int n;
	for (auto &c : Line) {
		cout << "����         �ִ����         ����ʱ��         Ԥ�Ƶ���ʱ��" << endl;
		cout << c << "         " << info.SearchDesti(c) << "         " << info.SearchDeparTime(c).tm_hour << ":" << info.SearchDeparTime(c).tm_min;
		cout << "           " << info.SearchDesTime(c).tm_hour << ":" << info.SearchDesTime(c).tm_min << endl;
	}
}

void AirlineBoard::desti(int ap)
{
	system("cls");
	string CurAP = AirportDatabase[ap].AirportName;
	cout << CurAP << endl;
	vector<string>Line;
	for (auto &c : AirlineInfoDatabase) {
		if (c.Destination == CurAP)Line.emplace_back(c.LineNo);
	}
	AirlineInfo info;
	sort(Line.begin(), Line.end(), [&info](const string &s1, const string &s2) {return info.SearchDeparTime(s1) < info.SearchDeparTime(s2); });
	int n;
	for (auto &c : Line) {
		cout << "����         ��������         ����ʱ��         Ԥ�Ƶ���ʱ��"<<endl;
		cout << c << "         " << info.SearchDepart(c) << "         " << info.SearchDeparTime(c).tm_hour << ":" << info.SearchDeparTime(c).tm_min;
		cout << "           " << info.SearchDesTime(c).tm_hour << ":" << info.SearchDesTime(c).tm_min << endl;
	}
}
