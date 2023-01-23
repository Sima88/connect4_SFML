#pragma once

bool four_same_chips(char a, char b, char c, char d);
void mouse_click(char board[6][7], char column[7], int& coordinate_on_board, char& current, int& number_of_chips_in_the_column1,
	int& number_of_chips_in_the_column2,
	int& number_of_chips_in_the_column3,
	int& number_of_chips_in_the_column4,
	int& number_of_chips_in_the_column5,
	int& number_of_chips_in_the_column6,
	int& number_of_chips_in_the_column7);
bool check_row(char board[6][7]);
bool check_diagonal(char board[6][7]);
bool check_reverse_diagonal(char board[6][7]);
bool check_column(char board[6][7]);
