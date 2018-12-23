// 2017203044 Han Hyung Seok

#include "MyIntVector.h"
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

// Constructors

MyIntVector::MyIntVector(const MyIntVector& v) {
	data = new int[v.capacity];
	copy(v.data, v.data + v.size, data);
	this->capacity = v.capacity;
	this->size = v.size;
}



// Operators

MyIntVector& MyIntVector::operator=(const MyIntVector& v) {
	if (this == &v) return *this; // Return if LHS and RHS are same 
	if (capacity != v.capacity) { // Allocate new memory space if LHS MyIntVector has different capacity with RHS MyIntVector
		delete[] data;
		data = new int[v.capacity];
		capacity = v.capacity;
	}
	size = v.size;
	copy(v.data,v.data+Size(),data);
	return *this;
}

void MyIntVector::operator+=(const MyIntVector& v) {
	if (v.isEmpty()) return; // Return if v is empty vector
	while(this->Size() + v.Size() > this->capacity) this->reserve(this->Capacity() * 2); // Reserve if need more space
	copy(v.data, v.data + v.Size(), this->data + this->Size());
	size += v.size;
}

MyIntVector MyIntVector::operator+(const MyIntVector& v) {
	if (this->Size() != v.Size()) { // Throw an error when two vectors have different size
		cout << "You can't use operator +,-,* with operands having different size value" << endl; 
		exit(-1); 
	}
	MyIntVector tmp(*this);
	for (int i = 0; i < tmp.Size(); i++) tmp.data[i] += v.data[i];
	return tmp;
}

MyIntVector MyIntVector::operator-(const MyIntVector& v) {
	if (this->Size() != v.Size()) { // Throw an error when two vectors have different size
		cout << "You can't use operator +,-,* with operands having different size value" << endl; 
		exit(-1); 
	}
	MyIntVector tmp(*this);
	for (int i = 0; i < tmp.Size(); i++) tmp.data[i] -= v.data[i];
	return tmp;
}

MyIntVector MyIntVector::operator*(const MyIntVector& v) {
	if (this->Size() != v.Size()) { // Throw an error when two vectors have different size
		cout << "You can't use operator +,-,* with operands having different size value" << endl; 
		exit(-1); 
	}
	MyIntVector tmp(*this);
	for (int i = 0; i < tmp.Size(); i++) tmp.data[i] *= v.data[i];
	return tmp;
}

MyIntVector MyIntVector::operator-() {
	if (this->isEmpty()) return *this; // Return if empty
	MyIntVector tmp(*this);
	for (int i = 0; i < tmp.Size(); i++) tmp.data[i] *= -1;
	return tmp;
}

bool MyIntVector::operator==(const MyIntVector& v) {
	if (this->Size() != v.Size()) return false;
	else {
		for (int i = 0; i < this->Size(); i++)
			if (this->data[i] != v.data[i]) return false;
		return true;
	}
}

MyIntVector& MyIntVector::operator()(int x) {
	for (int i = 0; i < this->Size(); i++) this->data[i] = x;
	return *this;
}

int MyIntVector::operator[](int x) { 
	if (x<0) { // Throw an error when x is a negative integer.
		cout << "Cannot use negative value for [] operator." << endl;
		exit(-1);
	}
	if (x >= this->Size()) { // Throw an error when x is too big.
		cout << "Out of index during usage of [] operator." << endl;
		exit(-1);
	}
	return data[x]; 
}

// Member functions

void MyIntVector::pop_back() {
	if (this->isEmpty()) return; // Return if empty
	this->size--;
}

void MyIntVector::push_back(int x) {
	if (this->Size() == this->Capacity()) this->reserve(2 * Capacity()); // Reserve if full
	data[this->size] = x;
	this->size++;
}


bool MyIntVector::isEmpty() const {
	if (Size() == 0)
		return true;
	else
		return false;
}

void MyIntVector::reserve(size_t n) {
	if (n < this->Size()) return; // Return if n is smaller than original size
	int* temp = new int[n];
	copy(data, data + this->Size(), temp);
	delete[] data;
	data = temp;
	this->capacity = n;
}

void MyIntVector::clear() {
	this->size = 0;
}

void MyIntVector::printElements() const {
	for (int i = 0; i < this->Size(); i++) cout << "[" << i << "]=>" << this->data[i] << " ";
	cout << endl;
}

