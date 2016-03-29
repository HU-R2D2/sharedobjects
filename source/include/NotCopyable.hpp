#ifndef NO_COPY_H
#define NO_COPY_H

/// Class NotCopyable
/// Thic class is used to make sure the inherentenced classes can not be copied
/// \authors Alexander Freeman, Koen van der Kruk, Timo Assen, Christiaan van den Berg, Remco Ruttenberg
/// \version 1.0
/// \date 29-3-2016
class NotCopyable {
protected:

	/// Prevents the class from using the default constructor
	NotCopyable() = default;

	/// Prevents the class from being destructed
	~NotCopyable() = default;

	/// Prevents the class from being copied into a new object
	/// \param The origin class
	NotCopyable(const NotCopyable&) = delete;

	/// Prevents the assignment of the inheritanced class
	/// \param The origin class
	/// \return A new copy of the class
	NotCopyable& operator=(const NotCopyable&) = delete;
};

#endif
