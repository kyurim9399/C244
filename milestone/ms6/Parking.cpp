//kyurim kim	168819183	kkim125@myseneca.com

#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <cstring>
#include <fstream>  
#include "Parking.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Utils.h"

using namespace std;

namespace sdds {
	Parking::Parking() {
		this->setEmpty();
	}

	Parking::Parking(const char* datafile, int noOfSpots) {
		this->setEmpty();
		if (datafile != nullptr && strcmp(datafile, "") != 0 && noOfSpots >= 10 && noOfSpots <= MAX_PARKING_SPOT) {
			filename = new char[strlen(datafile) + 1];
			strcpy(filename, datafile);
			m_noOfSpots = noOfSpots;
		}

		if (load_data()) {
			parking_menu = Menu("Parking Menu, select an action:", 0);
			parking_menu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Close Parking (End of day)" << "Exit Program";
			vehicle_menu = Menu("Select type of the vehicle:", 1);
			vehicle_menu << "Car" << "Motorcycle" << "Cancel";
		}
		else {
			cout << "Error in data file" << endl;
			this->setEmpty();
		}
	}

	Parking::~Parking() {
		save();
		delete[] filename;
		filename = nullptr;
		for (int i = 0; i < MAX_PARKING_SPOT; i++) {
			if (m_parkingSpots[i] != nullptr) {
				delete m_parkingSpots[i];
			}
			m_parkingSpots[i] = nullptr;
		}
	}

	bool Parking::isEmpty() const {
		return filename == nullptr;
	}

	void Parking::setEmpty() {
		filename = nullptr;
		parking_menu = Menu();
		vehicle_menu = Menu();
		m_noOfSpots = 0;
		for (int i = 0; i < MAX_PARKING_SPOT; i++) {
			m_parkingSpots[i] = nullptr;
		}
		m_numOfParkedVehicles = 0;
		m_spotNum = 0;
	}

	void Parking::status() const{
		cout << "****** Seneca Valet Parking ******" << endl;
		cout << "*****  Available spots: ";
		cout.width(4);
		cout.setf(ios::left);
		cout << m_noOfSpots - m_numOfParkedVehicles;
		cout.unsetf(ios::left);
		cout << " *****" << endl;
	}



	void Parking::park_vehicle() {
		if (m_numOfParkedVehicles == m_noOfSpots) {
			cout << "Parking is full" << endl;
		}
		else {
			switch (vehicle_menu.run()) {
			case 1:
				for (int i = 0; i < m_noOfSpots; i++) {
					if (m_parkingSpots[i] == nullptr) {
						m_spotNum = i;
						break;
					}
				}
				m_parkingSpots[m_spotNum] = new Car();
				cin >> *m_parkingSpots[m_spotNum];
				if (*m_parkingSpots[m_spotNum] == nullptr) {
					delete m_parkingSpots[m_spotNum];
					m_parkingSpots[m_spotNum] = nullptr;
				}
				else {
					m_parkingSpots[m_spotNum]->setParkingSpot(m_spotNum + 1);
					cout << endl << "Parking Ticket" << endl;
					cout << *m_parkingSpots[m_spotNum] << endl;
					m_numOfParkedVehicles++;
				}
				break;
			case 2:
				for (int i = 0; i < m_noOfSpots; i++) {
					if (m_parkingSpots[i] == nullptr) {
						m_spotNum = i;
						break;
					}
				}
				m_parkingSpots[m_spotNum] = new Motorcycle();
				cin >> *m_parkingSpots[m_spotNum];
				if (*m_parkingSpots[m_spotNum] == nullptr) {
					delete m_parkingSpots[m_spotNum];
					m_parkingSpots[m_spotNum] = nullptr;
				}
				else {
					m_parkingSpots[m_spotNum]->setParkingSpot(m_spotNum + 1);
					cout << endl << "Parking Ticket" << endl;
					cout << *m_parkingSpots[m_spotNum] << endl;
					m_numOfParkedVehicles++;
				}
				break;
			case 3:
				cout << "Parking cancelled" << endl;
				break;
			}
		}
	}

