#ifndef Options_hpp
#define Options_hpp

#include <stdio.h>

class Options
{
private:
    double pc80;
    double pp80;
    double pc90;
    double pp90;
    double pc100;
    double pp100;
    double pc110;
    double pp110;
    double pc120;
    double pp120;
    
    double volatility;
    
    double risk_free_rate;
    
    const double Pi = 3.141592653589793238462643;
    
    
    
public:
    
    double price_now;
    
    double time;
    
    Options(double starting_price, double risk_free, double starting_time_left, double v);
    
    double BlackScholes(char CallPutFlag, double S, double X, double T, double r, double v);
    
    double CND( double X );
    
    double get_option_price (char type, double strike_p, double time_left, double stock_price);
    
    void update_volatility(double v);
    
    void update_everything(double stock_price, double time_left, double v);
    
};

#endif
