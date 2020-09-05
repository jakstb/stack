#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"

double pushPop(double);

struct Test {
   char  desc[50];
   double testValue;
   double expectedReturnValue;
   double returnValue;
};

void runTest( struct Test );

char desc[5][40] =
{ "int",
  "decimal",
  "negative",
  "char",
  "zero"
};

double testValues[5] = {11, 9000.0084, -42.123456, 'd', 0};
double expectedReturnValues[5] = {11.89, 9000.0084, -42.123456, 100, 0};
double returnValues[5];


int main () {


// DECLARE TESTS
   struct Test test1;
   struct Test test2;
   struct Test test3;
   struct Test test4;
   struct Test test5;

   strcpy( test1.desc, "int");
   strcpy( test2.desc, "decimal");
   strcpy( test3.desc, "negative");
   strcpy( test4.desc, "char");
   strcpy( test5.desc, "zero");
   test1.testValue = 11;
   test2.testValue = 9000.0084;
   test3.testValue = -42.123456;
   test4.testValue = 'd';
   test5.testValue = 0;
   test1.expectedReturnValue = 11;
   test2.expectedReturnValue = 9000.0084;
   test3.expectedReturnValue = -42.123456;
   test4.expectedReturnValue = 100;
   test5.expectedReturnValue = 0;
   
// RUN TESTS
	runTest(test1);
	runTest(test2);
	runTest(test3);
	runTest(test4);
	runTest(test5);
	
   return 0;
}

void runTest( struct Test test ){

	push(test.testValue);
	test.returnValue = pop();
	if(test.expectedReturnValue == test.returnValue)
	{
		printf("PASS :: %s test was successful\n", test.desc);
	}else{
		printf("FAIL :: %s test failed\n", test.desc);
	}
}

double pushPop(double pushValue){
	push(pushValue);
	return pop();
}