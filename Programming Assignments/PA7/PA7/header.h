/*************************************************
Programmer: Colette Addah
Class: Cpts 121
Date Created: 11/09/2023
Date Modified: 01/05/2024
Assignment: Poker
Description: Poker
**************************************************/

#ifndef HEADER_H
#define HEADER_H

typedef struct card
{
	int faceIndex;
	int suitIndex;

}Card;
// Provided Functions
void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[]);

void displayCard(const int wDeck[][13], const char* wFace[], const char* wSuit[], int ndraw, int cr[], int cc[]);
void bubbleSort(int cr[], int cc[]);
void printGameRules(void);
int pair(int cc[]);
int twoPair(int cc[]);
int threeKind(int cc[]);
int fourKind(int cc[]);
int flushCheck(int cr[]);
int straightCheck(int cr[], int cc[]);
int houseCheck(int cc[]);
void changeCard(int wDeck[][13], int change, int cr[], int cc[]);
void dealerChange(int dcr[], int dcc[], int wDeck[][13]);
int checkWin(int cr[], int cc[], int dcr[], int dcc[]);
int returnBet(int bank, int wager, int win);
int cal_score(int cr[], int cc[]);
#endif  // HEADER_H

/**************************************************************************
* Term : Fall 2023                                                        *
* Class : Cpts 121                                                        *
* Instructor : Andy O'Fallon                                              *
* Assignment : PA7 - Poker                                                *
 *************************************************************************/
