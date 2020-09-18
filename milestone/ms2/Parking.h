//kyurim kim	168819183	kkim125@myseneca.ca
#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H
#include <iostream>
#include "Menu.h"


namespace sdds {
	class Parking {
		char* filename;
		Menu parking_menu;
		Menu vehicle_menu;
		
		bool isEmpty() const;
		void status();
		void park_vehicle();
		void return_vehicle();
		void list();
		bool close();
		bool exit();
		bool load_data();
		void save();
	public:
		Parking();
		Parking(const char* f);
		Parking(const Parking& p) = delete;
		Parking& operator=(const Parking& p) = delete;
		int run();
		~Parking();
	};
}

#endif