#include <stdio.h>
#include "LockingSharedObject.hpp"

int main()
{
	printf("This is project SharedObjects");
	
	LockingSharedObject< int > theQuestion = LockingSharedObject< int >(1); 
	
	LockingSharedObject< int > theAnswser = LockingSharedObject< int >(42); 
	
	printf("Initialized first shared object");
	
	while (true);
    return 0;
}
