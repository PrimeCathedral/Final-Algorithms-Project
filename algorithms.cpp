#include <iostream>
#include <deque>
#include <list>
#include <algorithm>
#include <set>
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
            if (Target_Weight_pair.first->get_value() == 5) std::cout << "hello" << std::endl;
            if (Target_Weight_pair.first->get_color() == "white") {
                Target_Weight_pair.first->set_color("gray");
                Target_Weight_pair.first->set_distance(current_Node->get_distance() + 1);
                Target_Weight_pair.first->set_predecesor(Q.front()); // This line causes issues and is not necessary yet, so commented out
                Target_Weight_pair.first->set_is_removable(false);
                Q.push_back(Target_Weight_pair.first); // Might be an error here
            } 
            // else {
            //     // Remove pairs containing the current node from the adjacency list
            //     auto current_pair = std::remove_if(
            //         BFS.get_Adjacency_List()[current_Node].begin(),
            //         BFS.get_Adjacency_List()[current_Node].end(),
            //         [&Target_Weight_pair](const std::pair<Node*, int>& element) {
            //             return element.first == Target_Weight_pair.first;
            //         }
            //     );
            //     BFS.get_Adjacency_List()[current_Node].erase(current_pair);
            // }
        }

        // Set the color of the current node to black after exploration
        current_Node->set_color("black");
    }

    // // Remove all non-essential nodes from the BFS graph
    // for (auto it = BFS.get_Vertices().begin(); it != BFS.get_Vertices().end();) {
    //     if (it->second.get_is_removable()) {
    //         // Remove the node and associated pairs from the adjacency list
    //         BFS.get_Adjacency_List().erase(&BFS.get_Vertices()[it->second.get_value()]);
    //         it = BFS.get_Vertices().erase(it);
    //     } else {
    //         ++it;
    //     }
    // }

    // Print the resulting adjacency list
    std::cout << std::endl << "BFS GRAPH" << std::endl;
    for (const auto& Source_Vector_pair : BFS.get_Adjacency_List()) {
        for (const auto& Target_Weight_pair : Source_Vector_pair.second) {
            std::cout   << "Address: "  << &Source_Vector_pair.first
                        << ", Source: "   << Source_Vector_pair.first->get_value()
                        << ", Address: "  << &Target_Weight_pair.first
                        << ", Target: "  << Target_Weight_pair.first->get_value()
                        << ", Weight: "  << Target_Weight_pair.second << std::endl;
        }
    }

    // Return the BFS graph
    return BFS;
}


// Function to perform DFS visit on a graph starting from a given source node
// The function uses recursion to traverse the graph depth-first
Graph& DFS_visit(Graph& DFS, Node& source_node, int& time, bool& is_cycled) {
    // Mark the source node as visited and set initial time
    source_node.set_color("gray");
    source_node.set_init_time(++time);

    // Debugging: Check if the source node's address is in the DFS adjacency list
    if (DFS.get_Adjacency_List().find(&source_node) == DFS.get_Adjacency_List().end()) {
        std::cout << "Source node has no adjacencies in DFS adjacency list." << std::endl;
        std::cout << "Node address: " << &source_node << ", Value: " << source_node.get_value() << std::endl;
    }

    // Explore adjacent nodes
    for (auto& vertex : DFS.get_Adjacency_List()[&source_node]) {
        // Check if the adjacent node is not visited
        if (vertex.first->get_color() == "white") {
            // Set the source node as the predecessor of the adjacent node
            vertex.first->set_predecesor(&source_node);

            // Recursive call to DFS_visit for the adjacent node
            DFS_visit(DFS, *vertex.first, time, is_cycled);
        } else if (vertex.first->get_color() == "gray") {
            is_cycled = true;
        }
    }

    // Mark the source node as fully explored and set final time
    source_node.set_color("black");
    source_node.set_final_time(++time);
    
    return DFS;
}

