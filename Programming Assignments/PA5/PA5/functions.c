/*************************************************
Programmer: Colette Addah
Class: Cpts 121
Date Created: 10/29/2023
Date Modified: 01/05/2024
Assignment: Dice Game Simulation
Description: Dice Game Simulation
**************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void gameMenu()
{
	int selection = 0;

	printf("1. Print Game Rules \n2. Start Game\n3. Exit Game\n");
	scanf("%d", &selection);

	if (selection == 1)
	{
		do {
			printf("The scorecard used for Yahtzee is composed of two sections. A upper section and a lower section. A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections. The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box. If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12. Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds. If the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus. The lower section contains a number of poker like combinations.\n\n\n");
			printf("1. Print Game Rules \n2. Start Game\n3. Exit Game\n");
			scanf("%d", &selection);

		} while (selection == 1);
	}

	if (selection == 2)
	{
		printf("Have Fun!\n\n");
	}
	else
	{
		printf("Goodbye! :(\n");
		exit(1);
	}

}

//First roll Of each round
void firstRoll(int roll_number[], int roll_count)
{
	int count = 0;
	int dice = 0;
	int total_rolls = 0;

	printf("press any key to roll the dice!\n\n");
	getch();
	system("CLS");

	printf("     Roll: %d\n\n", roll_count);
	printf("|Dice|\t |Face|\n");


	for (count = 0; count < 5; count++)
	{
		roll_number[count] = rand() % 6 + 1;
		printf("| %d  |\t | %d  |\n", count + 1, roll_number[count]);
	}


}

//Ask user if they want to Choose a comboniation or roll again and returns 1 or 0
int askUser(int total_rolls, int combination[], int pick_dice[])
{
	int choice = 0;
	char input;
	if (total_rolls < 3)
	{
		printf("Do you wish to select one of the Combinations for your roll [Y/N]?  ");
		scanf(" %ch", &input);

		if (input == 'y')
		{
			return 1;
		}
		if (input == 'n')
		{
			return 0;
		}

	}
	if (total_rolls == 3)
	{
		printf("You Must Now Select a Combination! \n\n");
		return 1;
	}
	return 0;
}

//Function for Picking which dice to reroll
void reRoll(int roll_number[], int pick_dice[]) {
	printf("New roll: ");

	for (int i = 0; i < 5; i++) {
		if (pick_dice[i] == 0) {
			roll_number[i] = rand() % 6 + 1;
		}
		printf("%d ", roll_number[i]);
	}

	printf("\n");
}




//Prints out the Roll each time
void printRoll(int roll_number[], int roll_count) {
	system("CLS"); // Clear the screen

	printf("Roll: %d\n\n", roll_count);
	printf("  _____\n");
	printf(" |     |\n");
	for (int i = 0; i < 5; i++) {
		printf(" |  %d  |\n", roll_number[i]);
		printf(" |_____|\n");
	}
	printf("\n");
}

//Function for adding up score and verifying if they got points for that category
void verifyCombo(int roll_number[], int* score1, int* score2, int* score3, int* score4, int* score_total, int* score_total2, int category)
{
	int check[6] = { 0 };
	int sum = 0;
	int i = 0;
	int hi = 0;

	//Find values in rollnumber array that are the same
	for (int i = 0; i < 5; i++)
	{
		check[roll_number[i] - 1]++;
	}

	//Summing up values with same face value
	if (category == 1 || category == 2 || category == 3 || category == 4 || category == 5 || category == 6)
	{

		for (int i = 0; i < 5; ++i)
		{
			if (roll_number[i] == category)
			{

				*score1 += category;
				*score_total = *score1 + *score2;
				*score3 += category;
				*score_total2 = *score3 + *score4;

			}
		}
	}
	//Sum of score for three of a kind
	if (category == 7)//&& check[i] >= 3)
	{
		for (int i = 0; i < 6; ++i)
		{
			if (check[i] >= 3) //Find first value that is greater than or equal to 3
			{
				for (int i = 0; i < 5; ++i)
				{
					*score2 += roll_number[i];
					*score_total = *score1 + *score2;
					*score4 += roll_number[i];
					*score_total2 = *score3 + *score4;

				}
			}
		}
	}
	//Sum of four of a kind
	if (category == 8)//&& check[i] >= 3)
	{
		for (int i = 0; i < 6; ++i)
		{
			if (check[i] >= 4) //Find first value that is greater than or equal to 3
			{
				for (int i = 0; i < 5; ++i)
				{
					*score2 += roll_number[i];
					*score_total = *score1 + *score2;
					*score4 += roll_number[i];
					*score_total2 = *score3 + *score4;
				}
			}
		}
	}

	//Find face values that equal a Full house
	if (category == 9)
	{
		for (int i = 0; i < 6; ++i)
		{
			if (check[i] == 3 || check[i] == 2)
			{
				*score2 += 25;// take the locatoin of i and add 1 to match dice face, and multiply by 4
				*score_total = *score1 + *score2;
				*score4 += 25;// take the locatoin of i and add 1 to match dice face, and multiply by 4
				*score_total2 = *score3 + *score4;
			}
		}
	}
	//Calculating score for Small Strsaight
	if (category == 10)
	{
		if ((check[0] == 0 && check[1] == 0) || (check[0] == 1 && check[1] == 0))
		{
			for (i = 2; i < 6; i++)
			{
				if (check[i] == 1)
				{
					*score2 += 30;
					*score_total = *score1 + *score2;
					*score4 += 30;
					*score_total2 = *score3 + *score4;
					break;


				}
			}
		}
		else if (check[0] == 0)
		{
			for (i = 1; i < 5; i++)
			{
				if (check[i] == 1)
				{
					*score2 += 30;
					*score_total = *score1 + *score2;
					*score4 += 30;
					*score_total2 = *score3 + *score4;
					break;

				}
			}
		}
		else
		{
			for (i = 0; i < 4; i++)
			{
				if (check[i] == 1)
				{
					*score2 += 30;
					*score_total = *score1 + *score2;
					*score4 += 30;
					*score_total2 = *score3 + *score4;
					break;


				}
			}
		}
	}

	//Calculating score for large straight
	if (category == 11)
	{
		if (check[0] == 0)
		{
			for (i = 1; i < 6; ++i)
			{
				if (check[i] == 1)
				{
					*score2 += 40;
					*score_total = *score1 + *score2;
					*score4 += 40;
					*score_total2 = *score3 + *score4;
					break;

				}
			}
		}
		else
		{
			for (i = 0; i < 5; ++i)
			{
				if (check[i] == 1)
				{
					*score2 += 40;
					*score_total = *score1 + *score2;
					*score4 += 40;
					*score_total2 = *score3 + *score4;
					break;

				}
			}
		}
	}
	//calculating score for Yahtzee
	if (category == 12)
	{
		for (i = 0; i < 6; ++i)
		{
			if (check[i] == 5) //If check array has an element == 5, then yahtzee is scored
			{
				*score2 += 50;
				*score_total = *score1 + *score2;
				*score4 += 50;
				*score_total2 = *score3 + *score4;
				break;
			}
		}
	}

	//Summing up all face values
	if (category == 13)
	{
		for (int i = 0; i < 5; ++i)
		{
			*score2 += roll_number[i];
			*score_total = *score1 + *score2;
			*score4 += roll_number[i];
			*score_total2 = *score3 + *score4;
		}
	}
}
void calcScore(int* score1, int* score2, int* score3, int* score4, int* score_total, int* score_total2)
{
	if (*score1 >= 63)
	{
		*score_total = (*score_total + 35);
	}
	if (*score3 >= 63)
	{
		*score_total2 = (*score_total2 + 35);
	}
}

//Prints Out Final Score and who won
void printScore(int* score_total, int* score_total2)
{
	printf("Player 1 Total Score: %d\n", *score_total);
	printf("Player 2 Total Score: %d\n\n", *score_total2);

	if (*score_total > *score_total2)
	{
		printf("Player 1 Won!!!\n\n");
		getch();
		system("CLS");
	}
	else
	{
		printf("Player 2 Won!!!\n\n");
		getch();
		system("CLS");
	}
}

//Lets user pick which category they want to form
int comboChoice(int combination[]) {
	int category = 0;
	printf("Which Combination do you wish to select? \n\n");
	printf("1. Sum of 1's\t 7. Three-of-a-kind\n2. Sum of 2's\t 8. Four-of-a-kind\n3. Sum of 3's\t 9. Full house\n4. Sum of 4's\t 10. Small straight\n5. Sum of 5's\t 11. Large straight \n6. Sum of 6's\t 12. Yahtzee\n          13. Chance\n\nCategory: ");
	scanf("%d", &category);
	system("CLS");

	if (category >= 1 && category <= 13) {
		if (combination[category - 1] == 0) {
			combination[category - 1] = 1;

			switch (category) {
			case 1: printf("You chose Sum of 1's!\n"); break;
			case 2: printf("You chose Sum of 2's!\n"); break;
			case 3: printf("You chose Sum of 3's!\n"); break;
			case 4: printf("You chose Sum of 4's!\n"); break;
			case 5: printf("You chose Sum of 5's!\n"); break;
			case 6: printf("You chose Sum of 6's!\n"); break;
			case 7: printf("You chose Three of a Kind!\n"); break;
			case 8: printf("You chose Four of a Kind!\n"); break;
			case 9: printf("You chose Full House!\n"); break;
			case 10: printf("You chose Small Straight!\n"); break;
			case 11: printf("You chose Large Straight!\n"); break;
			case 12: printf("You chose Yahtzee!\n"); break;
			case 13: printf("You chose Chance!\n"); break;
			}

			return category;
		}
		else {
			printf("You already chose this combo, so you gained 0 points this round!\n");
			return 0;
		}
	}
	else {
		printf("Invalid selection!\n");
		return 0;
	}
}

void displayScore(int player, int upperScore, int lowerScore) {
	printf("Player %d Upper Section Score: %d\nPlayer %d Lower Section Score: %d\n", player, upperScore, player, lowerScore);
}

void displayRoundMessage(int round) {
	if (round < 12) {
		printf("End of Round %d... Starting Round %d!\n\n", round + 1, round + 2);
	}
	else {
		system("CLS");
		printf("End Of Game!!\n\n");
	}
}

/**************************************************************************
* Term : Fall 2023                                                        *
* Class : Cpts 121                                                        *
* Instructor : Andy O'Fallon                                              *
* Assignment : PA4 - Craps                                                *
 *************************************************************************/


