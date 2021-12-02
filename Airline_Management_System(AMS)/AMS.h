#pragma once

#include "Common.h"
#include "AirlineBoard.h"
#include "Login.h"
#include "Menu.h"
#include "SuperUserInterface.h"
#include "UserInterface.h"
#include "AirlineCreator.h"
#include "File.h"

//Airport Part

class Passenger
{
public:
    Passenger(){};
    ~Passenger(){};
    string name;
private:
    
};


struct Time
{
    Time() = default;

    string weekday;
    string day;
    string time;
};


struct Airline
{
public:
    Airline() = default;
    Airline(const string &comp,const string &line,const string &dep,const string &dest,int re):
        Company(comp),LineNo(line),Departure(dep),Destination(dest),RemainTickets(re) {}
    string Company;
    string LineNo;
    string Departure;
    string Destination;
//    string Airplane;
//    Time DepartureTime;                          ,const string &airp,Time depa,Time desti,int maxp,
//    Time DestinationTime;  ��ӻ���ʱ�ǵøĹ��캯�� ,Airplane(airp),DepartureTime(depa),DestinationTime(desti),Maxpassenger(maxp)
    int Maxpassenger;
    int RemainTickets;

private:
    unordered_map<string, string>Bookedlist;
    queue<Passenger>Inqueuelist;

};
//Time aa = { "������","2021-11-30","20:30" };
//AirlineInfo a ( "��������","CA4563","�Ϻ�","����","C919",aa,aa,260,20 );
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


