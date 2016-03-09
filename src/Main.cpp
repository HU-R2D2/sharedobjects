#include <stdio.h>
#include <iostream>
#include "LockingSharedObject.hpp"
#include <thread> 

void firstThread()
{
	// do stuff...
}

void secondThread(int x)
{
	// do stuff...
}


int main()
{
	printf("This is project SharedObjects");
	
	std::thread first(firstThread);     // spawn new thread that calls foo()
	std::thread second(secondThread, 0);  // spawn new thread that calls bar(0)



	int question = 1;
	int answer = 1;

	LockingSharedObject<int> theQuestion(question);
	
	//LockingSharedObject< int > theAnswser(answer);
	
	printf("Initialized first shared object");
	
	first.join();                // pauses until first finishes
	second.join();               // pauses until second finishes

	std::cout << "foo and bar completed.\n";

	while (true);
    return 0;
}
