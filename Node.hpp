#ifndef NODE_HPP
#define NODE_HPP
#define MAX_DISTANCE 9999999
#include <iostream>
#include <string>


class Node {
  private:
    int value, init_time, final_time, distance;
    std::string color;
    Node* predecesor;
  public:
    // Getters
    int get_value() const;
    int get_init_time() const;
    int get_final_time() const;
    int get_distance() const;
    std::string get_color() const;
    Node* get_predecesor() const;

    // Setters
    void set_value(int new_value);
    void set_init_time(int new_init_time);
    void set_final_time(int new_final_time);
    void set_distance(int new_distance);
    void set_color(std::string new_color);
    void set_predecesor(Node& new_predecesor);

    // Constructors
    Node();
    Node(int new_value);
    Node(const Node& to_copy);
    ~Node();

    // Methods
    void operator = (const Node& to_copy);
    bool operator == (const Node& to_compare) const;
};


// This section is for being able to hash nodes int a hash-map
namespace std {
  template<>
  struct hash<Node> {
    auto operator () (const Node& key) const -> size_t {
      return hash<int>()(key.get_value());
    }
  };
}

#endif