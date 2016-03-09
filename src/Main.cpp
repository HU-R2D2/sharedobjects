#include <stdio.h>
#include "SharedObjects.hpp"

int main()
{
	printf("This is project SharedObjects");
	
	SharedObjects< int > theObject = SharedObjects< int >(42); 
	
	printf("Initialized first shared object");
	
	while (true);
    return 0;
}
