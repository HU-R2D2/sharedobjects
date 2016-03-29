#include "gtest/gtest.h"
#include "../source/include/LockingSharedObject.hpp"

TEST(LockingSharedObject, TestAccess){
  int a = 1;
  LockingSharedObject<int> testing(a);
  ASSERT_EQ(1,1);
}
