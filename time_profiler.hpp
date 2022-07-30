#pragma once
#include <string>
#include <chrono>
#include <unordered_map>
#include <iostream>

namespace gutil{

    struct TimeProfile{
        /*
        Start with new tag automatically means end 
        */
        std::chrono::steady_clock::time_point begin;
        std::unordered_map<std::string, double> times;
        std::string cur_string = "__Not Initialized";

        void Start(const std::string &tag){
            if (cur_string != "__Not Initialized"){
                End();
            }

            begin = std::chrono::steady_clock::now();
            cur_string = tag;

        }

        void End(){
            auto now = std::chrono::steady_clock::now();
            double ms = std::chrono::duration_cast<std::chrono::microseconds>(now - begin).count();
            double sec = ms /1000000;
            times[cur_string] +=sec;
            cur_string = "__Not Initialized";
        }

        void Result(){
            for (auto p: times){
                std::cout << p.first << " " << p.second << ",";
            }
            std::cout << std::endl;
        }

    };



}