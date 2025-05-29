// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>
#include <limits>

int main()
{
  std::cout << "Buffer Overflow Example" << std::endl;

  // TODO: The user can type more than 20 characters and overflow the buffer, 
  // resulting in account_number being replaced -
  //  even though it is a constant and the compiler buffer overflow checks are on.
  //  You need to modify this method to prevent buffer overflow without changing the account_number
  //  variable, and its position in the declaration. 
  // It must always be directly before the variable used for input.
  //  You must notify the user if they entered too much data.

  const std::string account_number = "CharlieBrown42";
  char user_input[20];
  std::cout << "Enter a value: ";

  // Safe input
  std::cin >> std::setw(20) >> user_input; // setw() sets limit to 19 + null terminator

  while (std::cin.peek() != '\n') { // return next char without destroying it, check if null terminator
      std::cout << "Input length is too large!\nPlease input under 20 characters.\n";

      // Ignore/flush additional chars, Safe upper bound from stream size
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      std::cout << "Enter a value: ";
      std::cin >> std::setw(20) >> user_input; // Again, safely setw() limits input size
  }

 
	std::cout << "You entered: " << user_input << std::endl;
	std::cout << "Account Number = " << account_number << std::endl;
  
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
