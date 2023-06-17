#include <string>


////////////////Inheritance, Polymorphism 
///Question 1
#include <iostream>
using namespace std;

class LivingThing {
public:
	virtual void intro() { cout << "I'm a living thing" << endl; }
};

class Person : public LivingThing {
public:
	virtual void intro() { cout << "I'm a person" << endl; }
};

class UniversityAdministrator : public Person {
public:
	virtual void intro() {
		cout << "I'm a university administrator" << endl;
	}
};

class Chancellor : public UniversityAdministrator {
public:
	virtual void intro() { cout << "I'm Gene" << endl; }
};

int main() {
	LivingThing* thing = new Chancellor();
	thing->intro();
}

///Question 2
string res = "Pet\nPet\nWoof\n~Pet";
//Note: Behavior is undefined, since the destructor in Pet is not declared virtual

///Question 3
string res = "Pet\nPet\nWoof\nDog ran away!\n~Pet\n~Pet";

///Question 4
string res = "This is not legal";



////////////////Recursion
///Question 1
struct Node {
	int data;
	Node* next;
};

class LL {
public:
	void deleteListHelper(Node*& head);
	// other functions such as insert not shown
	void deleteList(); // implement this function
private: // additional helper allowed
	Node* m_head;
};

void LL::deleteListHelper(Node*& head) {
	if (head == nullptr)
		return;


	Node* temp = head->next;
	delete head;
	head = nullptr;
	deleteListHelper(temp);
}

void LL::deleteList() {
	if (m_head == nullptr)
		return;


	Node* temp = m_head->next;
	delete m_head;
	m_head = temp;
	this->deleteList();
}

void LL::deleteList() {
	deleteListHelper(m_head);
}


///Question 2
bool isPalindrome(string foo) {
	int len = foo.length();
	if (len <= 1)
		return true;
	if (foo[0] != foo[len - 1])
		return false;
	return isPalindrome(foo.substr(1, len - 2));
}


int main() {
	isPalindrome("kayak"); // true
	isPalindrome("stanley yelnats"); // true
	isPalindrome("LAs rock"); // false (but the sentiment is true :))
}

///Question 3
bool isPrime(int num) {
	// start with testing divisibility by 2
	return isPrimeHelper(num, 2);
}

bool isPrimeHelper(int num, int i) {
	if (num <= 2)
		//1 is not prime
		return num == 2;
	// Not prime if divisible by i
	if (num % i == 0)
		return false;
	//Is prime if exausted all divisors
	if (i * i > num)
		return true;
	//Increment i and see if it is divisible by it
	return isPrimeHelper(num, i + 1);
}


///Question 4
string longestCommonSubsequence(string s1, string s2) {
	if (s1.empty() || s2.empty()) // base case: either empty
		return "";
	// split the strings into head and tail for simplicity
	char s1_head = s1[0];
	string s1_tail = s1.substr(1);
	char s2_head = s2[0];
	string s2_tail = s2.substr(1);

	// if heads are equal, use the head and
	// recursively find rest of common subsequence
	if (s1_head == s2_head)
		return s1_head + longestCommonSubsequence(s1_tail, s2_tail);
	// heads different, so check for common subsequences not
	// including one of the heads
	string if_behead_s1 = longestCommonSubsequence(s1_tail, s2);
	string if_behead_s2 = longestCommonSubsequence(s1, s2_tail);

	// return the longer of the subsequences we found
	if (if_behead_s1.length() >= if_behead_s2.length()) {
		return if_behead_s1;
	}
	else {
		return if_behead_s2;
	}

	//return if_behead_s1.length() >= if_behead_s2.length() ? if_behead_s1 : if_behead_s2;
}




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

Animal::Animal(string name)
	: m_name(name) {}

Cat::Cat(string name, int amountOfYarn)
	: Animal(name), m_amountOfYarn(amountOfYarn) {}

Himalayan::Himalayan(string name, int amountOfYarn)
	: Cat(name, amountOfYarn) {}

Siamese::Siamese(string name, int amountOfYarn, string toyName)
	: Cat(name, amountOfYarn), m_toyName(toyName) {}


///Question 2
class LivingThing {
public:
	LivingThing(int a) { age = a; }
	void myBirthday() { age++; }
private:
	int age;
};

class Person : public LivingThing {
public:
	Person(int a) : LivingThing(a) { /*age = a; */}
	void birthday() {
		/*age++;*/
		myBirthday();
	}
};

///Question 3
/*
What a wonderful world! 0
me has just been birthed.
What a wonderful world! 0
me has just been birthed.
What a wonderful world! 0
me has just been birthed.
Coming in from me with 5
Coming in from me with 5
Coming in from me with 5
What a wonderful world! 0
More complex birth B
25
What a wonderful world! 0
More complex birth C
Hello World!!
25
Why do I have to leave this world!
Guess this is goodbye
Why do I have to leave this world!
Guess this is goodbye
Why do I have to leave this world!
Guess this is goodbye
Coming in from B with 25
Why do I have to leave this world!
Guess this is goodbye
Goodbye world!
Coming in from C with 10
Why do I have to leave this world!
Guess this is goodbye
Goodbye world!
Why do I have to leave this world!
Guess this is goodbye
*/


//////////////Recursion
///Question 1
int res = 12;

///Question 2
// Node definition for singly linked list
struct Node {
	int val;
	Node* next;
};

Node* merge(Node* l1, Node* l2) {
	// base cases: if a list is empty, return the other list
	if (l1 == nullptr)
		return l2;
	if (l2 == nullptr)
		return l1;

	// determine which head should be the head of the 
// merged list. Then set head->next to the head returned
// from recursive calls.
	Node* head;
	if (l1->val < l2->val) {
		head = l1;
		head->next = merge(l1->next, l2);
	}
	else {
		head = l2;
		head->next = merge(l1, l2->next);
	}

	// return the head of the merged list
	return head;
}

///Question 3
// Node definition for doubly linked list
struct Node {
	int val;
	Node* next;
	Node* prev;
};

Node* reverse(Node* head) {
	if (head == nullptr)
		return head;
	// Swap next and prev
	Node* temp = head->next;
	head->next = head->prev;
	head->prev = temp;
	// If previous is null then we are done
	if (head->prev == nullptr)
		return head;
	return reverse(head->prev);
}
