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
		std::cout << "Object is currently claimed. "
	}

	void release() override {
		std::cout << "Object is currently unlocked. "
	}

private:
	std::mutex lock_object;
};

#endif