#include <iostream>
#include <vector>
#include "Book.hpp"

using namespace std;

class User{
    private:
        string username;
        bool membership;
        vector<Book> Borrowed;
        int fine, due, payable, id;
    public:
        User(string name, bool ms, int fn, int due, int pay) : username(name), membership(ms), fine(0), due(due), payable(pay){}
        void setMembership(int ms){
            this->membership = ms;
        }
        void setFine(int fn){
            this->fine = fn;
        }
        void setPayable(int pay){
            this->payable = pay;
        }
        void getUserInfo(){
            cout << "***** " << this->username << " *****\n";
            cout << "ID: " << this->id << endl;
            cout << "Membership : " << ((this->membership) ? "Premium" : "Normal") << "\n";
            cout << "Fine: $" << this->fine << endl;
            cout << "Payable: $" << this->payable << endl;
            cout << "************************************\n";
        }
        int getId(){
            return this->id;
        }
};
