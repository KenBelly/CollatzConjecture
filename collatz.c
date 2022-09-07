/* Visualizing the Collatz Conjecture 
 * Which states: This process will eventually reach the number 1, 
 *					regardless of which positive integer is chosen intially
 * 
 * 		Consider the following operation on an arbitrary positive integer:
 *			- If the number is even, divide it by two [if n%2==0: n/2]
 * 			- If the number is odd, triple it and add one [if n%2==1: (3n+1)/2]
 *			
 *		To find the stopping time:
 *			- Number of steps to reach 1
 * 			- EX: Starting number of 10 has a stopping time of 7 steps
 *
 * 		To prove it to be false: 
 *			 find a starting number which gives rise to a sequence that does not contain 1 (repeating cycle or increase w/o bounds)
 *
 * Author: Ben Kelly (GitHub/KenBelly)
 * Date: Sept. 3, 2022  
 *
 * To compile: navigate to src directory and type "make"
 *
 * For usage: navigate to src directory and type ./collatz
 *
 */

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>
#include <math.h>

//Defines
#define DEBUG true

//Global Declarations
int startNum = -1;
int steps = 0;

//Function Declarations
int strToInt(char* string);


//Main Function
int main(int argc, char* argv[])
{
  //First n Foremost: Check arguments
  if(argc != 2){
	fprintf(stderr, "\nError: Incorrect number of arguments! Expected 1 argument, recieved: [%d]", argc - 1);
	fprintf(stderr, "\n\nUsage: ./collatz [starting number]\n");
    return 1;
  }

  startNum = strToInt(argv[1]);

  printf("Starting number is: %d\n", startNum);

  if(startNum < 0){
    fprintf(stderr, "\nError: Expected a positive integer\n")
    return 1;
  }

  return 0;
}

/* Helper function: Converts a given string into an integer given that the provided string is actually an integer
 * Param: char* string to be converted
 * Returns: -1 upon failure, or the given string
 */
int strToInt(char* string)
{
    errno = 0;
    char* p;
    long arg = strtol(string, &p, 10); //strtol(const char *restrict str, char **restrict endptr, int base);
    if(*p != '\0' || errno != 0 || arg < INT_MIN || arg > INT_MAX)
        return -1;

    return (int)arg;
}
