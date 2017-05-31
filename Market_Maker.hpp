#ifndef Market_Maker_hpp
#define Market_Maker_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Books.hpp"
#include "Options.hpp"

using namespace std;

class Market_maker
{
public:
    Market_maker(int num_of_o);
    
    void receive_orders(double order [], int num_of_o, Options o);
    
    double order_index (int index_num);//this is to be able to send orders to books must call receive orders first
    
    void successful_order (double price_sold_at, int index);// this is to bring the order that was actaully sold
    
    void cal_PNL (Options o);
    
    double get_PNL(Options o);
    
    void close_out (Options o, int index);
    
    double get_realized (Options o);
    
    void close_orders(Books booky);
    
    void close_out_all (Options o);
    
    void sell_market(Options o, int index);
    
    vector<double> price_sold1;
    vector<double> price_sold2;
    vector<double> price_sold3;
    vector<double> price_sold4;
    vector<double> price_sold5;
    vector<double> price_sold6;
    vector<double> price_sold7;
    vector<double> price_sold8;
    vector<double> price_sold9;
    vector<double> price_sold10;
    
    int open1;
    int open2;
    int open3;
    int open4;
    int open5;
    int open6;
    int open7;
    int open8;
    int open9;
    int open10;
    
    
private:
    const int number_of_options =10;
    double  order_s [10];
    double PNL;
    double realized_PNL;
    


    
    
};

#endif /* Market_Maker_hpp */
