#include "AMS.h"

vector<string> AirlineInfo::SearchLine(string depart, string desti)
{
	vector<string>ans,temp;
	for (auto c : AirlineInfoDatabase) {

		if (c.Destination == desti) {
			temp.emplace_back(LineNo);
			if (c.Departure == depart)
				ans.emplace_back(LineNo);
		}
	}
	

	return ans;
}
