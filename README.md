# Billing-System

## Overview

This Billing System is a C++ application designed to handle basic billing and inventory management tasks. The program allows users to update inventory, generate bills for customers, and calculate change to be returned. It uses file handling to store and retrieve inventory and billing information.

## Features
### 1.Update Inventory:
Add new items to the inventory, including item name, rate, and quantity.

### 2.Generate Bill:

 --Add items to the bill based on the inventory.

 --Calculate and display the total bill amount.

 --Save bill details to a file.

### 3.Calculate Change: 
Determine the change to be returned to the customer based on the cash provided.

### 4.File Handling:

-Inventory data is stored in inventory.txt.

-Bill details are stored in Bill.txt.

### 5.User-Friendly Interface: 
A simple menu-driven interface to navigate through different features.

## How It Works

### 1. Update Inventory

-Select the option to update inventory.

-Enter the item name, rate, and quantity.

-The item is added to inventory.txt.

### 2. Generate Bill

-Select the option to generate a bill.

-Add items to the bill by specifying their name and quantity.

-The system checks inventory availability:

-If the item is available, it calculates the cost and updates the inventory.

-If the item is out of stock, it notifies the user.

-Save the bill details in Bill.txt.

-Optionally, calculate the change to be returned to the customer.

### 3. Exit

Exit the program safely.

## Code Structure

#### Class bill:

-Private members for item name, rate, and quantity.

-Public methods for getters, setters, and main functionalities.

#### Main Menu:

Displays options to update inventory, generate bills, and exit.

#### File Handling:

Reads and writes inventory and bill data using file streams.

## Notes

-Ensure inventory.txt exists before running the program. If not, it will be created automatically.

-The Bill.txt file is cleared after the bill is printed.

## Limitations

-The program is designed for a single user at a time.

-Does not support concurrent access or multi-threading.

-Requires manual input for all operations.

## Future Enhancements

-Add graphical user interface (GUI) for a more user-friendly experience.

-Implement database integration for more robust data storage.

-Add support for multi-user access and authentication.
