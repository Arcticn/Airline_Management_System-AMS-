#pragma once
struct UserInterface {
public:
	UserInterface(int uid):
		uid(uid){}
	int uid;
	void TicketOrder();
	void AirlineSearch();
	void TicketDiscard();
	void ViewMyTicket();
private:
};