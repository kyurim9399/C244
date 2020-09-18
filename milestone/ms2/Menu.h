//kyurim kim	168819183	kkim125@myseneca.com


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
		std::ostream& display(std::ostream& os = std::cout) const;
		//MenuItem& operator=(const MenuItem& m);
		// 만약 다른 함수가 필요하면 추가해도 됨.
	};

	class Menu {
		char* Title;
		MenuItem* menuitem[MAX_NO_OF_ITEMS];
		int Indentation;//0부터 시작하고 value가 1일때마다 오른쪽으로 4칸 들여쓰기 됨.
		int NumOfItem;//다른 variable필요하면 넣어도 됨

	public:
		Menu();
		Menu(const char* title, int indent = 0);
		Menu(const Menu& menu);
		~Menu();
		Menu& operator=(const Menu& menu);
		operator bool() const;
		void setEmpty();
		bool isEmpty() const;
		std::ostream& display(std::ostream& os = std::cout) const;
		Menu& operator=(const char* c);
		void add(const char* c);
		Menu& operator<<(const char* c);
		int run() const;
		operator int() const;

	};
}

#endif