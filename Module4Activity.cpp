// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <exception>

//creating customException class that is derived from std::exception
class customException : public std::exception {
public:
    const char* what() const noexcept override {
        return "custom exception"; //returns with custom exception message
    }
};


bool do_even_more_custom_application_logic()
{
    //Throwing any standard exception
    throw std::runtime_error("Standard Exception"); //choosing a runtime_error exception to throw

    std::cout << "Running Even More Custom Application Logic." << std::endl;

    return true;
}
void do_custom_application_logic()
{
    std::cout << "Running Custom Application Logic." << std::endl;

    try { //try block to get printed message of success
        if (do_even_more_custom_application_logic()){
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        }
    }

    catch (const std::exception& ex) { //catching std::exception if thrown
        std::cout << "exception caught : " << ex.what() << std::endl;  //if exception is caught, it will desplay an error message aliong with what exception that was caught

    }

    // Throwing a custom exception derived from std::exception and catching it explictly in main
    throw customException();

    std::cout << "Leaving Custom Application Logic." << std::endl;

}

float divide(float num, float den)
{
    if (den == 0) { //if denominator is 0
        throw std::runtime_error("Division by zero exception"); //exception message will print
    }

    return (num / den);
}

void do_division() noexcept
{
    try { // try block start for division of numbers
       
        float numerator = 10.0f;
        float denominator = 0;

        auto result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    }

    catch(const std::exception& ex){ // catch block to catch exceptions thrown by divide
        std::cout << "Exception caught: " << ex.what() << std::endl; //error message being output to the console if an exception is caught
    }
}

int main()
{
    std::cout << "Exceptions Tests!" << std::endl;
        
    try { //putting division in try block. if excpetion is caught/thrown then the catch block will catch the exception
        do_division();
        do_custom_application_logic();
    }

    catch (const customException& ex) { //catch block for custom exception
        std::cout << "custom exception caught: " << ex.what() << std::endl;
    }

    catch (const std::exception& ex) { //catch block for std::exception
        std::cout << "standard exception caught: " << ex.what() << std::endl;
    }

    catch (...) { //catch block for unhandled exception
        std::cout << "not handled exception caught!" << std::endl;
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu