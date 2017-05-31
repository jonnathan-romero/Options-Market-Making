
#ifndef Books_hpp
#define Books_hpp

#include <stdio.h>

class Books
{
public:
    
    Books();
    
    double limit_order1;
    double limit_order2;
    double limit_order3;
    double limit_order4;
    double limit_order5;
    double limit_order6;
    double limit_order7;
    double limit_order8;
    double limit_order9;
    double limit_order10;
    
    void get_mm_book_order(double limit, int index);
    
    double get_broker_order(double price_willing_to_pay, int &index);
    
    bool open_or_close;
    
    void close_books();
 
};

#endif /* Books_hpp */
