// Name kyurim kim   Date 2020.01.21    Reason NDD		e-mail kkim125@myseneca 

// Gift.h
#ifndef GIFT_H
#define GIFT_H

namespace sdds
{
	const int MAX_DESC = 15;
	const double MAX_PRICE = 999.99;

	struct Gift
	{
		char g_description[MAX_DESC + 1];
		double g_price;
		int g_units;
	};

	void gifting(char* description);
	void gifting(double& price);
	void gifting(int& units);
	void display(const Gift& gift);
}

#endif