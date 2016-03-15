#ifndef LOGGING_SHARED_OBJECT_H
#define LOGGING_SHARED_OBJECT_H

#include "SharedObject.hpp"
#include <mutex>
#include <iostream>

template<typename T>
class LoggingSharedObject : public SharedObject<T> {
public:
	LoggingSharedObject(T& data_input) :
		SharedObject(data_input)
	{
	}

	void claim() override
	{
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