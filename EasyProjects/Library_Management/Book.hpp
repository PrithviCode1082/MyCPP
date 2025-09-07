#include <iostream>

using namespace std;

class Book {
private:
  string bookName, author, genre;
  int published, pages;

public:
  Book(string bn, string au, string gen, int pub, int pg)
      : bookName(bn), author(au), genre(gen), published(pub), pages(pg) {};
  ~Book() {};
  string getBookName() { return bookName; }
  string getAuthor() { return author; }
  string getGenre() { return genre; }
  int getPub() { return published; }
  int getPages() { return pages; }
  void getDetail(int i) {
    cout << "(" << i << "). ";
    cout << "----- " << bookName << " -----\nBy " << author << "  -  [" << genre
         << "]  -  Published at: " << published << "  -  (" << pages
         << " Pages) ----- ";
  }
};
