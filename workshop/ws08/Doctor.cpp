//kyurim kim	168819183	kkim125@myseneca.com

#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <cstring>
#include "Doctor.h"


using namespace std;

namespace sdds {
	Doctor::Doctor() {
		m_type[0] = '\0';
		m_salary = 0.0;
		m_whours = 0;
		m_specialist = false;
	}

	Doctor::Doctor(const char* type, double salary, int whours, bool specialist) {
		if (type != nullptr && strcmp(type, "") != 0 && salary > 0.0 && whours >= MIN_W_HOURS) {
			strncpy(m_type, type, MAX_CHAR);
			m_type[MAX_CHAR] = '\0';
			m_whours = whours;
			m_specialist = specialist;
			setSalary(salary);
		}
		else {
			m_type[0] = '\0';
			m_salary = 0.0;
			m_whours = 0;
			m_specialist = false;
		}
	}

	void Doctor::setSalary(double salary) {
		m_salary = m_specialist ? salary + 2000.0 : salary;
	}

	bool Doctor::workHours() const{
		if (m_whours == MIN_W_HOURS) {
			return true;
		}
		else {
			return false;
		}
	}

	void Doctor::bonus() {
		if (!workHours()) {
			m_salary *= 1.1;
		}
		else {
			m_salary *= 1.05;
		}
	}

	std::ostream& Doctor::display(std::ostream& os) const {
		if (m_salary > 0.0 && m_whours >= MIN_W_HOURS) {
			os << "Doctor details" << endl;
			os << "Doctor Type: " << m_type << endl;
			os.setf(ios::fixed);
			os.precision(2);
			os << "Salary: " << m_salary << endl;
			os.unsetf(ios::fixed);
			os << "Working Hours: " << m_whours << endl;
		}
		else {
			os << "Doctor is not initiated yet" << endl;
		}
		return os;
	}

}
