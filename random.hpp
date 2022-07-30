#include <vector>
#include <random>

namespace gutil{ 
    std::vector<double> NormalVec(int size){
        std::vector<double> vec(size);
        std::mt19937 gen(std::random_device{}());
        std::normal_distribution<> dist {};

        for (int i=0; i<size; ++i){
            vec[i] = dist(gen);
        }
        return vec;
    }

}