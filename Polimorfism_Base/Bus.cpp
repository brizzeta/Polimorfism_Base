#include "Bus.h"
#include <iostream>
using namespace std;

Bus::Bus() :Vehicles() {
	BusPetrol = MaxBusPetrol = NULL;
	PeopleCapacity = NULL;
}
void Bus::Input() {
	setlocale(LC_ALL, "");
	do {
		cout << "Ââåäèòå êîëè÷åñòâî áåíçèíà â àâòîáóñå(ëèòðû): ";
		cin >> BusPetrol;
		if (BusPetrol < 0) {
			cout << "Áåçíèíà íå ìîæåò áûòü ìåíüøå 0 ëèòðîâ!";
			system("cls");
		}
		else {
			break;
		}
	} while (true);
	do {
		cout << "Ââåäèòå åìêîñòü áåíçîáàêà àâñòîáóñà(ëèòðû): ";
		cin >> MaxBusPetrol;
		if (MaxBusPetrol < 0) {
			cout << "Áåíçîáàê íå ìîæåò âìåùàòü ìåíüøå 0 ëèòðîâ!";
			system("cls");
		}
		else if (MaxBusPetrol < BusPetrol) {
			cout << "Áåíçèíà íå ìîæåò áûòü áîëüøå ÷åì âìåùàåò áåíçîáàê!";
			system("cls");
		}
		else {
			break;
		}
	} while (true);
	do {
		cout << "Ââåäèòå ïàññàæèðîâìåñòèìîñòü àâòîáóñà(øò): ";
		cin >> PeopleCapacity;
		if (PeopleCapacity < 0) {
			cout << "Ïààñàæèðîâìåñòèìîñòü íå ìîæåò áûòü ìåíüøå 0!";
			system("cls");
		}
		else {
			break;
		}
	} while (true);
}
void Bus::Arrive(Base& base) {
	setlocale(LC_ALL, "");
	int PetrTemp = BusPetrol * 0.05;
	BusPetrol -= PetrTemp;
	base.SetVehicles(base.GetVehicles() + 1);
	base.SetPeople(base.GetPeople() + 1);
	cout << "Òðàíñïîðò ïðèåõàë! Ïîòðà÷åíî 5% èëè æå " << PetrTemp << " ëèòðîâ áåíçèíà ýòîãî òðàíñïîðòà." << endl;
	cout << "Òðàíñïîðòíûõ ñðåäñòâ íà áàçå ñòàëî: " << base.GetVehicles() << " øòóê.";
	cout << "Ëþäåé íà áàçå ñòàëî: " << base.GetPeople() << " øòóê.";
	cout << "Ýòîò òðàíñïîðò íå ìîæåò ïåðåâîçèòü ãðóç!" << endl;
}
bool Bus::Refueling(Base& obj) {
	setlocale(LC_ALL, "");
	cout << "Çàïðàâêà íà÷àòà!";
	int NeedPetrol = MaxBusPetrol - BusPetrol;
	if (obj.GetPetrol() < NeedPetrol) {
		cout << "Íåâîçìîæíî çàïðàâèòüñÿ, íà áàçå íåäîñòàòî÷íî áåíçèíà!" << endl;
		return false;
	}
	else if (obj.GetPeople() == 0) {
		cout << "Íåâîçìîæíî çàïðàâèòüñÿ, ò.ê íà áàçå íå îñòàëîñü ëþäåé!" << endl;
		return false;
	}
	else {
		obj.SetPetrol(obj.GetPetrol() - NeedPetrol);
		BusPetrol = MaxBusPetrol;
		cout << "Çàïðàâêà ïðîøëà óñïåøíî!" << endl;
		return true;
	}
}
bool Bus::Leave(Base& base) {
	setlocale(LC_ALL, "");
	if (BusPetrol != MaxBusPetrol) {
		cout << "Òðàíñïîðò íå ìîæåò óåõàòü, ò.ê. áåíçîáàê íå ïîëîí!" << endl;
		return false;
	}
	else {
		int PetrTemp = BusPetrol * 0.05;
		BusPetrol -= PetrTemp;
		base.SetVehicles(base.GetVehicles() - 1);
		if (base.GetVehicles() < 0) {
			base.SetVehicles(0);
		}
		base.SetPeople(base.GetPeople() - PeopleCapacity - 1);
		if (base.GetPeople() < 0) {
			base.SetPeople(0);
		}
		cout << "Òðàíñïîðò óåõàë! Ïîòðà÷åíî 5% èëè æå " << PetrTemp << " ëèòðîâ áåíçèíà." << endl;
		cout << "Òðàíñïîðòíûõ ñðåäñòâ íà áàçå ñòàëî: " << base.GetVehicles() << " øòóê.";
		cout << "Ëþäåé íà áàçå ñòàëî: " << base.GetPeople() << " øòóê.";
		cout << "Ýòîò òðàíñïîðò íå ìîæåò ïåðåâîçèòü ãðóç!" << endl;
		return true;
	}
}