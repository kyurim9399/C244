//kyurim kim	168819183	kkim125@myseneca.com

#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <cstring>
#include "Parking.h"

using namespace std;

namespace sdds {
	Parking::Parking() {
		filename = nullptr;
	}

	Parking::Parking(const char* f) {
		if (f != nullptr && strcmp(f, "") != 0) {
			filename = new char[strlen(f) + 1];
			strcpy(filename, f);
			if (load_data()) {
				parking_menu = Menu ("Parking Menu, select an action:", 0);
				parking_menu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Close Parking (End of day)" << "Exit Program";
				vehicle_menu = Menu ("Select type of the vehicle:", 1);
				vehicle_menu << "Car" << "Motorcycle" << "Cancel";
			}
			else {
				cout << "Error in data file" << endl;
				filename = nullptr;
			}
		}
		else {
			cout << "Error in data file" << endl;
			filename = nullptr;
		}
	}

	Parking::~Parking() {
		save();
		delete[] filename;
		filename = nullptr;
	}

	bool Parking::isEmpty() const {
		return filename == nullptr;
	}

	void Parking::status() {
		cout << "****** Seneca Valet Parking ******" << endl;
	}


	void Parking::park_vehicle() {
		switch (vehicle_menu.run()) {
		case 1:
			cout << "Parking Car" << endl;
			break;
		case 2:
			cout << "Parking Motorcycle" << endl;
			break;
		case 3:
			cout << "Cancelled parking" << endl;
			break;
		}
	}

	void Parking::return_vehicle() {
		cout << "Returning Vehicle" << endl;
	}

	void Parking::list() {
		cout << "Listing Parked Vehicles" << endl;
	}

	bool Parking::close() {
		cout << "Closing Parking" << endl;
		return true;
	}

	
	bool Parking::exit() {
		char* a = nullptr;
		bool response;
		bool valid;
		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";
		do {
			a = new char[200];
			cin >> a;
			if (strcmp(a, "y") == 0 || strcmp(a, "Y") == 0) {
				valid = true;
				response = true;
			}
			else if (strcmp(a, "n") == 0 || strcmp(a, "N") == 0) {
				valid = true;
				response = false;
			}
			else {
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				valid = false;
			}
			delete[] a;
			a = nullptr;
		} while (!valid);
		return response;
	}

	bool Parking::load_data() {
		if (!isEmpty()) {
			cout << "loading data from " << filename << endl;
			return true;
		}
		else {
			return false;
		}
	}

	void Parking::save() {
		if(!isEmpty()) {
			cout << "Saving data into " << filename << endl;
		}
	}

	int Parking::run() {
		int result;
		bool valid;
		if (!isEmpty()) {
			do {
				status();
				switch (parking_menu.run()) {
				case 1:
					park_vehicle();
					valid = false;
					break;
				case 2:
					return_vehicle();
					valid = false;
					break;
				case 3:
					list();
					valid = false;
					break;
				case 4:
					if (close()) {
						valid = true;
					} 
					else {
						valid = false;
					}
					break;
				case 5:
					if (exit()) {
						cout << "Exiting program!" << endl;
						valid = true;
					}
					else {
						valid = false;
					}
				}

			} while (!valid);
		}
		if (isEmpty()) {
			result = 1;
		}
		else {
			result = 0;
		}
		return result;
	}
}