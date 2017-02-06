#include "sieve.h"
/**************************************************
	This function populates the list with integer
	values 2 to n; where 2 is the lower limit and
	n is the upper limit (n is user defined).
 ***************************************************/
void createList(int upper_bound){
    
    int i,j;								// local variables used in loop
    int sqrtOfInput = sqrt(upper_bound);	// take the squareroot of user input
    int list[upper_bound + 1];				// array length excludes values 0 and 1
    int *ptr = list;						// pointer to the list
    
    // here, fill in the array with integer values from
    // lower_limit to upper_limit
    for ( i = LOWER_LIMIT; i <= upper_bound; i ++){
        list[i] = i;
    }
    for ( j = LOWER_LIMIT; j <= sqrtOfInput; j++){
        computeSieve(list, j, upper_bound);
    }
    list[0] = list[1] = 0;	// 0 and 1 as neglected, the first prime value is 2
    print(ptr, upper_bound);	// output a table of prime numbers generated
    
}	// end of createList function definitions

/*************************************************
	This function finds and returns the list of
	prime values from 2 (lower limit) to n (user
	defined upper limit).
 **************************************************/

void computeSieve( int arr[], int lower_bound, int upper_bound){
    
    int temp, value;	// local var's (temp is loop control var)
    temp = value = lower_bound;	    // temp and value are now 2
    
    while(temp <= upper_bound){
        temp += value;
        
        // if the number is not prime, set to zero
        if ((temp <= upper_bound) && (arr[temp] != NOT_PRIME)){
            arr[temp] = NOT_PRIME;
        }
    }
} // end of computeSieve function definitions

/*************************************************
 This function reads from standard input and
 determines whether the input is a non-
 numerical value. If the input is a numerical
 value then it is converted into decimal value
 (using base 10 logic). The result is returned
 once the decimal representation of the input
 is computed.
 **************************************************/

int readValue(){
    
    int accumulator = 0;	// sum of values read (decimal representation)
    int c;
    
    while((c = checkChar()) != '\n'){	// continue until end of line is reached
        
        c = getchar();					// get the next character entered
        accumulator= accumulator * 10;	// parse to DECimal
        
        accumulator = accumulator + ( c - '0');		// add values
    }
    return accumulator;		// return the decimal value
    
} // end of readValue function definitions

/*************************************************
 This function simply determines whether or
 not the next character is pointer to End Of
 File. Then it returns the following character
 whether there is one to be read or EOF itself.
 **************************************************/

int checkChar(){
    
    int c;		// will contain next character input
    
    c = getchar();		// get the next character in stdin (buffer read)
    if( c != EOF){			// read values until there aren't anymore to be read
        ungetc(c, stdin);		// place the character back in stdin (buffer read)
    }
    return c;		// returns the character
}	// end of checkChar function definitions

/************************************************
	This function prints an array in table
	format by dividing it evenly in rows and
	columns. It accepts a pointer to
	an array of integers and a integer value
	wich defines the user input (upper bound).
 *************************************************/

void print(int *arr, int upper_bound){
    
    int i, j = 0;  // local variables for the loop
    int column = 0, index = 0 ;	// the columns and index for primes in the array
    int temp[upper_bound/2];	// new array is half the original array's size
    
    printf("\nYou entered: %5d \n", upper_bound);
    printf("The following table displays the prime values from:    2 to %5d \n\n", upper_bound );
    
    for(i = 0; i <= upper_bound; i++){			// print out generated prime values
        if(arr[i]) {						// populate the temp array with primes
            temp[index]= i;
            printf("[%4d]: %6d  ", j++, temp[index]);	// output primes
            
            column++;		// move to next column
            index++;				// move to next index
            
            if(column == 7){		// go to next line to format columns evenly
                printf("\n");
                column = 0;			// reset the column count
            }
        }
    }
    printf("\n");
} // end of print function definitions
