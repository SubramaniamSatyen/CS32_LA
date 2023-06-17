#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

class B {
	int m_val;
public:
	B() {
		m_val = 0;
	}
	B(const B& other) {
		m_val = other.m_val;
	}
	~B() {
	}
};

class A {
public:
	A(int sz) {

	}
	A(const A& other) {
	}
	A& operator=(const A& other) {
	}
	//...other functions
	~A() {
	}
private:
	//one dynamically allocated B object; assume B has a
	//default constructor, a copy constructor, and an
	//assignment operator
	B* b;
	//dynamically allocated array
	int* arr;
	//size of arr (determined by a constructor)
	int n;
	string str;
};
