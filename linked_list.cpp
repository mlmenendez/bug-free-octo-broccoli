#include "linked_list.h"
#include "aux_functions.h"
#include <iostream>

using namespace std;



linked_list::linked_list(){
	this->insert();
}

void linked_list::insert(){
	int temp;
	cout << "What integer are you trying to insert?" << endl;
	cin >> temp;
	this->next = new linked_list();
	this->next->previous = this;
	this->next->counter = 1;
	this->next->storage = temp;
	this->empty = false;
}

linked_list* linked_list::search(linked_list* temp, int item){
	if (temp->next == nullptr) {
		cout << "Item not found" << endl;
		return nullptr;
	}
	else if (temp->storage == item) {
		cout << "Item found" << endl;
		return this;
	}
	else if (temp->storage != item && temp->next != nullptr) {
		search(temp->next, item);
	}

}

void linked_list::delete_node(){
	if (this->next == nullptr && this->previous != nullptr) {
		this->previous->next = nullptr;
		delete this;
		return;
	}
	else if (this->next != nullptr && this->previous!= nullptr) {
		this->next->previous = this->previous;
		this->previous->next = this->next;
		delete this;
		return;
	}
	else if (this->previous == nullptr && this->next!=nullptr) {
		this->next->previous = nullptr;
		delete this;
		return;
	}
	else if (this->previous == nullptr && this->next == nullptr) {
		this->~linked_list;
		return;
	}
	else {
		cout << "Uncaught edge case :/ " << endl;
		return;
	}

}

bool linked_list::isEmpty(){
	return empty;
}


linked_list::~linked_list(){
	//When destroying, will always start at the head so no need to check the previous pointer
	if (this->next != nullptr) {
		this->next->~linked_list();
	}
	delete this;
	return;
}
