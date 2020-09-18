//kyurim kim	168819183	kkim125@myseneca.ca
// Gift.cpp


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <cstring>
#include "Gift.h"

using namespace std;

namespace sdds
{
	void gifting(char* description)
	{
		cout << "Enter gift description: ";
		cin.width(MAX_DESC + 1);
		cin >> description;
	}

	void gifting(double& price)
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
		if (gift.wrap_layers == 0)
		{
			cout << "Unwrapped" << endl;
		}
		else
		{
			cout << "Wrap Layers: " << gift.wrap_layers << endl;
			for (int x = 0; x < gift.wrap_layers; x++) {
				cout << "Wrap #" << x + 1 << ": " << gift.wrap[x].pattern << endl;
			}
			
		}
	}





	bool wrap(Gift& gift)
	{
		bool success;
		if (gift.wrap_layers > 0)
		{
			success = false;
			cout << "Gift is already wrapped!" << endl;
		}
		else
		{
			cout << "Wrapping gifts..." << endl;
			cout << "Enter the number of wrapping layers for the Gift: ";
			cin >> gift.wrap_layers;
			while (gift.wrap_layers < 1)
			{
				cout << "Layers at minimum must be 1, try again." << endl;
				cout << "Enter the number of wrapping layers for the Gift: ";
				cin >> gift.wrap_layers;
			}

			
			gift.wrap = new Wrapping[gift.wrap_layers];
			for (int x = 0; x < gift.wrap_layers; x++)
			{
				cout << "Enter wrapping pattern #" << x + 1 << ": ";
				cin.width(MAX_PATTERN + 1);
				gift.wrap[x].pattern = nullptr;
				gift.wrap[x].pattern = new char[MAX_PATTERN+1];
				cin >> gift.wrap[x].pattern;
			}

			success = true;
		}

		return success;
	}



	bool unwrap(Gift& gift)
	{
		bool success;
		if (gift.wrap_layers == 0) {
			cout << "Gift isn't wrapped! Can't unwrap." << endl;
			success = false;
		}

		else {
			cout << "Gift being unwrapped." << endl;

			delete[] gift.wrap;
			gift.wrap = nullptr;
			gift.wrap_layers = 0;
			success = true;
		}
		return success;
	}



	void gifting(Gift& gift)
	{
		cout << "Preparing a gift..." << endl;

		cout << "Enter gift description: ";
		cin.width(MAX_DESC + 1);
		cin >> gift.g_description;

		cout << "Enter gift price: ";
		cin >> gift.g_price;
		while (gift.g_price<0 || gift.g_price>MAX_PRICE)
		{
			cout << "Gift price must be between 0 and " << MAX_PRICE << endl;
			cout << "Enter gift price: ";
			cin >> gift.g_price;
		}

		cout << "Enter gift units: ";
		cin >> gift.g_units;
		while (gift.g_units < 1)
		{
			cout << "Gift units must be at least 1" << endl;
			cout << "Enter gift units: ";
			cin >> gift.g_units;
		}

		wrap(gift);

	}
}

