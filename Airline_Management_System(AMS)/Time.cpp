#include "AMS.h"

bool operator<(const tm &lhs, const tm &rhs) {
	if (lhs.tm_wday < rhs.tm_wday)return true;
	else if (lhs.tm_wday > rhs.tm_wday)return false;

	if (lhs.tm_hour < rhs.tm_hour)return true;
	else if (lhs.tm_hour > rhs.tm_hour)return false;

	if (lhs.tm_min < rhs.tm_min)return true;
	else if (lhs.tm_min > rhs.tm_min)return false;

	return false;
}//strict weak ordering

tm &operator+=(const tm &lhs,int rhs)
{
	tm temp=lhs;
	//convert to time_t
	time_t t= mktime(&temp);
	//convert to system_clock::time point
	auto tp = system_clock::from_time_t(t);
	//add time duration
	duration<int, std::ratio<60 * 60 * 24>> day(rhs);
	tp = tp + day;
	//convert to time_t
	auto tt = system_clock::to_time_t(tp);
	tm *ttt;
	//convert to tm*
	ttt = localtime(&tt);
	tm ans;
	ans.tm_year = ttt->tm_year;
	ans.tm_mon = ttt->tm_mon;
	ans.tm_mday = ttt->tm_mday;
	return ans;
}
