#pragma once
class AirlineInfo
{
public:
    AirlineInfo() = default;
    AirlineInfo(const string &comp, const string &line, const string &dep, const string &dest, const string &airp, double distance, tm deptime, tm destime, int maxp) :
        Company(comp), LineNo(line), Departure(dep), Destination(dest), Airplane(airp), Distance(distance), DepartureTime(deptime), estDestinationTime(destime), Maxpassenger(maxp) {}
    AirlineInfo(const string &line) :
        LineNo(line) {}
    string Company;
    string LineNo;
    string Departure;
    string Destination;
    string Airplane;
    double Distance = 0;
    tm DepartureTime = { 0 };
    tm estDestinationTime = { 0 };
    int Maxpassenger = 0;
    unordered_map<string, int> RemainTickets = { {"0",{}} };
    unordered_map<string, vector<int>>Bookedlist = { {"0",{}} }; 
    unordered_map<string, queue<int>>Inqueuelist{ {"0",{}} }; 

    vector<string> SearchLine(string depart, string desti);
    vector<vector<string>> SearchIndirectLine(string depart, string desti);
    string SearchDepart(string LineNo);
    string SearchDesti(string LinNo);
    string SearchCompany(string LineNo);
    string SearchAirplane(string LineNo);
    double SearchDistance(string LineNo);
    int SearchRemainTicket(string date, string LineNo);
    tm SearchDeparTime(string LineNo);
    tm SearchDesTime(string LineNo);
    void QueueOut(string date);
    void RefreshLine();
private:

};