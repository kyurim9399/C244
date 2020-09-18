//kyurim kim	168819183	kkim125@myseneca.com

#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <cstring>
#include "Menu.h"

using namespace std;

namespace sdds {
	//MenuItem
	MenuItem::MenuItem() {
		m_content = nullptr;
	}

	MenuItem::MenuItem(const char* content) {
		if (content != nullptr && strcmp(content, "") != 0) {
			m_content = new char[strlen(content)+1];
			strcpy(m_content, content);
		}
		else {
			m_content = nullptr;
		}
	}

	std::ostream& MenuItem::display(std::ostream& os) const {
		if (m_content != nullptr && strcmp(m_content, "") != 0) {
			os << m_content << endl;
		}
		return os;
	}

	MenuItem::~MenuItem() {
		delete[] m_content;
		m_content = nullptr;
	}

	//MENU
	Menu::Menu() :menuitem{nullptr} {
		Title = nullptr;
		Indentation = 0;
		NumOfItem = 0;
	}

	Menu::Menu(const char* title, int indent ) : Menu() {
		if (title != nullptr && strcmp(title, "") != 0 && indent>=0) {
			Title = new char[strlen(title) + 1];
			strcpy(Title, title);
			Indentation = indent;
		}
		else {
			Title = nullptr;
			Indentation = 0;
			NumOfItem = 0;
		}
	}

	Menu::Menu(const Menu& m){
		Title = nullptr;
		NumOfItem = 0;
		*this = m;
	}
	
	Menu& Menu::operator=(const Menu& m) {
		if (this != &m) {
			
			delete[] Title;
			if (m.Title != nullptr) {
				Title = new char[strlen(m.Title) + 1];
				strcpy(Title, m.Title);
			}
			else {
				Title = nullptr;
			}
			
			for (int i = 0; i < NumOfItem; i++) {
					delete menuitem[i];
					menuitem[i] = nullptr;
			}
			if (m.NumOfItem > 0) {
				for (int i = 0; i < m.NumOfItem; i++) {
					menuitem[i] = new MenuItem(m.menuitem[i]->m_content);
				}
			}
			Indentation = m.Indentation;
			NumOfItem = m.NumOfItem;
		}
		else {
			setEmpty();
		}
		return *this;
	}
	
	Menu::operator bool() const {
		return !isEmpty();
	}

	void Menu::setEmpty() {
		if (Title != nullptr) {
			delete[] Title;
		}
		Title = nullptr;
		for (int i = 0; i < NumOfItem; i++) {
			if (menuitem[i] != nullptr) {
				delete menuitem[i];
			}
			menuitem[i] = nullptr;
		}
		Indentation = 0;
		NumOfItem = 0; 
	}

	bool Menu::isEmpty() const {
		return Title == nullptr;
	}


	std::ostream& Menu::display(std::ostream& os) const {
		if (isEmpty()) {
			os << "Invalid Menu!" << endl;
		}
		else {
			if (Indentation > 0) {
				for (int i = 0; i < Indentation; i++) {
					os << "    ";
				}
				os << Title << endl;

				if (NumOfItem == 0) {
					os << "No Items to display!" << endl;
				}
				else {
					for (int i = 0; i < NumOfItem; i++) {
						for (int i = 0; i < Indentation; i++) {
							os << "    ";
						}
						os << i + 1 << "- ";
						menuitem[i]->display();
					}
					for (int i = 0; i < Indentation; i++) {
						os << "    ";
					}
					os << "> ";
				}
			}
			else {
				os << Title << endl;
				for (int i = 0; i < NumOfItem; i++) {
					os << i + 1 << "- ";
					menuitem[i]->display();
				}
				os << "> ";
			}
		}
		return os;
	}



	Menu& Menu::operator=(const char* c) {
		if (c != nullptr && strcmp(c, "") != 0) {
			if (Title != nullptr) {
				delete[] Title;
			}
			Title = new char[strlen(c) + 1];
			strcpy(Title, c);
		}
		else {
			setEmpty();
		}
		return *this;
	}


	void Menu::add(const char* c) {
		if (isEmpty()) {
			return;
		}
		else {
			if (c != nullptr && strcmp(c, "") != 0 && NumOfItem < MAX_NO_OF_ITEMS) {
				menuitem[NumOfItem] = new MenuItem(c);
				NumOfItem++;
			}
			else {
				setEmpty();
			}
		}
	}

	Menu& Menu::operator<<(const char* c) {
		add(c);
		return *this;
	}

	int Menu::run() const{
		int selection;
		bool valid;
		display();
		if (NumOfItem == 0) {
			selection = 0;
		}
		else {
			do {
				cin >> selection;
				if (cin.fail()) {
					cout << "Invalid Integer, try again: ";
					valid = false;
				}
				else {
					if (selection < 1 || selection > NumOfItem) {
						cout << "Invalid selection, try again: ";
						valid = false;
					}
					else {
						valid = true;
					}
				}
				cin.clear();
				cin.ignore(2000, '\n');
			} while (valid == false);
		}
		return selection;
	}

	Menu::operator int() const{
		return run();
	}

	Menu::~Menu() {
		delete[] Title;
		Title = nullptr;
		
		for (int i = 0; i < NumOfItem; i++) {
				delete menuitem[i];
				menuitem[i] = nullptr;
		}
	}
}