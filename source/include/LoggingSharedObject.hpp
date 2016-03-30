#ifndef LOGGING_SHARED_OBJECT_H
#define LOGGING_SHARED_OBJECT_H

#include "SharedObject.hpp"
#include <mutex>
#include <iostream>

template<typename T>
class LoggingSharedObject : public SharedObject<T> {
public:
	LoggingSharedObject(T& data_input) :
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
