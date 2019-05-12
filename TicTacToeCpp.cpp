
#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;

char square[] = { 'o','1','2','3','4','5','6','7','8','9' };

int checkstatus();
void board();
void marking(char *v, int choice, char mark);

int main()
{
	int player = 1;
	int status = -1;
	char mark;
	int choice;

	while(status == -1) {
		board();
		player = (player % 2) ? 1 : 2;

		cout << "Player " << player << ", enter a number:  ";
		cin >> choice;

		mark = (player == 1) ? 'X' : 'O';

		if (choice == 1 && square[1] == '1')
			marking(square, choice, mark);
			//square[1] = mark;
		else if (choice == 2 && square[2] == '2')
			marking(square, choice, mark);
			//square[2] = mark;
		else if (choice == 3 && square[3] == '3')
			marking(square, choice, mark);
			//square[3] = mark;
		else if (choice == 4 && square[4] == '4')
			marking(square, choice, mark);
			//square[4] = mark;
		else if (choice == 5 && square[5] == '5')
			marking(square, choice, mark);
			//square[5] = mark;
		else if (choice == 6 && square[6] == '6')
			marking(square, choice, mark);
			//square[6] = mark;
		else if (choice == 7 && square[7] == '7')
			marking(square, choice, mark);
			//square[7] = mark;
		else if (choice == 8 && square[8] == '8')
			marking(square, choice, mark);
			//square[8] = mark;
		else if (choice == 9 && square[9] == '9')
			marking(square, choice, mark);
			//square[9] = mark;
		else
		{
			cout << "Invalid move ";
			//do a fast reset
			player--;
			cin.ignore();
			cin.get();
		}
		status = checkstatus();
		player++;
	}
	//finally
	board();
	if (status == 1)
		cout << "==>\aPlayer " << --player << " win ";
	else if (status == 0)
		cout << "==>\aGame draw";

	cin.ignore();
	cin.get();
	return 0;
}

// functions/arrays as parameter decays to pointer
// No benefits to passing basic type by pointer
void marking (char *v, int choice, char mark) {
	v[choice] = mark;
}

int checkstatus()
{
	if (square[1] == square[2] && square[2] == square[3])

		return 1;
	else if (square[4] == square[5] && square[5] == square[6])

		return 1;
	else if (square[7] == square[8] && square[8] == square[9])

		return 1;
	else if (square[1] == square[4] && square[4] == square[7])

		return 1;
	else if (square[2] == square[5] && square[5] == square[8])

		return 1;
	else if (square[3] == square[6] && square[6] == square[9])

		return 1;
	else if (square[1] == square[5] && square[5] == square[9])

		return 1;
	else if (square[3] == square[5] && square[5] == square[7])

		return 1;
	// draw 
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
		&& square[4] != '4' && square[5] != '5' && square[6] != '6'
		&& square[7] != '7' && square[8] != '8' && square[9] != '9')

		return 0;
	// game continues
	else
		return -1;
}

void board()
{
	system("cls");
	cout << "\n\n\tTic Tac Toe Game\n\n";

	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

	cout << "     |     |     " << endl << endl;
}
