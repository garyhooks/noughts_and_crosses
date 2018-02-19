/**************************************************************************
#
#	Project      : Noughts and Crosses Game
#	Published on : Monday 19th February 2018
#	Author: Gary Hooks
#	Email: garyhooks@gmail.com
#	Licence: GPL
#
**************************************************************************/

#include <iostream>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <Windows.h>
using namespace std;

char numbers[10] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
string error = "";

void board() {

	system("cls");

	cout << "\n\n\t     Noughts and Crosses \n\n " << endl;

	cout << "\t\t | \t | " << endl;
	cout << "\t     " << numbers[0] << "   |   " << numbers[1] << "   |   " << numbers[2] << endl;

	cout << "\t   ______|_______|______" << endl;

	cout << "\t\t | \t | " << endl;
	cout << "\t     " << numbers[3] << "   |   " << numbers[4] << "   |   " << numbers[5] << endl;
	//cout << "\t\t | \t | " << endl;

	cout << "\t   ______|_______|______" << endl;

	cout << "\t\t | \t | " << endl;
	cout << "\t     " << numbers[6] << "   |   " << numbers[7] << "   |   " << numbers[8] << endl;
	cout << "\t\t | \t | " << endl;

	cout << "\n" << endl;
	
	if (error != "") {
		cout << error << "\n\n" << endl;
		error = "";
	}
	else {
		cout << "\n\n" << endl;
	}
	
}

int check_win(char numbers[]) {


	/****************** Start with the horizontal checks **************/
	if ( (numbers[0] == 'X') && (numbers[1] == 'X') && (numbers[2] == 'X') ) {

		return 1;

	} else if ((numbers[0] == 'O') && (numbers[1] == 'O') && (numbers[2] == 'O'))  {

		return 1;

	} else if ((numbers[3] == 'X') && (numbers[4] == 'X') && (numbers[5] == 'X')) {

		return 1;

	}
	else if ((numbers[3] == 'O') && (numbers[4] == 'O') && (numbers[5] == 'O')) {

		return 1;
	}
	else if ((numbers[6] == 'X') && (numbers[7] == 'X') && (numbers[8] == 'X')) {
		
		return 1;
	}
	else if ((numbers[6] == 'O') && (numbers[7] == 'O') && (numbers[8] == 'O')) {
		return 1;


	/***************** now the verticals *******************/
	} else if ((numbers[0] == 'X') && (numbers[3] == 'X') && (numbers[6] == 'X')) {
		return 1;
	}
	else if ((numbers[0] == 'O') && (numbers[3] == 'O') && (numbers[6] == 'O')) {
		return 1;
	}
	else if ((numbers[1] == 'X') && (numbers[4] == 'X') && (numbers[7] == 'X')) {
		return 1;
	}
	else if ((numbers[1] == 'O') && (numbers[4] == 'O') && (numbers[7] == 'O')) {
		return 1;
	}
	else if ((numbers[2] == 'X') && (numbers[5] == 'X') && (numbers[8] == 'X')) {
		return 1;
	}
	else if ((numbers[2] == 'O') && (numbers[5] == 'O') && (numbers[8] == 'O')) {
		return 1;
	}

	/******************* Now the diagonals ****************/
	else if ((numbers[0] == 'X') && (numbers[4] == 'X') && (numbers[8] == 'X')) {
		return 1;


	}
		else if ((numbers[0] == 'O') && (numbers[4] == 'O') && (numbers[8] == 'O')) {
			return 1;
		}
		else {

			return 0;

		}
}

int choice_converter(char choice) {

	int num_choice;

	switch (choice) {

		case '1':
			num_choice = 0;
			break;
		case '2':
			num_choice = 1;
			break;
		case '3':
			num_choice = 2;
			break;
		case '4':
			num_choice = 3;
			break;
		case '5':
			num_choice = 4;
			break;
		case '6':
			num_choice = 5;
			break;
		case '7':
			num_choice = 6;
			break;
		case '8':
			num_choice = 7;
			break;
		case '9':
			num_choice = 8;
			break;
		default:
			return -1;
			break;
	}

	return num_choice;
}

int choice_check(char choice, int player) {

	if (isdigit(choice)) {

		if ((choice >= '0') && (choice <= '9')) {

			/**** the Choice is valid .... but has this square already been taken??? */
			
			int num_choice = choice_converter(choice);

			if ((numbers[num_choice] == 'X') || (numbers[num_choice] == 'O')) {

				error = "[-] ERROR: This square has already been taken... try again";

				return 1;

			}



			return 0;

		}
		else
		{
			error = "[-] ERROR: Entries must be between 1-9";
			return 1;

		}

	}
	else
	{
		error = "[-] ERROR: Entries must be between 1-9 and can not be characters";
		return 1;
	}


}
int main() {


	char choice;
	int num_choice;
	int error = 0;

	// player one is X
	// player two is O
	int player(1);
	bool over(0);



	while (over == 0) {
	
		error = 0;

		board();

		cout << "Player " << player << " >> Enter your choice: ";
		cin >> choice;


		error = choice_check(choice, player);

		if (error == 1) {

			cout << "\n\n\nERROR!!!!!!!!!!!!!!!!!!! \n\n\n\n";
		}
		else {

			num_choice = choice_converter(choice);

			if (player == 1) {
				numbers[num_choice] = 'X';
				player = 2;
			}
			else {
				numbers[num_choice] = 'O';
				player = 1;
			}

			int result = check_win(numbers);
			if (result == 1) {
				over = 1;

				char again;
				cout << "\n\nGame Over!  Would you like to play again? [Y/n] : ";
				cin >> again;

				if (again == 'Y') {
					// Reset variables for a new game
					over = 0;
					numbers[0] = '1';
					numbers[1] = '2';
					numbers[2] = '3';
					numbers[3] = '4';
					numbers[4] = '5';
					numbers[5] = '6';
					numbers[6] = '7';
					numbers[7] = '8';
					numbers[8] = '9';
					player = 1;
					board();
				}

			}
			else {
				board();
			}


		}


	}
	
	return  0;

}
