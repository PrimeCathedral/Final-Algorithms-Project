#include <iostream>
#include "Graph.hpp"

using namespace std;

int main() {
    Node<int> MyNode {Node<int>(5)};
    cout << MyNode.get_name() << endl;
    return 0;
}