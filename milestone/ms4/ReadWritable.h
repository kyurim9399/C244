//kyurim kim	168819183	kkim125@myseneca.ca
#ifndef SDDS_READWRITABLE_H
#define SDDS_READWRITABLE_H
#include <iostream>

namespace sdds {

	class ReadWritable {
		bool flag;
		
	public:
		ReadWritable();
		virtual ~ReadWritable() {};
		bool isCsv() const;
		void setCsv(bool value);
		virtual std::istream& read(std::istream& istr = std::cin) = 0;
		virtual std::ostream& write(std::ostream& ostr = std::cout)const = 0;
	};
	std::istream& operator>>(std::istream&, ReadWritable&);
	std::ostream& operator<<(std::ostream&, const ReadWritable&);

}

#endif