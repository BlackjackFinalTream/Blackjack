#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;
void cards();
void betting_placements();

char ans;
string game_run, playerans;
enum Card { AC = 1, TC, ThC, FC, FiC, SC, SeC, EC, NC, TeC, JC = 10, QC = 10, KC = 10 };
int number_of_players, chipamount, bet, 
	playertotal, kingcheck = 0, queencheck = 0, 
	jokercheck = 0, acecheck = 0;
int s = 4;

int main() {
	cout << "--------------------------------";
	cout << "\n\n      !!! Black Jack !!!\n\n";
	cout << "--------------------------------\n\n";
	cout << "Welcome to Black Jack!"
		<< "How many players will be playing?: ";
	cin >> number_of_players;
	// I'm thinking here we can have some MORE 
	//void functions to display on the terminal 
	// how many players were selected and such
	//then that way each player can input their
	// names or user names along with theit bet
	//placements and such and in each void function
	// do the whole game through each player so just
	//copy and paste the same thing but keep the variables
	// seperate like player1name, player2name, etc
	//and player1_money, player2_money, etc
	// and then with each void fucntions im assuming its
	//like a do while loop and such with various if 
	// and else statements which can also be copy pasted
	//just again with spereate variables.


	return 0;
}

void cards() {
	s = rand() % 13 + 1;
	switch (s) {
	case 13:
		cout << "///////////\n"
			<< "/K        /\n"
			<< "/         /\n"
			<< "/    K    /\n"
			<< "/         /\n"
			<< "/         /\n"
			<< "/        K/\n"
			<< "///////////\n";
		playertotal += KC;
		kingcheck = 1;
		break;
	case 12:
		cout << "///////////\n"
			<< "/Q        /\n"
			<< "/         /\n"
			<< "/    Q    /\n"
			<< "/         /\n"
			<< "/         /\n"
			<< "/        Q/\n"
			<< "///////////\n";
		playertotal += QC;
		queencheck = 1;
		break;
	case 11:
		cout << "///////////\n"
			<< "/J        /\n"
			<< "/         /\n"
			<< "/    J    /\n"
			<< "/         /\n"
			<< "/         /\n"
			<< "/        J/\n"
			<< "///////////\n";
		playertotal += JC;
		jokercheck = 1;
		break;
	case 10:
		cout << "///////////\n"
			<< "/10       /\n"
			<< "/         /\n"
			<< "/    10   /\n"
			<< "/         /\n"
			<< "/         /\n"
			<< "/       10/\n"
			<< "///////////\n";
		playertotal += TeC;
		break;
	case 9:
		cout << "///////////\n"
			<< "/9        /\n"
			<< "/         /\n"
			<< "/    9    /\n"
			<< "/         /\n"
			<< "/         /\n"
			<< "/        9/\n"
			<< "///////////\n";
		playertotal += NC;
		break;
	case 8:
		cout << "///////////\n"
			<< "/8        /\n"
			<< "/         /\n"
			<< "/    8    /\n"
			<< "/         /\n"
			<< "/         /\n"
			<< "/        8/\n"
			<< "///////////\n";
		playertotal += EC;
		break;
	case 7:
		cout << "///////////\n"
			<< "/7        /\n"
			<< "/         /\n"
			<< "/    7    /\n"
			<< "/         /\n"
			<< "/         /\n"
			<< "/        7/\n"
			<< "///////////\n";
		playertotal += SeC;
		break;
	case 6:
		cout << "///////////\n"
			<< "/6        /\n"
			<< "/         /\n"
			<< "/    6    /\n"
			<< "/         /\n"
			<< "/         /\n"
			<< "/        6/\n"
			<< "///////////\n";
		playertotal += SC;
		break;
	case 5:
		cout << "///////////\n"
			<< "/5        /\n"
			<< "/         /\n"
			<< "/    5    /\n"
			<< "/         /\n"
			<< "/         /\n"
			<< "/        5/\n"
			<< "///////////\n";
		playertotal += FiC;
		break;
	case 4:
		cout << "///////////\n"
			<< "/4        /\n"
			<< "/         /\n"
			<< "/    4    /\n"
			<< "/         /\n"
			<< "/         /\n"
			<< "/        4/\n"
			<< "///////////\n";
		playertotal += FC;
		break;
	case 3:
		cout << "///////////\n"
			<< "/3        /\n"
			<< "/         /\n"
			<< "/    3    /\n"
			<< "/         /\n"
			<< "/         /\n"
			<< "/        3/\n"
			<< "///////////\n";
		playertotal += ThC;
		break;
	case 2:
		cout << "///////////\n"
			<< "/2        /\n"
			<< "/         /\n"
			<< "/    2    /\n"
			<< "/         /\n"
			<< "/         /\n"
			<< "/        2/\n"
			<< "///////////\n";
		playertotal += TC;
		break;
	case 1:
		cout << "///////////\n"
			<< "/A        /\n"
			<< "/         /\n"
			<< "/    A    /\n"
			<< "/         /\n"
			<< "/         /\n"
			<< "/        A/\n"
			<< "///////////\n";
		playertotal += AC;
		acecheck = 1;
		break;
	default:
		break;
	}
}

void betting_placements();
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

			if (amount > 500)
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
