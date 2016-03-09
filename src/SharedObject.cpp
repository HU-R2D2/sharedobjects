#include "SharedObject.hpp"

SharedObject::SharedObject(T& data_input):
data(data_input)
{
	
}

Accessor::Accessor(SharedObject<T>& so_input):
so(so_input)
{
	so.claim();
}

Accessor::~Accessor()
{
	so.release();
	
}


T& Accessor::access()
{
	so.claim();
	
}