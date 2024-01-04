/*************************************************
Programmer: Colette Addah
Class: Cpts 121
Date Created:
Date Modified: 12/27/2023
Assignment: Equation Evaluator - Modular Approach
Description: Program that computes equations
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592

#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(default: 4996)

// Function Prototypes
double calculate_newtons_2nd_law(double mass, double acceleration);
double calculate_volume_cylinder(double radius, double height);
char perform_character_encoding(char plaintext_character, int shift);
double calculate_distance_between_2pts(double x1, double x2, double y1, double y2);
double calculate_tangent_theta(double theta);
double resistance(int R1, int R2, int R3);
double general_equation(int a, int x, int z);

#pragma warning(default: 4996)

/**************************************************************************
* Term : Fall 2023                                                        *
* Class : Cpts 121                                                        *
* Instructor : Andy O'Fallon                                              *
* Assignment : PA2 - Equation Evaluator - Modular Approach                *
 *************************************************************************/
