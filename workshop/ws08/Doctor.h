//kyurim kim	168819183	kkim125@myseneca.com
#ifndef SDDS_DOCTOR_H
#define SDDS_DOCTOR_H
#include <iostream> 
#include "Employee.h"

namespace sdds {
	const int MIN_W_HOURS = 6;
	const int MAX_CHAR = 20;
	class Doctor : public Employee {
		char m_type[MAX_CHAR + 1]; //specialist or general
		double m_salary; //specialist = general + 2000
		int m_whours; //working hours
		bool m_specialist; // indicate whethere a doctor is a specialist // optional // defualt = false
	public:
		Doctor();
		Doctor(const char* type, double salary, int whours, bool specialist = false);
		void setSalary(double);
		bool workHours() const;
		void bonus();
		std::ostream& display(std::ostream& os) const;

	};
}
#endif