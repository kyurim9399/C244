//kyurim kim	168819183	kkim125@myseneca.ca
//Train.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Train.h"

using namespace std;

namespace sdds {
	void Cargo::setDesc(const char* setd) {
		strcpy(description, setd);
	}

	void Cargo::setWeight(double setw) {
		this->weight = setw;
	}

	const char* Cargo::getDesc() const {
		return description;
	}


	double Cargo::getWeight() const {
		return weight;
	}

	void Cargo::init(const char* d, double w) {
		if (w < MIN_WEIGHT || w > MAX_WEIGHT) {
			weight = MIN_WEIGHT;
		}
		else {
			weight = w;
		}

		if (strlen(d) <= MAX_DESC + 1)
			setDesc(d);
		else
			setDesc("\0");
	}

	void Train::setTrain(const char* sname, int sid) {
		if (sname == nullptr || strcmp(sname, "") == 0 || sid < 1) {
			id = 0;
			strcpy(name, "");
		}

		else {
			strcpy(name, sname);
			id = sid;
		}

		cargo = nullptr;
	}

	bool Train::isEmpty() const {
		if (cargo == nullptr && strcmp(name, "") == 0 && id == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	void Train::display() const {
		cout << "***Train Summary***" << endl;
		if (isEmpty())
			cout << "This is an empty train." << endl;
		else {
			cout << "Name: " << name << " ID: " << id << endl;
			cout.setf(ios::fixed);
			cout.precision(2);
			if (cargo != nullptr) {
				cout.setf(ios::fixed);
				cout.precision(2);
				cout << "Cargo: " << cargo->getDesc() << " Weight: " << cargo->getWeight() << endl;
			}
			else {
				cout << "No cargo on this train." << endl;
			}
		}
		
	}

	void Train::loadCargo(Cargo c) {
		this->cargo = new Cargo;
		this->cargo->setDesc(c.getDesc());
		this->cargo->setWeight(c.getWeight());
	}


	void Train::unloadCargo() {
		delete cargo;
		cargo = nullptr;
	}



	bool Train::swapCargo(Train& otherT) {
		bool swap;
		if (cargo != nullptr && otherT.cargo != nullptr) {
			Cargo* temp = cargo;
			cargo = otherT.cargo;
			otherT.cargo = temp;
			swap = true;
		}
		else
			swap = false;
		return swap;
	}


	bool Train::increaseCargo(double incWeight) {
		bool result;
		if (cargo != nullptr && cargo->getWeight() < MAX_WEIGHT) {
			double total = cargo->getWeight() + incWeight;
			if (total <= MAX_WEIGHT) {
				cargo->setWeight(total);
			}
			else {
				cargo->setWeight(MAX_WEIGHT);
			}
			result = true;
		}
		else
			result = false;
		return result;
	}

	bool Train::decreaseCargo(double decWeight) {
		bool result;
		if (cargo != nullptr && cargo->getWeight() > MIN_WEIGHT) {
			double total = cargo->getWeight() - decWeight;
			if (total >= MIN_WEIGHT) {
				cargo->setWeight(total);
			}
			else {
				cargo->setWeight(MIN_WEIGHT);
			}
			result = true;
		}
		else
			result = false;
		return result;
	}

}
