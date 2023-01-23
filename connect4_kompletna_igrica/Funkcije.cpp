#include <iostream>
#include<Window.hpp>
#include<Graphics.hpp>
#include "Header.h"





void mouse_click(char board[6][7], char column[7], int& coordinate_on_board, char& current, int& number_of_chips_in_the_column1,
	int& number_of_chips_in_the_column2,
	int& number_of_chips_in_the_column3,
	int& number_of_chips_in_the_column4,
	int& number_of_chips_in_the_column5,
	int& number_of_chips_in_the_column6,
	int& broj_cipova_u_stupcu7) {





	if (column[coordinate_on_board] == '1') {

		if (number_of_chips_in_the_column1 == 0)
			board[5][0] = current;

		if (number_of_chips_in_the_column1 == 1)
			board[4][0] = current;

		if (number_of_chips_in_the_column1 == 2)
			board[3][0] = current;

		if (number_of_chips_in_the_column1 == 3)
			board[2][0] = current;

		if (number_of_chips_in_the_column1 == 4)
			board[1][0] = current;

		if (number_of_chips_in_the_column1 == 5)
			board[0][0] = current;

		number_of_chips_in_the_column1++;

	}
	if (column[coordinate_on_board] == '2') {
		if (number_of_chips_in_the_column2 == 0)
			board[5][1] = current;

		if (number_of_chips_in_the_column2 == 1)
			board[4][1] = current;

		if (number_of_chips_in_the_column2 == 2)
			board[3][1] = current;

		if (number_of_chips_in_the_column2 == 3)
			board[2][1] = current;

		if (number_of_chips_in_the_column2 == 4)
			board[1][1] = current;

		if (number_of_chips_in_the_column2 == 5)
			board[0][1] = current;

		number_of_chips_in_the_column2++;

	}

	if (column[coordinate_on_board] == '3') {
		if (number_of_chips_in_the_column3 == 0)
			board[5][2] = current;

		if (number_of_chips_in_the_column3 == 1)
			board[4][2] = current;

		if (number_of_chips_in_the_column3 == 2)
			board[3][2] = current;

		if (number_of_chips_in_the_column3 == 3)
			board[2][2] = current;

		if (number_of_chips_in_the_column3 == 4)
			board[1][2] = current;

		if (number_of_chips_in_the_column3 == 5)
			board[0][2] = current;

		number_of_chips_in_the_column3++;


	}
	if (column[coordinate_on_board] == '4') {
		if (number_of_chips_in_the_column4 == 0)
			board[5][3] = current;

		if (number_of_chips_in_the_column4 == 1)
			board[4][3] = current;

		if (number_of_chips_in_the_column4 == 2)
			board[3][3] = current;

		if (number_of_chips_in_the_column4 == 3)
			board[2][3] = current;

		if (number_of_chips_in_the_column4 == 4)
			board[1][3] = current;

		if (number_of_chips_in_the_column4 == 5)
			board[0][3] = current;

		number_of_chips_in_the_column4++;

	}
	if (column[coordinate_on_board] == '5') {
		if (number_of_chips_in_the_column5 == 0)
			board[5][4] = current;

		if (number_of_chips_in_the_column5 == 1)
			board[4][4] = current;

		if (number_of_chips_in_the_column5 == 2)
			board[3][4] = current;

		if (number_of_chips_in_the_column5 == 3)
			board[2][4] = current;

		if (number_of_chips_in_the_column5 == 4)
			board[1][4] = current;

		if (number_of_chips_in_the_column5 == 5)
			board[0][4] = current;

		number_of_chips_in_the_column5++;

	}
	if (column[coordinate_on_board] == '6') {
		if (number_of_chips_in_the_column6 == 0)
			board[5][5] = current;

		if (number_of_chips_in_the_column6 == 1)
			board[4][5] = current;

		if (number_of_chips_in_the_column6 == 2)
			board[3][5] = current;

		if (number_of_chips_in_the_column6 == 3)
			board[2][5] = current;

		if (number_of_chips_in_the_column6 == 4)
			board[1][5] = current;

		if (number_of_chips_in_the_column6 == 5)
			board[0][5] = current;

		number_of_chips_in_the_column6++;

	}
	if (column[coordinate_on_board] == '7') {
		if (broj_cipova_u_stupcu7 == 0)
			board[5][6] = current;

		if (broj_cipova_u_stupcu7 == 1)
			board[4][6] = current;

		if (broj_cipova_u_stupcu7 == 2)
			board[3][6] = current;

		if (broj_cipova_u_stupcu7 == 3)
			board[2][6] = current;

		if (broj_cipova_u_stupcu7 == 4)
			board[1][6] = current;

		if (broj_cipova_u_stupcu7 == 5)
			board[0][6] = current;

		broj_cipova_u_stupcu7++;

	}
	if (current == 'R')
		current = 'Y';
	else
		current = 'R';

}

bool four_same_chips(char a, char b, char c, char d) {
	if (a == b && b == c && c == d) {
		return true;
	}

	return false;
}

bool check_row(char board[6][7]) {



	bool match_happened = false;


	for (int row_index = 0; row_index <= 5; row_index++) {

		for (int index = 0; index <= 3; index++)
		{

			if (four_same_chips(board[row_index][index], board[row_index][index + 1], board[row_index][index + 2], board[row_index][index + 3])

				&& board[row_index][index] != ' ')

				match_happened = true;



		}
	}




	return match_happened;


}
bool check_column(char board[6][7]) {



	bool match_happened = false;


	for (int column_index = 0; column_index <= 6; column_index++) {

		for (int index = 0; index <= 2; index++)
		{

			if (four_same_chips(board[index][column_index], board[index + 1][column_index], board[index + 2][column_index], board[index + 3][column_index])
				&& board[index][column_index] != ' ')

				match_happened = true;



		}
	}




	return match_happened;
}
bool check_diagonal(char board[6][7]) {



	bool match_happened = false;


	for (int j = 0; j <= 2; j++) {

		for (int i = 0; i <= 3; i++) {

			if (four_same_chips(board[0 + j][i + 0], board[1 + j][i + 1], board[2 + j][i + 2], board[3 + j][i + 3])
				&& (board[0 + j][0 + i] != ' ' || board[1 + j][1 + i] != ' ' || board[2 + j][2 + i] != ' ' || board[3 + j][3 + i] != ' '))

				match_happened = true;

		}

	}
	return match_happened;


}


bool check_reverse_diagonal(char board[6][7]) {

	for (int j = 0; j <= 2; j++) {
		for (int i = 0; i <= 3; i++) {
			if (four_same_chips(board[3 + j][0 + i], board[2 + j][1 + i], board[1 + j][2 + i], board[0 + j][3 + i])

				&& (board[3 + j][0 + i] != ' ' || board[2 + j][1 + i] != ' ' || board[1 + j][2 + i] != ' ' || board[0 + j][3 + i] != ' '))

				return true;
		}

	}
	return false;
}