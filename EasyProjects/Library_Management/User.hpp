#include "Book.hpp"
#include <iostream>
#include <vector>

namespace count {
int id = 100;
};

using namespace std;

class User {

private:
  int temp, limit, s_id;
  string username;
  bool isPro = false;
  vector<Book> borrowed;
  vector<int> days;

public:
  // static int id;

  User(string un) : username(un) {
    limit = 2;
    cout << "Welcome " << un
         << ". And Thank you for becoming a member!\nHappy Reading!\n";
    s_id = count::id + 1;
    cout << "Your Unique ID is: " << s_id << endl;
    count::id++;
  };
  void toggle() {
    isPro = !isPro;
    limit = 2;
  };
  string getName() { return username; }
  void getMembership() {
    if (isPro) {
      cout << "You're already a Pro Memeber!\n";
    } else {
      isPro = !isPro;
      limit = 4;
      cout << "You've successfully purchased the Pro Membership!\n";
    }
  }
  ~User() {};
  void traverse() {
    for (int i = 0; i < borrowed.size(); i++) {
      cout << i << ". " << borrowed.at(i).getBookName() << " By "
           << borrowed.at(i).getAuthor() << " - " << days.at(i)
           << " Days Remaining.\n";
    }
  }

  int getID() { return s_id; }
  void getStatus() {
    cout << " ***** Member *****\nID : " << s_id << "\nName: " << username
         << "\nPro Member? " << ((isPro) ? "Pro" : "False")
         << "\n***** Borrowed Books *****\n";
    traverse();
    cout << "************************************\n";
  }
  string returnBook() {
    cout << "Currently Borrowed Books: \n";
    traverse();
    cout << "Enter the index of the book to return it: ";
    cin >> temp;

    string b_name = borrowed.at(temp).getBookName();
    cout << borrowed.at(temp).getBookName()
         << " Has been returned Successfully.\n";
    borrowed.erase(borrowed.begin() + temp);
    return b_name;
  }
  void fined() {
    for (int i = 0; i < borrowed.size(); i++) {
      if (days.at(i) < 0) {
        cout << "You're fined 50 points, for delay in return.\n";
        cout << borrowed.at(i).getBookName() << " was delayed!\n";
      }
    }
  }
  void borrow(string bn, string au, string gen, int pub, int pag) {
    Book newBook(bn, au, gen, pub, pag);
    borrowed.push_back(newBook);
    (isPro) ? days.push_back(30) : days.push_back(15);
  }

  void reduceDays() {
    for (int &day : days) {
      day -= 1;
    }
  }
};

// int User::id = 100;
