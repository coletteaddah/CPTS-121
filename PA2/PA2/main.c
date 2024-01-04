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

#include "header.h"

int main(void) {

    // Newton's Second Law of Motion
    double force = 0, mass = 0, acceleration = 0; // Variable Declaration
    printf("Please enter the mass and acceleration <both floating-point values> for the use in Newton's Second Law: ");
    (void)scanf("%lf %lf", &mass, &acceleration); // the cast (void) suppressed the individual C6031 warnings
    force = calculate_newtons_2nd_law(mass, acceleration);
    printf("Force: %.2lf\n", force);

    // Volume of a cylinder
    double volume_cylinder = 0, radius = 0, height = 0; // Variable Declaration
    printf("Please enter the radius and height <both floating point values> for use in a volume of cylinder equation: ");
    (void)scanf("%lf %lf", &radius, &height);
    volume_cylinder = calculate_volume_cylinder(radius, height);
    printf("Volume of a cylinder: %.3lf\n", volume_cylinder);

    // Character Encoding
    char plaintext_character, encoded_character; // Variable Declaration
    int shift = 0;
    printf("Please enter the character and shift <char and integer> for use in the character encoding equation: ");
    (void)scanf(" %c %d", &plaintext_character, &shift);
    encoded_character = perform_character_encoding(plaintext_character, shift);
    printf("Encoded character: %c\n", encoded_character);

    // Distance between two points
    double x1, x2, y1, y2;
    printf("Please enter the points <integers (x1,x2,y1,y2)> for use in the distance equation:\n");
    printf("Enter x1: ");
    (void)scanf("%lf", &x1);
    printf("Enter x2: ");
    (void)scanf("%lf", &x2);
    printf("Enter y1: ");
    (void)scanf("%lf", &y1);
    printf("Enter y2: ");
    (void)scanf("%lf", &y2);
    double distance = calculate_distance_between_2pts(x1, x2, y1, y2);
    printf("Distance: %lf\n", distance);

    // Tangent Equation
    double tan_theta, theta; // Variable Declaration
    printf("Please enter theta <integer> for use in the tangent equation: ");
    (void)scanf("%lf", &theta);
    tan_theta = calculate_tangent_theta(theta);
    printf("Tangent: %lf\n", tan_theta);

    // Equivalent parallel resistance
    int R1 = 0, R2 = 0, R3 = 0; // Variable Declarations
    double parallel_resistance;
    printf("Please enter resistors <integers (R1,R2,R3)> for use in the parallel resistance equation: ");
    (void)scanf("%d %d %d", &R1, &R2, &R3);
    parallel_resistance = resistance(R1, R2, R3);
    printf("Equivalent parallel resistance: %lf\n", parallel_resistance);

    //// General Equation 
    printf("Please enter 3 values <integers (a, x, z)> for use in the General Equation: ");
    int a, x, z; // Variable Declarations
    double result = 0.0; // Variable Declaration
    (void)scanf("%d%d%d", &a, &x, &z);
    result = general_equation(a, x, z);
    printf("General Equation: %lf\n", result);

    return 0;
}


/**************************************************************************
* Term : Fall 2023                                                        *
* Class : Cpts 121                                                        *
* Instructor : Andy O'Fallon                                              *
* Assignment : PA2 - Equation Evaluator - Modular Approach                *
 *************************************************************************/
