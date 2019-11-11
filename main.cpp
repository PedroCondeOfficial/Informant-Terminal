#include <string>
#include <iostream>
#include "stack.h"
using namespace std;

void terminal_loop();
void clear_screen();

int main(){
	string pw;
	int j;
	j = 0;
	while(j == 0){
		std::cout << "Enter password" << endl;
		std::cin >> pw;
		clear_screen();
		if(pw == "pampelmousse"){
			std::cout << "Correct password" << endl;
			terminal_loop();
		}
		else{
			std::cout << "Incorrect password. Try again" << endl;
		}
	}

	return 0;
}

void terminal_loop(){
	Stack Informant;
	Stack Officer;

	int i = 0;

	while(i == 0){
		string x;
		std::cout << "Enter identity" << endl;
		std::cin >> x;
		clear_screen();
		if(x == "informant"){
			int t = 0;
			while(t == 0){
				string y;
				std::cout << "Informant: Enter command('read', 'write' or 'logout')" << endl;
				std::cin >> y;
				clear_screen();
				if(y == "read"){
					Informant.display();
				}
				else if(y == "write"){
					string message;
					std::cout << "Informant: Enter message: ";
					getline(cin, message);
					getline(cin, message);
					clear_screen();
					Officer.push(message);
				}
				else if(y == "logout"){
					t++;
				}
				else{
					std::cout << "Informant: Please enter proper command" << endl;
				}
			}


		}


		else if(x == "officer"){
			int t = 0;
			while(t == 0){
				string y;
				std::cout << "Officer: Enter command('read', 'write' or 'logout')" << endl;
				std::cin >> y;
				clear_screen();
				if(y == "read"){
					Officer.display();
				}
				else if(y == "write"){
					string message;
					std::cout << "Officer: Enter message" << endl;
					std::getline(std::cin, message);
					clear_screen();
					Informant.push(message);
				}
				else if(y == "logout"){
					t++;
				}
				else{
					std::cout << "Officer: Please enter proper command" << endl;
				}
			}
		}
		else{
			std::cout << "Please enter proper command" << endl;
		}
	}
}

void clear_screen(){
	for(int i = 0; i < 10; i++){
		std::cout << "\n\n\n\n\n" << endl;
	}
}
