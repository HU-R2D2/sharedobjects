#include <stdio.h>
#include "LockingSharedObject.hpp"

int main()
{
	printf("This is project SharedObjects");
	
	int question = 1;
	int answer = 1;

	LockingSharedObject<int> theQuestion(question);
	
	//LockingSharedObject< int > theAnswser(answer);
	
	printf("Initialized first shared object");
	
	while (true);
    return 0;
}