Graph DFS(Graph& to_traverse) {
    Graph DFS {to_traverse};
    bool is_cycled {false};

    for (auto& vertex : DFS.get_Vertices()) {
        vertex.second.set_color("white");
        vertex.second.set_predecesor(nullptr);
    }

    int time {0};

    for (auto& vertex : DFS.get_Vertices()) {
        if (vertex.second.get_color() == "white") {
            DFS_visit(DFS, vertex.second, time, is_cycled);
        }
    }

    std::cout << std::endl << "DFS Graph" << std::endl;
    for (auto& SVP : DFS.get_Vertices()) {
        std::cout   << "Node address: "     << &SVP.second                   
                    << ", Value: "          << SVP.second.get_value() 
                    << ", Initial time: "   << SVP.second.get_init_time()
                    << ", Final time: "     << SVP.second.get_final_time() 
                    << std::endl;
    }

    return DFS;
}
bool Cycle_DFS(const Graph& to_traverse){
    Graph DFS {to_traverse};
    bool is_cycled {false};

    for (auto& vertex : DFS.get_Vertices()) {
        vertex.second.set_color("white");
        vertex.second.set_predecesor(nullptr);
    }

    int time {0};

    for (auto& vertex : DFS.get_Vertices()) {
        if (vertex.second.get_color() == "white") {
            DFS_visit(DFS, vertex.second, time, is_cycled);
        }
    }

    std::cout << std::endl << "DFS Graph" << std::endl;
    for (auto& SVP : DFS.get_Vertices()) {
        std::cout   << "Node address: "     << &SVP.second                   
                    << ", Value: "          << SVP.second.get_value() 
                    << ", Initial time: "   << SVP.second.get_init_time()
                    << ", Final time: "     << SVP.second.get_final_time() 
                    << std::endl;
    }

    return is_cycled; 
}


// Function to visualize the DFS tree contained in the graph
// This function was made by ChatGPT
void visualizeDFSTree(Graph& G) {
    std::cout << std::endl << "DFS Tree Visualization:" << std::endl;

    for (auto& vertex : G.get_Vertices()) {

        // Print node value and its predecessor's value (if any)
        std::cout << "Node " << vertex.second.get_value() << " ";
        if (vertex.second.get_predecesor()) {
            std::cout << "← " << vertex.second.get_predecesor()->get_value();
        } else {
            std::cout << "(Root)";
        }

        std::cout << std::endl;
    }
}

bool CycleDetection(const Graph& to_detect) {
    return Cycle_DFS(to_detect);
}

Graph& DFS_visit(Graph& DFS, Node& source_node, int& time, std::list<Node*>& topo_list) {
    // Mark the source node as visited and set initial time
    source_node.set_color("gray");
    source_node.set_init_time(++time);

    // Debugging: Check if the source node's address is in the DFS adjacency list
    if (DFS.get_Adjacency_List().find(&source_node) == DFS.get_Adjacency_List().end()) {
        std::cout << "Source node has no adjacencies in DFS adjacency list." << std::endl;
        std::cout << "Node address: " << &source_node << ", Value: " << source_node.get_value() << std::endl;
    }

    // Explore adjacent nodes
    for (auto& vertex : DFS.get_Adjacency_List()[&source_node]) {
        // Check if the adjacent node is not visited
        if (vertex.first->get_color() == "white") {
            // Set the source node as the predecessor of the adjacent node
            vertex.first->set_predecesor(&source_node);

            // Recursive call to DFS_visit for the adjacent node
            DFS_visit(DFS, *vertex.first, time, topo_list);
        }
    }

    // Mark the source node as fully explored and set final time
    source_node.set_color("black");
    source_node.set_final_time(++time);
    topo_list.push_front(&source_node);
    
    return DFS;
}

Graph Topo_DFS(Graph& DFS, std::list<Node*>& topo_list) {
    //Graph DFS {to_traverse};

    for (auto& vertex : DFS.get_Vertices()) {
        vertex.second.set_color("white");
        vertex.second.set_predecesor(nullptr);
    }

    int time {0};

    for (auto& vertex : DFS.get_Vertices()) {
        if (vertex.second.get_color() == "white") {
            DFS_visit(DFS, vertex.second, time, topo_list);
        }
    }

    // std::cout << std::endl << "DFS Graph" << std::endl;
    // for (auto& SVP : DFS.get_Vertices()) {
    //     std::cout   << "Node address: "     << &SVP.second                   
    //                 << ", Value: "          << SVP.second.get_value() 
    //                 << ", Initial time: "   << SVP.second.get_init_time()
    //                 << ", Final time: "     << SVP.second.get_final_time() 
    //                 << std::endl;
    // }

    return DFS;  
}

