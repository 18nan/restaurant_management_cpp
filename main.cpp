#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Restaurant
{
public:
    virtual void display()
    {
        cout << "\nRestaurant Management System\n";
    }

    virtual ~Restaurant()
    {
    }
};

class Customer : public Restaurant
{
private:
    string itemNames[50];
    int itemPrices[50];
    int itemCount;

public:
    Customer()
    {
        itemCount = 0;
    }

    void display()
    {
        cout << "\nRestaurant Menu\n";
    }

    void placeOrder()
{
    ifstream file("menu.txt");

    if (!file)
    {
        throw "Unable to open menu.txt.";
    }

    string line;
    string name;
    int price;
    int i = 0;

    cout << "\n---------- RESTAURANT MENU ----------\n\n";

    while (getline(file, line))
    {
        if (line == "Gourmet Rolls:" ||
            line == "Side Dish:" ||
            line == "Drinks:" ||
            line == "Dessert:")
        {
            cout << "\n" << line << "\n";
        }
        else if (line.length() > 0)
        {
            int lastSpace = line.length() - 1;

            while (lastSpace >= 0 && line[lastSpace] == ' ')
            {
                lastSpace--;
            }

            int end = lastSpace;

            while (lastSpace >= 0 &&
                   line[lastSpace] >= '0' &&
                   line[lastSpace] <= '9')
            {
                lastSpace--;
            }

            if (lastSpace < end && i < 50)
            {
                price = 0;

                for (int j = lastSpace + 1; j <= end; j++)
                {
                    price = price * 10 + (line[j] - '0');
                }

                name = line.substr(0, lastSpace + 1);

                while (name.length() > 0 &&
                       name[name.length() - 1] == ' ')
                {
                    name.erase(name.length() - 1, 1);
                }

                itemNames[i] = name;
                itemPrices[i] = price;

                cout << i + 1 << ". "
                     << itemNames[i] << " - Rs. "
                     << itemPrices[i] << "\n";

                i++;
            }
        }
    }

    file.close();

    if (i == 0)
    {
        throw "No menu items found in menu.txt.";
    }

    itemCount = i;

    int quantities[50] = {0};
    int choice;
    int quantity;
    int orderPlaced = 0;

    // THIS IS THE ORDERING OPTION THAT WAS MISSING
    cout << "\n----------------------------------------\n";
    cout << "             PLACE YOUR ORDER\n";
    cout << "\n----------------------------------------\n";
    cout << "Enter the item number to order it.\n";
    cout << "Enter 0 when you finish ordering.\n";
    cout << "Enter -1 to cancel your order.\n";

    while (true)
    {
        cout << "\nEnter item number: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter a valid number.\n";
            continue;
        }

        if (choice == -1)
        {
            cout << "\nOrder cancelled.\n";
            return;
        }

        if (choice == 0)
        {
            break;
        }

        if (choice < 1 || choice > itemCount)
        {
            cout << "Invalid item number. Please try again.\n";
            continue;
        }

        cout << "Selected: " << itemNames[choice - 1] << "\n";
        cout << "Enter quantity: ";
        cin >> quantity;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter a valid quantity.\n";
            continue;
        }

        if (quantity <= 0)
        {
            cout << "Quantity must be greater than zero.\n";
            continue;
        }

        quantities[choice - 1] += quantity;
        orderPlaced = 1;

        cout << itemNames[choice - 1]
             << " added to your order.\n";
    }

    if (orderPlaced == 0)
    {
        cout << "\nNo items ordered. No bill generated.\n";
        return;
    }

    double total = 0;

    cout << "\n----------------------------------------\n";
    cout << "                 CUSTOMER BILL\n";
    cout << "\n----------------------------------------\n";

    cout << left << setw(27) << "Item"
         << right << setw(6) << "Qty"
         << setw(10) << "Price"
         << setw(10) << "Amount" << "\n";

    cout << "--------------------------------------------\n";

    for (int j = 0; j < itemCount; j++)
    {
        if (quantities[j] > 0)
        {
            double amount = itemPrices[j] * quantities[j];
            total += amount;

            cout << left << setw(27) << itemNames[j]
                 << right << setw(6) << quantities[j]
                 << setw(10) << itemPrices[j]
                 << setw(10) << fixed << setprecision(2)
                 << amount << "\n";
        }
    }

    cout << "--------------------------------------------\n";
    cout << "Total Amount: Rs. "
         << fixed << setprecision(2) << total << "\n";
    cout << "============================================\n";
    cout << "       Thank you for your order!\n";
    cout << "============================================\n";
}
};

class Staff : public Restaurant
{
public:
    void display()
    {
        cout << "\nStaff Portal\n";
    }
};

class Schedule : public Staff
{
public:
    void display()
    {
        ifstream file("schedule.txt");

        if (!file)
        {
            throw "Unable to open schedule.txt.";
        }

        string line;

        cout << "\n";

        while (getline(file, line))
        {
            cout << line << "\n";
        }

        file.close();
    }
};

class Pantry : public Staff
{
public:
    void display()
    {
        ifstream file("pantry.txt");

        if (!file)
        {
            throw "Unable to open pantry.txt.";
        }

        string line;

        cout << "\n";

        while (getline(file, line))
        {
            cout << line << "\n";
        }

        file.close();
    }
};

class Recipes : public Staff
{
public:
    void display()
    {
        ifstream file("recipes.txt");

        if (!file)
        {
            throw "Unable to open recipes.txt.";
        }

        string line;

        cout << "\n";

        while (getline(file, line))
        {
            cout << line << "\n";
        }

        file.close();
    }
};

void staffPortal()
{
    int choice;

    do
    {
        cout << "\nStaff Portal\n";
        cout << "1. Staff Schedule\n";
        cout << "2. Pantry Management\n";
        cout << "3. Recipes\n";
        cout << "4. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try
        {
            Restaurant *portal;

            Schedule schedule;
            Pantry pantry;
            Recipes recipes;

            switch (choice)
            {
            case 1:
                portal = &schedule;
                portal->display();
                break;

            case 2:
                portal = &pantry;
                portal->display();
                break;

            case 3:
                portal = &recipes;
                portal->display();
                break;

            case 4:
                cout << "\nReturning to Main Menu...\n";
                break;

            default:
                cout << "\nInvalid choice. Try again.\n";
            }
        }
        catch (const char *message)
        {
            cout << "\nError: " << message << "\n";
        }

    } while (choice != 4);
}

int main()
{
    int choice;

    Customer customer;
    Staff staff;
    Restaurant *portal;

    do
    {
        cout << "\nRestaurant Management System\n";
        cout << "1. Customer\n";
        cout << "2. Staff\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try
        {
            switch (choice)
            {
            case 1:
                portal = &customer;
                portal->display();
                customer.placeOrder();
                break;

            case 2:
                portal = &staff;
                portal->display();
                staffPortal();
                break;

            case 3:
                cout << "\nThank you for visiting!\n";
                break;

            default:
                cout << "\nInvalid choice. Try again.\n";
            }
        }
        catch (const char *message)
        {
            cout << "\nError: " << message << "\n";
        }

    } while (choice != 3);

    return 0;
}
