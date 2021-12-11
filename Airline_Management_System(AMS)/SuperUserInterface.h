#pragma once
struct SuperUserInterface {
public:
	SuperUserInterface() = default;
	void SuperTicketOrder(UserInterface u);
	void SuperAirlineSearch(UserInterface u);
	void SuperTicketDiscard(UserInterface u);
	void SuperViewTicket(UserInterface u);
private:
};