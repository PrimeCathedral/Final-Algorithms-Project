#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>

#include "Node.hpp"

template <class T>
class Graph {
 private:
  // Adjacency List
  std::unordered_map<T, std::vector<std::pair<Node<T>, int>>> adjacency_list;
  // Graph type (directed/undirected, weighted/unweighted)
  int graph_type;
  // (Optional) Path to CSV file
  std::string path_to_csv;

 public:
  std::unordered_map<Node<T>, std::vector<std::pair<Node<T>, int>>> create_adjacency_list(std::string path_to_csv);

  // Getters
  std::unordered_map<Node<T>, std::vector<std::pair<Node<T>, int>>> get_adjacency_list() const;
  int get_graph_type() const;

  // Setters
  void set_adjacency_list(std::unordered_map<Node<T>, std::vector<std::pair<Node<T>, int>>>& new_adjacency_list);
  void set_graph_type(int new_graph_type);

  // Constructors
  Graph();
  Graph(const Graph& to_copy);
  Graph(std::string new_path_to_csv);
  //~Graph();
  // Members
  Graph& operator=(const Graph& to_copy);
};

#include "Graph.cpp"
#endif