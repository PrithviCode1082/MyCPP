#include <iostream>

using namespace std;

namespace len {
	int length = 0;
}

struct Node {
	Node* next = NULL;
	int value;
	Node(int val) : value(val) {len::length++;}
};

void traverse(Node *head, Node *current) {
	if (head == nullptr)
	{
		cout << "List has 0 elements.\n";
		return;
	}
	current = head;
	while (current != nullptr) {
		cout << current->value << " ";
		current = current->next;
	}
	cout << "\n";
}

Node* push(Node* head, int value) {
	Node* newNode = new Node(value);
	if (head != NULL) {newNode->next = head;}
	return newNode;
}

Node* pop(Node* head, Node* current) {
	if (head != NULL)
	{
		current = head->next;
		delete head;
		len::length--;
		return current;
	}
	else {
		cout << "List has 0 elements!!!\n";
		return NULL;
	}
}

void menu() {
	cout << "1 - pop\n2 - push\n3 - traverse\n4 - Get length\n5 - peek\nEnter Your choice: ";
}

int main() {
	Node* temp = NULL;
	Node* current = NULL;
	int choice, value;

	cout << "Enter a value: ";
	cin >> value;
	Node* head = new Node(value);

	while (true) {
		menu();
		cin >> choice;

		if (choice == 1){head = pop(head, current);}
		else if (choice == 2) {
			cout << "Enter a value: ";
			cin >> value;
			head = push(head, value);
		}
		else if (choice == 3){traverse(head, current);}
		else if (choice == 4) { cout << "List has " << len::length << " elements\n"; }
		else if (choice == 5)
		{
			if (head != NULL) { cout << head->value << "\n"; }
			else { cout << "List has 0 elements\n";}
		}
		else {
			current = head;
			while (current != nullptr) {
				temp = current;
				current = current->next;
				delete temp;
			}
			return 0;
		}
		cout << "******************************************************\n";
	}
}
