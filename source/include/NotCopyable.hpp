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
//! \file   NotCopyable.hpp
//! \author Koen van der Kruk 1654581 
//!			Alexander Freeman 1656733
//! \date   Created: 1-4-2016
//! \date   Last Modified: 13-5-2016
//! \brief  Prevents copy and assignment operations.
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

#ifndef NO_COPY_H
#define NO_COPY_H

/// Prevents copy and assignment operations
/// Thic class is used to make sure the inherentenced classes can not be copied or assigned.
/// \author Alexander Freeman, Koen van der Kruk
/// \version 1.0
/// \date 1-4-2016
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
