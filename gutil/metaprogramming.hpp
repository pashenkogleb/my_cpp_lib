#pragma once


#include <type_traits>

namespace gutil{

template <typename T, typename Arg, typename... Args> // check that all types after T are equal to T
struct all_same{
    static const bool value = std::is_same<T, Arg>::value && all_same<T, Args...>::value ;
};



template <typename T, typename Arg>
struct all_same<T, Arg>{
    static const bool value = std::is_same<T, Arg>::value;
};



}