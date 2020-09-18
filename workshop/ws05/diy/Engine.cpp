//kyurim kim	168819183	kkim125@myseneca.ca		2020.02.11
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <cstring>
#include "Engine.h"

using namespace std;

namespace sdds {
	Engine::Engine() {
		strcpy(engine_type, "");
		size = 0;
	}
	
	Engine::Engine(const char* et, double s) {
		
		if (et != nullptr && strcmp(et, "") != 0 && strlen(et) < MAX_E_TYPE + 1 && s > 0 ) {
			strcpy(engine_type, et);
			size = s;
		}
		else {
			strcpy(engine_type, "");
			size = 0;
		}
	}
	double Engine::get() const {
		return size;
	}
	void Engine::display() const {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << size << " liters - " << engine_type << endl;
	}
}