#include <memory>
#include <string>
#include <iostream>

template < typename T >
void destroy_at( T * location )
{
    location->~T() ;
}

int main()
{
  {
    std::allocator<std::string> a;
    // 生のメモリー確保
    // std::string [1]分のメモリーサイズ
    std::string * p = a.allocate(1) ;
    // 構築
    std::string * s = new(p) std::string("hello") ;
    std::cout << *s << std::endl;
    std::cout << *p << std::endl;
    // 明示的なデストラクター呼び出し
    // s->~basic_string() ;
    destroy_at(s);
    // メモリー解放
    a.deallocate( p, 1 ) ;
  }
  {
    std::allocator<std::string> a ;
    // allocator_traits型
    using traits = std::allocator_traits<decltype(a)> ;

    // 生のメモリー確保
    std::string * p = traits::allocate( a, 1 ) ;
    // 構築
    traits::construct( a, p, "hello");
    std::cout << *p << std::endl;
    // 破棄
    traits::destroy( a, p ) ;
    // メモリー解放
    traits::deallocate( a, p, 1 ) ;
  }

}
