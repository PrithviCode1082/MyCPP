// #include <iostream>
#include <vector>
#include "User.hpp"

using namespace std;

class Library{
    private:
        vector<Book> BOOKS;
        vector<User> USERS;
    public:
        Library(){};
        void getMembership(int id, int mn){
            for (User &user : USERS) {
                if (user.getId() == id) {
                    user.setMembership(1);
                    break;
                }
            }
            cout << "Didn't Found Account with id: " << id << "! Create an account first!\n";
        }
        void getBook(int id, string bookname){
            for (Book &book : BOOKS) {
                if (bookname == book.getName() && book.getCopies() > 0) {
                    cout << "You've recieved book: " << book.getName() << endl;
                    book.setCopies(-1);
                    return;
                }
            }
            cout << "Book " << bookname << " not available!\n";
        }
        void setBook(int id, string bookname){
            for (Book &book : BOOKS) {
                if (bookname == book.getName() && book.getCopies() > 0) {
                    cout << "You've returned book: " << book.getName() << endl;
                    book.setCopies(1);
                    return;
                }
            }
            cout << "Book " << bookname << " not found!\n";
        }
        // void periodic(){

        // }
};
