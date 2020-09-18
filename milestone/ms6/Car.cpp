//kyurim kim	168819183	kkim125@myseneca.ca
#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <cstring>
#include "Car.h"

using namespace std;

namespace sdds {
	Car::Car() {
		m_carwash = false;
	}

	Car::Car(const char* licensePlate, const char* makemodel) : Vehicle(licensePlate, makemodel) {
		m_carwash = false;
	}

	std::istream& Car::read(std::istream& istr) {
		if (ReadWritable::isCsv()) {
			int carwash;
			Vehicle::read(istr);
			istr >> carwash;
			m_carwash = carwash == 0 ? false : true;
			istr.ignore();
		}
		else {
			char a[20] = {};
			bool valid;
			cout << endl << "Car information entry" << endl;
			Vehicle::read(istr);
			cout << "Carwash while parked? (Y)es/(N)o: ";
			do {
				istr >> a;
				if (strcmp(a, "y") == 0 || strcmp(a, "Y") == 0) {
					valid = true;
					m_carwash = true;
				}
				else if (strcmp(a, "n") == 0 || strcmp(a, "N") == 0) {
					valid = true;
					m_carwash = false;
				}
				else {
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					valid = false;
				}
			} while (!valid);
		}
		return istr;
	}


	std::ostream& Car::write(std::ostream& ostr)const {
		if (Vehicle::isEmpty()) {
			ostr << "Invalid Car Object" << endl;
		}
		else {
			if (ReadWritable::isCsv()) {
				ostr << "C,";
				Vehicle::write(ostr);
				ostr << m_carwash << endl;

			}
			else {
				ostr << "Vehicle type: Car" << endl;
				Vehicle::write(ostr);
				if (m_carwash) {
					cout << "With Carwash" << endl;
				}
				else {
					cout << "Without Carwash" << endl;
				}
			}
		}
		return ostr;
	}



}