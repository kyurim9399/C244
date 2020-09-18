// Gift.cpp
// Name kyurim kim   Date 2020.01.21    Reason NDD		e-mail kkim125@myseneca 

#include <iostream>
#include <cctype>
#include <cstring>
#include"Gift.h"
using namespace std;

namespace sdds
{
	void gifting(char* description)
	{
		cout << "Enter gift description: ";
		cin.width(MAX_DESC + 1);
		cin >> description;
	}

	void gifting(double&price)
	{
		cout << "Enter gift price: ";
		cin >> price;
		while (price<0 || price>MAX_PRICE)
		{
			cout << "Gift price must be between 0 and " << MAX_PRICE << endl;
			cout << "Enter gift price: ";
			cin >> price;
		}

	}



	void gifting(int& units)
	{
		cout << "Enter gift units: ";
		cin >> units;
		while (units < 1)
		{
			cout << "Gift units must be at least 1" << endl;
			cout << "Enter gift units: ";
			cin >> units;
		}
	}



	void display(const Gift& gift)
	{
		cout << "Gift Details:" << endl;
		cout << "Description: " << gift.g_description << endl;
		cout << "Price: " << gift.g_price << endl;
		cout << "Units: " << gift.g_units << endl;
	}
}