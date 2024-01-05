/*************************************************
Programmer: Colette Addah
Class: Cpts 121
Date Created: 10/11/2023
Date Modified: 01/05/2024
Assignment: Craps
Description: A game of Craps
**************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "header.h"

int main(void) {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Declare and initialize variables
    double bank_balance, wager;
    int number_rolls = 0;
    int point_value = 0;
    int win_loss_neither;

    // Display game rules
    print_game_rules();

    // Get the initial bank balance from the player
    bank_balance = get_bank_balance();

    // Main game loop
    while (bank_balance >= 10.0) { // Minimum bet is $10
        // Get the wager from the player
        wager = get_wager_amount();

        // Check if the wager is within limits
        if (!check_wager_amount(wager, bank_balance)) {
            printf("Invalid wager. Please enter a valid wager.\n");
            continue; // Restart the loop
        }

        // Roll two dice
        int die1_value = roll_die();
        int die2_value = roll_die();

        // Calculate the sum of the dice
        int sum_dice = calculate_sum_dice(die1_value, die2_value);

        if (number_rolls == 0) { // First roll
            // Determine win, loss, or point
            win_loss_neither = is_win_loss_or_point(sum_dice);

            if (win_loss_neither == -1) {
                point_value = sum_dice; // Establish a point
            }
        }
        else { // Subsequent rolls
            win_loss_neither = is_point_loss_or_neither(sum_dice, point_value);
        }

        // Adjust the bank balance based on the result
        if (win_loss_neither == 1) {
            bank_balance = adjust_bank_balance(bank_balance, wager, 1);
            printf("You won!\n");
        }
        else if (win_loss_neither == 0) {
            bank_balance = adjust_bank_balance(bank_balance, wager, 0);
            printf("You lost!\n");
        }

        // Print the die roll values
        printf("\nDie 1: %d, Die 2: %d, Sum: %d\n", die1_value, die2_value, sum_dice);

        // Print chatter messages
        chatter_messages(number_rolls, win_loss_neither, bank_balance, bank_balance - wager);

        if (win_loss_neither == 1 || win_loss_neither == 0) {
            if (bank_balance < 10.0) {
                printf("Your bank balance is less than $10. You cannot continue playing.\n");
                break; // End the game
            }

            printf("Do you want to play again? (1 for yes, 0 for no): ");
            int play_again;
            scanf("%d", &play_again);

            if (play_again == 0) {
                break; // End the game
            }

            // Reset the game for the next roll
            number_rolls = 0;
            point_value = 0;
        }
        else {
            number_rolls++;
        }
    }

    printf("Thank you for playing!\n");
    return 0;
}

/**************************************************************************
* Term : Fall 2023                                                        *
* Class : Cpts 121                                                        *
* Instructor : Andy O'Fallon                                              *
* Assignment : PA4 - Craps                                                *
 *************************************************************************/
