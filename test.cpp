#include "time_profiler.hpp"
#include <unistd.h>

int main(){
    gutil::TimeProfile profiler;

    profiler.Start("test");

    sleep(1);

    profiler.Start("test2");
    sleep(2);

    profiler.End();

    profiler.Result();

    return 0;
}