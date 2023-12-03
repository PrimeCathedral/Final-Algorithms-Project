#include <iostream>
#include <string>
#include "Node.hpp"

// Getters
int Node::get_value()       const {
  return value;
}
int Node::get_init_time()   const {
  return init_time;
}
int Node::get_final_time()  const {
  return final_time;
}
int Node::get_distance()    const {
  return distance;
}
std::string Node::get_color() const {
  return color;
}
Node* Node::get_predecesor()  const {
  return predecesor;
}



// Setters
void Node::set_value(int new_value) {
  value = new_value;
}
void Node::set_init_time(int new_init_time) {
  init_time = new_init_time;
}
void Node::set_final_time(int new_final_time) {
  final_time = new_final_time;
}
void Node::set_distance(int new_distance) {
  distance = new_distance;
}
void Node::set_color(std::string new_color) {
  color = new_color;
}
void Node::set_predecesor(Node& new_predecesor) {
  predecesor = &new_predecesor;
}

Node::Node() : value{}, init_time{}, final_time{}, distance{}, color{}, predecesor{} {}
Node::Node(int new_value) : value{new_value}, init_time{}, final_time{}, distance{}, color{}, predecesor{} {}
Node::Node(const Node& to_copy) : value{to_copy.get_value()}, init_time{to_copy.get_init_time()}, final_time{to_copy.get_final_time()}, distance{to_copy.get_distance()}, color{to_copy.get_color()}, predecesor{to_copy.get_predecesor()} {}