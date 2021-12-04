#pragma once
struct Airport
{
    Airport() = default;
    Airport(const string &a, const string &b, const string &c) :
        City(a), AirportCode(b), AirportName(c) {}
    string City;
    string AirportCode;
    string AirportName;
};

extern vector<Airport>AirportDatabase;

