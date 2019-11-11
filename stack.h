#include <string>
#include <iostream>
using namespace std;

class Stack{
private:
	struct node{
		string data;
		node *next;
	};
	node *head, *tail;
public:
	Stack(){
		head = NULL;
		tail = NULL;
	}

	void push(string s){
		node *temp = new node;
		temp->data = s;
		temp->next = NULL;
		if(head == NULL){
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else{
			temp->next = head;
			head = temp;
			temp = NULL;
		}
	}

	void pop(){
		node *temp = new node;
		if(tail->next == NULL){
			tail = NULL;
		}
		else{
			temp = head;
			head = temp->next;
			temp = NULL;
		}
	}

	void display(){
		node *temp = new node;
		string i;
		temp = head;

		while(temp != NULL){
			std::cout << temp->data << endl;
			pop();
			temp = temp->next;
		}
		std::cout << "No new messages" << endl;

	};
};
