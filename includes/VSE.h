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
		
		int dim = 50;               // Dimension of the elements
	    	int max_elements = 400001;   // Maximum number of elements, should be known beforehand
	    	int M = 16;                 // Tightly connected with internal dimensionality of the data
	                                // strongly affects the memory consumption
	        std::string hnsw_path = "hnsw.bin";
	    	int ef_construction = 200;  // Controls index search speed/build speed tradeoff

    	// Initing index
    
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
		// Make Function to leverage HNSW to search for similarity
		
		
		
		
		void insertVec(const std::string& id, const std::vector<float>& embedding) {
    		vectorStorage[id] = embedding; // This will overwrite the existing vector if the key exists.
		}
		
		
		std::vector<float> getVec(const std::string& id) {
        	return vectorStorage[id];
    	}
    	
	std::unordered_map<std::string, std::vector<float>> loadEmbeddings(const std::string& filename) {
	    std::unordered_map<std::string, std::vector<float>> embeddings;
	    std::unordered_map<int, std::string> idToWord;
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
	    
	    hnswlib::L2Space space(dim);
    	hnswlib::HierarchicalNSW<float>* alg_hnsw = new hnswlib::HierarchicalNSW<float>(&space, max_elements, M, ef_construction);
		std::mt19937 rng;
    	rng.seed(47);
	    
	    int id = 0;
		for (const auto& pair : embeddings) {
		    const std::vector<float>& vecData = pair.second;  // Get the embedding vector
		    alg_hnsw->addPoint(vecData.data(), id);  // Add the embedding to the index
		    
		    id++;
		}	
		
		alg_hnsw->saveIndex(hnsw_path);
		
	
    	std::cout << "Index built and saved.\n";
    	return embeddings;
 	}
    /*A function to take a sentence, convert it to it's vector embeddings, average it out, compare it to another to see if
    similar or not | Mean Pooling*
	
	So I'd need embed a document, store it, accept a query from a user, embed it, do a similarity search and return the top k
	
	Use hnswlib index for storage
	
	Create and save Glove embeddings as index
	Accept document from user
	Embed document
	Accept query from user
	Embed query
	Use hnswlib to do similarity search on document in terms of query
	Return something most similar to the query
	
	
	std::vector<float> query_embedding = /* some query embedding (e.g., GloVe) ;
	std::vector<std::pair<int, float>> results = alg_hnsw.searchKnn(query_embedding.data(), 5);  // Find top 5 similar vectors
	
	for (const auto& result : results) {
	    std::cout << "ID: " << result.first << ", Similarity: " << result.second << std::endl;
	}
	*/
};
