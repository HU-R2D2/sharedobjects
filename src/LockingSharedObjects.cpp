#include "LockingSharedObject.hpp"

LockingSharedObject::LockingSharedObject(T& data_input):
SharedObject(data_input)
{
	SharedObject::Accessor<T> ac(data_input);
	
	
}

LockingSharedObject::claim()
{
	lock_object.lock();
	ac.access();
	lock_object.unlock();
}

LockingSharedObject::release()
{
	 //todo
	
}
