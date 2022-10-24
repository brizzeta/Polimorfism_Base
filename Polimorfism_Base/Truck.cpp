#include "Truck.h"
#include <iostream>
using namespace std;

Truck::Truck() :Vehicles() {
	TruckPetrol = MaxTruckPetrol = GoodsCapaticy = NULL;
}
void Truck::Input() {
	setlocale(LC_ALL, "");
	do {
		cout << "Ââåäèòå êîëè÷åñòâî áåíçèíà â ãðóçîâèêå(ëèòðû): ";
		cin >> TruckPetrol;
		if (TruckPetrol < 0) {
			cout << "Áåçíèíà íå ìîæåò áûòü ìåíüøå 0 ëèòðîâ!";
			system("cls");
		}
		else {
			break;
		}
	} while (true);
	do {
		cout << "Ââåäèòå åìêîñòü áåíçîáàêà àâñòîáóñà(ëèòðû): ";
		cin >> MaxTruckPetrol;
		if (MaxTruckPetrol < 0) {
			cout << "Áåçíèíà íå ìîæåò áûòü ìåíüøå 0 ëèòðîâ!";
			system("cls");
		}
		else if (MaxTruckPetrol < TruckPetrol) {
			cout << "Áåíçèíà íå ìîæåò áûòü áîëüøå ÷åì âìåùàåò áåíçîáàê!";
			system("cls");
		}
		else {
			break;
		}
	} while (true);
	do {
		cout << "Ââåäèòå ãðóçîïîäúåìíîñòü ãðóçîâèêà(òîííû): ";
		cin >> GoodsCapaticy;
		if (GoodsCapaticy < 0) {
			cout << "Ãðóçà íå ìîæåò áûòü ìåíüøå 0 òîíí!";
			system("cls");
		}
		else {
			break;
		}
	} while (true);
}
void Truck::Arrive(Base& base) {
	setlocale(LC_ALL, "");
	int PetrTemp = TruckPetrol * 0.08;
	TruckPetrol -= PetrTemp;
	base.SetVehicles(base.GetVehicles() + 1);
	base.SetPeople(base.GetPeople() + 1);
	cout << "Òðàíñïîðò ïðèåõàë! Ïîòðà÷åíî 8% èëè æå " << PetrTemp << " ëèòðîâ áåíçèíà ýòîãî òðàíñïîðòà." << endl;
	cout << "Òðàíñïîðòíûõ ñðåäñòâ íà áàçå ñòàëî: " << base.GetVehicles() << " øòóê.";
	cout << "Ëþäåé íà áàçå ñòàëî: " << base.GetPeople() << " øòóê.";
	cout << "Ýòîò òðàíñïîðò íå ìîæåò ïåðåâîçèòü ëþäåé!" << endl;
}
bool Truck::Refueling(Base& obj) {
	setlocale(LC_ALL, "");
	cout << "Çàïðàâêà íà÷àòà!";
	int NeedPetrol = MaxTruckPetrol - TruckPetrol;
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
		TruckPetrol = TruckPetrol;
		cout << "Çàïðàâêà ïðîøëà óñïåøíî!" << endl;
		return true;
	}
}
bool Truck::Leave(Base& base) {
	setlocale(LC_ALL, "");
	if (TruckPetrol != TruckPetrol) {
		cout << "Òðàíñïîðò íå ìîæåò óåõàòü, ò.ê. áåíçîáàê íå ïîëîí!" << endl;
		return false;
	}
	else {
		int PetrTemp = TruckPetrol * 0.08;
		TruckPetrol -= PetrTemp;
		base.SetVehicles(base.GetVehicles() - 1);
		if (base.GetVehicles() < 0) {
			base.SetVehicles(0);
		}
		base.SetPeople(base.GetPeople() - 1);
		if (base.GetPeople() < 0) {
			base.SetPeople(0);
		}
		base.SetGoods(base.GetGoods() - GoodsCapaticy);
		if (base.GetGoods() < 0) {
			base.SetGoods(0);
		}
		cout << "Òðàíñïîðò óåõàë! Ïîòðà÷åíî 5% èëè æå " << PetrTemp << " ëèòðîâ áåíçèíà." << endl;
		cout << "Òðàíñïîðòíûõ ñðåäñòâ íà áàçå ñòàëî: " << base.GetVehicles() << " øòóê.";
		cout << "Ëþäåé íà áàçå ñòàëî: " << base.GetPeople() << " øòóê.";
		cout << "Ãðóçà íà áàçå ñòàëî: " << base.GetGoods() << " òîíí.";
		cout << "Ýòîò òðàíñïîðò íå ìîæåò ïåðåâîçèòü ëþäåé!" << endl;
		return true;
	}
}