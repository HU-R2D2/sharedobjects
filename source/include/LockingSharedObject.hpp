#ifndef LOCKING_SHARED_OBJECT_H
#define LOCKING_SHARED_OBJECT_H

#include "SharedObject.hpp"
#include <mutex>
#include <iostream>

/// Class LockingSharedObject
/// This class is used to lock and unlock data between multiple threads.
/// \authors Koen van der Kruk
/// \version 1.0
/// \date 31-3-2016
template<typename T>
class LockingSharedObject : public SharedObject<T> {
public:

	/// Constructs the LockingSharedObject with data as input
	/// \param data_input The input data the this class can use to lock and unlock data
	/// \return A new LockingSharedObject
	LockingSharedObject(T& data_input) :
		SharedObject<T>(data_input)
	{
	}

protected:

	/// This will claim the current object and it's data. This will block other threads that want to access the internal data.
	void claim() override {
		lock_object.lock();
	}

	/// This will release the current object and it's data. So other threads can access it again.
	void release() override {
		lock_object.unlock();
	}
	
private:

	/// Internal mutex to make sure the threads do not interfere with each other.
	std::mutex lock_object;
};

#endif
