#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Restaurant
{
public:
    virtual void Display()
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
    string ItemNames[50];
    int ItemPrices[50];
    int ItemCount;

public:
    Customer()
    {
        ItemCount = 0;
    }

    void Display()
    {
        cout << "\nRestaurant Menu\n";
    }

    void PlaceOrder()
    {
        ifstream File("menu.txt");

        if (!File)
        {
            throw 'a';
        }

        string Line;
        string Name;
        int Price;
        int I = 0;

        cout << "\n. . . . . . . . . . . . . . . . . . . .\n";
        cout << "          RESTAURANT MENU\n";
        cout << ". . . . . . . . . . . . . . . . . . . .\n";

        while (getline(File, Line))
        {
            if (Line == "Gourmet Rolls:" ||
                Line == "Side Dish:" ||
                Line == "Drinks:" ||
                Line == "Dessert:")
            {
                cout << "\n" << Line << "\n";
            }
            else if (Line.length() > 0)
            {
                int LastSpace = Line.length() - 1;

                while (LastSpace >= 0 && Line[LastSpace] == ' ')
                {
                    LastSpace--;
                }

                int End = LastSpace;

                while (LastSpace >= 0 &&
                       Line[LastSpace] >= '0' &&
                       Line[LastSpace] <= '9')
                {
                    LastSpace--;
                }

                if (LastSpace < End && I < 50)
                {
                    Price = 0;

                    for (int J = LastSpace + 1; J <= End; J++)
                    {
                        Price = Price * 10 + (Line[J] - '0');
                    }

                    Name = Line.substr(0, LastSpace + 1);

                    while (Name.length() > 0 &&
                           Name[Name.length() - 1] == ' ')
                    {
                        Name.erase(Name.length() - 1, 1);
                    }

                    ItemNames[I] = Name;
                    ItemPrices[I] = Price;

                    cout << I + 1 << ". "
                         << ItemNames[I] << " - Rs. "
                         << ItemPrices[I] << "\n";

                    I++;
                }
            }
        }

        File.close();

        if (I == 0)
        {
            throw 'b';
        }

        ItemCount = I;

        int Quantities[50] = {0};
        int Choice;
        int Quantity;
        int OrderPlaced = 0;

        cout << "\n. . . . . . . . . . . . . . . . . . . .\n";
        cout << "             PLACE YOUR ORDER\n";
        cout << ". . . . . . . . . . . . . . . . . . . .\n";
        cout << "Enter the item number to order it.\n";
        cout << "Enter 0 when you finish ordering.\n";
        cout << "Enter -1 to cancel your order.\n";

        while (true)
        {
            cout << "\nEnter item number: ";
            cin >> Choice;

            if (Choice == -1)
            {
                cout << "\nOrder cancelled.\n";
                return;
            }

            if (Choice == 0)
            {
                break;
            }

            if (Choice < 1 || Choice > ItemCount)
            {
                cout << "Invalid item number. Please try again.\n";
                continue;
            }

            cout << "Selected: " << ItemNames[Choice - 1] << "\n";
            cout << "Enter quantity: ";
            cin >> Quantity;

            if (Quantity <= 0)
            {
                cout << "Quantity must be greater than zero.\n";
                continue;
            }

            Quantities[Choice - 1] += Quantity;
            OrderPlaced = 1;

            cout << ItemNames[Choice - 1]
                 << " added to your order.\n";
        }

        if (OrderPlaced == 0)
        {
            cout << "\nNo items ordered. No bill generated.\n";
            return;
        }

        double Total = 0;

        cout << "\n. . . . . . . . . . . . . . . . . . . .\n";
        cout << "                 CUSTOMER BILL\n";
        cout << ". . . . . . . . . . . . . . . . . . . .\n";

        cout << setiosflags(ios::left) << setw(27) << "Item"
             << setiosflags(ios::right) << setw(6) << "Qty"
             << setw(10) << "Price"
             << setw(10) << "Amount" << "\n";

        cout << ". . . . . . . . . . . . . . . . . . . .\n";

        for (int J = 0; J < ItemCount; J++)
        {
            if (Quantities[J] > 0)
            {
                double Amount = ItemPrices[J] * Quantities[J];
                Total += Amount;

                cout << setiosflags(ios::left) << setw(27) << ItemNames[J]
                     << setiosflags(ios::right) << setw(6) << Quantities[J]
                     << setw(10) << ItemPrices[J]
                     << setw(10) << fixed << setprecision(2)
                     << Amount << "\n";
            }
        }

        cout << ". . . . . . . . . . . . . . . . . . . .\n";
        cout << "Total Amount: Rs. "
             << fixed << setprecision(2) << Total << "\n";
        cout << ". . . . . . . . . . . . . . . . . . . .\n";
        cout << "       Thank you for your order!\n";
        cout << ". . . . . . . . . . . . . . . . . . . .\n";
    }
};

