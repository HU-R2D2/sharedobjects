#include "gtest/gtest.h"
#include "../source/include/LoggingSharedObject.hpp"
#include <thread>

void LogAccessThreadOne(LoggingSharedObject<int>& obj){
  SharedObject<int>::Accessor acc(obj);
  ASSERT_EQ(1,acc.access());
}

void LogAccessThreadTwo(LoggingSharedObject<int> & obj){
  SharedObject<int>::Accessor acc(obj);
  ASSERT_EQ(1,acc.access());
}

void LogPassAccessorThread(SharedObject<int>::Accessor& acc){
  ASSERT_EQ(1, acc.access());
}

TEST(LoggingSharedObject, LogTestAccessor){
  int a = 1;
  LoggingSharedObject<int> testing(a);
  std::thread first(LogAccessThreadOne, std::ref(testing));
  std::thread second(LogAccessThreadTwo, std::ref(testing));
  first.join();
  second.join();
}

TEST(LoggingSharedObject, LogTestPassAccessor){
  int a = 1;
  LoggingSharedObject<int> testing(a);
  SharedObject<int>::Accessor acc(testing);
  std::thread first(LogPassAccessorThread, std::ref(acc));
  first.join();
}

TEST(LoggingSharedObject, LogChangeObjectValue){
  int start = 1;
  LoggingSharedObject<int> testing(start);
  SharedObject<int>::Accessor acc(testing);
  ASSERT_EQ(1, acc.access());
  acc.access() = 2;
  ASSERT_EQ(2, acc.access());
  acc.access() = 59;
  ASSERT_EQ(59, acc.access());
}
