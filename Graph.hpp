#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream>
#include "Node.hpp"

using Adjacency_List_Map = std::unordered_map<Node*, std::vector<std::pair<Node*, int>>>;
using Vertices_Map = std::unordered_map<int, Node>;

class Graph {
    private:
        /////////////////////////////////////////////////
        // Vertices is an unordered map that takes     //
        // an int value and pairs it to a Node Vertex. //
        /////////////////////////////////////////////////
        Vertices_Map Vertices;

        ///////////////////////////////////////////////////////////////////////////////
        // Adjacency List is an unordered map that uses a Source Node pointer as key //
        // and has a vector of std::pairs composed of Target Node pointers, and the  //
        // weight for traveling from Source Node ptr to Target Node ptr.             //
        ///////////////////////////////////////////////////////////////////////////////
        Adjacency_List_Map Adjacency_List;

        ///////////////////////////////////////////////////
        // Graph type is an int that represent the type  //
        // of graph this Graph is. If the number is      //
        // divisible by 2, it is directed. If the number //
        // is divisible by 3, its is weighted.           //
        // 1: - directed - weighted                      //
        // 2: + directed - weighted                      //
        // 3: - directed + weighted                      //
        // 6: + directed + weighted                      //
        ///////////////////////////////////////////////////
        int graph_type;
    public:
        // Getters

        // Returns a map of nodes (vertices) where they is their int value
        Vertices_Map& get_Vertices();
        // Returns an adjacency list that uses Node pointers as keys
        Adjacency_List_Map& get_Adjacency_List();
        // Returns a map of nodes (vertices) where they is their int value
        Vertices_Map get_Vertices() const;
        // Returns an adjacency list that uses Node pointers as keys
        Adjacency_List_Map get_Adjacency_List() const;
        // Returns the graph type
        int get_graph_type() const ;

        // Setters
        void set_Vertices(Vertices_Map new_Vertices);
        void set_Adjacency_List(Adjacency_List_Map new_Adjacency_List);
        void set_graph_type(int new_graph_type);

        // Constructors
        Graph();
        Graph(const Graph& to_copy);
        Graph(std::string path_to_csv);
};
#endif