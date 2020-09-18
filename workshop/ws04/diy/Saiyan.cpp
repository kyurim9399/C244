//kyurim kim	168819183	kkim125@myseneca.ca
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <cstring>
#include "Saiyan.h"

using namespace std;

namespace sdds {
	Saiyan::Saiyan() {
		m_name = nullptr;
		m_dob = EMPTY_DOB;
		m_power = 0;
		m_level = 0;
		m_super = false;
	}

	Saiyan::~Saiyan() {
		delete[] m_name;
		m_name = nullptr;
	}

	Saiyan::Saiyan(const char* name, int dob, int power) {
		if (name != nullptr && strcmp(name, "") != 0 && dob < 2020 && power > 0) {
			int len = strlen(name);
			m_name = new char[len + 1];
			strcpy(this->m_name, name);
			m_dob = dob;
			m_power = power;
			m_level = 0;
			m_super = false;
			}
		else {
			m_name = nullptr;
			m_dob = EMPTY_DOB;
			m_power = 0;
			m_super = false;
			m_level = 0;
		}
	}

	bool Saiyan::isSuper() const {
		return m_super;
	}

	bool Saiyan::isValid() const {
			return m_name != nullptr && strcmp(m_name, "") != 0 && m_dob < 2020 && m_power > 0;
	}

	void Saiyan::setEmpty() {
		m_name = nullptr;
		m_dob = EMPTY_DOB;
		m_power = 0;
		m_super = false;
	}

	void Saiyan::display() const {
		if (m_power > 0)
		{
			cout << m_name << endl;
			cout << "DOB: " << m_dob << " Power: " << m_power << endl;
			cout << "Super Saiyan Ability: ";
				if (isSuper()){
					cout << "Super Saiyan." << endl;
					cout << "Super Saiyan level is: " << m_level;
				}
				else {
					cout << "Not super Saiyan."<< endl;
				}
		}
		else
		{
			cout << "Invalid Saiyan!";
		}
		cout << endl;
	}


	void Saiyan::set(const char* name, int dob, int power, int level, bool super) {
		if (name != nullptr && strcmp(name, "") != 0 && dob < 2020 && power > 0) {
			int len = strlen(name);
			m_name = new char[len+1];
			strcpy(this->m_name, name);
			m_dob = dob;
			m_power = power;
			if (super) {
				m_level = level;
				m_super = super;
			}
			else {
				m_level = 0;
			}
		}
		else {
			m_name = nullptr;
			m_dob = EMPTY_DOB;
			m_power = 0;
			m_super = false;
			m_level = 0;
		}

	}


	bool Saiyan::hasLost(Saiyan& other){
		if (this->isValid() && other.isValid()) {
			this->powerup();
			other.powerup();

			if (m_power > other.m_power) {
				return false;
			}
			else {
				return true;
			}
		}
		else {
			return false;
		}
	}

	void Saiyan::powerup() {
		if (isSuper()) {
			m_power *= (m_level + 1);
		}
	}
}