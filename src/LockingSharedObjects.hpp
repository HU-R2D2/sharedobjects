#ifndef LOCKING_SHARED_OBJECT_H
#define LOCKING_SHARED_OBJECT_H

#include "SharedObject.hpp"
#include <mutex>

template<typename T>
class LockingSharedObject : public SharedObject {
public:    
    LockingSharedObject(T& data_input);    
       
	void claim() override;
	void release() override;

private:
	std::mutex lock_object;
	SharedObject::Accessor ac;
};
#endif