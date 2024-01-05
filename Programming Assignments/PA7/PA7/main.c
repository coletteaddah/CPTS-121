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

const char* suits[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };
const char* ranks[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

int main(void) {
    // Initialize variables
    int numDraw = 0, drawCount = 0, playerBank = 0, playerWager = 0;
    int deck[4][13] = { 0 }, userOption = 0;
    int userCardRow[5] = { 0 }, userCardCol[5] = { 0 }, dealerCardRow[10] = { 0 }, dealerCardCol[10] = { 0 }, change = 0, numChange = 0;
    int win = 0, initialBank = 0;

    printf("WELCOME TO THE POKER'S DEN\n");

    do {
        // Display menu options
        printf("\n1. Print game rules.\n");
        printf("2. Start a game.\n");
        printf("3. Exit\n");

        // Get user choice
        scanf("%d", &userOption);

        // Clear screen for better visibility
        system("cls");

        if (userOption == 1) {
            // Display game rules
            printGameRules();
        }
    } while (userOption <= 1 || userOption > 3);

    if (userOption == 3) {
        // Exit the game
        printf("Goodbye\n");
        return 0;
    }

    // Get the initial bank from the player
    printf("Please enter your initial bank (integer)\n");
    scanf("%d", &playerBank);
    initialBank = playerBank;

    // Main game loop
    while (playerBank < initialBank * 2) {
        // Initialize the deck
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 13; j++) {
                deck[i][j] = 0;
            }
        }

        // Seed random-number generator
        srand((unsigned)time(NULL));

        // Reset draw counts
        numDraw = 1;
        drawCount = numDraw;

        // Shuffle the deck
        shuffle(deck);

        // Display initial hands
        printf("\n You are getting your hands\n");
        while (numDraw < drawCount + 5) {
            deal(deck, ranks, suits, numDraw, userCardRow, userCardCol);
            displayCard(deck, ranks, suits, numDraw, userCardRow, userCardCol);
            numDraw += 1;
        }

        // Prompt user for card changes
        printf("How many cards do you want to change? (0-3)\n");
        scanf("%d", &numChange);

        if (numChange != 0) {
            for (int i = 0; i < numChange; i++) {
                printf("Please type the card number (1 to 5) to change\n");
                scanf("%d", &change);
                changeCard(deck, change, userCardRow, userCardCol);
            }
        }

        // Display final user hand
        printf("Your hand is now\n");
        bubbleSort(userCardRow, userCardCol);

        for (int index = 1; index < 6; index++) {
            displayCard(deck, ranks, suits, index, userCardRow, userCardCol);
        }

        // Draw additional cards for the dealer
        printf("\nDealer is getting his cards...\n");
        while (numDraw < drawCount + 5) {
            deal(deck, ranks, suits, numDraw, dealerCardRow, dealerCardCol);
            numDraw += 1;
        }

        // Allow the dealer to change cards if needed
        dealerChange(dealerCardRow, dealerCardCol, deck);

        // Sort the dealer's hand for display
        bubbleSort(dealerCardRow, dealerCardCol);

        // Get the player's bet
        do {
            printf("Please enter your bet (integer)\n");
            scanf("%d", &playerWager);

            if (playerWager > playerBank) {
                printf("You don't have enough money for that wager\n");
            }
        } while (playerWager > playerBank);

        // Deduct the player's bet from their bank
        playerBank -= playerWager;

        // Display the dealer's hand
        printf("\n\nDealer's hand\n");
        for (int index = 6; index < 11; index++) {
            displayCard(deck, ranks, suits, index, dealerCardRow, dealerCardCol);
        }

        // Check who won the round
        win = checkWin(userCardRow, userCardCol, dealerCardRow, dealerCardCol);

        // Update player's bank based on the result
        playerBank = returnBet(playerBank, playerWager, win);

        // Display the updated bank
        printf("Your bank is now %d", playerBank);

        // End the game if the player's bank is zero
        if (playerBank <= 0) {
            break;
        }
    }

    // Display game over messages based on the outcome
    if (playerBank == 0) {
        printf("Out of Moolah\n");
    }
    else if (playerBank >= initialBank * 2) {
        printf("Game Over\n");
    }

    // Game has ended
    printf("Thanks for playing!\n");

    return 0;
}

/**************************************************************************
* Term : Fall 2023                                                        *
* Class : Cpts 121                                                        *
* Instructor : Andy O'Fallon                                              *
* Assignment : PA7 - Poker                                                *
 *************************************************************************/
