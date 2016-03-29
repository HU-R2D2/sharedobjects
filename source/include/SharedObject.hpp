#ifndef SHAREDOBJECT_H
#define SHAREDOBJECT_H

#include "NotCopyable.hpp"

template<typename T>
class SharedObject : public NotCopyable {
public:
	SharedObject(T & data_input) : data(data_input) {}



protected:
	T& data; // SharedData only accesible by Accessor
	template <typename T> friend class Accessor;

	virtual void claim() = 0;
	virtual void release() = 0;
};

template<typename T>
class Accessor : public NotCopyable {
public:

	Accessor(SharedObject<T> & so_input) : so(so_input) { so.claim(); }

	~Accessor() { so.release(); }

	T& access() { return so.data; }

private:
	SharedObject<T>& so;
};

#endif
