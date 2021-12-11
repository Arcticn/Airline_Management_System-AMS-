#include "AMS.h"

vector<string> AirlineInfo::SearchLine(string depart, string desti)
{
	vector<string>ans;
	for (auto &c : AirlineInfoDatabase) {
		if (c.Destination == desti)
			if (c.Departure == depart)
				ans.emplace_back(c.LineNo);
	}
	return ans;
}

vector<vector<string>> AirlineInfo::SearchIndirectLine(string depart, string desti)
{
	vector<string> first;
	vector<vector<string>>ans;
	vector<string>temp;
	for (auto &c : AirlineInfoDatabase) {
		if (c.Departure == depart && c.Destination != desti)
			first.emplace_back(c.LineNo);
	}
	for (auto &c : first) {
		string t = SearchDesti(c);
		vector<string>tt(SearchLine(t, desti));
		for (auto &d : tt) {
			temp.clear();
			temp.emplace_back(c);
			temp.emplace_back(d);
			ans.emplace_back(temp);
		}
	}
	return ans;
}

string AirlineInfo::SearchDepart(string LineNo)
{
	return AirlineInfoDatabase[LineQuickFind[LineNo]].Departure;
}

string AirlineInfo::SearchDesti(string LineNo)
{
	return AirlineInfoDatabase[LineQuickFind[LineNo]].Destination;
}

double AirlineInfo::SearchDistance(string LineNo)
{
	return AirlineInfoDatabase[LineQuickFind[LineNo]].Distance;
}

int AirlineInfo::SearchRemainTicket(string date,string LineNo)
{
	return AirlineInfoDatabase[LineQuickFind[LineNo]].RemainTickets[date];
}

tm AirlineInfo::SearchDeparTime(string LineNo)
{
	return AirlineInfoDatabase[LineQuickFind[LineNo]].DepartureTime;
}

tm AirlineInfo::SearchDesTime(string LineNo)
{
	return AirlineInfoDatabase[LineQuickFind[LineNo]].estDestinationTime;
}

void AirlineInfo::QueueOut(string date)
{
	int id=Inqueuelist[date].front();
	Ticket tic;
	tic.Order(id, this->LineNo, 1, date, 1);
	Inqueuelist[date].pop();
}
