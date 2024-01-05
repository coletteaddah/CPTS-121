/*************************************************
Programmer: Colette Addah
Class: Cpts 121
Date Created:
Date Modified: 01/03/2023
Assignment: Statistical Analysis of Student Record
Description: Program that computes equations
**************************************************/

#include "header.h"

//Main
int main(void) {

    // Create input.dat and output.dat
    FILE* input = fopen("input.txt", "w");
    // Open input and output files
    FILE* output = fopen("output.dat", "w");

    // Checks if [INPUT]/[OUTPUT] can be opened
    if (input == NULL || output == NULL) {
        printf("Error opening files.\n");
        return 1;
    
    }

    // Declare variables
    int id1, id2, id3, id4, id5, stand1, stand2, stand3, stand4, stand5, sumstand, sumage;
    double gpa1, gpa2, gpa3, gpa4, gpa5, age1, age2, age3, age4, age5;
    double sumgpa, meangpa, meanage, meanstand, dev1, dev2, dev3, dev4, dev5, var, standdev, max, min;

    // Call Functions for Students [1-5]

    // Student 1 [Call function]
    id1 = read_integer(input);
    gpa1 = read_double(input);
    stand1 = read_integer(input);
    age1 = read_double(input);

    // Student 2 [Call function]
    id2 = read_integer(input);
    gpa2 = read_double(input);
    stand2 = read_integer(input);
    age2 = read_double(input);

    // Student 3 [Call function]
    id3 = read_integer(input);
    gpa3 = read_double(input);
    stand3 = read_integer(input);
    age3 = read_double(input);

    // Student 4 [Call function]
    id4 = read_integer(input);
    gpa4 = read_double(input);
    stand4 = read_integer(input);
    age4 = read_double(input);

    // Student 5 [Call function]
    id5 = read_integer(input);
    gpa5 = read_double(input);
    stand5 = read_integer(input);
    age5 = read_double(input);

    // GPA - Standing - Age [Sum all Students]
    sumgpa = calculate_sum(gpa1, gpa2, gpa3, gpa4, gpa5);
    sumstand = calculate_sum(stand1, stand2, stand3, stand4, stand5);
    sumage = calculate_sum(age1, age2, age3, age4, age5);

    // GPA - Standing - Age [Mean]
    meangpa = calculate_mean(sumgpa, 5);
    meanstand = calculate_mean(sumstand, 5);
    meanage = calculate_mean(sumage, 5);

    // Deviation - Variance - Standard Deviation [Computation]
    dev1 = calculate_deviation(gpa1, meangpa);
    dev2 = calculate_deviation(gpa2, meangpa);
    dev3 = calculate_deviation(gpa3, meangpa);
    dev4 = calculate_deviation(gpa4, meangpa);
    dev5 = calculate_deviation(gpa5, meangpa);
    var = calculate_variance(dev1, dev2, dev3, dev4, dev5, 5);
    standdev = calculate_standard_deviation(var);

    // Max and Min [Computation]
    max = find_max(gpa1, gpa2, gpa3, gpa4, gpa5);
    min = find_min(gpa1, gpa2, gpa3, gpa4, gpa5);

    // Print statements [Outfile]
    print_double(output, meangpa);
    print_double(output, meanstand);
    print_double(output, meanage);
    print_double(output, standdev);
    print_double(output, min);
    print_double(output, max);

    // Close Files [Input/Output]
    fclose(input);
    fclose(output);

    return 0;
}


/**************************************************************************
* Term : Fall 2023                                                        *
* Class : Cpts 121                                                        *
* Instructor : Andy O'Fallon                                              *
* Assignment : PA3 - Statistical Analysis of Student Record               *
 *************************************************************************/
