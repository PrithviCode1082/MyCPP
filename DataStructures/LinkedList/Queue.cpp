#include <cstddef>
#include <iostream>

using namespace std;

namespace len {
    int length = 0;
}

struct Node {
    Node* next = NULL;
    Node* previous = NULL;
    int value;
    Node(int val) : value(val) { len::length++; }
};

Node* push(Node *head, Node *tail, int value) {
    Node* newNode = new Node(value);
    Node* current = tail;
    current->next = newNode;
    newNode->previous = current;
    return newNode;
}

void pop(Node *head, Node *tail) {
    if (head == tail)
    {
        head = NULL;
        tail = NULL;
        len::length--;
    }
    else if (head == NULL && tail == NULL) {
        cout << "NULL\n";
    }
    else {
        if (head!=NULL)
        {
            Node* current;
            current = head;
            head = head->next;
            delete current;
        }
        len::length--;
    }
}

static void Traverse(Node *head, Node *tail) {
    if (head == NULL && tail == NULL)
    {
        cout << "List has 0 elements\n";
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << "\n";
}

inline static void menu() {
    cout << "[1]Enqueue    [2]Dequeue   [3]Traverse   [4]Get Length\n";
    cout << "Enter your choice: ";
}

int main() {
    int num1, num2, choice, val;
    Node* current;
    Node* temp;
    cout << "Enter two values: ";
    cin >> num1 >> num2;
    Node* head = new Node(num1);
    Node* tail = new Node(num2);
    head->next = tail;
    tail->previous = head;

    while (true) {
        menu();
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter a value: ";
            cin >> val;
            // push an element
            if (head == NULL && tail == NULL)
            {
                Node *newNode = new Node(val);
                head = newNode;
                head->next = tail;
            }
            else if (head != NULL && tail == NULL) {
                Node* newNode = new Node(val);
                tail = newNode;
                head->next = tail;
                tail->previous = head;
            }
            else {
                tail = push(head, tail, val);
            }
        }
        else if (choice == 2)
        {
            if (head == tail)
            {
                head = NULL;
                tail = NULL;
                len::length--;
            }
            else if (head == NULL && tail == NULL) {
                cout << "NULL\n";
            }
            else {
                current = head;
                head = head->next;
                delete current;
                len::length--;
            }
        }
        else if (choice == 3)
        {
            Traverse(head, tail);
        }
        else if (choice == 4) {
            cout << "List has " << len::length << " elements\n";
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
        //cout << "Head: " << head->value << " | " << "Tail : " << tail->value << endl;
        cout << "**************************************************\n";
    }
}
