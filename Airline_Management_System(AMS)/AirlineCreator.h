#pragma once


class AirlineCreator {
	typedef std::chrono::duration<int, std::nano> nano_type;
	std::chrono::high_resolution_clock::time_point start = high_resolution_clock::now();
	Airline Creator();
	string LineNoCreator();
	string CompanyCreator();
	string NameCreator();
};