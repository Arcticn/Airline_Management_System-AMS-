#pragma once
constexpr double Ma = 1225;//1ÂíºÕ
struct Airplane
{
	Airplane() = default;
	Airplane(string model,double speed,int maxp,int maxr):
		Model(model),Speed(speed*Ma),Maxpassenger(maxp),MaxRange(maxr){}
	string Model;
	double Speed;
	int Maxpassenger;
	int MaxRange;
};

