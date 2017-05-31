#include "Options.hpp"
#include <iostream>
#include <cmath>


Options::Options(double starting_price, double risk_free, double starting_time_left, double v)
{
    this->risk_free_rate = risk_free;
    
    this->update_everything(starting_price, starting_time_left, v);
    
}


double Options::BlackScholes(char CallPutFlag, double S, double X, double T, double r, double v)
{
    double d1, d2;
    double bs_price;
    
    
    d1=(log(S/X)+(r+v*v/2)*T)/(v*sqrt(T));
    d2=d1-v*sqrt(T);
    
    if(CallPutFlag == 'c')
        bs_price = S *CND(d1)-X * exp(-r*T)*CND(d2);
    else if(CallPutFlag == 'p')
        bs_price =  X * exp(-r * T) * CND(-d2) - S * CND(-d1);
    else
        return 0;
    
    if (bs_price <0.01)
    {
        return 0.01;
    }
    else
    {
        return bs_price;
    }
}


double Options::CND( double X )
{
    double L, K, w ;
    
    double const a1 = 0.31938153, a2 = -0.356563782, a3 = 1.781477937;
    double const a4 = -1.821255978, a5 = 1.330274429;
    
    L = fabs(X);
    K = 1.0 / (1.0 + 0.2316419 * L);
    w = 1.0 - 1.0 / sqrt(2 * Pi) * exp(-L *L / 2) * (a1 * K + a2 * K *K + a3 * pow(K,3) + a4 * pow(K,4) + a5 * pow(K,5));
    
    if (X < 0 ){
        w= 1.0 - w;
    }
    return w;
}


double Options::get_option_price (char type, double strike_p, double time_left, double stock_price)
{
    double interested_stock;
    update_everything(stock_price, time_left , this->volatility);
    
    if (type == 'c')
    {
        if (strike_p == 80)
        {
            interested_stock = pc80;
        }
        else if (strike_p ==90)
        {
            interested_stock = pc90;
        }
        else if (strike_p ==100)
        {
            interested_stock = pc100;
        }
        else if (strike_p ==110)
        {
            interested_stock = pc110;
        }
        else if (strike_p ==120)
        {
            interested_stock = pc120;
        }
        
    }else if (type == 'p')
    {
        if (strike_p == 80)
        {
            interested_stock = pp80;
        }
        else if (strike_p ==90)
        {
            interested_stock = pp90;
        }
        else if (strike_p ==100)
        {
            interested_stock = pp100;
        }
        else if (strike_p ==110)
        {
            interested_stock = pp110;
        }
        else if (strike_p ==120)
        {
            interested_stock = pp120;
        }
        
    }else{
        
    }

    return interested_stock;
}


void Options::update_volatility(double v)
{
    this->volatility = v;
}


void Options::update_everything(double stock_price, double time_left, double v)
{
    update_volatility(v);
    
    price_now = stock_price;
    
    time = time_left;
    
    pc80=BlackScholes('c', stock_price, 80, time_left, this->risk_free_rate, this->volatility);
    pp80=BlackScholes('p', stock_price, 80, time_left, this->risk_free_rate, this->volatility);
    pc90=BlackScholes('c', stock_price, 90, time_left, this->risk_free_rate, this->volatility);
    pp90=BlackScholes('p', stock_price, 90, time_left, this->risk_free_rate, this->volatility);
    pc100=BlackScholes('c', stock_price, 100, time_left, this->risk_free_rate, this->volatility);
    pp100=BlackScholes('p', stock_price, 100, time_left, this->risk_free_rate, this->volatility);
    pc110=BlackScholes('c', stock_price, 110, time_left, this->risk_free_rate, this->volatility);
    pp110=BlackScholes('p', stock_price, 110, time_left, this->risk_free_rate, this->volatility);
    pc120=BlackScholes('c', stock_price, 120, time_left, this->risk_free_rate, this->volatility);
    pp120=BlackScholes('p', stock_price, 120, time_left, this->risk_free_rate, this->volatility);
}


