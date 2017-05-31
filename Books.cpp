//
//  Books.cpp
//  Market_Making_Options
//
//  Created by Jonnathan Romero on 1/15/16.
//  Copyright © 2016 John. All rights reserved.
//

#include "Books.hpp"

Books::Books()
{
    open_or_close = false;
}

void Books::get_mm_book_order(double limit, int index)
{
    open_or_close = true;
    
    if (index==1)
    {
        limit_order1= limit;
        
    }else if (index==2)
    {
        limit_order2= limit;
    }
    else if (index==3)
    {
        limit_order3= limit;
        
    }else if (index==4)
    {
        limit_order4= limit;
        
    }else if (index==5)
    {
        limit_order5= limit;
        
    }else if (index==6)
    {
        limit_order6= limit;
        
    }else if (index==7)
    {
        limit_order7= limit;
        
    }else if (index==8)
    {
        limit_order8= limit;
        
    }else if (index==9)
    {
        limit_order9= limit;
        
    }else if (index==10)
    {
       limit_order10= limit;
    }
}

void Books::close_books()
{
    limit_order1=0;
    limit_order2=0;
    limit_order3=0;
    limit_order4=0;
    limit_order5=0;
    limit_order6=0;
    limit_order7=0;
    limit_order8=0;
    limit_order9=0;
    limit_order10=0;
    
    open_or_close = false;
    
}

double Books::get_broker_order(double price_willing_to_pay, int &index)
{
    double  price  =0;
    
    if (index==1)
    {
        if (price_willing_to_pay >= limit_order1)
        {
            price = limit_order1;
        }
    }else if (index==2)
    {
        if (price_willing_to_pay >= limit_order2)
        {
            price = limit_order2;
        }
    }
    else if (index==3)
    {
        if (price_willing_to_pay >= limit_order3)
        {
            price = limit_order3;
        }
        
    }else if (index==4)
    {
        if (price_willing_to_pay >= limit_order4)
        {
            price = limit_order4;
        }
        
    }else if (index==5)
    {
        if (price_willing_to_pay >= limit_order5)
        {
            price = limit_order5;
        }
    }else if (index==6)
    {
        if (price_willing_to_pay >= limit_order6)
        {
            price = limit_order6;
        }
        
    }else if (index==7)
    {
        if (price_willing_to_pay >= limit_order7)
        {
            price = limit_order7;
        }
        
    }else if (index==8)
    {
        if (price_willing_to_pay >= limit_order8)
        {
            price = limit_order8;
        }
        
    }else if (index==9)
    {
        if (price_willing_to_pay >= limit_order9)
        {
            price = limit_order9;
        }
        
    }else if (index==10)
    {

        if (price_willing_to_pay >= limit_order10)
        {
            price = limit_order10;
        }
    }

    
    return price;
}