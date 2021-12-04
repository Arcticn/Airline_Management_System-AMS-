#pragma once
class AirlineInfo
{
public:
    AirlineInfo() = default;
    AirlineInfo(const string &comp, const string &line, const string &dep, const string &dest, const string &airp, int maxp) :
        Company(comp), LineNo(line), Departure(dep), Destination(dest), Airplane(airp),Maxpassenger(maxp), RemainTickets(maxp) {}
    string Company;
    string LineNo;
    string Departure;
    string Destination;
    string Airplane;
    //    Time DepartureTime;                          ,Time depa,Time desti,int maxp,
    //    Time DestinationTime;  添加回来时记得改构造函数 ,DepartureTime(depa),DestinationTime(desti)
    int Maxpassenger;
    int RemainTickets;
    vector<string>SearchLine(string depart, string desti);
    string SearchDepart(string LineNo);
    string SearchDesti(string LinNo);
private:
    unordered_map<string, string>Bookedlist;
    //queue<Passenger>Inqueuelist;

};
