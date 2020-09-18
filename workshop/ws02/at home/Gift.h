//kyurim kim	168819183	kkim125@myseneca.ca
// Gift.h
#ifndef SDDS_GIFT_H 
#define SDDS_GIFT_H

namespace sdds {

	const int MAX_DESC = 15;
	const double MAX_PRICE = 999.99;
	const int MAX_PATTERN = 20;

	struct Gift {
		char g_description[MAX_DESC + 1];
		double g_price; 
		int g_units; 
		struct Wrapping* wrap; 
		int wrap_layers;
	};

	struct Wrapping {
		char* pattern; 
	};

	void gifting(char* desc);
	void gifting(double& price);
	void gifting(int& units);
	void gifting(Gift& gift);
	void display(const Gift& gift);
	bool wrap(Gift& gift);
	bool unwrap(Gift& gift);

}

#endif 