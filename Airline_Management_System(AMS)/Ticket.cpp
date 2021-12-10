#include "AMS.h"

bool Ticket::Order(int Id, string LineNo, int amount, int diffday, bool ifqueue)
{
	if (diffday > 15)return false;
	int lineid = LineQuickFind[LineNo];
	if (AirlineInfoDatabase[lineid].RemainTickets < amount) {
		for (size_t i = 0; i < amount; i++)
			AirlineInfoDatabase[lineid].Inqueuelist.push(Id);
		return true;
	}
	else {
		for (size_t i = 0; i < amount; i++)
			AirlineInfoDatabase[lineid].Bookedlist.emplace_back(Id);
		AirlineInfoDatabase[lineid].RemainTickets -= amount;
		for (size_t i = 0; i < amount; i++)
			PassengerDatabase[Id].tickets.emplace_back(Ticket(Id, LineNo, CurTime));
		return true;
	}
}

bool Ticket::Refund(Ticket ticket)
{
	auto it1 = find(PassengerDatabase[ticket.Id].tickets.begin(), PassengerDatabase[ticket.Id].tickets.end(), ticket);
	PassengerDatabase[ticket.Id].tickets.erase(it1);
	auto it2 = find(AirlineInfoDatabase[LineQuickFind[ticket.LineNo]].Bookedlist.begin(), AirlineInfoDatabase[LineQuickFind[ticket.LineNo]].Bookedlist.end(), ticket.Id);
	AirlineInfoDatabase[LineQuickFind[ticket.LineNo]].Bookedlist.erase(it2);
	AirlineInfoDatabase[LineQuickFind[ticket.LineNo]].
	return false;
}

size_t Ticket::TicketHash()
{
	auto end = high_resolution_clock::now();
	nano_type diff = end - start;
	std::hash<int>tichash;
	return size_t(tichash(diff.count()));
}


