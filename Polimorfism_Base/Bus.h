#pragma once
#include "Vehicles.h"
#include "Base.h"

class Bus :public Vehicles {
	double BusPetrol, MaxBusPetrol;
	int PeopleCapacity;
public:
	Bus();
	void Input();
	void Arrive(Base& base);
	bool Refueling(Base& base);
	bool Leave(Base& base);
};
