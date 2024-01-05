/*************************************************
Programmer: Colette Addah
Class: Cpts 121
Date Created: 10/11/2023
Date Modified: 01/05/2024
Assignment: Craps
Description: A game of Craps
**************************************************/

#include "header.h"

// Function that prints the detailed game rules
// The printed rules should align with the key aspects of the game's logic and behavior in this Program.
void print_game_rules(void) {
    printf("Welcome to craps!\n");
    printf("1. Enter your initial balance, which represents the money you have to play with.\n");
    printf("2. Make a bet; the minimum bet is $10.\n");
    printf("3. The game begins with the roll of two dice, and the sum is displayed.\n");
    printf("4. On the first roll, if you roll a 7 or 11, you win even money!\n");
    printf("5. If you roll a 2, 3, or 12, you lose your bet.\n");
    printf("6. If the first roll results in any other sum, that sum becomes your 'point.'\n");
    printf("7. Continue rolling and betting until you roll your 'point' again or a 7.\n");
    printf("8. Rolling your 'point' results in a win, but rolling a 7 results in a loss!\n");
    //printf("9. Note: Bets accumulate. Enter 0 to stop betting for the current turn.\n");
    printf("9. You'll be prompted to play again if you have enough money after each turn.\n");
    printf("Good luck and enjoy the game!\n");
}

// Function to get the initial bank balance
double get_bank_balance(void) {
    double balance;
    printf("\nEnter your initial bank balance: $");
    scanf("%lf", &balance);
    return balance;
}

// Function to get the wager amount
double get_wager_amount(void) {
    double wager;
    printf("Enter your wager amount: $");
    scanf("%lf", &wager);
    return wager;
}

// Function to check if the wager is within the limits of the player's available balance
int check_wager_amount(double wager, double balance) {
    if (wager >= 10 && wager <= balance) {
        return 1; // Wager is valid
    }
    else {
        return 0; // Wager is invalid
    }
}

// Function to roll one die (randomly generate a value between 1 and 6)
int roll_die(void) {
    return (rand() % 6) + 1;
}

// Function to calculate the sum of two dice
int calculate_sum_dice(int die1_value, int die2_value) {
    return die1_value + die2_value;
}

// Function to determine the result of the first dice roll
int is_win_loss_or_point(int sum_dice) {
    if (sum_dice == 7 || sum_dice == 11) {
        return 1; // Player wins
        // The sum of the dice is 7 or 11 on the initial roll, indicating a win.
    }
    else if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12) {
        return 0; // Player loses
    }   // The sum of the dice is 2, 3, or 12 on the initial roll, indicating a loss (craps).
    else {
        return -1; // Point established
        // The sum of the dice is not an immediate win (7 or 11) or an immediate loss (2, 3, or 12).
        // Instead, it establishes a point for the player to aim for.
    }
}

// Function to determine the result of any successive roll after the first roll
int is_point_loss_or_neither(int sum_dice, int point_value) {
    if (sum_dice == point_value) {
        return 1; // Player wins
    }
    else if (sum_dice == 7) {
        return 0; // Player loses
    }
    else {
        return -1; // Continue rolling
    }
}

// Function to adjust the bank balance based on the outcome of the roll
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract) {
    if (add_or_subtract == 1) {
        return bank_balance + wager_amount; // Add the wager amount to the balance
    }
    else if (add_or_subtract == 0) {
        return bank_balance - wager_amount; // Subtract the wager amount from the balance
    }
    else {
        return bank_balance; // No change in balance
    }
}

// Function to print messages based on the game state 
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance) {
    printf("\n--- Game Update ---\n");

    if (number_rolls == 0) {
        printf("First roll result: ");
    }
    else {
        printf("Roll %d result: ", number_rolls);
    }

    if (win_loss_neither == 1) {
        printf("You won!\n");
    }
    else if (win_loss_neither == 0) {
        printf("You lost.\n");
    }
    else {
        printf("Point established: %d\n", win_loss_neither);
    }

    printf("Initial balance: $%.2f\n", initial_bank_balance);
    printf("Current balance: $%.2f\n", current_bank_balance);

    if (current_bank_balance < 10.0) {
        printf("Your bank balance is less than $10. You cannot continue playing.\n");
    }
}

/**************************************************************************
* Term : Fall 2023                                                        *
* Class : Cpts 121                                                        *
* Instructor : Andy O'Fallon                                              *
* Assignment : PA4 - Craps                                                *
 *************************************************************************/
