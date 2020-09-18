//kyurim kim	168819183	kkim125@myseneca.ca
#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H
#include <iostream>
#include "ReadWritable.h"

namespace sdds {
	const int MAX_LICENSE_PLATE = 8;
	const int MIN_MODEL = 2;

	class Vehicle : public ReadWritable {
		char* m_licensePlate;
		char* m_makeModel;
		int m_parkingSpot;

	public:
		Vehicle();
		Vehicle(const char* licensePlate, const char* makemodel);
		Vehicle(const Vehicle&) = delete;
		Vehicle& operator=(const Vehicle&) = delete;
		~Vehicle();
		int getParkingSpot() const;
		void setParkingSpot(int parkingSpot);
		bool compare(const char* c1, const char* c2) const;
		bool operator==(const char* licensePlate) const;
		friend bool operator==(const Vehicle& v1, const Vehicle& v2);
		std::istream& read(std::istream& istr = std::cin);
		std::ostream& write(std::ostream& ostr = std::cout)const;


	protected:
		void setEmpty();
		bool isEmpty() const;
		const char* getLicensePlate() const;
		const char* getMakeModel() const;
		void setMakeModel(const char* makemodel);
		void setLicensePlate(const char* licensePlate);
	};

}

#endif