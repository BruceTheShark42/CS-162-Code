#include <iostream>

#define MAX_CHARS 65

// Compares a char[] with another char[]
bool CompareCStrings(char* str1, const char* str2)
{
	// If only one is nullptr
	if ((str1 != nullptr) ^ (str2 != nullptr))
		// They're not equal
		return false;
	// If they're both nullptr
	if (!str1 && !str2)
		// They're equal
		return true;
	
	// Both are not nullptr, so check their lengths and characters
	unsigned int i = 0;
	// While they both have more characters
	while (str1[i] && str2[i])
	{
		// If their characters aren't equal
		if (str1[i] != str2[i])
			// They aren't equal
			return false;
		++i;
	}
	
	// If they both have a null terminating character in the same place, they're equal
	return !str1[i] && !str2[i];
}

// Returns a char[] entered by the user
char* GetString(const char* message)
{
	// Print the message
	std::cout << message;
	char* in = new char[MAX_CHARS];
	
	// Get user input
	std::cin.get(in, MAX_CHARS, '\n');
	
	// Help clean up io stuff
	std::cin.get();
	if (!std::cin)
	{
		std::cin.clear();
		std::cin.get();
	}
	
	return in;
}

int main()
{
	// Welcome message
	std::cout << "Welcome to Checkout Simulator!\n"
		  << "To add an item to your cart, type:\n"
		  << "\"add\" followed by the name of\n"
		  << "the item and the price as well.\n"
		  << "When you'd like to checkout,\n"
		  << "at the next opportunity, type:\n"
		  << "\"checkout\". Alternatively, you\n"
		  << "could type: \"exit\" to put\n"
		  << "everything in your cart back\n"
		  << "where it came from and go home.\n"
		  << "Have fun shopping!\n";
	
	double total = 0.0;
	bool shopping = true, exited = false;
	
	while (shopping)
	{
		// Prompt the user for what they want to do
		char* action = GetString("\nWhat would you like to do?\n> ");
		
		// If they want to add something to their cart
		if (CompareCStrings(action, "add"))
		{
			// Get the name of the item
			char* itemName = GetString("Enter the name of the item: ");
			
			// Get the price of the item
			char* costInput = GetString("Enter the price of the item: ");
			
			// Check the validity of the price
			bool bad = false, foundDecimal = false, badOnFirst = false;
			unsigned int i = 0, numbersAfterDecimal = 0;
			while (!bad && costInput[i])
			{
				// If the character is not a number
				if (costInput[i] < '0' || costInput[i] > '9')
				{
					// If a decimal point hasn't been found and the character being checked is a decimal point
					if (!foundDecimal && (foundDecimal = costInput[i] == '.'))
						// Inform the checker that a decimal point has been found
						foundDecimal = true;
					else
						// The price is invalid (more than one decimal point)
						bad = true;
				}
				// If a decimal is found and there's more than 2 numbers after it
				else if (foundDecimal && ++numbersAfterDecimal > 2)
					// The price is invalid because this 
					// doesn't support 1/10ths of a cent
					bad = true;
				
				// If the price is valid
				// Maybe i should rename "bad" to "invalid"...
				if (!bad)
					++i;
			}
			
			// This will make std::stod throw not an error
			if (i == 1 && costInput[0] == '.')
				bad = true;
			
			// If the price is invalid
			if (bad || !i)
			{
				// Inform the user what they did wrong
				if (bad)
					std::cout << "You entered bad data.\n"
						  << "Invalid character found at index = " << i << ": '" << costInput[i] << "'\n";
				else
					std::cout << "You entered nothing, how rude!\n";
			}
			else // The price is valid
			{
				double itemPrice = std::stod(costInput);
				
				// Let the user confirm their information
				std::cout << "Is the following information correct? (yes/no)\n"
					  << "Item Name: " << itemName << '\n'
					  << "Item Price: " << itemPrice << '\n';
				char* validation = GetString("");
				
				// If they validate the information
				if (CompareCStrings(validation, "yes"))
					// Tell them their total and save it
					std::cout << "Your total is now: " << (total += itemPrice) << '\n';
				else if (!CompareCStrings(validation, "no"))
					// Anything that isn't yes or no is interpreted as no
					std::cout << "Interpreting \"" << validation << "\" as no.\n";
				
				// Memory management
				delete[] itemName;
				delete[] costInput;
				delete[] validation;
			}
		}
		// If the user wants to go to the checkout aisle
		else if (CompareCStrings(action, "checkout"))
		{
			// Let the user confirm if they want to checkout
			char* terminate = GetString("Are you sure you want to check out? (yes/no)\n");
			
			// If they do want to checkout
			if (CompareCStrings(terminate, "yes"))
				// Stop shopping
				shopping = false;
			else if (!CompareCStrings(terminate, "no"))
				// Anything that isn't yes or no is interpreted as no
				std::cout << "Interpreting \"" << terminate << "\" as no.\n";
			
			// More memory management
			delete[] terminate;
		}
		// If the user wants to exit the store
		else if (CompareCStrings(action, "exit"))
		{
			shopping = false;
			exited = true;
		}
		else // The user input an unknown command
			std::cout << "Unknown command.\n";
		
		// Even more memory management
		delete[] action;
	}
	
	// If the user hasn't exited the store
	if (!exited)
	{
		// Setup std::cout for correct displayment of their cost
		std::cout.setf(std::ios::fixed, std::ios::floatfield);
		std::cout.setf(std::ios::showpoint);
		std::cout.precision(2);
		
		// Print their total cost
		std::cout << "Your total is: $" << total << '\n';
	}
	
	return 0;
}
