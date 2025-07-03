#include <iostream>

using namespace std;

namespace getLength {
int length = 0;
}

struct Node {
public:
  Node *next = NULL;
  int value;
  Node(int val) {
    this->value = val;
    getLength::length++;
  }
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
  if (current->value == value) {
    getLength::length--;
    return current->next == nullptr ? NULL : current->next;
  }
  Node *head = current;
  Node *temp;
  while (current != nullptr) {
    if (current->next != nullptr && current->next->value == value) {
      temp = current->next;
      // making current node link to next->next node -> Node present after next
      // or NULL
      current->next =
          (current->next->next != nullptr ? current->next->next : NULL);
      delete temp;
      getLength::length--;
      break;
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
    Node *newHead = new Node(value);
    newHead->next = current;
    return newHead;
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
  cout << "1 - push\n2 - Insert\n3 - delete\n4 - Iterate\n5 - Get Length\n6 - "
          "Exit\n";
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
      if (head == nullptr) {
        ask("Linked List is deleted!\nAdd a head to linked list: ", headVal);
        head = new Node(headVal);
      }
      break;
    case 4:
      iterate(head);
      break;
    case 5:
      cout << "Total length is: " << getLength::length << endl;
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
