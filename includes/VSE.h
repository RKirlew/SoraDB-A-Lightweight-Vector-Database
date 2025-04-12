#include <unordered_map>
#include <iostream>
#include <cmath>
#include <math.h>
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
		 	float sumOfVecs=0; 
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
    	
    	std::string readEmbeddingsFile(std::string soraFile){
    		std::map<std::string, std::vector<float>> embeddings;
    		std::string line;
    		 // I want to store in a vector that is usable, a map with a string to a vector vec[0]->string vec[1]->vector
    		 std::ifstream file_in(soraFile);
   			 if (!file_in) {
					std::cerr << "Could not open the file.\n";
        			return "Could not open the file.\n";
				}
			while(std::getline(file_in,line)){
				std::istringstream iss(line);
			}
    		return "The file data";
		}

};
