#ifndef NO_COPY_H
#define NO_COPY_H

/// Prevents copy and assignment operations
/// Thic class is used to make sure the inherentenced classes can not be copied or assigned.
/// \author Alexander Freeman, Koen van der Kruk, Timo Assen, Christiaan van den Berg, Remco Ruttenberg
/// \version 1.0
/// \date 29-3-2016
class NotCopyable {
protected:

   /// Forces the use of the default constructor (compiler generated)
   NotCopyable() = default;

   /// Forces the use of the default destructor (compiler generated)
   ~NotCopyable() = default;

   /// Prevents the class from being copied into a new object
   NotCopyable(const NotCopyable&) = delete;

   /// Prevents the class from being assigned
   NotCopyable& operator=(const NotCopyable&) = delete;
};

#endif
