//Joel Asante

//includes
#include "ArrayList.h"
#include <iostream>

//Constructor
ArrayList::ArrayList() {
	_pa = new Car[10];
	_size = 0;
	_capacity = 10;
}

//p. COntrustor
ArrayList::ArrayList(int capacity) {
	if (capacity > 0) {
		_pa = new Car[capacity];
		_size = 0;
		_capacity = capacity;
	}
	else {
		ArrayList();
	}
}

ArrayList::ArrayList(const ArrayList& that) {
	this->_capacity = that._capacity;
	this->_size = that._size;
	// this->_pa = that._pa;	// shallow copy
	
	this->_pa = new Car[_capacity];
	
	for (int i = 0; i < _size; ++i) {
		this->_pa[i] = that._pa[i];
	}
}

ArrayList& ArrayList::operator=(const ArrayList& that) {
	if (this != &that){
		Car* temp = _pa;

		this->_capacity = that._capacity;
		this->_size = that._size;
		this->_pa = new Car[_capacity];
		for (int i = 0; i < _size; ++i) {
			this->_pa[i] = that._pa[i];
		}

		delete[] temp;
	}

	return *this;
}

ArrayList::~ArrayList() {
	delete[] _pa;
}

void ArrayList::push_back(Car obj) {
	add(obj);
}

Car ArrayList::pop() {
	if (_size <= 0) {
		std::cerr << "Fail to exec pop(). ArrayList empty.";
		exit(1);
	}

	Car temp = _pa[_size - 1];
	_size--;
	return temp;
}

Car ArrayList::get(int index) {
	if (index < 0 || index >= _size) {
		std::cerr << "Fail to exec get(). Invalid index.";
		exit(1);
	}

	return _pa[index];
}

void ArrayList::set(int index, Car obj) {
	if (index < 0 || index >= _size) {
		std::cerr << "Fail to exec set(). Invalid index.";
		exit(1);
	}

	_pa[index] = obj;

}

void ArrayList::add(int index, Car obj) {

	// invalid index, call exit()
	if (index < 0 || index > _size) {
		std::cerr << "Invalid index. " << std::endl;
		exit(1);
	}
	
	// valid index, add new element
	if (!_isFull()) {
		// case 1: add and shift
		// case 2: add without shifting

		// shift 0 or more elements
		for (int i = _size - 1; i >= index; --i) {		// note that (_size - 1)
			_pa[i + 1] = _pa[i];
		}

		// set new element
		_pa[index] = obj;

		// manage _size
		_size++;

	}
	else {
		_doubleCapacity();
		add(index, obj);
	}
}

void ArrayList::add(Car obj) {

	if (!_isFull()) {
		_pa[_size] = obj;

		// manage _size
		_size++;
	}
	else {
		_doubleCapacity();
		add(obj);
	}
}

void ArrayList::del(int index) {
	// TO_DO: implement this function
    if (index >= 0 && index < _size){
    for(int i = index; i < _size; i++)
		{
			_pa[i] = _pa[i+1];	//Moving values from right to left
    	}	
    }
    else {
    cout << " Invaild , out oF RANGE";
    }
}

int ArrayList::size() {
	return _size;
}

int ArrayList::capacity() {
	return _capacity;
}

void ArrayList::traverse() {
	for (int i = 0; i < _size; ++i) {
		std::cout << _pa[i] << " ";
	}
	std::cout << std::endl;
}

bool ArrayList::_isFull() {
	return _size == _capacity;
}

void ArrayList::_doubleCapacity() {
	// allocate new space with doubled capacity
	Car* temp = new Car[_capacity * 2];

	// copy existing elements over
	for (int i = 0; i < _size; ++i) {
		temp[i] = _pa[i];
	}

	// update _capacity 
	_capacity *= 2;

	// update _pa 
	delete[] _pa;
	_pa = temp;
}
