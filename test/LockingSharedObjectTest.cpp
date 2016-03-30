#include "gtest/gtest.h"
#include "../source/include/LockingSharedObject.hpp"
#include <thread>

void AccessThreadOne(LockingSharedObject<int>& obj){
  SharedObject<int>::Accessor acc(obj);
  ASSERT_EQ(1,acc.access());
}

void AccessThreadTwo(LockingSharedObject<int> & obj){
  SharedObject<int>::Accessor acc(obj);
  ASSERT_EQ(1,acc.access());
}

void PassAccessorThread(SharedObject<int>::Accessor& acc){
  ASSERT_EQ(1, acc.access());
}


TEST(LockingSharedObject, TestAccessor){
  int a = 1;
  LockingSharedObject<int> testing(a);
  std::thread first(AccessThreadOne, std::ref(testing));
  std::thread second(AccessThreadTwo, std::ref(testing));
  first.join();
  second.join();
}

TEST(LockingSharedObject, TestPassAccessor){
  int a = 1;
  LockingSharedObject<int> testing(a);
  SharedObject<int>::Accessor acc(testing);
  std::thread first(PassAccessorThread, std::ref(acc));
  first.join();
}
