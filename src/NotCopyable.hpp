#ifndef NO_COPY_H
#define NO_COPY_H


class NotCopyable {
protected:
   constexpr NotCopyable() = default;
    ~NotCopyable() = default;

   NotCopyable( const NotCopyable& ) = delete;
   NotCopyable& operator=( const NotCopyable& ) = delete;
};

#endif