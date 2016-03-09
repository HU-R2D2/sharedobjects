#include "SharedObject.hpp"

template<typename T>
SharedObject<T>::SharedObject(T& data_input):
data(data_input)
{
	
}

template<typename T>
SharedObject<T>::Accessor::Accessor(SharedObject<T>& so_input):
so(so_input)
{
	so.claim();
}

template<typename T>
SharedObject<T>::Accessor::~Accessor()
{
	so.release();
}

template<typename T>
T& SharedObject<T>::Accessor::access()
{
	so.claim();
	
}