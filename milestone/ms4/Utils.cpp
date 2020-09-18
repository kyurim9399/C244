//kyurim kim	168819183	kkim125@myseneca.ca
#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <cstring>
#include "Utils.h"

using namespace std;

namespace sdds {
	void Toupper(char* c) {
		for (unsigned i = 0; i < strlen(c); i++) {
			c[i] = toupper(c[i]);
		}
	}
}