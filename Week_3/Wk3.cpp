#include <iostream>

//Question 1
struct Node {
	int val;
	Node* next;
};

int cmpr(Node* head, int* arr, int arr_size) {
	int max, arrVal, listVal;
	max = -1;
	//arrVal = arr[0];
	//listVal = head->val;
	//listVal = (*head).val;
	for (int i = 0; i < arr_size; i++) {
		if (head == nullptr) {
			break;
		}
		listVal = head->val;
		arrVal = arr[i];
		if (arrVal == listVal) {
			max = i;
			head = head->next;
		}
		else {
			break;
		}
	}
	return max;
}

//Question 2
struct Node {
	char c;
	Node* next;
};

int compare(Node* list1, Node* list2) {
	Node* curr1 = list1;
	Node* curr2 = list2;
	while (curr1 != nullptr && curr2 != nullptr) {
		if (curr1->c != curr2->c) {
			return (curr1->c - curr2->c);
		}
		curr1 = curr1->next;
		curr2 = curr2->next;
	}
	if (curr1 == nullptr) {
		if (curr2 == nullptr) {
			return 0;
		}
		return -1;
	}
	return 1;

}


//Question 3
class LL {
public:
	LL() { head = nullptr; }

	LL(const LL& other) {
		if (other.head == nullptr) {
			head = nullptr;
		}
		else {
			Node* curr = other.head;
			head = new Node();
			head->val = curr->val;

			Node* ourCurr = head;
			curr = curr->next;

			while (curr != nullptr) {
				Node* newNode = new Node();
				newNode->val = curr->val;
				newNode->next = nullptr;

				ourCurr->next = newNode;
				ourCurr = ourCurr->next;
				curr = curr->next;

			}
		}
		

	}
	//Question 4
	int findNthFromLast(int n) {
	}

private:
	struct Node {
		int val;
		Node* next;
	};
	Node* head;
};

//Question 5
//struct Node {
//	int val;
//	Node* next;
//};
//
//class LinkedList {
//public:
//	void rotateLeft(int n); //rotates head left by n
//	//Other working functions such as insert and printItems
//private:
//	Node* head;
//};
//
//void LinkedList::rotateLeft(int n) {
//	if (head == nullptr)
//		return;
//	int size = 1;
//	Node* oldTail = head;
//	while (oldTail->next != nullptr) {
//		size++;
//		oldTail = oldTail->next;
//	}
//
//	if (n % size > 0) {
//		int headPos = n % size;
//		Node* newTail = head;
//		for (int x = 0; x < headPos - 1; x++) {
//			newTail = newTail->next;
//		}
//		Node* newHead = newTail->next;
//
//		newTail->next = nullptr;
//		oldTail->next = head;
//		head = newHead;
//	}
//}


//Question 6
struct Node
{
	int data;
	Node* next;
};

Node* reverse(Node* head) {
	Node* prev = nullptr;
	Node* curr = head;

	while (curr != nullptr) {
		Node* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
}

//Question 7
//struct Node {
//    int val;
//    Node* next;
//};
//
//
//Node* combine(Node* h, Node* h2) {
//}