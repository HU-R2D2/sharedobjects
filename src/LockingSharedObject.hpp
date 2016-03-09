#ifndef LOCKING_SHARED_OBJECT_H
#define LOCKING_SHARED_OBJECT_H

#include "SharedObject.hpp"
#include <mutex>

template<typename T>
class LockingSharedObject : public SharedObject<T> {
public:    
	LockingSharedObject(T& data_input) :
	SharedObject(data_input)
	{
		SharedObject<T>::Accessor ac(data_input); //THIS IS NOT WORKING
	}
       
	void claim() override 
	{
		lock_object.lock();
	}

	void release() override {
		lock_object.unlock();
	}

private:
	std::mutex lock_object;
};

#endif