#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int amount, bettingAmount;
    char choice, playername[36];

    cout << "\n\nEnter Your Name : ";
    cin >> playername;
    cout << "\n\nA minimum of $50 is required to play and only up to $500 is allowed. \n"
        << "Please enter the deposit amount to play : $";
    cin >> amount;
    while (amount < 50)
    {
        if (amount < 50)
        {
            cout << "Please deposit a minimum of $50\n";
            cout << "Please re-enter the deposit amount to play : $";
            cin >> amount;
        }

        if (amount >500)
        {
            cout << "Only a maximum of $500 is allowed. \n";
            cout << "Please re-enter the deposit amount to play : $";
            cin >> amount;
        }

        else
        {
            do
            {
                cout << "\n\nYour current balance is: $" << amount << "\n";

                do
                {
                    cout << playername << ", enter money to bet : $";
                    cin >> bettingAmount;
                    if (bettingAmount > amount)
                        cout << "Your betting amount is more than your current balance\n"
                        << "\nRe-enter data\n ";
                } while (bettingAmount > amount);


                if (playertotal = 21)
                {
                    cout << "\n\n You won! " << bettingAmount; //* idk how much
                    amount = amount + bettingAmount; //*idk how much;
                }
                else
                {
                    cout << "You lost $ " << bettingAmount << "\n";
                    amount = amount - bettingAmount;
                }

                cout << "\n" << playername << ", You have $ " << amount << "\n";
                if (amount == 0)
                {
                    cout << "You have no money to play ";
                    break;
                }
                cout << "\n\nDo you want to play again (y/n)? ";
                cin >> choice;

            } while (choice == 'Y' || choice == 'y');
        }
        cout << "\n\n\n";
        cout << "\n\nThanks for playing game. Your balance amount is $ " << amount << "\n\n";
    }
    return 0;
}
