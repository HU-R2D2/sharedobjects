#include "gtest/gtest.h"
#include "../source/include/LockingSharedObject.hpp"
#include <thread>
#include <exception>

void firstThread(LockingSharedObject<int>& obj){
  std::cout <<"Thread 1 access start" << std::endl;
  SharedObject<int>::Accessor acc(obj);
  std::cout <<"Thread 1 access done" << std::endl;
  ASSERT_EQ(1,1);
  std::cout << "thread 1: " << acc.access() << std::endl;
}

void secondThread(LockingSharedObject<int> & obj){
std::cout <<"Thread 2 access start" << std::endl;
  SharedObject<int>::Accessor acc(obj);
  std::cout <<"Thread 2 access done" << std::endl;

  ASSERT_EQ(1,1);
  std::cout << "thread 2: " << acc.access() << std::endl;
}

TEST(LockingSharedObject, TestAccess){
  int a = 1;
  LockingSharedObject<int> testing(a);
  std::thread first(firstThread, std::ref(testing));
  std::thread second(secondThread, std::ref(testing));

  first.join();
  second.join();
  ASSERT_EQ(1,1);
  std::cout << "DONE" << std::endl;

}
