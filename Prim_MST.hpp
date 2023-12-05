// #include <iostream>
// #include <vector>
// #include <queue>
// #include <limits>
// #include "Node.hpp"

// class PrimMSTGraph {
// private:
//     std::vector<Node*> vertices;
//     std::vector<std::vector<std::pair<Node*, int>>> adjList;

// public:
//     PrimMSTGraph() {}

//     void addNode(Node* node) {
//         vertices.push_back(node);
//         adjList.emplace_back(); // Add an empty vector for the new node
//     }

//     void addEdge(Node* u, Node* v, int weight) {
//         // Assuming an undirected graph
//         adjList[u->get_value()].emplace_back(v, weight);
//         adjList[v->get_value()].emplace_back(u, weight);
//     }
    
//     // Getter methods
//     const std::vector<Node*>& getVertices() const {
//         return vertices;
//     }

//     const std::vector<std::vector<std::pair<Node*, int>>>& getAdjList() const {
//         return adjList;
//     }
// };

// class MinHeap {
// private:
//     std::priority_queue<std::pair<int, Node*>, std::vector<std::pair<int, Node*>>, std::greater<std::pair<int, Node*>>> minHeap;

// public:
//     bool empty() const {
//         return minHeap.empty();
//     }

//     void insert(int key, Node* value) {
//         minHeap.push({key, value});
//     }

//     std::pair<int, Node*> extractMin() {
//         auto minPair = minHeap.top();
//         minHeap.pop();
//         return minPair;
//     }
// };

// class PrimMST {
// private:
//     const PrimMSTGraph& graph;
//     MinHeap minHeap;
//     std::vector<bool> inMST;
//     std::vector<int> key;

// public:
//     explicit PrimMST(const PrimMSTGraph& g) : graph(g) {
//         inMST.assign(graph.getVertices().size(), false);
//         key.assign(graph.getVertices().size(), std::numeric_limits<int>::max());
//     }

//     void runPrim() {
//         key[0] = 0;
//         minHeap.insert(0, graph.getVertices()[0]);

//         while (!minHeap.empty()) {
//             auto minPair = minHeap.extractMin();
//             Node* u = minPair.second;

//             if (!inMST[u->get_value()]) {
//                 inMST[u->get_value()] = true;

//                 for (const auto& neighbor : graph.getAdjList()[u->get_value()]) {
//                     Node* v = neighbor.first;
//                     int weight = neighbor.second;

//                     if (!inMST[v->get_value()] && weight < key[v->get_value()]) {
//                         key[v->get_value()] = weight;
//                         minHeap.insert(weight, v);
//                     }
//                 }
//             }
//         }
//     }
// };