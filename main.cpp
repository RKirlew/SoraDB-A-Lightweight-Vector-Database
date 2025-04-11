#include <iostream>
#include <vector>
#include "VSE.h"

int main(int argc, char** argv) {
    VSE v;
    
    
    std::vector<float> a = {1.0f, 2.0f, 3.0f};
    std::vector<float> b = {4.0f, 5.0f, 6.0f};
    
    std::cout << "Similarity score = " << v.cosineSimilarity(a, b) << std::endl;
    
    return 0;
}
