#ifndef LIBRARY_H
#define LIBRARY_H
#include <vector>
#include <string>

using namespace std;

class Customer{
public:    
    Customer(string name) : name_{name} {}
    string getName(){return name_;}    
private:
    string name_;
    

};


class Book{
public:
    Book(string author, string title) : author_{author}, title_{title} {}
    string getTitle(){return title_;}
    string getAuthor(){return author_;}
private:
    string author_;
    string title_;

};

class Loan{
public:
    Loan(Customer* customer, Book* book) : customer_{customer}, book_{book} {}
    Book* getBook(){return book_;}
    Customer* getCustomer(){return customer_;}
private:
    Customer* customer_;
    Book* book_;

    
    
};

class Library {
public:
    Book* addBook(string author, string title);
    Customer* addCustomer(string name);
    Loan* borrow(Customer* customer, Book* book);
    Customer* getBorrower(Book* book);
    vector<Book*> getBorrowedBooks(Customer* customer);
    bool isBorrowed(Book* book);
    vector<Book*> getAvailableBooks();

    vector<Book*> books_;
    vector<Customer*> customers_;
private:
    vector<Loan*> loans_;

};

#endif /* LIBRARY_H */

