#include "sieve.h"

/****************************************************
	This function runs the header.h file functions
	which in combination implement the Sieve of
	Eratosthenes algorithm to isolate the prime
	numbers. To apply Sieve's algorithm, a list
	is created with a series of integers beginning
	at 2 (in increments of 1) and ending at n,
	where n is defined by the user ( n is not to
	exceed the value 10000).
 -----------------------------------------------------
	@author Paola Jiron
 *****************************************************/

int main(){
    // local variables
    int user_input, bound;
    int flag = 0;
    
    printf("\nPress ENTER to continue.");
    
    // continue until flag is set (indicating correct input)
    // and no more values to be read in-line
    while((flag != 1) && (user_input = readValue()) != '\n'){
        printf("Please enter a number between 2 and 10,000\n");
        
        scanf("%d", &bound);	// this is the user's input (upper bound)
        
        if(bound >= 2 && bound <= 10000 ){		// validate user's input
            
            createList(bound);			// if here, create table
            flag = 1;					// set the flag to terminate loop
        }else{				// otherwise, continue to ask for user input
            
            printf("You have entered an unacceptable value. Let's try this again...\n");
        }
    }
    return 0;
}
