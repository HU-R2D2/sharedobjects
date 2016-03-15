#include <stdio.h>
#include <iostream>
#include "LockingSharedObject.hpp"
#include "LoggingSharedObject.hpp"
#include <thread>
#include <sstream>
#include <chrono>

static int times = 1000 * 1000;

void firstThread(SharedObject<int>& obj){
	for (int i = 0; i < times; ++i) {
		Accessor<int> a(obj);
		int& b = a.access();
		++b;
		int c;
	}
	std::stringstream ss;
	ss << "#1: " << Accessor<int>(obj).access() << std::endl;
	std::cout << ss.str();
}

void secondThread(SharedObject<int>& obj){
	for (int i = 0; i < times; ++i) {
		Accessor<int> a(obj);
		int& b = a.access();
		b -= 2;
		int c;
	}
	std::stringstream ss;
	ss << "#2: " << Accessor<int>(obj).access() << std::endl;
	std::cout << ss.str();
}


int main(){
	std::cout << "This is project SharedObjects" << std::endl;
	int a = 1;
	LockingSharedObject<int> theQuestion(a);

	typedef std::chrono::microseconds t_stamp;

	t_stamp time_start = std::chrono::duration_cast<t_stamp>(std::chrono::high_resolution_clock::now().time_since_epoch());

	std::thread first(firstThread, std::ref(theQuestion));     // spawn new thread that calls foo()
	std::thread second(secondThread, std::ref(theQuestion));  // spawn new thread that calls bar(0)

	//LockingSharedObject< int > theAnswser(answer);

	std::cout << "Initialized first shared object" << std::endl;

	first.join();                // pauses until first finishes
	second.join();               // pauses until second finishes

	std::cout << "Time (us): " << ((std::chrono::duration_cast<t_stamp>(std::chrono::high_resolution_clock::now().time_since_epoch() - time_start).count())) << std::endl;

	std::cout << std::boolalpha << "Testing: " << (a == 1 - times) << std::endl;

	std::cout << "foo and bar completed.\n";

	std::cin.get();
    return 0;
}
