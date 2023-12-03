#include "Graph.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "Node.hpp"

// Getters
template <class T>
std::unordered_map<T, std::vector<std::pair<Node<T>, int>>> Graph<T>::get_adjacency_list()
    const {
  return adjacency_list;
}

template <class T>
int Graph<T>::get_graph_type() const {
  return graph_type;
}

// Setters
template <class T>
void Graph<T>::set_adjacency_list(
    std::unordered_map<T, std::vector<std::pair<Node<T>, int>>>& new_adjacency_list) {
  adjacency_list = new_adjacency_list;
}

template <class T>
void Graph<T>::set_graph_type(int new_graph_type) {
  graph_type = new_graph_type;
}

// Constructors
template <class T>
Graph<T>::Graph()
    : adjacency_list{}, graph_type{1} {}

template <class T>
Graph<T>::Graph(const Graph<T>& to_copy): adjacency_list{to_copy.get_adjacency_list()}, graph_type{to_copy.get_graph_type()} {}

template <class T>
Graph<T>::Graph(std::string new_path_to_csv) {
  // Parse the input string
  // Cannot be null
  if (new_path_to_csv.empty()) {
    return;
  }
  // Must contain .csv extension
  if (new_path_to_csv.find(".csv") == -1) {
    return;
  }
  // Modify so it only contains file name, not full path
  std::string file;
  if (new_path_to_csv.rfind("/") != -1) {
    file = new_path_to_csv;
  } else {
    file = new_path_to_csv.substr(
        new_path_to_csv.rfind("/") + 1,
        new_path_to_csv.length() - new_path_to_csv.rfind("/"));
  }

  ///////////////////////////////////////////
  // This next section determines the type //
  // of graph contained in the CSV file.   //
  // 1: - directed - weighted              //
  // 2: + directed - weighted              //
  // 3: - directed + weighted              //
  // 6: + directed + weighted              //
  ///////////////////////////////////////////
  graph_type = 1;
  if (file.find("undirected") == std::string::npos) graph_type *= 2;
  if (file.find("unweighted") == std::string::npos) graph_type *= 3;

  // Create graph
  vertices = create_vertices(new_path_to_csv);

  // Create adjacency list
  adjacency_list = create_adjacency_list(new_path_to_csv);
  // Open CSV file
}

// template <class T>
// Graph<T>::~Graph();

// // Members
// template <class T>
// Graph& Graph<T>::operator=(const Graph& to_copy);

// template <class T>
// std::vector<Node<T>> Graph<T>::create_vertices(std::string path_to_csv) {
//   std::vector<Node<int>> vertices;

//   // Open CSV file
//   std::ifstream csv_file(path_to_csv);

//   // Helper variables
//   std::string line;
//   int val;
//   bool is_there{false};

//   // Ignore the header line
//   std::getline(csv_file, line);

//   // Read data, line by line
//   while (std::getline(csv_file, line)) {
//     // Create a stringstream of the current line
//     std::stringstream ss(line);

//     // Extract each value
//     while (ss >> val) {
//       // Set is_there to false
//       is_there = false;

//       // Make sure the vertex has not been created before creating it.
//       for (const auto& vertex : vertices) {
//         if (vertex.get_name() == val) is_there = true;
//       }

//       if (!(is_there)) vertices.emplace_back(Node<int>(val));

//       // if the next token is a comma, ignore it and move on
//       if (ss.peek() == ',') ss.ignore();
//     }
//   }
//   // Close the file
//   csv_file.close();
//   return vertices;
// }

template <class T>
std::unordered_map<Node<T>, std::vector<std::pair<Node<T>, int>>> Graph<T>::create_adjacency_list(std::string path_to_csv) {
  // Create map to place all vertices in
  std::unordered_map<T, Node<T>> Vertices;

  std::unordered_map<Node<T>, std::vector<std::pair<Node<T>, int>>> adjacency_list;


  // Open CSV file
  std::ifstream csv_file(path_to_csv);

  // Helper variables
  std::string line;
  int source, target, weight;


  // Ignore the header line
  std::getline(csv_file, line);

  // Read data, line by line
  while (std::getline(csv_file, line)) {
    // Create a stringstream of the current line
    std::stringstream ss(line);

    ss >> source;
    if (Vertices.find(source) == Vertices.end()) {
      Vertices[source] = Node<T>(source);
    }
    ss.ignore(); // The comma

    ss >> source;
    if (Vertices.find(source) == Vertices.end()) {
      Vertices[source] = Node<T>(source);
    }
  }
  // Close the file
  csv_file.close();
  return adjacency_list;
}