class Staff : public Restaurant
{
public:
    void Display()
    {
        cout << "\nStaff Portal\n";
    }
};

class Schedule : public Staff
{
public:
    void Display()
    {
        ifstream File("schedule.txt");

        if (!File)
        {
            throw 'c';
        }

        string Line;

        cout << "\n";

        while (getline(File, Line))
        {
            cout << Line << "\n";
        }

        File.close();
    }
};

class Pantry : public Staff
{
public:
    void Display()
    {
        ifstream File("pantry.txt");

        if (!File)
        {
            throw 'd';
        }

        string Line;

        cout << "\n";

        while (getline(File, Line))
        {
            cout << Line << "\n";
        }

        File.close();
    }
};

class Recipes : public Staff
{
public:
    void Display()
    {
        ifstream File("recipes.txt");

        if (!File)
        {
            throw 'e';
        }

        string Line;

        cout << "\n";

        while (getline(File, Line))
        {
            cout << Line << "\n";
        }

        File.close();
    }
};

void StaffPortal()
{
    int Choice;

    do
    {
        cout << "\nStaff Portal\n";
        cout << ". . . . . . . . . . . . . . . . . . . .\n";
        cout << "1. Staff Schedule\n";
        cout << "2. Pantry Management\n";
        cout << "3. Recipes\n";
        cout << "4. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> Choice;

        try
        {
            if (Choice < 1 || Choice > 4)
            {
                throw 1;
            }

            Restaurant *Portal;

            Schedule ScheduleObject;
            Pantry PantryObject;
            Recipes RecipesObject;

            switch (Choice)
            {
            case 1:
                Portal = &ScheduleObject;
                Portal->Display();
                break;

            case 2:
                Portal = &PantryObject;
                Portal->Display();
                break;

            case 3:
                Portal = &RecipesObject;
                Portal->Display();
                break;

            case 4:
                cout << "\nReturning to Main Menu...\n";
                break;
            }
        }
        catch (int I)
        {
            cout << "\nInvalid choice. Try again.\n";
        }
        catch (char C)
        {
            if (C == 'c')
            {
                cout << "\nError: Unable to open schedule.txt.\n";
            }
            else if (C == 'd')
            {
                cout << "\nError: Unable to open pantry.txt.\n";
            }
            else if (C == 'e')
            {
                cout << "\nError: Unable to open recipes.txt.\n";
            }
        }

    } while (Choice != 4);
}

int main()
{
    int Choice;

    Customer CustomerObject;
    Staff StaffObject;
    Restaurant *Portal;

    do
    {
        cout << "\nRestaurant Management System\n";
        cout << ". . . . . . . . . . . . . . . . . . . .\n";
        cout << "1. Customer\n";
        cout << "2. Staff\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> Choice;

        try
        {
            if (Choice < 1 || Choice > 3)
            {
                throw 1;
            }

            switch (Choice)
            {
            case 1:
                Portal = &CustomerObject;
                Portal->Display();
                CustomerObject.PlaceOrder();
                break;

            case 2:
                Portal = &StaffObject;
                Portal->Display();
                StaffPortal();
                break;

            case 3:
                cout << "\nThank you for visiting!\n";
                break;
            }
        }
        catch (int I)
        {
            cout << "\nInvalid choice. Try again.\n";
        }
        catch (char C)
        {
            if (C == 'a')
            {
                cout << "\nError: Unable to open menu.txt.\n";
            }
            else if (C == 'b')
            {
                cout << "\nError: No menu items found in menu.txt.\n";
            }
        }

    } while (Choice != 3);

    return 0;
}
