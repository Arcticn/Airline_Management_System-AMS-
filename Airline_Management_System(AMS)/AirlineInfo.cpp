#include "AMS.h"

vector<string> AirlineInfo::SearchLine(string depart, string desti)
{
	vector<string>ans;
	for (auto c : AirlineInfoDatabase) {
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
	for (auto c : AirlineInfoDatabase) {
		if (c.Departure == depart && c.Destination != desti)
			first.emplace_back(c.LineNo);
	}
	for (auto c : first) {
		string t = SearchDesti(c);
		vector<string>tt(SearchLine(t, desti));
		for (auto d : tt) {
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

void AirlineInfo::QueueOut(int diffday)
{
	int id=Inqueuelist.front();
	Ticket tic;
	tic.Order(id, this->LineNo, 1, diffday, 1);
}
