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
	string CurAP = AirportDatabase[ap].AirportName;
	vector<string>Line;
	for (auto &c : AirlineInfoDatabase) {
		if (c.Departure == CurAP)Line.emplace_back(c.LineNo);
	}
	AirlineInfo info;
	sort(Line.begin(), Line.end(), [&info](const string &s1, const string &s2) {return info.SearchDesTime(s1) < info.SearchDesTime(s2); });
	char buffer[80];
	strftime(buffer, 80, "今天是 %F %A", &CurTime);
	cout << buffer << endl;
	tm Date;
	cout << "请输入想要查看的日期（15天以内）：" << '\n' << "年：";
	cin >> Date.tm_year;
	cout << "月：";
	cin >> Date.tm_mon;
	cout << "日：";
	cin >> Date.tm_mday;
	string date = to_string(Date.tm_year) + to_string(Date.tm_mon) + to_string(Date.tm_mday);
	while (true) {
		system("cls");
		cout << CurAP << endl;
		cout << "机号" << '\t' << left << setw(20) << "抵达机场" << '\t' << "出发时间" << '\t' << "预计到达时间" << '\t' << "余票" << endl;
		for (auto &c : Line) {
			char buffer1[10], buffer2[10];
			tm t1 = info.SearchDeparTime(c), t2 = info.SearchDesTime(c);
			strftime(buffer1, 10, "%R", &t1);
			strftime(buffer2, 10, "%R", &t2);
			cout << c << '\t' << left << setw(20) << info.SearchDesti(c) << '\t' << buffer1;
			cout << '\t' << '\t' << buffer2 << '\t' <<'\t' << info.SearchRemainTicket(date, c)<<'\t'<<'\t' << endl;
		}
		cout << "按0返回上级菜单，按1刷新";
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
	strftime(buffer, 80, "今天是 %F %A", &CurTime);
	cout << buffer << endl;
	tm Date;
	cout << "请输入想要查看的日期（15天以内）：" << '\n' << "年：";
	cin >> Date.tm_year;
	cout << "月：";
	cin >> Date.tm_mon;
	cout << "日：";
	cin >> Date.tm_mday;
	string date = to_string(Date.tm_year) + to_string(Date.tm_mon) + to_string(Date.tm_mday);
	while (true) {
		system("cls");
		cout << CurAP << endl;
		string date = to_string(CurTime.tm_year+1900) + to_string(CurTime.tm_mon+1) + to_string(CurTime.tm_mday);
		cout << "机号" << '\t' << left << setw(20) << "抵达机场" << '\t' << "出发时间" << '\t' << "预计到达时间" <<'\t'<<"余票" << endl;
		for (auto &c : Line) {
			char buffer1[10], buffer2[10];
			tm t1 = info.SearchDeparTime(c), t2 = info.SearchDesTime(c);
			strftime(buffer1, 10, "%R", &t1);
			strftime(buffer2, 10, "%R", &t2);
			cout << c << '\t' << left << setw(20) << info.SearchDepart(c) << '\t' << buffer1;
			cout << '\t' << '\t' << buffer2 <<'\t'<<info.SearchRemainTicket(date,c) << endl;
		}
		cout << "按0返回上级菜单，按1刷新";
		char a;
		cin >> a;
		if (a == '0')break;
	}
}

