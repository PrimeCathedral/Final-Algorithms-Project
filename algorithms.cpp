#include <iostream>
#include "Node.hpp"

using Adjacency_List = std::unordered_map<Node*, std::vector<std::pair<Node*, int>>>;
using Vertices = std::unordered_map<int, Node>;

Adjacency_List BFS();