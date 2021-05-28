namespace std {
    template <typename T>
    class allocator {
    public:
        typedef size_t    size_type;
        typedef ptrdiff_t difference_type;
        typedef T*        pointer;
        typedef const T*  const_pointer;
        typedef T&        reference;
        typedef const T&  const_reference;
        typedef T         value_type;

        template <typename U>
        struct rebind {
            typedef allocator<U> other;
        };

        allocator() throw() {}
        allocator(const allocater&) throw() {}
        template <typename U> allocator(const allocator<U>&) throw() {}

        ~allocator() throw() {}

        pointer allocate(size_type num, allocator<void>::const_pointer hint = 0)
        {
            return static_cast<pointer>(::operator new(num * sizeof(T)));
        }

        void deallocate(pointer p, size_type num)
        {
            ::operator delete(p);
        }

        void construct(pointer p, const T& value)
        {
            new((void*)p) T(value);
        }

        void destroy(pointer p)
        {
            ((T*)p)->~T();
        }

        pointer address(reference value) const { return &value; }
        const_pointer address(const_reference value) const { return &value; }

        size_type max_size() const throw()
        {
            return numeric_limits<size_t>::max() / sizeof(T);
        }
    };

    template <>
    class allocator<void> {
    public:
        typedef void*        pointer;
        typedef const void*  const_pointer;
        typedef void         value_type;

        template <typename U>
        struct rebind {
            typedef allocator<U> other;
        };
    };

    template <typename T1, typename T2>
    bool operator==(const allocator<T1>&, const allocator<T2>&) throw()
    {
        return true;
    }

    template <typename T1, typename T2>
    bool operator!=(const allocator<T1>&, const allocator<T2>&) throw()
    {
        return false;
    }
}