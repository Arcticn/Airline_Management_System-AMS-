#include "AMS.h"

bool Ticket::Order(int id, string LineNo, int amount, int diffday, bool ifqueue)
{
	if (diffday > 15)return false;
	int lineid = LineQuickFind[LineNo];
	if (AirlineInfoDatabase[lineid].RemainTickets < amount) {
		for (size_t i = 0; i < amount; i++)
			AirlineInfoDatabase[lineid].Inqueuelist.push(id);
		return true;
	}
	else {
		AirlineInfoDatabase[lineid].Bookedlist.insert({ id,amount });
		AirlineInfoDatabase[lineid].RemainTickets -= amount;
		Passenger
		return true;
	}
}
