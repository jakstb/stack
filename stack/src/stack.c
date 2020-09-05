#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define STACK_LENGTH 7
#define EMPTY_STACK INT_MIN

double theStack[STACK_LENGTH];
int top = -1;

bool push(double pushValue) {
	if (top >= STACK_LENGTH - 1) {
		printf("ERROR: Can't push to full stack.\n");
		return false;
	}

	top++;
	theStack[top] = pushValue;
	return true;
}

double pop(void) {
	if (top == -1) {
		printf("ERROR: Can't pop from empty stack.\n");
		return EMPTY_STACK;
	}

	top--;
	return theStack[top + 1];

}
