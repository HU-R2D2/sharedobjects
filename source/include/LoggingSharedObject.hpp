/**
*______      _          ______                          
*| ___ \    | |         | ___ \                         
*| |_/ /___ | |__   ___ | |_/ /___  ___  ___ _   _  ___ 
*|    // _ \| '_ \ / _ \|    // _ \/ __|/ __| | | |/ _ \
*| |\ \ (_) | |_) | (_) | |\ \  __/\__ \ (__| |_| |  __/
*\_| \_\___/|_.__/ \___/\_| \_\___||___/\___|\__,_|\___|
*                                                       
*
* @file LoggingSharedObject.hpp
* @date Created: 1-4-2016
* @version 1.0
*
* @author Koen van der Kruk
*
* @section LICENSE
* License: newBSD
*
* Copyright © 2016, HU University of Applied Sciences Utrecht.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
* - Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* - Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
* - Neither the name of the HU University of Applied Sciences Utrecht nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE HU UNIVERSITY OF APPLIED SCIENCES UTRECHT
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
* GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
* OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/

#ifndef LOGGING_SHARED_OBJECT_H
#define LOGGING_SHARED_OBJECT_H

#include "SharedObject.hpp"
#include <mutex>
#include <iostream>

/// Class LoggingSharedObject
/// This class is used to log when an object is claimed and released. 
/// \authors Koen van der Kruk
/// \version 1.0
/// \date 1-4-2016
template<typename T>
class LoggingSharedObject : public SharedObject<T> {
public:

	/// Constructs the LoggingSharedObject with data as input
	/// \param data_input The input data the loggingsharedobject can use to lock and unlock
	/// \return A new LoggingSharedObject
	LoggingSharedObject(T& data_input) :
		SharedObject<T>(data_input)
	{
	}

protected:

	/// This will claim the current object and it's data. This will also print out when the object is currently claimed.
	void claim() override {
		std::cout << "Object is currently claimed. " << std::endl;
		lock_object.lock();
	}
	
	/// This will release the current object and it's data. This will also print out when the object is currently released.
	void release() override {
		std::cout << "Object is currently released. " << std::endl;
		lock_object.unlock();
	}
private:
	/// Internal mutex to make sure the threads do not interfere with each other.
	std::mutex lock_object;
};

#endif
