#pragma once


#include <type_traits>

namespace gutil{

template <typename T, typename... Args>
struct all_same;

template <typename T>
struct all_same<T>{
    static const bool value = true; // if just one type lets that it is true 
};  

template <typename T, typename Arg, typename... Args> // check that all types after T are equal to T
struct all_same<T, Arg, Args...>{
    static const bool value = std::is_same<T, Arg>::value && all_same<T, Args...>::value ;
};

}