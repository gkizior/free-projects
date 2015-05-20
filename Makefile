goal: tictactoe blackjack

tictactoe: tictactoe.c
	gcc -g -o tictactoe tictactoe.c

blackjack: blackjack.c
	gcc -g -o blackjack blackjack.c

clean: rm -f tictactoe blackjack
