#include "metaprogramming.hpp"

int main(){
    static_assert(gutil::all_same<int, int, int>::value, "yes");
    static_assert(gutil::all_same<int, int, double>::value, "should fail to compile");
    return 0;
}