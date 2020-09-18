//kyurim kim	168819183	kkim125@myseneca.com
#ifndef SDDS_ENGINEER_H
#define SDDS_ENGINEER_H
#include <iostream> 
#include "Employee.h"

namespace sdds {
	const int MIN_HOURS = 5;
	const int MAX_LEVEL = 4;

	class Engineer : public Employee {
		double m_esalary;
		int m_ewhours;
		int m_level;
	public:
		Engineer();
		Engineer(double esalary, int ewhours, int level);
		void setSalary(double esalary);
		bool workHours() const;
		void bonus();
		std::ostream& display(std::ostream& os) const;
	};
}
#endif