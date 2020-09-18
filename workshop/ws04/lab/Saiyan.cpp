//kyurim kim	168819183	kkim125@myseneca.ca
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <cstring>
#include "Saiyan.h"

using namespace std;

namespace sdds {
	Saiyan::Saiyan() {
		setEmpty();
	}
	Saiyan::Saiyan(const char* name, int dob, int power) {
		m_super = false;
		if (name != nullptr && strcmp(name, "") != 0 && dob < 2020 && power > 0 ){ 
			
			strcpy(m_name, name);
			m_dob = dob;
			m_power = power;
			//name[0] != '\0'
		}
		else {
			setEmpty();
			
		}
	}
	bool Saiyan::isSuper() const {
		return m_super;
	}

	bool Saiyan::isValid() const {
			return strcmp(m_name, "") != 0 && m_dob < 2020 && m_power > 0;
	}

	void Saiyan::setEmpty() {
		strcpy(m_name, "");
		m_dob = 0;
		m_power = 0;
		m_super = false;
	}

	void Saiyan::display() const {
		if (isValid())
		{
			cout << m_name << endl;
			cout << "DOB: " << m_dob << " Power: " << m_power << endl;
			cout << "Super Saiyan Ability: ";
				if (isSuper()){
					cout << "Super Saiyan.";
				}
				else {
					cout << "Not super Saiyan.";
				}
				cout << endl;
		}
		else
		{
			cout << "Invalid Saiyan!";
		}
		cout << endl;
	}


	void Saiyan::set(const char* name, int dob, int power, bool super) {
		if (strcmp(name, "") != 0 && dob < 2020 && power > 0 && name!=nullptr) {
			strcpy(m_name, name);
			m_dob = dob;
			m_power = power;
			m_super = super;
		}
		else {
			setEmpty();
		}
	}

	bool Saiyan::hasLost(const Saiyan& other) {
		return (isValid() && other.isValid() && m_power < other.m_power);
	}



}