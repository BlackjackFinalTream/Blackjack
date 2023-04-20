#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <string>

using namespace std;

// Variables need to have the card function work
int card = 0, playertotal = 0, acecheck = 0, queencheck = 0, kingcheck = 0, jokercheck = 0, amount, playeramount1, playeramount2, playeramount3, bettingAmount, number_of_players, 
player1total, player2total, player3total;
enum Cards { Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Joker = 10, Queen = 10, King = 10 };
char answer, choice;
string player1, player2, player3, playername;
// Function Definition card_choose will display a card from Ace to King
void card_choose();
// Draws two cards and checks for early blackjack
void twocards();
// Name and amount
void pl_name_amount();
// Ask player amount for bet
void player1bet();
void player2bet();
void player3bet();
// Get player names and amount
void start();
// check player win or lose
void playerworl();
//Hit function for each player
void hitplayer1();
void hitplayer2();
void hitplayer3();
int main()
{
	srand((unsigned int)time(0));
	start();

	return 0;
}
void hitplayer3() {
	while (player3total <= 21) {
		cout << "Do you want to Hit? ";
		cin >> choice;
		cout << endl;
		if (choice == 'H' || choice == 'h') {
			card = rand() % 13 + 1;
			card_choose();
			player3total = playertotal;
			cout << "Player 1 Total: " << player3total << endl;
		}
		else {
			cout << "You choose to stay." << endl;
			break;
		}
		if (player3total == 21) {
			cout << "Blackjack You Win.";
			break;
		}
		if (player3total > 21) {
			cout << "You Lose. \n";
			break;
		}
	}
}
void hitplayer2() {
	while (player2total <= 21) {
		cout << "Do you want to Hit? ";
		cin >> choice;
		cout << endl;
		if (choice == 'H' || choice == 'h') {
			card = rand() % 13 + 1;
			card_choose();
			player2total = playertotal;
			cout << "Player 1 Total: " << player2total << endl;
		}
		else {
			cout << "You choose to stay." << endl;
			break;
		}
		if (player2total == 21) {
			cout << "Blackjack You Win.";
			break;
		}
		if (player2total > 21) {
			cout << "You Lose. \n";
			break;
		}
	}
}
void hitplayer1() {
	while (player1total <= 21) {
		cout << "Do you want to Hit? ";
		cin >> choice;
		cout << endl;
		if (choice == 'H' || choice == 'h') {
			card = rand() % 13 + 1;
			card_choose();
			player1total = playertotal;
			cout << "Player 1 Total: " << player1total << endl;
		}
		else {
			cout << "You choose to stay." << endl;
			break;
		}
		if (player1total == 21) {
			cout << "Blackjack You Win.";
			break;
		}
		if (player1total > 21) {
			cout << "You Lose. \n";
			break;
		}
	}
}
void getplbet() {
	switch (number_of_players) {
	case 3: {
		player1bet();
		player2bet();
		player3bet();
		break;
	}
	case 2: {
		player1bet();
		player2bet();
		break;
	}
	case 1: {
		player1bet();
		break;
	}
	}
}
void start() {
	cout << "How many players(max 3): ";
	cin >> number_of_players;
	while (number_of_players > 3) {
		cout << endl << "Enter the more players than allowed. Please re-enter amount of players: ";
		cin >> number_of_players;
	}
	switch (number_of_players) {
	case 1: {
		// Get player1 name and amount
		pl_name_amount();
		player1 = playername;
		playeramount1 = amount;
		cout << "Player 1: " << player1 << " $" << playeramount1 << endl;
		break;
	}
	case 2: {
		// Get player1 name and amount
		pl_name_amount();
		player1 = playername;
		playeramount1 = amount;
		// Get player2 name and amount
		pl_name_amount();
		player2 = playername;
		playeramount2 = amount;
		cout << "Player 1: " << player1 << " $" << playeramount1 << endl;
		cout << "Player 2: " << player2 << " $" << playeramount2 << endl;
		break;
	}
	case 3: {
		// Get player1 name and amount
		pl_name_amount();
		player1 = playername;
		playeramount1 = amount;
		// Get player2 name and amount
		pl_name_amount();
		player2 = playername;
		playeramount2 = amount;
		// Get player3 name and amount
		pl_name_amount();
		player3 = playername;
		playeramount3 = amount;
		cout << "Player 1: " << player1 << " $" << playeramount1 << endl;
		cout << "Player 2: " << player2 << " $" << playeramount2 << endl;
		cout << "Player 3: " << player3 << " $" << playeramount3 << endl;
		break;
	}
	}
}
void player1bet() {
	do
	{
		cout << "\n\nYour current balance is: $" << playeramount1 << "\n";
		do
		{
			cout << player1 << ", enter money to bet : $";
			cin >> bettingAmount;
			if (bettingAmount > playeramount1)
				cout << "Your betting amount is more than your current balance\n"
				<< "\nRe-enter data\n ";
		} while (bettingAmount > playeramount1);


		if (player1total == 21)
		{
			cout << "\n\n You won! " << bettingAmount; //* idk how much
			playeramount1 = playeramount1 + bettingAmount; //*idk how much;
		}
		else
		{
			cout << "You lost $ " << bettingAmount << "\n";
			playeramount1 = playeramount1 - bettingAmount;
		}

		cout << "\n" << player1 << ", You have $ " << playeramount1 << "\n";
		if (playeramount1 == 0)
		{
			cout << "You have no money to play ";
			break;
		}
		cout << "\n\nDo you want to play again (y/n)? ";
		cin >> choice;

	} while (choice == 'Y' || choice == 'y');
	cout << "\n" << player1 << " your balance amount is $ " << playeramount1 << "\n\n";
}
void player3bet() {
	do
	{
		cout << "\n\nYour current balance is: $" << playeramount3 << "\n";
		do
		{
			cout << player3 << ", enter money to bet : $";
			cin >> bettingAmount;
			if (bettingAmount > playeramount3)
				cout << "Your betting amount is more than your current balance\n"
				<< "\nRe-enter data\n ";
		} while (bettingAmount > playeramount3);


		if (player3total == 21)
		{
			cout << "\n\n You won! " << bettingAmount; //* idk how much
			playeramount3 = playeramount3 + bettingAmount; //*idk how much;
		}
		else
		{
			cout << "You lost $ " << bettingAmount << "\n";
			playeramount3 = playeramount3 - bettingAmount;
		}

		cout << "\n" << player3 << ", You have $ " << playeramount3 << "\n";
		if (playeramount3 == 0)
		{
			cout << "You have no money to play ";
			break;
		}
		cout << "\n\nDo you want to play again (y/n)? ";
		cin >> choice;

	} while (choice == 'Y' || choice == 'y');
	cout << "\n" << player3 << " your balance amount is $ " << playeramount3 << "\n\n";
}
void player2bet() {
	do
	{
		cout << "\n\nYour current balance is: $" << playeramount2 << "\n";
		do
		{
			cout << player2 << ", enter money to bet : $";
			cin >> bettingAmount;
			if (bettingAmount > playeramount2)
				cout << "Your betting amount is more than your current balance\n"
				<< "\nRe-enter data\n ";
		} while (bettingAmount > playeramount2);


		if (player2total == 21)
		{
			cout << "\n\n You won! " << bettingAmount; //* idk how much
			playeramount2 = playeramount2 + bettingAmount; //*idk how much;
		}
		else
		{
			cout << "You lost $ " << bettingAmount << "\n";
			playeramount2 = playeramount2 - bettingAmount;
		}

		cout << "\n" << player2 << ", You have $ " << playeramount2 << "\n";
		if (playeramount2 == 0)
		{
			cout << "You have no money to play ";
			break;
		}
		cout << "\n\nDo you want to play again (y/n)? ";
		cin >> choice;

	} while (choice == 'Y' || choice == 'y');
	cout << "\n" << player2 << " your balance amount is $ " << playeramount2 << "\n\n";
}
void twocards() {
	acecheck = 0;
	queencheck = 0;
	kingcheck = 0;
	jokercheck = 0;
	for (int i = 2; i--; i == 0) {
		card = rand() % 13 + 1;
		card_choose();
	}
	if (acecheck == 1 && kingcheck == 1) {
		playertotal = 21;
		cout << "Blackjack. You Win";
	}
	if (acecheck == 1 && queencheck == 1) {
		playertotal = 21;
		cout << "Blackjack. You Win";
	}
	if (acecheck == 1 && jokercheck == 1) {
		playertotal = 21;
		cout << "Blackjack. You Win";
	}
	cout << endl << playertotal << ": Player's Total\n";
}
void pl_name_amount() {
	cout << "\n\nEnter Your Name(minimun 36 characters): ";
	cin >> playername;
	cout << "\n\nA minimum of $50 is required to play and only up to $500 is allowed. \n"
		<< "Please enter the deposit amount to play : $";
	cin >> amount;
	cout << endl;
	while (amount < 50|| amount > 500)
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
	}
}
void card_choose() {
	switch (card) {
	case 13:
		cout << "///////////\n"
			<< "/K        /\n"
			<< "/         /\n"
			<< "/    K    /\n"
			<< "/         /\n"
			<< "/         /\n"
			<< "/        K/\n"
			<< "///////////\n";
		playertotal += King;
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
		playertotal += Queen;
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
		playertotal += Joker;
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
		playertotal += Ten;
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
		playertotal += Nine;
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
		playertotal += Eight;
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
		playertotal += Seven;
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
		playertotal += Six;
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
		playertotal += Five;
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
		playertotal += Four;
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
		playertotal += Three;
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
		playertotal += Two;
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
		playertotal += Ace;
		acecheck = 1;
		break;
	default:
		break;
	}

}