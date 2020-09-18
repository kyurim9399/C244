//kyurim kim	168819183	kkim125@myseneca.ca
#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <cstring>
#include "Vehicle.h"
#include "Utils.h"

using namespace std;

namespace sdds {

	Vehicle::Vehicle() {
		m_licensePlate = nullptr;
		m_makeModel = nullptr;
		m_parkingSpot = -1;
	}

	Vehicle::Vehicle(const char* licensePlate, const char* makemodel) {
		if (licensePlate != nullptr && strcmp(licensePlate, "") != 0 && strlen(licensePlate) <= MAX_LICENSE_PLATE && makemodel != nullptr && strlen(makemodel) >= MIN_MODEL) {
			m_licensePlate = new char[strlen(licensePlate) + 1];
			strcpy(m_licensePlate, licensePlate);

			m_makeModel = new char[strlen(makemodel) + 1];
			strcpy(m_makeModel, makemodel);

			m_parkingSpot = 0;
		}
		else {
			m_licensePlate = nullptr;
			m_makeModel = nullptr;
			m_parkingSpot = -1;
		}
	}

	Vehicle::~Vehicle() {
		delete[] m_licensePlate;
		m_licensePlate = nullptr;
		delete[] m_makeModel;
		m_makeModel = nullptr;
	}

	//prodected
	void Vehicle::setEmpty() {
		if (m_licensePlate != nullptr) {
			delete[] m_licensePlate;
		}
		m_licensePlate = nullptr;

		if (m_makeModel != nullptr) {
			delete[] m_makeModel;
		}
		m_makeModel = nullptr;
		m_parkingSpot = -1;
	}

	bool Vehicle::isEmpty() const {
		return m_licensePlate == nullptr || m_makeModel == nullptr || m_parkingSpot < 0;
	}

	const char* Vehicle::getLicensePlate() const {
		return m_licensePlate;
	}

	const char* Vehicle::getMakeModel() const {
		return m_makeModel;
	}

	void Vehicle::setMakeModel(const char* makemodel) {
		if (makemodel != nullptr && strlen(makemodel) >= MIN_MODEL) {
			if (getMakeModel() != nullptr) {
				delete[] m_makeModel;
				m_makeModel = nullptr;
			}
			m_makeModel = new char[strlen(makemodel) + 1];
			strcpy(m_makeModel, makemodel);
		}
		else {
			setEmpty();
		}
	}

	void Vehicle::setLicensePlate(const char* licensePlate) {
		if (licensePlate != nullptr && strcmp(licensePlate, "") != 0 && strlen(licensePlate) <= MAX_LICENSE_PLATE) {
			if (m_licensePlate != nullptr) {
				delete[] m_licensePlate;
				m_licensePlate = nullptr;
			}
			m_licensePlate = new char[strlen(licensePlate) + 1];
			strcpy(m_licensePlate, licensePlate);
		}
		else {
			setEmpty();
		}
	}

	//public
	int Vehicle::getParkingSpot() const {
		return m_parkingSpot;
	}

	void Vehicle::setParkingSpot(int parkingSpot) {
		if (parkingSpot >= 0) {
			m_parkingSpot = parkingSpot;
		}
		else {
			setEmpty();
		}
	}

	bool Vehicle::compare(const char* c1, const char* c2) const {
		bool result;
		char* temp1 = new char[strlen(c1) + 1];
		strcpy(temp1, c1);
		Toupper(temp1);

		char* temp2 = new char[strlen(c2) + 1];
		strcpy(temp2, c2);
		Toupper(temp2);

		result = strcmp(temp1, temp2) == 0 ? true : false;

		delete[] temp1;
		temp1 = nullptr;

		delete[] temp2;
		temp2 = nullptr;

		return result;
	}


	bool Vehicle::operator==(const char* licensePlate) const {
		if (!isEmpty() && licensePlate != nullptr && strcmp(licensePlate, "") != 0 && strlen(licensePlate) <= MAX_LICENSE_PLATE) {
			return compare(getLicensePlate(), licensePlate);
		}
		else {
			return false;
		}
	}

	bool operator==(const Vehicle& v1, const Vehicle& v2) {
		if (!v1.isEmpty() && !v2.isEmpty()) {
			return v1.compare(v1.getLicensePlate(), v2.getLicensePlate());
		}
		else {
			return false;
		}
	}

	std::istream& Vehicle::read(std::istream& istr) {
		int parkingSpot;
		char* licensePlate = nullptr;
		char* makeModel = nullptr;
		if (ReadWritable::isCsv()) {
			licensePlate = new char[MAX_LICENSE_PLATE + 1];
			makeModel = new char[61];
			istr >> parkingSpot;
			setParkingSpot(parkingSpot);
			istr.ignore(2000, ',');
			istr.get(licensePlate, MAX_LICENSE_PLATE + 1, ',');
			Toupper(licensePlate);
			setLicensePlate(licensePlate);
			istr.ignore(2000, ',');
			istr.get(makeModel, 61, ',');
			setMakeModel(makeModel);
			istr.ignore(2000, ',');
			delete[] licensePlate;
			licensePlate = nullptr;
			delete[] makeModel;
			makeModel = nullptr;
		}
		else {
			bool valid;
			cout << "Enter Licence Plate Number: ";
			do {
				licensePlate = new char[100];
				istr.getline(licensePlate, 100);
				if (strcmp(licensePlate, "") != 0 && strlen(licensePlate) <= MAX_LICENSE_PLATE) {
					Toupper(licensePlate);
					setLicensePlate(licensePlate);
					valid = true;
				}
				else {
					cout << "Invalid Licence Plate, try again: ";
					valid = false;
				}
				delete[] licensePlate;
				licensePlate = nullptr;
			} while (!valid);

			cout << "Enter Make and Model: ";
			do {
				makeModel = new char[100];
				istr.getline(makeModel, 100);
				if (strlen(makeModel) <= 60 && strlen(makeModel) >= MIN_MODEL) {
					if (getMakeModel() != nullptr) {
						delete[] m_makeModel;
					}
					m_makeModel = new char[strlen(makeModel) + 1];
					strcpy(m_makeModel, makeModel);
					valid = true;
				}
				else {
					cout << "Invalid Make and model, try again: ";
					valid = false;
				}
				delete[] makeModel;
				makeModel = nullptr;
			} while (!valid);
			setParkingSpot(0);
		}
		return istr;
	}

	std::ostream& Vehicle::write(std::ostream& ostr)const {
		if (isEmpty()) {
			ostr << "Invalid Vehicle Object" << endl;
		}
		else {
			if (isCsv()) {
				ostr << getParkingSpot() << "," << getLicensePlate() << "," << getMakeModel() << ",";
			}
			else {
				ostr << "Parking Spot Number: ";
				if (getParkingSpot() == 0) {
					ostr << "N/A" << endl;
				}
				else {
					ostr << getParkingSpot() << endl;
				}
				ostr << "Licence Plate: " << getLicensePlate() << endl;
				ostr << "Make and Model: " << getMakeModel() << endl;
			}
		}
		return ostr;
	}

}