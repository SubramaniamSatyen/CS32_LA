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
	A(int sz) : n(sz) {
		arr = new int[sz];
		b = new B();
	}
	A(const A& other) : n(other.n) {
		arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = other.arr[i];
		}
		b = new B(*other.b);
	}
	A& operator=(const A& other) {
		A temp = A(other);
		if (this != &other) {
			n = temp.n;

			B* swapB = temp.b;
			temp.b = b;
			b = swapB;

			int* swapArr = temp.arr;
			temp.arr = arr;
			arr = swapArr;
		}
		return *this;
	}
	//...other functions
	~A() {
		delete[] arr;
		delete b;
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
