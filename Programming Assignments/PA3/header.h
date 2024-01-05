/*************************************************
Programmer: Colette Addah
Class: Cpts 121
Date Created:
Date Modified: 01/03/2023
Assignment: Statistical Analysis of Student Record
Description: Program that computes equations
**************************************************/

#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h> 
#include <math.h> 

// Defined Functions
double read_double(FILE* infile);
int read_integer(FILE* infile);
double calculate_sum(double number1, double number2, double number3, double number4, double number5);
double calculate_mean(double sum, int number);
double calculate_deviation(double number, double mean);
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number);
double calculate_standard_deviation(double variance);
double find_max(double number1, double number2, double number3, double number4, double number5);
double find_min(double number1, double number2, double number3, double number4, double number5);
void print_double(FILE* outfile, double number);


/**************************************************************************
* Term : Fall 2023                                                        *
* Class : Cpts 121                                                        *
* Instructor : Andy O'Fallon                                              *
* Assignment : PA3 - Statistical Analysis of Student Record               *
 *************************************************************************/
