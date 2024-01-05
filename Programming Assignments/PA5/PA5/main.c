/*************************************************
Programmer: Colette Addah
Class: Cpts 121
Date Created: 10/29/2023
Date Modified: 01/05/2024
Assignment: Dice Game Simulation
Description: Dice Game Simulation
**************************************************/

#include "header.h"
int main() {
    int combination1[13] = { 0 };
    int combination2[13] = { 0 };
    int player1_scores[6] = { 0 };  // score1, score2, score3, score4, score_total, score_total2
    int player2_scores[6] = { 0 };  // score1, score2, score3, score4, score_total, score_total2
    int player = 1;
    srand((unsigned int)time(NULL));

    gameMenu();
    system("CLS");

    for (int round = 0; round <= 12; round++) {
        int roll_number[5] = { 0 };
        int count = 1;

        printf("Welcome to Round %d!\n", round + 1);

        while (count <= 3) {
            printf("Player %d, Roll %d:\n", player, count);
            firstRoll(roll_number, count);
            int choice = askUser(count, (player == 1) ? combination1 : combination2, roll_number);

            if (choice == 0 && count < 3) {
                do {
                    count++;
                    reRoll(roll_number, roll_number);
                    printRoll(roll_number, count);
                    choice = askUser(count, (player == 1) ? combination1 : combination2, roll_number);
                } while (choice == 0 && count < 3);
            }

            int category = comboChoice((player == 1) ? combination1 : combination2);
            verifyCombo(roll_number, &player1_scores[0], &player1_scores[1], &player1_scores[2], &player1_scores[3], &player1_scores[4], &player1_scores[5], category);
            verifyCombo(roll_number, &player2_scores[0], &player2_scores[1], &player2_scores[2], &player2_scores[3], &player2_scores[4], &player2_scores[5], category);

            displayScore(1, player1_scores[0], player1_scores[1]);
            displayScore(2, player2_scores[2], player2_scores[3]);

            if (count < 3) {
                printf("\nEnd of roll %d...\n", count);
            }

            player = (player == 1) ? 2 : 1;
            count++;
        }

        displayRoundMessage(round);
    }

    calcScore(&player1_scores[0], &player1_scores[1], &player1_scores[2], &player1_scores[3], &player1_scores[4], &player1_scores[5]);
    calcScore(&player2_scores[0], &player2_scores[1], &player2_scores[2], &player2_scores[3], &player2_scores[4], &player2_scores[5]);
    printScore(&player1_scores[4], &player2_scores[5]);
    gameMenu();
}

/**************************************************************************
* Term : Fall 2023                                                        *
* Class : Cpts 121                                                        *
* Instructor : Andy O'Fallon                                              *
* Assignment : PA4 - Craps                                                *
 *************************************************************************/

