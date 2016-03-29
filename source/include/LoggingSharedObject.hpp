#ifndef LOGGING_SHARED_OBJECT_H
#define LOGGING_SHARED_OBJECT_H

#include "SharedObject.hpp"
#include <mutex>
#include <iostream>

/// Class LoggingSharedObject
/// This class is used to log when an object is claimed and released. 
/// \authors Alexander Freeman, Koen van der Kruk, Timo Assen, Christiaan van den Berg, Remco Ruttenberg
/// \version 1.0
/// \date 29-3-2016

template<typename T>
class LoggingSharedObject : public SharedObject<T> {
public:
	LoggingSharedObject(T& data_input) :
		SharedObject(data_input)
	{
	}

	void claim() override {
		lock_object.lock();
		std::cout << "Object is currently claimed. " << std::endl;
	}

	void release() override {
		lock_object.unlock();
		std::cout << "Object is currently unlocked. " << std::endl;
	}

private:
	std::mutex lock_object;
};

#endif
