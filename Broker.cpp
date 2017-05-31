//
//  Broker.cpp
//  Market_Making_Options
//
//  Created by Jonnathan Romero on 1/15/16.
//  Copyright © 2016 John. All rights reserved.
//

#include <iostream>
#include <random>
#include "Options.hpp"
#include "Market_Maker.hpp"
#include "Broker.hpp"
#include "Books.hpp"

default_random_engine g;
normal_distribution<double> generous(1,0.017);

double Broker::price_w_pay(Options o, int index)
{
    double e = generous(g);
    double price =0;
    
    if (index==1)
    {
        price=e*o.get_option_price('c', 80, o.time, o.price_now);
        
    }else if (index==2)
    {
        price=e*o.get_option_price('c', 90, o.time, o.price_now);
        
    }else if (index==3)
    {
        price=e*o.get_option_price('c', 100, o.time, o.price_now);

    }else if (index==4)
    {
        price=e*o.get_option_price('c', 110, o.time, o.price_now);
    }else if (index==5)
    {
        price=e*o.get_option_price('c', 120, o.time, o.price_now);
        
    }else if (index==6)
    {
       price=e*o.get_option_price('p', 80, o.time, o.price_now);

    }else if (index==7)
    {
        price=e*o.get_option_price('p', 90, o.time, o.price_now);
            
    }else if (index==8)
    {
        price=e*o.get_option_price('p', 100, o.time, o.price_now);
    }else if (index==9)
    {
        price=e*o.get_option_price('p', 110, o.time, o.price_now);
        
    }else if (index==10)
    {
        price=e*o.get_option_price('p', 120, o.time, o.price_now);
    }
    
    return price;
    
}