std::list<Node*> TopologicalSort(Graph& to_create) {
    std::list<Node*> Topo_List;
    Topo_DFS(to_create, Topo_List);
    return Topo_List;
}

struct Edge { // This owuld have been way easier to implement from the beggining
    Node* Source, *Target;
    int Weight;

    Edge(Node* new_Source, Node* new_Target, int new_Weight) : Source{new_Source}, Target{new_Target}, Weight{new_Weight} {}
};

bool cmp(const Edge& a, const Edge& b) {
    if (a.Weight < b.Weight) return true;
    return false;
}

// void Prims(const Graph& to_min_span) {
//     if (to_min_span.get_graph_type() % 2 == 0) {
//         std::cout << "Cannot use Prims. Graph must be undirected." << std::endl;
//         return;
//     }
//     Graph K {to_min_span};
//     std::vector<Edge> Edges;
//     std::set<Node*> S;
//     // std::vector<std::set<Node*>> Sets(K.get_Vertices().size());
//     // std::vector<Node*> Vertices;

//     for (auto& VNP : K.get_Vertices()) {
//         VNP.second.set_is_removable(true);
//     }

//     // for (auto& VNP : K.get_Vertices()) {
//     //     Sets.emplace_back(std::set<Node*>());
//     //     std::set<Node*> MySet {};
//     //     MySet.insert(&VNP.second);
//     //     Sets.insert(Sets.begin() + VNP.second.get_value(), MySet);
//     // }

//     // for (const auto& Set : Sets) {
//     //     for (const auto& element : Set) {
//     //         std::cout << element->get_value() << std::endl;
//     //     }
//     // }

//     for (const auto& SVP : K.get_Adjacency_List()) {
//         for (const auto& TWP : SVP.second) {
//             Edges.emplace_back(Edge(SVP.first, TWP.first, TWP.second));
//         } 
//     }

//     std::sort(Edges.begin(), Edges.end(), cmp);

//     // for (int i = 0; i < Edges.size(); i++) {
//     //     std::cout   << " Source: " << Edges[i].Source->get_value()
//     //                 << " Target: " << Edges[i].Target->get_value()
//     //                 << " Weight: " << Edges[i].Weight << std::endl;
//     // }

//     S.insert(&K.get_Vertices()[0]);
//     K.get_Vertices()[0].set_is_removable(false);
//     std::vector<Edge> F {};

//     while(S.size() != K.get_Vertices().size()) {
        
//     }





// }

#include <iostream>
#include <unordered_set>
#include <queue>
#include <limits>

Graph PrimMST(const Graph& graph) {
    Graph minSpanningTree;
    std::unordered_set<Node*> visitedNodes;

    // Choose a starting node arbitrarily (or based on some logic)
    Node* startNode = selectStartingNode(graph);

    if (!startNode) {
        std::cerr << "Error: Graph is empty." << std::endl;
        return minSpanningTree;
    }

    visitedNodes.insert(startNode);

    // Priority queue to store edges ordered by weight
    std::priority_queue<std::pair<int, std::pair<Node*, Node*>>,
                        std::vector<std::pair<int, std::pair<Node*, Node*>>>,
                        std::greater<int>> edgeQueue;

    // Add all edges connected to the starting node to the priority queue
    for (const auto& edge : graph.get_Adjacency_List().at(startNode)) {
        edgeQueue.push({edge.second, {startNode, edge.first}});
    }

    while (!edgeQueue.empty() && visitedNodes.size() < graph.get_Vertices().size()) {
        auto edge = edgeQueue.top();
        edgeQueue.pop();

        Node* sourceNode = edge.second.first;
        Node* targetNode = edge.second.second;

        if (visitedNodes.find(targetNode) == visitedNodes.end()) {
            visitedNodes.insert(targetNode);
            minSpanningTree.get_Adjacency_List()[sourceNode].emplace_back(targetNode, edge.first);
            minSpanningTree.get_Adjacency_List()[targetNode].emplace_back(sourceNode, edge.first);
        }
    }

    return minSpanningTree;
}

Node* selectStartingNode(const Graph& graph) {
    if (!graph.get_Vertices().empty()) {
        // Choose the first node as the starting node
        return &graph.get_Vertices().begin()->second;
    }
    return nullptr;
}