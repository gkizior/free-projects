#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define SHUFFLES 3

typedef struct CARD {
	char * suit;
	char * number;
}CARD;

int handcash;

CARD deck[52];
CARD hand[11];
CARD house[11];
int housesize;
int handsize;
int decksize;


void init() {
	handcash = 1000;
	handsize = 0;
	housesize = 0;
	decksize = 52;
	int count;
	for(count = 0; count < 51; count++) {
		deck[count].suit = (char *)malloc(10*sizeof(char));
		deck[count].number = (char *)malloc(2*sizeof(char));
	}
	for(count = 0; count < 9; count++) {
		int i = count + 2;
		deck[count].suit = "hearts";
		sprintf(deck[count].number, "%d", i);
	}
	for(count = 0; count < 9; count++) {
		int i = count + 2;
		deck[count + 9].suit = "spades";
		sprintf(deck[count + 9].number, "%d", i);
	}
	for(count = 0; count < 9; count++) {
		int i = count + 2;
		deck[count + 18].suit = "diamonds";
		sprintf(deck[count + 18].number, "%d", i);
	}
	for(count = 0; count < 9; count++) {
		int i = count + 2;
		deck[count + 27].suit = "clubs";
		sprintf(deck[count + 27].number, "%d", i);
	}
	deck[36].suit = "hearts";deck[36].number = "jack";	deck[37].suit = "hearts";deck[37].number = "queen";
	deck[38].suit = "hearts";deck[38].number = "king";	deck[39].suit = "spades";deck[39].number = "jack";
	deck[40].suit = "spades";deck[40].number = "queen";	deck[41].suit = "spades";deck[41].number = "king";
	deck[42].suit = "diamonds";deck[42].number = "jack";	deck[43].suit = "diamonds";deck[43].number = "queen";
	deck[44].suit = "diamonds";deck[44].number = "king";	deck[45].suit = "clubs";deck[45].number = "jack";
	deck[46].suit = "clubs";deck[46].number = "queen";	deck[47].suit = "clubs";deck[47].number = "king";
	deck[48].suit = "hearts";deck[48].number = "ace";	deck[49].suit = "spades";deck[49].number = "ace";
	deck[50].suit = "diamonds";deck[50].number = "ace";	deck[51].suit = "clubs";deck[51].number = "ace";
	for(count = 0; count < 11; count++) {
		hand[count].suit = (char *)malloc(10*sizeof(char));
		hand[count].number = (char *)malloc(2*sizeof(char));
		house[count].suit = (char *)malloc(10*sizeof(char));
		house[count].number = (char *)malloc(2*sizeof(char));
	}	
}

void shuffle() {
	struct timespec ts;
	if (timespec_get(&ts, 1) == 0) {
		/* Handle error */
	}
	srandom(ts.tv_nsec ^ ts.tv_sec);
	int i, pos1, pos2;
	for(i = 0; i < 10000; i++) {
		pos1 = random() % 52;
		pos2 = random() % 52;
		char * tempsuit = deck[pos1].suit;
		char * tempnumber = deck[pos1].number;
		deck[pos1].suit = deck[pos2].suit;
		deck[pos1].number = deck[pos2].number;
		deck[pos2].suit = tempsuit;
		deck[pos2].number = tempnumber;
	}
	decksize = 52;
}	

int fliphand() {
	if(decksize > 0) {
		decksize--;
		CARD c = deck[decksize];
		hand[handsize] = c;
		handsize++;
		return 1;
	}
	return 0;
}
int fliphouse() {
	if(decksize > 0) {
		decksize--;
		CARD c = deck[decksize];
		house[housesize] = c;
		housesize++;
		return 1;
	}
	return 0;
}

void printhand() {
	int i = 0;
	printf("Your Hand:\n");
	for(i = 0; i < handsize; i++){
		printf("Card %d: %s_%s\n", i, hand[i].number, hand[i].suit);
	}
}

