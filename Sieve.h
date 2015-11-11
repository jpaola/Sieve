#ifndef sieve_h
#define sieve_h					// defines this file as header file

#include <stdio.h>
#include <stdlib.h>
#include <math.h>				// to access the sqrt() function

#define LOWER_LIMIT 2				// the first valid prime number
#define NOT_PRIME 0		// determines whether or not an integer is a prime number
void createList(int upper_bound);			// creates a list of integers

void computeSieve(int arr[], int lower_bound, int upper_boundint);	// computes sieve
void print(int arr[], int upper_bound);			// prints the sieve to screen
int readValue();				// function to read and evaluate user input
int checkChar();				// helper function for the readValue() function

#endif
