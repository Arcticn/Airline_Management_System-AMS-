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
