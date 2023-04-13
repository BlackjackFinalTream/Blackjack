#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//Variables need to have the card function work
int card = 0, playertotal = 0, acecheck = 0, queencheck = 0, kingcheck = 0, jokercheck = 0;
enum Cards { Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Joker = 10, Queen = 10, King = 10 };
char answer;
//Function Definition card_choose will display a card from Ace to King
void card_choose();
// Draws two cards and checks for early blackjack
void twocards();
int main()
{
	srand((unsigned int)time(0));
	do {
		playertotal = 0;
		twocards();
		cout << "Do you want to more cards: ";
		cin >> answer;
	} while (answer != 'N' && answer != 'n');
	return 0;
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