/*
 *	stack.c
 *
 *	Creates a stack of size 7 that can be filled with double variables.
 *	The push and pop functions add and remove variables from the stack.
 *	Strings can not be added and chars will not work correctly.
 *	The double minimum value is reserved and should not be used.
 *
 *	Written by Jakob Östberg on 05/09/2020
 *
 */
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define STACK_LENGTH 7
#define DOUBLE_MIN -1.7976931348623157E+308
#define EMPTY_STACK DOUBLE_MIN

double theStack[STACK_LENGTH];
int top = -1;

/*
 * 	push()
 *
 *	Pushes one double value to the stack.
 *	input: double
 *	output: TRUE if success, FALSE if failure
 */
bool push(double pushValue) {
	if (top >= STACK_LENGTH - 1) {
		printf("ERROR: Can't push to full stack.\n");
		return false;
	}

	top++;
	theStack[top] = pushValue;
	return true;
}

/*
 * 	pop()
 *
 *	Pops a double variable from the stack
 *	input: void
 *	output: double if successful, EMPTY_STACK if stack is empty
 */
double pop(void) {
	if (top == -1) {
		printf("ERROR: Can't pop from empty stack.\n");
		return EMPTY_STACK;
	}

	top--;
	return theStack[top + 1];

}
