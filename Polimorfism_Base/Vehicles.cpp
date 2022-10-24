#include "Vehicles.h"
#include "Base.h"
#include <iostream>
using namespace std;

Vehicles::Vehicles() {
	MaxVehiclePetrol = VehiclePetrol = NULL;
}
void Vehicles::Input() {
	setlocale(LC_ALL, "");
	do {
		cout << "Ââåäèòå êîëè÷åñòâî áåíçèíà â òðàíñïîðòå(ëèòðû): ";
		cin >> VehiclePetrol;
		if (VehiclePetrol < 0) {
			cout << "Áåçíèíà íå ìîæåò áûòü ìåíüøå 0 ëèòðîâ!";
			system("cls");
		}
		else {
			break;
		}
	} while (true);
	do {
		cout << "Ââåäèòå åìêîñòü áåíçîáàêà òðàíñïîðòà(ëèòðû): ";
		cin >> MaxVehiclePetrol;
		if (MaxVehiclePetrol < 0) {
			cout << "Áåíçîáàê íå ìîæåò âìåùàòü ìåíüøå 0 ëèòðîâ!";
			system("cls");
		}
		else if (MaxVehiclePetrol < VehiclePetrol) {
			cout << "Áåíçèíà íå ìîæåò áûòü áîëüøå ÷åì âìåùàåò áåíçîáàê!";
			system("cls");
		}
		else {
			break;
		}
	} while (true);
}
void Vehicles::Arrive(Base& base) {
	setlocale(LC_ALL, "");
	int PetrTemp = VehiclePetrol * 0.01;
	VehiclePetrol -= PetrTemp;
	base.SetVehicles(base.GetVehicles() + 1);
	base.SetPeople(base.GetPeople() + 1);
	cout << "Òðàíñïîðò ïðèåõàë! Ïîòðà÷åíî 1% èëè æå " << PetrTemp << " ëèòðîâ áåíçèíà ýòîãî òðàíñïîðòà." << endl;
	cout << "Òðàíñïîðòíûõ ñðåäñòâ íà áàçå ñòàëî: " << base.GetVehicles() << " øòóê.";
	cout << "Ëþäåé íà áàçå ñòàëî: " << base.GetPeople() << " øòóê.";
	cout << "Ýòîò òðàíñïîðò íå ìîæåò ïåðåâîçèòü ëþäåé è ãðóç!" << endl;
}
bool Vehicles::Refueling(Base& obj) {
	setlocale(LC_ALL, "");
	cout << "Çàïðàâêà íà÷àòà!";
	int NeedPetrol = MaxVehiclePetrol - VehiclePetrol;
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
		VehiclePetrol = MaxVehiclePetrol;
		cout << "Çàïðàâêà ïðîøëà óñïåøíî!" << endl;
		return true;
	}
}
bool Vehicles::Leave(Base& base) {
	setlocale(LC_ALL, "");
	if (VehiclePetrol != MaxVehiclePetrol) {
		cout << "Òðàíñïîðò íå ìîæåò óåõàòü, ò.ê. áåíçîáàê íå ïîëîí!" << endl;
		return false;
	}
	else {
		int PetrTemp = VehiclePetrol * 0.01;
		VehiclePetrol -= PetrTemp;
		base.SetVehicles(base.GetVehicles() - 1);
		if (base.GetVehicles() < 0) {
			base.SetVehicles(0);
		}
		base.SetPeople(base.GetPeople() - 1);
		if (base.GetPeople() < 0) {
			base.SetPeople(0);
		}
		cout << "Òðàíñïîðò óåõàë! Ïîòðà÷åíî 1% èëè æå " << PetrTemp << " ëèòðîâ áåíçèíà." << endl;
		cout << "Òðàíñïîðòíûõ ñðåäñòâ íà áàçå ñòàëî: " << base.GetVehicles() << " øòóê.";
		cout << "Ëþäåé íà áàçå ñòàëî: " << base.GetPeople() << " øòóê.";
		cout << "Ýòîò òðàíñïîðò íå ìîæåò ïåðåâîçèòü ëþäåé è ãðóç!" << endl;
		return true;
	}
}