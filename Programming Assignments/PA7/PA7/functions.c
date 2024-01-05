/*************************************************
Programmer: Colette Addah
Class: Cpts 121
Date Created: 11/09/2023
Date Modified: 01/05/2024
Assignment: Poker
Description: Poker
**************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printGameRules(void)
{
	printf("1. Each player draws five cards.\n");
	printf("2. Each player chooses up to 3 cards to re-draw.\n");
	printf("3. Each player can bet, call, fold, or check.\n");

}

/* shuffle cards in deck */
void shuffle(int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

void changeCard(int wDeck[][13], int change, int cr[], int cc[])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0, temp;   /* card counter */
	int u = 0, r = 0, c = 0;
	/* for each of the 52 cards, choose slot of deck randomly */
	u = change;
	for (row = 0; row <= 3; row++)
	{
		/* loop through columns of wDeck for current row */
		for (column = 0; column <= 12; column++)
		{

			if (wDeck[row][column] == change + 10)
			{
				cr[change - 1] = row;
				cc[change - 1] = column;
				r = row;
				c = column;

				//wDeck[row][column] = change;
			}


			//change the value of card with +10th card(it is still sth random)

		}

	}

	for (row = 0; row <= 3; row++)
	{
		/* loop through columns of wDeck for current row */
		for (column = 0; column <= 12; column++)
		{

			if (wDeck[row][column] == change)
			{
				wDeck[row][column] = change + 10;

			}

		}
	}
	wDeck[r][c] = change;
}
/* deal cards in deck */

