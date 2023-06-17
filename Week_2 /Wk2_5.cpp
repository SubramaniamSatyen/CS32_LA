#include <iostream>
#include <string>
using namespace std;

class Account {
public:
	Account(int x) {
		cash = x;
	}
	int cash;
};


class Billionaire {
public:
	Billionaire(string n) : account(10000) {
		offshore = new Account(1000000000);
		name = n;
	}
	~Billionaire() {
		delete offshore;
	}
	Account account;
	Account* offshore;
	string name;
};

int main() {
	Billionaire jim = Billionaire("Jimmy");
	Billionaire jimClone = jim;
	cout << jimClone.name << " has " << jimClone.account.cash + jimClone.offshore->cash << endl;
	cout << jim.name << " has " << jim.account.cash + jim.offshore->cash << endl;
}