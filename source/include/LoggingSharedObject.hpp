#ifndef LOGGING_SHARED_OBJECT_H
#define LOGGING_SHARED_OBJECT_H

#include "SharedObject.hpp"
#include <mutex>
#include <iostream>

/// Class LoggingSharedObject
/// This class is used to log when an object is claimed and released. 
/// \authors Koen van der Kruk
/// \version 1.0
/// \date 31-3-2016
template<typename T>
class LoggingSharedObject : public SharedObject<T> {
public:

	/// Constructs the LogginSharedObject with data as input
	/// \param data_input The input data the loggingsharedobject can use to lock and unlock
	/// \return A new LoggingSharedObject
	LoggingSharedObject(T& data_input) :
		SharedObject<T>(data_input)
	{
	}

protected:

	/// This will claim the current object and it's data. This will also print out when the object is currently claimed.
	void claim() override {
		std::cout << "Object is currently claimed. " << std::endl;
		lock_object.lock();
	}
	
	/// This will release the current object and it's data. This will also print out when the object is currently released.
	void release() override {
		std::cout << "Object is currently released. " << std::endl;
		lock_object.unlock();
	}
private:
	/// Internal mutex to make sure the threads do not interfere with each other.
	std::mutex lock_object;
};

#endif
