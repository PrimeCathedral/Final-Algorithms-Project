#include <iostream>
#include <fstream>
#include <sstream>
#include "Graph.hpp"

// Getters
Vertices_Map Graph::get_Vertices() const {
    return Vertices;
}
Adjacency_List_Map Graph::get_Adjacency_List() const {
    return Adjacency_List;
}
int Graph::get_graph_type() const {
    return graph_type;
}

// Setters
void Graph::set_Vertices(Vertices_Map new_Vertices) {
    Vertices = new_Vertices;
}
void Graph::set_Adjacency_List(Adjacency_List_Map new_Adjacency_List) {
    Adjacency_List = new_Adjacency_List;
}
void Graph::set_graph_type(int new_graph_type) {
    graph_type = new_graph_type;
}

// Constructors
Graph::Graph() : Vertices{}, Adjacency_List{}, graph_type{1} {};
Graph::Graph(const Graph& to_copy) : Vertices{to_copy.get_Vertices()} {
    // Deep copy the adjacency list
    Adjacency_List_Map New_Map;
    // for each key
    for (const auto& Node_Vector_pair : to_copy.get_Adjacency_List()) {
        // Find the value of the node being used as key
        // and find its corresponding node in the Vertices
        // Map, save the address of that vertex to be used 
        // as the key for the new adjacency list.
        int source_value {Node_Vector_pair.first-> get_value()};
        Node* Source_Node {&Vertices[source_value]};
        // for each pair in the value vector
        for (const auto& Weight_pair : Node_Vector_pair.second) {   
            // Find the corresponding node in the copied Vertices set
            int target_value {Weight_pair.first->get_value()};
            // Save the address of the corresponding node
            Node* Target_Node {&Vertices[target_value]};
            // Make the new map entry
            New_Map[Source_Node].emplace_back(std::pair<Node*, int>(Target_Node, Weight_pair.second));
        }
    }
    // This bit could have been optimized but I was lazy 
    Adjacency_List = New_Map;
}
Graph::Graph(std::string path_to_csv) {
    // Preprocessing: validate input

    // Path to csv cannot be empty
    if (path_to_csv.empty()) {
        std::cout << "File path is empty." << std::endl;
        return;
    }
    // Must contain .csv extension
    if (path_to_csv.find(".csv") == -1) {
        std::cout << "File path does not contain a .csv file" << std::endl;
        return;
    }

    // Modify so it only contains file name, not full path
    std::string file;
    // If no backslashes("/") are found, file = path to csv,
    // If they are found, file = everything AFTER the LAST backslash.
    if (path_to_csv.rfind("/") != -1) {
        file = path_to_csv;
    } else {
        file = path_to_csv.substr(
            path_to_csv.rfind("/") + 1,
            path_to_csv.length() - path_to_csv.rfind("/"));
    }

    // Part 1: Set Graph type
    graph_type = 1;
    if (file.find("undirected") == std::string::npos) graph_type *= 2;
    if (file.find("unweighted") == std::string::npos) graph_type *= 3;

    // Part 2: Extract vertices from CSV and create adjacency list

    // Open CSV file
    std::ifstream csv_file(path_to_csv);

    // Helper variables
    std::string line;
    int source, target, weight;
    bool source_is_there {false}, target_is_there {false};

    // Ignore the header line
    std::getline(csv_file, line);

    // Read data, line by line
    while (std::getline(csv_file, line)) {
        // Create a stringstream of the current line
        std::stringstream ss(line);

        // Extract source value
        ss >> source;
        ss.ignore(); // Ignore the comma
        ss >> target;

        // If the graph is weighted, extract weight
        // If its not, weight = 1
        if (graph_type % 3 == 0) {
            ss.ignore(); // Ignore the next comma
            ss >> weight;
        } else {
            weight = 1;
        }

        // Set is_there to false
        source_is_there = false;
        target_is_there = false;

        // Make sure the vertex has not been created before creating it.
        if (Vertices.find(source) == Vertices.end()) Vertices[source] = (Node(source));
        if (Vertices.find(target) == Vertices.end()) Vertices[target] = (Node(target));

        // Add the relationship into the adjacency list
        // if directed, one way, if undirected 2 way
        if (graph_type % 2 == 0) {
            Adjacency_List[&Vertices[source]].emplace_back(std::pair<Node*, int>(&Vertices[target], weight));
        } else {
            Adjacency_List[&Vertices[source]].emplace_back(std::pair<Node*, int>(&Vertices[target], weight));
            Adjacency_List[&Vertices[target]].emplace_back(std::pair<Node*, int>(&Vertices[source], weight));
        }
    }
    // Close the file
    csv_file.close();
}