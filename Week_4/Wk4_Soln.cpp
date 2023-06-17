#include <iostream>
#include <stack>
#include <string>
#include <queue>
using namespace std;


///Question 1

bool isValid(string parens) {
	stack<char> hold;
	for (int i = 0; i < parens.size(); i++){
		char curr = parens[i];
		if (curr == '(' || curr == '[') {
			hold.push(curr);
		}
		else if (curr == ')') {
			if (hold.empty() || hold.top() != '(') {
				return false;
			}
			hold.pop();
		}
		else if (curr == ']') {
			if (hold.empty() || hold.top() != '[') {
				return false;
			}
			hold.pop();
		}
	}
	return hold.empty();
}

///Question 2
void reverseQueue(queue<int>& Q) {
	stack<int> rev;
	while (!Q.empty()) {
		rev.push(Q.front());
		Q.pop();
	}
	while (!rev.empty()) {
		Q.push(rev.top());
		rev.pop();
	}
}

///Question 3
void findNextInts(const int sequence[], int results[], int n) {
	if (n <= 0)
		return;

	stack<int> s;
	// push the first index to stack
	s.push(0);

	// iterate for rest of the elements
	for (int i = 1; i < n; i++) {
		int current = sequence[i];

		// Fill in results for preceding unfilled items
		// that are less than current.
		while (!s.empty() && current > sequence[s.top()]) {
			results[s.top()] = current;
			s.pop();
		}

		s.push(i);
	}

	// Remaining items don't have a later greater value
	while (!s.empty()) {
		results[s.top()] = -1;
		s.pop();
	}
}


///Question 4
string q4 = "9 5 * 8 - 6 7 * 5 3 - / *";
//May help to do it step wise
string a4 = "((9 * 5) - 8) * (6 * 7) / (5 - 3) = 777";

///Question 5
class Stack {
public:
	bool empty() const;
	size_t size() const;
	int top() const;
	void push(const int& value);
	void pop();
private:
	queue<int> storage;
};

bool Stack::empty() const {
	storage.empty();
}

size_t Stack::size() const {
	storage.size();
}

int Stack::top() const {
	storage.back();
}

void Stack::push(const int& value) {
	storage.push(value);
}

void Stack::pop() {
	for (int i = 0; i < storage.size() - 1; i++) {
		storage.push(storage.front());
		storage.pop();
	}
	storage.pop();
}

///Question 6
class Queue {
	//This implementation of Queue accepts only int. See if you can
	//make an implementation with templates!
	 //pushStorage is a stack that contains items when they're first      
   //pushed. popStorage is another stack, and we move items from 
   //pushStorage to popStorage when we want to pop from the queue
public:
	bool empty() const;
	size_t size() const;
	int front() const;
	int back() const;
	void push(const int& value);
	void pop();
private:
	//move items from pushStorage to popStorage while leaving back
	//item within pushStorage
	void moveItems();

	//storage for pushing items with one exception: always includes
	//back item if available
	stack<int> pushStorage;
	//storage for popping items: always includes front item
	stack<int> popStorage;
};

bool Queue::empty() const {
	return pushStorage.empty() && popStorage.empty();
}

size_t Queue::size() const {
	return pushStorage.size() + popStorage.size();
}

int Queue::front() const {
	return popStorage.top();
}

int Queue::back() const {
	if (size() == 1)
		return popStorage.top();
	return pushStorage.top();
}

void Queue::push(const int& value) {
	if (size() > 0)
		pushStorage.push(value);
	else
		popStorage.push(value);
}

void Queue::pop() { //Note that this causes a runtime error if 
// popStorage and pushStorage are empty (i.e. the Queue has no 
// items in it). This matches how calling pop() on an empty 
// C++ STL queue causes a runtime error.
	if (popStorage.size() > 0) {
		popStorage.pop();
		if (popStorage.size() == 0 && pushStorage.size() > 0)
			moveItems();
	}
	else {
		moveItems();
		popStorage.pop();
	}
}

void Queue::moveItems() {
	int temp = pushStorage.top();
	bool backExists = false;
	if (pushStorage.size() > 1) {
		pushStorage.pop();
		backExists = true;
	}

	while (pushStorage.size() > 0) {
		popStorage.push(pushStorage.top());
		pushStorage.pop();
	}

	if (backExists)
		pushStorage.push(temp);
}