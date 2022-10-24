#pragma once
#include "Base.h"

class Vehicles {
protected:
	Base ObjBase;
	double VehiclePetrol, MaxVehiclePetrol;
public:
	Vehicles();
	void Input();
	void Arrive(Base& base);
	bool Refueling(Base& base);
	bool Leave(Base& base);
};