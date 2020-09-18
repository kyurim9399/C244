//kyurim kim	168819183	kkim125@myseneca.com
#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H
#include <iostream> 

namespace sdds {
	const int MIN_SPEED = 100;
	const int MAX_SPEED = 140;
	class Vehicle {
		int m_speed;
		int m_noOfSeats;
		//valid : m_speed>=100 && m_noOfSeats > 0
	public:
		Vehicle();
		Vehicle(int speed, int seats);
		bool finetune();
		std::ostream& display(std::ostream& os) const;
		std::istream& input(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& os, const Vehicle& v);
	std::istream& operator>>(std::istream& in, Vehicle& V);

}
#endif