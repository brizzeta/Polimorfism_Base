#pragma once
class Base {
	static int PeopleOnBase, VehiclesOnBase;
	static double PetrolOnBase, GoodsOnBase;
public:
	Base();
	Base(const Base& obj);
	void Input();
	void SetPeople(int people);
	void SetVehicles(int vehicle);
	void SetPetrol(double petrol);
	void SetGoods(double goods);
	int GetPeople();
	int GetVehicles();
	double GetPetrol();
	double GetGoods();
};