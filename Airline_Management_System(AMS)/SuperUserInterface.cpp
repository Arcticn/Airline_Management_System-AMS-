#include "AMS.h"

void SuperUserInterface::SuperTicketOrder()
{
	UserInterface u;
	cout << "��������û���UID��";
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
	cout << "��������û���UID��";
	int uid;
	cin >> uid;
	u.TicketDiscard(uid);
}

void SuperUserInterface::SuperViewTicket()
{
	UserInterface u;
	cout << "��������û���UID��";
	int uid;
	cin >> uid;
	u.ViewMyTicket(uid);
}
