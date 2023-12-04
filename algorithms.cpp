#include <iostream>
#include <deque>
#include "Graph.hpp"
#include "Node.hpp"

using Adjacency_List_Map = std::unordered_map<Node*, std::vector<std::pair<Node*, int>>>;
using Vertices_Map = std::unordered_map<int, Node>;

Graph BFS(const Graph& to_traverse, Node& source_node) {
    // // Check if Node is in graph
    // if (to_traverse.get_Adjacency_List().find(&source_node) == to_traverse.get_Adjacency_List().end()) {
    //     std::cout << "Given node has no adjacencies in Graph." << std::endl;
    //     return to_traverse;
    // }

    // Check if Node is in graph
    if (to_traverse.get_Vertices().find(source_node.get_value()) == to_traverse.get_Vertices().end()) {
        std::cout << "Given node has no adjacencies in Graph." << std::endl;
        return to_traverse;
    }

    // Create the Graph that is to be returned
    Graph BFS {to_traverse};

    Node* real_source_node = &BFS.get_Vertices()[source_node.get_value()];

    // Preprocess Nodes in BFS Graph
    for (auto& Value_Node_pair : BFS.get_Vertices()) {
        Value_Node_pair.second.set_color("white");
        Value_Node_pair.second.set_distance(MAX_DISTANCE);
        Value_Node_pair.second.set_predecesor(nullptr);

        // This needs to be here to know if the node is important to the BFS
        // Primarily for when the tree is not connected
        Value_Node_pair.second.set_is_removable(true);
    }

    // Process source node
    real_source_node->set_color("gray");
    real_source_node->set_distance(0);
    real_source_node->set_predecesor(nullptr);
    real_source_node->set_is_removable(false);
    

    // Create empty queue Q
    std::vector<Node*> Q;
    Q.push_back(real_source_node);

    while(!(Q.empty())) {
        
        Node* current_Node = Q.front();
        Q.erase(Q.begin());
        for (const auto& Target_Weight_pair : BFS.get_Adjacency_List()[current_Node]) {
            if (Target_Weight_pair.first->get_color() == "white") {
                Target_Weight_pair.first->set_color("gray");
                Target_Weight_pair.first->set_distance(current_Node->get_distance() + 1);
                Target_Weight_pair.first->set_predecesor(current_Node);
                Target_Weight_pair.first->set_is_removable(false);
                std::cout << "About to push" << std::endl;
                Q.push_back(Target_Weight_pair.first); // Might be an error here
                std::cout << "Pushed" << std::endl;
            } else {
                // BFS.get_Adjacency_List()[current_Node].erase(std::find(BFS.get_Adjacency_List().begin(), BFS.get_Adjacency_List().end(), Target_Weight_pair));
                auto current_pair = std::remove_if(
                    BFS.get_Adjacency_List()[current_Node].begin(),
                    BFS.get_Adjacency_List()[current_Node].end(),
                    [&Target_Weight_pair](const std::pair<Node*, int>& element) {return element.first == Target_Weight_pair.first;} );

                BFS.get_Adjacency_List()[current_Node].erase(current_pair);
            }
        }
        current_Node->set_color("black");
    }

    // // Remove all non-essential nodes
    // for (const auto& Key_Value_pair : BFS.get_Vertices()) {
    //     if (Key_Value_pair.second.get_is_removable()) {
    //         BFS.get_Vertices().erase(Key_Value_pair.first);
    //     }
    // }

    // Remove all non-essential nodes
    for (auto it = BFS.get_Vertices().begin(); it != BFS.get_Vertices().end();) {
        if (it->second.get_is_removable()) {
            it = BFS.get_Vertices().erase(it);
        } else {
            ++it;
        }
    }

    for(const auto& Source_Vector_pair : BFS.get_Adjacency_List()) {
        for (const auto& Target_Weight_pair : Source_Vector_pair.second) {
            std::cout   << "Source: " << Source_Vector_pair.first->get_value()
                        << " Target: " << Target_Weight_pair.first->get_value()
                        << " Weight: " << Target_Weight_pair.second << std::endl;
        }
    }

    return BFS;
}