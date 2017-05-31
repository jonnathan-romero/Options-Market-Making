//
//  Broker.hpp
//  Market_Making_Options
//
//  Created by Jonnathan Romero on 1/15/16.
//  Copyright © 2016 John. All rights reserved.
//

#ifndef Broker_hpp
#define Broker_hpp

#include <iostream>
#include <random>
#include "Options.hpp"
#include "Market_Maker.hpp"
#include "Broker.hpp"
#include "Books.hpp"

class Broker
{
public:
    double price_w_pay(Options o,int index);
private:
    
};

#endif /* Broker_hpp */
