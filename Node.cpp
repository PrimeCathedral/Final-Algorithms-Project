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

Node::Node() : value{0}, init_time{0}, final_time{0}, distance{MAX_DISTANCE}, color{"white"}, predecesor{nullptr} {}
Node::Node(int new_value) : value{new_value}, init_time{0}, final_time{0}, distance{MAX_DISTANCE}, color{"white"}, predecesor{nullptr} {}
Node::Node(const Node& to_copy) : value{to_copy.get_value()}, init_time{to_copy.get_init_time()}, final_time{to_copy.get_final_time()}, distance{to_copy.get_distance()}, color{to_copy.get_color()}, predecesor{to_copy.get_predecesor()} {}
Node::~Node() {
  delete predecesor; // Keep an eye on this
}

void Node::operator = (const Node& to_copy) {
  color       = to_copy.get_color();
  init_time   = to_copy.get_init_time();
  final_time  = to_copy.get_final_time();
  distance    = to_copy.get_distance();
  color       = to_copy.get_color();
  predecesor  = to_copy.get_predecesor();
}
bool Node::operator == (const Node& to_compare) const {
  if (color       != to_compare.get_color()) return false;
  if (init_time   != to_compare.get_init_time()) return false;
  if (final_time  != to_compare.get_final_time()) return false;
  if (distance    != to_compare.get_distance()) return false;
  if (color       != to_compare.get_color()) return false;
  if (predecesor  != to_compare.get_predecesor()) return false;
  return true;
}