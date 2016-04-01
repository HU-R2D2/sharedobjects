///
/// ______      _          ______                          
/// | ___ \    | |         | ___ \                         
/// | |_/ /___ | |__   ___ | |_/ /___  ___  ___ _   _  ___ 
/// |    // _ \| '_ \ / _ \|    // _ \/ __|/ __| | | |/ _ \
/// | |\ \ (_) | |_) | (_) | |\ \  __/\__ \ (__| |_| |  __/
/// \_| \_\___/|_.__/ \___/\_| \_\___||___/\___|\__,_|\___|
///                                                       
///
/// @file NotCopyable.hpp
/// @date Created: 1-4-2016
/// @version 1.0
///
/// @author Koen van der Kruk, Alexander Freeman
///
/// @section LICENSE
/// License: newBSD
///
/// Copyright © 2016, HU University of Applied Sciences Utrecht.
/// All rights reserved.
///
/// Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
/// - Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
/// - Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
/// - Neither the name of the HU University of Applied Sciences Utrecht nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
///
/// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
/// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
/// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
/// ARE DISCLAIMED. IN NO EVENT SHALL THE HU UNIVERSITY OF APPLIED SCIENCES UTRECHT
/// BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
/// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
/// GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
/// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
/// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
/// OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

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
