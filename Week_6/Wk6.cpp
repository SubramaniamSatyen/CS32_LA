#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

///Recursion, Templates, STL Question 1
int getMax(int a[], int n) {
}


///Question 2
int sumOverThreshold(int x[], int length, int threshold) {
	int sum = 0;
	for (int i = 0; i < length; i++) {
		sum += x[i];
		if (sum > threshold) {
			return sum;
		}
	}

	return -1;
}

int sumOverThreshold2(int x[], int length, int threshold) {
	return sumOverThreshold2Helper(x, length, threshold, 0);
}

int sumOverThreshold2Helper(int x[], int length, int threshold,
	int sum)
{
	if (sum > threshold) {
		return sum;
	}
	if (length == 0) { 
		return -1;
	}
	return sumOverThreshold2Helper(x + 1, length - 1, threshold,
		sum + x[0]);
}

///Question 3
string endX(string str);

///Question 4
bool isSolvable(int x, int y, int c);

///Template/STL Question 1

template <class T>
void foo(T input) {
	cout << "Inside the main template foo(): " << input << endl;
}

template<>
void foo(int input) {
	cout << "Specialized template for int: " << input << endl;
}

int main() {
	foo<char>('A');
	foo<int>(19);
	foo<double>(19.97);
}

///Question 2
class Potato {
public:
	Potato(int in_size) : size(in_size) { };
	int getSize() const {
		return size;
	};
private:
	int size;
};

int main() {
	vector<Potato> potatoes;
	Potato p1(3);
	potatoes.push_back(p1);
	potatoes.push_back(Potato(4));
	potatoes.push_back(Potato(5));

	vector<int>::iterator it = potatoes.begin(); // 1
	while (it != potatoes.end()) {
		potatoes.erase(it);  // 2
	}

	for (it = potatoes.begin(); it != potatoes.end(); it++) {
		cout << it->getSize() << endl;  // 3
	}
}


///Question 3
class Stack {

};

///Question 4
class Vector {

};

///Recursion Question 1
int sumOfDigits(int num);

///Question 2
struct Node {
	int data;
	Node* next;
};

Node* deleteAll(Node* head, int value);
Node* insertInOrder(Node* head, int value);
void reversePrint(Node* head);

///Question 3
bool isClimbable(int stairs[], int length);

///Template/STL Question 1
template <typename T>
T max(T x, T y)
{
	return (x > y) ? x : y;
}

///Question 2
//Repeat Question

///Question 3
