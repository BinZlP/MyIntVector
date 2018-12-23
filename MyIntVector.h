#pragma once
// 2017203044 Han Hyung Seok

#define DEFAULT_CAPACITY 32

class MyIntVector {
private:
	int* data;
	size_t capacity;
	size_t size;

public:
	// *** CONSTRUCTORS ***

	MyIntVector(size_t _capacity = DEFAULT_CAPACITY) :capacity(_capacity), size(0) { data = new int[capacity]; }
	MyIntVector(const MyIntVector& v);
	~MyIntVector() { delete[] data; };


	// *** OPERATORS ***

	// Deep copy to LHS from RHS.
	// Precondition: Operands are MyIntVector. RHS has valid memory space and data.
	// Postcondition: LHS MyIntVector will have same elements and capacity with RHS MyIntVector in different memory space.
	MyIntVector& operator=(const MyIntVector& v);

	// Append elements of RHS to LHS vector.
	// Precondition: LHS and RHS variables are MyIntVector. RHS has valid memory space and data.
	// Postcondition: LHS MyIntVector will have its own elements and also RHS MyIntVector's.
	void operator+=(const MyIntVector& v);

	// Return MyIntVector object that is a vector-sum of the two operands.
	// Precondition: Both operands have same value of size, valid data and memory space.
	// Postcondition: No change in operands. Return MyIntVector object having data of vector-sum of two operands.
	MyIntVector operator+(const MyIntVector& v);

	// Return MyIntVector object that is a vector-difference of the two operands.
	// Precondition: Both operands have same value of size, valid data and memory space.
	// Postcondition: No change in operands. Return MyIntVector object having data of vector-difference of two operands.
	MyIntVector operator-(const MyIntVector& v);

	// Return MyIntVector object that is a scala-product of the two operands.
	// Precondition: Both operands have same value of size, valid data and memory space.
	// Postcondition: No change in operands. Return MyIntVector object having data of scala-product of two operands.
	MyIntVector operator*(const MyIntVector& v);

	// Return MyIntVector object that has data which values are negative values of the operand's elements.
	// Precondition: The operand has valid data and memory space.
	// Postcondition: No change in operands. Return MyIntVector object having data of negative valeu of operand's data elements.
	MyIntVector operator-();

	// Return true if two operands are having exactly same capacity and elements. If not, return false. 
	// Precondition: Both operands are MyIntVector, and have valid data and memory space.
	// Postcondition: No change in operands. Return boolean value.
	bool operator==(const MyIntVector& v);

	// Make all elements of this object value of x.
	// Precondition: MyIntVector object has valid data and memory space.
	// Postcondition: All data value of MyIntVector is x.
	MyIntVector& operator()(int x);

	// Return x-th index element of data
	// Precondition: MyIntVector object has more than x+1 elements.
	// Postcondition: No change in MyIntVector. Return int value that is value of x-th element of data.
	int operator[](int x);


	// *** MEMBER FUNCTIONS ***

	// Delete last element of MyIntVector object.
	// Precondition: MyIntVector object has same or more than one element.
	// Postcondition: MyIntVector object's last data element will be deleted, and it's size decrease of 1.
	void pop_back();

	// Add element to MyIntVector object. If the object's data space is full, reserve it's space. 
	// Precondition: MyIntVector object has valid memory space. Enough system memory space to allocate new data.
	// Postcondition: x will be added to MyIntVector object's data, and MyIntVector's size increase of 1. If the object was full, it's capacity will be doubled.
	void push_back(int x);


	// Return capacity variable's value of MyIntVector object.
	// Precondition: MyIntVector is a successfully constructed MyIntVector object.
	// Postcondition: No change in MyIntVector object. Return the object's capacity variable's value.
	size_t Capacity() const { return this->capacity; }

	// Return size variable's value of MyIntVector object.
	// Precondition: MyIntVector object is a successfully constructed MyIntVector object.
	// Postcondition: No change in MyIntVector object. Return the object's size variable's value.
	size_t Size() const { return this->size; }

	
	// Reserve MyIntVector object's capacity of n.
	// Precondition: MyIntVector object has valid memory space. n have to be bigger than the object's size value.
	// Postcondition: The object's capacity will change to n, and have new data space which is able to save n elements.
	void reserve(size_t n);


	// Return true if there's no data in MyIntVector. If not, return false.
	// Precondition: MyIntVector object has valid data and memory space.
	// Postcondition: 
	bool isEmpty() const;

	// Delete all data of MyIntVector.
	// Precondition: MyIntVector object has valid memory space.
	// Postcondition: MyIntVector object will lose all data, and have new memory space to save elements.
	void clear();


	// Print all data of MyIntVector object.
	// Precondition: MyIntVector object has valid data and memory space.
	// Postcondition: No change in MyIntVector object. Print all data of the object at console.
	void printElements() const;


};