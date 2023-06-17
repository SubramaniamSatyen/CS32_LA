#include <string>


////////////////Inheritance, Polymorphism 
///Question 1
#include <iostream>
using namespace std;

class LivingThing {
public:
	virtual void intro() { cout << "I知 a living thing" << endl; }
};

class Person : public LivingThing {
public:
	void intro() { cout << "I知 a person" << endl; }
};

class UniversityAdministrator : public Person {
public:
	void intro() {
		cout << "I知 a university administrator" << endl;
	}
};

class Chancellor : public UniversityAdministrator {
public:
	void intro() { cout << "I知 Gene" << endl; }
};

int main() {
	LivingThing* thing = new Chancellor();
	thing->intro();
}

///Question 2
string res = "";
//Note: Behavior is undefined, since the destructor in Pet is not declared virtual

///Question 3
string res = "";

///Question 4
string res = "";



////////////////Recursion
///Question 1
struct Node {
	int data;
	Node* next;
};

class LL {
public: // other functions such as insert not shown
	void deleteList(); // implement this function
private: // additional helper allowed
	Node* m_head;
};

///Question 2
bool isPalindrome(string foo) {

}

int main() {
	isPalindrome("kayak"); // true
	isPalindrome("stanley yelnats"); // true
	isPalindrome("LAs rock"); // false (but the sentiment is true :))
}

///Question 3
bool isPrime(int num) {
	return false;
}

///Question 4
string longestCommonSubsequence(string s1, string s2);



///////////////////////Inheritance, Polymorphism 
///Question 1
class Animal {
public:
	Animal(string name);
private:
	string m_name;
};

class Cat : public Animal {
public:
	Cat(string name, int amountOfYarn);
private:
	int m_amountOfYarn;
};

class Himalayan : public Cat {
public:
	Himalayan(string name, int amountOfYarn);
};

class Siamese : public Cat {
public:
	Siamese(string name, int amountOfYarn, string toyName);
private:
	string m_toyName;
};

///Question 2
class LivingThing {
private:
	int age;
};

class Person : public LivingThing {
public:
	Person(int a) { age = a; }
	void birthday() {
		age++;
	}
};

///Question 3
/*
*/


//////////////Recursion
///Question 1
int res;

///Question 2
// Node definition for singly linked list
struct Node {
	int val;
	Node* next;
};

Node* merge(Node* l1, Node* l2);

///Question 3
// Node definition for doubly linked list
struct Node {
	int val;
	Node* next;
	Node* prev;
};

Node* reverse(Node* head);
