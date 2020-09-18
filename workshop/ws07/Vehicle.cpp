//kyurim kim	168819183	kkim125@myseneca.com

#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <cstring>
#include "Vehicle.h"

using namespace std;

namespace sdds {
	Vehicle::Vehicle() {
		m_speed = 0;
		m_noOfSeats = 0;
	}
	Vehicle::Vehicle(int speed, int seats) {
		if (speed >= MIN_SPEED && seats > 0) {
			m_speed = speed;
			m_noOfSeats = seats;
		}
		else {
			*this = Vehicle();
		}
	}
	bool Vehicle::finetune() {
		if (m_speed >= MAX_SPEED) {
			m_speed = MIN_SPEED;
			return true;
		}
		else {
			cout << "The car cannot be tuned" << endl;
			return false;
		}
	}

	std::ostream& Vehicle::display(std::ostream& os) const {
		if (m_speed >= MIN_SPEED && m_noOfSeats > 0) {
			os << "|" << m_speed << "|" << m_noOfSeats << endl;
			if (m_speed >= MAX_SPEED) {
				os << "Car has to be fine tuned for speed limit" << endl;
			}
		}
		else {
			os << "This Car is not initiated" << endl;
		}
		return os;
	}

	std::istream& Vehicle::input(std::istream& in) {
		int tem_speed;
		int tem_noOfSeats;
		cout << "Enter the Vehicle`s speed: ";
		in >> tem_speed;
		cout << "Enter no of seats: ";
		in >> tem_noOfSeats;
		Vehicle temp(tem_speed, tem_noOfSeats);
		if (temp.m_speed > 0) {
			*this = temp;
		}
		return in;
	}

	std::ostream& operator<<(std::ostream& os, const Vehicle& v) {
		v.display(os);
		return os;
	}


	std::istream& operator>>(std::istream& in, Vehicle& V){
		V.input(in);
		return in;
	}



}