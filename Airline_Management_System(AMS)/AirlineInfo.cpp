#include "AMS.h"

vector<string> AirlineInfo::SearchLine(string depart, string desti)
{
	vector<string>ans;
	for (auto c : AirlineInfoDatabase) {
		if (c.Destination == desti)
			if (c.Departure == depart)
				ans.emplace_back(c.LineNo);
		return ans;
	}
}

vector<string> AirlineInfo::SearchIndirectLine(string depart, string desti)
{
	vector<string>ans, temp;
	for (auto c : AirlineInfoDatabase) {
		if (c.Departure == depart && c.Destination != desti)
			temp.emplace_back(c.LineNo);
	}
	for (auto c : temp) {
		string t = SearchDesti(c);
		vector<string>tt(SearchLine(t, desti));
		for (auto d : tt) {
			string e = c;
			e += " ";
			e += d;
			ans.emplace_back(e);
		}
	}
	return ans;
}

string AirlineInfo::SearchDepart(string LineNo)
{
	string ans;
	for (auto c : AirlineInfoDatabase) {
		if (c.LineNo == LineNo) {
			ans = c.Departure;
			break;
		}
	}
	return ans;
}

string AirlineInfo::SearchDesti(string LinNo)
{
	string ans;
	for (auto c : AirlineInfoDatabase) {
		if (c.LineNo == LineNo) {
			ans = c.Destination;
			break;
		}
	}
	return ans;
}
