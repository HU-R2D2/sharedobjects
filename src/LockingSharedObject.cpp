#include "LockingSharedObject.hpp"

template<typename T>
LockingSharedObject<T>::LockingSharedObject(T& data_input):
SharedObject(data_input)
{
	SharedObject::Accessor<T> ac(data_input);
}

template<typename T>
void LockingSharedObject<T>::claim()
{
	lock_object.lock();
	ac.access();
	lock_object.unlock();
}

template<typename T>
void LockingSharedObject<T>::release()
{
	 //todo
	
}

