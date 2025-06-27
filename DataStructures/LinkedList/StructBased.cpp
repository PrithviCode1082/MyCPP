#include <cstddef>
#include <iostream>

using namespace std;

struct Node {
  int value;
  Node *next = NULL;

  void printValue() { cout << value << " "; }
};

int main() {
  Node *head = new Node;
  head->value = 6;

  head->next = new Node;
  head->next->value = 7;

  head->next->next = new Node;
  head->next->next->value = 8;

  Node *current = head;
  while (current != nullptr) {
    current->printValue();
    current = current->next;
  }
  return 0;
}
