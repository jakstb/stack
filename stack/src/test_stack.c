/*
 *	test_stack.c
 *
 *	Creates a series of unit tests that tests the functionality
 *	of the push() and pop() functions in stack.c
 *
 *	Written by Jakob Östberg on 05/09/2020
 *
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"

struct Test {
	char desc[50];
	double testValue;
	double expectedReturnValue;
	double returnValue;
};

bool runTest(struct Test);

int main() {

	// DECLARE TESTS
	struct Test test1;
	struct Test test2;
	struct Test test3;
	struct Test test4;
	struct Test test5;

	// Test 1 - int
	strcpy(test1.desc, "int");
	test1.testValue = 11;
	test1.expectedReturnValue = 11;

	// Test 2 - decimal
	strcpy(test2.desc, "decimal");
	test2.testValue = 9000.0084;
	test2.expectedReturnValue = 9000.0084;

	// Test 3 - negative
	strcpy(test3.desc, "negative");
	test3.testValue = -42.123456;
	test3.expectedReturnValue = -42.123456;

	// Test 4 - char
	strcpy(test4.desc, "char");
	test4.testValue = 'd';
	test4.expectedReturnValue = 100;

	// test 5 - zero
	strcpy(test5.desc, "zero");
	test5.testValue = 0;
	test5.expectedReturnValue = 0;

	// RUN TESTS
	runTest(test1);
	runTest(test2);
	runTest(test3);
	runTest(test4);
	runTest(test5);

	return 0;
}
/*
 * 	runTest()
 *
 *	Tests if a pushed variable is the same as the popped variable
 *	input: struct
 *	output: TRUE if success, FALSE if failure
 */
bool runTest(struct Test test) {
	push(test.testValue);
	test.returnValue = pop();
	if (test.expectedReturnValue == test.returnValue) {
		printf("PASS :: %s test was successful\n", test.desc);
		return true;
	} else {
		printf("FAIL :: %s test failed, expected value was %f but got %f \n",
				test.desc, test.expectedReturnValue, test.returnValue);
		return false;
	}
}
