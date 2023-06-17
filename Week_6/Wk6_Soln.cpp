#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <list>
using namespace std;

///Recursion, Templates, STL Question 1
int getMax(int a[], int n) {
	if (n == 1)
		return a[0];
	int x = getMax(a, n - 1);
	if (x > a[n - 1])
		return x;
	else
		return a[n - 1];



	int x = getMax(a + 1, n - 1);
	if (x > a[0]) {
		return x;
	}
	else {
		return a[0];
	}
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

///Question 3
string endX(string str) {
	if (str.length() <= 1) 	
		return str;
	if (str[0] == 'x')
		return endX(str.substr(1)) + 'x'; 
	else
		return str[0] + endX(str.substr(1));
}

///Question 4
bool isSolvable(int x, int y, int c) {
	if (c == 0)
		return true;
	if (c < 0)
		return false;

	return isSolvable(x, y, c - x) || isSolvable(x, y, c - y);
}

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

/*
Inside the main template foo(): A
Specialized template for int: 19
Inside the main template foo(): 19.97
*/


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

	vector<Potato>::iterator it = potatoes.begin(); // 1
	while (it != potatoes.end()) {
		it = potatoes.erase(it);  // 2
		it++;
	}

	for (it = potatoes.begin(); it != potatoes.end(); it++) {
		cout << it->getSize() << endl;  // 3
	}
}

///Question 3
template<typename Item>
class Stack {
public:
	Stack() : m_head(nullptr) {}

	bool isEmpty() const {
		return m_head == nullptr;
	}

	Item top() const {
		// We'll return a default-valued Item if the Stack is empty,
		// because you should always check if it's empty before     
		// calling top().
		if (m_head != nullptr)
			return m_head->val;
		else
			return Item();

	}

	void push(Item item) {
		Node* new_node = new Node;
		new_node->val = item;
		new_node->next = m_head;
		m_head = new_node;
	}

	void pop() {
		// We'll simply do nothing if the Stack is already empty,
		// because you should always check if it's empty while 
		// popping.
		if (m_head == nullptr) {
			return;
		}
		Node* temp = m_head;
		m_head = m_head->next;
		delete temp;
	}

	~Stack() {
		while (m_head != nullptr) {
			Node* temp = m_head;
			m_head = m_head->next;
			delete temp;
		}
	}

private:
	struct Node {
		Item val;
		Node* next;
	};
	Node* m_head;
};

///Question 4
template <typename T>
class Vector {
public:
	Vector();
	~Vector();
	void push_back(const T& item);
private:
	// Total capacity of the vector -- doubles each time
	int m_capacity;
	// The number of elements in the array
	int m_size;
	// Underlying dynamic array
	T* m_buffer;
};

template <typename T>
Vector<T>::Vector()
	: m_capacity(0), m_size(0), m_buffer(nullptr)
{}

template <typename T>
Vector<T>::~Vector() {
	delete[] m_buffer;
}

template <typename T>
void Vector<T>::push_back(const T& item) {
	// if space is full, allocate more capacity
	if (m_size == m_capacity)
	{
		// double capacity(doesn’t have to be doubled, but recommended);
		//special case for capacity 0
		if (m_capacity == 0)
			m_capacity = 1;
		else
			m_capacity *= 2;

		// allocate an array of the new capacity
		T* newBuffer = new T[m_capacity];

		// copy old items into new array
		for (int i = 0; i < m_size; i++)
			newBuffer[i] = m_buffer[i];

		// delete original array (harmless if m_buffer is null)    
		delete[] m_buffer;

		// install new array
		m_buffer = newBuffer;
	}

	// add item to the array, update m_size
	m_buffer[m_size] = item;
	m_size++;
}

///Recursion Question 1
int sumOfDigits(int num) {
	if (num < 10)
		return num;
	return num % 10 + sumOfDigits(num / 10);
}

///Recursion Question 2
struct Node {
	int data;
	Node* next;
};

Node* insertInOrder(Node* head, int value) {
	if (head == nullptr || value < head->data) {
		Node* p = new Node;
		p->data = value;
		p->next = head;
		head = p;
	}
	else
		head->next = insertInOrder(head->next, value);
	return head;
}


Node* deleteAll(Node* head, int value) {
	if (head == nullptr)
		return nullptr;
	else {
		if (head->data == value) {
			Node* temp = head->next;
			delete head;
			return deleteAll(temp, value);
		}
		else {
			head->next = deleteAll(head->next, value);
			return head;
		}
	}
}

void reversePrint(Node* head) {
	if (head == nullptr)
		return;
	reversePrint(head->next);
	cout << head->data;
}

///Question 3
bool isClimbableHelper(int stairs[], bool visited[], int length, int pos) {
	if (pos < 0)
		return false;
	if (pos >= length)
		return true;

	if (stairs[pos] == 0 || visited[pos])
		return false;
	visited[pos] = true;

	return isClimbableHelper(stairs, visited, length, pos - stairs[pos]) || isClimbableHelper(stairs, visited, length, pos + stairs[pos]);
}

///Template/STL Question 1
template <typename T>
T max(T x, T y)
{
	return (x > y) ? x : y;
}

/*No matching function for the desired function call (types must be the same)*/

///Question 2
//Repeat Question

///Question 3
int deleteOddSumLists(set<list<int>*>& s) {
	int numDeleted = 0;

	// iterate over the set
	set<list<int>*>::iterator set_it = s.begin();
	while (set_it != s.end())
	{
		// iterate over each list and get the sum
		int sum = 0;
		list<int>::iterator list_it = (*set_it)->begin();
		list<int>::iterator list_end = (*set_it)->end();
		while (list_it != list_end)
		{
			sum += *list_it;
			list_it++;
		}

		// delete list and remove from set if sum is odd
		// otherwise, proceed to check the next list
		if (sum % 2 == 1)
		{
			delete* set_it;
			set_it = s.erase(set_it);
			numDeleted++;
		}
		else
			set_it++;
	}

	return numDeleted;
}

// Sample driver code:
int main()
{
	set<list<int>*> s;
	list<int>* l1 = new list<int>;
	l1->push_back(1);
	l1->push_back(2);
	list<int>* l2 = new list<int>;;
	l2->push_back(1);
	l2->push_back(1);
	list<int>* l3 = new list<int>;;
	l3->push_back(1);
	l3->push_back(0);
	s.insert(l1);
	s.insert(l2);
	s.insert(l3);
	cout << deleteOddSumLists(s) << endl;
}
