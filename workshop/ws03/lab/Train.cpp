//Train.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <cstring>
#include "Train.h"

using namespace std;

namespace sdds {
	void Train::setTrain(const char* sname, int sid) {
		if (sname == nullptr || strcmp(sname, "") == 0 || sid < 1 ) {
			id = 0;
			strcpy(name, "");
		}
		
		else {
			strcpy(name, sname);
			id = sid;
		}
	
		cargo = nullptr;
	}

	bool Train::isEmpty() const{
		if (cargo == nullptr && strcmp(name, "") == 0 && id == 0)
		{return true; }
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
			if (cargo->description != nullptr) {
				cout << "Cargo: " << cargo->description << " Weight: " << cargo->weight << endl;
			}
			else {
				cout << "No cargo on this train." << endl;
			}
		}
	
	}

	void Train::loadCargo(Cargo c) {
		cargo = new Cargo;
		strcpy(cargo->description, c.description);
		cargo->weight = c.weight;
	}

	void Train::unloadCargo() {
		delete cargo;
		cargo = nullptr;
	}

}