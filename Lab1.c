/*
program: Lab1.c
author: Sandy, Gao, 300384424
date: 2024-09-05
purpose: Lab 1
*/

#include <stdio.h>

// Functions
double Sqrt(double input);
double Square(double input);
double Hypotenuse(double a, double b);

// Main function
int main() 
{
    double a;
    double b;
    int validInput;

    // Display messages
    printf("Welcome to this Pythagorean calculator!\n");

    do 
    {
        printf("Please enter two positive, non-zero real values for the two right sides of a right triangle:\n");
        validInput = scanf_s("%lf %lf", &a, &b);

        // Validate the inputs
        if (validInput != 2 || a <= 0 || b <= 0) 
        {
            printf("ERROR! Please ensure both inputs are positive and nonzero real values.\n");
            // Clear invalid input
            while (getchar() != '\n');
        }
    } while (a <= 0 || b <= 0);

    // Calculate and display the length of the hypotenuse
    printf("The length of the hypotenuse is equal to %.2f.\n", Hypotenuse(a, b));

    return 0;
}

// Calculates the square of a number
double Square(double input) 
{
    return input * input;
}

// Calculates the approximate square root value using the square root approximation algorithm
double Sqrt(double input) 
{
    double lastGuess = 1.0, nextGuess;
    do 
    {
        nextGuess = 0.5 * (lastGuess + (input / lastGuess));
        if (nextGuess - lastGuess < 0.001 && lastGuess - nextGuess < 0.001)
        {
            break;
        }
        lastGuess = nextGuess;
    } while (1);

    return nextGuess;
}

// Calculates the hypotenuse using the Pythagorean Theorem
double Hypotenuse(double a, double b) 
{
    return Sqrt(Square(a) + Square(b));
}