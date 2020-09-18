//kyurim kim	168819183	kkim125@seneca.ca

#ifndef _SDDS_NUMBERBOXS_H
#define _SDDS_NUMBERBOXS_H

#include <iostream>
#include <cstring>

using namespace std;

namespace sdds {
	const int MAX_NAME = 15;

	template <class T>
	class NumbersBox {
		char m_name[MAX_NAME + 1];
		int m_size;
		T* m_items;

	public:
		NumbersBox() {
			m_name[0] = '\0';
			m_size = 0;
			m_items = nullptr;
		}

		NumbersBox(int size, const char* name) {
			if (size > 0 && name != nullptr && strcmp(name, "") != 0 && strlen(name) < MAX_NAME+1) {
				strcpy(m_name, name);
				m_size = size;
				m_items = new T[m_size];
			}
			else {
				m_name[0] = '\0';
				m_size = 0;
				m_items = nullptr;
			}
		}

		~NumbersBox() {
			delete[] m_items;
			m_items = nullptr;
		}

		T& operator[](int i) {
			return m_items[i];
		}

		NumbersBox<T>& operator*=(const NumbersBox<T>& other) {
			if (m_size == other.m_size) {
				for (int i = 0; i < m_size; i++) {
					m_items[i] *= other.m_items[i];
				}
			}
			return *this;
		}

		NumbersBox<T>& operator+=(T num) {
			T* temp = new T[m_size + 1];
			for (int i = 0; i < m_size; i++) {
				temp[i] = m_items[i];
			}
			temp[m_size] = num;
			delete[] m_items;
			m_items = temp;
			m_size++;
			return *this;
		}

		ostream& display(ostream& os) const {
			if (m_name == nullptr || strcmp(m_name, "") == 0 || m_size < 1) {
				os << "Empty Box" << endl;
			}
			else {
				os << "Box name: " << m_name << endl;
				for (int i = 0; i < m_size; i++)
				{
					os << m_items[i];
					if (i < m_size - 1) {
						os << ", ";
					}
				}
				os << endl;
			}
			return os;
		}

		friend ostream& operator<<(ostream& os, NumbersBox<T>& box) {
			box.display(os);
			return os;
		}
	};
}
#endif