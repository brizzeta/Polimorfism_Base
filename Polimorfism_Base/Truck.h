#pragma once
#include "Base.h"
#include "Vehicles.h"

class Truck :public Vehicles {
	double TruckPetrol, MaxTruckPetrol, GoodsCapaticy;
public:
	Truck();
	void Input();
	void Arrive(Base& base);
	bool Refueling(Base& base);
	bool Leave(Base& base);
};