#include "Library.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

void menu() {
  cout << "------- Menu -------\n";
  cout << "1 - Buy Membership.\n2 - Buy Pro Membership\n3 - View All available "
          "books\n4 - Borrow Book\n5 - Return Book\n6 - Check your status\n7 - "
          "Cancel Membership\n8 - "
          "Exit\n";
  cout << "--------------------\n";
}

int main() {
  int ch = 1;
  int temp;
  int choice = 1;
  string name;
  Library lib;
  lib.addUser("ABC");

  cout << "----- Welcome To Library -----\n";
  while (ch >= 1 && ch <= 7) {
    menu();
    cout << "Enter your choice: ";
    cin >> ch;
    switch (ch) {
    case 1:
      cout << "Enter your name: ";
      cin >> name;
      lib.addUser(name);
      break;
    case 2:
      cout << "Enter your account ID: ";
      cin >> choice;
      lib.addPro(choice);
      break;
    case 3:
      lib.showBooks();
      break;
    case 4:
      cout << "Enter your account ID: ";
      cin >> choice;
      cout << "Enter Book Number: ";
      cin >> temp;
      lib.AddBooks(choice, temp);
      break;
    case 5:
      cout << "Enter your account ID: ";
      cin >> choice;
      lib.returnBooks(choice);
      break;
    case 6:
      cout << "Enter your account ID: ";
      cin >> choice;
      lib.checkUserStatus(choice);
      break;
    case 7:
      cout << "Enter your account ID: ";
      cin >> choice;
      lib.removePro(choice);
      break;
    case 8:
      exit(0);
      break;
    default:
      lib.iterate();
    }
  }
  cout << "Hello World\n";
  return 0;
}
