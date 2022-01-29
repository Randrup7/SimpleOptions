# SimpleOptions
*** 
## Description
---
In this repository, I upload the files - .h files, .cpp files, and build settings - I use to follow the book 
"C++ Design Patterns and Derivatives Pricing 2nd Edition" by Mark S. Joshi.

The main.cpp calls the OptionMC function that calculates the value of a stock option with Monte Carlo simulation.

The OptionMC function is flexible as it utilises classes that handle modifications and easy extensions of payoffs, term structure in volatility,
term structure in rates, randon number generation and more.

## Explanaition of part of the code
---
The latest code changes in the book has created a vanilla option class.
The payoff class has defined a .clone() function that return a copy (new) of the payoff object.
this makes sure that changes to the original payoff object wont affect the vanilla options class.
the .clone() function return a pointer to a payoff object.
The vanilla options class then takes a const reference to a payoff object, which the vanilla options constructor clones. The option payoff function in the vanilla options class then dereferences the payoff pointer and calls the payoff function (*ThePayOffPtr)(Spot). The vanilla options class has also defined a copy constructor and overloaded the assignment operator. Note here that the copy constructor will create the new payoff object as ThePayOffPtr = original.ThePayOffPtr->clone(); and similarly for the assignment operator (with a check that the assigned object is not the same) as the .clone() creates a new payoff, the vanilla options destructor will destroy the payoff. 

In the book, the PayOffBridge is a 'bridge' class that only holds a pointer to a PayOff object.
The class has defined constructor, copy constructor and overloaded assignment operator, destructor.
Also a constructor that takes a Payoff object as input. That way, we only have to rely on the BrigdePayOff's constructors and destructors, and not write them for each derived PayOff class. We now have the Option class to take a BridgePayOff instead of a PayOff object. Option class now does not have copy semantics defined, as everything is done by the bridge class. We have now implemented Parameters class setup. This both includes a bridge class (Parameter) and an abstract base interface class (IParameterInner). We have one derived parameter class so far. The ParametersConstant that simply is a constant integral and sqaured integral over time1 and time2. We could create a derived class to hold a piecewise constant, or follow some other process. This is to introduce varying parameters in terms of rates and volatility to the MC-pricer. The OptionMC function now returns void instead of double, as the gatherer input (a reference to a Statistics object) holds all results. In each loop of the simulation, the payoff is inserted in the gatherer.

## Overview of Classes in Project
---
**IPayOff:**
Interface Payoff class with pure virtual overloaded operator() and .clone() and virtual destructor.
Derived classes:
1. PayOffPut
    * Has m_strike as member variable.
    * Has defined .clone function and operator() to return payoff of put option given spot
2. PayOffCall
    * Has m_strike as member variable.
    * Has defined .clone function and operator() to return payoff of call option given spot

**PayOffBridge**
PayOffBridge is a 'bridge' class that only holds a pointer to a PayOff object.
It has defined constructor, copy constructor, overloaded assignment operator and destructor. The normal constructor takes a reference to a IPayOff object as input. This is made to avoid writing similar constructors, destructors etc. for the derived PayOff classes.

**Option**
This class has a PayOffBridge and an expiry as member variables. It has a constructor taking the two member variables as input, a GetExpiry and OptionPayff function to simply return that using the PayOffBridge member.

**IParametersInner**
Abstract interface class that holds virtual destructor and three pure virtual functions. A .clone() function, a Integral and a IntegralSquare function. The ladder two with two double (time1, time2) inputs to return the integral or squared integral between two time stamps.
Derived classes:
1. ParametersConstant
    * Takes a double constant as input.
    * Has Integral function to return constant times time different between the two time stamps
    * Has IntegralSquare function to return the time different between the two time stamps times the squared constant
    * Has a .clone() defined

**Parameters**
Class to hold a pointer to a IParametersInner object. Handles construction, copying, destruction etc. for the inner object. It also has a Mean and RMSE returning the Integral or IntegralSquare over time passed respectively.

**Wrapper**
This class is basically just a smart pointer. It is a template class to take a pointer to an object of type T. It has overloaded operators* and -> in both const and non-const version. It has assignment operator, copy constructor and constructor that takes an input of type T or no input (nullptr)

**IStatisticsMC**
Abstract interface class that holds virtual destructor and three pure virtual functions. A .clone() function, DumpOneResult and GetResultsSoFar.
Derived classes:
1. StatisticsMean
    * Has two member variables; m_PathsDone and m_RunningSum
    * Has .clone() class to copy
    * Has DumpOneResult function that takes a double as input, increases RunningSum by the input and increases PathsDone. The result of the MC trial is meant to be dumped in this class with this function.
    * GetResultsSoFar is a vector of double vectors variable. Returns the result(s) of the MC simulation (RunningSum / PathsDone).
2. ConvergenceTable
    * 



---
## Use of Classes
The OptionMonteCarlo function has the inputs:
* const Option& option,
* double spot,
* const Parameters& vol,
* const Parameters& r,
* unsigned long trials,
* StatisticsMC& gatherer


## Ideas for Improvement
---
* The Wrapper template class is basically just a smart_ptr
* Use move semantics if applicable
* Maybe test to see how many copies is taken.