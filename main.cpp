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
    

    return 0;
}

