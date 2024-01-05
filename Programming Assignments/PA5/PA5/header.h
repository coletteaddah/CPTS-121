/*************************************************
Programmer: Colette Addah
Class: Cpts 121
Date Created: 10/29/2023
Date Modified: 01/05/2024
Assignment: Dice Game Simulation
Description: Dice Game Simulation
**************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifndef HEADER_H
#define HEADER_H

// Function to display the game menu
void gameMenu();
/* Precondition: None
   Parameters: None */

   // Function to perform the first dice roll
void firstRoll(int rollnumber[], int rollcount);
/* Precondition: Requires an array for the dice roll results and the current roll count
   Parameters: Array 'rollnumber' representing dice values, integer 'rollcount' indicating the current roll number */

   // Function to ask the user for dice selection
int askUser(int totalrolls, int combination[], int pickdice[]);
/* Precondition: Requires the total number of rolls, an array for combinations, and an array for picked dice
   Parameters: Integer 'totalrolls' representing the total rolls, array 'combination' for combinations, and array 'pickdice' for picked dice */

   // Function to re-roll selected dice
void reRoll(int rollnumber[], int pickdice[]);
/* Precondition: Requires an array for the dice roll results and an array for picked dice
   Parameters: Array 'rollnumber' representing dice values, array 'pickdice' indicating which dice to re-roll */

   // Function to print the current dice roll
void printRoll(int rollnumber[], int rollcount);
/* Precondition: Requires an array for the dice roll results and the current roll count
   Parameters: Array 'rollnumber' representing dice values, integer 'rollcount' indicating the current roll number */

   // Function to verify selected combination and update scores
void verifyCombo(int rollnumber[], int* score1, int* score2, int* score3, int* score4, int* scoretotal, int* scoretotal2, int category);
/* Precondition: Requires the dice roll results, individual scores, and total scores
   Parameters: Array 'rollnumber' representing dice values, integer pointers 'score1', 'score2', 'score3', 'score4' for individual scores,
               integer pointers 'scoretotal' and 'scoretotal2' for total scores, and an integer 'category' representing the selected combination */

               // Function to calculate total scores
void calcScore(int* score1, int* score2, int* score3, int* score4, int* scoretotal, int* scoretotal2);
/* Precondition: Requires individual scores and total scores
   Parameters: Integer pointers 'score1', 'score2', 'score3', 'score4' for individual scores,
               integer pointers 'scoretotal' and 'scoretotal2' for total scores */

               // Function to select a combination for scoring
int comboChoice(int combination[]);
/* Precondition: Requires an array of combinations
   Parameters: Array 'combination' for available combinations */

   // Function to print the total scores
void printScore(int* scoretotal, int* scoretotal2);
/* Precondition: Requires total scores
   Parameters: Integer pointers 'scoretotal' and 'scoretotal2' for total scores */

   // Function to display player scores
void displayScore(int player, int upperScore, int lowerScore);
/* Precondition: Requires player number, upper score, and lower score
   Parameters: Integer 'player' representing the player number, integers 'upperScore' and 'lowerScore' for scores */

   // Function to display round-related messages
void displayRoundMessage(int round);
/* Precondition: Requires the current round number
   Parameters: Integer 'round' indicating the current round number */


#endif

/**************************************************************************
* Term : Fall 2023                                                        *
* Class : Cpts 121                                                        *
* Instructor : Andy O'Fallon                                              *
* Assignment : PA4 - Craps                                                *
 *************************************************************************/
