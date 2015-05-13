#include <stdio.h>
#include <math.h>

char board[3][3]; 
int moveX = 0;

initialize() {
	int i;
	int j;
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
}	

void movePlayerX(int row, int col) {
	board[row][col] = 'x';
}

void printGAMEOVER() {
	printf("\n\n");
	printf("GGGGGGGGG        A        M       M  EEEEEEEE     OOOOOOOO  V           V   EEEEEEEE  RRRRRRRR  !!!\n");
	printf("G               A A       M M   M M  E            O      O   V         V    E         R      R  !!!\n");
	printf("G              A   A      M  M M  M  E            O      O    V       V     E         R     R   !!!\n");
	printf("G             AAAAAAA     M   M   M  EEEEE        O      O     V     V      EEEEE     RRRRRR    !!!\n");
	printf("G   GGGGG    A       A    M       M  E            O      O      V   V       E         RR        !!!\n"); 
	printf("G       G   A         A   M       M  E            O      O       V V        E         R  RR     !!!\n");
	printf("GGGGGGGGG  A           A  M       M  EEEEEEEE     OOOOOOOO        V         EEEEEEEE  R     RR  !!!\n");
	printf("\n");
}
void printTIEGAME() {
	printf("\n\n");
	printf("TTTTTTTTT  IIIIIIIII  EEEEEEEEE     GGGGGGGGG        A        M       M  EEEEEEEE\n");
	printf("    T          I      E             G               A A       M M   M M  E\n");
	printf("    T          I      E             G              A   A      M  M M  M  E\n");
	printf("    T          I      EEEEE         G             AAAAAAA     M   M   M  EEEEE\n");
	printf("    T          I      E             G   GGGGG    A       A    M       M  E\n"); 
	printf("    T          I      E             G       G   A         A   M       M  E\n");
	printf("    T      IIIIIIIII  EEEEEEEEE     GGGGGGGGG  A           A  M       M  EEEEEEEE\n");
	printf("\n");
}
int win() {
	if(board[0][0] == 'o' && board[0][1] == 'o' && board[0][2] == 'o') {
		printGAMEOVER();
		return 1;
	}
	if(board[1][0] == 'o' && board[1][1] == 'o' && board[1][2] == 'o') {
		printGAMEOVER();
		return 1;
	}
	if(board[2][0] == 'o' && board[2][1] == 'o' && board[2][2] == 'o') {
		printGAMEOVER();
		return 1;
	}

	if(board[0][0] == 'o' && board[1][0] == 'o' && board[2][0] == 'o') {
		printGAMEOVER();
		return 1;
	}
	if(board[0][1] == 'o' && board[1][1] == 'o' && board[2][1] == 'o') {
		printGAMEOVER();
		return 1;
	}
	if(board[0][2] == 'o' && board[1][2] == 'o' && board[2][2] == 'o') {
		printGAMEOVER();
		return 1;
	}
	

	if(board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == 'o') {
		printGAMEOVER();
		return 1;
	}
	if(board[0][2] == 'o' && board[1][1] == 'o' && board [2][0] == 'o') {
		printGAMEOVER();
		return 1;
	}

	int i, j, count;
	count = 0;
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			if(board[i][j] != ' ')
				count++;
		}
	}
	if(count == 9) {
		printTIEGAME();
		return 1;
	}
	return 0;	
}	

