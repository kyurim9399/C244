//kyurim kim	168819183	kkim125@myseneca.com

#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <cstring>
#include "Basket.h"

using namespace std;

namespace sdds {

	Basket::Basket() {
		m_fruitName = nullptr;
		m_qty = 0;
		m_price = 0;
	}

	Basket::Basket(const char* fruitName, int qty, double price) {
		if (
			fruitName != nullptr && 
			strcmp(fruitName, "") != 0 && 
			qty > 0 && price > 0
		) {
			m_fruitName = new char[strlen(fruitName) + 1];
			strcpy(m_fruitName, fruitName);
			m_qty = qty;
			m_price = price;
		}
		else {
			m_fruitName = nullptr;
			m_qty = 0;
			m_price = 0;
		}
	}

	Basket::Basket(const Basket& source) {
			m_fruitName = nullptr;
			*this = source;

	}
	 
	Basket::~Basket() {
		delete[] m_fruitName;
		m_fruitName = nullptr;
	}


	void Basket::setName(const char* fn) {
		if (fn != nullptr && strcmp(fn, "") != 0) {
			if (m_fruitName != nullptr) {
				delete[] m_fruitName;
				m_fruitName = nullptr;
			}
			m_fruitName = new char[strlen(fn) + 1];
			strcpy(m_fruitName, fn);
		}
		else {
			m_fruitName = nullptr;
		}
	}

	void Basket::setQty(int qty) {
		m_qty = qty > 0 ? qty : 0;
	}

	void Basket::setPrice(double price) {
		m_price = price > 0 ? price : 0;
	}

	bool Basket::isempty() const {
		return (m_fruitName == nullptr || strcmp(m_fruitName, "") == 0 || m_qty == 0 || m_price == 0);
	}

	bool Basket::addPrice(double price) {
		if (price > 0) {
			m_price += price;
			return true;
		}
		else {
			return false;
		}
	}


	ostream& Basket::display(ostream& os) const {
		if (isempty()) {
			os << "The Basket has not yet been filled" << endl;
		}
		else {
			os << "Basket Details" << endl;
			os << "Name: " << m_fruitName << endl;
			os << "Quantity: " << m_qty << endl;
			os.setf(ios::fixed);
			os.precision(2);
			os << "Price: " << m_price << endl;
		}
		return os;
	}


	Basket& Basket::operator=(const Basket& bas) {
		if (this != &bas) {
			m_qty = bas.m_qty;
			m_price = bas.m_price;
			delete[] m_fruitName;
			if (bas.m_fruitName != nullptr) {
				m_fruitName = new char[strlen(bas.m_fruitName) + 1];
				strcpy(m_fruitName, bas.m_fruitName);
			}
			else {
				m_fruitName = nullptr;
			}
		}
		return *this;
	}

	bool Basket::operator==(const Basket& bas) {
		if (strcmp(m_fruitName, bas.m_fruitName) == 0 &&
			m_qty == bas.m_qty &&
			m_price == bas.m_price
			) {
			return true;
		}
		else {
			return false;
		}	
	}


	bool Basket::operator!=(const Basket& bas) {
		if (m_price != bas.m_price) {
			return true;
		}
		else {
			return false;
		}
	}

	ostream& operator<<(ostream& os, const Basket& b) {
		b.display(os);
		return os;
	}


}


