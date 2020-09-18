//kyurim kim	168819183	kkim125@myseneca.ca
#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <cstring>
#include "Motorcycle.h"

using namespace std;

namespace sdds {
	Motorcycle::Motorcycle() : Vehicle() {
		m_hasSidecar = false;
	}

	Motorcycle::Motorcycle(const char* licensePlate, const char* makemodel) : Vehicle(licensePlate, makemodel) {
		m_hasSidecar = false;
	}
	std::istream& Motorcycle::read(std::istream& istr) {
		if (ReadWritable::isCsv()) {
			Vehicle::read();
			istr >> m_hasSidecar;
			istr.ignore(2000, '\n');
		}
		else {
			char a[20] = {};
			bool valid;
			cout << endl << "Motorcycle information entry" << endl;
			Vehicle::read();
			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
			do {
				istr >> a;
				if (strcmp(a, "y") == 0 || strcmp(a, "Y") == 0) {
					valid = true;
					m_hasSidecar = true;
				}
				else if (strcmp(a, "n") == 0 || strcmp(a, "N") == 0) {
					valid = true;
					m_hasSidecar = false;
				}
				else {
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					valid = false;
				}
			} while (!valid);
		}
		return istr;
	}


	std::ostream& Motorcycle::write(std::ostream& ostr)const {
		if (Vehicle::isEmpty()) {
			ostr << "Invalid Motorcycle Object" << endl;
		}
		else {
			if (ReadWritable::isCsv()) {
				ostr << "M,";
				Vehicle::write();
				ostr << m_hasSidecar << endl;

			}
			else {
				ostr << "Vehicle type: Motorcycle"  << endl;
				Vehicle::write();
				if (m_hasSidecar) {
					cout << "With Sidecar" << endl;
				}
			}
		}
		return ostr;
	}



}