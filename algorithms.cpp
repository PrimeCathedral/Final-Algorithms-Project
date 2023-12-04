#include <iostream>
#include <deque>
#include "Graph.hpp"
#include "Node.hpp"

using Adjacency_List_Map = std::unordered_map<Node*, std::vector<std::pair<Node*, int>>>;
using Vertices_Map = std::unordered_map<int, Node>;

Graph BFS(Graph& to_traverse, Node& source_node) {
    // Check if the source node has no adjacencies in the graph
    if (to_traverse.get_Adjacency_List().find(&source_node) == to_traverse.get_Adjacency_List().end()) {
        std::cout << "Given node has no adjacencies in Graph." << std::endl;
        return to_traverse;
    }

    // Check if the source node is in the graph vertices
    if (to_traverse.get_Vertices().find(source_node.get_value()) == to_traverse.get_Vertices().end()) {
        std::cout << "Given node has no adjacencies in Graph." << std::endl;
        return to_traverse;
    }

    // Create the Breadth-First Search (BFS) graph that is to be returned
    Graph BFS {to_traverse};

    // Preprocess Nodes in BFS Graph
    for (auto& Value_Node_pair : BFS.get_Vertices()) {
        Value_Node_pair.second.set_color("white");
        Value_Node_pair.second.set_distance(MAX_DISTANCE);
        Value_Node_pair.second.set_predecesor(nullptr);

        // Flag to know if the node is important to the BFS, primarily for when the tree is not connected
        Value_Node_pair.second.set_is_removable(true);
    }

    // Process the source node
    BFS.get_Vertices()[source_node.get_value()].set_color("gray");
    BFS.get_Vertices()[source_node.get_value()].set_distance(0);
    BFS.get_Vertices()[source_node.get_value()].set_predecesor(nullptr);
    BFS.get_Vertices()[source_node.get_value()].set_is_removable(false);

    // Create an empty queue Q
    std::vector<Node*> Q;
    Q.push_back(&BFS.get_Vertices()[source_node.get_value()]);

    // Perform BFS traversal
    while (!Q.empty()) {
        Node* current_Node = Q.front();
        Q.erase(Q.begin());

        // Explore adjacent nodes
        for (const auto& Target_Weight_pair : BFS.get_Adjacency_List()[current_Node]) {
            if (Target_Weight_pair.first->get_color() == "white") {
                Target_Weight_pair.first->set_color("gray");
                Target_Weight_pair.first->set_distance(current_Node->get_distance() + 1);
                // Target_Weight_pair.first->set_predecesor(Q.front()); // This line causes issues and is not necessary yet, so commented out
                Target_Weight_pair.first->set_is_removable(false);
                Q.push_back(Target_Weight_pair.first); // Might be an error here
            } else {
                // Remove pairs containing the current node from the adjacency list
                auto current_pair = std::remove_if(
                    BFS.get_Adjacency_List()[current_Node].begin(),
                    BFS.get_Adjacency_List()[current_Node].end(),
                    [&Target_Weight_pair](const std::pair<Node*, int>& element) {
                        return element.first == Target_Weight_pair.first;
                    }
                );
                BFS.get_Adjacency_List()[current_Node].erase(current_pair);
            }
        }

        // Set the color of the current node to black after exploration
        current_Node->set_color("black");
    }

    // Remove all non-essential nodes from the BFS graph
    for (auto it = BFS.get_Vertices().begin(); it != BFS.get_Vertices().end();) {
        if (it->second.get_is_removable()) {
            // Remove the node and associated pairs from the adjacency list
            BFS.get_Adjacency_List().erase(&BFS.get_Vertices()[it->second.get_value()]);
            it = BFS.get_Vertices().erase(it);
        } else {
            ++it;
        }
    }

    // Print the resulting adjacency list
    for (const auto& Source_Vector_pair : BFS.get_Adjacency_List()) {
        for (const auto& Target_Weight_pair : Source_Vector_pair.second) {
            std::cout   << "Source: " << Source_Vector_pair.first->get_value()
                        << " Target: " << Target_Weight_pair.first->get_value()
                        << " Weight: " << Target_Weight_pair.second << std::endl;
        }
    }

    // Return the BFS graph
    return BFS;
}