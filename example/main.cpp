#include "../source/include/LockingSharedObject.hpp"
#include "../source/include/LoggingSharedObject.hpp"
#include "../source/include/NotCopyable.hpp"
#include "../source/include/SharedObject.hpp"

#include <thread>
using namespace std;




void access_thread_one(LockingSharedObject<int>& obj){
    SharedObject<int>
        ::Accessor acc(obj);// Create an accessor of the LockingSharedObject
        cout <<"AccesThreadOne: "<< acc.access() << endl;//Access the Accessor
}

void access_thread_two(LockingSharedObject<int> & obj){
    SharedObject<int>
        ::Accessor acc(obj); // Create an accessor of the LockingSharedObject
        cout << "AccesThreadTwo: "<< acc.access() << endl;//Access the Accessor
}

void access_thread_three(LoggingSharedObject<int>& obj){
    SharedObject<int>
        ::Accessor acc(obj); // Create an accessor of the LockingSharedObject
        cout <<"AccesThreadThree: "<< acc.access() << endl;//Access the Accessor
}

void access_thread_four(LoggingSharedObject<int> & obj){
    SharedObject<int>
        ::Accessor acc(obj);//Create an accessor of the LockingSharedObject
        cout << "AccesThreadFour: "<< acc.access() << endl;//Access the Accessor
}
int main(){

  // You create two threads and give them a LockingSharedObject reference,
  // each thread creates its own accessor and tries to access it.
  // Because the Accessor constructor claims the accessor when you create it,
  // after one of the threads creates the Accessor,
  // the other thread has to wait for the first thread to finish because the
  // Accessor is only released when the destructor is called.

  //************  LockingSharedObject ************//

  cout << "************  LockingSharedObject ************" << endl;
  int a = 1; // create an int with a value
  LockingSharedObject<int>
      example_a(a);//assign the int to the LockingSharedObject

  thread first_a(access_thread_one,
      std::ref(example_a));// Create a thread and give it a
                        //std::ref of the LockingSharedObject
  thread second_a(access_thread_two,
      std::ref(example_a));// Create a thread and give it a
                        //std::ref of the LockingSharedObject
  first_a.join(); // Wait for thread 1 to finish
  second_a.join(); // Wait for thread 2 to finish


  //************  LoggingSharedObject ************//

  cout << "************  LoggingSharedObject ************" << endl;
  int b = 2; // create an int with a value
  LoggingSharedObject<int>
      example_b(b);//assign the int to the LockingSharedObject
  thread first_b(access_thread_three,
      std::ref(example_b));// Create a thread and give it a
                        //std::ref of the LockingSharedObject
  thread second_b(access_thread_four,
      std::ref(example_b));// Create a thread and give it a
                        //std::ref of the LockingSharedObject
  first_b.join(); // Wait for thread 1 to finish
  second_b.join(); // Wait for thread 2 to finish






  return 0;
}
