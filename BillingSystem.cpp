#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
using namespace std;

class bill {
private:
    string Item_name;
    int Rate, Qty;

public:
    bill() : Item_name(""), Rate(0), Qty(0) {}//constructor for initializing the values

//Getters and setters for getting values and setting them
    void setItem(string item) {
        Item_name = item;
    }

    void setRate(int rate) {
        Rate = rate;
    }

    void setQuant(int quant) {
        Qty = quant;
    }

    string getItem() {
        return Item_name;
    }

    int getRate() {
        return Rate;
    }

    int getQuant() {
        return Qty;
    }
//function definition
    void addInventory(bill B);
    void generateBill(bill B);
};

// Function to update inventory
void bill::addInventory(bill B) {
    ofstream outfile("inventory.txt", ios::app);
    string item;
    int rate, quant;

    cout << "\tEnter Item Name: ";
    cin >> item;
    cout << "\tEnter Rate: ";
    cin >> rate;
    cout << "\tEnter Quantity: ";
    cin >> quant;

    outfile << item << " : " << rate << " : " << quant << endl;//writes into  the inventory text file
    outfile.close();
    cout << "\tInventory Updated Successfully!" << endl;
}

// Function to generate bill
void bill::generateBill(bill B) {
    bool close = false;
    int totalAmount = 0;
    while (!close) {
        int choice;
        cout << "\t\t1. Add Item" << endl;
        cout << "\t\t2. Print Bill" << endl;
        cout << "\t\t3. Calculate Change to be returned" << endl;
        cout << "\t\t4. Close" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1) {
            ifstream infile("inventory.txt");
            ofstream outfile1("inventory temp.txt");
            ofstream outfile2("Bill.txt", ios::app);
            string item;
            int quant;

            cout << "\tEnter Item: ";
            cin >> item;
            cout << "\tEnter Quantity: ";
            cin >> quant;

            string line;
            bool found = false;
            //iterating through each line of the text file
            while (getline(infile, line)) {
                stringstream ss(line);
                string itemName;
                int itemRate, itemQuant;
                char delimiter;

                ss >> itemName >> delimiter >> itemRate >> delimiter >> itemQuant;

                if (item == itemName) {
                    found = true;
                    if (quant <= itemQuant) {
                        int amount = itemRate * quant;
                        cout << "\t Item | Rate | Quantity | Amount" << endl;
                        cout << "\t" << itemName << "\t " << itemRate << "\t " << quant << "\t " << amount << endl;
                        int newQuant = itemQuant - quant;
                        outfile1 << itemName << " : " << itemRate << " : " << newQuant << endl;
                        outfile2 << itemName << " : " << itemRate << " : " << quant << " : " << amount << endl;
                    }
                    else {
                        cout << "\tSorry, " << item << " Out of Stock!" << endl;
                    }
                }
                else {
                    outfile1 << line << endl;
                }
            }

            if (!found) {
                cout << "\tItem Not Available!" << endl;
            }

            infile.close();
            outfile1.close();
            outfile2.close();
            remove("inventory.txt");//removes the old file
            rename("inventory temp.txt", "inventory.txt");//temp file becomes the new updated file
        }
        else if (choice == 2) {
            ifstream infile("Bill.txt");
            string line;
            totalAmount=0;
            cout << "\t Item | Rate | Quantity | Amount" << endl;
            cout << "\t--------------------------------" << endl;

            while (getline(infile, line)) {
                stringstream ss(line);
                string itemName;
                int itemRate, itemQuant, amount;
                char delimiter;
                //displaying the bill
                ss >> itemName >> delimiter >> itemRate >> delimiter >> itemQuant >> delimiter >> amount;

                cout << "\t" << itemName << "\t " << itemRate << "\t " << itemQuant << "\t " << amount << endl;
                totalAmount += amount;//calculating the total amount of the bill
            }

            infile.close();
            cout << "\t--------------------------------" << endl;
            cout << "\t Total Bill ----------------- : " << totalAmount << endl << endl;
            cout << "\tThanks For Shopping!" << endl;
            Sleep(5000);

            ofstream outfile("Bill.txt", ios::trunc);
            outfile.close();
        }
        //Calculates the total change to be returned to a customer
        else if(choice==3){
            system("cls");
            int cash;
            cout<<"Enter amount of cash given by user:";
            cin>>cash;
            int change=cash-totalAmount;
            cout<<"Total change to be returned:"<<change<<endl;

        }
        else if (choice == 4) {
            system("cls");
            close = true;
            cout << "\tBack To Main Menu!" << endl;
            Sleep(3000);
        }
        else {
            cout << "\tInvalid Choice! Try Again." << endl;
        }
    }
}

int main() {
    bill B;
    bool exit = false;
    while (!exit) {
        system("cls");
        int choice;
        cout << "\tWelcome To Billing System" << endl;
        cout << "\t---------------------------" << endl;
        cout << "\t\t1. Update Inventory" << endl;
        cout << "\t\t2. Generate Bill" << endl;
        cout << "\t\t3. Exit" << endl;
        cout << "\t\tEnter Choice: ";
        cin >> choice;

        if (choice == 1) {
            system("cls");
            B.addInventory(B);
            Sleep(3000);//delay
        }
        else if (choice == 2) {
            system("cls");//clears the screen
            B.generateBill(B);
            Sleep(3000);
        }
        else if (choice == 3) {
            exit = true;
            cout << "\tGoodbye!" << endl;
            Sleep(3000);
        }
        else {
            cout << "\tInvalid Choice! Try Again." << endl;
        }
    }
    return 0;
}
