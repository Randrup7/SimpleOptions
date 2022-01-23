#include "OptionMC.h"
#include "Option.h"
#include <iostream>
#include <chrono>

int main()
{
    auto start = std::chrono::steady_clock::now();

    PayOffCall callPayOff(200.0);
    Option callOption(callPayOff, 2.0);

    ParametersConstant vol(0.2);
    ParametersConstant rate(0.02);

    double price = OptionMonteCarlo(callOption, 100.0, vol, rate, 1000000);

    std::cout << price << "\n";

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

    return 0;
}

/*  
    The latest code changes in the book has created a vanilla option class.
    The payoff class has defined a .clone() function that return a copy (new) of the payoff object.
    this makes sure that changes to the original payoff object wont affect the vanilla options class.
    the .clone() function return a pointer to a payoff object.
    The vanilla options class then takes a const reference to a payoff object, 
        which the vanilla options constructor clones.
    The option payoff function in the vanilla options class then dereferences 
        the payoff pointer and calls the payoff function (*ThePayOffPtr)(Spot).
    The vanilla options class has also defined a copy constructor and overloaded the assignment operator.
    Note here that the copy constructor will create the new payoff object as 
        ThePayOffPtr = original.ThePayOffPtr->clone();
    and similarly for the assignment operator (with a check that the assigned object is not the same)
    as the .clone() creates a new payoff, the vanilla options destructor will destroy the payoff. 
 

    In the book, the PayOffBridge is a 'bridge' class that only holds a pointer to a PayOff object.
    The class has defined constructor, copy constructor and overloaded assignment operator, destructor.
    Also a constructor that takes a Payoff object as input.
    That way, we only have to rely on the BrigdePayOff's constructors and destructors, and not write them
        for each derived PayOff class.
    We now have the Option class to take a BridgePayOff instead of a PayOff object.
    Option class now does not have copy semantics defined, as everything is done by the bridge class.


    We have now implemented Parameters class setup. This both includes a bridge class (Parameter) 
        and an abstract base interface class (IParameterInner).
    We have one derived parameter class so far. The ParametersConstant that simply is a constant integral
        and sqaured integral over time1 and time2.
    We could create a derived class to hold a piecewise constant, or follow some other process.
    This is to introduce varying parameters in terms of rates and volatility to the MC-pricer. 
 */