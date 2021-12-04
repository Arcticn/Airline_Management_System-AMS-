#pragma once
constexpr double Ma = 1225;//1ÂíºÕ
struct Airplane
{
	Airplane() = default;
	Airplane(string type,double speed,int maxp,int maxr):
		Type(type),Speed(speed*Ma),Maxpassenger(maxp),MaxRange(maxr){}
	string Type;
	double Speed;
	int Maxpassenger;
	int MaxRange;
};

