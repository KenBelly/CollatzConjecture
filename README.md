# CollatzConjecture
Attempting to visualize the collatzConjecture using C, possibly other languages in the future as well 

 * Which states: This process will eventually reach the number 1, 
 *					regardless of which positive integer is chosen intially
 * 
 * 		Consider the following operation on an arbitrary positive integer:
 *			- If the number is even, divide it by two [if n%2==0: n/2]
 * 			- If the number is odd, triple it and add one [if n%2==1: (3n+1)/2]
 *			
 *		To find the stopping time:
 *			- Number of steps to reach a value 1
 * 			- EX: Starting number of 10 has a stopping time of 7 steps
 *
 * 		To prove it to be false: 
 *			 find a starting number which gives rise to a sequence that does not contain 1 (repeating cycle or increase w/o bounds)