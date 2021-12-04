#pragma once
struct Airport
{
    Airport() = default;
    Airport(const string &a, const string &b, const string &c,double lat,double lng) :
        City(a), AirportCode(b), AirportName(c),Latitude(lat),Longitude(lng) {}
    string City;
    string AirportCode;
    string AirportName;
    double Latitude;
    double Longitude;
};