	void Parking::return_vehicle() {
		bool valid;
		char licensePlate[20] = {'\0'};

		cout << "Return Vehicle" << endl;
		cout << "Enter Licence Plate Number: ";
		do {
			cin.getline(licensePlate, 100);
			if (strlen(licensePlate) >= 1 && strlen(licensePlate) <= MAX_LICENSE_PLATE) {
				Toupper(licensePlate);
				for (int i = 0; i < m_noOfSpots; i++) {
					if (*m_parkingSpots[i] == licensePlate) {
						cout << endl << "Returning: " << endl;
						m_parkingSpots[i]->setCsv(false);
						cout << *m_parkingSpots[i] << endl;
						m_numOfParkedVehicles--;
						delete m_parkingSpots[i];
						m_parkingSpots[i] = nullptr;
						valid = true;
						break;
					}
				}
				if (!valid) {
					cout << "License plate " << licensePlate << " Not found" << endl;
					valid = false;
				}
			}
			else {
				cout << "Invalid Licence Plate, try again: ";
				valid = false;
			}
		} while (!valid);
	}

	void Parking::list() const{
		cout << "*** List of parked vehicles ***" << endl;
		for (int i = 0; i < m_noOfSpots; i++) {
			if (m_parkingSpots[i] != nullptr) {
				m_parkingSpots[i]->setCsv(false);
				cout << *m_parkingSpots[i] << "-------------------------------" << endl;
			}
		}
	}

	bool Parking::close() {
		char a[20] = { '\0' };
		bool response;
		bool valid;
		if (isEmpty()) {
			cout << "Closing Parking" << endl;
			return true;
		}
		else {
			cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
			cout << "Are you sure? (Y)es/(N)o: ";
			do {
				cin >> a;
				if (strcmp(a, "y") == 0 || strcmp(a, "Y") == 0) {
					cout << "Closing Parking" << endl;
					for (int i = 0; i < m_noOfSpots; i++) {
						if (m_parkingSpots[i] != nullptr) {
							cout << endl << "Towing request" << endl;
							cout << "*********************" << endl;
							cout << *m_parkingSpots[i];
							delete m_parkingSpots[i];
							m_parkingSpots[i] = nullptr;
							m_numOfParkedVehicles--;
						}
					}
					valid = true;
					response = true;
				}
				else if (strcmp(a, "n") == 0 || strcmp(a, "N") == 0) {
					cout << "Aborted!" << endl;
					valid = true;
					response = false;
				}
				else {
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					valid = false;

				}
				cin.clear();
				cin.ignore(2000, '\n');
			} while (!valid);
			return response;
		}
	}


	bool Parking::exit() const{
		char a[20] = { '\0' };
		bool response;
		bool valid;
		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";
		do {
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
		} while (!valid);
		return response;
	}

	
	bool Parking::load_data() {
		bool valid;
		char type;
		if (!isEmpty()) {
			ifstream fin(filename, ios::in);
			if (!fin) {
				fin.clear();
				valid = false;
			}
			else {
				while (fin && m_numOfParkedVehicles < m_noOfSpots) {
					type = ' ';
					fin >> type;
					fin.ignore(1, ',');
					Vehicle* temp = nullptr;
					if (type == 'C') {
						temp = new Car();
					}
					else {
						temp = new Motorcycle();
					}
					temp->setCsv(true);
					fin >> *temp;
					temp->setCsv(false);
					if (!fin) {
						delete temp;
						temp = nullptr;
					}
					else {
						m_parkingSpots[temp->getParkingSpot() - 1] = temp;
						m_numOfParkedVehicles++;
					}
				}
				fin.close();
				valid = true;
			}
		}
		return valid;
	}


	void Parking::save() const{
		ofstream fout;
		if (!isEmpty()) {
			//cout << "Saving data into " << filename << endl;
			fout.open(filename);
			if (fout) {
				for (int i = 0; i < m_noOfSpots; i++) {
					if (m_parkingSpots[i] != nullptr) {
						m_parkingSpots[i]->setCsv(true);
						fout << *m_parkingSpots[i];
					}
				}
			}
		}
		fout.close();
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
					cin.clear();
					cin.ignore(2000, '\n');
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