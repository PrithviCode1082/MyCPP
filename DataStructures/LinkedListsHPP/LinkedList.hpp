#include <iostream>

using namespace std;

struct Node {
  Node *next = nullptr;
  int value;
  Node(int val) : value(val) {};
};

class LinkedList {
private:
  int count = 0;
  Node *head, *current, *temp;

  int checkers(int index) {
    if (count == 0) {
      cout << "Zero Elements in the list!\n";
      return 1;
    }
    if (index > count) {
      cout << "Index exceeds the size of the List!\n";
      return 2;
    }
    return 3;
  }

public:
  LinkedList(int val) {
    head = new Node(val);
    count++;
  }
  ~LinkedList() {
    current = head;
    while (current != nullptr) {
      temp = current;
      current = current->next;
      delete temp;
    }
  };

  void traverse() {
    current = head;
    while (current != nullptr) {
      cout << current->value << " ";
      current = current->next;
    }
    cout << endl;
  }

  int find(int val) {
    if (checkers(count) == 1) {
      return -1;
    }
    int i = 0;
    current = head;
    while (current != nullptr) {
      if (current->value == val) {
        return i;
      }
      current = current->next;
      i++;
    }
    cout << "Element " << val << " wasn't found!\n";
    return -1;
  }

  void push_back(int val) {
    if (head == nullptr) {
      head = new Node(val);
      count += 1;
      return;
    }
    current = head;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = new Node(val);
    count += 1;
  }

  void pop() {
    if (checkers(count) == 1) {
      return;
    }
    if (count == 1) {
      head = nullptr;
      count -= 1;
      return;
    }
    temp = head;
    head = head = head->next;
    count -= 1;
    delete temp;
  }

  void insert(int index, int val) {
    if (checkers(index) < 3) {
      return;
    }
    if (count >= 1 && index == 0) {
      temp = head;
      head = new Node(val);
      head->next = temp;
      return;
    }
    current = head;
    int i = 0;
    while (current != nullptr) {
      if (i + 1 == index) {
        temp = current->next;
        current->next = new Node(val);
        current->next->next = temp;
        return;
      }
      current = current->next;
      i++;
    }
  }

  void getLength() { cout << "Length is: " << count << endl; }
};
