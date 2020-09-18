//kyurim kim	168819183	kkim125@myseneca.com

#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <cstring>
#include "Engineer.h"

using namespace std;

namespace sdds {
	Engineer::Engineer() {
		m_esalary = 0.0;
		m_ewhours = 0;
		m_level = 0;
	}

	Engineer::Engineer(double esalary, int ewhours, int level) {
		if (esalary > 0.0 && ewhours >= MIN_HOURS && level >0 && level <=MAX_LEVEL) {
			m_ewhours = ewhours;
			m_level = level;
			setSalary(esalary);
		}
		else {
			m_esalary = 0.0;
			m_ewhours = 0;
			m_level = 0;
		}
	}

	void Engineer::setSalary(double esalary) {
		m_esalary = m_level == MAX_LEVEL ? esalary + 3000.0 : esalary;
	}

	bool Engineer::workHours() const{
		if (m_ewhours == MIN_HOURS) {
			return true;
		}
		else {
			return false;
		}
	}

	void Engineer::bonus() {
		if (!workHours()) {
			m_esalary *= 1.1;
		}
		else {
			m_esalary *= 1.05;
		}
	}

	std::ostream& Engineer::display(std::ostream& os) const {
		if (m_esalary > 0.0 && m_ewhours >= MIN_HOURS && m_level > 0 && m_level <= MAX_LEVEL) {
			os << "Engineer details" << endl;
			os << "level: " << m_level << endl;
			os.setf(ios::fixed);
			os.precision(2);
			os << "Salary: " << m_esalary << endl;
			os.unsetf(ios::fixed);
			os << "Working hours: " << m_ewhours << endl;
		}
		else {
			os << "Engineer is not initiated yet" << endl;
		}
		return os;
	}
}