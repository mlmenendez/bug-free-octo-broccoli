#pragma once
class linked_list
{
public:
	linked_list();
	void insert();
	linked_list* search(linked_list*,int);
	void delete_node();
	bool isEmpty();
	~linked_list();
private:
	unsigned int counter = 0;
	bool empty = true;
	linked_list* next = nullptr;
	linked_list* previous = nullptr;
	int storage;
};


