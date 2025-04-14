#include <iostream>
#include <vector>
#include "VSE.h"

int main(int argc, char** argv) {
    VSE v;
    
    
    std::vector<float> a = {1.0f, 2.0f, 3.0f};
    std::vector<float> b = {4.0f, 5.0f, 6.0f};
    
    std::cout << "Similarity score = " << v.cosineSimilarity(a, b) << std::endl;
   	auto embeddings = v.loadEmbeddings("embeddings/glove.6B.50d.txt");

    std::string query = "banana";
    if (embeddings.count(query)) {
        std::cout << query << " ? [ ";
        for (float v : embeddings[query]) {
            std::cout << v << " ";
        }
        std::cout << "]\n";
    } else {
        std::cout << query << " not found.\n";
    }
 
 
 	auto results = v.findTopKFromText("what", 5);
	for (const auto& result : results) {
	    const std::string& word = result.first;
	    float dist = result.second;
	    
	    std::cout << word << " with distance: " << dist << "\n";
	}
 	
 
    
    return 0;
}

