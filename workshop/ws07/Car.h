//kyurim kim	168819183	kkim125@myseneca.com
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream> 
#include "Vehicle.h"

namespace sdds {
	const int MAX_CHAR = 20;
	const int MIN_YEAR = 2000;
	class Car : public Vehicle{
		char m_carType[MAX_CHAR + 1];
		int m_regYear;
	
	public:
		Car();
		Car(const char* type,int year, int speed, int seats);
		void finetune();
		std::ostream& display(std::ostream& os) const;
		std::istream& input(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& os, const Car& C);
	std::istream& operator>>(std::istream& in, Car& C);
}
#endif