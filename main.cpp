
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void customerPortal()
{
    ifstream file("menu.txt");

    if (!file)
    {
        cout << "\nUnable to open menu.txt.\n";
        return;
    }

    string line;

    cout << "\nRestaurant Menu\n\n";
tf c
    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

void staffSchedule()
{
    ifstream file("schedule.txt");

    if (!file)
    {
        cout << "\nUnable to open schedule.txt.\n";
        return;
    }

    string line;

    cout << "\nStaff Schedule\n\n";

    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

void pantryManagement()
{
    ifstream file("pantry.txt");

    if (!file)
    {
        cout << "\nUnable to open pantry.txt.\n";
        return;
    }

    string line;

    cout << "\nPantry Management\n\n";

    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

void recipeManagement()
{
    ifstream file("recipes.txt");

    if (!file)
    {
        cout << "\nUnable to open recipes.txt.\n";
        return;
    }

    string line;

    cout << "\nRecipes\n\n";

    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

void staffPortal()
{
    int choice;

    do
    {
        cout << "\nStaff Portal\n\n";
        cout << "1. Staff Schedule\n";
        cout << "2. Pantry Management\n";
        cout << "3. Recipes\n";
        cout << "4. Back to Main Menu\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                staffSchedule();
                break;

            case 2:
                pantryManagement();
                break;

            case 3:
                recipeManagement();
                break;

            case 4:
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 4);
}

int main()
{
    int choice;

    do
    {
        cout << "\nRestaurant Management System\n\n";
        cout << "1. Customer\n";
        cout << "2. Staff\n";
        cout << "3. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                customerPortal();
                break;

            case 2:
                staffPortal();
                break;

            case 3:
                cout << "\nExiting Restaurant Management System.\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}
