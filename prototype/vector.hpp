#ifndef VECTOR
#define VECTOR

#include <iterator>
#include <memory>
#include <iostream>

template <typename T, typename Allocator = std::allocator<T> >
class vector {
 public:
  typedef std::size_t  size_type;

  T*         elems_;
  Allocator  allocator_;
  size_type  size_;


  vector(size_type size, const T& val, const Allocator& a = Allocator())
    : allocator_(a), size_(size)
  {
    // 必要なメモリ領域を確保する
    elems_ = allocator_.allocate(size);
    
    // オブジェクトを生成する
    for (size_type i = 0; i < size_; ++i) {
        allocator_.construct(&elems_[i], val);
    }
  }

  ~vector()
  {
    // オブジェクトを解体する
    for (size_type i = 0; i < size_; ++i) {
        allocator_.destroy(&elems_[i]);
    }

    // メモリ領域を解放する
    allocator_.deallocate(elems_, 1);
  }
};

// template<typename _Tp, typename _Alloc = std::allocator<_Tp> >
// class vector
// {
//   typedef _Vector_base<_Tp, _Alloc>			_Base;
//   typedef typename _Base::_Tp_alloc_type		_Tp_alloc_type;
//   typedef __gnu_cxx::__alloc_traits<_Tp_alloc_type>	_Alloc_traits;

// public:
//   typedef size_t					size_type;
//   typedef ptrdiff_t					difference_type;
//   typedef typename _Alloc_traits::reference		reference;
//   typedef typename _Alloc_traits::const_reference	const_reference;
//   typedef __gnu_cxx::__normal_iterator<pointer, vector> iterator;
//   typedef __gnu_cxx::__normal_iterator<const_pointer, vector> const_iterator;
//   typedef std::reverse_iterator<iterator>		reverse_iterator;
//   typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
//   typedef _Tp					value_type;
//   typedef _Alloc					allocator_type;
//   typedef typename _Base::pointer			pointer;
//   typedef typename _Alloc_traits::const_pointer	const_pointer;
// };

#endif /* VECTOR */