#include <iostream>

//Question 1
struct Node {
	int val;
	Node* next;
};

int cmpr(Node* head, int* arr, int arr_size) {
	int i = 0;
	while (i < arr_size && head != nullptr) {
		if (head->val != arr[i]) {
			return i - 1;
		}
		i++;
		head = head->next;
	}
	return i - 1;
}


//Question 2
struct Node {
	char c;
	Node* next;
};

int compare(Node* list1, Node* list2) {
	while (list1 != nullptr && list2 != nullptr) {
		int cmp = list1->c - list2->c;
		if (cmp != 0) {
			return cmp;
		}
		list1 = list1->next;
		list2 = list2->next;
	}

	if (list1 == nullptr) {
		if (list2 == nullptr) {
			return 0;
		}
		return -1;
	}
	else if (list2 == nullptr) {
		return 1;
	}
	return 0;
}

//Question 3
class LL {
public:
	LL() { head = nullptr; }

	LL(const LL& other) {
		if (other.head == nullptr)
			head = nullptr;
		else {
			head = new Node;
			head->val = other.head->val;
			head->next = nullptr;

			Node* thisCurrent = head;
			Node* otherCurrent = other.head;
			while (otherCurrent->next != nullptr) {
				thisCurrent->next = new Node;
				thisCurrent->next->val = otherCurrent->next->val;
				thisCurrent->next->next = nullptr;

				thisCurrent = thisCurrent->next;
				otherCurrent = otherCurrent->next;
			}
		}
	}

private:
	struct Node {
		int val;
		Node* next;
	};
	Node* head;
};

//Question 4
class LL {
public:
	LL() { head = nullptr; }

	LL(const LL& other) {
		if (other.head == nullptr)
			head = nullptr;
		else {
			head = new Node;
			head->val = other.head->val;
			head->next = nullptr;

			Node* thisCurrent = head;
			Node* otherCurrent = other.head;
			while (otherCurrent->next != nullptr) {
				thisCurrent->next = new Node;
				thisCurrent->next->val = otherCurrent->next->val;
				thisCurrent->next->next = nullptr;

				thisCurrent = thisCurrent->next;
				otherCurrent = otherCurrent->next;
			}
		}
	}
	int findNthFromLast(int n) {
		Node* p = head;
		// advance p forward by n, checking there are at least n
		// elements
		for (int i = 0; i < n; i++) {
			if (p == nullptr) {
				return -1;
			}
			p = p->next;
		}
		if (p == nullptr) {
			return -1;
		}

		Node* nthBeforeP = head;  // will lag n steps behind p
		while (p->next != nullptr) {
			p = p->next;
			nthBeforeP = nthBeforeP->next;
		}
		return nthBeforeP->val;
	}

private:
	struct Node {
		int val;
		Node* next;
	};
	Node* head;
};

//Question 5
struct Node {
	int val;
	Node* next;
};

class LinkedList {
public:
	void rotateLeft(int n); //rotates head left by n
	//Other working functions such as insert and printItems
private:
	Node* head;
};

void LinkedList::rotateLeft(int n) {
   if (head == nullptr)
       return;
   int size = 1;
   Node* oldTail = head;
   while (oldTail->next != nullptr) {
       size++;
       oldTail = oldTail->next;
   }

   if (n % size > 0) {
       int headPos = n % size;
       Node* newTail = head;
       for (int x = 0; x < headPos - 1; x++) {
           newTail = newTail->next;
       }
       Node* newHead = newTail->next;

       newTail->next = nullptr;
       oldTail->next = head;
       head = newHead;
   }
}

//Question 6
Linked list node
struct Node
{
	int data;
	Node* next;
};

Node* reverse(Node* head) {
	Node* prev = nullptr;
	Node* curr = head;
	while (curr != nullptr) {
		// point �next� to the node after curr
		Node* next = curr->next;
		// make curr�s next pointer point
//to the node before curr
		curr->next = prev;
		// making prev point to curr and curr point to �next�
		// this is just advancing the linked list pointers
		prev = curr;
		curr = next;
	}
	// prev points to the last-examined node of the list, which 
//is the head of the reversed linked list
	return prev;
}


//Question 7
struct Node {
   int val;
   Node* next;
};


Node* combine(Node* h, Node* h2) {
   // checking that the lists aren�t empty
   if (h == nullptr) {
       return h2;
   }
   if (h2 == nullptr) {
       return h;
   }

   Node* newList;

   // determining which should be the resultant head
   if (h->val <= h2->val) {
       newList = h;
       h = h->next;
   }
   else {
       newList = h2;
       h2 = h2->next;
   }

   Node* newNext = newList;

   // iterate through both given linked lists
   while (h != nullptr && h2 != nullptr) {
       // the next node in the combined list is the currently 
       //examined node in either list that has the lesser value
       if (h->val <= h2->val) {
           newNext->next = h;
           h = h->next;
       }
       else {
           newNext->next = h2;
           h2 = h2->next;
       }
       newNext = newNext->next;
   }
   // if one list was longer than the other
// append the rest of the list to the new list
   if (h != nullptr) {
       newNext->next = h;
   }
   else if (h2 != nullptr) {
       newNext->next = h2;
   }

   // return the head of the combined list
   return newList;
}