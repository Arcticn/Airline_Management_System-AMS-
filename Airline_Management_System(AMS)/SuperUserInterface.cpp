#include "AMS.h"

void SuperUserInterface::SuperTicketOrder()
{
	UserInterface u;
	cout << "请输入该用户的UID：";
	int uid;
	cin >> uid;
	u.TicketOrder(uid);
}

void SuperUserInterface::SuperAirlineSearch()
{
	UserInterface u;
	u.AirlineSearch();
}

void SuperUserInterface::SuperTicketDiscard()
{
	UserInterface u;
	cout << "请输入该用户的UID：";
	int uid;
	cin >> uid;
	u.TicketDiscard(uid);
}

void SuperUserInterface::SuperViewTicket()
{
	UserInterface u;
	cout << "请输入该用户的UID：";
	int uid;
	cin >> uid;
	u.ViewMyTicket(uid);
}
