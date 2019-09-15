//#pragma once

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "Car.h"

class ArrayList
{
public: 
	ArrayList();
	ArrayList(int capacity);
	ArrayList(const ArrayList& that);
	ArrayList& operator=(const ArrayList& that);
	~ArrayList();

	// interface
	void push_back(Car obj);
	Car pop();
	Car get(int index);
	void set(int index, Car obj);
	void add(Car obj);
	void add(int index, Car obj);
	void del(int index);
	int size();
	int capacity();
	
	void traverse();

private:
	Car* _pa;			// pointer of dynamic array's address
	int _size;			// number of elements used. 1-based. 
	int _capacity;		// capcacity of the list
	
	bool _isFull();
	void _doubleCapacity();
};

#endif
