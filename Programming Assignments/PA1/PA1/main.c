/*************************************************
Programmer: Colette Addah
Class: Cpts 121
Date Created:
Date Modified: 12/27/2023
Assignment: Equation Evaluator
Description: Program that computes equations
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592

#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(default: 4996)

int main(void) {
   
    // Newton's Second Law of Motion
    double force = 0, mass = 0, acceleration = 0; // Variable Declaration
    printf("Please enter the mass and acceleration <both floating-point values> for the use in Newton's Second Law: ");
    (void)scanf("%lf %lf", &mass, &acceleration); // the cast (void) suppressed the individual C6031 warnings
    force = mass * acceleration;
    printf("Newton's Second Law: force = mass * acceleration = %lf * %lf = %lf\n", mass, acceleration, force);

    // Volume of a cylinder
    double volume_cylinder = 0, radius = 0, height = 0; // Variable Declaration
    printf("Please enter the radius and height <both floating point values> for use in a volume of cylinder equation: ");
    (void)scanf("%lf %lf", &radius, &height);
    volume_cylinder = PI * pow(radius, 2) * height;
    printf("Volume of a cylinder: volume_cylinder = PI * radius^2 * height = %lf * %lf^2 * %lf = %lf\n", PI, radius, height, volume_cylinder);

    // Character Encoding
    char plaintext_character, encoded_character; // Variable Declaration
    int shift = 0;
    printf("Please enter the character and shift <char and integer> for use in the character encoding equation: ");
    (void)scanf(" %c %d", &plaintext_character, &shift);
    encoded_character = (plaintext_character - 'A') + 'a' - shift;
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
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    printf("Distance between two points: distance = %lf = sqrt((%lf - %lf)^2 + (%lf - %lf)^2)\n", distance, x2, x1, y2, y1);

    // Tangent Equation
    double tan_theta, theta; // Variable Declaration
    printf("Please enter theta <integer> for use in the tangent equation: ");
    (void)scanf("%lf", &theta);
    tan_theta = sin(theta) / cos(theta);
    printf("Tangent: %lf = sin(%lf) / cos(%lf)\n", tan_theta, theta, theta);

    // Equivalent parallel resistance
    int shift, R1 = 0, R2 = 0, R3 = 0; // Variable Declarations
    double parallel_resistance;
    printf("Please enter resistors <integers (R1,R2,R3)> for use in the parallel resistance equation: ");
    (void)scanf("%d %d %d", &R1, &R2, &R3);
    parallel_resistance = 1 / ((1.0 / R1) + (1.0 / R2) + (1.0 / R3));
    printf("Equivalent parallel resistance: %lf = 1 / (1 / %d + 1 / %d + 1 / %d)\n", parallel_resistance, R1, R2, R3);

    // General Equation 
    printf("Please enter 3 values <integers (z,x,a)> for use in the General Equation: ");
    int a, x, z; // Variable Declarations
    double result = 0.0; // Variable Declaration
    (void)scanf("%d%d%d", &a, &x, &z);
    result = ((double)2 / (double)3) -  z * x / (a % 2) + PI;
    printf("General Equation: y = (2 / 3) - %lf + %d * %d / (%d %% 2) + %lf\n", z, x, a, PI);

    return 0;
}

#pragma warning(default: 4996)

/**************************************************************************
* Term : Fall 2023                                                        *
* Class : Cpts 121                                                        *
* Instructor : Andy O'Fallon                                              *
* Assignment : PA1 - Equation Evaluator                                   *
 *************************************************************************/
 
