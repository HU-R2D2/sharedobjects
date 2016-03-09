#include "NotCopyable.hpp"

template<typename T>
class SharedObject : public NotCopyable {
public:    
    SharedObject(T& data);    
        
    class Accessor : public NotCopyable {
    public:    
        Accessor(SharedObject<T>& so);
        ~Accessor();
        
        T& access();
    private:
        SharedObject& so;
    };
protected:    
    T& data; // SharedData only accesible by Accessor
    friend class Accessor;
    
    virtual void claim() {}
    virtual void release() {}
};