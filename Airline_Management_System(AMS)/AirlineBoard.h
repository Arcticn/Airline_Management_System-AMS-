#pragma once
class AirlineBoard {
public:
	void menu();

private:
	void depart(int ap);
	void desti(int ap);
};
/*ostream &operator<<(ostream &os, const tm &rhs) {
	os << setfill('0') << setw(2) << rhs.tm_hour << ":" << setw(2) << rhs.tm_min;
	return os;
}*/