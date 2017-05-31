

#include "Market_Maker.hpp"
#include "Options.hpp"


Market_maker::Market_maker(int num_of_o) : number_of_options(num_of_o)
{
    order_s [number_of_options];
    
    for (int i =0 ; i < number_of_options; i++)
    {
        order_s[i]=0.0;
    }
    
    realized_PNL =0;
    
    open1=0;
    open2=0;
    open3=0;
    open4=0;
    open5=0;
    open6=0;
    open7=0;
    open8=0;
    open9=0;
    open10=0;
    
}

void Market_maker::receive_orders(double order [], int num_of_o, Options o)
{
    vector<double> prices;
    prices.push_back(o.get_option_price ('c',80,o.time,o.price_now));
    prices.push_back(o.get_option_price ('c',90,o.time,o.price_now));
    prices.push_back(o.get_option_price ('c',100,o.time,o.price_now));
    prices.push_back(o.get_option_price ('c',110,o.time,o.price_now));
    prices.push_back(o.get_option_price ('c',120,o.time,o.price_now));
    prices.push_back(o.get_option_price ('p',80,o.time,o.price_now));
    prices.push_back(o.get_option_price ('p',90,o.time,o.price_now));
    prices.push_back(o.get_option_price ('p',100,o.time,o.price_now));
    prices.push_back(o.get_option_price ('p',110,o.time,o.price_now));
    prices.push_back(o.get_option_price ('p',120,o.time,o.price_now));
    
    if (number_of_options == num_of_o)
    {
        for (int i =0 ; i < number_of_options; i++)
        {
            if(order[i]>(prices[i]*.95)){
              order_s[i]=order[i];
            }
            else
            {
                order_s[i]=(prices[i]*.95);
            }
        }
    }
    prices.clear();
}

void Market_maker::sell_market(Options o, int index)
{
    vector<double> prices;
    prices.push_back(o.get_option_price ('c',80,o.time,o.price_now));
    prices.push_back(o.get_option_price ('c',90,o.time,o.price_now));
    prices.push_back(o.get_option_price ('c',100,o.time,o.price_now));
    prices.push_back(o.get_option_price ('c',110,o.time,o.price_now));
    prices.push_back(o.get_option_price ('c',120,o.time,o.price_now));
    prices.push_back(o.get_option_price ('p',80,o.time,o.price_now));
    prices.push_back(o.get_option_price ('p',90,o.time,o.price_now));
    prices.push_back(o.get_option_price ('p',100,o.time,o.price_now));
    prices.push_back(o.get_option_price ('p',110,o.time,o.price_now));
    prices.push_back(o.get_option_price ('p',120,o.time,o.price_now));
    
    (*this).successful_order(prices[index-1], index);
    
}

double Market_maker::order_index (int index_num)
{
    double num = order_s[index_num];
    
    return num;
}

double  Market_maker::get_PNL(Options o)
{
    cal_PNL (o);
    return (*this).PNL;
}

void Market_maker::successful_order (double price_sold_at, int index)
{
    if (index==1)
    {
        price_sold1.push_back(price_sold_at);
        open1++;
    }else if (index==2)
    {
        price_sold2.push_back(price_sold_at);
        open2++;
    }
    else if (index==3)
    {
        price_sold3.push_back(price_sold_at);
        open3++;

    }else if (index==4)
    {
        price_sold4.push_back(price_sold_at);
        open4++;
 
    }else if (index==5)
    {
        price_sold5.push_back(price_sold_at);
        open5++;

    }else if (index==6)
    {
        price_sold6.push_back(price_sold_at);
        open6++;

    }else if (index==7)
    {
        price_sold7.push_back(price_sold_at);
        open7++;
 
    }else if (index==8)
    {
        price_sold8.push_back(price_sold_at);
        open8++;

    }else if (index==9)
    {
        price_sold9.push_back(price_sold_at);
        open9++;

    }else if (index==10)
    {
        price_sold10.push_back(price_sold_at);
        open10++;

    }
    else if (index == 0)
    {
        //miss
    }
}

