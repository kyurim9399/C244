#pragma once
#ifndef SDDS_SAIYAN_H
#define SDDS_SAIYAN_H

namespace sdds {
	class Saiyan {
		char m_name[31];
		int m_dob; //<2020
		int m_power; //>0
		bool m_super; //saiyan이 진화할수 있는지 없는지 알수 있는 부울값
	public:
		Saiyan();
		Saiyan(const char* name, int dob, int power);
		bool isSuper() const;
		bool isValid() const;
		void setEmpty();
		void display() const;
		void set(const char* name, int dob, int power, bool super = false);
		bool hasLost(const Saiyan& other);
	};

}

#endif