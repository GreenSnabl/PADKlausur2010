#include "Library.h"

Book* Library::addBook(string author, string title)
{
    Book b(author, title);
    Book* bp = &b;
    books_.push_back(bp);
    return bp;
}

Customer* Library::addCustomer(string name)
{
    Customer c(name);
    Customer* cp = &c;
    customers_.push_back(cp);
    return cp;
}

Loan* Library::borrow(Customer* customer, Book* book)
{
    Loan loan(customer, book);
    Loan* lp = &loan;
    loans_.push_back(lp);
    return lp;
}

Customer* Library::getBorrower(Book* book)
{
    for(int i = 0; i < loans_.size(); ++i)
        if(loans_[i]->getBook() == book) return loans_[i]->getCustomer();
    return NULL;
}

vector<Book*> Library::getBorrowedBooks(Customer* customer)
{
    vector<Book*> vb;
    for(int i = 0; i < loans_.size(); ++i)
        if(loans_[i]->getCustomer() == customer) vb.push_back(loans_[i]->getBook());
    return vb;
}

bool Library::isBorrowed(Book* book)
{
    return getBorrower(book);
}

vector<Book*> Library::getAvailableBooks()
{
    vector<Book*> available;
    for(int i = 0; i < books_.size(); ++i)
        if(!isBorrowed(books_[i])) available.push_back(books_[i]);
    return available;
}

