#include "AMS.h"

tm CurTime={0};
time_t rawtime{};

void SyncTime() {
	while (true) {
		time(&rawtime);
		localtime_s(&CurTime, &rawtime);
		this_thread::sleep_for(chrono::seconds(3));
	}
}

void RefreshLine()
{
	int day = 0;
	while (true) {
		if (day != CurTime.tm_mday) {
			tm temp = CurTime;
			for (size_t i = 0; i <= 15; i++)
			{
				string date = to_string(temp.tm_year) + to_string(temp.tm_mon) + to_string(temp.tm_mday);
				for (auto &a : AirlineInfoDatabase) {
					a.RemainTickets.insert({date,a.Maxpassenger});
				}
				temp += 1;
			}
			day = CurTime.tm_mday;
		}
		this_thread::sleep_for(chrono::seconds(10));
	}
	return;
}

bool operator<(const tm &lhs, const tm &rhs) {
	if (lhs.tm_wday < rhs.tm_wday)return true;
	else if (lhs.tm_wday > rhs.tm_wday)return false;

	if (lhs.tm_hour < rhs.tm_hour)return true;
	else if (lhs.tm_hour > rhs.tm_hour)return false;

	if (lhs.tm_min < rhs.tm_min)return true;
	else if (lhs.tm_min > rhs.tm_min)return false;

	return false;
}//strict weak ordering

tm& operator+=(const tm &lhs,int rhs)
{
	tm temp=lhs;
	time_t t= mktime(&temp);
	auto tp = system_clock::from_time_t(t);
	days_type day(rhs);
	tp = tp + day;
	auto tt = system_clock::to_time_t(tp);
	tm ttt={0};
	localtime_s(&ttt,&tt);
	tm a = { 0 };
	tm* ans = &a;
	ans->tm_year = ttt.tm_year;
	ans->tm_mon = ttt.tm_mon;
	ans->tm_mday = ttt.tm_mday;
	return *ans;
}

int operator-(tm &lhs, tm &rhs)
{
	time_t templ = mktime(&lhs);
	time_t tempr = mktime(&rhs);
	auto l = system_clock::from_time_t(templ);
	auto r = system_clock::from_time_t(tempr);
	system_clock::duration d = l-r;
	days_type diff = duration_cast<days_type> (d);
	return diff.count();
}