void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[], int ndraw, int cr[], int cc[])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0;   /* card counter */

	/* deal each of the 52 cards */

	for (row = 0; row <= 3; row++)
	{
		/* loop through columns of wDeck for current row */
		for (column = 0; column <= 12; column++)
		{
			/* if slot contains current card, display card */
			if (wDeck[row][column] == ndraw)
			{
				//printf ("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
				cr[ndraw - 1] = row;
				cc[ndraw - 1] = column;
			}

		}
	}

}
void displayCard(const int wDeck[][13], const char* wFace[], const char* wSuit[], int ndraw, int cr[], int cc[])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0;   /* card counter */
	int i = 0, rw = 0, cl = 0;
	/* deal each of the 52 cards */

	for (row = 0; row <= 3; row++)
	{
		/* loop through columns of wDeck for current row */
		for (column = 0; column <= 12; column++)
		{
			/* if slot contains current card, display card */
			if (wDeck[row][column] == ndraw)
			{
				rw = cr[ndraw - 1];
				cl = cc[ndraw - 1];
				printf("%5s of %-8s%c", wFace[cl], wSuit[rw], card % 2 == 0 ? '\n' : '\t');

			}

		}
	}
}
void bubbleSort(int cr[], int cc[])
{
	int c, d, swap, len, rswp;

	len = 5;

	for (c = 0; c < (len + 1); c++)
	{
		for (d = 0; d < len - 1; d++)
		{
			if (cc[d] > cc[d + 1]) /* For decreasing order use < */
			{
				swap = cc[d];
				rswp = cr[d];
				cc[d] = cc[d + 1];
				cr[d] = cr[d + 1];
				cc[d + 1] = swap;
				cr[d + 1] = rswp;

			}
		}
	}


}
int pair(int cc[])
{
	int pair = 0;

	for (int i = 0; i < 5; i++) {
		if (cc[i] == cc[(i + 1) % 5] || cc[i] == cc[(i + 2) % 5]) {
			pair++;
		}
	}

	return (pair == 2) ? 1 : 0;

}
int twoPair(int cc[])
{
	int pair = 0;

	for (int i = 0; i < 5; i++) {
		if (cc[i] == cc[(i + 1) % 5] || cc[i] == cc[(i + 2) % 5] || cc[i] == cc[(i + 3) % 5] || cc[i] == cc[(i + 4) % 5]) {
			pair++;
		}
	}

	return (pair == 4) ? 1 : 0;

}
int threeKind(int cc[])
{
	int pair = 0;

	for (int i = 0; i < 5; i++) {
		if (cc[i] == cc[(i + 1) % 5] || cc[i] == cc[(i + 2) % 5] || cc[i] == cc[(i + 3) % 5] || cc[i] == cc[(i + 4) % 5] || cc[i] == cc[i % 5]) {
			pair++;
		}
	}

	return (pair == 6) ? 1 : 0;


}
int fourKind(int cc[])
{
	int pair = 0;

	for (int i = 0; i < 5; i++) {
		if (cc[i] == cc[(i + 1) % 5] || cc[i] == cc[(i + 2) % 5] || cc[i] == cc[(i + 3) % 5] || cc[i] == cc[(i + 4) % 5] || cc[i] == cc[i % 5]) {
			pair++;
		}
	}

	return (pair >= 12) ? 1 : 0;

}
int houseCheck(int cc[])
{
	int pair = 0;

	for (int i = 0; i < 5; i++) {
		if (cc[i] == cc[(i + 1) % 5] || cc[i] == cc[(i + 2) % 5] || cc[i] == cc[(i + 3) % 5] || cc[i] == cc[(i + 4) % 5] || cc[i] == cc[i % 5]) {
			pair++;
		}
	}

	return (pair == 10) ? 1 : 0;

}
int flushCheck(int cr[])
{
	if (cr[0] == cr[1] && cr[1] == cr[2] && cr[2] == cr[3] && cr[3] == cr[4]) {
		return 1;
	}
	else {
		return 0;
	}

}
int straightCheck(int cr[], int cc[])
{
	int pair = 0;
	bubbleSort(cr, cc);

	for (int i = 0; i < 4; i++) {
		if (cc[i + 1] == cc[i] + 1) {
			pair++;
		}
	}

	return (pair >= 4) ? 1 : 0;

}
void dealerChange(int dcr[], int dcc[], int wDeck[][13]) {
	if (!(pair(dcc) || twoPair(dcc) || threeKind(dcc) || fourKind(dcc) || flushCheck(dcc) || straightCheck(dcr, dcc))) {
		printf("Dealer got bad hands and now he is changing his cards\n");
		for (int change = 0; change < 3; change++) {
			changeCard(wDeck, change + 6, dcr, dcc);
		}
	}
}
int cal_score(int cr[], int cc[])
{
	int p1 = 0, p2 = 0, k3 = 0, k4 = 0, house = 0, fl = 0, st = 0, score = 0;

	p1 = pair(cc);
	p2 = twoPair(cc);
	k3 = threeKind(cc);
	k4 = fourKind(cc);
	house = houseCheck(cc);
	fl = flushCheck(cc);
	st = straightCheck(cr, cc);
	score = 0;
	if (p1 == 1)
	{
		score += 1;
	}
	if (p2 == 1)
	{
		score += 10;
	}
	if (k3 == 1)
	{
		score += 100;
	}
	if (k4 == 1)
	{
		score += 1000;
	}
	if (house == 1)
	{
		score += 900;
	}
	if (fl == 1)
	{
		score += 800;
	}
	if (st == 1)
	{
		score += 700;
	}
	return score;
}
int checkWin(int cr[], int cc[], int dcr[], int dcc[])
{
	int dscore = 0, pscore = 0;
	dscore = cal_score(dcr, dcc);
	pscore = cal_score(cr, cc);
	if (pscore > dscore)
	{
		printf("You won, the money is yours\n");
		return 1;
	}
	else if (pscore < dscore)
	{
		printf("You lost, you lost your wager");
		return 0;
	}

	else if (pscore == dscore)
	{
		if (dcr[5] > cr[5])
		{
			printf("You lost, you lost your wager");
			return 0;
		}
		else if (dcr[5] < cr[5])
		{
			printf("You won, the money is yours\n");
			return 1;
		}
		else
		{
			printf("Tied, wager returned to your bank\n");
			return 2;
		}
	}
}
int returnBet(int bank, int wager, int win)
{
	int result = 0;
	if (win == 0)
	{
		result = bank;
	}
	else if (win == 1)
	{
		result = bank + wager * 2;
	}
	else
	{
		result = bank + wager;
	}
}

/**************************************************************************
* Term : Fall 2023                                                        *
* Class : Cpts 121                                                        *
* Instructor : Andy O'Fallon                                              *
* Assignment : PA7 - Poker                                                *
 *************************************************************************/
