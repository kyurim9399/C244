//kyurim kim	168819183	kkim125@myseneca.ca		2020.02.11
#ifndef SDDS_ENGINE_H
#define SDDS_ENGINE_H

namespace sdds {
	const int MAX_E_TYPE = 30;
	class Engine {
		char engine_type[MAX_E_TYPE + 1];
		double size;

	public:
		Engine();
		Engine(const char* et, double s);
		double get() const;
		void display() const;
	};
}

#endif
