#pragma once
//kyurim kim	168819183	kkim125@myseneca.com
#ifndef SDDS_BASKET_H
#define SDDS_BASKET_H
#include <iostream> 

namespace sdds {
	class Basket {
		char* m_fruitName;
		int m_qty; // can not be less than one
		double m_price; // can not be less than zero
	public:
		Basket();
		Basket(const char* fruitName, int qty, double price);
		Basket(const Basket& bas);
		~Basket();
		void setName(const char* fn);
		void setQty(int qty);
		void setPrice(double);
		bool isempty() const;
		bool addPrice(double);
		std::ostream& display(std::ostream& os) const;
		Basket& operator=(const Basket& bas);
		bool operator==(const Basket& bas);
		bool operator!=(const Basket&);
	};
	std::ostream& operator<<(std::ostream& os, const Basket& b);
}
#endif
