class Book;
#include "User.hpp"
#include <fstream>
#include <rapidjson/document.h>
#include <vector>

using namespace std;
using namespace rapidjson;

class Library {
private:
  string tmp;
  int temp;
  vector<User> users;
  vector<Book> books;
  vector<int> stock;

public:
  Library() {
    ifstream BookFile("data.json");
    string json((istreambuf_iterator<char>(BookFile)),
                istreambuf_iterator<char>());
    Document doc;
    doc.Parse(json.c_str());
    if (doc.HasParseError()) {
      cerr << "Error parsing JSON: " << doc.GetParseError() << endl;
    } else {
      for (int i = 0; i < doc.Size(); i++) {
        Book book(doc[i]["name"].GetString(), doc[i]["author"].GetString(),
                  doc[i]["genre"].GetString(), doc[i]["published"].GetInt(),
                  doc[i]["pages"].GetInt());
        stock.push_back(doc[i]["stock"].GetInt());
        books.push_back(book);
      }
      BookFile.close();
    }
  };
  ~Library() {};

  int userIterator(int id) {
    for (int i = 0; i < users.size(); i++) {
      if (users.at(i).getID() == id) {
        return i;
      }
    }
    return -1;
  }
  int bookIterator(int id) {
    for (int i = 0; i < books.size(); i++) {
      if (i == id)
        return i;
    }
    return -1;
  }

  void addUser(string name) {
    cout << "Do you want to create an account with a Pro membership? Tap 1 for yes, "
            "or any other number for no: ";
    cin >> temp;
    User user(name);
    if (temp == 1) {
      user.getMembership();
    }
    users.push_back(user);
  }

  void iterate() {
    for (User &user : users) {
      user.reduceDays();
    }
  }

  void addPro(int ID) {
    if (userIterator(ID) != -1) {
      users.at(userIterator(ID)).getMembership();
      return;
    }
    cout << "You don't have an account! Add an account to get pro "
            "membership!\n";
  }

  void removePro(int ID) {
    if (userIterator(ID) != -1) {
      users.at(userIterator(ID)).toggle();
      return;
    }
    cout << "You don't have an account! Add an account to get/remove pro "
            "membership!\n";
  }

  void checkUserStatus(int id) {
    if (userIterator(id) == -1) {
      cout << "User with ID " << id << " Not Found!\n";
      return;
    }
    users.at(userIterator(id)).getStatus();
  }

  void showBooks() {
    for (int i = 0; i < books.size(); i++) {
      books.at(i).getDetail(i);
      cout << stock.at(i) << " pieces remaining\n\n";
    }
  }

  void returnBooks(int ID) {
    tmp = users.at(userIterator(ID)).returnBook();
    for (int i = 0; i < books.size(); i++) {
      if (tmp == books.at(i).getBookName()) {
        stock.at(i) += 1;
      }
    }
  }

  void AddBooks(int userId, int bookID) {
    users.at(userIterator(userId))
        .borrow(books.at(bookID).getBookName(), books.at(bookID).getAuthor(),
                books.at(bookID).getGenre(), books.at(bookID).getPub(),
                books.at(bookID).getPages());
    cout << books.at(bookID).getBookName() << " was added to user "
         << users.at(userIterator(userId)).getName() << endl;
    stock.at(bookID) -= 1;
  };
};
