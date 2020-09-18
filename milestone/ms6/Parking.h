//kyurim kim	168819183	kkim125@myseneca.ca
#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H
#include <iostream>
#include "Menu.h"
#include "Vehicle.h"

namespace sdds {

	const int MAX_PARKING_SPOT = 100;
	class Parking {
		char* filename;
		Menu parking_menu;
		Menu vehicle_menu;
		int m_noOfSpots; //½ºÆÌÀÇ °³¼ö
		Vehicle* m_parkingSpots[MAX_PARKING_SPOT];
		int m_numOfParkedVehicles; // < m_noOfSpots
		int m_spotNum;

		bool isEmpty() const;
		void setEmpty();
		void status() const;
		void park_vehicle();
		void return_vehicle();
		void list() const;
		bool close();
		bool exit() const;
		bool load_data();
		void save() const;

	public:
		Parking();
		Parking(const char* datafile, int noOfSpots);
		Parking(const Parking& p) = delete;
		Parking& operator=(const Parking& p) = delete;
		int run();
		~Parking();
	};
}

#endif