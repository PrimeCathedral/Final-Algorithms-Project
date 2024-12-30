# Final Algorithms Project - C++

This repository contains the final project for the Algorithms class (COMP 4017). The project implements graph algorithms and related utilities using C++.

## Features

- **Graph Representations:**
  - Directed and undirected graphs
  - Support for weighted and unweighted graphs
- **Graph Algorithms:**
  - Prim's Minimum Spanning Tree (MST) algorithm
  - Utility functions for graph traversal and manipulation
- **Data Input:**
  - Supports reading graph data from CSV files

## Project Structure

```
.
├── Graph.cpp                # Implementation of the Graph class
├── Graph.hpp                # Header file for the Graph class
├── Node.cpp                 # Implementation of the Node class
├── Node.hpp                 # Header file for the Node class
├── Prim_MST.hpp             # Header file for Prim's MST algorithm
├── algorithms.cpp           # Additional algorithm implementations
├── main.cpp                 # Main entry point of the application
├── menu.cpp                 # Command-line menu for interacting with the program
├── directed_unweighted_graph.csv  # Sample data for directed unweighted graphs
├── undirected_weighted_graph.csv  # Sample data for undirected weighted graphs
├── .vscode/                 # Configuration files for Visual Studio Code
└── README                   # Original project description
```

## Requirements

- **C++ Compiler:**
  - Compatible with C++11 or later
- **Development Environment:**
  - Visual Studio Code (optional; `.vscode` folder included for convenience)

## Setup and Usage

1. **Clone the repository:**

   ```bash
   git clone <repository-url>
   ```

2. **Navigate to the project directory:**

   ```bash
   cd Final-Algorithms-Project-CPP_V2
   ```

3. **Build the project:**

   Compile the `main.cpp` file along with dependencies:

   ```bash
   g++ main.cpp Graph.cpp Node.cpp menu.cpp algorithms.cpp -o main
   ```

4. **Run the program:**

   ```bash
   ./main
   ```

## Sample Data Files

- **directed_unweighted_graph.csv:** Contains adjacency data for a directed, unweighted graph
- **undirected_weighted_graph.csv:** Contains adjacency data for an undirected, weighted graph

## Key Classes and Files

### Graph Class (`Graph.hpp` and `Graph.cpp`)

Handles the representation of graphs, including methods for accessing vertices, adjacency lists, and graph type.

### Node Class (`Node.hpp` and `Node.cpp`)

Represents individual nodes in the graph, with utilities for managing node properties.

### Prim_MST Algorithm (`Prim_MST.hpp`)

Provides an implementation of Prim's algorithm to calculate the Minimum Spanning Tree (MST) of a graph.

### Algorithms (`algorithms.cpp`)

Additional graph-related algorithms and utility functions.

### Main Entry Point (`main.cpp`)

The main program logic, including examples and command-line interaction.

## Contributing

Feel free to fork this repository and submit pull requests to enhance the functionality or fix issues.

## License

This project is licensed under the MIT License.

## Acknowledgments

This project was completed as a requirement for the COMP 4017 Algorithms course.
