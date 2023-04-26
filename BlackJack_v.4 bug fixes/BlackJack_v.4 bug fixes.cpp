#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <string>
#include <cmath>
using namespace std;

// Variables need to have the card function work
int card = 0, playertotal = 0, acecheck = 0, queencheck = 0, kingcheck = 0, jokercheck = 0, amount, playeramount1, playeramount2, playeramount3, bettingAmount, number_of_players,
player1total, player2total, player3total, player1bamount, player2bamount, player3bamount, houseTotal, houseGive, playerzero = 0;
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
// Each player round
void player1play();
void player2play();
void player3play();
//Hit function for each player
void hitplayer1();
void hitplayer2();
void hitplayer3();
// Shows house Card to go againest for one player mode
void houseCard();

// The Game
int main()
{
	srand((unsigned int)time(0));
	char ans, anstwo;
	cout << "                   Welcome to Blackjack\n"
		<< "This Blackjack has singleplayer or play with up to 3 other player.\n"
		<< "The singleplayer mode has you play againest the House which their \ncards are shown at the end.\n\n"
		<< "The play up to 3 player mode will have each player draw and hit\nat their own turn then after it will move to the next players turn.\n\n";
	do {
		cout << "Do you want to play? y/n \n";
		cin >> ans;
		if (ans == 'y' || ans == 'Y') {
			start();
		}
		else {
			break;
		}
		do
		{
			switch (number_of_players) {
			case 1: {
				player1play();
				playertotal = 0;
				houseTotal = 0;
				houseCard();
				cout << "\n" << player1 << " has " << player1total << " and bet $" << player1bamount << endl << endl;
				if (player1total == 21) {
					playeramount1 += player1bamount;
					cout << player1 << "had blackjack and won $" << player1bamount << " and now has $" << playeramount1 << endl;
					break;
				}
				if (player1total > 21) {
					playeramount1 -= player1bamount;
					cout << player1 << " lose $" << player1bamount << " and now has $" << playeramount1 << endl;
				}
				else
				{
					if (houseTotal < player1total || houseTotal > 21) {
						playeramount1 += player1bamount;
						cout << player1 << " won $" << player1bamount << " and now has $" << playeramount1 << endl;
					}
					else
					{
						if (houseTotal <= 21 && houseTotal > player1total)
						{
							playeramount1 -= player1bamount;
							cout << player1 << " lose $" << player1bamount << " and now has $" << playeramount1 << endl;
						}
					}
				}
				if (houseTotal == 21 && player1total == 21) {
					houseGive = round(player1bamount / 2);
					playeramount1 += houseGive;
					cout << player1 << " got half of $" << player1bamount << " and now has $" << playeramount1 << endl;
				}
				if (houseTotal == player1total) {
					houseGive = round(playeramount1 / 2);
					playeramount1 += houseGive; 
					cout << player1 << " got half of $" << player1bamount << " and now has $" << playeramount1 << endl;
				}
				cout << "House had " << houseTotal << endl;
				break;
			}
			case 2: {
				player1play();
				player2play();
				cout << "\n" << player1 << " has " << player1total << " and bet $" << player1bamount << endl;
				cout << "\n" << player2 << " has " << player2total << " and bet $" << player2bamount << endl << endl;
				if (player1total == 21) {
					playeramount1 += player1bamount;
					cout << player1 << "had blackjack and won $" << player1bamount << " and now has $" << playeramount1 << endl;
					break;
				}
				if (player1total > 21) {
					playeramount1 -= player1bamount;
					cout << player1 << " lose $" << player1bamount << " and now has $" << playeramount1 << endl;
				}
				else
				{
					if (player2total < player1total || player2total > 21) {
						playeramount1 += player1bamount;
						cout << player1 << " won $" << player1bamount << " and now has $" << playeramount1 << endl;
					}
					else
					{
						if (player2total <= 21 && player2total > player1total)
						{
							playeramount1 -= player1bamount;
							cout << player1 << " lose $" << player1bamount << " and now has $" << playeramount1 << endl;
						}
					}
				}
				if (player2total == 21) {
					playeramount2 += player2bamount;
					cout << player2 << "had blackjack and won $" << player2bamount << " and now has $" << playeramount2 << endl;
					break;
				}
				if (player2total > 21) {
					playeramount2 -= player2bamount;
					cout << player2 << " lose $" << player2bamount << " ans now has $" << playeramount2 << endl;
				}
				else
				{
					if (player1total < player2total || player1total > 21) {
						playeramount2 += player2bamount;
						cout << player2 << " won $" << player2bamount << " and now has $" << playeramount2 << endl;
					}
					else
					{
						if (player1total <= 21 && player1total > player2total)
						{
							playeramount2 -= player2bamount;
							cout << player2 << " lose $" << player2bamount << " and now has $" << playeramount2 << endl;
						}
					}
				}
				break;
			}
			case 3: {
				player1play();
				player2play();
				player3play();
				cout << "\n" << player1 << " has " << player1total << " and bet $" << player1bamount << endl;
				cout << "\n" << player2 << " has " << player2total << " and bet $" << player2bamount << endl;
				cout << "\n" << player3 << " has " << player3total << " and bet $" << player3bamount << endl << endl;
				if (player1total == 21) {
					playeramount1 += player1bamount;
					cout << player1 << "had blackjack and won $" << player1bamount << " and now has $" << playeramount1 << endl;
					break;
				}
				if (player1total > 21) {
					playeramount1 -= player1bamount;
					cout << player1 << " lose $" << player1bamount << " and now has $" << playeramount1 << endl;
				}
				else
				{
					if ((player2total < player1total || player2total > 21) && (player3total < player1total || player3total > 21)) {
						playeramount1 += player1bamount;
						cout << player1 << " won $" << player1bamount << " and now has $" << playeramount1 << endl;
					}
					else
					{
						if ((player2total <= 21 && player2total > player1total) && (player3total <= 21 && player3total > player1total))
						{
							playeramount1 -= player1bamount;
							cout << player1 << " lose $" << player1bamount << " and now has $" << playeramount1 << endl;
						}
						else
						{
							if (player2total < player1total || player3total < player1total) {
								playeramount1 += player1bamount;
								cout << player1 << " won $" << player1bamount << " and now has $" << playeramount1 << endl;
							}
						}

					}
				}
				if (player2total == 21) {
					playeramount2 += player2bamount;
					cout << player2 << "had blackjack and won $" << player2bamount << " and now has $" << playeramount2 << endl;
					break;
				}
				if (player2total > 21) {
					playeramount2 -= player2bamount;
					cout << player2 << " lose $" << player2bamount << " ans now has $" << playeramount2 << endl;
				}
				else
				{
					if ((player1total < player2total || player1total > 21) && (player3total < player2total || player3total > 21)) {
						playeramount2 += player2bamount;
						cout << player2 << " won $" << player2bamount << " and now has $" << playeramount2 << endl;
					}
					else
					{
						if ((player1total <= 21 && player1total > player2total) && (player3total <= 21 && player3total > player2total))
						{
							playeramount2 -= player2bamount;
							cout << player2 << " lose $" << player2bamount << " and now has $" << playeramount2 << endl;
						}
						else
						{
							if (player1total < player2total || player3total < player2total) {
								playeramount2 += player2bamount;
								cout << player2 << " won $" << player2bamount << " and now has $" << playeramount2 << endl;
							}
						}
					}
				}
				if (player3total == 21) {
					playeramount3 += player3bamount;
					cout << player3 << "had blackjack and won $" << player3bamount << " and now has $" << playeramount3 << endl;
					break;
				}
				if (player3total > 21) {
					playeramount3 -= player3bamount;
					cout << player3 << " lose $" << player3bamount << " ans now has $" << playeramount3 << endl;
				}
				else
				{
					if ((player1total < player3total || player1total > 21) && (player2total < player3total || player1total > 21)) {
						playeramount3 += player3bamount;
						cout << player3 << " won $" << player3bamount << " and now has $" << playeramount3 << endl;
					}
					else
					{
						if ((player1total <= 21 && player1total > player3total) && (player2total <= 21 && player2total > player3total))
						{
							playeramount3 -= player3bamount;
							cout << player3 << " lose $" << player3bamount << " and now has $" << playeramount3 << endl;
						}
						else
						{
							if (player1total < player3total || player2total < player3total) {
								playeramount3 += player3bamount;
								cout << player3 << " won $" << player3bamount << " and now has $" << playeramount3 << endl;
							}
						}
					}
				}
				break;
			}
			}
			switch (number_of_players)
			{
			case 1: {
				if (playeramount1 == 0) {
					playerzero = 1;
				}
				break;
			}
			case 2: {
				if (playeramount2 == 0 || playeramount1 == 0) {
					playerzero = 1;
				}
				break;
			}
			case 3: {
				if ((playeramount1 == 0 || playeramount2 == 0) || playeramount3 == 0) {
					playerzero = 1;
				}
				break;
			}
			default:
				break;
			}
			if (playerzero == 1) {
				break;
			}
			cout << "Do want to play another round? y/n\n";
			cin >> anstwo;
			if (anstwo == 'n' || anstwo == 'N') {
				break;
			}
		} while (true);
		if (playerzero == 1) {
			break;
		}
		if (anstwo == 'n' || anstwo == 'N') {
			break;
		}
	} while (true);
	cout << "Thanks for playing";
	return 0;
}
// All the Funtions needed to make the game run
void houseCard() {
	cout << endl;
	twocards();
	houseTotal += playertotal;
	cout << "House card total " << houseTotal << endl;
	while (houseTotal < 18)
	{
		playertotal = 0;
		card_choose();
		houseTotal += playertotal;
		cout << "House card total " << houseTotal << endl;
	}
	if (houseTotal == 21) {
		cout << "House has blackjack\n";
	}
}
void player1play() {
	player1bet();
	player1bamount = bettingAmount;
	bettingAmount = 0;
	cout << "\n" << player1 << ", You have $ " << playeramount1 << "\n";
	playertotal = 0;
	twocards();
	player1total = playertotal;
	cout << endl << player1total << ": " << player1 << " Total\n";
	if (player1total == 21) {
		return;
	}
	hitplayer1();
	if (playeramount1 == 0)
	{
		cout << "You have no money to play ";
	}
}
void player2play() {
	player2bet();
	player2bamount = bettingAmount;
	bettingAmount = 0;
	cout << "\n" << player2 << ", You have $ " << playeramount2 << "\n";
	playertotal = 0;
	twocards();
	player2total = playertotal;
	cout << endl << player2total << ": " << player2 << " Total\n";
	if (player2total == 21) {
		return;
	}
	hitplayer2();
	if (playeramount2 == 0)
	{
		cout << "You have no money to play ";
	}
}
void player3play() {
	player3bet();
	player3bamount = bettingAmount;
	cout << "\n" << player3 << ", You have $ " << playeramount3 << "\n";
	playertotal = 0;
	twocards();
	player3total = playertotal;
	cout << endl << player3total << ": " << player3 << " Total\n";
	if (player3total == 21) {
		return;
	}
	hitplayer3();
	if (playeramount3 == 0)
	{
		cout << "You have no money to play ";
	}
}
void hitplayer3() {
	while (player3total <= 21) {
		cout << "Do you want to Hit? h for Hit/s for Stay";
		cin >> choice;
		cout << endl;
		if (choice == 'H' || choice == 'h') {
			card = rand() % 13 + 1;
			card_choose();
			player3total = playertotal;
			cout << player3 << " Total: " << player3total << endl;
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
		cout << "Do you want to Hit? h for Hit/s for Stay";
		cin >> choice;
		cout << endl;
		if (choice == 'H' || choice == 'h') {
			card = rand() % 13 + 1;
			card_choose();
			player2total = playertotal;
			cout << player2 << " Total: " << player2total << endl;
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
		cout << "Do you want to Hit? h for Hit/s for Stay";
		cin >> choice;
		cout << endl;
		if (choice == 'H' || choice == 'h') {
			card = rand() % 13 + 1;
			card_choose();
			player1total = playertotal;
			cout << player1 << " Total: " << player1total << endl;
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

	cout << "\n\nYour current balance is: $" << playeramount1 << "\n";
	do
	{
		cout << player1 << ", enter money to bet : $";
		cin >> bettingAmount;
		if (bettingAmount > playeramount1) {
			cout << "Your betting amount is more than your current balance\n"
				<< "\nRe-enter data\n ";
			bettingAmount = 0;
		}
	} while (bettingAmount > playeramount1);
}
void player3bet() {
	cout << "\n\nYour current balance is: $" << playeramount3 << "\n";
	do
	{
		cout << player3 << ", enter money to bet : $";
		cin >> bettingAmount;
		if (bettingAmount > playeramount3)
			cout << "Your betting amount is more than your current balance\n"
			<< "\nRe-enter data\n ";
	} while (bettingAmount > playeramount3);
}
void player2bet() {
	cout << "\n\nYour current balance is: $" << playeramount2 << "\n";
	do
	{
		cout << player2 << ", enter money to bet : $";
		cin >> bettingAmount;
		if (bettingAmount > playeramount2)
			cout << "Your betting amount is more than your current balance\n"
			<< "\nRe-enter data\n ";
	} while (bettingAmount > playeramount2);
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
}
void pl_name_amount() {
	cout << "\n\nEnter Your Name(minimun 36 characters): ";
	cin >> playername;
	cout << "\n\nA minimum of $50 is required to play and only up to $500 is allowed. \n"
		<< "Please enter the deposit amount to play : $";
	cin >> amount;
	cout << endl;
	while (amount < 50 || amount > 500)
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
