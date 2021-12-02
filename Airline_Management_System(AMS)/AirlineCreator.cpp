#include "AMS.h"

//LineNo Creator
string LineNoCreator() {
	string LineNo;
	default_random_engine e;
	uniform_int_distribution<unsigned> u(65, 90);
	for (size_t i = 0; i < 2; i++)
	{
		e.seed(GetTickCount64());
		this_thread::sleep_for(chrono::microseconds(274));
		char temp = u(e);
		LineNo += temp;
	}
	uniform_int_distribution<unsigned> u1(0, 9);
	for (size_t i = 0; i < 4; i++)
	{
		e.seed(GetTickCount64());
		this_thread::sleep_for(chrono::microseconds(115));
		LineNo += to_string(u1(e));
	}
	return LineNo;
}

string CompanyCreator() {
	string Company;
}
