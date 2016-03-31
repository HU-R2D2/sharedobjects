#ifndef SHAREDOBJECT_H
#define SHAREDOBJECT_H

#include "NotCopyable.hpp"

/// Allows for mutual exclusion of specified objects of type T.
/// Can be extended for advanced mutual exclusion.
/// \authors Alexander Freeman, Koen van der Kruk, Remco Ruttenberg
/// \version 1.0
/// \date 29-03-2016
template<typename T>
class SharedObject : public NotCopyable {
public:

   /// Creates a SharedObject containing a reference to specified data.
   /// \param data_input The data to reference to.
   SharedObject(T & data_input) : data(data_input) {}

   /// Allows access to the mutually exclusive object.
   /// \authors Alexander Freeman, Koen van der Kruk, Remco Ruttenberg
   /// \version 1.0
   /// \date 29-03-2016
   class Accessor : public NotCopyable {
   public:

      /// Creates an Accessor object.
      /// Automatically claims the data of the SharedObject.
      /// \param so_input The SharedObject to use for mutual exclusion.
      Accessor(SharedObject<T> & so_input) : so(so_input) { so.claim(); }

      /// Automatically releases the claim on the data of the SharedObject.
      ~Accessor() { so.release(); }

      /// Returns a reference to the data of the SharedObject.
      /// \return A reference to the data of the SharedObject.
      T& access() { return so.data; }

   private:
      SharedObject<T>& so;
   };

protected:
   T& data; // SharedData only accesible by Accessor
   friend class Accessor;

   /// Claims the data of the SharedObject.
   virtual void claim() = 0;
   /// Releases the claim on the data of the SharedObject.
   virtual void release() = 0;
};


#endif
