#ifndef NODE_HPP
#define NODE_HPP
#define MAX_DISTANCE 9999999
#include <iostream>
#include <string>

template <class T>
class Node {
 private:
  T name;
  std::string color;
  int distance;
  Node<T> *predecesor;

 public:
  // Getters
  T get_name() const;
  std::string get_color() const;
  int get_distance() const;
  Node<T> *get_predecesor() const;

  // Setters
  void set_name(T new_name);
  void set_color(std::string new_color);
  void set_distance(int new_distance);
  void set_predecesor(Node &new_predecesor);

  // Constructors
  Node();
  Node(T new_name);
  Node(std::string new_color, int new_distance, Node &predecesor);
  Node(T new_name, std::string new_color, int new_distance, Node &predecesor);
  Node(const Node<T> &to_copy);
  ~Node();

  // Members
  Node<T> &operator=(Node<T> &to_copy);
};

#include "Node.cpp"
#endif