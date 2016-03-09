// No copy, no assign
class NotCopyable {
protected:
   constexpr NotCopyable() = default;
    ~NotCopyable() = default;

   NotCopyable( const NotCopyable& ) = delete;
   NotCopyable& operator=( const NotCopyable& ) = delete;
};
