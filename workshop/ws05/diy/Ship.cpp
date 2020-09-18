//kyurim kim	168819183	kkim125@myseneca.ca		2020.02.11
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <cctype>
#include <cstring>
#include "Ship.h"
#include "Engine.h"

using namespace std;

namespace sdds {
	Ship::Ship() {
		ship_type = nullptr;
		engines = nullptr;
		engine_len = 0;
	}


	Ship::Ship(const char* st, const Engine *e, int l) {
		if (st != nullptr && strcmp(st, "") != 0 && strlen(st) < MAX_S_TYPE + 1 && l > 0) {
			ship_type = new char[strlen(st) + 1];
			strcpy(ship_type, st);
			engines = new Engine[l];
			for (int i = 0; i < l; i++) {
				engines[i] = e[i];
			}
			engine_len = l;
		}
		else {
			ship_type = nullptr;
			engines = nullptr;
			engine_len = 0;
		}
	}
	Ship::~Ship() {
		delete[] ship_type;
		delete[] engines;
		ship_type = nullptr;
		engines = nullptr;
	}

	bool Ship::empty() const {
		return engine_len == 0;
	}
	
	float Ship::calculatePower() const {
		float power = 0.f;
		for (int i = 0; i < engine_len; i++) {
			power += ((float)engines[i].get() * 5.f);
		}
		return power;
	}

	void Ship::display() const {
		if (ship_type != nullptr && strcmp(ship_type, "") != 0 && strlen(ship_type) < MAX_S_TYPE + 1) {
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << ship_type << "-" << setw(6) << calculatePower() << endl;
			for (int i = 0; i < engine_len; i++) {
				engines[i].display();
			}
		}
		else {
			cout << "No available data"<< endl;
		}
	}

	Ship& Ship::operator+=(Engine e) {
		if (ship_type != nullptr && engine_len != 0) {
			Engine* temp = nullptr;
				temp = new Engine[engine_len + 1];

			for (int i = 0; i < engine_len; i++) {
				temp[i] = engines[i];
			}
			temp[engine_len] = e;
			engine_len++;
			delete[] engines;
			engines = nullptr;
			engines = temp;
		}
		else {
			cout << "The ship doesn't have a type! Engine cannot be added!" << endl;
		}
		return *this;
	}

	bool operator==(const Ship& s1, const Ship& s2) {
		if (s1.engine_len == 0 || s2.engine_len == 0 || s1.calculatePower() != s2.calculatePower()) {
			return false;
		}
		else {
			return true;
		}
	}

	bool operator<(const Ship& ship, const double power) {
		return (ship.calculatePower() < power);
	}
}