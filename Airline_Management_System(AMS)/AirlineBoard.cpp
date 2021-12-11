#include"AMS.h"

void AirlineBoard::menu() {
	system("cls");
	int n = 1;
	for (auto &c : AirportDatabase) {
		cout << n++ << "、" << c.AirportName << endl;
	}
	cout << "请输入您想要查看的机场的编号：";
	int choice;
	cin >> choice;
	choice -= 1;//Sync
	cout << "出发大厅电子公示板请按1；候机大厅电子公示板请按2：" ;
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
	cout << "机号"<<'\t'<<"抵达机场"<<'\t'<<"出发时间"<<'\t'<<"预计到达时间" << endl;
	for (auto &c : Line) {
		char buffer1[10],buffer2[10];
		tm t1 = info.SearchDeparTime(c), t2 = info.SearchDesTime(c);
		strftime(buffer1, 10, "%R", &t1);
		strftime(buffer2, 10, "%R", &t2);
		cout << c << '\t'<< info.SearchDesti(c) <<'\t' << '\t' << buffer1;
		cout << '\t' << buffer2<< endl;
	}
	cout << "按任意键返回上级菜单";
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
	cout << "机号" << '\t' << "抵达机场" << '\t' << "出发时间" << '\t' << "预计到达时间" << endl;
	for (auto &c : Line) {
		char buffer1[10], buffer2[10];
		tm t1 = info.SearchDeparTime(c), t2 = info.SearchDesTime(c);
		strftime(buffer1, 10, "%R", &t1);
		strftime(buffer2, 10, "%R", &t2);
		cout << c << '\t' << info.SearchDepart(c) << '\t' << '\t' << buffer1;
		cout << '\t' << buffer2 << endl;
	}
	cout << "按任意键返回上级菜单";
	char a;
	cin >> a;
}

