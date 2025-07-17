#include <cstddef>
#include <iostream>

using namespace std;

class Node {
public:
  int value;
  Node *next = NULL;
  Node(int val) { this->value = val; }
};

int main() {
  Node *head = new Node(6);
  Node *current = head;
  for (int num : {7, 8, 9, 10}) {
      current->next = new Node(num);
      current = current->next;
  }
  current = head;
  Node *temp;
  while (current != nullptr) {
    cout << current->value << " ";
    temp = current;
    current = current->next;
    delete temp;
  }
  return 0;
}
