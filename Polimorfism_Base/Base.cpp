#include <iostream>
#include "Base.h"
#include <Windows.h>
using namespace std;

Base::Base() {
	PeopleOnBase = VehiclesOnBase = NULL;
	PetrolOnBase = GoodsOnBase = NULL;
}
Base::Base(const Base& obj) {
	PeopleOnBase = obj.PeopleOnBase;
	VehiclesOnBase = obj.VehiclesOnBase;
	PetrolOnBase = obj.PetrolOnBase;
	GoodsOnBase = obj.GoodsOnBase;
}
void Base::Input() {
	setlocale(LC_ALL, "");
	cout << "Ââĺäčňĺ ęîëč÷ĺńňâî ëţäĺé íŕ áŕçĺ: ";
	cin >> PeopleOnBase;
	cout << "Ââĺäčňĺ ęîëč÷ĺńňâî ňđŕíńďîđňŕ íŕ áŕçĺ: ";
	cin >> VehiclesOnBase;
	cout << "Ââĺäčňĺ ęîëč÷ĺńňâî ňîďëčâŕ íŕ áŕçĺ(ëčňđű): ";
	cin >> PetrolOnBase;
	cout << "Ââĺäčňĺ ęîëč÷ĺńňâî ăđóçŕ íŕ áŕçĺ(ňîííű): ";
	cin >> GoodsOnBase;
}
void Base::SetPeople(int people) {
	Base::PeopleOnBase = people;
}
void Base::SetVehicles(int vehicle) {
	Base::VehiclesOnBase = vehicle;
}
void Base::SetPetrol(double petrol) {
	Base::PetrolOnBase = petrol;
}
void Base::SetGoods(double goods) {
	Base::GoodsOnBase = goods;
}
int Base::GetPeople() {
	return PeopleOnBase;
}
int Base::GetVehicles() {
	return VehiclesOnBase;
}
double Base::GetPetrol() {
	return PetrolOnBase;
}
double Base::GetGoods() {
	return GoodsOnBase;
}