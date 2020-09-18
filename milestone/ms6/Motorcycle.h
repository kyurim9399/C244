//kyurim kim	168819183	kkim125@myseneca.ca
#ifndef SDDS_MOTORCYCLE_H
#define SDDS_MOTORCYCLE_H
#include <iostream>
#include "Vehicle.h"

namespace sdds {

	class Motorcycle : public Vehicle {
		bool m_hasSidecar;

	public:
		Motorcycle();
		Motorcycle(const char* licensePlate, const char* makemodel);
		Motorcycle(const Motorcycle&) = delete;
		Motorcycle& operator=(const Motorcycle&) = delete;
		std::istream& read(std::istream& istr = std::cin);
		std::ostream& write(std::ostream& ostr = std::cout)const;
	};

}

#endif