//! \addtogroup 0005 Shared Objects
//! \brief This project is used to safely share objects between two or more threads.
//!
//! When multiple threads share one object, it is important that they do not
//! access and change the object at the same time. So SharedObjects is a 
//! universal project that can be used throughout R2D2 so everyone uses 
//! the same way to access and lock objects between multiple threads. 
//! Developers do not need to implement their own way to 
//! lock and release objects between threads. 
//! This will reduce duplicated code in multiple projects.
//!
//! \file   SharedObject.hpp
//! \author Koen van der Kruk 1654581 
//!         Alexander Freeman 1656733 
//!         Remco Ruttenberg  1671986
//! \date   Created: 1-4-2016
//! \date   Last Modified: 13-5-2016
//! \brief  Allows for mutual exclusion of specified objects of type T.
//! 
//! Can be extended for advanced mutual exclusion.
//!
//! \copyright Copyright © 2016, HU University of Applied Sciences Utrecht. 
//! All rights reserved.
//! 
//! License: newBSD
//!
//! Redistribution and use in source and binary forms, 
//! with or without modification, are permitted provided that 
//! the following conditions are met:
//! - Redistributions of source code must retain the above copyright notice, 
//!   this list of conditions and the following disclaimer.
//! - Redistributions in binary form must reproduce the above copyright notice, 
//!   this list of conditions and the following disclaimer in the documentation 
//!   and/or other materials provided with the distribution.
//! - Neither the name of the HU University of Applied Sciences Utrecht 
//!   nor the names of its contributors may be used to endorse or promote 
//!   products derived from this software without specific prior written 
//!   permission.
//!
//! THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
//! "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, 
//! BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY 
//! AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
//! IN NO EVENT SHALL THE HU UNIVERSITY OF APPLIED SCIENCES UTRECHT
//! BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
//! CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
//! PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; 
//! OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
//! WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
//! OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
//! EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// ~< HEADER_VERSION 2016 04 12 >~

#ifndef SHAREDOBJECT_H
#define SHAREDOBJECT_H

#include "NotCopyable.hpp"

/// Allows for mutual exclusion of specified objects of type T.
/// Can be extended for advanced mutual exclusion.
/// \authors Alexander Freeman, Koen van der Kruk, Remco Ruttenberg
/// \version 1.0
/// \date 1-4-2016
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
