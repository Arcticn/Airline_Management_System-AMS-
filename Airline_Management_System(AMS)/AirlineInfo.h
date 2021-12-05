#pragma once
class AirlineInfo
{
public:
    AirlineInfo() = default;
    AirlineInfo(const string &comp, const string &line, const string &dep, const string &dest, const string &airp, tm deptime,tm destime,int maxp) :
        Company(comp), LineNo(line), Departure(dep), Destination(dest), Airplane(airp),DepartureTime(deptime), estDestinationTime(destime), Maxpassenger(maxp), RemainTickets(maxp) {}
    string Company;
    string LineNo;
    string Departure;
    string Destination;
    string Airplane;
    tm DepartureTime;                         
    tm estDestinationTime;
    int Maxpassenger;
    int RemainTickets;
    vector<string> SearchLine(string depart, string desti);
    vector<vector<string>> SearchIndirectLine(string depart, string desti);
    string SearchDepart(string LineNo);
    string SearchDesti(string LinNo);
private:
    //unordered_map<string, string>Bookedlist;
    //queue<Passenger>Inqueuelist;

};
