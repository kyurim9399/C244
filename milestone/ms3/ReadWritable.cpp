//kyurim kim	168819183	kkim125@myseneca.com
#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <cstring>
#include "ReadWritable.h"

using namespace std;

namespace sdds {
	ReadWritable::ReadWritable() {
		flag = false;
	}

	bool ReadWritable::isCsv() const {
		return flag;
	}

	void ReadWritable::setCsv(bool value) {
		flag = value;
	}

	std::istream& operator>>(std::istream& is, ReadWritable& r) {
		r.read(is);
		return is;
	}
	std::ostream& operator<<(std::ostream& os, const ReadWritable& r) {
		r.write(os);
		return os;
	}
}
