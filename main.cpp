#include "Library.h"
#include <iostream>

void test(bool testresult)
{
    if (testresult) std::cout << "Great success!\n";
    else std::cout << "Failure\n"; 
}



int main() {
    

    Library lib;
    Book* book1 = lib.addBook("Breymann", "C++");
    Book* book2 = lib.addBook("Gosling", "Java");
    Book* book3 = lib.addBook("Goldberg", "Smalltalk");
    Customer* customer1 = lib.addCustomer("Huber");
    Customer* customer2 = lib.addCustomer("Müller");
    Loan* loan1 = lib.borrow(customer1, book1);
    Loan* loan2 = lib.borrow(customer1, book2);
    
    
    test(loan1->getBook()->getAuthor() == "Breymann");
    test(loan1->getBook()->getTitle() == "C++");
    test(loan1->getCustomer()->getName() == "Huber");
    test(lib.getBorrower(book1) == customer1);
    test(lib.getBorrower(book2) == customer1);
    test(lib.getBorrower(book3) == NULL);
    test(lib.getBorrowedBooks(customer1).size() == 2);
    test(lib.getBorrowedBooks(customer2).size() == 0);
    test(lib.isBorrowed(book1));
    test(lib.isBorrowed(book2));
    test(!lib.isBorrowed(book3));
    test(lib.getAvailableBooks().size() == 1);
    
    

    return 0;
}

