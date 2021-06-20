#include "vector.hpp"
#include <vector>
#include <list>
#include <forward_list>

void putTestInfo(int& test_no, const std::string& outline)
{
  std::cout << "TEST No." << test_no++ << ": " << outline << std::flush;
}

int main()
{
  bool flg = 0;
  int test_no = 1;

  std::cout << "=== TEST VECTOR ===" << std::endl;

  putTestInfo(test_no, "Vector: default construction");
  try {
    ft::vector<int> vec;
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  // あとで実装
  putTestInfo(test_no, "vector: fill construction with 42, 42");
  try {
    ft::vector<int> vec(42, 42);
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: copy construction with default");
  try {
    std::vector<int> vec_std1;
    std::vector<int> vec_std2(vec_std1);
    ft::vector<int> vec_ft1;
    ft::vector<int> vec_ft2(vec_ft1);
    if (vec_ft1 != vec_ft2 || vec_ft2.capacity() != vec_std2.capacity() ||
        vec_ft2.size() != vec_std2.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  // あとで実装
  putTestInfo(test_no, "vector: copy construction with vec(42,42)");
  try {
    std::vector<int> vec_std1(42, 42);
    std::vector<int> vec_std2(vec_std1);
    ft::vector<int> vec_ft1(42, 42);
    ft::vector<int> vec_ft2(vec_ft1);
    std::vector<int>::iterator itr_std;
    ft::vector<int>::iterator itr_ft;
    for (itr_std = vec_std2.begin(), itr_ft = vec_ft2.begin();
    itr_std != vec_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("failed");
      }
    }
    std::vector<int>::const_iterator citr_std;
    // ft::vector<int>::const_iterator citr_ft;
    // for (citr_std = vec_std2.begin(), citr_ft = vec_ft2.begin();
    // citr_std != vec_std2.end(); ++citr_std, ++citr_ft) {
    //   if (*citr_std != *citr_ft) {
    //     throw std::runtime_error("failed");
    //   }
    // }
    // std::vector<int>::reverse_iterator ritr_std;
    // ft::vector<int>::reverse_iterator ritr_ft;
    // for (ritr_std = vec_std2.rbegin(), ritr_ft = vec_ft2.rbegin();
    // ritr_std != vec_std2.rend(); ++ritr_std, ++ritr_ft) {
    //   if (*ritr_std != *ritr_ft) {
    //     throw std::runtime_error("failed");
    //   }
    // }
    // std::vector<int>::const_reverse_iterator rcitr_std;
    // ft::vector<int>::const_reverse_iterator rcitr_ft;
    // for (rcitr_std = vec_std2.rbegin(), rcitr_ft = vec_ft2.rbegin();
    // rcitr_std != vec_std2.rend(); ++rcitr_std, ++rcitr_ft) {
    //   if (*rcitr_std != *rcitr_ft) {
    //     throw std::runtime_error("failed");
    //   }
    // }
    // if (vec_ft1 != vec_ft2 || vec_ft2.capacity() != vec_std2.capacity() ||
    //     vec_ft2.size() != vec_std2.size()) {
    //   throw std::runtime_error("failed");
    // }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector: range construction with iterator of vec(42,42)");
  try {
    std::vector<int> src(42, 21);
    std::vector<int> std_vec(src.begin(), src.end());
    ft::vector<int> ft_vec(src.begin(), src.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": "
                  << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector: range construction with iterator of lst(42,21)");
  try {
    std::list<int> src(42, 21);
    std::vector<int> std_vec(src.begin(), src.end());
    ft::vector<int> ft_vec(src.begin(), src.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": "
                  << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector: range construction with iterator of flst(42,21)");
  try {
    std::forward_list<int> src(42, 21);
    std::vector<int> std_vec(src.begin(), src.end());
    ft::vector<int> ft_vec(src.begin(), src.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": "
                  << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector: range construction with iterator of flst(42,21)");
  try {
    int src[10] = {0, 1, 2, 3, 42, 5, 6, 7, 8, 9};
    std::vector<int> std_vec(src, src + 10);
    ft::vector<int> ft_vec(src, src + 10);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": "
                  << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector: range construction with iterator of vec(42,42) (between "
              "begin() + 20 and end()");
  try {
    std::vector<int> src(42, 21);
    std::vector<int> std_vec(src.begin() + 20, src.end());
    ft::vector<int> ft_vec(src.begin() + 20, src.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": "
                  << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector: range construction with iterator of vec(42,42) (between "
              "begin() + 10 and end() - 10");
  try {
    std::vector<int> src(42, 21);
    std::vector<int> std_vec(src.begin() + 10, src.end() - 10);
    ft::vector<int> ft_vec(src.begin() + 10, src.end() - 10);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": "
                  << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  // あとで実装
  // putTestInfo(test_no,
  //             "vector: copy construction with vec(42,42) with cap(84)");
  // try {
  //   std::vector<int> vec_std1(42, 42);
  //   vec_std1.reserve(84);
  //   std::vector<int> vec_std2(vec_std1);
  //   ft::vector<int> vec_ft1(42, 42);
  //   vec_ft1.reserve(84);
  //   ft::vector<int> vec_ft2(vec_ft1);
  //   for (size_t idx = 0; idx < vec_std2.size(); idx++) {
  //     if (vec_std2[idx] != vec_ft2[idx]) {
  //       throw std::runtime_error("failed");
  //     }
  //   }
  //   if (vec_ft1 != vec_ft2 || vec_ft2.capacity() != vec_std2.capacity() ||
  //       vec_ft2.size() != vec_std2.size()) {
  //     throw std::runtime_error("failed");
  //   }
  // } catch (std::exception& e) {
  //   throw std::runtime_error("failed");
  // }
  // std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: check vec1 == vec2 (default construction");
  try {
    ft::vector<int> vec1;
    ft::vector<int> vec2;
    if (!(vec1 == vec2)) {
      throw std::runtime_error("should be true");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // あとで実装
  // putTestInfo(test_no, "vector: check vec1(42,42) == vec2(42,42)");
  // try {
  //   ft::vector<int> vec1(42, 42);
  //   ft::vector<int> vec2(42, 42);
  //   if (!(vec1 == vec2)) {
  //     throw std::runtime_error("should be true");
  //   }
  // } catch (std::exception& e) {
  //   throw std::runtime_error(e.what());
  // }
  // std::cout << " => OK :)" << std::endl;

  // putTestInfo(test_no, "vector: check vec1(42,42) == vec2(21,42)");
  // try {
  //   ft::vector<int> vec1(42, 42);
  //   ft::vector<int> vec2(21, 42);
  //   if (vec1 == vec2) {
  //     throw std::runtime_error("should not be true");
  //   }
  // } catch (std::exception& e) {
  //   throw std::runtime_error(e.what());
  // }
  // std::cout << " => OK :)" << std::endl;

  // putTestInfo(test_no, "vector: check vec1(42,42) == vec2(42,21)");
  // try {
  //   ft::vector<int> vec1(42, 42);
  //   ft::vector<int> vec2(42, 21);
  //   if (vec1 == vec2) {
  //     throw std::runtime_error("should not be true");
  //   }
  // } catch (std::exception& e) {
  //   throw std::runtime_error(e.what());
  // }
  // std::cout << " => OK :)" << std::endl;

  // putTestInfo(test_no, "vector: vec1(42,42) == vec2(42,42) but capacity diffs");
  // try {
  //   ft::vector<int> vec1(42, 42);
  //   ft::vector<int> vec2(42, 42);
  //   vec2.reserve(84);
  //   // std::cout << "\nvec1.capacity() = " << vec1.capacity() << std::endl;
  //   // std::cout << "vec2.capacity() = " << vec2.capacity() << std::endl;
  //   // std::cout << "vec1 == vec2: " << (vec1 == vec2) << std::endl;
  //   if (vec1 != vec2) {
  //     throw std::runtime_error("should be true");
  //   }
  // } catch (std::exception& e) {
  //   throw std::runtime_error(e.what());
  // }
  // std::cout << " => OK :)" << std::endl;

  // putTestInfo(test_no, "vector: check vec1 = vec2(42,42)");
  // try {
  //   ft::vector<int> vec1;
  //   ft::vector<int> vec2(42, 42);
  //   vec1 = vec2;
  //   if (vec1 != vec2) {
  //     throw std::runtime_error("should not be equal");
  //   }
  // } catch (std::exception& e) {
  //   throw std::runtime_error("failed");
  // }
  // std::cout << " => OK :)" << std::endl;

  // putTestInfo(test_no, "vector: check vec1 = vec2(42,42) with 84 capacity");
  // try {
  //   ft::vector<int> vec1;
  //   ft::vector<int> vec2(42, 42);
  //   vec2.reserve(84);
  //   vec1 = vec2;
  //   // std::cout << "\nvec1.capacity() = " << vec1.capacity() << std::endl;
  //   // std::cout << "vec2.capacity() = " << vec2.capacity() << std::endl;
  //   if (vec1 != vec2) {
  //     throw std::runtime_error("should not be equal");
  //   }
  // } catch (std::exception& e) {
  //   throw std::runtime_error("failed");
  // }
  // std::cout << " => OK :)" << std::endl;

  // putTestInfo(test_no, "vector: check vec1(42, 42) = vec2");
  // try {
  //   ft::vector<int> vec1(42, 42);
  //   ft::vector<int> vec2;
  //   vec1 = vec2;
  //   if (!(vec1 == vec2)) {
  //     throw std::runtime_error("should be equal");
  //   }
  // } catch (std::exception& e) {
  //   throw std::runtime_error("failed");
  // }
  // std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: size() of empty vector construct with default");
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    if (std_vec.size() != ft_vec.size()) {
      throw std::exception();
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  // putTestInfo(test_no, "vector: size() of fill construction with 42, 42");
  // try {
  //   std::vector<int> std_vec(42, 42);
  //   ft::vector<int> ft_vec(42, 42);
  //   if (std_vec.size() != ft_vec.size()) {
  //     throw std::exception();
  //   }
  // } catch (std::exception& e) {
  //   throw std::runtime_error("failed");
  // }
  // std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector: max_size() of empty vector construct with default");
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    if (std_vec.max_size() != ft_vec.max_size()) {
      throw std::exception();
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  // putTestInfo(test_no, "vector: max_size() of fill construction with 42, 42");
  // try {
  //   std::vector<int> std_vec(42, 42);
  //   ft::vector<int> ft_vec(42, 42);
  //   if (std_vec.max_size() != ft_vec.max_size()) {
  //     throw std::exception();
  //   }
  // } catch (std::exception& e) {
  //   throw std::runtime_error("failed");
  // }
  // std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector: capacity() of empty vector construct with default");
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    if (std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  // putTestInfo(test_no, "vector: capacity() of fill construction with 42, 42");
  // try {
  //   std::vector<int> std_vec(42, 42);
  //   ft::vector<int> ft_vec(42, 42);
  //   if (std_vec.capacity() != ft_vec.capacity()) {
  //     std::cout << std_vec.capacity() << std::endl;
  //     throw std::exception();
  //   }
  // } catch (std::exception& e) {
  //   throw std::runtime_error("failed");
  // }
  // std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector: empty() of empty vector construct with default");
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    if (std_vec.empty() != ft_vec.empty()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  // putTestInfo(test_no, "vector: empty() of fill construction with 42, 42");
  // try {
  //   std::vector<int> std_vec;
  //   ft::vector<int> ft_vec;
  //   if (std_vec.empty() != ft_vec.empty()) {
  //     throw std::runtime_error("failed");
  //   }
  // } catch (std::exception& e) {
  //   throw std::runtime_error("failed");
  // }
  // std::cout << " => OK :)" << std::endl;

  // putTestInfo(test_no, "Vector: vec[0] (int) of fill construction with 42, 42");
  // flg = 0;
  // try {
  //   std::vector<int> std_vec(42, 42);
  //   ft::vector<int> ft_vec(42, 42);
  //   int std_res = std_vec[0];
  //   int ft_res = ft_vec[0];
  //   if (std_res != ft_res) {
  //     throw std::runtime_error("failed");
  //   }
  // } catch (std::exception& e) {
  //   throw std::runtime_error(e.what());
  // }
  // std::cout << " => OK :)" << std::endl;

  // putTestInfo(test_no,
  //             "Vector: vec[21] (int) of fill construction with 42, 42");
  // flg = 0;
  // try {
  //   std::vector<int> std_vec(42, 42);
  //   ft::vector<int> ft_vec(42, 42);
  //   int std_res = std_vec[21];
  //   int ft_res = ft_vec[21];
  //   if (std_res != ft_res) {
  //     throw std::runtime_error("failed");
  //   }
  // } catch (std::exception& e) {
  //   throw std::runtime_error(e.what());
  // }
  // std::cout << " => OK :)" << std::endl;

  // putTestInfo(test_no,
  //             "Vector: vec[40] (int) of fill construction with 42, 42");
  // flg = 0;
  // try {
  //   std::vector<int> std_vec(42, 42);
  //   ft::vector<int> ft_vec(42, 42);
  //   int std_res = std_vec[40];
  //   int ft_res = ft_vec[40];
  //   if (std_res != ft_res) {
  //     throw std::runtime_error("failed");
  //   }
  // } catch (std::out_of_range& e) {
  //   throw std::runtime_error(e.what());
  // }
  // std::cout << " => OK :)" << std::endl;

  // putTestInfo(test_no,
  //             "Vector: assign vec[i] = i with constructed with 42, 42");
  // flg = 0;
  // try {
  //   std::vector<int> std_vec(42, 42);
  //   ft::vector<int> ft_vec(42, 42);
  //   for (int i = 0; i < 42; i++) {
  //     std_vec[i] = i;
  //     ft_vec[i] = i;
  //     if (std_vec[i] != ft_vec[i]) {
  //       throw std::runtime_error("failed");
  //     }
  //   }
  // } catch (std::out_of_range& e) {
  //   throw std::runtime_error(e.what());
  // }
  // std::cout << " => OK :)" << std::endl;

  // putTestInfo(test_no,
  //             "Vector: vec[0] (const int) of fill construction with 42, 42");
  // flg = 0;
  // try {
  //   std::vector<int> std_vec(42, 42);
  //   ft::vector<int> ft_vec(42, 42);
  //   const int std_res = std_vec[0];
  //   const int ft_res = ft_vec[0];
  //   if (std_res != ft_res) {
  //     throw std::runtime_error("failed");
  //   }
  // } catch (std::exception& e) {
  //   throw std::runtime_error(e.what());
  // }
  // std::cout << " => OK :)" << std::endl;

  // putTestInfo(test_no,
  //             "Vector: vec[21] (const int) of fill construction with 42, 42");
  // flg = 0;
  // try {
  //   std::vector<int> std_vec(42, 42);
  //   ft::vector<int> ft_vec(42, 42);
  //   const int std_res = std_vec[21];
  //   const int ft_res = ft_vec[21];
  //   if (std_res != ft_res) {
  //     throw std::runtime_error("failed");
  //   }
  // } catch (std::exception& e) {
  //   throw std::runtime_error(e.what());
  // }
  // std::cout << " => OK :)" << std::endl;

  // putTestInfo(test_no,
  //             "Vector: vec[40] (const int) of fill construction with 42, 42");
  // flg = 0;
  // try {
  //   std::vector<int> std_vec(42, 42);
  //   ft::vector<int> ft_vec(42, 42);
  //   const int std_res = std_vec[40];
  //   const int ft_res = ft_vec[40];
  //   if (std_res != ft_res) {
  //     throw std::runtime_error("failed");
  //   }
  // } catch (std::exception& e) {
  //   throw std::runtime_error(e.what());
  // }
  // std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: at(0) of default constructed vector");
  flg = 0;
  try {
    ft::vector<int> vec;
    std::cout << vec.at(0) << std::endl;
  } catch (std::out_of_range& e) {
    if (std::string(e.what()) == "vector") {
      flg = true;
    }
  }
  if (!flg) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  // putTestInfo(test_no, "Vector: at(0) of fill construction with 42, 42");
  // flg = 0;
  // try {
  //   std::vector<int> std_vec(42, 42);
  //   ft::vector<int> ft_vec(42, 42);
  //   if (std_vec.at(0) != ft_vec.at(0)) {
  //     throw std::runtime_error("failed");
  //   }
  // } catch (std::exception& e) {
  //   throw std::runtime_error(e.what());
  // }
  // std::cout << " => OK :)" << std::endl;

  // putTestInfo(test_no, "Vector: at(21) of fill construction with 42, 42");
  // flg = 0;
  // try {
  //   std::vector<int> std_vec(42, 42);
  //   ft::vector<int> ft_vec(42, 42);
  //   if (std_vec.at(21) != ft_vec.at(21)) {
  //     throw std::runtime_error("failed");
  //   }
  // } catch (std::exception& e) {
  //   throw std::runtime_error(e.what());
  // }
  // std::cout << " => OK :)" << std::endl;

  // putTestInfo(test_no, "Vector: at(41) of fill construction with 42, 42");
  // flg = 0;
  // try {
  //   std::vector<int> std_vec(42, 42);
  //   ft::vector<int> ft_vec(42, 42);
  //   if (std_vec.at(41) != ft_vec.at(41)) {
  //     throw std::runtime_error("failed");
  //   }
  // } catch (std::out_of_range& e) {
  // } catch (std::exception& e) {
  //   throw std::runtime_error(e.what());
  // }
  // std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: reserve(42) for default construction");
  flg = 0;
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std_vec.reserve(42);
    ft_vec.reserve(42);
    std_vec[21] = 21;
    ft_vec[21] = 21;
    std_vec[41] = 41;
    ft_vec[41] = 41;
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size() ||
        std_vec.max_size() != ft_vec.max_size() || std_vec[41] != ft_vec[41] ||
        std_vec[21] != ft_vec[21]) {
      std::cout << "21: " << std_vec[21] << ", " << ft_vec[21] << std::endl;
      std::cout << "24: " << std_vec[24] << ", " << ft_vec[24] << std::endl;
      std::cout << "41: " << std_vec[41] << ", " << ft_vec[41] << std::endl;
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // putTestInfo(test_no, "Vector: reserve(42) for construction with 42, 42");
  // flg = 0;
  // try {
  //   std::vector<int> std_vec(42, 42);
  //   ft::vector<int> ft_vec(42, 42);
  //   std_vec.reserve(42);
  //   ft_vec.reserve(42);
  //   std_vec[21] = 21;
  //   ft_vec[21] = 21;
  //   std_vec[41] = 41;
  //   ft_vec[41] = 41;
  //   if (std_vec.capacity() != ft_vec.capacity() ||
  //       std_vec.size() != ft_vec.size() ||
  //       std_vec.max_size() != ft_vec.max_size() || std_vec[41] != ft_vec[41] ||
  //       std_vec[21] != ft_vec[21]) {
  //     throw std::runtime_error("failed");
  //   }
  // } catch (std::exception& e) {
  //   throw std::runtime_error(e.what());
  // }
  // std::cout << " => OK :)" << std::endl;

  // putTestInfo(test_no, "Vector: reserve(84) for construction with 42, 42");
  // flg = 0;
  // try {
  //   std::vector<int> std_vec(42, 42);
  //   ft::vector<int> ft_vec(42, 42);
  //   std_vec.reserve(84);
  //   ft_vec.reserve(84);
  //   std_vec[21] = 21;
  //   ft_vec[21] = 21;
  //   std_vec[41] = 41;
  //   ft_vec[41] = 41;
  //   std_vec[83] = 83;
  //   ft_vec[83] = 83;
  //   if (std_vec.capacity() != ft_vec.capacity() ||
  //       std_vec.size() != ft_vec.size() ||
  //       std_vec.max_size() != ft_vec.max_size() || std_vec[41] != ft_vec[41] ||
  //       std_vec[21] != ft_vec[21] || std_vec[83] != ft_vec[83]) {
  //     // std::cout << "24: " << std_vec[24] << ", " << ft_vec[24] << std::endl;
  //     // std::cout << "41: " << std_vec[41] << ", " << ft_vec[41] << std::endl;
  //     // std::cout << "80: " << std_vec[83] << ", " << ft_vec[83] << std::endl;
  //     throw std::runtime_error("failed");
  //   }
  // } catch (std::exception& e) {
  //   throw std::runtime_error(e.what());
  // }
  // std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: reserve(INT_MAX) for default construction");
  flg = 0;
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std_vec.reserve(214748364);
    ft_vec.reserve(214748364);
    // std_vec.reserve(INT32_MAX);
    // ft_vec.reserve(INT32_MAX);
    std_vec[21] = 21;
    ft_vec[21] = 21;
    std_vec[41] = 41;
    ft_vec[41] = 41;
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size() ||
        std_vec.max_size() != ft_vec.max_size() || std_vec[41] != ft_vec[41] ||
        std_vec[21] != ft_vec[21]) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;





  return 0;
}