void movePlayerO() {
	if(board[0][0] == 'o' && board[0][1] == 'o' && board[0][2] == ' '){
		board[0][2] = 'o';	
		return;
	}
	if(board[0][0] == 'o' && board[0][1] == ' ' && board[0][2] == 'o'){
		board[0][1] = 'o';	
		return;
	}
	if(board[0][0] == ' ' && board[0][1] == 'o' && board[0][2] == 'o'){
		board[0][0] = 'o';
		return;
	}	

	if(board[1][0] == 'o' && board[1][1] == 'o' && board[1][2] == ' '){
		board[1][2] = 'o';	
		return;
	}
	if(board[1][0] == 'o' && board[1][1] == ' ' && board[1][2] == 'o'){
		board[1][1] = 'o';
		return;
	}	
	if(board[1][0] == ' ' && board[1][1] == 'o' && board[1][2] == 'o'){
		board[1][0] = 'o';
		return;
	}

	if(board[2][0] == 'o' && board[2][1] == 'o' && board[2][2] == ' '){
		board[2][2] = 'o';	
		return;
	}
	if(board[2][0] == 'o' && board[2][1] == ' ' && board[2][2] == 'o'){
		board[2][1] = 'o';	
		return;
	}
	if(board[2][0] == ' ' && board[2][1] == 'o' && board[2][2] == 'o'){
		board[2][0] = 'o';
		return;
	}


	if(board[0][0] == 'o' && board[1][0] == 'o' && board[2][0] == ' '){
		board[2][0] = 'o';	
		return;
	}
	if(board[0][0] == 'o' && board[1][0] == ' ' && board[2][0] == 'o'){
		board[1][0] = 'o';	
		return;
	}
	if(board[0][0] == ' ' && board[1][0] == 'o' && board[2][0] == 'o'){
		board[0][0] = 'o';
		return;
	}	

	if(board[0][1] == 'o' && board[1][1] == 'o' && board[2][1] == ' '){
		board[2][1] = 'o';	
		return;
	}
	if(board[0][1] == 'o' && board[1][1] == ' ' && board[2][1] == 'o'){
		board[1][1] = 'o';
		return;
	}	
	if(board[0][1] == ' ' && board[1][1] == 'o' && board[2][1] == 'o'){
		board[0][1] = 'o';
		return;
	}

	if(board[0][2] == 'o' && board[1][2] == 'o' && board[2][2] == ' '){
		board[2][2] = 'o';	
		return;
	}
	if(board[0][2] == 'o' && board[1][2] == ' ' && board[2][2] == 'o'){
		board[1][2] = 'o';	
		return;
	}
	if(board[0][2] == ' ' && board[1][2] == 'o' && board[2][2] == 'o'){
		board[0][2] = 'o';
		return;	
	}

	if(board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == ' ') {
		board[2][2] = 'o';
		return;
	}
	if(board[0][0] == 'o' && board[1][1] == ' ' && board[2][2] == 'o') {
		board[1][1] = 'o';
		return;
	}
	if(board[0][0] == ' ' && board[1][1] == 'o' && board[2][2] == 'o') {
		board[0][0] = 'o';
		return;
	}

	if(board[0][2] == 'o' && board[1][1] == 'o' && board[2][0] == ' ') {
		board[2][0] = 'o';
		return;
	}
	if(board[0][2] == 'o' && board[1][1] == ' ' && board[2][0] == 'o') {
		board[1][1] = 'o';
		return;
	}
	if(board[0][2] == ' ' && board[1][1] == 'o' && board[2][0] == 'o') {
		board[0][2] = 'o';
		return;
	}

	//---------------------------------------------------------------------------------------------------------------

	if(board[0][0] == 'x' && board[0][1] == 'x' && board[0][2] == ' '){
		board[0][2] = 'o';	
		return;
	}
	if(board[0][0] == 'x' && board[0][1] == ' ' && board[0][2] == 'x'){
		board[0][1] = 'o';	
		return;
	}
	if(board[0][0] == ' ' && board[0][1] == 'x' && board[0][2] == 'x'){
		board[0][0] = 'o';
		return;
	}	

	if(board[1][0] == 'x' && board[1][1] == 'x' && board[1][2] == ' '){
		board[1][2] = 'o';	
		return;
	}
	if(board[1][0] == 'x' && board[1][1] == ' ' && board[1][2] == 'x'){
		board[1][1] = 'o';
		return;
	}	
	if(board[1][0] == ' ' && board[1][1] == 'x' && board[1][2] == 'x'){
		board[1][0] = 'o';
		return;
	}

	if(board[2][0] == 'x' && board[2][1] == 'x' && board[2][2] == ' '){
		board[2][2] = 'o';	
		return;
	}
	if(board[2][0] == 'x' && board[2][1] == ' ' && board[2][2] == 'x'){
		board[2][1] = 'o';	
		return;
	}
	if(board[2][0] == ' ' && board[2][1] == 'x' && board[2][2] == 'x'){
		board[2][0] = 'o';
		return;
	}


	if(board[0][0] == 'x' && board[1][0] == 'x' && board[2][0] == ' '){
		board[2][0] = 'o';	
		return;
	}
	if(board[0][0] == 'x' && board[1][0] == ' ' && board[2][0] == 'x'){
		board[1][0] = 'o';	
		return;
	}
	if(board[0][0] == ' ' && board[1][0] == 'x' && board[2][0] == 'x'){
		board[0][0] = 'o';
		return;
	}	

	if(board[0][1] == 'x' && board[1][1] == 'x' && board[2][1] == ' '){
		board[2][1] = 'o';	
		return;
	}
	if(board[0][1] == 'x' && board[1][1] == ' ' && board[2][1] == 'x'){
		board[1][1] = 'o';
		return;
	}	
	if(board[0][1] == ' ' && board[1][1] == 'x' && board[2][1] == 'x'){
		board[0][1] = 'o';
		return;
	}

	if(board[0][2] == 'x' && board[1][2] == 'x' && board[2][2] == ' '){
		board[2][2] = 'o';	
		return;
	}
	if(board[0][2] == 'x' && board[1][2] == ' ' && board[2][2] == 'x'){
		board[1][2] = 'o';	
		return;
	}
	if(board[0][2] == ' ' && board[1][2] == 'x' && board[2][2] == 'x'){
		board[0][2] = 'o';
		return;	
	}

	if(board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == ' ') {
		board[2][2] = 'o';
		return;
	}
	if(board[0][0] == 'x' && board[1][1] == ' ' && board[2][2] == 'x') {
		board[1][1] = 'o';
		return;
	}
	if(board[0][0] == ' ' && board[1][1] == 'x' && board[2][2] == 'x') {
		board[0][0] = 'o';
		return;
	}

	if(board[0][2] == 'x' && board[1][1] == 'x' && board[2][0] == ' ') {
		board[2][0] = 'o';
		return;
	}
	if(board[0][2] == 'x' && board[1][1] == ' ' && board[2][0] == 'x') {
		board[1][1] = 'o';
		return;
	}
	if(board[0][2] == ' ' && board[1][1] == 'x' && board[2][0] == 'x') {
		board[0][2] = 'o';
		return;
	}


	if(moveX == 1 && board[1][1] == ' ') {
		board[1][1] = 'o';
		return;
	}
	if(moveX == 1 && board[1][1] != ' ') {
		board[0][0] = 'o';
		return;
	}

	if(board[0][0] == ' ') {
		board[0][0] = 'o';
		return;
	}
	else if(board[0][2] == ' ') {
		board[0][2] = 'o';
		return;
	}
	else if(board[2][0] == ' ') {
		board[2][0] = 'o';
		return;
	}
	else if(board[2][2] == ' ') {
		board[2][2] = 'o';
		return;
	}


	int i, j;
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			if(board[i][j] == ' ') {
				board[i][j] = 'o';
				return;
			}
		}
	}
}


