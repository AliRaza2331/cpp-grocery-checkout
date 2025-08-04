// ALI RAZA
// Project 1 (Sep. 23, 2024)

/*

Objective: The goal of this assignment is to create a simple checkout system for a grocery store
using C++ constructs such as variables, loops, conditional statements, strings, vectors and
any other construct that we have covered so far in our course.

Problem Statement: You are tasked with developing a program that simulates a grocery store checkout
system. The program should allow a user to input items they want to purchase and calculate the total
cost of those items, accounting for any discounts or taxes.

*/

# include <iostream>
# include <cmath>
# include <string>
# include <vector>
# include <iomanip>


// A structure with several data types for an item with its price and quantity details
struct Item {
    std::string name;
    double price;
    int quantity;
};


int main() {
	
	// list with the item structure 
	std::vector<Item> item_list;
	
	std::string name;
	double price;
	int quantity;
	
	// Initializing fixed and constant variables
	double total_price = 0.0;
	const double discount_rate = 0.10;
	const double tax_rate = 0.05;
	
	
	// An infinite loop for adding items that breaks when done is entered for name
	while (true) {
		
		// Asks for user name input
		std::cout << "Enter item name: or done to finish";
		std::cin >> name;
		
		// loop break command
		if (name == "done") {
			break;
		}
		
		// Asks for item price
		std::cout << "Enter item price: ";
		std::cin >> price;
		
		// Asks for item quantity
		std::cout << "Enter item quantity: ";
		std::cin >> quantity;
		
		// Initializing boolean variable
		bool item_exists = false;
		
		// Checks for an existing item and adjusts only quantity
		for (auto& item : item_list) {
			if (item.name == name) {
				item.quantity += quantity;
				item_exists = true;
				break;
			}
		}
		
		// If item does not exist in the list, new item is added
		// push_back() is a method of the std::vector class that adds a new element to the end of the vector.
		if (!item_exists) {
            item_list.push_back({name, price, quantity});
        }
		
		// Keeps track of total price in the list
		total_price += price * quantity;
	}
	
	// Calculates discount, applied if total is above $100
    double discount = 0.0;
    if (total_price > 100.00) {
        discount = total_price * discount_rate;
    }
	
	// Calculates price after the discount, id applied
    double discounted_total = total_price - discount;

    // Calculates tax of 5%
    double tax = discounted_total * tax_rate;
	
	// Calculates End price
    double final_price = discounted_total + tax;
	
	// Outputs the receipt
	
	// Print "Item purchased" followed by a new line
    std::cout << "\nItems Purchased:\n";
	// Iterates through the list using address, &, avoids copying any items
	// i.e. item in item_list, and auto deduces its data type automatically
    for (const auto& item : item_list) {
        double item_total_price = item.price * item.quantity;
		// outputs items in list, always rounds to a fixed 2 decimal places
        std::cout << "- " << item.name << ": $" << std::fixed << std::setprecision(2) << item_total_price << "\n";
    }

    std::cout << "Total before discount: $" << std::fixed << std::setprecision(2) << total_price << std::endl;
    std::cout << "Total after discount: $" << std::fixed << std::setprecision(2) << discounted_total << std::endl;
    std::cout << "Total after tax: $" << std::fixed << std::setprecision(2) << final_price << std::endl;

    std::cout << "Thank you for shopping with us!" << std::endl;

	return 0;
}
