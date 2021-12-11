#pragma once
struct UserInterface {
public:
	UserInterface() = default;
	UserInterface(int uid):
		uid(uid){}
	int uid;

	void TicketOrder(int uid);
	void AirlineSearch();
	void TicketDiscard(int uid);
	void ViewMyTicket(int uid);
	friend void SuperUserInterface::SuperTicketOrder(UserInterface u);
	friend void SuperUserInterface::SuperAirlineSearch(UserInterface u);
	friend void SuperUserInterface::SuperTicketDiscard(UserInterface u);
	friend void SuperUserInterface::SuperViewTicket(UserInterface u);
private:
};