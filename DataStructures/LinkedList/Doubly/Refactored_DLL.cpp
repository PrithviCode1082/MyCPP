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

Node* pop_shift(Node* h_node, Node* t_node, int op){
    if (len::length == 2) {
        if(op == 1) {t_node->previous = NULL;} else{h_node->next = NULL;}
        if(op == 1) {delete h_node;} else {delete t_node;}
        len::length--;
        return NULL;
    } else if((op == 1 && h_node==NULL) || (op == 2 && t_node==NULL)){
        cout << ((op == 1) ? "Head Doesn't exist\n" : "Tail Doesn't exist\n");
        return NULL;
    } else if((op==1 && h_node != NULL && t_node == NULL) || (op==2 && h_node == NULL && t_node != NULL)){
        len::length--;
        return NULL;
    } else{
        Node* current = (op == 1) ? h_node->next : t_node->previous;
        if (op == 1) {current->previous = NULL;} else {current->next = NULL;}
        if (op == 1) {delete h_node;} else {delete t_node;}
        len::length--;
        return current;
    }
}

Node* prepend_append(Node *h_node, Node *t_node, int value, int op){
    Node *newNode = new Node(value);
    if ((op == 1 && h_node == NULL) || (op == 2 && t_node == NULL)) {
        if (op == 1) {newNode->next = t_node;} else {newNode->previous = h_node;}
        if (op == 1 && t_node != NULL) {t_node->previous = newNode;} else if(op == 2 && h_node != NULL) {h_node->next = newNode;}
        return newNode;
    } else if(h_node == NULL && t_node == NULL) {return newNode;}
    else{
        if (op == 1) {h_node->previous = newNode;} else {t_node->next = newNode;}
        if (op == 1) {newNode->next = h_node;} else {newNode->previous = t_node;}
        return newNode;
    }
}

void traverse(Node* node, Node*current, Node* opposite, int op){
    if (node != NULL) {
        current = node;
        while (current != nullptr) {
            cout << current->value << " ";
            current = (op == 1) ? current->next : current->previous;
        }
    } else if(opposite == NULL) {cout << "List has 0 elements";}
    else{cout << opposite->value << " ";}
    cout << endl;
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
        if (choice == 1 || choice == 2) {
            cout << "Enter a new value: ";
            cin >> val;
            if (choice == 1) {head = prepend_append(head, tail, val, 1);}
            else{tail = prepend_append (head, tail, val, 2);}
        }
        else if (choice == 3) {
            head = pop_shift(head, tail, 1);
        }
        else if (choice == 4) {
            tail = pop_shift(head, tail, 2);
        }
        else if (choice == 5 || choice == 6) {
            traverse((choice == 5) ? head : tail, current, (choice == 5) ? tail : head, (choice == 5) ? 1 : 2);
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
}
