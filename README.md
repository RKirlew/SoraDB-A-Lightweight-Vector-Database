# SoraDB - A Lightweight Vector Database

<p align="center">
  <img src="https://github.com/user-attachments/assets/fbb1bcfe-e2bd-454f-bcac-e62339805759" alt="SoraDB Image" width="500">
</p>

SoraDB is a custom-built vector storage engine designed to manage and query high-dimensional vector data. It provides core functionality for storing vectors, computing cosine similarity, and performing efficient searches based on similarity. SoraDB is ideal for use cases like recommendation systems, search engines, and AI-powered applications that require vector-based data retrieval.

## Project Structure

### 🗂️ **Vector Storage**
- Uses `std::unordered_map` to store vectors by their unique string IDs.

### 🔍 **Cosine Similarity**
- Computes similarity between vectors using cosine similarity for efficient nearest neighbor search.

### 🏆 **Top K Search**
- Will implement `findTopK` to return the top K most similar vectors based on a given query.

---

## To-Do List

### ✅ **Completed**:
- Store vectors using `unordered_map` (id → vector)
- Implement `cosineSimilarity` function for comparing vectors
- Set up basic `VSE` (Vector Storage Engine) class structure
- Begin implementing `findTopK` for searching based on cosine similarity

### ⏳ **In Progress / To Come**:
- Implement `findTopK` to return the top K most similar vectors for a query
- Implement `insert` function for adding vectors with unique IDs
- Add batch insert and search functionality for efficiency
- Implement multi-threaded search for faster query results
- Add support for metadata (e.g., tags, timestamps) alongside vectors
- Persist vector storage to disk (JSON or binary file format)
- Create a basic REST API for interfacing with the database (using a C++ framework)
- Build an example project using SoraDB (e.g., AI-powered FAQ search or image similarity search)
- Dockerize the vector database service for easy deployment
- Optimize query performance using Approximate Nearest Neighbor (ANN) techniques
