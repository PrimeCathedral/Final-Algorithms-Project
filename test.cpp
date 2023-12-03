#include <iostream>
#include "Graph.hpp"
#include "algorithms.cpp"

using namespace std;

int main() {
    Graph<int> MyGraph {Graph<int>("./directed_weighted_graph.csv")};

    BFS(MyGraph, 9);

}