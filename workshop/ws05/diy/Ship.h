//kyurim kim	168819183	kkim125@myseneca.ca		2020.02.11
#ifndef SDDS_SHIP_H
#define SDDS_SHIP_H
#include "Engine.h"

namespace sdds {
	const int MAX_S_TYPE = 6;
	class Ship {
		char *ship_type;
		Engine *engines;
		int engine_len; //<=10 Engine array passed in

	public:
		Ship();
		Ship(const char* st, const Engine* e, int l);
		~Ship();
		bool empty() const;
		float calculatePower() const;
		void display() const;
		Ship& operator+=(Engine e);
		friend bool operator==(const Ship& s1, const Ship& s2);
	};
	bool operator<(const Ship& ship, const double power);
}
#endif