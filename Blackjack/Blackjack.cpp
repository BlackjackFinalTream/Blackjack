#include <iostream>
#include <cmath>

using namespace std;
void cards();
char ans;
string game_run, playerans;
enum Card {AC = 1, TC, ThC, FC, FiC, SC, SeC, EC, NC, TeC, JC = 10, QC = 10, KC = 10};
int number_of_players, chipamount, bet, playertotal, kingcheck = 0, queencheck = 0, jokercheck = 0, acecheck = 0;
int s = 4;
int number_of_players;

int main(){
	cout << "Welcome to Blackjack!\n"
		<< "How many players will be playing?";
	cin >> number_of_players;
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