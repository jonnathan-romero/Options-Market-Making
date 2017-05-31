#include <iostream>
#include <random>
#include "Options.hpp"
#include "Market_Maker.hpp"
#include "Broker.hpp"
#include "Books.hpp"

using namespace std;

const double stock_starting_price = 100.0;
const double risk_free_rate = .17;
const double one_sec = .000000317057705;
const int days_until_strike=5;
const double secs_in_a_day = 86400;

default_random_engine generator;
normal_distribution<double> vol_dis(0.45,.15);
normal_distribution<double> distribution(0.0,1.0);

const int num_of_options = 10;

int random_index()
{
    srand(time(0));
    
    return (rand()%10)+1;
}

double rand_volatility(Options o)
{
    double vol=0;
    
    for (int j=0;j<=(rand()%10000);j++)
    {
        vol= vol_dis(generator);
    }
    
    o.update_volatility(vol);
    
    return vol;
}

double stock_price(double price_one, double risk_free_rate, double change_in_time, double volatility)
{
    double price;
    double e;
    
    for (int j=0;j<=(rand()%10000);j++)
    {
    e=distribution(generator);
    }
    
    price = price_one*((1+risk_free_rate*change_in_time)+(volatility*e*sqrt(change_in_time)));
    
    return price;
}

int main(int argc, const char * argv[])
{
    srand(time(NULL));
    
    double volatility=0;
    double starting_time_til_strike = (days_until_strike*(secs_in_a_day)*one_sec)+one_sec*5;
    double price_now = stock_starting_price;
    
    Options option(stock_starting_price, risk_free_rate, starting_time_til_strike, volatility);
    
    volatility = rand_volatility(option);
    double time_left = starting_time_til_strike;
    
    Market_maker me (num_of_options);
    Books booky;
    Broker brokerr;
    
    double orders_i_will_send[num_of_options];
    
    int rand_broker_option_to_buy=0;
    int opposite =0;
    
    for (int i =0 ; i <secs_in_a_day*days_until_strike;i++)
    {   time_left=time_left-one_sec;
        price_now = stock_price(price_now, risk_free_rate, one_sec, volatility);
        option.update_everything(price_now, time_left, volatility);
        
        cout<<price_now<<endl;
        cout<<option.get_option_price ('c',80,time_left,price_now)<<endl;
        cout<<option.get_option_price ('c',90,time_left,price_now)<<endl;
        cout<<option.get_option_price ('c',100,time_left,price_now)<<endl;
        cout<<option.get_option_price ('c',110,time_left,price_now)<<endl;
        cout<<option.get_option_price ('c',120,time_left,price_now)<<endl;
        cout<<option.get_option_price ('p',80,time_left,price_now)<<endl;
        cout<<option.get_option_price ('p',90,time_left,price_now)<<endl;
        cout<<option.get_option_price ('p',100,time_left,price_now)<<endl;
        cout<<option.get_option_price ('p',110,time_left,price_now)<<endl;
        cout<<option.get_option_price ('p',120,time_left,price_now)<<endl;
        cout<<time_left<<endl<<endl;

        
        if (i%(8640*days_until_strike+4320)==0)
        {

        orders_i_will_send[0]=option.get_option_price ('c',80,time_left,price_now)*1.0112;
        orders_i_will_send[1]=option.get_option_price ('c',90,time_left,price_now)*1.0112;
        orders_i_will_send[2]=option.get_option_price ('c',100,time_left,price_now)*1.0112;
        orders_i_will_send[3]=option.get_option_price ('c',110,time_left,price_now)*1.0112;
        orders_i_will_send[4]=option.get_option_price ('c',120,time_left,price_now)*1.0112;
        orders_i_will_send[5]=option.get_option_price ('p',80,time_left,price_now)*1.0112;
        orders_i_will_send[6]=option.get_option_price ('p',90,time_left,price_now)*1.0112;
        orders_i_will_send[7]=option.get_option_price ('p',100,time_left,price_now)*1.0112;
        orders_i_will_send[8]=option.get_option_price ('p',110,time_left,price_now)*1.0112;
        orders_i_will_send[9]=option.get_option_price ('p',120,time_left,price_now)*1.0112;
        
        me.receive_orders(orders_i_will_send, num_of_options, option);
        
        for (int j = 0; j < 10; j++)
        {
            //sending limit orders to books
            booky.get_mm_book_order(me.order_index(j), (j+1));
        }
        
        rand_broker_option_to_buy=random_index();
            if (rand_broker_option_to_buy>5)
            {
                opposite=rand_broker_option_to_buy-5;
            }else if(rand_broker_option_to_buy<=5)
            {
                opposite=rand_broker_option_to_buy+5;
            }
        
        double temp_hol_price;
        
        temp_hol_price = booky.get_broker_order(brokerr.price_w_pay(option, rand_broker_option_to_buy), rand_broker_option_to_buy);
        
        if (temp_hol_price==0)
        {
            rand_broker_option_to_buy =0;
        }
        
        me.successful_order(temp_hol_price, rand_broker_option_to_buy);
        me.sell_market(option,opposite);
            
        me.close_orders(booky);
       
        me.close_out_all(option );
        
        
        me.cal_PNL(option);
        cout<<me.get_PNL(option)<<endl;
        
        }

    }
    
            cout<<me.get_PNL(option)<<endl;
    
    return 0;
}