void Market_maker::cal_PNL (Options o)
{
    //sold-real
    
    PNL = realized_PNL+0;
    
    if (open1>0)
    {
        for (int i =0; i < open1; i++)
        {
            PNL = PNL + price_sold1[i]-o.get_option_price('c', 80, o.time, o.price_now);
        }
        
    }else if (open2>0)
    {
        for (int i =0; i < open2; i++)
        {
            PNL = PNL + price_sold2[i]-o.get_option_price('c', 90, o.time, o.price_now);
        }
    }else if (open3>0)
    {
        for (int i =0; i < open3; i++)
        {
            PNL = PNL + price_sold3[i]-o.get_option_price('c', 100, o.time, o.price_now);
        }
    }else if (open4>0)
    {
        for (int i =0; i < open4; i++)
        {
            PNL = PNL + price_sold4[i]-o.get_option_price('c', 110, o.time, o.price_now);
        }
        
    }else if (open5>0)
    {
        for (int i =0; i < open5; i++)
        {
            PNL = PNL + price_sold5[i]-o.get_option_price('c', 120, o.time, o.price_now);
        }
        
    }else if (open6>0)
    {
        for (int i =0; i < open6; i++)
        {
            PNL = PNL + price_sold6[i]-o.get_option_price('p', 80, o.time, o.price_now);
        }
        
    }else if (open7>0)
    {
        for (int i =0; i < open7; i++)
        {
            PNL = PNL + price_sold7[i]-o.get_option_price('p', 90, o.time, o.price_now);
        }
    }else if (open8>0)
    {
        for (int i =0; i < open8; i++)
        {
            PNL = PNL + price_sold8[i]-o.get_option_price('p', 100, o.time, o.price_now);
        }
        
    }else if (open9>0)
    {
        for (int i =0; i < open9; i++)
        {
            PNL = PNL + price_sold9[i]-o.get_option_price('p', 110, o.time, o.price_now);
        }
        
    }else if (open10>0)
    {
        for (int i =0; i < open10; i++)
        {
            PNL = PNL + price_sold10[i]-o.get_option_price('p', 120, o.time, o.price_now);
        }
    }
    
}

void Market_maker::close_out (Options o, int index)
{
    if (index==1)
    {
        if (open1>0)
        {
            for (int i =0; i < open1; i++)
            {
                realized_PNL = realized_PNL + price_sold1[i]-o.get_option_price('c', 80, o.time, o.price_now);
            }
            
        }
        open1=0;
        price_sold1.clear();
        
    }else if (index==2)
    {
        if (open2>0)
        {
            for (int i =0; i < open2; i++)
            {
                realized_PNL = realized_PNL + price_sold2[i]-o.get_option_price('c', 90, o.time, o.price_now);
            }
        }
        open2=0;
        price_sold2.clear();
        
    }else if (index==3)
    {
        if (open3>0)
        {
            for (int i =0; i < open3; i++)
            {
                realized_PNL = realized_PNL + price_sold3[i]-o.get_option_price('c', 100, o.time, o.price_now);
            }
        }
        open3=0;
        price_sold3.clear();
    }else if (index==4)
    {
        if (open4>0)
        {
            for (int i =0; i < open4; i++)
            {
                realized_PNL = realized_PNL + price_sold4[i]-o.get_option_price('c', 110, o.time, o.price_now);
            }
            
        }
        open4=0;
        price_sold4.clear();
    }else if (index==5)
    {
        if (open5>0)
        {
            for (int i =0; i < open5; i++)
            {
                realized_PNL = realized_PNL + price_sold5[i]-o.get_option_price('c', 120, o.time, o.price_now);
            }
            
        }
        open5=0;
        price_sold5.clear();
    }else if (index==6)
    {
        if (open6>0)
        {
            for (int i =0; i < open6; i++)
            {
                realized_PNL = realized_PNL + price_sold6[i]-o.get_option_price('p', 80, o.time, o.price_now);
            }
            
        }
        open6=0;
        price_sold6.clear();
    }else if (index==7)
    {
        if (open7>0)
        {
            for (int i =0; i < open7; i++)
            {
                realized_PNL = realized_PNL + price_sold7[i]-o.get_option_price('p', 90, o.time, o.price_now);
            }
        }
        open7=0;
        price_sold7.clear();
    }else if (index==8)
    {
        if (open8>0)
        {
            for (int i =0; i < open8; i++)
            {
                realized_PNL = realized_PNL + price_sold8[i]-o.get_option_price('p', 100, o.time, o.price_now);
            }
            
        }
        open8=0;
        price_sold8.clear();
    }else if (index==9)
    {
        if (open9>0)
        {
            for (int i =0; i < open9; i++)
            {
                realized_PNL = realized_PNL + price_sold9[i]-o.get_option_price('p', 110, o.time, o.price_now);
            }
            
        }
        open9=0;
        price_sold9.clear();
    }else if (index==10)
    {
        if (open10>0)
        {
            for (int i =0; i < open10; i++)
            {
                realized_PNL = realized_PNL + price_sold10[i]-o.get_option_price('p', 120, o.time, o.price_now);
            }
        }
        open10=0;
        price_sold10.clear();
        
    }
    
    cal_PNL(o);
}

void Market_maker::close_out_all (Options o)
{
    for (int i=1; i<11;i++)
    {
        close_out (o,i);
    }
}

double Market_maker::get_realized(Options o)
{
    cal_PNL(o);
    return realized_PNL;
}

void Market_maker::close_orders(Books booky){
    booky.close_books();
}

