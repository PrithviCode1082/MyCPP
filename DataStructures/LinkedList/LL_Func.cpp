#include <iostream>

using namespace std;

struct Node {
public:
  Node *next = NULL;
  int value;
  Node(int val) { this->value = val; }
};

void push(Node *current, int value) {
  while (current != nullptr) {
    if (current->next == nullptr) {
      current->next = new Node(value);
      cout << "Value " << value << " added!\n";
      break;
    }
    current = current->next;
  }
}

Node *removeElement(Node *current, int value) {
  Node *head = current;
  if (current->value == value) {
    return current->next;
    delete head;
  }

  Node *temp;
  while (current != nullptr) {
    if (current->next != nullptr) {
      if (current->next->value == value) {
        if (current->next->next != nullptr) {
          temp = current->next;
          current->next = current->next->next;
          delete temp;
          break;
        }
        if (current->next->next == nullptr) {
          temp = current->next;
          current->next = NULL;
          delete temp;
          break;
        }
        cout << "True\n";
      }
    }
    current = current->next;
  }
  return head;
}

void iterate(Node *current) {
  cout << "Current List: ";
  while (current != nullptr) {
    cout << current->value << " ";
    current = current->next;
  }
  cout << endl;
}

Node *insert(Node *current, int index, int value) {
  Node *head = current;
  if (index == 0) {
    Node *head = new Node(value);
    head->next = current;
    return head;
  }
  int i = 0;
  while (current != nullptr) {
    i++;
    if (index == i) {
      if (current->next == NULL) {
        current->next = new Node(value);
        break;
      }
      Node *temp = current->next;
      current->next = new Node(value);
      current->next->next = temp;
      break;
    }
    current = current->next;
  }
  return head;
}

void menu() {
  cout << "\n***** MENU *****\n";
  cout << "1 - push\n2 - Insert\n3 - delete\n4 - Iterate\n5 - Exit\n";
  return;
}

void ask(string message, int &val) {
  cout << message;
  cin >> val;
}

int main() {
  int headVal, index;
  Node *temp;
  ask("Add a head to linked list: ", headVal);


  Node *head = new Node(headVal);

  while (true) {
    menu();
    ask("Enter a choice: ", headVal);

    switch (headVal) {
    case 1:
      ask("Enter a value: ", headVal);
      push(head, headVal);
      break;
    case 2:
      ask("Enter a value: ", headVal);
      iterate(head);
      ask("Enter index: ", index);
      head = insert(head, index, headVal);
      break;
    case 3:
      ask("Enter a value: ", headVal);
      head = removeElement(head, headVal);
      break;
    case 4:
      iterate(head);
      break;
    default:
      // Clean memory
      Node *current = head;
      while (current != nullptr) {
        temp = current;
        current = current->next;
        delete temp;
      }
      return 0;
    }
  }
}
