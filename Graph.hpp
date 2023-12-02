#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#include "Node.hpp"

template <class T>
class Graph {
 private:
  // Set of vertices V
  std::vector<Node<T>> vertices;
  // Adjacency List
  std::unordered_map<T, std::vector<Node<T>>> adjacency_list;
  // Adjacency Matrix
  std::unordered_map<Node<T>, std::unordered_map<Node<T>, int>> adjacency_matrix;
  // Graph type (directed/undirected, weighted/unweighted)
  int graph_type;
  // (Optional) Path to CSV file
  std::string path_to_csv;
  // Create vertices

  // Create adjacency matrix
  std::unordered_map<Node<T>, std::unordered_map<Node<T>, int>> create_adjacency_matrix(
      std::string path_to_csv);
  // Create adjacency list

 public:
  std::vector<Node<T>> create_vertices(std::string path_to_csv);

  // Getters
  std::vector<Node<T>> get_vertices() const;
  std::unordered_map<T, std::vector<Node<T>>> get_adjacency_list() const;
  std::unordered_map<Node<T>, std::unordered_map<Node<T>, int>> get_adjacency_matrix() const;
  int get_graph_type() const;
  // Setters
  void set_vertices(std::vector<Node<T>>& new_vertices);
  void set_adjacency_list(
      std::unordered_map<T, std::vector<Node<T>>>& new_adjacency_list);
  void set_adjacency_matrix(
      std::unordered_map<Node<T>, std::unordered_map<Node<T>, int>>& new_adjacency_matrix);
  void set_graph_type(int new_graph_type);

  std::unordered_map<Node<T>, std::unordered_map<Node<T>, int>> create_adjacency_matrix(
      int graph_type, std::string path_to_csv);
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