#include <iostream>
#include "Graph.hpp"

template<class T>
std::unordered_map<T, std::vector<std::pair<Node<T>,int>>> BFS(const Graph<T>& to_traverse, T node) {
    // Make sure the given node is in the given graph
    if (to_traverse.get_adjacency_list().find(node) == to_traverse.get_adjacency_list().end()) {
        std::cout << "BFS: source node not in graph." << std::endl; 
        return to_traverse.get_adjacency_list();
    } 

    // Make the return map
    std::unordered_map<T, std::vector<std::pair<Node<T>,int>>> bfs;

    // Preprocessing
    for (const auto& node : to_traverse.get_vertices()) {
        node.set_color("white");
        node.set_distance(MAX_DISTANCE);
        node.set_predecesor(nullptr);

        // Also find source node. This will make it easier moving forwards
        if (node.get_name() == node) Node<T>& source_node = 
    }

    to_traverse.get_adjacency_list()
}