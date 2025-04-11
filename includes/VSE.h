#include <unordered_map>
#include <iostream>
#include <cmath>
#include <math.h>
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
		
		bool insertVec(std::string id,std::vector<float> embedding){
			
		}

};
