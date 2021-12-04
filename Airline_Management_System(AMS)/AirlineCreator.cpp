#include "AMS.h"

//LineNo Creator
string AirlineCreator::LineNoCreator() {
	auto end = high_resolution_clock::now();
	string LineNo;
	default_random_engine e;
	uniform_int_distribution<unsigned> u(65, 90);
	for (size_t i = 0; i < 2; i++)
	{
		end = high_resolution_clock::now();
		nano_type diff = end - start;
		e.seed(diff.count());
		this_thread::sleep_for(chrono::nanoseconds(3));
		char temp = u(e);
		LineNo += temp;
	}
	uniform_int_distribution<unsigned> u1(0, 9);
	for (size_t i = 0; i < 4; i++)
	{
		end = high_resolution_clock::now();
		nano_type diff = end - start;
		e.seed(diff.count());
		this_thread::sleep_for(chrono::nanoseconds(3));
		LineNo += to_string(u1(e));
	}
	return LineNo;
}
/*
int main() {
	int cnt = 0;
	vector<string>a;
	while (cnt != 3000) {
		a.emplace_back(LineNoCreator());
		cnt++;
		this_thread::sleep_for(chrono::nanoseconds(1));
	}
	auto end = high_resolution_clock::now();
	duration<double>diff = end - start;
	cout << diff.count();
}
*/

string AirlineCreator::CompanyCreator() {
	default_random_engine e;
	uniform_int_distribution<unsigned> u(0,Company.size()-1);
	auto end = high_resolution_clock::now();
	end = high_resolution_clock::now();
	nano_type diff = end - start;
	e.seed(diff.count());
	return Company[u(e)];
}

string AirlineCreator::AirplaneCreator() {
	//temp
	vector<string>company(27);

	string Company;
	default_random_engine e;
	uniform_int_distribution<unsigned> u(0, 26);
	auto end = high_resolution_clock::now();
	end = high_resolution_clock::now();
	nano_type diff = end - start;
	e.seed(diff.count());
	return company[u(e)];
}