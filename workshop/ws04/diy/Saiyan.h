//kyurim kim	//168819183		//kkim125@myseneca.ca
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_SAIYAN_H
#define SDDS_SAIYAN_H

namespace sdds {
	const int MAX_NAME = 30;
	const int EMPTY_DOB = 2020;
	class Saiyan {
		char *m_name;
		int m_dob; //<2020
		int m_power; //>0
		bool m_super; //saiyan이 진화할수 있는지 없는지 알수 있는 부울값
		int m_level; //>=0 of super, and initially set to zero
	public:
		Saiyan();
		~Saiyan();

		Saiyan(const char* name, int dob, int power);

		bool isSuper() const;
		bool isValid() const;
		void setEmpty();
		void display() const;
		void set(const char* name, int dob, int power, int level = 0, bool super = false);
		bool hasLost(Saiyan& other);
		void powerup();
	};

}

#endif