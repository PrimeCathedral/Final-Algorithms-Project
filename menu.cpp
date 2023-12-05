#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Algorithms.cpp"

using namespace std;

bool isValidPath(const string &path) {
    ifstream file(path);
    return file.good();
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <path_to_CSF_file>" << endl;
        return 1;
    }

    string filePath = argv[1];

    if (!isValidPath(filePath)) {
        cout << "Invalid file path. Please provide a valid CSF file path." << endl;
        return 1;
    }

    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. BFS\n2. DFS\n3. Connected Components\n4. Detect Cycles\n5. Topological Order\n6. MST\n7. Dijkstra\n8. Exit\n";
        cout << "Enter your choice (1-8): ";
        cin >> choice;
        Graph MyGraph {Graph(argv[1])};

        switch (choice) {
            case 1:
                int tmp;
                std::cout << "What node? " << std::endl;
                std::cin >> tmp;
                BFS(MyGraph, MyGraph.get_Vertices()[tmp]);
                break;
            case 2:
                DFS(MyGraph);
                break;
            case 3:
                std::cout << "Incomplete" <<std::endl;
                break;
            case 4:
                CycleDetection(MyGraph)? std::cout << "\nGraph has cycles.\n" << std::endl : std::cout << "Graph does not have cycles." << std::endl;
                break;
            case 5:
                TopologicalSort(MyGraph);
                break;
            case 6:
                std::cout << "Incomplete" <<std::endl;
                break;
            case 7:
                std::cout << "Incomplete" <<std::endl;
                break;
            case 8:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 8." << endl;
        }

    } while (choice != 8);

    return 0;
}
