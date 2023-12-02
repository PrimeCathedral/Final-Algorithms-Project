#include <iostream>
#include <string>
// Getters
template <class T>
T Node<T>::get_name() const {
  return name;
}

template <class T>
std::string Node<T>::get_color() const {
  return color;
}

template <class T>
int Node<T>::get_distance() const {
  return distance;
}

template <class T>
Node<T> *Node<T>::get_predecesor() const {
  return predecesor;
}

// Setters

template <class T>
void Node<T>::set_name(T new_name) {
  name = new_name;
}

template <class T>
void Node<T>::set_color(std::string new_color) {
  color = new_color;
}

template <class T>
void Node<T>::set_distance(int new_distance) {
  distance = new_distance;
}

template <class T>
void Node<T>::set_predecesor(Node &new_predecesor) {
  predecesor = new_predecesor;
}

// Constructors
template <class T>
Node<T>::Node()
    : name{}, color{""}, distance{MAX_DISTANCE}, predecesor{nullptr} {}

template <class T>
Node<T>::Node(T new_name)
    : name{new_name},
      color{"white"},
      distance{MAX_DISTANCE},
      predecesor{nullptr} {}

template <class T>
Node<T>::Node(std::string new_color, int new_distance, Node &new_predecesor)
    : name{""},
      color{new_color},
      distance{new_distance},
      predecesor{new_predecesor} {}

template <class T>
Node<T>::Node(T new_name, std::string new_color, int new_distance,
              Node &new_predecesor)
    : name{new_name},
      color{new_color},
      distance{new_distance},
      predecesor{new_predecesor} {}

template <class T>
Node<T>::Node(const Node<T> &to_copy)
    : name{to_copy.get_name()},
      color{to_copy.get_color()},
      distance{to_copy.get_distance()},
      predecesor{to_copy.get_predecesor()} {}

template <class T>
Node<T>::~Node() {}

template <class T>
Node<T> &Node<T>::operator=(Node<T> &to_copy) {
  name = to_copy.get_name();
  color = to_copy.get_color();
  distance = to_copy.get_distance();
  predecesor = to_copy.get_predecesor();
  return *this;
}

// This section is placed here to allow for hashing of Nodes in unordered maps
// Although I understand what it is doing, I don't know the reason for every detail
// I need to check up on this more.
namespace std {
    template <class T>
    struct hash<Node<T>> {
        size_t operator () (const Node<T>& key) {
            return hash<std::string>()(key.get_name());
        }
    };
}