int counthand() {
	int i, sum;
	sum = 0;
	int numAce = 0;
	for(i = 0; i < handsize; i++) {
		if(strcmp(hand[i].number, "ace") == 0){
			sum += 11;
			numAce++;
		}
		else if(strcmp(hand[i].number, "jack") == 0 || strcmp(hand[i].number, "queen") == 0 || strcmp(hand[i].number, "king") == 0) {
			sum += 10;
		}
		else { 
			sum += atoi(hand[i].number);
		}
	}
	while(sum > 21 && numAce != 0) {
		sum-=10;
		numAce--;
	}
	return sum;
}
int counthouse() {
	int i, sum;
	sum = 0;
	int numAce = 0;
	for(i = 0; i < housesize; i++) {
		if(strcmp(house[i].number, "ace") == 0){
			sum += 11;
			numAce++;
		}
		else if(strcmp(house[i].number, "jack") == 0 || strcmp(house[i].number, "queen") == 0 || strcmp(house[i].number, "king") == 0) {
			sum += 10;
		}
		else 
			sum += atoi(house[i].number);
	}
	while(sum > 21 && numAce != 0) {
		sum-=10;
		numAce--;
	}
	return sum;

}
int isNumeric (char * s)
{
	while(*s) {
		if(!isdigit(*s))
			return 0;
		else
			s++;
	}
	return 1;
}

int main() {
	init();	
	printf("Welcome to Kizior's Castle Grand Casino\nLets play a game of BlackJack\nYou have $%d to bet!!\n", handcash);
	int i = 0;
	int iterations = 0;
	int done = 1;
	while(done && handcash > 0) {
		int j;
		for(j = 0; j < 11; j++) {
			hand[0].suit = "";
			hand[0].number = "";
			house[0].suit = "";
			house[0].number = "";
		}
		handsize = 0; housesize = 0;
		if(iterations % SHUFFLES == 0) {
			shuffle();
		}
		fliphand();
		fliphouse();
		fliphand();
		fliphouse();
		printhand();
		printf("How much money do you want to bet? You have a total of $%d\n", handcash);
		char * b = (char *)malloc(8*sizeof(char));
		scanf("%s", b);
		int bet = atoi(b);
		while(bet < 0 || bet > handcash || isNumeric(b) == 0) {
			printf("Please enter a bet between $0-$%d\n", handcash);
			scanf("%s", b);
			bet = atoi(b);
		}
		int hit = 1;
		int i = 0;
		while(hit) {
			if(i != 0) {
				printhand();
			}
			i++;
			if(counthand() > 21) {
				break;
			}
			if(counthouse() < 16) {
				fliphouse();
			}
			printf("\nHit or hold?\n");
			char * ans = (char *)malloc(5*sizeof(char));;
			scanf("%s", ans);
			while(strcasecmp("hit",ans) != 0 && strcasecmp("hold",ans) != 0) {
				printf("Please enter either <hit> or <hold>\n");
				scanf("%s", ans);
			}
			if(strcasecmp("hit",ans) == 0){
				hit = 1;
				fliphand();
			}
			else	
				hit = 0;
		}
		if(counthand() > 21) {
			printf("You lose.\nYour count was: %d\n", counthand());
			handcash-=bet;
		}
		else{
			while(counthand() > counthouse()) {
				fliphouse();
			}
			if(counthouse() == counthand()) {
				printf("You tied.\nYour count was: %d\nHouse count was: %d\n", counthand(),counthouse());
			}
			else if(counthouse() > counthand() && counthouse() <= 21) {
				printf("You lose.\nYour count was: %d\nHouse count was: %d\n",counthand(),counthouse());
				handcash-=bet;
			}
			else{
				printf("You WIN.\nYour count was: %d\nHouse count was: %d\n",counthand(),counthouse());
				handcash+=bet;
			}
		}
		if(handcash > 0) {
			printf("Do you want to play again? <y/n> Money left: $%d\n", handcash);
			char * a = (char *)malloc(10*sizeof(char));
			scanf("%s", a);
			while(strcasecmp(a,"y") != 0 && strcasecmp("n", a) != 0) {
				printf("Please enter either <y> or <n>\n");
				scanf("%s",a);
			}
			if(strcasecmp("y", a) == 0)
				done = 1;
			else{
				printf("Thanks for playing! You left with $%d\n", handcash);
				done = 0;
			}
		}
		iterations++;
	}
	if(handcash == 0) {
		printf("You ran out of money. Please come again!\n");
	}
}
