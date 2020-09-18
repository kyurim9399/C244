//kyurim kim	168819183	kkim125@myseneca.ca
// Train.h
#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

namespace sdds {
	const int MAX_NAME = 30;
	const int MAX_DESC = 20;

	struct Cargo {
		char description[MAX_DESC+1]; //
		double weight;
	};

	class Train {
		char name[MAX_NAME+1];
		int id;
		struct Cargo* cargo; //will be used dynamic memory

	public:
		void setTrain(const char*, int);
		bool isEmpty() const;
		void display() const;
		void loadCargo(Cargo cargo);
		void unloadCargo();
	};

}

#endif