#include <cstddef>
#include <iostream>

using namespace std;

class Node {
public:
  int value;
  Node *next = NULL;

  Node(int val) { this->value = val; }
  void printValue() { cout << value << " "; }
};

int main() {
  Node *head = new Node(6);
  head->next = new Node(7);
  head->next->next = new Node(8);

  Node *current = head;
  while (current != nullptr) {
    current->printValue();
    current = current->next;
  }
  return 0;
}
