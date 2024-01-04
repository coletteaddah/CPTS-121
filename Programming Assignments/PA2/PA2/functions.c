/*************************************************
Programmer: Colette Addah
Class: Cpts 121
Date Created:
Date Modified: 12/27/2023
Assignment: Equation Evaluator - Modular Approach
Description: Program that computes equations
**************************************************/

#include "header.h"

double calculate_newtons_2nd_law(double mass, double acceleration) {

    double force = mass * acceleration;
    return(force);
}

double calculate_volume_cylinder(double radius, double height) {
    double volume_cylinder = PI * pow(radius, 2) * height;
    return(volume_cylinder);
}

char perform_character_encoding(char plaintext_character, int shift) {
    char encoded_character = (plaintext_character - 'A') + 'a' - shift;
    return(encoded_character);
}

double calculate_distance_between_2pts(double x1, double x2, double y1, double y2) {
   double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
   return(distance);
}

double calculate_tangent_theta(double theta) {
   double tan_theta = sin(theta) / cos(theta);
   return(tan_theta);
}

double resistance(int R1, int R2, int R3) {
    double parallel_resistance = 1 / ((1.0 / R1) + (1.0 / R2) + (1.0 / R3));
    return(parallel_resistance);
}

double general_equation(int a, int x, int z) {
    double result = ((double)2 / (double)3) - z * x / (a % 2) + PI;
    return(result);
}


/**************************************************************************
* Term : Fall 2023                                                        *
* Class : Cpts 121                                                        *
* Instructor : Andy O'Fallon                                              *
* Assignment : PA2 - Equation Evaluator - Modular Approach                *
 *************************************************************************/

