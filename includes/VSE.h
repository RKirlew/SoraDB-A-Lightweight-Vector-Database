#include <unordered_map>
#include <iostream>
#include <cmath>
#include <math.h>
#include <map>
#include <sstream>
#include "hnswlib/hnswlib.h"
#include <fstream>
class VSE{
	public:
		 std::unordered_map<std::string, std::vector<float>> vectorStorage;
		 
		 std::vector<std::pair<std::string, float>> findTopK(const std::vector<float>& query, size_t k){
		 	
		 }
		 float cosineSimilarity(const std::vector<float>& a, const std::vector<float>& b){
		 	// + 1e-8, avoid division by zero
		 	float similarityScore;
		 	float magnitude;
		 	float sumOfVecs=0; //C8FA-9B27
		 	float magnitudeSumA=0;
		 	float magnitudeSumB=0;

		 	for (size_t i = 0; i < a.size(); ++i) {
        			sumOfVecs += a[i] * b[i];
    			}
    		for (size_t j = 0; j < a.size(); ++j) {
        			magnitudeSumA +=std::pow(a[j], 2);
        			magnitudeSumB +=std::pow(b[j], 2);

    			}	
    			similarityScore=sumOfVecs/(std::sqrt(magnitudeSumA)*std::sqrt(magnitudeSumB)+ 1e-8);
    			
    			return similarityScore;
		 }
		
		void insertVec(const std::string& id, const std::vector<float>& embedding) {
    		vectorStorage[id] = embedding; // This will overwrite the existing vector if the key exists.
		}
		
		
		std::vector<float> getVec(const std::string& id) {
        	return vectorStorage[id];
    	}
    	
	std::unordered_map<std::string, std::vector<float>> loadEmbeddings(const std::string& filename) {
	    std::unordered_map<std::string, std::vector<float>> embeddings;
	    std::ifstream file(filename);
	    
	    if (!file.is_open()) {
	        std::cerr << "Failed to open the embedding file: " << filename << std::endl;
	        return embeddings;
	    }

    	std::string line;
    	while (std::getline(file, line)) {
	        std::istringstream iss(line);
	        std::string word;
	        iss >> word;
	
	        std::vector<float> vec;
	        float value;
	        while (iss >> value) {
	            vec.push_back(value);
	        }
	
	        if (!word.empty() && !vec.empty()) {
	            embeddings[word] = vec;
	        }
	    }
    	return embeddings;
 	}

};
