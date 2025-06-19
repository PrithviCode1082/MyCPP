#include <iostream>
#include <string>

using namespace std;

class Book{
    private:
        string bookName;
        string author;
        string published;
        int due;
        int pages, no_of_Copies;
    public:
        Book(string name, string au, string pub, int pg, int noc):bookName(name), author(au), published(pub),pages(pg), no_of_Copies(noc){}
        void getDetail(){
            cout << "***** " << this->bookName << " *****\n";
            cout << "Author: " << this->author << endl;
            cout << "Published: " << this->author << endl;
            cout << "No.Of Pages: " << this->pages << endl;
            cout << "Available Copies: " << this->no_of_Copies << endl;
            cout << "************************************\n";
        }
        void setCopies(int copy){
            this->no_of_Copies+=copy;
        }
        string getName(){
            return this->bookName;
        }
        int getCopies(){
            return this->no_of_Copies;
        }
};
