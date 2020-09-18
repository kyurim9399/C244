//kyurim kim	168819183	kkim125@myseneca.com

#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <cstring>
#include "Car.h"


using namespace std;

namespace sdds {
	Car::Car() {
		m_carType[0] = '\0';
		m_regYear = 0;
	}


	Car::Car(const char* type, int year, int speed, int seats) : Vehicle(speed, seats) {
		if (type != nullptr && strcmp(type,"")!=0 && year >= MIN_YEAR && speed >= MIN_SPEED && seats > 0) {
			strncpy(m_carType, type, MAX_CHAR);
			m_carType[MAX_CHAR] = '\0';
			m_regYear = year;
		}
		else {
			*this = Car();
		}
	}

	void Car::finetune() {
		if (m_regYear >= MIN_YEAR) {
			if (Vehicle::finetune()) {
				cout << "This car is finely tuned to default speed" << endl;
			}
		}
		else {
			cout << "Car cannot be tuned and has to be scraped" << endl;
		}
	}

	std::ostream& Car::display(std::ostream& os) const {
		if (m_regYear == 0) {
			os << "Car is not initiated yet" << endl;
		}
		else {
			cout.width(20);
			cout.setf(ios::left);
			os << m_carType << m_regYear;
			Vehicle::display(os);
		}
		return os;
	}

	std::istream& Car::input(std::istream& in) {
		char tmp_type[MAX_CHAR+1];
		int tmp_year;

		cout << "Enter the car type: ";
		in >> tmp_type;
		cout << "Enter the car registration year: ";
		in >> tmp_year;

		if (strcmp(tmp_type, "") != 0 && tmp_year >= MIN_YEAR) {
			strncpy(m_carType, tmp_type, MAX_CHAR);
			m_carType[MAX_CHAR] = '\0';
			m_regYear = tmp_year;
		}
		Vehicle::input(in);
		
		return in;
	}
	
	std::ostream& operator<<(std::ostream& os, const Car& C) {
		C.display(os);
		return os;
	}

	std::istream& operator>>(std::istream& in, Car& C) {
		C.input(in);
		return in;
	}

}