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

void AirlineBoard::depart(int n)
{
	system("cls");
	cout << AirportDatabase[n].AirportName << endl;
	AirlineInfo info;
	vector<string>line(info.SearchDepart());
}

void AirlineBoard::desti(int n)
{
	system("cls");
	cout << AirportDatabase[n].AirportName << endl;
}
