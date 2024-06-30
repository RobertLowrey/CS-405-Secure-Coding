// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>

int main()
{
	std::cout << "Buffer Overflow Example" << std::endl;

	// TODO: The user can type more than 20 characters and overflow the buffer, resulting in account_number being replaced -
	//  even though it is a constant and the compiler buffer overflow checks are on.
	//  You need to modify this method to prevent buffer overflow without changing the account_order
	//  varaible, and its position in the declaration. It must always be directly before the variable used for input.

	const std::string account_number = "CharlieBrown42";
	std::string user_input;
	std::cout << "Enter a value: ";
	std::cin >> user_input;

	if (user_input.length() > 20) { //checks length of input
		std::cout << "Too long of input!! try again with less than 20 characters/numbers" << std::endl; // if input is greater than 20, error will print
		return 1; //exists the program
	}

	//add new line terminator on end of input string 
	user_input += '\n';


	std::cout << "You entered: " << user_input << std::endl;
	std::cout << "Account Number = " << account_number << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
