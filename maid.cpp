#include<bits/stdc++.h>
using namespace std;
void dealCard(int hands[][26], int handsize[], int players){
	int deck[51] = { 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10, 11, 11, 11, 11, 12, 12, 12, 13, 13, 13 };
	for (int i = 0; i < 51; i++){
		int random = rand() % 51 + 1;
		if (random != i){ //make sure not to swap a number with itself
			swap(deck[i], deck[random]);
		}
	}
	for (int card = 0; card < (51 / players); card++){
		for (int player = 0; player < players; player++){
			for (int draw = 0; draw < 51; draw++){
				hands[player][card] = deck[draw]; //Distribute the cards in order, to each player
				handsize[player] = handsize[player] + 1; //Add a card to the hand
			}
		}
	}
}

void Turn(int hands[][26], int handsize[], int current_player, int previous_player){
			//takes a turn, either for the person at the keyboard or simulated by computer
			if (current_player == 0){ // Player taking from computer
				cout << "You have these cards in your hand:  " << endl;
				for (int t = 0; t < 51; t++)
					if (hands[0][t] == 1)
						cout << "Ace    ";
					else if (hands[0][t] == 2)
						cout << "Two   ";
					else if (hands[0][t] == 3)
						cout << "Three   ";
					else if (hands[0][t] == 4)
						cout << "Four   ";
					else if (hands[0][t] == 5)
						cout << "Five   ";
					else if (hands[0][t] == 6)
						cout << "Six   ";
					else if (hands[0][t] == 7)
						cout << "Seven   ";
					else if (hands[0][t] == 8)
						cout << "Eight   ";
					else if (hands[0][t] == 9)
						cout << "Nine   "; 
					else if (hands[0][t] == 10)
						cout << "Ten   ";
					else if (hands[0][t] == 11)
						cout << "Jack   ";
					else if (hands[0][t] == 12)
						cout << "Queen   ";
					else if (hands[0][t] == 13)
						cout << "King   ";
				

				int pickcard;
				cout << "You get to draw a card from a hand containing   " << handsize[previous_player] << endl;;
				cout << "Choose a number from one to   " << handsize[previous_player] << endl;
				cin >> pickcard;

				ReceiveCard(hands[current_player], handsize[current_player], hands[previous_player][pickcard]);
				RemoveCard(hands[previous_player], handsize[previous_player], pickcard);
			}
			else if (previous_player == 0){ //Simulate a computer taking from player, randomly choosing a card.
				int compcard;
				compcard = rand() % handsize[previous_player] + 1;
				cout << "A computer player took your  ";
				if (hands[0][compcard] == 1)
					cout << "Ace    ";
				else if (hands[0][compcard] == 2)
					cout << "Two   ";
				else if (hands[0][compcard] == 3)
					cout << "Three   ";
				else if (hands[0][compcard] == 4)
					cout << "Four   ";
				else if (hands[0][compcard] == 5)
					cout << "Five   ";
				else if (hands[0][compcard] == 6)
					cout << "Six   ";
				else if (hands[0][compcard] == 7)
					cout << "Seven   ";
				else if (hands[0][compcard] == 8)
					cout << "Eight   ";
				else if (hands[0][compcard] == 9)
					cout << "Nine   ";
				else if (hands[0][compcard] == 10)
					cout << "Ten   ";
				else if (hands[0][compcard] == 11)
					cout << "Jack   ";
				else if (hands[0][compcard] == 12)
					cout << "Queen   ";
				else if (hands[0][compcard] == 13)
					cout << "King   ";
				ReceiveCardComputer(hands[current_player], handsize[current_player], hands[previous_player][compcard]);
				RemoveCardComputer(hands[previous_player], handsize[previous_player], compcard);
			}
			else{																		//Computer taking from computer, randomly choosing a card
				int compcard2;
				compcard2 = rand() % handsize[previous_player] + 1;
				ReceiveCardComputer(hands[current_player], handsize[previous_player], hands[previous_player][compcard2]);
				RemoveCardComputer(hands[previous_player], handsize[previous_player], compcard2);
			
			
			
			}
		}
int main()
{

	char yesNo;
	do{
		int players;
		int hands[6][26];
		int handsize[6] = { 0 };
		cout << "How many players do you want to play? ";
		cin >> players;
		int turnorder[6];
		for (int counter = 0; counter < players; counter++){ //filling the turn order array depending on how many players there are, from one to the number of players.
		for (int counter1 = 1; counter1 <= players; counter1++){
			turnorder[counter] = counter1;
			}
		}
		dealCard(hands, handsize, players);



		bool GameOver = false;
		int counter3;
		for (int check = 0; check < players; check++){ //see how many players are left in the game
			if (turnorder[check] != 0)
				counter3++;
			if (counter3 = 1) //if there is only one player left, then the game is over
				GameOver = true;
		}
				
			
		if (GameOver = true){
			cout << "Game Over! Do you want to play again? (y\n)  ";
			cin >> yesNo;
		}
	} while (yesNo == 'y' || yesNo == 'Y');
			cout << "Thanks for playing!" << endl;
		}