void printboard() {
	if(board[0][0] == ' ' && board[0][1] == ' ' && board[0][2] == ' ') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("_________|_________|_________\n");	
	}
	if(board[0][0] == 'o' && board[0][1] == ' ' && board[0][2] == ' ') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  o o o  |         |         \n");
		printf("  o   o  |         |         \n");
		printf("  o o o  |         |         \n");
		printf("_________|_________|_________\n");	
	}
	if(board[0][0] == ' ' && board[0][1] == 'o' && board[0][2] == ' ') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |  o o o  |         \n");
		printf("         |  o   o  |         \n");
		printf("         |  o o o  |         \n");
		printf("_________|_________|_________\n");	
	}
	if(board[0][0] == ' ' && board[0][1] == ' ' && board[0][2] == 'o') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |         |  o o o  \n");
		printf("         |         |  o   o  \n");
		printf("         |         |  o o o  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[0][0] == 'o' && board[0][1] == 'o' && board[0][2] == ' ') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  o o o  |  o o o  |         \n");
		printf("  o   o  |  o   o  |         \n");
		printf("  o o o  |  o o o  |         \n");
		printf("_________|_________|_________\n");	
	}
	if(board[0][0] == 'o' && board[0][1] == ' ' && board[0][2] == 'o') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  o o o  |         |  o o o  \n");
		printf("  o   o  |         |  o   o  \n");
		printf("  o o o  |         |  o o o  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[0][0] == ' ' && board[0][1] == 'o' && board[0][2] == 'o') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |  o o o  |  o o o  \n");
		printf("         |  o   o  |  o   o  \n");
		printf("         |  o o o  |  o o o  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[0][0] == 'o' && board[0][1] == 'o' && board[0][2] == 'o') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  o o o  |  o o o  |  o o o  \n");
		printf("  o   o  |  o   o  |  o   o  \n");
		printf("  o o o  |  o o o  |  o o o  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[0][0] == 'x' && board[0][1] == ' ' && board[0][2] == ' ') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  x   x  |         |         \n");
		printf("    x    |         |         \n");
		printf("  x   x  |         |         \n");
		printf("_________|_________|_________\n");	
	}
	if(board[0][0] == 'x' && board[0][1] == 'o' && board[0][2] == ' ') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  x   x  |  o o o  |         \n");
		printf("    x    |  o   o  |         \n");
		printf("  x   x  |  o o o  |         \n");
		printf("_________|_________|_________\n");	
	}
	if(board[0][0] == 'x' && board[0][1] == ' ' && board[0][2] == 'o') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  x   x  |         |  o o o  \n");
		printf("    x    |         |  o   o  \n");
		printf("  x   x  |         |  o o o  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[0][0] == 'x' && board[0][1] == 'o' && board[0][2] == 'o') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  x   x  |  o o o  |  o o o  \n");
		printf("    x    |  o   o  |  o   o  \n");
		printf("  x   x  |  o o o  |  o o o  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[0][0] == ' ' && board[0][1] == 'x' && board[0][2] == ' ') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |  x   x  |         \n");
		printf("         |    x    |         \n");
		printf("         |  x   x  |         \n");
		printf("_________|_________|_________\n");	
	}
	if(board[0][0] == 'o' && board[0][1] == 'x' && board[0][2] == ' ') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  o o o  |  x   x  |         \n");
		printf("  o   o  |    x    |         \n");
		printf("  o o o  |  x   x  |         \n");
		printf("_________|_________|_________\n");	
	}
	if(board[0][0] == ' ' && board[0][1] == 'x' && board[0][2] == 'o') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |  x   x  |  o o o  \n");
		printf("         |    x    |  o   o  \n");
		printf("         |  x   x  |  o o o  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[0][0] == 'o' && board[0][1] == 'x' && board[0][2] == 'o') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  o o o  |  x   x  |  o o o  \n");
		printf("  o   o  |    x    |  o   o  \n");
		printf("  o o o  |  x   x  |  o o o  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[0][0] == ' ' && board[0][1] == ' ' && board[0][2] == 'x') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |         |  x   x  \n");
		printf("         |         |    x    \n");
		printf("         |         |  x   x  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[0][0] == 'o' && board[0][1] == ' ' && board[0][2] == 'x') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  o o o  |         |  x   x  \n");
		printf("  o   o  |         |    x    \n");
		printf("  o o o  |         |  x   x  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[0][0] == ' ' && board[0][1] == 'o' && board[0][2] == 'x') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |  o o o  |  x   x  \n");
		printf("         |  o   o  |    x    \n");
		printf("         |  o o o  |  x   x  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[0][0] == 'o' && board[0][1] == 'o' && board[0][2] == 'x') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  o o o  |  o o o  |  x   x  \n");
		printf("  o   o  |  o   o  |    x    \n");
		printf("  o o o  |  o o o  |  x   x  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[0][0] == 'x' && board[0][1] == 'x' && board[0][2] == ' ') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  x   x  |  x   x  |         \n");
		printf("    x    |    x    |         \n");
		printf("  x   x  |  x   x  |         \n");
		printf("_________|_________|_________\n");	
	}
	if(board[0][0] == 'x' && board[0][1] == 'x' && board[0][2] == 'o') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  x   x  |  x   x  |  o o o  \n");
		printf("    x    |    x    |  o   o  \n");
		printf("  x   x  |  x   x  |  o o o  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[0][0] == 'x' && board[0][1] == ' ' && board[0][2] == 'x') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  x   x  |         |  x   x  \n");
		printf("    x    |         |    x    \n");
		printf("  x   x  |         |  x   x  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[0][0] == 'x' && board[0][1] == 'o' && board[0][2] == 'x') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  x   x  |  o o o  |  x   x  \n");
		printf("    x    |  o   o  |    x    \n");
		printf("  x   x  |  o o o  |  x   x  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[0][0] == ' ' && board[0][1] == 'x' && board[0][2] == 'x') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |  x   x  |  x   x  \n");
		printf("         |    x    |    x    \n");
		printf("         |  x   x  |  x   x  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[0][0] == 'o' && board[0][1] == 'x' && board[0][2] == 'x') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  o o o  |  x   x  |  x   x  \n");
		printf("  o   o  |    x    |    x    \n");
		printf("  o o o  |  x   x  |  x   x  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[0][0] == 'x' && board[0][1] == 'x' && board[0][2] == 'x') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  x   x  |  x   x  |  x   x  \n");
		printf("    x    |    x    |    x    \n");
		printf("  x   x  |  x   x  |  x   x  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[1][0] == ' ' && board[1][1] == ' ' && board[1][2] == ' ') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("_________|_________|_________\n");	
	}
	if(board[1][0] == 'o' && board[1][1] == ' ' && board[1][2] == ' ') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  o o o  |         |         \n");
		printf("  o   o  |         |         \n");
		printf("  o o o  |         |         \n");
		printf("_________|_________|_________\n");	
	}
	if(board[1][0] == ' ' && board[1][1] == 'o' && board[1][2] == ' ') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |  o o o  |         \n");
		printf("         |  o   o  |         \n");
		printf("         |  o o o  |         \n");
		printf("_________|_________|_________\n");	
	}
	if(board[1][0] == ' ' && board[1][1] == ' ' && board[1][2] == 'o') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |         |  o o o  \n");
		printf("         |         |  o   o  \n");
		printf("         |         |  o o o  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[1][0] == 'o' && board[1][1] == 'o' && board[1][2] == ' ') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  o o o  |  o o o  |         \n");
		printf("  o   o  |  o   o  |         \n");
		printf("  o o o  |  o o o  |         \n");
		printf("_________|_________|_________\n");	
	}
	if(board[1][0] == 'o' && board[1][1] == ' ' && board[1][2] == 'o') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  o o o  |         |  o o o  \n");
		printf("  o   o  |         |  o   o  \n");
		printf("  o o o  |         |  o o o  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[1][0] == ' ' && board[1][1] == 'o' && board[1][2] == 'o') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |  o o o  |  o o o  \n");
		printf("         |  o   o  |  o   o  \n");
		printf("         |  o o o  |  o o o  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[1][0] == 'o' && board[1][1] == 'o' && board[1][2] == 'o') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  o o o  |  o o o  |  o o o  \n");
		printf("  o   o  |  o   o  |  o   o  \n");
		printf("  o o o  |  o o o  |  o o o  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[1][0] == 'x' && board[1][1] == ' ' && board[1][2] == ' ') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  x   x  |         |         \n");
		printf("    x    |         |         \n");
		printf("  x   x  |         |         \n");
		printf("_________|_________|_________\n");	
	}
	if(board[1][0] == 'x' && board[1][1] == 'o' && board[1][2] == ' ') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  x   x  |  o o o  |         \n");
		printf("    x    |  o   o  |         \n");
		printf("  x   x  |  o o o  |         \n");
		printf("_________|_________|_________\n");	
	}
	if(board[1][0] == 'x' && board[1][1] == ' ' && board[1][2] == 'o') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  x   x  |         |  o o o  \n");
		printf("    x    |         |  o   o  \n");
		printf("  x   x  |         |  o o o  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[1][0] == 'x' && board[1][1] == 'o' && board[1][2] == 'o') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  x   x  |  o o o  |  o o o  \n");
		printf("    x    |  o   o  |  o   o  \n");
		printf("  x   x  |  o o o  |  o o o  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[1][0] == ' ' && board[1][1] == 'x' && board[1][2] == ' ') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |  x   x  |         \n");
		printf("         |    x    |         \n");
		printf("         |  x   x  |         \n");
		printf("_________|_________|_________\n");	
	}
	if(board[1][0] == 'o' && board[1][1] == 'x' && board[1][2] == ' ') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  o o o  |  x   x  |         \n");
		printf("  o   o  |    x    |         \n");
		printf("  o o o  |  x   x  |         \n");
		printf("_________|_________|_________\n");	
	}
	if(board[1][0] == ' ' && board[1][1] == 'x' && board[1][2] == 'o') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |  x   x  |  o o o  \n");
		printf("         |    x    |  o   o  \n");
		printf("         |  x   x  |  o o o  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[1][0] == 'o' && board[1][1] == 'x' && board[1][2] == 'o') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  o o o  |  x   x  |  o o o  \n");
		printf("  o   o  |    x    |  o   o  \n");
		printf("  o o o  |  x   x  |  o o o  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[1][0] == ' ' && board[1][1] == ' ' && board[1][2] == 'x') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |         |  x   x  \n");
		printf("         |         |    x    \n");
		printf("         |         |  x   x  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[1][0] == 'o' && board[1][1] == ' ' && board[1][2] == 'x') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  o o o  |         |  x   x  \n");
		printf("  o   o  |         |    x    \n");
		printf("  o o o  |         |  x   x  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[1][0] == ' ' && board[1][1] == 'o' && board[1][2] == 'x') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |  o o o  |  x   x  \n");
		printf("         |  o   o  |    x    \n");
		printf("         |  o o o  |  x   x  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[1][0] == 'o' && board[1][1] == 'o' && board[1][2] == 'x') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  o o o  |  o o o  |  x   x  \n");
		printf("  o   o  |  o   o  |    x    \n");
		printf("  o o o  |  o o o  |  x   x  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[1][0] == 'x' && board[1][1] == 'x' && board[1][2] == ' ') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  x   x  |  x   x  |         \n");
		printf("    x    |    x    |         \n");
		printf("  x   x  |  x   x  |         \n");
		printf("_________|_________|_________\n");	
	}
	if(board[1][0] == 'x' && board[1][1] == 'x' && board[1][2] == 'o') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  x   x  |  x   x  |  o o o  \n");
		printf("    x    |    x    |  o   o  \n");
		printf("  x   x  |  x   x  |  o o o  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[1][0] == 'x' && board[1][1] == ' ' && board[1][2] == 'x') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  x   x  |         |  x   x  \n");
		printf("    x    |         |    x    \n");
		printf("  x   x  |         |  x   x  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[1][0] == 'x' && board[1][1] == 'o' && board[1][2] == 'x') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  x   x  |  o o o  |  x   x  \n");
		printf("    x    |  o   o  |    x    \n");
		printf("  x   x  |  o o o  |  x   x  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[1][0] == ' ' && board[1][1] == 'x' && board[1][2] == 'x') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |  x   x  |  x   x  \n");
		printf("         |    x    |    x    \n");
		printf("         |  x   x  |  x   x  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[1][0] == 'o' && board[1][1] == 'x' && board[1][2] == 'x') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  o o o  |  x   x  |  x   x  \n");
		printf("  o   o  |    x    |    x    \n");
		printf("  o o o  |  x   x  |  x   x  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[1][0] == 'x' && board[1][1] == 'x' && board[1][2] == 'x') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  x   x  |  x   x  |  x   x  \n");
		printf("    x    |    x    |    x    \n");
		printf("  x   x  |  x   x  |  x   x  \n");
		printf("_________|_________|_________\n");	
	}
	if(board[2][0] == ' ' && board[2][1] == ' ' && board[2][2] == ' ') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |         |         \n");	
	}
	if(board[2][0] == 'o' && board[2][1] == ' ' && board[2][2] == ' ') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  o o o  |         |         \n");
		printf("  o   o  |         |         \n");
		printf("  o o o  |         |         \n");
		printf("         |         |         \n");	
	}
	if(board[2][0] == ' ' && board[2][1] == 'o' && board[2][2] == ' ') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |  o o o  |         \n");
		printf("         |  o   o  |         \n");
		printf("         |  o o o  |         \n");
		printf("         |         |         \n");	
	}
	if(board[2][0] == ' ' && board[2][1] == ' ' && board[2][2] == 'o') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |         |  o o o  \n");
		printf("         |         |  o   o  \n");
		printf("         |         |  o o o  \n");
		printf("         |         |         \n");	
	}
	if(board[2][0] == 'o' && board[2][1] == 'o' && board[2][2] == ' ') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  o o o  |  o o o  |         \n");
		printf("  o   o  |  o   o  |         \n");
		printf("  o o o  |  o o o  |         \n");
		printf("         |         |         \n");	
	}
	if(board[2][0] == 'o' && board[2][1] == ' ' && board[2][2] == 'o') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  o o o  |         |  o o o  \n");
		printf("  o   o  |         |  o   o  \n");
		printf("  o o o  |         |  o o o  \n");
		printf("         |         |         \n");	
	}
	if(board[2][0] == ' ' && board[2][1] == 'o' && board[2][2] == 'o') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |  o o o  |  o o o  \n");
		printf("         |  o   o  |  o   o  \n");
		printf("         |  o o o  |  o o o  \n");
		printf("         |         |         \n");	
	}
	if(board[2][0] == 'o' && board[2][1] == 'o' && board[2][2] == 'o') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  o o o  |  o o o  |  o o o  \n");
		printf("  o   o  |  o   o  |  o   o  \n");
		printf("  o o o  |  o o o  |  o o o  \n");
		printf("         |         |         \n");	
	}
	if(board[2][0] == 'x' && board[2][1] == ' ' && board[2][2] == ' ') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  x   x  |         |         \n");
		printf("    x    |         |         \n");
		printf("  x   x  |         |         \n");
		printf("         |         |         \n");
	}
	if(board[2][0] == 'x' && board[2][1] == 'o' && board[2][2] == ' ') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  x   x  |  o o o  |         \n");
		printf("    x    |  o   o  |         \n");
		printf("  x   x  |  o o o  |         \n");
		printf("         |         |         \n");	
	}
	if(board[2][0] == 'x' && board[2][1] == ' ' && board[2][2] == 'o') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  x   x  |         |  o o o  \n");
		printf("    x    |         |  o   o  \n");
		printf("  x   x  |         |  o o o  \n");
		printf("         |         |         \n");	
	}
	if(board[2][0] == 'x' && board[2][1] == 'o' && board[2][2] == 'o') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  x   x  |  o o o  |  o o o  \n");
		printf("    x    |  o   o  |  o   o  \n");
		printf("  x   x  |  o o o  |  o o o  \n");
		printf("         |         |         \n");	
	}
	if(board[2][0] == ' ' && board[2][1] == 'x' && board[2][2] == ' ') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |  x   x  |         \n");
		printf("         |    x    |         \n");
		printf("         |  x   x  |         \n");
		printf("         |         |         \n");	
	}
	if(board[2][0] == 'o' && board[2][1] == 'x' && board[2][2] == ' ') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  o o o  |  x   x  |         \n");
		printf("  o   o  |    x    |         \n");
		printf("  o o o  |  x   x  |         \n");
		printf("         |         |         \n");	
	}
	if(board[2][0] == ' ' && board[2][1] == 'x' && board[2][2] == 'o') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |  x   x  |  o o o  \n");
		printf("         |    x    |  o   o  \n");
		printf("         |  x   x  |  o o o  \n");
		printf("         |         |         \n");	
	}
	if(board[2][0] == 'o' && board[2][1] == 'x' && board[2][2] == 'o') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  o o o  |  x   x  |  o o o  \n");
		printf("  o   o  |    x    |  o   o  \n");
		printf("  o o o  |  x   x  |  o o o  \n");
		printf("         |         |         \n");	
	}
	if(board[2][0] == ' ' && board[2][1] == ' ' && board[2][2] == 'x') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |         |  x   x  \n");
		printf("         |         |    x    \n");
		printf("         |         |  x   x  \n");
		printf("         |         |         \n");	
	}
	if(board[2][0] == 'o' && board[2][1] == ' ' && board[2][2] == 'x') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  o o o  |         |  x   x  \n");
		printf("  o   o  |         |    x    \n");
		printf("  o o o  |         |  x   x  \n");
		printf("         |         |         \n");	
	}
	if(board[2][0] == ' ' && board[2][1] == 'o' && board[2][2] == 'x') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |  o o o  |  x   x  \n");
		printf("         |  o   o  |    x    \n");
		printf("         |  o o o  |  x   x  \n");
		printf("         |         |         \n");	
	}
	if(board[2][0] == 'o' && board[2][1] == 'o' && board[2][2] == 'x') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  o o o  |  o o o  |  x   x  \n");
		printf("  o   o  |  o   o  |    x    \n");
		printf("  o o o  |  o o o  |  x   x  \n");
		printf("         |         |         \n");	
	}
	if(board[2][0] == 'x' && board[2][1] == 'x' && board[2][2] == ' ') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  x   x  |  x   x  |         \n");
		printf("    x    |    x    |         \n");
		printf("  x   x  |  x   x  |         \n");
		printf("         |         |         \n");	
	}
	if(board[2][0] == 'x' && board[2][1] == 'x' && board[2][2] == 'o') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  x   x  |  x   x  |  o o o  \n");
		printf("    x    |    x    |  o   o  \n");
		printf("  x   x  |  x   x  |  o o o  \n");
		printf("         |         |         \n");	
	}
	if(board[2][0] == 'x' && board[2][1] == ' ' && board[2][2] == 'x') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  x   x  |         |  x   x  \n");
		printf("    x    |         |    x    \n");
		printf("  x   x  |         |  x   x  \n");
		printf("         |         |         \n");	
	}
	if(board[2][0] == 'x' && board[2][1] == 'o' && board[2][2] == 'x') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  x   x  |  o o o  |  x   x  \n");
		printf("    x    |  o   o  |    x    \n");
		printf("  x   x  |  o o o  |  x   x  \n");
		printf("         |         |         \n");	
	}
	if(board[2][0] == ' ' && board[2][1] == 'x' && board[2][2] == 'x') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("         |  x   x  |  x   x  \n");
		printf("         |    x    |    x    \n");
		printf("         |  x   x  |  x   x  \n");
		printf("         |         |         \n");	
	}
	if(board[2][0] == 'o' && board[2][1] == 'x' && board[2][2] == 'x') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  o o o  |  x   x  |  x   x  \n");
		printf("  o   o  |    x    |    x    \n");
		printf("  o o o  |  x   x  |  x   x  \n");
		printf("         |         |         \n");	
	}
	if(board[2][0] == 'x' && board[2][1] == 'x' && board[2][2] == 'x') {
		printf("         |         |         \n");
		printf("         |         |         \n");
		printf("  x   x  |  x   x  |  x   x  \n");
		printf("    x    |    x    |    x    \n");
		printf("  x   x  |  x   x  |  x   x  \n");
		printf("         |         |         \n");	
	}
}

int main() {
	initialize();
	printboard();
	while(win() == 0) {
		int row = -1;
		int col = -1;
		printf("Enter move <row> <column>\n");
		scanf("%d %d", &row, &col);

		while(row < 0 || col < 0 || row >= 3 || col >= 3 || board[row][col] != ' ') {
			printf("Please enter a valid move in the following format <row> <col>\n");
			scanf("%d %d", &row, &col);		
		}
		movePlayerX(row, col);
		moveX++;
		movePlayerO();
		printboard();
	}
}
