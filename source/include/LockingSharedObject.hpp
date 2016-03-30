#ifndef LOCKING_SHARED_OBJECT_H
#define LOCKING_SHARED_OBJECT_H

#include "SharedObject.hpp"
#include <mutex>
#include <iostream>

template<typename T>
class LockingSharedObject : public SharedObject<T> {
public:
	LockingSharedObject(T& data_input) :
		SharedObject<T>(data_input)
	{
	}



protected:
	void claim() override {
		lock_object.lock();
	}

	void release() override {
		lock_object.unlock();
	}
private:
	std::mutex lock_object;
};

#endif
