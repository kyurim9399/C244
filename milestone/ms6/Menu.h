//kyurim kim	168819183	kkim125@myseneca.ca


#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>

namespace sdds {
	const int MAX_NO_OF_ITEMS = 10;
	class MenuItem {
		//no public members
		friend class Menu;
		char* m_content;

		MenuItem();
		MenuItem(const char* cont);
		MenuItem(const MenuItem&) = delete;
		MenuItem& operator=(const MenuItem&) = delete;
		~MenuItem();
		void display() const;
		//MenuItem& operator=(const MenuItem& m);
		// ���� �ٸ� �Լ��� �ʿ��ϸ� �߰��ص� ��.
	};

	class Menu {
		char* Title;
		MenuItem* menuitem[MAX_NO_OF_ITEMS];
		int Indentation;//0���� �����ϰ� value�� 1�϶����� ���������� 4ĭ �鿩���� ��.
		int NumOfItem;//�ٸ� variable�ʿ��ϸ� �־ ��

	public:
		Menu();
		Menu(const char* title, int indent = 0);
		Menu(const Menu& menu);
		~Menu();

		Menu& operator=(const Menu& menu);
		operator bool() const;
		bool isEmpty() const;
		void display() const;
		Menu& operator=(const char* c);
		void add(const char* c);
		Menu& operator<<(const char* c);
		int run() const;
		operator int() const;
	};
}

#endif