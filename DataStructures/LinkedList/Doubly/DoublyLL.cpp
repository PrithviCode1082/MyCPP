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

Node* pop(Node* head, Node*tail) {
    if (len::length == 2)
    {
        tail->previous = NULL;
        delete head;
        len::length--;
        return NULL;
    }
    else if (head == NULL) {
        cout << "Head doesn't exist\n";
        return NULL;
    }
    else if (head != NULL && tail == NULL) {
        len::length--;
        return NULL;
    }
    else {
        Node* current = head->next;
        current->previous = NULL;
        delete head;
        len::length--;
        return current;
    }
}

Node* shift(Node* head, Node* tail) {
    if (len::length == 2) {
        head->next = NULL;
        delete tail;
        len::length--;
        return NULL;
    }
    else if (tail == NULL) {
        cout << "Tail doesn't exist\n";
        return NULL;
    }
    else if (head == NULL && tail != NULL) {
        len::length--;
        return NULL;
    }
    else {
        Node* current = tail->previous;
        current->next = NULL;
        delete tail;
        len::length--;
        return current;
    }
}

Node* prepend(Node *head, Node *tail, int value) {
    if (head == NULL)
    {
        Node* newNode = new Node(value);
        newNode->next = tail;
        tail->previous = newNode;
        return newNode;
    }
    else if (head == NULL && tail == NULL) {
        Node* newNode = new Node(value);
        return newNode;
    }
    else {
        Node* newNode = new Node(value);
        head->previous = newNode;
        newNode->next = head;
        return newNode;
    }
}

Node* append(Node *head, Node *tail, int value) {
    if (tail == NULL) {
        Node* newNode = new Node(value);
        newNode->previous = head;
        head->next = newNode;
        return newNode;
    }
    else if (head == NULL && tail == NULL) {
        Node* newNode = new Node(value);
        return newNode;
    }
    else {
        Node* newNode = new Node(value);
        tail->next = newNode;
        newNode->previous = tail;
        return newNode;
    }
}

inline static void menu(){
    cout << "[1]Push front   [2]Push back   [3]remove head   [4]remove tail\n[5]Traverse front   [6]Traverse back   [7]Get Length\n";
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
        if (choice == 1) {
            cout << "Enter a new value: ";
            cin >> val;
            if (head == NULL)
            {
                head = new Node(val);
                head->next = tail;
                if (tail != nullptr) {
                    tail->previous = head;
                } 
            }
            else if (head != nullptr && tail == nullptr) {
                tail = head;
                Node *newNode = new Node(val);
                head = newNode;
                tail->next = NULL;
                tail->previous = head;
                head->next = tail;
            }
            else {
                head = prepend(head, tail, val);
            }
        }
        else if (choice == 2) {
            cout << "Enter a new value: ";
            cin >> val;
            if (tail == NULL)
            {
                tail = new Node(val);
                tail->previous = head;
                if (head != nullptr) {
                    head->next = tail;
                }
            }
            else if (head == nullptr && tail != nullptr)
            {
                head = tail;
                Node* newNode = new Node(val);
                tail = newNode;
                head->next = tail;
                head->previous = NULL;
                tail->next = NULL;
                tail->previous = head;
            }
            else {
                tail = append(head, tail, val);
            }
        }
        else if (choice == 3) {
            head = pop(head, tail);
        }
        else if (choice == 4) {
            tail = shift(head, tail);
        }
        else if (choice == 5) {
            if (head != NULL)
            {
                current = head;
                while (current != nullptr) {
                    cout << current->value << " ";
                    current = current->next;
                }
                cout << "\n";
            }
            else if (tail == NULL) {
                cout << "List has 0 elements\n";
            }
            else {
                cout << tail->value << "\n";
            }
        }
        else if (choice == 6) {
            if (tail != NULL)
            {
                current = tail;
                while (current != nullptr) {
                    cout << current->value << " ";
                    current = current->previous;
                }
                cout << "\n";
            }
            else if (head == NULL) {
                cout << "List has 0 elements\n";
            }
            else {
                cout << head->value << endl;
            }
        }
        else if (choice == 7) {
            cout << "Length of List is: " << len::length << "\n";
        }
        else {
            current = head;
            while (current != NULL) {
                temp = current;
                current = current->next;
                delete temp;
            }
            return 0;
        }
        cout << "**************************************************\n";
    }

     //return 0;
}
