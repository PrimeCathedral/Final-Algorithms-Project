#include <iostream>
#include "Node.hpp"
using namespace std;

int main() {
    Node MyNode {Node(3)};
    std::cout << MyNode.get_color() << std::endl;
    return 0;
}