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
//! \file   LockingSharedObject.hpp
//! \author Koen van der Kruk 1654581
//! \date   Created: 1-4-2016
//! \date   Last Modified: 13-5-2016
//! \brief  This class is used to lock and unlock data between multiple threads.
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

#ifndef LOCKING_SHARED_OBJECT_H
#define LOCKING_SHARED_OBJECT_H

#include "SharedObject.hpp"
#include <mutex>
#include <iostream>

/// Class LockingSharedObject
/// This class is used to lock and unlock data between multiple threads.
/// \authors Koen van der Kruk
/// \version 1.0
/// \date 1-4-2016
template<typename T>
class LockingSharedObject : public SharedObject<T> {
public:

	/// Constructs the LockingSharedObject with data as input
	/// \param data_input The input data the this class can use to lock and unlock data
	/// \return A new LockingSharedObject
	LockingSharedObject(T& data_input) :
		SharedObject<T>(data_input)
	{
	}

protected:

	/// This will claim the current object and it's data. This will block other threads that want to access the internal data.
	void claim() override {
		lock_object.lock();
	}

	/// This will release the current object and it's data. So other threads can access it again.
	void release() override {
		lock_object.unlock();
	}
	
private:

	/// Internal mutex to make sure the threads do not interfere with each other.
	std::mutex lock_object;
};

#endif
