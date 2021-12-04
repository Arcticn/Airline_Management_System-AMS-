#pragma once
class AirlineInfo
{
public:
    AirlineInfo() = default;
    AirlineInfo(const string &comp, const string &line, const string &dep, const string &dest, int re) :
        Company(comp), LineNo(line), Departure(dep), Destination(dest), RemainTickets(re) {}
    string Company;
    string LineNo;
    string Departure;
    string Destination;
    //    string Airplane;
    //    Time DepartureTime;                          ,const string &airp,Time depa,Time desti,int maxp,
    //    Time DestinationTime;  添加回来时记得改构造函数 ,Airplane(airp),DepartureTime(depa),DestinationTime(desti),Maxpassenger(maxp)
    int Maxpassenger;
    int RemainTickets;

private:
    unordered_map<string, string>Bookedlist;
    queue<Passenger>Inqueuelist;

};
