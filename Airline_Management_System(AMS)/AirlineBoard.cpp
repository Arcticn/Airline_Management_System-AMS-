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
	cout << "����"<<'\t'<<"�ִ����"<<'\t'<<"����ʱ��"<<'\t'<<"Ԥ�Ƶ���ʱ��" << endl;
	for (auto &c : Line) {
		char buffer1[10],buffer2[10];
		tm t1 = info.SearchDeparTime(c), t2 = info.SearchDesTime(c);
		strftime(buffer1, 10, "%R", &t1);
		strftime(buffer2, 10, "%R", &t2);
		cout << c << '\t'<< info.SearchDesti(c) <<'\t' << '\t' << buffer1;
		cout << '\t' << buffer2<< endl;
	}
	cout << "������������ϼ��˵�";
	char a;
	cin >> a;
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
	cout << "����" << '\t' << "�ִ����" << '\t' << "����ʱ��" << '\t' << "Ԥ�Ƶ���ʱ��" << endl;
	for (auto &c : Line) {
		char buffer1[10], buffer2[10];
		tm t1 = info.SearchDeparTime(c), t2 = info.SearchDesTime(c);
		strftime(buffer1, 10, "%R", &t1);
		strftime(buffer2, 10, "%R", &t2);
		cout << c << '\t' << info.SearchDepart(c) << '\t' << '\t' << buffer1;
		cout << '\t' << buffer2 << endl;
	}
	cout << "������������ϼ��˵�";
	char a;
	cin >> a;
}

