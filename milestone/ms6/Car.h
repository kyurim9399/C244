//kyurim kim	168819183	kkim125@myseneca.ca
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include "Vehicle.h"

namespace sdds {

	class Car : public Vehicle {
		bool m_carwash;

	public:
		Car();
		Car(const char* licensePlate, const char* makemodel);
		Car(const Car&) = delete;
		Car& operator=(const Car&) = delete;
		std::istream& read(std::istream& istr = std::cin);
		std::ostream& write(std::ostream& ostr = std::cout)const;
	};

}

#endif